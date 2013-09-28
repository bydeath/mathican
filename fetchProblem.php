<?
  include_once("base/databaseManager.php");
  $chapter=$_POST["chapter"];
	$retval="<table id='apTable'>";
	$con=new DatabaseManager();
	$sql="SELECT problems.title,problems.number";
	$sql.=" FROM problems";
	$sql.=" inner join problemchapter on problems.number=problemchapter.fk_problem";
	if($chapter=="all")
	{
		$course=$_POST["course"];
		$sql.=" inner join chapters on problemchapter.fk_chapter=chapters.chapterId";
		$sql.=" WHERE chapters.fk_pcourse=" . $course ;
  }
	else{
	 $sql.=" WHERE problemchapter.fk_chapter=" . $chapter ;
  }
	$sql.=" ORDER BY problems.number";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
     $retval.="<tr><td>";
		 $retval.="<input value='". $dr[1] ."' id='p".$dr[1]."' type='checkbox' /><span class='phand' onClick='openp(".$dr[1].");'>P" .$dr[1].".". $dr[0] . "</span></td></tr>";
	}
	$retval.="</table>";
	echo $retval;
	$con->Dispose();
?>