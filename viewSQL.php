<?
		include_once("base/baseForm.php");
		include_once("base/databaseManager.php");
		
		$b->AddCrumb("View each problem correct rate ","");
		$b->ActiveMenu=15;
		$b->MainMenuIndex=15;
		
		$b->SecurePage("2");
		//$b->AddSubMenuItem("View students' grade","viewGrades.php?aid=".$_GET["aid"]."&cid=".$_GET["cid"]);
		
		
		$con=new DatabaseManager();
		//$aid=$_GET["aid"];
		//$cid=$_GET["cid"];	
		$grades="";
	
	
	
//	$sql="SELECT courseId,courses.title,assignments.title,_list_assignmenttypes.title";
//  $sql.=" FROM courses";
//  $sql.="  INNER JOIN assignmentcourses ON courses.courseId=assignmentcourses.fk_course";
//  $sql.="  INNER JOIN assignments ON  assignments. assignmentId=assignmentcourses.fk_assignment";
//  $sql.="  INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
//  $sql.=" WHERE courses.active=1 and fk_assignment=" .$aid ;
//  if($cid!="")
//  {
//   $sql.=" and courseId=".$cid;	
//	}


//  $sql="select assignmentTakeId,fk_assignment,correctAnswers,incorrectAnswers from";
//  $sql.=" assignmenttakes where assignmentTakeId=76308";

  $sql="select * from assignmenttakequestions where fk_assignmentTake=76308 order by number asc";

 // $sql="insert into assignmenttakequestions values('',76308,15,70,1,'5x^2-15x-3x+9','(5x-3)(x-3)','1','0','0','{\"infix_0\":\"(5x-3)(x-3)\"}',1);";
  $ds=$con->Query($sql);

  while($dr=mysql_fetch_row($ds))
  { 	
  	$grades.=$dr[0]."$   ".$dr[1]."$   ".$dr[2]."$   ".$dr[3]."$   ";
  	$grades.=$dr[4]."$   ".$dr[5]."$   ".$dr[6]."$   ".$dr[7]."$   ";
  	$grades.=$dr[8]."$   ".$dr[9]."$   ".$dr[10]."$   ".$dr[11]."<br>";
	}
	
	

	$con->Dispose();
	$b->RenderTemplateTop();
?>

<? echo($grades); ?>
<script language="javascript" src="scripts/dialog.js"></script>
<script language="javascript" src="scripts/sendrequest.js"></script>
<script language="javascript" src="scripts/changescore.js"></script>
<script language="javascript" src="scripts/openta.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>