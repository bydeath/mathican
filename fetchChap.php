<?
  include_once("base/databaseManager.php");
  $course=(int)$_POST["course"];
	$con=new DatabaseManager();
	$sql="SELECT chapterId,title";
	$sql.=" FROM chapters";
	$sql.=" WHERE fk_pcourse=" . $course;
	$sql.=" order by title";
	$ds=$con->Query($sql);
	//$chapters=array();
  $re='<option value="all">All Chapters</option>';	
	while($dr=mysql_fetch_row($ds))
	{
		 //$chapters[$dr[0]]=$dr[1];	 
		 $re.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';		 
	}
	echo $re;
	$con->Dispose();
?>