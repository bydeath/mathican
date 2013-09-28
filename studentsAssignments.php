<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	
	$b->SecurePage(3);
	$b->MainMenuIndex=9;
	
	$b->AddCrumb("Your Assignments","");
	
	//
	// - Members
	//
	global $con;
	$con=new DatabaseManager();
	$list='';
	
	//
	// - Filter Script
	//
	$b->AddScriptMethods($script);
	
	//
	// - Generate list
	//
	$sql="SELECT courses.courseId,courses.title,courses.courseId";
	$sql.=" FROM studentenrollment";
	$sql.="  INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	$sql.=" WHERE ( courses.active=1 AND studentenrollment.active=1 AND fk_user=" . $b->User->UserId . " )";
	$ds=$con->Query($sql);
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		//create header and table
		$list.='<h2>' . $dr[1] . '</h2>';
		$list.='<p>';
		$list.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$list.='	<tr>';
		$list.='		<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
		$list.='		&nbsp;</td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$list.='		Assignment Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'studentsAssignments.php?sort=assignments.title&filter=' . $_GET["filter"] . '\';" /></td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$list.='		Id</td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$list.='		Type&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'studentsAssignments.php?sort=_list_assignmenttypes.title&filter=' . $_GET["filter"] . '\';" /></td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="startDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$list.='		Open Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'studentsAssignments.php?sort=startDate&filter=' . $_GET["filter"] . '\';" /></td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="dueDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$list.='		Due Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'studentsAssignments.php?sort=dueDate&filter=' . $_GET["filter"] . '\';" /></td>';
		$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="takes" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$list.='		Taken Times/Allowed&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'studentsAssignments.php?sort=takes&filter=' . $_GET["filter"] . '\';" /></td>';
		$list.='	</tr>';
		
		//add assignments
		$sql="SELECT assignments.assignmentId,assignments.title,_list_assignmenttypes.title,assignments.startDate,assignments.dueDate,takes";
		$sql.=" FROM assignments";
		$sql.="  INNER JOIN assignmentcourses ON assignmentcourses.fk_assignment=assignments.assignmentId";
		$sql.="  INNER JOIN _list_assignmenttypes ON _list_assignmenttypes.assignmentTypeId=assignments.type";
		$sql.=" WHERE ( assignments.active=1 AND assignmentcourses.fk_course=" . $dr[2] . " AND assignmentcourses.active=1 )";
		if($_GET["sort"])
		{
			$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
		}
		$sDs=$con->Query($sql);
		while($sDr=mysql_fetch_row($sDs))
		{
			$added=TRUE;
			$due=strtotime($sDr[4]);
			$start=strtotime($sDr[3]);
			//$d=getdate();
			//$today=strtotime($d[5] . "-" . $d[8] . "-" . $d[3]);
			$today=strtotime("now");
			//$today=date("Y-m-d");
			$list.='	<tr>';
			$list.='		<td style="background-color:#ffffff;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
			if($today<=$due && $today>=$start)
			{
				//$list.='<script language="javascript">alert("'.$dr[0].'");</script>';
				$list.='		' . GetOptions($sDr[0],$dr[0]);
			}
			$took=tooktimes($sDr[0]);
			$list.='		&nbsp;</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . $sDr[1] . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$list.='		' . $sDr[0] . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . $sDr[2] . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="startDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . substr($sDr[3],0,10) . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="dueDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . substr($sDr[4],0,10) . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="takes" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		'.$took.'/' . ($sDr[5]=="999"?"unlimited":$sDr[5]) . '</td>';
			$list.='	</tr>';
		}
		
		//empty message
		if($added==FALSE)
		{
			$list.='	<tr>';
			$list.='		<td colspan="5" style="border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:white;">';
			$list.='		You have no assignments.</td>';
			$list.='	</tr>';
		}
		$list.='</table>';
		$list.='</p>';
	}
	
	function GetOptions($assId,$courseId)
	{
		global $con;
		global $b;
		$retval='';
		
		$takes=1;
		//$took=0;
		
		//takes
		$sql="SELECT takes,password";
		$sql.=" FROM assignments";
		$sql.=" WHERE assignmentId=" . $assId;
		$ds=$con->Query($sql);
		$pw="";
		while($dr=mysql_fetch_row($ds))
		{
			$takes=((int)$dr[0]);
			$pw=$dr[1];
		}
		
		//took

		$took=tooktimes($assId);
		//determin if there are any assignments to be finished
		$sql="SELECT assignmentTakeId,done";
		$sql.=" FROM assignmenttakes";
		$sql.=" WHERE ( active=1 AND fk_user_taker=" . $b->User->UserId . " AND fk_assignment=" . $assId . " )";
		$sql.=" ORDER BY assignmentTakeId ASC";
		$ds=$con->Query($sql);
		$unfinished=0;
		while($dr=mysql_fetch_row($ds))
		{
			//echo '<script language="javascript">alert("'.$dr[1].'");</script>';
			if($dr[1]=="0")
			{
				$retval="<a href='javascript:openta(\"takeAssignment.php?openmode=2&id=" . $assId . "&cid=" . $courseId . "&finish=" . $dr[0] . "\",\"".$pw."\")'><img src='pics/finish.gif' alt='Finish this assignment that you`ve already started' border='0' /></a>";
			  $unfinished=1;
			}
			else
			{
				$retval='';
			}
		}
		
		if($took<$takes && $unfinished==0)
		{
			if($retval!='')
			{
				$retval.='&nbsp;';
			}
			$retval.="<a href='javascript:openta(\"takeAssignment.php?openmode=2&id=" . $assId . "&cid=". $courseId ."\",\"".$pw."\")'><img src='pics/fillOut.gif' alt='Take this assignment' border='0' /></a>";
		}
		
		return $retval;
	}
	function tooktimes($assId)
	{
		global $b;
		global $con;
		$sql="SELECT COUNT(*)";
		$sql.=" FROM assignmenttakes";
		$sql.=" WHERE ( active=1 AND fk_user_taker=" . $b->User->UserId . " AND fk_assignment=" . $assId . " )";
		//echo($sql);
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$took=((int)$dr[0]);
		}
		return $took;
	}
	function GetStatus($assId)
	{
		global $b;
		global $con;
		$sql="SELECT done";
		$sql.=" FROM assignmenttakes";
		$sql.=" WHERE ( fk_assignment=" . $assId . " AND active=1 AND fk_user_taker=" . $b->User->UserId . " )";
		$sql.=" ORDER BY assignmentTakeId ASC";
		//echo($sql);
		$d=$con->Query($sql);
		$retval="Not Started";
		while($dr=mysql_fetch_row($d))
		{
			$retval="Started";
			if($dr[0]=="1")
			{
				$retval="Done";
			}
		}
		return $retval;
	}
	
	//
	// - Drop out
	//
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Below is your list of assignments. Each assignment has an open date and a due date, you must complete the assignment between these two dates. For some assignments you may be allowed to have one or several retakes, review the "Takes" column to find out which assignments can. To take an assignment, click on the "take assignment" icon to the left of the assignment name.</p>

<h1>Your Assignments</h1>
<p>
<? echo($list); ?>
</p>
<script language="javascript">
	function openta(aurl,pw)
	{
		var userpw="";
		if(pw!="")
		{
			userpw=prompt("Please Enter Password for This Assignment:","");
			if(userpw==null)
			{
				return;
			}
			if(userpw!=pw) 
			{
				alert("The Password is not Correct");
				return;
			}
		}
		document.location=aurl;
	}
</script>
<?
	$con->Dispose();
	$b->RenderTemplateBottom();
	$b->Dispose();
?>