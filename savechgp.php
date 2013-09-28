<?
 	include_once("base/baseForm.php");
	$startp=$_POST["startp"];
	$endp=$_POST["endp"];
  
	$con=new DatabaseManager();
	for($i=(int)$startp;$i<=(int)$endp;$i++)
  {
  	$sql="update problems";
  	$sql.=" set questionIntro='".$_POST["p".$i]."'";
  	$sql.=" where number=".$i;
  	$ds=$con->Query($sql);
  }
  $con->Dispose();
  echo $_POST["p".$i-1];
?>