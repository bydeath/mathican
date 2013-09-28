<script type="text/javascript" src="mathEdit/mathplayer.js"></script>
<script type="text/javascript" src="mathEdit/mathedit/infix.js"></script>
<script type="text/javascript" src="mathEdit/mathedit/editing.js"></script>
<script type="text/javascript" src="scripts/ajax.js"></script>
<link rel="stylesheet" type="text/css" href="globals.css" />

<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	include_once("base/layoverGenerator.php");

	include_once("base/gen_func.inc");
	include_once("base/rand_gen.inc");
	include_once("base/str_funcs.inc");
	include_once("base/reduce.inc");
	include_once("base/rand_switch_sign.inc");
	include_once("base/parsers.inc");
	include_once("base/answer_input.inc");
	include_once("base/question_retrieve.inc");
	
	
	$number=$_GET["number"];
	$page=$_GET["page"];
	$pageSize=200;
	$c=0;
	$flag=0;
	$b->AddCrumb("The kind of answers for P".$number.".","");
	$b->ActiveMenu=23;
	$b->MainMenuIndex=23;

	$con=new DatabaseManager();
	
	$b->AddSubMenuItem("Update The Kind Of User Answers","updateAnswerKind.php?number=".$number);
	$b->AddSubMenuItem("Item Analysis","correctRate.php");
	
  $answerkind='<p>';
	$answerkind.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
	$answerkind.='<tr>';
  $answerkind.='	<td align="center" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$answerkind.='	Problems</td>';
	$answerkind.='	<td align="center" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$answerkind.='	Standard Answers</td>';
	$answerkind.='	<td align="center" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$answerkind.='	User Answers</td>';
  $answerkind.='	<td align="center" style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort".$n]=="" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$answerkind.='	Attempts</td>';
	$answerkind.='</tr>';
	
	$sql="select count(*) from kindofanswers where fk_problem=".$number;
	$dscount=$con->Query($sql);
	$drcount=mysql_fetch_row($dscount);
	$totalPage=((int)$drcount[0])/$pageSize+1;
	//	select * from users limit (pageNo-1)*pageSize,pageSize;
	
	$sql="select * from kindofanswers where fk_problem=".$number." order by questions asc limit ".(($page-1)*$pageSize).",".$pageSize;
	$dsp=$con->Query($sql);
	while($drp=mysql_fetch_row($dsp))
	{
		  $q_out = parse_question($drp[2],(int)$number,$c);
		  if($drp[7]==1)
		  {
			  $answerkind.='<tr>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$q_out.'</td>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$drp[3].'</td>';
        if(strcmp($drp[6],"YES")==0)
				{
					$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				}else
				{
					$answerkind.='	<td style="border-bottom-style:dashed;color:red;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				}
				$answerkind.='	'.$drp[4].'</td>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$drp[5].'</td>';
			  $answerkind.='</tr>';
		  }else
		  {
		  	$answerkind.='<tr>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:#E8E8E8;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$q_out.'</td>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:#E8E8E8;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$drp[3].'</td>';
				if(strcmp($drp[6],"YES")==0)
				{
					$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:#E8E8E8;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				}else
				{
					$answerkind.='	<td style="border-bottom-style:dashed;color:red;border-bottom-width:1px;border-bottom-color:black;background-color:#E8E8E8;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				}
				$answerkind.='	'.$drp[4].'</td>';
				$answerkind.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:#E8E8E8;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$answerkind.='	'.$drp[5].'</td>';
			  $answerkind.='</tr>';
		  }
		  $c++;
  }
  $answerkind.='</table><br><br>';
  $answerkind.='<center>Page ';
  for($i=1;$i<= $totalPage;$i++)
  {
  	if($i==$page)
  	  $answerkind.='<a href="answerKindAdmin.php?number='.$number.'&page='.$i.'" ><font size="2" color="red"><b>'.$i.'&nbsp;&nbsp;</b></font></a>';
  	else
  		$answerkind.='<a href="answerKindAdmin.php?number='.$number.'&page='.$i.'" ><font size="2"><b>'.$i.'&nbsp;&nbsp;</b></font></a>';
  }
  $answerkind.='</center>';
	$answerkind.='</p>';
	
//	echo($retval);
	//
	// - Drop out
	//
	$con->Dispose();	
	$b->RenderTemplateTop();
?>
  <p>If the font color of the user answers is red, it represents that the answer is wrong.</p>
<?
  echo($answerkind);
	$b->RenderTemplateBottom();
	$b->Dispose();
?>