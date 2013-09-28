<?
	include_once("base/baseForm.php");
	$b->ActiveMenu=6;
	
	$b->AddCrumb("Remove Assignment","");
	
	$b->AddSubMenuItem("Add Assignment","addAssignment.php");
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php");
	
	$con=new DatabaseManager();
	$id=$_GET["id"];
	$name="";
	
	$sql="SELECT title";
	$sql.=" FROM assignments";
	$sql.=" WHERE ( assignmentId=" . $id . " )";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$name=$dr[0];
	}
	
	if($_POST["btn_submit"])
	{
		$sql="UPDATE assignments";
		$sql.=" SET active=0";
		$sql.=" WHERE assignmentId=" . $id;
		$con->Query($sql);
		$b->Redirect("teachersAssignments.php");
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Confirm Assignment Deletion</h1>
<p>Are you sure you want to delete <b><? echo($name); ?></b>? Deleting this assignment will erase all data associated with it, including any student's scores that have taken this assignment.</p>
<p align="center"><input type="submit" id="btn_submit" name="btn_submit" value="Delete Assignment" class="button1" />&nbsp;<button onclick="document.location='teachersAssignments.php'" class="button1">Cancel</button></p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>