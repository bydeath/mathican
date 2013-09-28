<?
	include_once("base/databaseManager.php");
  global $con;
  $con=new DatabaseManager();
  $sql="update assignmenttakes";
	$sql.=" set correctAnswersch=".$_POST["chgs"];
	$sql.=",chDate=now()";
	$sql.=" WHERE assignmentTakeId=".$_POST["tid"];
	$ds=$con->Query($sql);  
	echo "1";
  $con->Dispose();
?>
