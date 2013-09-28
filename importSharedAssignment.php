<?
	include_once("base/baseForm.php");
	include_once("base/dateSelector.php");
	$b->ActiveMenu=6;
	
	$b->AddCrumb("Import Shared Assignment","");
	
	$b->AddSubMenuItem("Add Assignment","addAssignment.php");
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php");
	
	//members
	$id=$_GET["id"];
	$con=new DatabaseManager();
	$sql="SELECT title";
	$sql.=" FROM assignments";
	$sql.=" WHERE ( assignmentId=" . $id . " )";
	$ds=$con->Query($sql);
	$atitle="";
	while($dr=mysql_fetch_row($ds))
	{
		$atitle=$dr[0];
	}
	//html vars
	$classList='';
	
	//load classList
	$sql="SELECT courseId,title";
	$sql.=" FROM courses";
	$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
	$ds2=$con->Query($sql);
	while($dr=mysql_fetch_row($ds2))
	{
		if($classList!='')
		{
			$classList.='<br />';
		}
		$classList.='<input type="checkbox" id="cb_class_' . $dr[0] . '" name="cb_class_' . $dr[0] . '" value="' . $dr[0] . '" />&nbsp;' . $dr[1];
	}
	
	if($_POST["btn_submit"])
	{
		//validate form
		if($_POST["txt_title"]=="")
		{
			$b->Alert("You must enter a title for the assignment!",TRUE);
		}
	
		//process form
		if($b->Errored==FALSE)
		{
			//define fields
			$fk_user_owner=$b->User->UserId;
			$fk_user_creator="";
			$title=$_POST["txt_title"];
			$type="";
			$shared="";
			$numberQuestions="";
			$password="";
			$startDate="";
			$dueDate="";
			$takes="";
			$problemOrientation="";
			$fk_problem_primary="";
			$fk_problem_alternative="";
			$fk_chapter="";
			
			//get origional values
			$sql="SELECT fk_user_owner,type,shared,password,startDate,dueDate,takes";
			$sql.=" FROM assignments";
			$sql.=" WHERE ( assignmentId=" . $id . " )";
			//echo($sql . "<br />");
			$ds=$con->Query($sql);
			while($dr=mysql_fetch_row($ds))
			{
				$fk_user_creator=$dr[0];
				$type=$dr[1];
				$shared=$dr[2];
				$password=$dr[3];
				$startDate=$dr[4];
				$dueDate=$dr[5];
				$takes=$dr[6];
			}
			
			//set new values
			$s=new DateSelector("startDate");
			$d=new DateSelector("endDate");
			$startDate=$s->Get("year") . "-" . $s->Get("month") . "-" . $s->Get("day");
			$dueDate=$d->Get("year") . "-" . $d->Get("month") . "-" . $d->Get("day");
			$shared="0";
			
			//save new record
			$sql="INSERT INTO assignments";
			$sql.=" ( fk_user_owner,fk_user_creator,title,type,shared,password,startDate,dueDate,takes )";
			$sql.=" VALUES ( " . $fk_user_owner . "," . $fk_user_creator . ",'" . $title . "'," . $type . "," . $shared . ",'" . $password . "','" . $startDate . "','" . $dueDate . "'," . $takes . " )";
			//echo($sql . "<br />");
			$con->Query($sql);
			
			//retreive pk
			$pk="";
			$sql="SELECT assignmentId";
			$sql.=" FROM assignments";
			$sql.=" WHERE ( fk_user_owner=" . $fk_user_owner . " )";
			$sql.=" ORDER BY assignmentId DESC";
			//echo($sql . "<br />");
			$ds=$con->Query($sql);
			while($dr=mysql_fetch_row($ds))
			{
				$pk=$dr[0];
				break;
			}
			
			//set question info
			$sql="SELECT numbers,fk_problem,sortnum";
			$sql.=" FROM assignmentquestions";
			$sql.=" WHERE ( fk_assignment=" . $id . " )";
			//echo($sql . "<br />");
			$ds=$con->Query($sql);
			while($dr=mysql_fetch_row($ds))
			{
				$sql="INSERT INTO assignmentquestions";
				$sql.=" ( fk_assignment,numbers,fk_problem,sortnum )";
				$sql.=" VALUES ( " . $pk . "," . $dr[0] . "," . $dr[1] . "," . $dr[2] . " )";
				//echo($sql . "<br />");
				$con->Query($sql);
			}
			
			//set classes
			$sql="SELECT courseId";
			$sql.=" FROM courses";
			$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
			$ds2=$con->Query($sql);
			while($dr=mysql_fetch_row($ds2))
			{
				if($_POST["cb_class_" . $dr[0]]==TRUE)
				{
					$sql="INSERT INTO assignmentcourses";
					$sql.=" ( fk_assignment,fk_course,active )";
					$sql.=" VALUES ( " . $pk . "," . $dr[0] . ",1 )";
					$con->Query($sql);
				}
			}
			
			//redirect
			$b->Redirect("teachersAssignments.php");
		}
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Use the form below to specify how you would like to import this assignment. When you are finished, click the submit button located at the bottom of the form.</p>

<h1>Import Form</h1>
<p>
<table width="100%" border="0" cellpadding="2" cellspacing="0">
	<tr>
		<td class="white">
		Assignment Name:</td>
		<td class="white">
		<input type="text" id="txt_title" name="txt_title" value="<?echo $atitle; ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		For Classes:</td>
		<td class="white">
		<? echo($classList); ?></td>
	</tr>
	<tr>
		<td class="white">
		Start Date:</td>
		<td class="white">
		<?
		$start=new DateSelector("startDate");
		$today=getdate();
		$start->Set("year",$today['year']);
  	$start->Set("month",$today['mon']);
  	$start->Set("day",$today['mday']);
		$start->Render();
		?></td>
	</tr>
	<tr>
		<td class="white">
		Due Date:</td>
		<td class="white">
		<?
		$end=new DateSelector("endDate");
		$today=getdate();
		$end->Set("year",$today['year']);
  	$end->Set("month",$today['mon']);
  	$end->Set("day",$today['mday']);
		$end->Render();
		?></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" id="btn_submit" name="btn_submit" value="Import Assignment" class="button1" />&nbsp;<button class="button1" onclick="document.location='sharedAssignments.php'">Cancel</button></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>