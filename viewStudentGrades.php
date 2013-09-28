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
	$problemNum=0;

	
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
	
	$sql="select max(problemId) from problems";
	$dsproblemCount=$con->Query($sql);
	while($drproblemCount=mysql_fetch_row($dsproblemCount))
	{
		$problemNum=$drproblemCount[0];
		for($i=1;$i<=$drproblemCount[0];$i++)
		{
			$problemCorrectNum[$i]=0;
			$problemTotalNum[$i]=0;
			$problemNoSimpleNum[$i]=0;
			$problemCorrectRate[$i]=0;
		}
	}	

	
	$grades.='<p>';
	$grades.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$grades.='<tr>';
		$grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Problem</td>';
		$grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Attempts</td>';
		$grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Correct Attempts</td>';
		$grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Simplify Error</td>';
	  $grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Percentage Correct</td>';
		$grades.='</tr>';
	
	
	$sql="SELECT distinct assignmentTakeId,title FROM assignmenttakes";
	$sql.=",assignments WHERE ( assignmenttakes.fk_user_taker=".$id;
	$sql.=" AND assignmenttakes.done=1 and fk_assignment=assignmentId);";
	$dsAssignmentTake=$con->Query($sql);
	while($drAssignmentTake=mysql_fetch_row($dsAssignmentTake))
	{
		$sql="select assignmenttakequestionid,fk_assignmenttake,fk_problem,result from assignmenttakequestions where fk_assignmentTake=".$drAssignmentTake[0];
		$dsContent = $con->Query($sql);
		while($drContent=mysql_fetch_row($dsContent))
		{
			$problemTotalNum[(int)$drContent[2]]++;
			if($drContent[3]==1||$drContent[3]==2)
				$problemCorrectNum[(int)$drContent[2]]++;
			if($drContent[3]==3)
				$problemNoSimpleNum[(int)$drContent[2]]++;
		}
	}
	
	for($j=1;$j<=$problemNum;$j++)
	{
		if($problemTotalNum[$j]!=0)
		{
			$problemCorrectRate[$j]=round($problemCorrectNum[$j]/$problemTotalNum[$j],4)*100;
			$grades.='<tr>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	<a href="#" onclick="openp('.$j.')" >P'.$j.'</a></td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='  '.$problemTotalNum[$j].'</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='	'.$problemCorrectNum[$j].'</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='  '.$problemNoSimpleNum[$j].'</td>';
			$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
			$grades.='  '.$problemCorrectRate[$j].'%</td>';				
			$grades.='</tr>';
		}	
	}
	
		//foreach($problemCorrectNum as $k => $v)
		//print $k."=>".$v."<br>";
	$grades.='</table>';
	$grades.='</p>';
	//
	// - Drop out
	//
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Your Credentials</h1>
<p>
<b>First Name:</b> <? echo($fName); ?>
<br /><b>Last Name:</b> <? echo($lName); ?>
<br /><b>Email Address:</b> <? echo($email); ?>
</p>
<h1>Your Correct Rate Of Each Problem</h1>
<p>Below are <? echo(strtoupper($fName)); ?>'s correct rate of each problem that <? echo(strtoupper($fName)); ?> has token.</p>
<? echo($grades); ?>

<script language="javascript" src="scripts/showproblem.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>