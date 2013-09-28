<?
		include_once("base/baseForm.php");
		include_once("base/databaseManager.php");
		
		$b->AddCrumb("View each problem correct rate ","");
		$b->ActiveMenu=15;
		$b->MainMenuIndex=15;
		
		$b->SecurePage("2");
		$b->AddSubMenuItem("View students' grade","viewGrades.php?aid=".$_GET["aid"]."&cid=".$_GET["cid"]);
		
		
		$con=new DatabaseManager();
		$aid=$_GET["aid"];
		$cid=$_GET["cid"];	
		$subjectTotal=$_GET["subjectTotal"];

	 	for($i=0;$i < $subjectTotal;$i++) {
  		$subjectnumber[]=0;	
  	}

  	$sTotal=0;
	
	
	
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


  while($dr=mysql_fetch_row($ds))
  { 	
  	$aname=$dr[2];
  	$atype=$dr[3];
  	$sql="SELECT studentenrollment.fk_user,firstName,lastName,email";
  	$sql.=" FROM studentenrollment";
  	$sql.=" INNER JOIN users on users.userId=studentenrollment.fk_user";
  	$sql.=" WHERE studentenrollment.fk_course=".$dr[0];

  	$sds=$con->Query($sql);
  	$n=0;
  	while($sdr=mysql_fetch_row($sds))
  	{
  		$added=FALSE;
      $sql="SELECT assignmenttakes.assignmentTakeId,assignmenttakes.finished,correctAnswers,incorrectAnswers,correctAnswersch,chDate";
  		$sql.=" FROM assignmenttakes";
  		$sql.=" WHERE ( fk_user_taker=" . $sdr[0] . " AND assignmenttakes.fk_assignment=" . $aid . ")";//AND assignmenttakes.done=1 
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

  			 //write html
		 
  		 
  		 if($bestscore!="-1")
  		 {
  		 	 $sTotal++;
  		 	 $sql="select * from assignmenttakequestions where fk_assignmenttake=".$bestid;
  		 	 $dscrs=$con->Query($sql);
  			 
  			 $i=0;
	  		 while($drcrs=mysql_fetch_row($dscrs)){ 	 
	  			 if($drcrs[11]==1||$drcrs[11]==2) {
	  				 $subjectnumber[$i]++;
	  			 }
	  			 $i++;
	  		 }
  		 }
  	  	
  	} 
		$grades.='<p>';
		if($sTotal>1)
  		$grades.='<br>Below are correct times and correct rate of the problems in this '.strtolower($atype).' . Each problem has been done '.$sTotal.' times .';
		else
			$grades.='<br>Below are correct times and correct rate of the problems in this '.strtolower($atype).' . Each problem has been done '.$sTotal.' time .';
		$grades.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$grades.='<tr>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Problem #</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Number correct</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Percentage correct</td>';
		$grades.='</tr>';
		

		$sql="select fk_problem from assignmentquestions where fk_assignment=".$aid;
		$dsnumber=$con->Query($sql);
		
		
			$num=0;
			  
			for($i=0;$i<(int)($subjectTotal);$i++){  
				
				$drnumber=mysql_fetch_row($dsnumber);
			  $grades.='<tr>';
				$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$grades.='	<a href="#" onclick="openp('.$drnumber[0].')" >No. '.($num+1).'</a></td>';
				//echo "<br>".$drnumber[0];
				
				$frate=round($subjectnumber[$num]/$sTotal,4)*100;
				
				$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$grades.='	'.$subjectnumber[$num].'</td>';
				$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$grades.='	'.$frate.'%</td>';
					$num++;
			  $grades.='</tr>';
			}
  	  $grades.='</table>';
  		$grades.='</p>';
  		//format html
	}
	
	

	$con->Dispose();
	$b->RenderTemplateTop();
?>

<p>Below are correct rates for each problem in <b><? echo(strtoupper($aname)); ?> </b><? echo(strtolower($atype));?>.</p>
<? echo($grades); ?>
<script language="javascript" src="scripts/dialog.js"></script>
<script language="javascript" src="scripts/sendrequest.js"></script>
<script language="javascript" src="scripts/changescore.js"></script>
<script language="javascript" src="scripts/openta.js"></script>
<script language="javascript" src="scripts/selectproblem.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>