<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	$b->ActiveMenu=5;
	
	$b->AddCrumb("Remove Student","");
	
	$b->AddSubMenuItem("Add Student","addStudent.php");
	
	$b->SecurePage("2");
	
	if($_POST["btn_submit"])
	{
		$con=new DatabaseManager();
		
		$sql="delete from studentenrollment";
		$sql.=" WHERE ( fk_user=" . $_GET["id"] . " AND fk_course=" . $_GET["cid"] . " )";
		$con->Query($sql);
		
		$con->Dispose();
		$b->Redirect("teachersStudents.php");
	}
	
	$b->RenderTemplateTop();
?>

<h1>Remove Student Confirmation</h1>
<p>Once you remove a student all his/her records will be lost. Are you sure that you would like to remove <? echo($userName); ?> from your class?</p>
<p align="center"><input type="submit" id="btn_submit" name="btn_submit" value="Remove Student" class="button1" />&nbsp;<button class="button1" onclick="document.location='teachersStudents.php'">Cancel</button></p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>