<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("View Student's Best and Last Grades Information","");
	$b->ActiveMenu=15;
	$b->MainMenuIndex=15;
	
	$con=new DatabaseManager();
	$id="";
	$email="";
	$fName="";
	$lName="";
	$grades='';
		if($b->User->Type==3)
	{
		$id=$b->User->UserId;
	}
	else
	{
		$id=$_GET["id"];
	}
	$b->AddSubMenuItem("All Grades","viewStudent1.php?id=$id");
	$b->AddSubMenuItem("Item Analysis","viewStudentGrades.php?id=$id");
	//
	// - User's Credentials
	//
	$sql="SELECT email,firstName,lastName";
	$sql.=" FROM users";
	$sql.=" WHERE ( userId = " . $id . " )";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$email=$dr[0];
		$fName=$dr[1];
		$lName=$dr[2];
	}	
	//
	// - Create list
	//
	if($b->User->Type==3)
	{
	 $sql="SELECT studentenrollment.fk_course,courses.title";
	 $sql.=" FROM studentenrollment";
	 $sql.="  INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	 $sql.=" WHERE (courses.active=1 and studentenrollment.fk_user=" . $id . " )";
	 $sql.=" GROUP BY studentenrollment.fk_course";
	 $sql.=" ORDER BY studentenrollment.active DESC";
	}else
	{
	 $sql="SELECT studentenrollment.fk_course,courses.title";
	 $sql.=" FROM studentenrollment";
	 $sql.="  INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	 $sql.=" WHERE courses.active=1 and fk_user_teacher=" .$b->User->UserId ;
	 $sql.=" GROUP BY studentenrollment.fk_course";
	 $sql.=" ORDER BY studentenrollment.active DESC";
	}
	$ds=$con->Query($sql);

	$b->AddScriptMethods($script);
	$n=0;
	while($dr=mysql_fetch_row($ds))
	{
		$n++;
		$i=0;
		$grades.='<p>';
		$grades.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$grades.='<tr>';
		$grades.='	<td><h2>'. $dr[1] ;
		$grades.='	</h2></td>'; 
		$grades.='	<td>';
		$grades.='	</td>';
		$grades.='	<td colspan="2" align="right">';
		$grades.='	</td>';
		$grades.='</tr>';
		$grades.='<tr>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Assignment Name</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="assignmentId"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Assignment ID</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="assignmentId"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Type</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="grade" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Best Grade</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="started"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Recent Grade</td>';
		$grades.='</tr>';
		$cid=$dr[0];
		$sql="SELECT  distinct fk_assignment,assignments.title,_list_assignmenttypes.title";
		$sql.=" FROM assignmenttakes";
		$sql.="  INNER JOIN assignments ON assignments.assignmentId=assignmenttakes.fk_assignment";
		$sql.="  INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
		$sql.=" WHERE ( assignmenttakes.fk_user_taker=" . $id . " AND assignmenttakes.fk_course=" . $cid . " AND assignmenttakes.done=1 )";
		$sDs=$con->Query($sql);
		$added=FALSE;
		$aname="";
		while($sDr=mysql_fetch_row($sDs))
		{
      $sql="SELECT assignmenttakes.assignmentTakeId,assignmenttakes.finished,correctAnswers,incorrectAnswers,correctAnswersch,chDate";
		  $sql.=" FROM assignmenttakes";
		  $sql.=" WHERE ( fk_user_taker=" . $id . " AND assignmenttakes.fk_assignment=" . $sDr[0] . " AND assignmenttakes.done=1 )";
	    $sql.=" Order by correctAnswersch desc,assignmenttakes.finished desc limit 1";
	    $sDs1=$con->Query($sql);
	    $added=TRUE;
	    $bestscore=0;
	    $bestscorech="-1";
	    $aname=$sDr[1];
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
	      $chdate=$sDr1[5]; 
      }
      $sql="SELECT assignmenttakes.assignmentTakeId,assignmenttakes.finished,correctAnswers,incorrectAnswers,correctAnswersch,chDate";
		  $sql.=" FROM assignmenttakes";
		  $sql.=" WHERE ( fk_user_taker=" . $id . " AND assignmenttakes.fk_assignment=" . $sDr[0] . " AND assignmenttakes.done=1 )";
	    $sql.=" Order by assignmenttakes.finished desc, assignmentTakeId desc limit 1";
	    $sDs1=$con->Query($sql);
	    $lastscore=30;
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
			 $grades.='	' . $sDr[1] . '&nbsp;</td>';
			 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			 $grades.='	' . $sDr[0] . '&nbsp;</td>';
			 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			 $grades.='	' . $sDr[2] . '&nbsp;</td>';
			 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			
			 $img='pics/changescore3.png';
			 if($chdate!="")
  		 {
  		 	 $img='pics/changescore2.png';
  		 }
  		 $chimg="";
  		 if($b->User->Type==2)
  		 {
  		 	 $chimg='<a href="#" onClick=\'changesc("'. $fName .'","'.$lName.'","'.$aname.'","'.$bestid.'",'.$bestscore.','.$besttotal.','.$bestscorech.');\'><img src="'.$img.'" border="0" title="change the score" style="vertical-align: middle;"/></a>';
  		 }
  		 
  		 $imglast='pics/changescore3.png';
			 if($chdatelast!="")
  		 {
  		 	 $imglast='pics/changescore2.png';
  		 }
  		 $chimglast="";
  		 if($b->User->Type==2)
  		 {
  		 	 $chimglast='<a href="#" onClick=\'changesc("'. $fName .'","'.$lName.'","'.$aname.'","'.$lastid.'",'.$lastscore.','.$lasttotal.','.$lastscorech.');\'><img src="'.$imglast.'" border="0" title="change the score" style="vertical-align: middle;"/></a>';
  		 }
  		 
			 $grades.='	<a href="javascript:openta(3,' . $sDr[0] . ','.$cid.','.$bestid.')" title="Date Taken: '. $bestfinish .'">' . $bestscorech.'/'.$besttotal .'</a>&nbsp;'.$chimg;
      
		   $grades.='	</td><td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			 $grades.='	<a href="javascript:openta(3,' . $sDr[0] . ','.$cid.','.$lastid.')" title="Date Taken:'.$lastfinish.' ">' . $lastscorech.'/'.$lasttotal .'&nbsp;'.$chimglast;
		  	$grades.='</td></tr>';
	  	
		}
		if($added==FALSE)
		{
			 $grades.='<tr>';
			 $grades.='	<td colspan="4" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="dueDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			 $grades.='	No assignments were submited for this class.</td>';
			 $grades.='</tr>';
		 }  
	  $grades.='</table>';
		$grades.='</p>';
		//format html		
	}

	//
	// - Drop out
	//
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>User's Credentials</h1>
<p>
<b>First Name:</b> <? echo($fName); ?>
<br /><b>Last Name:</b> <? echo($lName); ?>
<br /><b>Email Address:</b> <? echo($email); ?>
</p>
<h1>User's Grades</h1>
<p>Below are <? echo(strtoupper($fName)); ?>'s grades for each in which <? echo(strtoupper($fName)); ?> is or has been enrolled.</p>
<? echo($grades); ?>
<script language="javascript" src="scripts/dialog.js"></script>
<script language="javascript" src="scripts/sendrequest.js"></script>
<script language="javascript" src="scripts/changescore.js"></script>
<script language="javascript" src="scripts/openta.js"></script>


<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>