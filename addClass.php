<?
	include_once("base/baseForm.php");
	include_once("base/dateSelector.php");
	$b->ActiveMenu=7;
	
	$b->AddCrumb("Add Class","");
	
	$b->AddSubMenuItem("Add Class","addClass.php",TRUE);
	
	if($_POST["btn_submit"])
	{
		//validate form
		if($_POST["txt_title"]=="")
		{
			$b->Alert("You must enter a course name!",TRUE);
		}
		
		//process form
		if($b->Errored==FALSE)
		{
			$con=new DatabaseManager();
			
			$s=new DateSelector("startDate");
			$e=new DateSelector("endDate");
			$sql="INSERT INTO courses";
			$sql.=" ( fk_user_teacher,title,startDate,endDate,days,room,active,password)";
			$sql.=" VALUES ( " . $b->User->UserId . ",'" . $_POST["txt_title"] . "','" . $s->Get("year") . "-" . $s->Get("month") . "-" . $s->Get("day") . "','" . $e->Get("year") . "-" . $e->Get("month") . "-" . $e->Get("day") . "','" . $_POST["txt_days"] . "','" . $_POST["txt_room"] . "',1,'".$_POST["txt_password"]."')";
			$con->Query($sql);
			if(mysql_error())
			{
				$b->Alert(mysql_error(),TRUE);
			}
			$con->Dispose();
			
			$b->Redirect("teachersClasses.php");
		}
	}
	
	$b->RenderTemplateTop();
?>

<h1>New Class Form</h1>
<p>Enter the class information in the form below. When you have finished click the submit button to add the class.</p>
<p>
<table border="0" cellpadding="2" cellspacing="0">
	<tr>
		<td class="white">
		Course Name:</td>
		<td class="white">
		<input type="text" id="txt_title" name="txt_title" /></td>
	</tr>
	<tr>
		<td class="white">
		Day/Time:</td>
		<td class="white">
		<input type="text" id="txt_days" name="txt_days" maxlength="50" /></td>
	</tr>
	<tr>
		<td class="white">
		Room:</td>
		<td class="white">
		<input type="text" id="txt_room" name="txt_room" maxlength="50" /></td>
	</tr>
	<tr>
		<td class="white">
		Password:</td>
		<td class="white">
		<input type="password" id="txt_password" name="txt_password" maxlength="50" /></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Password:</td>
		<td class="white">
		<input type="password" id="txt_confpassword" name="txt_confpassword" maxlength="50" /></td>
	</tr>
	<tr>
		<td class="white">
		Start Date:</td>
		<td class="white">
		<?
			$s=new DateSelector("startDate");
			$s->Render();
		?></td>
	</tr>
	<tr>
		<td class="white">
		End Date:</td>
		<td class="white">
		<?
			$e=new DateSelector("endDate");
			$e->Render();
		?></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" id="btn_submit" name="btn_submit" value="Add Class" class="button1" /></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>