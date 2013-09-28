<?
	include_once("base/baseForm.php");
	include_once("base/dateSelector.php");
	$b->ActiveMenu=7;
	
	$b->AddCrumb("Modify Class","");
	
	$b->AddSubMenuItem("Add Class","addClass.php");
	
	//members
	$id=$_GET["id"];
	$con=new DatabaseManager();
	
	//define properties
	$title="";
	$startDate="";
	$endDate="";
	$days="";
	$room="";
	
	//populate properties
	if($_POST["btn_submit"])
	{
		$s=new DateSelector("startDate");
		$e=new DateSelector("endDate");
		$title=$_POST["txt_title"];
		$startDate=$s->Get("year") . "-" . $s->Get("month") . "-" . $s->Get("day");
		$endDate=$e->Get("year") . "-" . $e->Get("month") . "-" . $e->Get("day");
		$days=$_POST["txt_days"];
		$room=$_POST["txt_room"];
		$password=$_POST["txt_password"];
	}
	else
	{
		$sql="SELECT title,startDate,endDate,days,room,password";
		$sql.=" FROM courses";
		$sql.=" WHERE courseId=" . $id;
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$title=$dr[0];
			$startDate=$dr[1];
			$endDate=$dr[2];
			$days=$dr[3];
			$room=$dr[4];
			$password=$dr[5];
		}
	}
	
	//submit form
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
			$s=new DateSelector("startDate");
			$e=new DateSelector("endDate");
			
			$sql="UPDATE courses";
			$sql.=" SET title='" . $title . "',startDate='" . $startDate . "',endDate='" . $endDate . "',days='" . $days . "',room='" . $room . "',password='".$password."'";
			$sql.=" WHERE courseId = " . $id;
			$con->Query($sql);
	
			$b->Redirect("teachersClasses.php");
		}
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Modify <? echo($className); ?></h1>
<p>
<table border="0" cellpadding="2" cellspacing="0">
	<tr>
		<td class="white">
		Course Name:</td>
		<td class="white">
		<input type="text" id="txt_title" name="txt_title" value="<? echo($title); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Day/Time:</td>
		<td class="white">
		<input type="text" id="txt_days" name="txt_days" maxlength="10" value="<? echo($days); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Room:</td>
		<td class="white">
		<input type="text" id="txt_room" name="txt_room" maxlength="10" value="<? echo($room); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		New Password:</td>
		<td class="white">
		<input type="password" id="txt_password" name="txt_password" maxlength="50" value="<? echo($password); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Password:</td>
		<td class="white">
		<input type="password" id="txt_confpassword" name="txt_confpassword" maxlength="50" value="<? echo($password); ?>"/></td>
	</tr>
	<tr>
		<td class="white">
		Start Date:</td>
		<td class="white">
		<?
			$s=new DateSelector("startDate");
			$x=split("-",$startDate);
			$s->Set("year",$x[0]);
			$s->Set("month",$x[1]);
			$s->Set("day",$x[2]);
			$s->Render();
		?></td>
	</tr>
	<tr>
		<td class="white">
		End Date:</td>
		<td class="white">
		<?
			$e=new DateSelector("endDate");
			$x=split("-",$endDate);
			$e->Set("year",$x[0]);
			$e->Set("month",$x[1]);
			$e->Set("day",$x[2]);
			$e->Render();
		?></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" id="btn_submit" name="btn_submit" value="Modify Class" class="button1" />&nbsp;<button class="button1" onclick="document.location='teachersClasses.php'">Cancel</button></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>