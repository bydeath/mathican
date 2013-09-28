<?
	include_once("base/baseForm.php");
	include_once("base/dateSelector.php");
	$b->ActiveMenu=6;

	$b->AddCrumb("Your Assignments","teachersAssignments.php");
	$b->AddCrumb("Modify Assignment","");
	$b->SecurePage("2");
	$b->AddScript("scripts/ajax.js");
	$b->AddGenericScript("InitAjax();");

	$b->AddSubMenuItem("Add Assignment","addAssignment.php");
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php");

	//
	// - Prepare Form
	//

	//members
	$id=$_GET["id"];
	$types='';
	$classes='';
	$chapters='';
	$con=new DatabaseManager();
	$questionScript='';
	
	//
	// - Define and populate properties
	//
	
	//define
	$p_title="";
	$p_password="";
	$p_type="";
	$p_takes="";
	$p_shared="";
	$p_start="";
	$p_due="";
	$p_chapter="";
	$p_orientation="";
	$p_count="";
	$p_primary="";
	$p_alternative="";
	
	//populate
	if($_POST["btn_submit"])
	{
		$p_title=$_POST["txt_title"];
		$p_password=$_POST["txt_password"];
		$p_type=$_POST["ddl_type"];
		$p_takes=$_POST["ddl_takes"];
		$p_shared=$_POST["cb_shared"]==TRUE ? "1" : "0";
		$x=new DateSelector("ddl_startDate");
		$y=new DateSelector("ddl_dueDate");
		$p_start=$x->Get("year") . "-" . $x->Get("month") . "-" . $x->Get("day");
		$p_due=$y->Get("year") . "-" . $y->Get("month") . "-" . $y->Get("day");
		$p_chapter=$_POST["ddl_chapter"];
		$p_orientation=$_POST["ddl_problemOrientation"];
		$p_count=$_POST["ddl_problemNumber"];
		$p_primary=$_POST["ddl_problem"];
		$p_alternative=$_POST["ddl_problem_or"];
	}
	else
	{
		$sql="SELECT title,password,type,takes,shared,startDate,dueDate,fk_chapter,problemOrientation,numberQuestions,fk_problem_primary,fk_problem_alternative";
		$sql.=" FROM assignments";
		$sql.=" WHERE ( assignmentId=" . $id . " )";
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$p_title=$dr[0];
			$p_password=$dr[1];
			$p_type=$dr[2];
			$p_takes=$dr[3];
			$p_shared=$dr[4];
			$p_start=$dr[5];
			$p_due=$dr[6];
			$p_chapter=$dr[7];
			$p_orientation=$dr[8];
			$p_count=$dr[9];
			$p_primary=$dr[10];
			$p_alternative=$dr[11];
		}
	}

	//types
	$sql="SELECT assignmentTypeId,title";
	$sql.=" FROM _list_assignmenttypes";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$extra='';
		if($dr[0]==$p_type)
		{
			$extra=' selected="true"';
		}
		$types.='<option value="' . $dr[0] . '"' . $extra . '>' . $dr[1] . '</option>';
	}

	//classes
	$sql="SELECT courseId,title";
	$sql.=" FROM courses";
	$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
	$ds2=$con->Query($sql);
	while($dr=mysql_fetch_row($ds2))
	{
		$extra='';
		$sql="SELECT *";
		$sql.=" FROM assignmentcourses";
		$sql.=" WHERE ( active=1 AND fk_assignment=" . $id . " AND fk_course=" . $dr[0] . " )";
		$sDs=$con->Query($sql);
		while($sDr=mysql_fetch_row($sDs))
		{
			$extra=' checked="true"';
		}
		if($classes!='')
		{
			$classes.='<br />';
		}
		$classes.='<input type="checkbox" id="cb_class_' . $dr[0] . '" name="cb_class_' . $dr[0] . '" value="' . $dr[0] . '"' . $extra . ' />&nbsp;' . $dr[1];
	}

	//chapters
	$sql="SELECT chapterId,title";
	$sql.=" FROM chapters";
	$ds3=$con->Query($sql);
	while($dr=mysql_fetch_row($ds3))
	{
		$chapters.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	}
	
	//question script
	if($p_orientation=="1")
	{
		$myP="0";
		$myA="0";
		$sql="SELECT title,number";
		$sql.=" FROM problems";
		$sql.=" WHERE ( active=1 AND fk_chapter=" . $p_chapter . " )";
		$sql.=" ORDER BY title";
		$ds=$con->Query($sql);
		$i=0;
		while($dr=mysql_fetch_row($ds))
		{
			if($dr[1]==$p_primary)
			{
				$myP=$i;
			}
			if($dr[1]==$p_alternative)
			{
				$myA=$i+1;
			}
			if($myP!="0" && ( $myA!="0" || $p_alternative=="0" ))
			{
				break;
			}
			$i++;
		}
		if($myP!="")
		{
			$questionScript.='GetBrowserElement("ddl_problem").selectedIndex=' . $myP . ';';
		}
		if($myA!="")
		{
			$questionScript.='GetBrowserElement("ddl_problem_or").selectedIndex=' . $myA . ';';
		}
	}
	else
	{
		$sql="SELECT number,fk_problem_primary,fk_problem_alternative";
		$sql.=" FROM assignmentquestions";
		$sql.=" WHERE ( active=1 AND fk_assignment=" . $id . " )";
		$sql.=" ORDER BY number ASC";
		$ds=$con->Query($sql);
		$p=0;
		while($dr=mysql_fetch_row($ds))
		{
			$myP="0";
			$myA="0";
			$sql="SELECT title,number";
			$sql.=" FROM problems";
			$sql.=" WHERE ( active=1 AND fk_chapter=" . $p_chapter . " )";
			$sql.=" ORDER BY title";
			$sDs=$con->Query($sql);
			$i=0;
			while($sDr=mysql_fetch_row($sDs))
			{
				if($sDr[1]==$dr[1])
				{
					$myP=$i;
				}
				if($sDr[1]==$dr[2])
				{
					$myA=$i+1;
				}
				if($myP!="0" && ( $myA!="0" || $sDr[2]=="0" ))
				{
					break;
				}
				$i++;
			}
			if($myP!="")
			{
				$questionScript.='GetBrowserElement("ddl_problem_' . $p . '").selectedIndex=' . $myP . ';';
			}
			if($myA!="")
			{
				$questionScript.='GetBrowserElement("ddl_problem_' . $p . '_or").selectedIndex=' . $myA . ';';
			}
			$p++;
		}
	}
	
	//load script
	$b->AddGenericScript('SetProblems();');

	//set problems - ajax
	$ajax='var firstCallDone=false;';
	$ajax.='var ajaxSecondCounter=0;';
	$ajax.='function SetProblems()';
	$ajax.='{';
	$ajax.='	var count=GetBrowserElement("ddl_problemNumber").options[GetBrowserElement("ddl_problemNumber").selectedIndex].value;';
	$ajax.='	var chapter=GetBrowserElement("ddl_chapter").options[GetBrowserElement("ddl_chapter").selectedIndex].value;';
	$ajax.='	var orientation=GetBrowserElement("ddl_problemOrientation").options[GetBrowserElement("ddl_problemOrientation").selectedIndex].value;';
	$ajax.='	GetBrowserElement("td_setProblems").style.display="none";';
	$ajax.='	GetBrowserElement("td_loading").style.display="";';
	$ajax.='	AjaxRequest("GET","ajax/fetchProblemCount.php?chapter=" + chapter + "&orientation=" + orientation + "&count=" + count + "&poo=' . md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']) . '",true);';
	$ajax.='	ajaxSecondCounter=0;';
	$ajax.='	IncrementCounter();';
	$ajax.='}';
	$ajax.='function OnRequestComplete()';
	$ajax.='{';
	$ajax.='	if(ajaxSecondCounter>=3)';
	$ajax.='	{';
	$ajax.='		GetBrowserElement("td_setProblems").innerHTML=xmlHttp.responseText;';
	$ajax.='		if(firstCallDone==false)';
	$ajax.='		{';//firstCallDone
	$ajax.='			' . $questionScript;
	$ajax.='			firstCallDone=true;';
	$ajax.='		}';
	$ajax.='		GetBrowserElement("td_loading").style.display="none";';
	$ajax.='		GetBrowserElement("td_setProblems").style.display="";';
	$ajax.='		GetBrowserElement("txt_setQuestions").value="1";';
	$ajax.='	}';
	$ajax.='	else';
	$ajax.='	{';
	$ajax.='		setTimeout("OnRequestComplete()",1000);';
	$ajax.='	}';
	$ajax.='}';
	$ajax.='function IncrementCounter()';
	$ajax.='{';
	$ajax.='	ajaxSecondCounter+=1;';
	$ajax.='	if(ajaxSecondCounter<3)';
	$ajax.='	{';
	$ajax.='		setTimeout("IncrementCounter()",1000);';
	$ajax.='	}';
	$ajax.='}';
	$ajax.='function CopyProlemType(copy,paste)';
	$ajax.='{';
	$ajax.='	GetBrowserElement("ddl_problem_" + paste).selectedIndex=GetBrowserElement("ddl_problem_" + copy).selectedIndex;';
	$ajax.='	GetBrowserElement("ddl_problem_" + paste + "_or").selectedIndex=GetBrowserElement("ddl_problem_" + copy + "_or").selectedIndex;';
	$ajax.='}';
	$ajax.='';
	$ajax.='';
	$ajax.='';
	$ajax.='';
	$b->AddScriptMethods($ajax);

	//
	// - Process Submited Form
	//
	if($_POST["btn_submit"])
	{
		if($_POST["txt_title"]=="")
		{
			$b->Alert("You must enter a title for the assignment!",TRUE);
		}
		if($_POST["txt_setQuestions"]=="")
		{
			$b->Alert("You must complete the 'problem set' section of the form!",TRUE);
		}
		if($b->Errored==FALSE)
		{
			// - Create Assignment
			$dueDate=new DateSelector("ddl_dueDate");
			$startDate=new DateSelector("ddl_startDate");
		//	$sql="INSERT INTO assignments";
		//	$sql.=" ( title,fk_user_owner,fk_user_creator,type,shared,numberQuestions,password,startDate,dueDate,problemOrientation )";
		//	$sql.=" VALUES ( '" . $_POST["txt_title"] . "'," . $b->User->UserId . "," . $b->User->UserId . "," . $_POST["ddl_type"] . "," . ( $_POST["cb_shared"]==TRUE ? "1" : "0" ) . "," . $_POST["ddl_problemNumber"] . ",'" . $_POST["txt_password"] . "',DATE('" . $startDate->Get("year") . "-" . $startDate->Get("month") . "-" . $startDate->Get("day") . "'),DATE('" . $dueDate->Get("year") . "-" . $dueDate->Get("month") . "-" . $dueDate->Get("day") . "')," . $_POST["ddl_problemOrientation"] . " )";
		//	$con->Query($sql);
			
			// - Retreive PK
			$pk=$id;
		//	$sql="SELECT assignmentId";
		//	$sql.=" FROM assignments";
		//	$sql.=" WHERE ( fk_user_owner=" . $b->User->UserId . " )";
		//	$sql.=" ORDER BY assignmentId DESC";
		//	$ds=$con->Query($sql);
		//	while($dr=mysql_fetch_row($ds))
		//	{
		//		$pk=(int)$dr[0];
		//		break;
		//	}
		
			// - Save Generic Details
			$x=new DateSelector("ddl_startDate");
			$y=new DateSelector("ddl_dueDate");
			$sql="UPDATE assignments";
			$sql.=" SET title='" . $p_title . "',type=" . $p_type . ",shared=" . $p_shared . ",numberQuestions=" . $p_count . ",password='" . $p_password . "',startDate=DATE('" . $x->Get("year") . "-" . $x->Get("month") . "-" . $x->Get("day") . "'),dueDate=DATE('" . $y->Get("year") . "-" . $y->Get("month") . "-" . $y->Get("day") . "'),problemOrientation=" . $p_orientation . ",takes=" . $p_takes . ",fk_user_creator=" . $b->User->UserId;
			$sql.=" WHERE assignmentId = " . $pk;
			$con->Query($sql);
			
			// - Save Class Assignments
			//remove old
			$con->Query("UPDATE assignmentcourses SET active=0 WHERE fk_assignment=" . $id);
			
			//create new
			$sql="SELECT courseId";
			$sql.=" FROM courses";
			$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
			//echo("<br />" . $sql);
			$ds2=$con->Query($sql);
			while($dr=mysql_fetch_row($ds2))
			{
				//echo("<br />' . $dr[0] . ' Val=" . $_POST["cb_class_" . $dr[0]]);
				if($_POST["cb_class_" . $dr[0]]==TRUE)
				{
					$sql="INSERT INTO assignmentcourses";
					$sql.=" ( fk_assignment,fk_course,active )";
					$sql.=" VALUES ( " . $pk . "," . $dr[0] . ",1 )";
					//echo("<br />" . $sql);
					$con->Query($sql);
				}
			}
			
			// - Save Problem Information
			//remove old
			$con->Query("UPDATE assignmentquestions SET active=0 WHERE fk_assignment=" . $id);
			
			//create new
			if($_POST["ddl_problemOrientation"]=="2")
			{
				$count=(int)$_POST["ddl_problemNumber"];
				$i=0;
				while($i<$count)
				{
					$sql="INSERT INTO assignmentquestions";
					$sql.=" ( fk_assignment,number,fk_problem_primary,fk_problem_alternative )";
					$sql.=" VALUES ( " . $pk . "," . ($i+1) . "," . $_POST["ddl_problem_" . $i] . "," . $_POST["ddl_problem_" . $i . "_or"] . " )";
					//echo($sql);
					$con->Query($sql);
					$i=$i+1;
				}
			}
			else
			{
				$sql="UPDATE assignments";
				$sql.=" SET fk_problem_primary=" . $_POST["ddl_problem"] . ",fk_problem_alternative=" . $_POST["ddl_problem_or"];
				$sql.=" WHERE ( assignmentId = " . $pk . " )";
				$con->Query($sql);
			}
			$b->Redirect("teachersAssignments.php");
		}
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Use the form below to create your new assignment. Complete the <i>assignment information</i>, and the <i>class assignments</i>, then begin the <i>problem set</i> information. After you've selected the <i>chapter</i>, <i>problem orientation</i>, and <i>number of problems</i> click the <i><b>set questions</b></i> button to set the properties for individual questions. Once you've completed the form click the <i><b>create assignment</b></i> button at the bottom of the page.</p>

<h1>Add Assignment Form</h1>
<p>
<table width="700" border="0" cellpadding="2" cellspacing="0">
	<tr>
		<td colspan="2">
		<h2>Assignment Information</h2></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Title:</td>
		<td width="500" class="white">
		<input type="text" id="txt_title" name="txt_title" value="<? echo($p_title) ?>" /></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Type:</td>
		<td width="500" class="white">
		<select id="ddl_type" name="ddl_type">
		<? echo($types); ?>
		</select></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Takes:</td>
		<td width="500" class="white">
		<select id="ddl_takes" name="ddl_takes">
		<?
			$i=0;
			while($i<10)
			{
				$extra='';
				if(($i+1)==$p_takes)
				{
					$extra=' selected="true"';
				}
				echo('<option value="' . ($i+1) . '"' . $extra . '>' . ($i+1) . '</option>');
				$i=$i+1;
			}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Shared:</td>
		<td width="500" class="white">
		<input type="checkbox" id="cb_shared" name="cb_shared"<? if($p_shared=="1"){ echo(' checked="true"'); } ?> />&nbsp;<a href="link">What is this?</a></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Password:</td>
		<td width="500" class="white">
		<input type="text" id="txt_password" name="txt_password" value="<? echo($p_password) ?>" /></td>
	</tr>
	<tr>
		<td colspan="2">
		<hr></td>
	</tr>
	<tr>
		<td colspan="2">
		<h2>Class Assignments</h2></td>
	</tr>
	<tr>
		<td width="200" valign="top" class="white">
		Classes:</td>
		<td width="500" class="white">
		<? echo($classes); ?></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Start Date:</td>
		<td width="500" class="white">
		<?
			$startDate=new DateSelector("ddl_startDate");
			$a=split("-",$p_start);
			$startDate->Set("year",$a[0]);
			$startDate->Set("month",$a[1]);
			$startDate->Set("day",$a[2]);
			$startDate->Render();
		?></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Due Date:</td>
		<td width="500" class="white">
		<?
			$dueDate=new DateSelector("ddl_dueDate");
			$a=split("-",$p_due);
			$dueDate->Set("year",$a[0]);
			$dueDate->Set("month",$a[1]);
			$dueDate->Set("day",$a[2]);
			$dueDate->Render();
		?></td>
	</tr>
	<tr>
		<td colspan="2">
		<hr></td>
	</tr>
	<tr>
		<td colspan="2">
		<h2>Problem Set</h2></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Chapter:</td>
		<td width="500" class="white">
		<select id="ddl_chapter" name="ddl_chapter">
		<?
			echo($chapters);
		?>
		</select></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Problem Orientation:</td>
		<td width="500" class="white">
		<select id="ddl_problemOrientation" name="ddl_problemOrientation">
			<option value="1"<? if($p_orientation=="1"){ echo(' selected="true"'); } ?>>Single Problem Type</option>
			<option value="2"<? if($p_orientation=="2"){ echo(' selected="true"'); } ?>>Multiple Problem Types</option>
		</select></td>
	</tr>
	<tr>
		<td width="200" class="white">
		Number of Problems:</td>
		<td width="500" class="white">
		<select id="ddl_problemNumber" name="ddl_problemNumber">
		<?
			$i=0;
			while($i<50)
			{
				$extra='';
				if($p_count==($i+1))
				{
					$extra=' selected="true"';
				}
				echo('<option value="' . ($i+1) . '"' . $extra . '>' . ($i+1) . '</option>');
				$i=$i+1;
			}
		?>
		</select>&nbsp;<button onclick="javascript:SetProblems();" class="button1">Set Questions</button><input type="hidden" id="txt_setQuestions" name="txt_setQuestions" /></td>
	</tr>
	<tr>
		<td id="td_setProblems" colspan="2" style="display:none;">&nbsp;
		</td>
	</tr>
	<tr>
		<td id="td_loading" colspan="2" align="center" valign="middle" style="display:none;">
		<div width="75%" align="center" style="background-color:#eeffee;height:150px;width:475px;border-style:dashed;border-color:gray;border-width:1px;padding-top:45;font-family:arial;font-size:11;color:black;">Loading<br /><img src="pics/loading.gif" alt="Loading..." /></div></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input id="btn_submit" name="btn_submit" type="submit" value="Modify Assignment" class="button"/>&nbsp;<button onclick="document.location='teachersAssignments.php'">Cancel</button></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>