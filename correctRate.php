<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	
	$b->AddCrumb("Item Analysis","");
	$b->ActiveMenu=23;
	$b->MainMenuIndex=23;
	
	$con=new DatabaseManager();
	
	
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
		$grades.='	<td align="center" width="15%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Problem</td>';
		$grades.='	<td align="center" width="15%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Attempts</td>';
		$grades.='	<td align="center" width="15%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Correct Attempts</td>';
		$grades.='	<td align="center" width="15%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Simplify Error</td>';
	  $grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Percentage Correct</td>';
		$grades.='	<td align="center" width="20%" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
		$grades.='	Answer Detail</td>';
		$grades.='</tr>';
	
	
		$sql="select assignmenttakequestionid,fk_assignmenttake,fk_problem,result from assignmenttakequestions";
		$dsContent = $con->Query($sql);
		while($drContent=mysql_fetch_row($dsContent))
		{
			$problemTotalNum[(int)$drContent[2]]++;
			if($drContent[3]==1||$drContent[3]==2)
				$problemCorrectNum[(int)$drContent[2]]++;
			if($drContent[3]==3)
				$problemNoSimpleNum[(int)$drContent[2]]++;
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
				$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$grades.='  <a href="answerKindAdmin.php?number='.$j.'&page=1" >Answer Detail For P'.$j.'</a></td>';	
				$grades.='</tr>';
			}	
		}
	
	$grades.='</table>';
	$grades.='</p>';
	//
	// - Drop out
	//
	$con->Dispose();	
	$b->RenderTemplateTop();
?>

	<p>Below are the correct rates for each problem.</p>
	<input type="hidden" id="course" value="1"></input>
	<? echo($grades); ?>
	<script language="javascript" src="scripts/showproblem.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>