<?
  include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

  global $con;
  $con=new DatabaseManager();
	$cid=$_GET['cid'];
	$aids = $_GET['aid'];
	//$aid=split(",",$aids);
  $aid=explode(",",$aids);
  $dt=$_GET['dt'];
  $sql="SELECT courses.title";
  $sql.=" FROM courses";
  $sql.=" WHERE courses.courseId=".$cid;
  $ds=$con->Query($sql);
  $ctitle="";
  while($dr=mysql_fetch_row($ds))
  {
  	$ctitle=$dr[0];
  }
	$sql="SELECT assignments.title,_list_assignmenttypes.title";
  $sql.=" FROM assignments";
  $sql.=" INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
  $sql.=" WHERE assignmentId=" .$aid[0] ;
  for($i=1;$i<count($aid);$i++)
  {
  	$sql.=" or assignmentId=".$aid[$i] ;
  }
	$sql.=" order by assignments.assignmentId";
  $ds=$con->Query($sql);
  $anamearr=array();
  $i=0;
  $grades.='<p>';
  $grades.=' <h3>The students\' grades in the class <b>'.strtoupper($ctitle).'</b></h3>';
	$grades.='<table width="90%" border="0" cellpadding="2" cellspacing="0">';
	$grades.='<tr>';
	$grades.='	<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;width:60">';
	$grades.='	Name</td>';
	
  while($dr=mysql_fetch_row($ds))
  {
  	$grades.='	<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
		$grades.='	'.$dr[0].'</td>';
  }
	$grades.='</tr>';
  $sql="SELECT studentenrollment.fk_user,firstName,lastName,email";
  $sql.=" FROM studentenrollment";
  $sql.=" INNER JOIN users on users.userId=studentenrollment.fk_user";
  $sql.=" WHERE studentenrollment.fk_course=".$cid;
  $sql.=" order by lastName,firstName";
  $sds=$con->Query($sql);
  $n=0;
  while($sdr=mysql_fetch_row($sds))
  {
  	
  	$grades.='<tr>';	
  	$grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
  	$grades.='	' . $sdr[2].', '.$sdr[1] . '&nbsp;</td>';
  	for($i=0;$i<count($aid);$i++)
    {
    	$sql="SELECT correctAnswers,correctAnswers+incorrectAnswers,correctAnswersch";
      $sql.=" FROM assignmenttakes";
      $sql.=" WHERE fk_user_taker=" . $sdr[0] . " AND fk_assignment=".$aid[$i];
      $sql.=" order by correctAnswersch desc,assignmentTakeId desc limit 1";
      $sDs1=$con->Query($sql);
      if(mysql_num_rows($sDs1)==0)
      {
      	 $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white; text-align:center">';
  	     $grades.='	n/a&nbsp;</td>';   
      }
      else
      {
       while($sDr1=mysql_fetch_row($sDs1))
    	 {
  		  $grades.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;text-align:center">';
  	    $bs=$sDr1[2];
  	    if($dt=="1")
  	    {
  	     $res=round((int)$bs/(int)$sDr1[1]*100,2);
  	     $gra=(string)$res."%";
  	    }else if($dt=="2")
  	    {
  	    	$gra=$bs;
  	    }else
  	    {
  	    	$gra=$bs."/(".$sDr1[1].")";
  	    }
  	    $grades.='	' . $gra . '</td>';   
       }
      }
    }
    $n++;
    $grades.='</tr>';
  }
  $grades.='</table>';
  $grades.='</p>';  
?>
<html>
<head>
	<title>Export Students' Grades</title>
</head>
<body bgcolor="#F5F8F9">
    <form id="frm_body" name="frm_body" method="post" action="exportgradeexcel.php?cid=<? echo $cid; ?>&aid=<? echo $aids; ?>&dt=<? echo $dt; ?>">
		<p>
		<table id="tbl_" width="85%" border="0" align="center" cellpadding="2" cellspacing="0">
			<tr>
				<td>	
					<img src="pics/logo.png" alt="Math Pass V3.1" /></td>		
				</td>
			</tr>
			<tr>
				<td style="padding:5px 5px 5px 5px;border-style:solid;border-color:#b0b0b0;border-width:1px;background-color:#F5F8F9;text-align:center">
         <? echo( $grades);?>
      </td>
			</tr>
		</table>
		</p>
		<p align="center"><button type="submit" id="btn_submit" name="btn_submit" class="button1">Export to Excel File</button></p>
</form>
</body>
</html>
<?
 $con->Dispose();
 $b->Dispose();
?>