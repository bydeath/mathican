<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("View All Grades Information","");
	$b->ActiveMenu=15;
	$b->MainMenuIndex=15;
	
	$con=new DatabaseManager();
	$id="";
	$email="";
	$fName="";
	$lName="";
	$grades='';
	
	//
	// - Get Student Id
	//
	if($b->User->Type==3)
	{
		$id=$b->User->UserId;
	}
	else
	{
		$id=$_GET["id"];
	}
	$b->AddSubMenuItem("Best and Last Grades","viewStudent.php?id=$id");
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
	 $sql.=" WHERE (courses.active=1 and studentenrollment.fk_user=" . $id . " and fk_user_teacher=" .$b->User->UserId .")";
	 $sql.=" GROUP BY studentenrollment.fk_course";
	 $sql.=" ORDER BY studentenrollment.active DESC";
	}
	$ds=$con->Query($sql);
	$script='function sortf(n,t)';
	$script.='{';
	$script.='  if(t==null)t="'.$_GET["sort"].'";';
	$script.='	var link="viewStudent1.php";';
	if($_GET["id"]!="")
	{
	  $script.='	link+="?id='.$_GET["id"].'&";';
	}else
	{
		$script.='	link+="?";';
	}
	$script.='	link+="sort"+n+"="+t+"&filter"+n+"="+ GetBrowserElement("ddl_filter"+n).options[GetBrowserElement("ddl_filter"+n).selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);
	$n=0;
	while($dr=mysql_fetch_row($ds))
	{
		$n++;
		$cid=$dr[0];
		$sql="SELECT distinct fk_assignment";
		$sql.=" FROM assignmenttakes";
		$sql.=" WHERE ( assignmenttakes.fk_user_taker=" . $id . " AND assignmenttakes.fk_course=" . $cid . " AND assignmenttakes.done=1 )";
		$sDs1=$con->Query($sql);
		$i=0;
		while($sDr1=mysql_fetch_row($sDs1))
		{
		 $filter.='<option value="' . $sDr1[0] . '">';
		 $filter.=$sDr1[0];
		 $filter.='</option>';
		 $i++;
		 if($sDr1[0]==$_GET["filter".$n])
		 {
			$selectedFilter=$i;
		 }
		}
		if($selectedFilter!="")
	  {
		 $script='GetBrowserElement("ddl_filter'.$n.'").selectedIndex=' . $selectedFilter . ';';
		 $b->AddGenericScript($script);
	  }
		$sql="SELECT assignmenttakes.assignmentTakeId,assignments.title,assignmenttakes.started,assignmenttakes.finished,chDate,assignments.assignmentId,correctAnswers,incorrectAnswers,correctAnswersch,startDate,dueDate";
		$sql.=" FROM assignmenttakes";
		$sql.="  INNER JOIN assignments ON assignments.assignmentId=assignmenttakes.fk_assignment";
		$sql.=" WHERE ( assignmenttakes.fk_user_taker=" . $id . " AND assignmenttakes.fk_course=" . $cid . " AND assignmenttakes.done=1 ";
		if($_GET["filter".$n]!="" && $_GET["filter".$n]!="0")
	  {
	  	$sql.="and assignmenttakes.fk_assignment=" . $_GET["filter".$n] . "";
	  }
	  $sql.=")";
	  if($_GET["sort".$n]!=NULL)
	  {
	  	$sql.=" order by " . $_GET["sort".$n];
	  }
	  
		 $sDs=$con->Query($sql);
		//format html
		$grades.='<p>';
		$grades.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$grades.='<tr>';
		$grades.='	<td><h2>'. $dr[1] ;
		$grades.='	</h2></td>'; 
		$grades.='	<td>';
		$grades.='	</td>';
		$grades.='	<td colspan="4" align="right">Showing grades for:<select id="ddl_filter'.$n.'" name="ddl_filter'.$n.'" onchange="javascript:sortf('.$n.');"><option value="0">All Assignments</option>'.$filter.'</select>';
		$grades.='	</td>';
		$grades.='</tr>';
		$grades.='<tr>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="assignmentTakeId" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Attempt ID<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'assignmentTakeId\')" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="aname" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Assignment Name</td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="assignmentId"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Assignment ID<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'assignmentId\')" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="correctAnswers" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Grade<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'correctAnswers\')" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="started"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Date Taken<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'started\')" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="startDate"? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Open<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'startDate\')" /></td>';
		$grades.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="dueDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Due<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="sortf('.$n.',\'dueDate\')" /></td>';
		$grades.='</tr>';
		$added=FALSE;
		
		while($sDr=mysql_fetch_row($sDs))
		{
			$added=TRUE;
			
			//figure out number of questions

			//write html
			$grades.='<tr>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	<a href="javascript:openta(3,' . $sDr[5] . ','.$cid.','.$sDr[0].')" title="Click to view this assignment" class="black">' . $sDr[0] . '</a>&nbsp;</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	<a href="javascript:openta(3,' . $sDr[5] . ','.$cid.','.$sDr[0].')" title="Click to view this assignment" class="black">' . $sDr[1] . '</a>&nbsp;</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	' . $sDr[5] . '&nbsp;</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$img='pics/changescore3.png';
			if($sDr[4]!="")
  		{
  		 	 $img='pics/changescore2.png';
  		}
  		$chimg="";
  		if($b->User->Type==2)
  		{
  		 	$chimg='<a href="#" onClick=\'changesc("'. $fName .'","'.$lName.'","'.$sDr[1].'","'.$sDr[0].'",'.$sDr[6].','.$sDr[7].','.$sDr[8].');\'><img src="'.$img.'" border="0" title="change the score" style="vertical-align: middle;"/></a>';
  		}
			$grades.='	' . $sDr[8] . '/' . ($sDr[6]+$sDr[7]) . '&nbsp;'.$chimg;
			
			$grades.='	</td><td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	' . $sDr[2] . '&nbsp;</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	' . $sDr[9] . '&nbsp;</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	' . $sDr[10] . '&nbsp;</td>';
			$grades.='</tr>';
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