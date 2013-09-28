<?
  include_once("base/databaseManager.php");
  $userid=(int)$_POST["userid"];
	$con=new DatabaseManager();
	$sql="delete from users where userId=".$userid;
	$ds=$con->Query($sql);
	if(mysql_error()!="")echo "no";
	else echo $userid;
	$con->Dispose();
?>