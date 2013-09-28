
<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("View Student's Best and Last Grades Information","");
	$b->ActiveMenu=15;
	$b->MainMenuIndex=15;
	
	$con=new DatabaseManager();
	$aid=$_GET["aid"];
	$cid=$_GET["cid"];
	
	$b->SecurePage("2");
	
		
	$subjectTotal=0;
	//
	// - Create list
	//
	$sql="SELECT courseId,courses.title,assignments.title,_list_assignmenttypes.title";
  $sql.=" FROM courses";
  $sql.="  INNER JOIN assignmentcourses ON courses.courseId=assignmentcourses.fk_course";
  $sql.="  INNER JOIN assignments ON  assignments. assignmentId=assignmentcourses.fk_assignment";
  $sql.="  INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
  $sql.=" WHERE courses.active=1 and fk_assignment=" .$aid ;
  if($cid!="")
  {
   $sql.=" and courseId=".$cid;	
	}
  $ds=$con->Query($sql);
  $aname="";
  $atype="";
  while($dr=mysql_fetch_row($ds))
  {
  	$aname=$dr[2];
  	$atype=$dr[3];
  	$sql="SELECT studentenrollment.fk_user,firstName,lastName,email";
  	$sql.=" FROM studentenrollment";
  	$sql.=" INNER JOIN users on users.userId=studentenrollment.fk_user";
  	$sql.=" WHERE studentenrollment.fk_course=".$dr[0];
  	if($_GET["sort"]=="firstName,lastName" || $_GET["sort"]=="email")
	  {
		 $sql.=" ORDER BY " . $_GET["sort"]." asc";
	  }else
	  {
	  	$sql.=" ORDER BY lastName asc";
	  }
  	$sds=$con->Query($sql);
  	$n=0;
  	$grades.='<p>';
  	$grades.=' The grades of students in course <b>'.$dr[1].'</b>';
		$grades.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$grades.='<tr>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Student Name<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'viewGrades.php?aid='.$aid.'&cid='.$cid.'&sort=firstName,lastName\';" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="assignmentId"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Email Address<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'viewGrades.php?aid='.$aid.'&cid='.$cid.'&sort=email\';" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="grade" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Best Grade</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="started"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Recent Grade</td>';
		$grades.='</tr>';
  	while($sdr=mysql_fetch_row($sds))
  	{
  		$n++;
  		$added=FALSE;
      $sql="SELECT assignmenttakes.assignmentTakeId,assignmenttakes.finished,correctAnswers,incorrectAnswers,correctAnswersch,chDate";
  		$sql.=" FROM assignmenttakes";
  		$sql.=" WHERE ( fk_user_taker=" . $sdr[0] . " AND assignmenttakes.fk_assignment=" . $aid . " )";// AND assignmenttakes.done=1 
  	  $sql.=" Order by correctAnswersch desc,assignmentTakeId desc limit 1";
  	  $sDs1=$con->Query($sql);
  	  $added=TRUE;
  	  $bestscore="-1";
  	  $bestscorech="-1";
  	  $bestid=0;
  	  $bestfinish="2008-1-1";
  	  $chdate="";
  	  while($sDr1=mysql_fetch_row($sDs1))
  		{  
  			  $bestscore=$sDr1[2];
  			  $besttotal=(int)$sDr1[2]+(int)$sDr1[3];
  			  $bestid=$sDr1[0];
  	      $bestfinish=$sDr1[1]; 
  	      $bestscorech= $sDr1[4];
  	      $chdate= $sDr1[5];
       }
       $sql="SELECT assignmenttakes.assignmentTakeId,assignmenttakes.finished,correctAnswers,incorrectAnswers,correctAnswersch,chDate";
  		 $sql.=" FROM assignmenttakes";
  		 $sql.=" WHERE ( fk_user_taker=" . $sdr[0] . " AND assignmenttakes.fk_assignment=" . $aid . " )";// AND assignmenttakes.done=1 
  	   $sql.=" Order by assignmentTakeId desc limit 1";
  	   $sDs1=$con->Query($sql);
  	   $lastscore="-1";
  	   $lastid=0;
  	   $lastfinish="2008-1-1";
  	   $chdatelast="";
  	   while($sDr1=mysql_fetch_row($sDs1))
  		 {
  			  $lastscorech=$sDr1[4];
  			  $lastscore=$sDr1[2];
  			  $lasttotal=(int)$sDr1[2]+(int)$sDr1[3];
  			  $lastid=$sDr1[0];
  	      $lastfinish=$sDr1[1];
  	      $chdatelast=$sDr1[5];
       }
  			 //write html
  		 $grades.='<tr>';	
  		 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
  		 $grades.='	' . $sdr[1].' '.$sdr[2] . '&nbsp;</td>';
  		 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
  		 $grades.='	' . $sdr[3] . '&nbsp;</td>';
  		 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
  		 $img='pics/changescore3.png';
			 if($chdate!="")
  		 {
  		 	 $img='pics/changescore2.png';
  		 }
  		 
  		 $imglast='pics/changescore3.png';
			 if($chdatelast!="")
  		 {
  		 	 $imglast='pics/changescore2.png';
  		 }
  		 
  		 if($bestscore=="-1")
  		 {
  		 	 $grades.='N/A';
  		 }else
  		 {
  		 	 $grades.='	<a href="javascript:openta(3,' . $aid . ','.$dr[0].','.$bestid.')" title="Date Taken: '. $bestfinish .'">' . $bestscorech.'/'.$besttotal .'</a> &nbsp;<a href="#" onClick=\'changesc("'. $sdr[1] .'","'.$sdr[2].'","'.$aname.'","'.$bestid.'",'.$bestscore.','.$besttotal.','.$bestscorech.');\'><img src="'.$img.'" border="0" title="change the score" style="vertical-align: middle;"/></a>';
  		 	 $subjectTotal=$besttotal;
  		 }
  		 $grades.='</td>';
  		 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
  		 if($bestscore=="-1")
  		 {
  		 	 $grades.='N/A';
  		 }else
  		 {
  		  $grades.='	<a href="javascript:openta(3,' . $aid . ','.$dr[0].','.$lastid.')" title="Date Taken:'.$lastfinish.' ">' . $lastscorech.'/'.$lasttotal .'&nbsp;<a href="#" onClick=\'changesc("'. $sdr[1] .'","'.$sdr[2].'","'.$aname.'","'.$lastid.'",'.$lastscore.','.$lasttotal.','.$lastscorech.');\'><img src="'.$imglast.'" border="0" title="change the score" style="vertical-align: middle;"/></a>';
  		 }
  		 $grades.='</td>'; 
  		 $grades.='</tr>';
  	  	
  		} 
  	  $grades.='</table>';
  		$grades.='</p>';
  		
  		//format html
	}

	$b->AddSubMenuItem("Item Analysis","viewSubjectCorrectRate.php?aid=".$aid."&cid=".""."&subjectTotal=".$subjectTotal);
	
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	

	
	
	
	
	
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// - Drop out
	//
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<p>Below are students' grades for  <b><? echo(strtoupper($aname)); ?> </b><? echo(strtolower($atype));?>.</p>
<? echo($grades); ?>
<script language="javascript" src="scripts/dialog.js"></script>
<script language="javascript" src="scripts/sendrequest.js"></script>
<script language="javascript" src="scripts/changescore.js"></script>
<script language="javascript" src="scripts/openta.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>