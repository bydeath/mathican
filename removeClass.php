<?
	include_once("base/baseForm.php");
	$b->ActiveMenu=7;
	
	$b->AddCrumb("Remove Class","");
	
	$b->SecurePage("2");
	
	$b->AddSubMenuItem("Add Class","addClass.php");
	
	if($_POST["btn_submit"])
	{
		//query db
		$sql="UPDATE courses";
		$sql.=" SET active=0";
		$sql.=" WHERE courseId=" . $_GET["id"];
		
		$con=new DatabaseManager();
		$con->Query($sql);
		$con->Dispose();
	
		//redirect
		$b->Redirect("teachersClasses.php");
	}
	
	$b->RenderTemplateTop();
?>

<h1>Remove Class Confirmation</h1>
<p>When you remove a class you will lose all data associated with that class - including assignment grades. Are you sure you want to remove <b><? echo($className); ?></b>?</p>
<p align="center"><input type="submit" id="btn_submit" name="btn_submit" value="Remove Class" class="button1" />&nbsp;<button onclick="document.location='teachersClasses.php'" class="button">Cancel</button></p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>