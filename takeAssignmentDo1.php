<?
	include_once("base/baseForm.php");
	include_once("base/layoverGenerator.php");

	include_once("base/gen_func.inc");
	include_once("base/rand_gen.inc");
	include_once("base/str_funcs.inc");
	include_once("base/reduce.inc");
	include_once("base/rand_switch_sign.inc");
	include_once("base/parsers.inc");
	include_once("base/answer_input.inc");
	include_once("base/question_retrieve.inc");
	include_once("base/check_answer.inc");
	include_once("base/u_answer_save.inc");
  $b->AddScript("scripts/base64.js");
	$b->AddScript("mathEdit/mathplayer.js");
	$b->AddScript("mathEdit/mathedit/infix.js");
	$b->AddScript("mathEdit/mathedit/editing.js");
	$b->AddScript("scripts/ajax.js");
	
	$b->AddScript("scripts/cheater.js");
	//
	// - Members
	//

	//properties
	$navigation='';
	$problems='';
	global $problemDescriptions;
	$problemDescriptions='';
  global $con;
  $con=new DatabaseManager();
  $openmode=$_GET[openmode];
	if($openmode==1)
	{
		$types=$_GET["types"];
	  $title="";
	  $list=split(",",$types);
	  $indivNumber=((int)$_GET["number"]);
	  $number=$indivNumber*count($list);
	  $type=1;
	}else if($openmode>=2)
  {
  	$id=$_GET["id"];
  	$cid=$_GET["cid"];
  	$finish=$_GET["finish"];
  	$title="";
  	$number=0;
  	$type="";
  	$pgTitle="";
  	
  	//
  	// - Populate essential vars
  	//
  	$sql="SELECT title,type";
  	$sql.=" FROM assignments";
  	$sql.=" WHERE ( assignmentId = " . $id . " )";
  	$ds=$con->Query($sql);
  	while($dr=mysql_fetch_row($ds))
  	{
  		$title=$dr[0];
  		$pgTitle=$title;
  		$type=$dr[1];
  	}
  	$sql0="SELECT numbers";
  	$sql0.=" FROM assignmentquestions";
  	$sql0.=" WHERE ( fk_assignment = " . $id . " )";
  	$ds0=$con->Query($sql0);
  	while($dr0=mysql_fetch_row($ds0))
  	{
  		$number=$number+(int)$dr0[0];
  	}
  }
	
	if($openmode==1 ||$openmode==3)
	{
	  $b->AddGenericScript('GetBrowserElement("btn_save").style.display="none";');
	  $b->AddGenericScript('GetBrowserElement("btn_submit").style.display="none";');
	}
	$b->AddCrumb($title,"");

	$sRun='';
	$sRun.='Init();';
	$b->AddGenericScript($sRun);

	$i=0;
	while($i<$number)//suwei-2008-4-5 $nu
	{
		$i=$i+1;
		
		//generate nav
		if($navigation!='')
		{
			$navigation.='&nbsp;';
		}
		if(($i-1)%25==0 && $i!=1)
		{
		  $navigation.='<br/>';
		}
		$navigation.='<span id="spn_questionLink_' . $i . '" class="questionLink0"><a href="javascript:GoTo(' . $i . ');" id="a_questionLink_' . $i . '">' . $i . '</a></span>';
	}


	function GenProblem($rn,$num,$qtype,$altType="",$a0="",$a1="",$a2="",$a3="",$a4="",$useranswer="",$active="0",$result1="0")
	{
		global $con;
		global $played;
		global $problemDescriptions;
		$retval='';
		$intro="";
		$select=$qtype;
		$played=$select;
		$problemDescriptions.=GenDescription($num,$select);
		$html_a='';
		$sqld="SELECT questionIntro";
   	$sqld.=" FROM problems";
   	$sqld.=" WHERE ( number=" . $select . " AND active=1 )";
   	$dsd=$con->Query($sqld);
   	while($drd=mysql_fetch_row($dsd))
   	{
   			$intro=$drd[0];
   	}
		if($rn==0)//$rn==0 means generate problem. $rn==1 means recover problem
		{   	 
   		$q=gen_question((int)$select);
   		$a=str_replace(" ","",$q[1]);
	  }else
	  {
   	  $a=str_replace(" ","",$a1);
   		$q=array($a0,$a1,$a2,$a3,$a4);		
	  }
	  if(($qtype>=156 && $qtype<=162) || ($qtype>=264 && $qtype<=266))
		{
			$matha='X is in &nbsp';
	  }
		$matha.='<center><div id="correcta_'.$num.'" class="question"></div><center>';
		if((($qtype>=156 && $qtype<=162) || ($qtype>=264 && $qtype<=266)) && $q[2]!="not_used" )
		{
			if(strpos($q[2],","))
			{
				$matha.='<br/>-And/Or-<br/><br/>';
		    $matha.='<center><div>X&#8800;&nbsp;<span  id="correcta1_'.$num.'" class="question"></span> And X&#8800;&nbsp;<span  id="correcta2_'.$num.'" class="question"></span></div><center>';
			}else
			{
			  $matha.='<br/>-And/Or-<br/><br/>';
		    $matha.='<center><div>X&#8800;&nbsp;<span id="correcta1_'.$num.'" class="question"></span></div><center>';
	    }
	  }
	  if(($qtype>=256 && $qtype<=263) ||($qtype>=281 && $qtype<=282) || ($qtype>=323 && $qtype<=326))
		{
			$qar=explode("@@",$q[1]);
			if($qar[2]!="n/a")
			{
			  $matha.='<br/>-Or-<br/><br/>';
		    $matha.='<center><div id="correcta1_'.$num.'" class="question"></div><center>';
		  }
	  }
	  if($qtype==297 || $qtype==299 || $qtype==301 || ($qtype>=303 && $qtype<=307))
	  {
	  	$matha.='<center><div class="question"><span  id="correcta1_'.$num.'" class="question"></span> U <span  id="correcta2_'.$num.'" class="question"></span></div><center>';
    }
    $matha.='<script type="text/javascript">';
    $matha.=' var correcta=document.getElementById("correcta_'.$num.'");';
    if(($qtype>=135 && $qtype<=139)|| $qtype==296 || $qtype==298 || $qtype==300 || $qtype==302)
    { 	
	    $matha.=' var co_'.$num.'=convertToPresentDOM("interval'.$q[1]. '",document);';
	  }else if($qtype==297 || $qtype==299 || $qtype==301 || ($qtype>=303 && $qtype<=307))
	  {
	  	$qar=explode("union",$q[1]);
	    $matha.=' var co1=convertToPresentDOM("interval'.$qar[0]. '",document);';
		  $matha.=' var correcta1=document.getElementById("correcta1_'.$num.'");';
		  $matha.=' correcta1.appendChild(co1);';
		  $matha.=' var co2=convertToPresentDOM("interval'.$qar[1]. '",document);';
		  $matha.=' var correcta2=document.getElementById("correcta2_'.$num.'");';
		  $matha.=' correcta2.appendChild(co2);';
	  }else if(($qtype>=156 && $qtype<=162) || ($qtype>=264 && $qtype<=266))
		{
		  $matha.=' var co_'.$num.'=convertToPresentDOM("interval'.$q[1]. '",document);';
		  if($q[2]!="not_used")
		  {
		   if(strpos($q[2],","))
			 {
			 	 $q2array=split(",",$q[2]);
			 	 $matha.=' var co1=convertToPresentDOM("'.$q2array[0]. '",document);';
		     $matha.=' var correcta1=document.getElementById("correcta1_'.$num.'");';
		     $matha.=' correcta1.appendChild(co1);';
		     $matha.=' var co2=convertToPresentDOM("'.$q2array[1]. '",document);';
		     $matha.=' var correcta2=document.getElementById("correcta2_'.$num.'");';
		     $matha.=' correcta2.appendChild(co2);';
			 }else
			 {
		     $matha.=' var co1=convertToPresentDOM("'.$q[2]. '",document);';
		     $matha.=' var correcta1=document.getElementById("correcta1_'.$num.'");';
		     $matha.=' correcta1.appendChild(co1);';
		   }
		  }
	  }else if($qtype>=163 && $qtype<=185)
	  {
	  	$qar=explode("@@",$q[1]);
	  	if($qtype<=179)
	  	{
	  		$x="x";
	  		$y="y";
	  	}else
	  	{
	  		switch($qtype)
	  	  {
	  	 	  case 180:$x="n";$y="A";break;
	  	 	  case 181:$x="t";$y="V";break;
	  	  	case 182:$x="n";$y="P";break;
	  	  	case 183:$x="a";$y="V";break;
	  	  	case 184:$x="n";$y="C";break;
	  	  	case 185:$x="n";$y="P";break;
	  	  }
	  	}
	  	if($qar[0]=="not_used")
	  	{
	  		if($qar[4]=="not_used")
	  		{
	  			$me=$x."=";
	  			if($qar[7]=="1")
	  		  {
	  			 $me.=$qar[6];
	  		  }else
	  		  {
	  			 $me.=$qar[6]."/".$qar[7];
	  		  }
	  		}else
	  		{
	  			$me=$y."=";
	  			if($qar[5]=="1")
	  		  {
	  			 $me.=$qar[4];
	  		  }else
	  		  {
	  			 $me.=$qar[4]."/".$qar[5];
	  		  }
	  		}
	  	}else
	  	{
	  		if($qar[1]=="1")
	  		{
	  			$me=$y."=".$qar[0].$x;
	  		}else
	  		{
	  			$me=$y."=".$qar[0]."/".$qar[1].$x;
	  		}
	  		if(strpos($qar[2],"-")===false)
	  		{
	  		 	 $me.="+";
	  		}
	  		if($qar[3]=="1")
	  		{
	  		  $me.=$qar[2];
	  		}else
	  		{
	  		  $me.=$qar[2]."/".$qar[3];
	  		}
	  	}
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("'.$me. '",document);';
	  }else if($qtype==189 )
	  {
	  	if($q[3]=="1")
	  	 $matha.=' correcta.innerHTML="A.'.$q[1].'";';
	  	if($q[3]=="2")
	  	 $matha.=' correcta.innerHTML="B.'.$q[1].'";';
	  	if($q[3]=="3")
	  	 $matha.=' correcta.innerHTML="C.'.$q[1].'";';
	  }else if($qtype==190 )
	  {
	  	$qa190=explode("@@",$q[1]);
      $matha.=' correcta.innerHTML="<table><tr><td rowspan=2><i>g</i>( <i>i</i> ) = </td><td rowspan=2><font size=7>{</font></td><td>'.$qa190[0].'<i>i</i></td><td>for <i>i</i> <u>&#60;</u> $'.$qa190[1].'</td></tr><tr><td> '.$qa190[2].'+ '.$qa190[3].'(<i>i</i> - '.$qa190[4].' )&nbsp;&nbsp;&nbsp; </td><td>for <i>i</i> &#62; $'.$qa190[5].'</td></tr></table>";';
	  }else if($qtype>=197 && $qtype<=198)
	  {
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("'.$q[1].'*10^'.$q[2].'",document);';
	  }else if($qtype==204)
	  {
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("log('.$q[1].')='.$q[2].'",document);';
	  }else if($qtype==205)
	  {
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("10^'.$q[1].'='.$q[2].'",document);';
	  }else if($qtype==208)
	  {
	  	$matha.=' correcta.innerHTML="<div>Initial Population:&nbsp;'.$q[1].'</div><div> Growth Rate:&nbsp;'.$q[2].'</div>";';
	  }else if(($qtype>=211 && $qtype<=213) || ($qtype>=220 && $qtype<=223))
	  {
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("P(t)='.$q[1].'*('.$q[2].')^t",document);';
	  }else if(($qtype>=256 && $qtype<=263) ||($qtype>=281 && $qtype<=282) || ($qtype>=323 && $qtype<=326))
	  {
	  	$qar=explode("@@",$q[1]);
	  	if(count($qar)<=1)
	  	{
	  		$matha.='var co_'.$num.'=convertToPresentDOM("x='.$q[1]. '",document);';
	  	}else
	  	{
	  		if($qar[0]=="n/a")
	  		{
	  			if($qtype>=323 && $qtype<=326)
	  			 $matha.='correcta.innerHTML="<div>It never happens.</div>";';
	  			else
	  			 $matha.='correcta.innerHTML="<div>The equation has no real solutions.</div>";';
	  		}else if($qar[2]=="n/a")
	  		{
	  			$qar1=$qar[0];
	  			 if($qar[1]!="1")$qar1="(".$qar1.")/".$qar[1];
	  			$matha.=' var co_'.$num.'=convertToPresentDOM("x='.$qar1. '",document);';
	  		}else
	  		{
	  			$qar1=$qar[0];
	  			if($qar[1]!="1")$qar1="(".$qar1.")/".$qar[1];
	  			$qar2=$qar[2];
	  			if($qar[3]!="1")$qar2="(".$qar2.")/".$qar[3];
	  			$matha.=' var co_'.$num.'=convertToPresentDOM("x='.$qar1. '",document);';
	  			$matha.=' var co1=convertToPresentDOM("x='.$qar2. '",document);';
		      $matha.=' var correcta1=document.getElementById("correcta1_'.$num.'");';
		      $matha.=' correcta1.appendChild(co1);';
	  		}
	  	}
	  }else if($qtype==267)
	  {
	  	$matha.=' var co_'.$num.'=convertToPresentDOM("N(t)='.$q[1].'*e^('.$q[2].'t)",document);';
	  }else if($qtype>=290 && $qtype<=291)
	  {
	  	$qar=explode("@@",$q[1]);
	  	$disin=$qar[0]." ".$qar[1]." ".$qar[2]." ".$qar[3];
	    if($qar[4]=="1")
	  	{
	  		$disin.=" Reflected about the x-axis ";
	    }
	    $matha.=' correcta.innerHTML="<div>'.$disin.'</div>";';
	  }else if($qtype>=294 && $qtype<=295)
	  {
	  	$matha.=' correcta.innerHTML="<div>L='.$q[1].' and W='.$q[2].'</div>";';
	  }else if($qtype>=317 && $qtype<=318)
	  {
	  	$matha.=' correcta.innerHTML="<div>'.$q[1].'</div>";';
	  }else if($qtype==209)
	  {
	  	$matha.=' correcta.innerHTML="<div>'.$q[1].'%</div>";';
	  }
	  else
	  {
	    $matha.=' var co_'.$num.'=convertToPresentDOM(catch_cheater("'.base64_encode($q[1]). '"),document);';
	  }
	  if($qtype!=189)
	  {
		   $matha.='if(typeof(co_'.$num.')=="undefined"){}else {correcta.appendChild(co_'.$num.')};';
	  }
		$matha.='</script>';
    $html_a.='<table border="0" cellpadding="2" cellspacing="0" style="background-color:#dddddd;">';
		$html_a.='	<tr>';
		$html_a.='		<td>';
		$html_a.='		<input type="text" value="' . str_replace(" ","",$q[1]) . '" readonly="true" /></td>';
		$html_a.='	</tr>';
		if($q[2]!="" && $q[2]!="1" && $q[2]!=NULL)
		{
			$html_a.='	<tr>';
			$html_a.='		<td style="border-top-style:solid;border-top-width:2px;border-top-color:black;">';
			$html_a.='		<input type="text" value="' . str_replace(" ","",$q[2]) . '" readonly="true" /></td>';
			$html_a.='	</tr>';
			$a.="/" . str_replace(" ","",$q[2]);
		}
		$html_a.='</table>';
		$altA=NULL;
		if($q[3]!="" && $q[3]!=NULL)
		{
			$altA=str_replace(" ","",$q[3]);
		}
		if($q[4]!="" && $q[4]!="1" && $q[4]!=NULL)
		{
			$altA.="/" . str_replace(" ","",$q[4]);
		}
		$retval.='<input type="hidden" id="txt_altAnswer_' . $num . '" name="txt_altAnswer_' . $num . '" value="' . $altA . '" />';
		$retval.='<input type="hidden" id="txt_provided_' . $num . '" name="txt_provided_' . $num . '" value="" />';
		$retval.='<input type="hidden" id="txt_problemType_' . $num . '" name="txt_problemType_' . $num . '" value="' . $select . '" />';
		$retval.='<input type="hidden" id="txt_array_0_' . $num . '" name="txt_array_0_' . $num . '" value="' . $q[0] . '" />';
		$retval.='<input type="hidden" id="txt_array_1_' . $num . '" name="txt_array_1_' . $num . '" value="' . base64_encode($q[1]) . '" />';
		$retval.='<input type="hidden" id="txt_array_2_' . $num . '" name="txt_array_2_' . $num . '" value="' . $q[2] . '" />';
		$retval.='<input type="hidden" id="txt_array_3_' . $num . '" name="txt_array_3_' . $num . '" value="' . $q[3] . '" />';
		$retval.='<input type="hidden" id="txt_array_4_' . $num . '" name="txt_array_4_' . $num . '" value="' . $q[4] . '" />';
		$retval.='<input type="hidden" id="txt_array_5_' . $num . '" name="txt_array_5_' . $num . '" value="' . $q[5] . '" />';
		$retval.='<input type="hidden" id="trytimes_'. $num .'"  value="' .$active. '"></input>';
		$retval.='<input type="hidden" id="result_'. $num .'"  value="' .$result1. '"></input>';
		$retval.='<table id="tbl_problem_' . $num . '" border="0" cellpadding="0" cellspacing="0" style="display:none;">';
		$retval.='	<tr>';
		$retval.='		<td>';
		$retval.='		<img src="pics/blank.gif" alt="" height="10" /></td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td rowspan="9" valign="middle" align="center">';
		$retval.='		<img id="img_right_' . $num . '" src="pics/right.gif" alt="" style="display:none;" /><img id="img_wrong_' . $num . '" src="pics/wrong.gif" alt="" style="display:none;" /></td>';
		$retval.='		<td>';
		$retval.='		<h2 class="black">Question #' . $num . '</h2></td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td class="black">';
		$retval.='		' . $intro . '</td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td id="td_questionInfix_' . $num . '" align="center" style="cursor:default;"><br/>';
    
    $q_out = parse_question($q[0],(int)$select,$num);
    $retval.=$q_out;
    $retval.='		' . '<br/></td>';
		$retval.='	</tr>';

		$retval.='	<tr>';
		$retval.='		<td>';
		$retval.='		<h2 class="black">Enter Your Answer:</h2></td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td>';
		$retval.=gen_answer_input($select,$num,$q[3],$q[4]);
		$retval.='	 </td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td id="td_checkLink_' . $num . '" align="center">';
		$retval.='		<br/><button type="button" id="checkans_'.$num.'" onclick="checkthis(' . $num . ');" class="button1">Check Answer&nbsp;<span id="trytimesdis_'.$num.'" style="font-size:12px">(0/5)</span></button></td>';
		$retval.='	</tr>';
		
		$retval.='	<tr>';
		$retval.='		<td>';
		$retval.='		<div id="as_'. $num .'" style="background-color:#f4f4f4;width:350;display:none"></div></td>';
		$retval.='	</tr>';
		$retval.='	<tr>';
		$retval.='		<td id="td_answer_' . $num . '" style="display:none;" class="black">';
		$retval.='		<h2 class="black">Correct Answer</h2>';
		$retval.='		<p class="black" align="center">' . $matha . '</p>';
		//$retval.='		<p class="black" align="center">' . $html_a . '</p>';
		$retval.='	</td></tr>';
		$retval.='	<tr>';
		$retval.='		<td>';
		$retval.='		<img src="pics/blank.gif" alt="" height="10" /></td>';
		$retval.='	</tr>';
		$retval.='</table>';
		$retval.='<hr id="hr'.$num.'" style="color:#b0b0b0"/>';
		if($rn==1)
		{
		$retval.='	 <script language="javascript">';
		$retval.='	 restoreuseranswer('.$num.',\''.$useranswer.'\',"'.$result1.'","'.$active.'");';
		$retval.='	 </script>';
	  }
		echo($retval);
	}
	function GenDescription($num,$type)
	{
		global $con;
		
		$html='';
		
		//$html='<span id="spn_questionDescription_' . $num . '" style="font-weight:bold;display:none;">' . gen_directions($type) . '</span>';
		
		$sql="SELECT title";
		$sql.=" FROM problems";
		$sql.=" WHERE ( number=" . (int)$type . " AND active=1 )";
		//echo('<br />' . $sql);
		$ds=$con->Query($sql);
		$x="";
		while($dr=mysql_fetch_row($ds))
		{
			$x=$dr[0];
		}
		$html='<span id="spn_questionDescription_' . $num . '" style="font-weight:bold;display:none;">' . $x . '</span>';
		
		return $html;
	}
?>

<html>
	<head>
<meta http-equiv="X-UA-Compatible" content="IE=7" />
		<title><? global $pageTitle; echo($pageTitle); ?> - Math Pass 3.1</title>
		<link rel="stylesheet" type="text/css" href="globals.css" />
		<script type="text/javascript" src="scripts/dialog.js"></script>
		<script type="text/javascript" src="base/scripts/globals.js"></script>
		<script language="javascript">
      var m_seconds=0;
      var m_lastConverted=0;	
      function Init()
      {
      	IncrementTimeSpent();
      	SetTimeStarted();
      	SingleProblemView();
      	var installmath=checkForMathPlayer();
      	//alert(installmath);
      	if(installmath!=3)
      	{
      	  CompleteInit();
      	}else
      	{
      //		GetBrowserElement("tbl_loading").style.display="none";
      //	  GetBrowserElement("tbl_installmath").style.display="";
      	}
      }
      function CompleteInit()
      {
      //	GetBrowserElement("tbl_loading").style.display="none";
      //	GetBrowserElement("tbl_installmath").style.display="none";
      	GetBrowserElement("tbl_form").style.display="";
      }
      function GoTo(num)
      {
      	if(GetBrowserElement("txt_question").value!="")
      	{
      		x=GetBrowserElement("txt_question").value;
      		GetBrowserElement("a_questionLink_" + x).className="questionLink";
      		GetBrowserElement("tbl_problem_" + x).style.display="none";
      		GetBrowserElement("spn_questionDescription_" + x).style.display="none";
      	}
      	GetBrowserElement("a_questionLink_" + num).className="questionLinkOn";
      	
      	GetBrowserElement("tbl_problem_" + num).style.display="";
      	GetBrowserElement("tbla").style.display="";
      	GetBrowserElement("spn_questionDescription_" + num).style.display="";
      	var num_questions=GetBrowserElement("num_questions").value;
      	if(num==num_questions)
      	{
      		GetBrowserElement("btn_next").style.display="none";
      		GetBrowserElement("btn_previous").style.display="";
      		if(<? echo $openmode; ?>=="2")
      		GetBrowserElement("btn_submit").style.display="";
      	}
      	else if(num==1)
      	{
      		GetBrowserElement("btn_previous").style.display="none";
      		GetBrowserElement("btn_next").style.display="";
      		GetBrowserElement("btn_submit").style.display="none";
      	}else
      	{
      		GetBrowserElement("btn_next").style.display="";
      		GetBrowserElement("btn_previous").style.display="";
      		GetBrowserElement("btn_submit").style.display="none";
      	}
      	GetBrowserElement("txt_question").value=num;
      }
      function Last()
      {
      	var x=parseInt(GetBrowserElement("txt_question").value);
      	if(GetBrowserElement("tbl_problem_" + (x-1))!=null)
      	{
      		GoTo(x-1);
      	}
      }
      	
      function Next()
      {
      	var x=parseInt(GetBrowserElement("txt_question").value);
      	if(GetBrowserElement("tbl_problem_" + (x+1))!=null)
      	{
      		GoTo(x+1);
      	}
      }
      function IncrementTimeSpent()
      {
      	min=String((parseInt(m_seconds/60)));
      	seconds=String((m_seconds%60));
      	if(seconds.length<2)
      	{
      		seconds="0" + seconds;
      	}
      	GetBrowserElement("spn_spent").innerHTML=min + ":" + seconds;
      	m_seconds+=5;
      	var t=new Date();
      	var time=t.getHours() <= 11 ? "A.M." : "P.M.";
      	var hour=t.getHours() <= 12 ? t.getHours() : t.getHours()-12;
      	var h=t.getHours();
      	var min=String(t.getMinutes());
      	var tmonth=t.getMonth()+1;
      	GetBrowserElement("txt_finished").value=t.getFullYear() + "-" + tmonth + "-" + t.getDate() + " " + h + ":" + min;
      	setTimeout("IncrementTimeSpent()",5000);
      }
      function SetTimeStarted()
      {
      	var x=new Date();
      	var time=x.getHours() <= 11 ? "A.M." : "P.M.";
      	var hour=x.getHours() <= 12 ? x.getHours() : x.getHours()-12;
      	var h=x.getHours();
      	var min=String(x.getMinutes());
      	if(min.length<2)
      	{
      		min="0" + seconds;
      	}
      	var tmonth=x.getMonth()+1;
      	GetBrowserElement("txt_started").value=x.getFullYear() + "-" + tmonth + "-" + x.getDate() + " " + h + ":" + min;
      	GetBrowserElement("spn_started").innerHTML=hour + ":" + min + " " + time;
      }
      function MathHelp()
      {
      	ShowLayover("lay_answerChecker");
      	
      }
      
      function SingleProblemView()
      {
      	GetBrowserElement("spn_multipleProblemView").className="questionViewOff";
      	GetBrowserElement("spn_singleProblemView").className="questionViewOn";
      	GetBrowserElement("td_assignmentNavigation").style.display="";
      	var num_questions=GetBrowserElement("num_questions").value;
      	for(var i=1;i<=num_questions;i+=1)
      	{
      	  GetBrowserElement("hr"+i).style.display="none";
      		GetBrowserElement("tbl_problem_" + i).style.display="none";
      	  if(<? echo $type; ?>=="1" || <? echo $openmode; ?>==1)
      	  {
      			GetBrowserElement("td_checkLink_" + i).style.display="";
      	  }
        	else
        	{
      			GetBrowserElement("td_checkLink_" + i).style.display="none";
      	  }
      	}
      	if(GetBrowserElement("txt_question").value=="")
      	{
      		GetBrowserElement("txt_question").value="1";
      	}
      	GetBrowserElement("tbl_problem_" + GetBrowserElement("txt_question").value).style.display="";
      	if(<? echo $type; ?>=="1" || <? echo $openmode; ?>==1)
      	{
      	 GetBrowserElement("btn_next").style.display="";
      	}
      	GoTo(GetBrowserElement("txt_question").value);
      }
      function MultipleProblemView()
      {
      	GetBrowserElement("spn_singleProblemView").className="questionViewOff";
      	GetBrowserElement("spn_multipleProblemView").className="questionViewOn";
      	GetBrowserElement("td_assignmentNavigation").style.display="none";
      	var num_questions=GetBrowserElement("num_questions").value;
      	for(var i=1;i<=num_questions;i+=1)
      	{
      	GetBrowserElement("hr"+i).style.display="";
      		GetBrowserElement("tbl_problem_" + i).style.display="";
      	if(<? echo $type; ?>=="1" || <?echo $openmode;?>==1)
      	{
      			GetBrowserElement("td_checkLink_" + i).style.display="";
      	}
      	else
      	{
      			GetBrowserElement("td_checkLink_" + i).style.display="none";
      	}
      	}
      	GetBrowserElement("btn_next").style.display="none";
      	if(<? echo $openmode;?>=="2")
      		GetBrowserElement("btn_submit").style.display="";
      }
      function winClose()
      {
      	var sta=document.getElementById("sta");
     	  if(<? echo $openmode; ?>=="2")
     	  {
     		 var cff=confirm("Please click on OK to save the assignment before close the window, or CANCEL to close the window directly.");
     	   if(cff==true)
     	   {
     	 	  sta.value="1";
     		  save();
     	   }else
     	   {
     	    window.close();
     	   }
      	}else
     	  {
     		  window.close();
     	  }
      }
      function ShowAnswer(num)
      {
        var rs="infix_";
      	if(document.getElementById(rs+num)!=null)
        {
      	  document.getElementById(rs+num).disabled=true;
      	}
      	for(var i=1;i<6;i++)
        {
        	rs="infix"+i+"_";
          if(document.getElementById(rs+String(num))!=null)
          {
          	document.getElementById(rs+String(num)).disabled=true;
          }
        }
      	GetBrowserElement("td_answer_" + num).style.display="";	
      }

      function checkthis(k)
      {
      	
      	var as=GetBrowserElement("as_"+k);
      	
      	var uajson=eval('('+getuseranswer(k,1)+')');
      	if(uajson.infix_0=="" && (uajson.infix_1=="" ||uajson.infix_1==null) && (uajson.infix_2=="" ||uajson.infix_2==null) && (uajson.infix_3=="" ||uajson.infix_3==null) && (uajson.infix_4=="" ||uajson.infix_4==null) && (uajson.infix_5=="" ||uajson.infix_5==null) && (uajson.check=="" ||uajson.check==null))
      	{
      		alert("You have not entered your answer.");
      		return;
      	}
//      	var trytimes=GetBrowserElement("trytimes_"+k);
//      	var trytimedis=GetBrowserElement("trytimesdis_"+k);
//      	var trytimesn=parseInt(trytimes.value);
//      	if(trytimesn>4)
//      	{
//      		displayresult(k,0);
//      		return;
//      	}
      	var as=GetBrowserElement("as_"+k);
      	as.innerHTML="";
      	as.innerHTML="Check Answering...";
      	btndisab(1);
        checkanswer(k);
      }
      function checkanswer(k)
      {
 	      var txt_problemType=GetBrowserElement("txt_problemType_"+k).value;
     	  var ptype=parseInt(txt_problemType); 
     	  var uajson=eval('('+getuseranswer(k,1)+')');
     	  var done=GetBrowserElement("txt_done").value; 
        var txt_array=GetBrowserElement("txt_array_1_"+k).value;
        txt_array=catch_cheater(txt_array);
        txt_array=addstar(txt_array);
        var result=GetBrowserElement("result_"+k);
        var cur=GetBrowserElement("current");
        cur.value=k;
        if(done=="1" && uajson.infix_0=="" && (uajson.infix_1=="" ||uajson.infix_1==null) && (uajson.infix_2=="" ||uajson.infix_2==null) && (uajson.infix_3=="" ||uajson.infix_3==null) && (uajson.infix_4=="" ||uajson.infix_4==null) && (uajson.infix_5=="" ||uajson.infix_5==null)&& (uajson.select0=="" ||uajson.select0==null)&& (uajson.select1=="" ||uajson.select1==null)&& (uajson.check=="" ||uajson.check==null))
      	{
      		result.value="7";
      		checknext();
      		return;
      	}
        if(ptype>=135 && ptype<=139)
        {
        	checkanswerinte(0,1);
        }else if(ptype==156||(ptype>=159 && ptype<=162) ||(ptype==264 || ptype==266))
        {
        	checkanswerinte(0,2);
        }else if(ptype==265 || ptype==157)
        {
        	checkanswerdomain();
        }else if(ptype==158)
        {
        	checkanswerdomain2();
        }else if(ptype>=163 && ptype<=185)
        {
        	checkanswerline(0);
        }else if(ptype>=296 && ptype<=307)
        {
        	checkanswerinte(0,3);
        }else if(ptype==190)
        {
        	checkanswermult(0);
        }else if((ptype>=197 && ptype<=198) || (ptype>=204 &&ptype<=205) ||ptype==208 || (ptype>=211 &&ptype<=213)|| (ptype>=220 && ptype<=223) ||(ptype==267))
        {
        	checkanswermult(1);
        }else if(ptype==189 ||ptype==210 || (ptype>=217 &&ptype<=219) || (ptype>=275 &&ptype<=278) ||(ptype>=309 &&ptype<=313) || ptype==316|| ptype==319)
        {
        	 if(ptype==189)
               txt_array=GetBrowserElement("txt_array_3_"+k).value;
        	 if(uajson.infix_0==txt_array)
        	 {
        	 	 result.value="1";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             }    	
        	 }else
        	 {
        	   result.value="4";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             }    	
        	 }
        	 return;
        }else if(ptype==226 || ptype==268 || ptype==288)
        {
        	if(Math.abs(parseFloat(uajson.infix_0)-parseFloat(txt_array))<0.005)
        	{ 
        		result.value="1";		
          }else
          {
          	result.value="4";	
          }
          if(done=="0")
          {
             displayresult(k,0);
          }else
          {
            checknext();
          }  
          return;  	
        }else if((ptype>=256 && ptype<=263) || (ptype>=281 && ptype<=282) || (ptype>=323 && ptype<=326))
        {	
        	checkanswerequ();
        }else if(ptype>=290 && ptype<=291)
        {
        	var ane=txt_array.split("@@");
        	if(ane[0]==uajson.select0 && ane[1]==uajson.infix_0 &&ane[2]==uajson.select1 && ane[3]==uajson.infix_1 && ane[4]==uajson.check)
          {
          	result.value="1";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             }   
          }else
          {
          	 result.value="4";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             } 
          }
        }else if(ptype>=294 && ptype<=295)
        {	 
           var txt_array1=GetBrowserElement("txt_array_2_"+k).value;
           txt_array1=txt_array1.replace(/\s/g,"");
        	 if(uajson.infix_0==txt_array && uajson.infix_1==txt_array1)
        	 {
        	 	 result.value="1";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             }    	
        	 }else
        	 {
        	   result.value="4";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             } 
           }   	
        }else if(ptype>=317 && ptype<=318)
        {	 
           var cane=txt_array.split(",");
           var ane=uajson.infix_0.split(",");
           
           if(cane.length!=ane.length)
           {
           	 result.value="1";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             } 
             return;
           }
           var k=0;
           for(var i=0;i<cane.length;i++)
           {
           	 for(var j=0;j<ane.length;j++)
           	 {
           	 	if(cane[i]==ane[j])
           	 	{
           	 		k++;
           	 		break;
           	 	}
           	 }
           }
           if(k==cane.length)
           {
        	 	 result.value="1";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             } 
             return;   	
        	 }else
        	 {
        	   result.value="4";	
          	 if(done=="0")
             {
              displayresult(k,0);
             }else
             {
            	checknext();
             } 
             return;
           }  	
        }else
        {
        	if(uajson.infix_0==txt_array)//0:Not Check,1:Totally right,2:right, But not simpliest,3:wrong
          { 
          	result.value="1";	
          	if(done=="0")
            {
             displayresult(k,0);
            }else
            {
            	checknext();
            }   	    
          }else 
          {
            var params="";
            params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(txt_array);
            send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);   
          } 
        }	
      }
      function checkanswerequ()
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;  
      	var ane=txt_array.split("@@");
      	if(ane.length<=1)
      	{
      		if(ane[0]==uajson.infix_0 && uajson.infix_1=="" && uajson.check=="0")
      		{
      			result.value="1";	
      		}else
      		{
      			result.value="4";	  
      		}
      	}else
      	{
      		if(ane[0]=="n/a" && ane[2]=="n/a" && ane[4]!="")
      		{
      			if(uajson.check=="1" && uajson.infix_0=="" && uajson.infix_1=="" )
      			{
      				result.value="1";	  
      			}
      			else
      			{
      				result.value="4";	  
      			}	
      		}else if(ane[0]!="n/a" && ane[2]=="n/a")
      		{
      			var ane1=ane[0];
      			if(ane[1]!="1")
      			{ 
      				ane1=ane1+"/"+ane[1];
      			}
      			if(uajson.check!="0")
      			{
      			 result.value="4";
      			 if(done=="0")
             {
               displayresult(k,0);
             }else
             {
            	checknext();
             } 
             return;
      			}
      			if(uajson.infix_1!="")
      			{
      				result.value="4";	
      			}else
      			{
      		    if(ane1==uajson.infix_0)
      		    {
      			    result.value="1";	 
      	  	  }else
      		    {
      		  	var params="";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ane1);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca); 
              return;
      		    }
      		   }
      		}else if(ane[0]!="n/a" && ane[2]!="n/a")
      		{
      			if(uajson.check!="0")
      			{
      			 result.value="4";
      			 if(done=="0")
             {
               displayresult(k,0);
             }else
             {
            	checknext();
             } 
             return;
      			}
      			var ane1=ane[0];
      			if(ane[1]!="1")
      			{ 
      				ane1="("+ane1+")/"+ane[1];
      			}
      			var ane2=ane[2];
      			if(ane[3]!="1")
      			{ 
      				ane2="("+ane2+")/"+ane[3];
      			}
      			if((ane1==uajson.infix_0 && ane2==uajson.infix_1) || (ane2==uajson.infix_0 && ane1==uajson.infix_1))
      		  {
      			 result.value="1";		 
      	  	}else
      		  {
      		   if(result.value!="20" && result.value!="21" && result.value!="22" && result.value!="23" && result.value!="24")
      		   {
      		   	 result.value="20";
      			   var params="";
               params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ane1);
               send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
               return; 
      			 }else if(result.value=="21")
      			 {
      			 	 result.value="0";
      			   var params="";
               params="expr1="+encodeURIComponent(uajson.infix_1)+"&expr2="+encodeURIComponent(ane2);
               send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca); 
      			   return; 
      			 }else if(result.value=="22")
      			 {
      			 	 result.value="23";
      			   var params="";
               params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ane2);
               send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca); 
      			   return; 
      			 }else if(result.value=="24")
      			 {
      			 	 result.value="0";
      			   var params="";
               params="expr1="+encodeURIComponent(uajson.infix_1)+"&expr2="+encodeURIComponent(ane1);
               send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca); 
      			   return; 
      			 }	
      		  }
      		}else
      		{
      			 result.value="4";	 
      		}			
      	}
      	if(done=="0")
        {
          displayresult(k,0);
        }else
        {
          checknext();
        } 
       }
      function checkanswermult(t)
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;   
        r=new Array();
        if(t==1)
        {
        	if(uajson.infix_0=="" ||uajson.infix_1=="")
        	{
        		result.value="6";
            if(done=="0")
            {
             displayresult(k,0);
            }else
            {
            	    checknext();
            }
            return;
        	}
        	var txt_array1=GetBrowserElement("txt_array_2_"+k).value;
          txt_array1=txt_array1.replace(/\s/g,"");
        	r[0]=parseFloat(uajson.infix_0)-parseFloat(txt_array);
          r[1]=parseFloat(uajson.infix_1)-parseFloat(txt_array1);
        }
        if(t==0)
        {
         if(uajson.infix_0=="" ||uajson.infix_1==""|| uajson.infix_2==""|| uajson.infix_3==""|| uajson.infix_4==""|| uajson.infix_4=="")
         {
        	result.value="6";
          if(done=="0")
          {
             displayresult(k,0);
          }else
          {
            checknext();
          }
           return; 
         } 
         var ana=txt_array.split("@@");
         r[0]=parseFloat(uajson.infix_0)-parseFloat(ana[0]);
         r[1]=parseFloat(uajson.infix_1)-parseFloat(ana[1]);
         r[2]=parseFloat(uajson.infix_2)-parseFloat(ana[2]);
         r[3]=parseFloat(uajson.infix_3)-parseFloat(ana[3]);
         r[4]=parseFloat(uajson.infix_4)-parseFloat(ana[4]);
         r[5]=parseFloat(uajson.infix_5)-parseFloat(ana[5]);
        }
        for(i=0;i<r.length;i++)
        {
        	if(Math.abs(r[i])>0.000001)
        	{
        		result.value="4";
            if(done=="0")
            {
             displayresult(k,0);
            }else
            {
            	checknext();
            }
            return; 
        	}
        }
        result.value="1";
        if(done=="0")
        {
         displayresult(k,0);
        }else
        {
          checknext();
        }
        return; 
      }
      
      function checkanswerline(t)
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;
        var ana=txt_array.split("@@");
        var an1=ana[0];
    		if(ana[1]!="1")
    		 an1=an1+"/"+ana[1];
    		var an2=ana[2];
    		if(ana[3]!="1")
    		 an2=an2+"/"+ana[3];
    		var an3=ana[4];
    		if(ana[5]!="1")
    		 an3=an3+"/"+ana[5];
    		var an4=ana[6];
    		if(ana[7]!="1")
    		 an4=an4+"/"+ana[7];
        if(t==0)
        {
        	if(ana[0]=="not_used")
        	{
        		if(ana[4]=="not_used")
        		{
        			if(uajson.infix_0!="" || uajson.infix_1!=""|| uajson.infix_2!="")
        		  {
          			result.value="4";
             	  if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	    checknext();
                }  
                return; 
        		  }
        			if(uajson.infix_3==an4)
        			{
        				result.value="1";
             	  if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	    checknext();
                }
                return; 
        			}else
        			{
        				params="expr1="+encodeURIComponent(uajson.infix_3)+"&expr2="+encodeURIComponent(an4);
                send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
        			}
        		}else
        		{
        			if(uajson.infix_0!="" || uajson.infix_1!=""|| uajson.infix_3!="")
        		  {
          			result.value="4";
             	  if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	    checknext();
                }
                return; 
        		  }
        			if(uajson.infix_2==an3)
        			{
        				result.value="1";
             	  if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	    checknext();
                }
                return; 
        			}else
        			{
        				params="expr1="+encodeURIComponent(uajson.infix_2)+"&expr2="+encodeURIComponent(an3);
                send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
        			}
        		}
        	}else
        	{
        		if(uajson.infix_2!="" || uajson.infix_3!="")
        		{
        			result.value="4";
           	  if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	    checknext();
              }
              return; 
        		}
        		
        		if(uajson.infix_0==an1 && uajson.infix_1==an2)
        		{
       			  result.value="1";
           	  if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	    checknext();
              } 
        		}else if(uajson.infix_0==an1)
        		{
        			checkanswerline(1);
        		}else if(uajson.infix_1==an2)
        		{
        			params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(an1);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
        		}else
        		{
        			result.value="16";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(an1);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
        		}
        	}
        }else if(t==1)
        {
           params="expr1="+encodeURIComponent(uajson.infix_1)+"&expr2="+encodeURIComponent(an2);
           send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
        }
      }
      function checkanswerdomain2()
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        txt_array=addstar(txt_array);
        var txt_array1=GetBrowserElement("txt_array_2_"+k).value;
        txt_array1=txt_array1.replace(/\s/g,"");
        txt_array1=addstar(txt_array1);
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;
        var an=txt_array.substring(1,txt_array.length-1);
        var ana=an.split(",");
        var anb=txt_array1.split(",");
        if(uajson.asileft=="(" && uajson.asiright==")" )
        {
         if((uajson.infix_0==ana[0] && uajson.infix_1==ana[1])||(uajson.infix_0=="" && uajson.infix_1==""))
         { 
         	 if((uajson.infix_2==anb[0] && uajson.infix_3==anb[1]) ||(uajson.infix_2==anb[1] && uajson.infix_3==anb[0]))
         	 {
         	    result.value="1";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
              return;
            }else
            {
         	    result.value="4";
          	  if(done=="0")
              {
                displayresult(k,0);
              }else
              {
                checknext();
              }  
            }
         }else
         {
         	 result.value="4";
          	if(done=="0")
            {
              displayresult(k,0);
            }else
            {
              checknext();
            }  
         }
        }else
        {
        	  result.value="5";
          	if(done=="0")
            {
              displayresult(k,0);
            }else
            {
              checknext();
            }  
        }
      }
      function checkanswerdomain()
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        txt_array=addstar(txt_array);
        var txt_array1=GetBrowserElement("txt_array_2_"+k).value;
        txt_array1=txt_array1.replace(/\s/g,"");
        txt_array1=addstar(txt_array1);
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;
        var an=txt_array.substring(1,txt_array.length-1);
        var ana=an.split(",");
        if(uajson.asileft=="(" && uajson.asiright==")" )
        {
         if((uajson.infix_0==ana[0] && uajson.infix_1==ana[1])||(uajson.infix_0=="" && uajson.infix_1==""))
         { 
         	 if(uajson.infix_2==txt_array1)
         	 {
         	    result.value="1";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
              return;
            }else
            {
         	    var params="";
              params="expr1="+encodeURIComponent(uajson.infix_2)+"&expr2="+encodeURIComponent(txt_array1);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca); 
            }
         }else
         {
         	 result.value="4";
          	if(done=="0")
            {
              displayresult(k,0);
            }else
            {
              checknext();
            }  
         }
        }else
        {
        	  result.value="5";
          	if(done=="0")
            {
              displayresult(k,0);
            }else
            {
              checknext();
            }  
        }
      }
      function checkanswerinte(t,qt)
      {
      	var k=GetBrowserElement("current").value;
     	  var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      	txt_array=catch_cheater(txt_array);
        txt_array=txt_array.replace(/\s/g,"");
        txt_array=addstar(txt_array);
        var txt_array1=GetBrowserElement("txt_array_2_"+k).value;
        txt_array1=txt_array1.replace(/\s/g,"");
        txt_array1=addstar(txt_array1);
        var params="";
        var result=GetBrowserElement("result_"+k);
        var done=GetBrowserElement("txt_done").value;
        if(t==0)
       	{
       		if(qt==2 && txt_array1!="not_used")
       		{	
        		var an=txt_array.substring(1,txt_array.length-1);
            var ana=an.split(",");
          	if(txt_array.charAt(0)!=uajson.asileft || txt_array.charAt(txt_array.length-1)!=uajson.asiright)
          	{
          		result.value="5";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
          	}else if(txt_array1.search(/\,/)==-1 && uajson.infix_3!=null && uajson.infix_3!="" )
       			{
       				  result.value="4";
          		  if(done=="0")
                {
                 displayresult(k,0);
                }else
                {
            	   checknext();
                 }  
                return;
       			}else if(txt_array1.search(/\,/)!=-1)
       			{
       				var taa=txt_array1.split(",");
       				if(uajson.infix_0==ana[0] && uajson.infix_1==ana[1] && uajson.infix_2==taa[0] && uajson.infix_3==taa[1])
          	  {
            		result.value="1";
            		if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	   checknext();
                }  
          	  }else if(uajson.infix_0==ana[0] && uajson.infix_1==ana[1] && uajson.infix_2==taa[1] && uajson.infix_3==taa[0])
          	  {
            		result.value="1";
            		if(done=="0")
                {
                  displayresult(k,0);
                }else
                {
            	   checknext();
                }  
          	  }else
          	  {
          	    result.value="4";
          		  if(done=="0")
                {
                 displayresult(k,0);
                }else
                {
            	    checknext();
                }  
          	  }
          	   return;
       			}else if(uajson.infix_0==ana[0] && uajson.infix_1==ana[1] && uajson.infix_2==txt_array1)
          	{
          		result.value="1";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
              return;
          	}else if(uajson.infix_0==ana[0] && uajson.infix_1==ana[1])
          	{
              result.value="110";
              checkanswerinte(2,qt);
          	}else if(uajson.infix_0==ana[0] && uajson.infix_2==txt_array1)
          	{
              result.value="101";
              checkanswerinte(1,qt);
          	}else if(uajson.infix_0==ana[0])
          	{
              result.value="100";
              checkanswerinte(1,qt);
          	}else if(uajson.infix_1==ana[1] && uajson.infix_2==txt_array1)
          	{
              result.value="011";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}else if(uajson.infix_1==ana[1])
          	{
              result.value="010";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}else if(uajson.infix_2==txt_array1)
          	{
              result.value="001";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}else
          	{
              result.value="000";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}
       		}else if(qt==2 && txt_array1=="not_used" && (uajson.infix_2!="" || (uajson.infix_3!="" && uajson.infix_3!=null)))
          {
          	result.value="4";
          	if(done=="0")
            {
              displayresult(k,0);
            }else
            {
            	checknext();
            } 
          }else if(qt!=2 && uajson.infix_0!="" && uajson.infix_2!=null && uajson.infix_2!="")
          {
          	result.value="4";
            if(done=="0")
            {
              displayresult(k,0);
            }else
            {
            	checknext();
            } 
          }else if(uajson.infix_0!="")
        	{	
        		var an=txt_array.substring(1,txt_array.length-1);
            var ana=an.split(",");
          	if(txt_array.charAt(0)!=uajson.asileft || txt_array.charAt(txt_array.length-1)!=uajson.asiright)
          	{
          		result.value="5";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
          	}else if(uajson.infix_0==ana[0] && uajson.infix_1==ana[1])
          	{
          		result.value="1";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
          	}else if(uajson.infix_0==ana[0])
          	{
              result.value="11";
              checkanswerinte(1,qt);
          	}else
          	{
              result.value="10";
              params="expr1="+encodeURIComponent(uajson.infix_0)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}
          }else if(uajson.infix_2!="" && qt==3)
          {
          	if(txt_array.match(/union/gi)==null)
          	{
          		result.value="4";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              } 
              return; 
          	}   	
          	var txt_array1=txt_array.split("union");
          	var an=txt_array1[0].substring(1,txt_array1[0].length-1);
            var ana=an.split(",");
            var an1=txt_array1[1].substring(1,txt_array1[1].length-1);
            var ana1=an1.split(",");
          	if(txt_array1[0].charAt(0)!=uajson.adileft1 || txt_array1[0].charAt(txt_array1[0].length-1)!=uajson.adiright1 || txt_array1[1].charAt(0)!=uajson.adileft2 || txt_array1[1].charAt(txt_array1[1].length-1)!=uajson.adiright2)
          	{
          		result.value="5";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	 checknext();
              }  
          	}else if(uajson.infix_2==ana[0] && uajson.infix_3==ana[1])
          	{
          		result.value="1";
          		if(done=="0")
              {
                displayresult(k,0);
              }else
              {
            	  checknext();
              }  
          	}else
          	{
              result.value="12";
              params="expr1="+encodeURIComponent(uajson.infix_2)+"&expr2="+encodeURIComponent(ana[0]);
              send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
          	}
          }else
          {
          	result.value="0";
          	if(done=="0")
            {
                displayresult(k,0);
            }else
            {
            	  checknext();
            }  
          }
         }else if(t==1)
         {
         	   var an=txt_array.substring(1,txt_array.length-1);
             var ana=an.split(",");
             params="expr1="+encodeURIComponent(uajson.infix_1)+"&expr2="+encodeURIComponent(ana[1]);
             send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
         }else if(t==2)
         {
             params="expr1="+encodeURIComponent(uajson.infix_2)+"&expr2="+encodeURIComponent(txt_array1);
             send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
         }else if(t==3)
         {
         	   
         	   var txt_array1=txt_array.split("union");
          	 var an=txt_array1[0].substring(1,txt_array1[0].length-1);
             var ana=an.split(",");
             
             var an1=txt_array1[1].substring(1,txt_array1[1].length-1);
             var ana1=an1.split(",");
             params="expr1="+encodeURIComponent(uajson.infix_3)+"&expr2="+encodeURIComponent(ana[1]);
             send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
         }else if(t==4)
         {
             var txt_array1=txt_array.split("union");
          	 var an=txt_array1[0].substring(1,txt_array1[0].length-1);
             var ana=an.split(",");
             var an1=txt_array1[1].substring(1,txt_array1[1].length-1);
             var ana1=an1.split(",");
             params="expr1="+encodeURIComponent(uajson.infix_4)+"&expr2="+encodeURIComponent(ana1[0]);
             send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
         }else if(t==5)
         {
         	   var txt_array1=txt_array.split("union");
          	 var an=txt_array1[0].substring(1,txt_array1[0].length-1);
             var ana=an.split(",");
             var an1=txt_array1[1].substring(1,txt_array1[1].length-1);
             var ana1=an1.split(",");
             params="expr1="+encodeURIComponent(uajson.infix_5)+"&expr2="+encodeURIComponent(ana1[1]);
             send_request("phpproxy.php?proxy_url=http://local/cgi-bin/equalityjson.pl",params,prca);
         }
      }
      function displayresult(k,rst)
      {
      	var result=GetBrowserElement("result_"+k).value;
      	var as=GetBrowserElement("as_"+k);
      	if(result=="0")
      	{
      		as.style.display="block";
          as.style.color="#cc3300";
      	  as.innerHTML="You have not entered your answer.";
      	}else if(result=="3")
      	{
      	   as.style.display="block";
           as.style.color="#cc3300";
      	   as.innerHTML="Your answer is not simplest, please do it again.";
      	   var spnq=GetBrowserElement("spn_questionLink_" + k)
      	   spnq.className="questionLink4"; 
      	}else if(result=="1" || result=="2")
      	{
      		 as.style.display="block";
           as.style.color="#00cc33";
      	   as.innerHTML="The answer is right.";
      	   var spnq=GetBrowserElement("spn_questionLink_" + k)
      	   spnq.className="questionLink1"; 
      	}else if(result=="4")
      	{
      		 as.style.display="block";
           as.style.color="#cc3300";
      	   as.innerHTML="Your answer is not right, please do it again.";
      	   var spnq=GetBrowserElement("spn_questionLink_" + k)
      	   spnq.className="questionLink4"; 
      	}else if(result=="5")
      	{
      		 as.style.display="block";
           as.style.color="#cc3300";
      	   as.innerHTML="The interval is not right, please do it again.";
      	   var spnq=GetBrowserElement("spn_questionLink_" + k)
      	   spnq.className="questionLink4"; 
      	}else if(result=="6")
      	{
      		as.style.display="block";
          as.style.color="#cc3300";
      	  as.innerHTML="Please enter every parts of the answer.";
      	  var spnq=GetBrowserElement("spn_questionLink_" + k)
      	  spnq.className="questionLink4"; 
      	}else if(result=="7")
      	{
      	   as.style.display="block";
           as.style.color="#cc3300";
      	   as.innerHTML="You did not enter the answer.";
      	   var spnq=GetBrowserElement("spn_questionLink_" + k)
      	   spnq.className="questionLink4"; 
      	}
      	var trytimes=GetBrowserElement("trytimes_"+k);
      	var trytimesn=parseInt(trytimes.value);
      	var trytimesdis=GetBrowserElement("trytimesdis_"+k);
      	btndisab(0);
      	if(rst==1)
      	{
      		trytimesdis.innerHTML="("+trytimesn+"/5)";
      		if(trytimesn>=5)
      		{
      			var checkb=document.getElementById("checkans_"+k);
      			checkb.disabled=true;
        		checkb.style.color="#a5a5a5";
        		ShowAnswer(k);
        		saveHomework(k);  //modify: 2009-120-04  
      		}
      	}else
      	{
        	if(trytimesn>=4){
        		var checkb=document.getElementById("checkans_"+k);
        		trytimesdis.innerHTML="(5/5)";
        	  trytimes.value=5;
        		checkb.disabled=true;
        		checkb.style.color="#a5a5a5";
        		ShowAnswer(k);
        		saveHomework(k);  //modify: 2009-120-04
        	}else
        	{
        	  trytimesn++;
        	  trytimes.value=trytimesn;
        	  trytimesdis.innerHTML="("+trytimesn+"/5)";
          }
        }
      }
      function postcheck(k)
      {
      	var plus=0;
      	var minus=0;
      	var divide=0;
      	var multiply=0;
      	var exponent=0;
      	var varx=0;
      	var vary=0;
      	var vara=0;
      	var varb=0;
      	var varc=0;
      	var vard=0;
      	var varn=0;
      	var vark=0;
      	var varm=0;
      	var vart=0;
      	var parenthesis1=0;
      	var parenthesis=0;
      	var uajson=eval('('+getuseranswer(k,1)+')');
      	var txt_problemType=GetBrowserElement("txt_problemType_"+k).value;
     	  var ptype=parseInt(txt_problemType); 
     	  var an=uajson.infix_0; 
      	for(var i=0;i<an.length;i++)
      	{
      		if(an.charAt(i)=="+")plus++;
      		if(an.charAt(i)=="-")minus++;
      		if(an.charAt(i)=="/")divide++;
      		if(an.charAt(i)=="*")multiply++;
      		if(an.charAt(i)=="^")exponent++;
      		if(an.charAt(i)=="x")varx++;
      		if(an.charAt(i)=="y")vary++;
      		if(an.charAt(i)=="a")vara++;
      		if(an.charAt(i)=="b")varb++;
      		if(an.charAt(i)=="c")varc++;
      		if(an.charAt(i)=="d")vard++;
      		if(an.charAt(i)=="n")varn++;
      		if(an.charAt(i)=="m")varm++;
      		if(an.charAt(i)=="k")vark++;
      		if(an.charAt(i)=="t")vart++;
      		if(an.charAt(i)=="(")parenthesis++;
      		if(an.charAt(i)==")")parenthesis1++;
      	}
      	if(ptype<=16 ||(ptype>=24 && ptype<=25))
      	{
      		if(plus>=1)return 1;
      		if(minus>=2)return 1;
      		if(divide>=2)return 1;
      		if(multiply>=1)return 1;
      		if(exponent>=1)return 1;
      		if(varx>=1)return 1;
      		if(vary>=1)return 1;
      	}else if(ptype<=20 || (ptype>=22 && ptype<=23) ||(ptype==28)||(ptype>=33 && ptype<=39))
      	{
      		if(plus>=1)return 1;
      		if(minus>=4)return 1;
      		if(divide>=3)return 1;
      		if(multiply>=4)return 1;
      		if(exponent>=3)return 1;
      		if(varx>=2)return 1;
      		if(vary>=2)return 1;
      	}else if(ptype==29)
      	{
      		if(plus>=1)return 1;
      		if(minus>=4)return 1;
      		if(divide>=4)return 1;
      		if(multiply>=4)return 1;
      		if(exponent>=3)return 1;
      		if(varx>=2)return 1;
      		if(vary>=2)return 1;
      	}else if(ptype==21)
      	{
      		if(plus>=1)return 1;
      		if(minus>=5)return 1;
      		if(divide>=3)return 1;
      		if(multiply>=4)return 1;
      		if(exponent>=4)return 1;
      		if(vara>=2)return 1;
      		if(varb>=2)return 1;
      		if(varc>=2)return 1;
      	}else if(ptype<=27)
      	{
      		if(plus>=1)return 1;
      		if(minus>=2)return 1;
      		if(divide>=2)return 1;
      		if(multiply>=1)return 1;
      		if(exponent>=2)return 1;
      		if(varx>=1)return 1;
      		if(vary>=1)return 1;
      		if((exponent+divide)>=2)return 1;
      	}else if(ptype<=32)
      	{
      		if(plus>=1)return 1;
      		if(minus>=3)return 1;
      		if(divide>=3)return 1;
      		if(multiply>=3)return 1;
      		if(exponent>=3)return 1;
      		if(varx>=2)return 1;
      		if(vary>=2)return 1;
      	}else if(ptype==40)
      	{
      		if(plus>=4)return 1;
      		if(minus>=5)return 1;
      		if(divide>=1)return 1;
      		if(multiply>=4)return 1;
      		if(exponent>=3)return 1;
      		if(varx>=4)return 1;
      		if(vary>=1)return 1;
      	}else if(ptype==41)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(divide>=1)return 1;
      		if(multiply>=3)return 1;
      		if(exponent>=2)return 1;
      		if(varn>=4)return 1;
      		if(varx>=1)return 1;
      	}else if(ptype==42)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(divide>=1)return 1;
      		if(multiply>=3)return 1;
      		if(exponent>=2)return 1;
      		if(vary>=3)return 1;
      		if(varx>=1)return 1;
      	}else if(ptype==43)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(divide>=1)return 1;
      		if(multiply>=5)return 1;
      		if(exponent>=3)return 1;
      		if(vary>=3)return 1;
      		if(varx>=3)return 1;
      	}else if(ptype==44)
      	{
      		if(plus<1 ||plus>2)return 1;
      		if(vary!=2)return 1;
      		if(varx!=2)return 1;
      	}else if(ptype>=45 && ptype<=48)
      	{
      		if(an.search(/\)\(/)!=-1) return 1;
      		if(an.search(/\)*\(/)!=-1) return 1;
      	}else if(ptype>=49 && ptype<=51)
      	{
      		if(an.search(/\)\(/)!=-1) return 1;
      		if(an.search(/\)*\(/)!=-1) return 1;
      		if(an.search(/\)\^/)!=-1) return 1;
      	}else if(ptype==52)
      	{
      		if(varm>=3)return 1;
      		if(varn>=3)return 1;
      	}else if(ptype>=53 && ptype<=54)
      	{
      		if(varx!=2)return 1;
      	}else if(ptype==55)
      	{
      		if(varm<2)return 1;
      		if(varn<2)return 1;
      	}else if(ptype>=56 && ptype<=58)
      	{
      		if(exponent>=1 && varx>=2) return 1;
      	}else if(ptype==59)
      	{
      		if(exponent>=2)return 1;
      	}else if(ptype>=60 && ptype<=61)
      	{
      		if(exponent>=1)return 1;
      	}else if(ptype==62)
      	{
      		if(exponent>=2)return 1;
      	}else if(ptype>=63 && ptype<=66)
      	{
      		if(varx<=2)return 1;
      	}else if(ptype>=67 && ptype<=68)
      	{
      		if(varm<=2)return 1;
      		if(varn<=2)return 1;
      	}else if(ptype==69)
      	{
      		if(varx!=2)return 1;
      	}else if(ptype==70)
      	{
      		if(varx!=2)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype==71)
      	{
      		if(vara>=2)return 1;
      		if(varb>=2)return 1;
      		if(varc>=2)return 1;
      		if(vard>=2)return 1;
      	}else if(ptype>=72 && ptype<=73)
      	{
      		if(varx!=2)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype==74)
      	{
      		if(vary>=3)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype==75)
      	{
      		if(varx>=4)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype==76)
      	{
      		if(varx<=2)return 1;
      		if(exponent>=2)return 1;
      	}else if(ptype==77)
      	{
      		if(exponent>=2)return 1;
      	}else if(ptype>=78 && ptype<=82)
      	{
      		if(exponent>=1)return 1;
      		if(varx>=3)return 1;
      	}else if(ptype==83)
      	{
      		if(varx>=5)return 1;
      		//behind is new 2009-11-7
      		//if(exponent>=2)return 1;
      	}else if(ptype==84)
      	{
      		if(varx>=4)return 1;
      		//if(exponent>=1)return 1;
      	}else if(ptype==85)
      	{
      		if(varx>=5)return 1;
      		//behind is new 2009-11-7
      		//if(exponent>=2)return 1;
      	}else if(ptype==86)
      	{
      		if(vart>=6)return 1;
      		//if(exponent>=2)return 1;
      	}else if(ptype==87)
      	{
      		if(varx>=4)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype==88)
      	{
      		if(varx>=3)return 1;
      	}else if(ptype==89)
      	{
      		if(varx>=2)return 1;
      		if(vary>=2)return 1;
      	}else if(ptype>=90 && ptype<=96)
      	{
      		if(divide>=2)return 1;
      	}else if(ptype>=97 && ptype<=99)
      	{
      		if(an.search(/\^\-/g)!=-1) return 1;
      		if(an.search(/\^\(\-/g)!=-1) return 1;
      	}else if(ptype>=100 && ptype<=102)
      	{
      		if(varx>=2)return 1;
      		if(exponent>=1)return 1;
      	}else if(ptype>=103 && ptype<=104)
      	{
      		if(varx!=2)return 1;
      	}else if(ptype==105)
      	{
      		if(!(isInteger(an)))return 1;
      	}else if(ptype>=106 && ptype<=107)
      	{
      		if(!(isWhat(an,1)))return 1;
      		if(varx>=3) return 1;
      	}else if(ptype==108)
      	{
      		var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      		txt_array=catch_cheater(txt_array);
          txt_array=addstar(txt_array);   
      		if(!(issamepart(an,txt_array,1)))return 1;
      	}else if(ptype==109)
      	{
      		if(divide>=1)return 1;
      	}else if(ptype>=110 && ptype<=111)
      	{
      		if(multiply>=2)return 1;
      	}else if(ptype==112)
      	{
      		if(!(isPlusminus(an)))return 1;
      		if(plus>=2)return 1;
      		if(minus>=3)return 1;
      		if((plus+minus)>=3)return 1;
      	}else if(ptype==113)
      	{
      		if(!(isPlusminus(an)))return 1;
      		if(plus>=2)return 1;
      		if(minus>=2)return 1;
      	}else if(ptype>=114 && ptype<=115)
      	{
      		var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      		txt_array=catch_cheater(txt_array);
          txt_array=addstar(txt_array);   
      		if(!(issamepart(an,txt_array,1)))return 1;
      	}else if(ptype>=116 && ptype<=117)
      	{
      		var txt_array=GetBrowserElement("txt_array_1_"+k).value;
      		txt_array=catch_cheater(txt_array);
          txt_array=addstar(txt_array);   
      		if(!issamepart(an,txt_array,2))return 1;
      	}else if(ptype>=118  && ptype<=134)
      	{
      		if(!(isFraction(an)))return 1;
      	}else if(ptype>=140  && ptype<=141)
      	{
      		if(!(isInteger(an)))return 1;
      	}else if(ptype==142)
      	{
      		if(!(isFraction(an)))return 1;
      	}else if(ptype==143)
      	{
      		if(plus>=2)return 1;
      		if(minus>=3)return 1;
      		if(minus+plus>=3)return 1;
      		if(multiply>=2)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype>=144 && ptype<=145)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(minus+plus>=4)return 1;
      		if(multiply>=3)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==146)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(minus+plus>=4)return 1;
      		if(multiply>=3)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==147)
      	{
      		if(plus>=4)return 1;
      		if(minus>=5)return 1;
      		if(minus+plus>=5)return 1;
      		if(multiply>=5)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==148)
      	{
      		if(plus>=6)return 1;
      		if(minus>=7)return 1;
      		if(minus+plus>=7)return 1;
      		if(multiply>=7)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==149)
      	{
      		if(!isInteger(an))return 1;
      	}else if(ptype==150)
      	{
      		if(plus>=2)return 1;
      		if(minus>=3)return 1;
      		if(minus+plus>=3)return 1;
      		if(multiply>=3)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==151)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(minus+plus>=4)return 1;
      		if(multiply>=3)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if((ptype>=152 && ptype<=155)||ptype==206 ||ptype==274)
      	{
      		if(!isInteger(an))return 1;
      	}else if((ptype>=186 && ptype<=188) ||(ptype>=191 && ptype<=196) ||(ptype>=199 && ptype<=203) || ptype==207 ||(ptype>=214 && ptype<=216)||(ptype>=244 && ptype<=255))
      	{
      		if(!isReal(an))return 1;
      	}else if(ptype>=269 && ptype<=270)
      	{
      		if(plus>=2)return 1;
      		if(minus>=3)return 1;
      		if(minus+plus>=3)return 1;
      		if(multiply>=3)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype>=271 && ptype<=273)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(minus+plus>=4)return 1;
      		if(multiply>=4)return 1;
      		if(parenthesis1>=1)return 1;
      		if(parenthesis>=1)return 1;
      	}else if(ptype==289)
      	{
      		if(plus>=3)return 1;
      		if(minus>=4)return 1;
      		if(minus+plus>=4)return 1;
      		if(multiply>=1)return 1;
      		if(parenthesis1<=0)return 1;
      		if(parenthesis<=0)return 1;
      	}else if(ptype==331 || ptype==334 || ptype==336 || (ptype>=339 && ptype<=347))
      	{
      		if(an.search(/\^-/)!=-1 || an.search(/\^\(-/)!=-1)return 1;
      		if(parenthesis1<=0)return 1;
      		if(parenthesis<=0)return 1;
      		if(!(isWhat(an,1))  && !(isWhat(an,3)))return 1;
      	}else if((ptype>=332 && ptype<=333) || ptype==335 || ptype==337 || ptype==338 || (ptype>=348 && ptype<=350))
      	{
      		if(an.search(/\^-/)!=-1 || an.search(/\^\(-/)!=-1)return 1;
      		if(!(isWhat(an,1))  && !(isWhat(an,2)))return 1;
      	}
      	if((ptype>=17 && ptype<=23)|| ptype==330)
      	{
      		if(an.search(/\^-/)!=-1 || an.search(/\^\(-/)!=-1)return 1;
      	}
      	return 0;
      }
      function isReal(an) //1: true 0: false; 
      {
        if(an.length>=2)
        {
         	if((an.charCodeAt(0)>=48 && an.charCodeAt(0)<=57)||an.charCodeAt(0)==43 ||an.charCodeAt(0)==45 )
         	{
         		for(var i=1;i<an.length;i++)
         	  {
         	  	if((an.charCodeAt(i)<48 || an.charCodeAt(i)>57) && an.charCodeAt(i)!=46 )
         	  	{
         	  		return 0;
         	  	}
         	  }
         	  return 1;
         	}
        }else if(an.length==1) 
        {
        	if(an.charCodeAt(i)>=48 || an.charCodeAt(i)<=57 )
         	{
         	 	return 1;
         	}
        }
        return 0;
      }
      function isFraction(an)
      {
      	if(isInteger(an))
      	{
      		return 1;
      	}else
      	{
      		var f=an.search(/\//g);
      		if(f!=-1)
      		{
      		  var farray=an.split("/");
      			if(isInteger(farray[0]) && isInteger(farray[1]))
      			 return 1;
      		}
      	}
      }
      function isPlusminus(an)
      {
      	var cd=convertToContentDOM(an);
      	var tn=cd.firstChild.tagName;
      	if(tn.search(/plus/gi)!=-1 || tn.search(/minus/gi)!=-1)
      	{
      		return 1;
      	}else
      	{
      		return 0;
      	}
      }
      function issamepart(an,crtan,part)//1:"denominator"
      {
      	var cd=convertToContentDOM(an);
      	var crtcd=convertToContentDOM(crtan);
      	var tn;
      	var tn1;
      	var tn2;
      	switch(part)
      	{
      		case 1: tn="divide";break;
      		case 2: tn="divide";tn1="sqrt";tn2="root";break
      	}
      	if(getOs()==1)tn="mml:"+tn;
      	if(getOs()==1)
      	{
      		tn1="mml:"+tn1;
      		tn2="mml:"+tn2;
      	}
      	nodes=new Array();
      	nodes=cd.getElementsByTagName(tn);
      	crtnodes=crtcd.getElementsByTagName(tn);
        if(part==2 && nodes.length<=0)return 1;
      	for(i=0;i<nodes.length;i++)
      	{
      		if(part==1 && crtnodes[0].nextSibling.nextSibling.firstChild.nodeValue==nodes[i].nextSibling.nextSibling.firstChild.nodeValue)
      	  {      	 
      	  	return 1;
      	  }
      	  if(part==2)
      	  {
      	  	var di=nodes[i].nextSibling.nextSibling.cloneNode(true);
      	  	nodes1=new Array();
      	  	nodes1=di.getElementsByTagName(tn1);
      	  	nodes2=new Array();
      	  	nodes2=di.getElementsByTagName(tn2);
      	    if(nodes1.length<=0 && nodes2.length<=0)return 1;
      	  }
      	}
      	return 0;
      }
      function isWhat(an,kk) //1:times; 2:divide; 3:power;
      {
      	var cd=convertToContentDOM(an);
      	var tn=cd.firstChild.tagName;
      	if(kk==1)
      	{
        	if(tn.search(/times/gi)!=-1)
        	{
        		return 1;
        	}else
        	{
        		return 0;
        	}
        }
        if(kk==2)
      	{
        	if(tn.search(/divide/gi)!=-1)
        	{
        		return 1;
        	}else
        	{
        		return 0;
        	}
        }
        if(kk==3)
      	{
        	if(tn.search(/power/gi)!=-1)
        	{
        		return 1;
        	}else
        	{
        		return 0;
        	}
        }
      }
      function isInteger(an) //1: true 0: false; 
      {
        if(an.length>=2)
        {
         	if((an.charCodeAt(0)>=48 && an.charCodeAt(0)<=57)||an.charCodeAt(0)==43 ||an.charCodeAt(0)==45 )
         	{
         		for(var i=1;i<an.length;i++)
         	  {
         	  	if(an.charCodeAt(i)<48 || an.charCodeAt(i)>57 )
         	  	{
         	  		return 0;
         	  	}
         	  }
         	  return 1;
         	}
        }else if(an.length==1) 
        {
        	if(an.charCodeAt(i)>=48 || an.charCodeAt(i)<=57 )
         	{
         	 	return 1;
         	}
        }
        return 0;
      }

      function addstar(str)
      {
      	var m=0;
      	var i=0;
      	if(str.search(/INF/g)!=-1) return str;
      	if(str.search(/undefined/gi)!=-1) return str;
      	if(str.search(/not_used/gi)!=-1) return str;
      	//str=str.replace(/\s/gi,"");
      	str=str.replace(/\s+/g,"");
      	str=str.replace(/\)\(/gi,")*(");
      	str= str.replace(/\)(\w+)/gi,")*$1");
      	str=str.replace(/\$/gi,"");
      	str=str.replace(/years/gi,"");
      	str=str.replace(/\%/gi,"");
        str=str.toLowerCase();
      	len=str.length;
      	if(len>=1&& str.charAt(0)=="." && str.charAt(1)>="0" && str.charAt(1)<="9")
      	{
      		str="0"+str;
      	}
      	while(i<len)
      	{
       	  if(((str.charAt(i)>='A')&&(str.charAt(i)<='Z'))||((str.charAt(i)>='a')&&(str.charAt(i)<='z'))) 
       	  {
       	    if(m==1 || m==2)
       	  	{
         	  	str=str.substring(0,i)+"*"+str.substring(i,len);
         	    len=str.length;
         	    m=0;
       	    }else
       	    {
       	       m=1;
       	    }
       	  }else if((str.charAt(i)>='0')&&(str.charAt(i)<='9'))
       	  {
       	  	if(m==2)
       	  	{
       	  		str=str.substring(0,i)+"*"+str.substring(i,len);
         	    len=str.length;
         	    m=0;
       	    }else
       	    {
       	      m=1;
       	    }
       	  }else if(str.charAt(i)=='(')
       	  {
       	  	if(m==1 || m==2)
       	  	{
         	  	str=str.substring(0,i)+"*"+str.substring(i,len);
         	    len=str.length;
         	    m=0;
       	    }else
       	    {
       	       m=0;
       	    }
       	  }else if(str.charAt(i)==')')
       	  {
       	  	m=2;
       	  }else
       	  {
       	  	m=0;
       	  } 
          i++;
        }
       
        str=str.replace(/r\*o\*o\*t\*/gi,"root");
        str=str.replace(/c\*b\*r\*t\*/gi,"cbrt");
        str=str.replace(/f\*t\*r\*t\*/gi,"ftrt");
        str=solveroot(str,1);
        str=solveroot(str,2);
        str=solveroot(str,3);
        str=str.replace(/s\*q\*r\*t\*/gi,"sqrt");
        str=str.replace(/I\*N\*F/gi,"INF");
        str=str.replace(/f\*\(x\)/gi,"f(x)");
        return str;
      }
      function solveroot(str,rtsign)
      {
      	var rts;
      	if(rtsign==1)
      	 rts=/root/g;
      	else if(rtsign==2)
      	 rts=/cbrt/g;
      	else if(rtsign==3)
      	 rts=/ftrt/g;
      	var ind=str.search(rts);
      	if(ind!=-1)
      	{
        	k=0;
        	str1=str;
        	var ir=0;
        	while(ind!=-1)
          {
          	k++;
          	ir=ir+5+ind;
          	str1=str1.substring(ind+5,str1.length);
          	ind=str1.search(rts);
          }
          var comma=0;
          if(ir>1)
          {
          	var i=ir;
          	var j=0;
            while(i<str.length)
            {
            	if(str.charAt(i)=="(")j++;
            	if(str.charAt(i)==")")j--;
            	if(str.charAt(i)==",")comma=i;
            	if(j==-1)break;
            	i++;
            }
            if(rtsign==1)
      	      str=str.substring(0,ir-5)+"("+str.substring(ir,comma)+")^(1/("+str.substring(comma+1,i)+"))"+str.substring(i+1,str.length);
      	    else if(rtsign==2)
      	      str=str.substring(0,ir-5)+"("+str.substring(ir,i)+")^(1/3)"+str.substring(i+1,str.length);
      	    else if(rtsign==3)
      	      str=str.substring(0,ir-5)+"("+str.substring(ir,i)+")^(1/4)"+str.substring(i+1,str.length);
            if(k>=2)
             str=solveroot(str,rtsign);
          }
        }
  
        return str;
      }
      function prca()
      {
      	var k=GetBrowserElement("current").value;
      	var done=GetBrowserElement("txt_done").value;
      	var as=GetBrowserElement("as_"+k);
        if(http_request.readyState==4){
      	 if(http_request.status==200){
      	 	 //bs.value="Save Unfinished Work";
           var rt=http_request.responseText;
           var beg=rt.search("{");
           var end=rt.search("}");
           rtjson=rt.substring(beg,end+1);
      	   var resultjson=eval('('+rtjson+')');
      	   //var k=resultjson.serviceid; 
      	    	   
      	   var result=GetBrowserElement("result_"+k);
      	   if(resultjson.status=="normal" && resultjson.equality=="true")
      	   {
      	   	
      	   	 if(result.value=="20")
      	   	 { 
      	   	 	 result.value="21";
      	   	 	 checkanswerequ();
      	   	 	 return;
      	     }
      	     if(result.value=="23")
      	   	 { 
      	   	 	 result.value="24";
      	   	 	 checkanswerequ();
      	   	 	 return;
      	     }
      	   	 if(result.value=="000")
      	   	 { 
      	   	 	 result.value="100";
      	   	 	 checkanswerinte(1);
      	   	 	 return;
      	     }
      	     if(result.value=="001")
      	   	 { 
      	   	 	 result.value="101";
      	   	 	 checkanswerinte(1);
      	   	 	 return;
      	     }
      	     if(result.value=="010")
      	   	 { 
      	   	 	 result.value="110";
      	   	 	 checkanswerinte(2);
      	   	 	 return;
      	     }
      	     if(result.value=="100")
      	   	 { 
      	   	 	 result.value="110";
      	   	 	 checkanswerinte(2);
      	   	 	 return;
      	     }
      	   	 if(result.value=="10")
      	   	 { 
      	   	 	 result.value="11";
      	   	 	 checkanswerinte(1);
      	   	 	 return;
      	     }
      	     if(result.value=="12")
      	   	 { 
      	   	 	 result.value="13";
      	   	 	 checkanswerinte(3);
      	   	 	 return; 
      	     }
      	     if(result.value=="13")
      	   	 { 
      	   	 	 result.value="14";
      	   	 	 checkanswerinte(4); 
      	   	 	 return;
      	     }
      	     if(result.value=="14")
      	   	 { 
      	   	 	 result.value="15";
      	   	 	 checkanswerinte(5);
      	   	 	 return;
      	     }
      	     if(result.value=="16")
      	   	 { 
      	   	 	 result.value="17";
      	   	 	 checkanswerline(1);
      	   	 	 return;
      	     }
      	   	 var pc=postcheck(k);
      	   	 if(pc==1)
      	   	 {
      	   	 	result.value="3";
      	   	 }else
      	   	 {
      	   	 	result.value="2";
      	   	 }
      	   }else
      	   {
      	     if(result.value=="20")
      	   	 { 
      	   	 	 result.value="22";
      	   	 	 checkanswerequ();
      	   	 	 return;
      	     }
      	   	 result.value="4"; 
      	   }
      	   if(done=="0")
      	   {
      	   	 displayresult(k,0);
      	 	 }else
      	 	 {
      	 	 	 checknext();
      	 	 }
      	 }else {
      	  alert("The page you requested is abnormal.");  
      	 }
       } //end if       
      } //
      function restoreuseranswer(num,useranswer,result,trytimes)
      {
      	var em;
      	var uajson=eval('('+useranswer+')');
      	em="infix_"+num;
        if(document.getElementById(em)!=null && uajson.infix_0!=null && uajson.infix_0!="")
        {
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_0;
          	if(document.getElementById("present"+num)!=null)
          	{
          	 doIP(em,"present"+num);
          	 hideinfix(em);
          	}
        }
        em="infix1_"+num;
        if(document.getElementById(em)!=null && uajson.infix_1!=null && uajson.infix_1!="")
        {
        	  
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_1;
          	if(document.getElementById("present1_"+num)!=null)
          	{
          	 doIP(em,"present1_"+num);
          	 hideinfix(em);
          	}
        }
        em="infix2_"+num;
        if(document.getElementById(em)!=null && uajson.infix_2!=null && uajson.infix_2!="")
        {
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_2;
          	if(document.getElementById("present2_"+num)!=null)
          	{
          	 doIP(em,"present2_"+num);
          	 hideinfix(em);
          	}
        }
        em="infix3_"+num;
        if(document.getElementById(em)!=null && uajson.infix_3!=null && uajson.infix_3!="")
        {
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_3;
          	if(document.getElementById("present3_"+num)!=null)
          	{
          	 doIP(em,"present3_"+num);
          	 hideinfix(em);
          	}
        }
        em="infix4_"+num;
        if(document.getElementById(em)!=null && uajson.infix_4!=null && uajson.infix_4!="")
        {
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_4;
          	if(document.getElementById("present4_"+num)!=null)
          	{
          	 doIP(em,"present4_"+num);
          	 hideinfix(em);
          	}
        }
        em="infix5_"+num;
        if(document.getElementById(em)!=null && uajson.infix_5!=null && uajson.infix_5!="")
        {
          	inf=document.getElementById(em);
          	inf.value=uajson.infix_5;
          	if(document.getElementById("present5_"+num)!=null)
          	{
          	 doIP(em,"present5_"+num);
             hideinfix(em);
            }
        }
        em="answer_single_interval_right_"+num;
        if(document.getElementById(em)!=null && uajson.asiright!=null && uajson.asiright=="]")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="]";
          	document.getElementById("answer_single_interval_right1_"+num).innerHTML=")";
        }
        em="answer_single_interval_left_"+num;
        if(document.getElementById(em)!=null && uajson.asileft!=null && uajson.asileft=="[")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="[";
          	document.getElementById("answer_single_interval_left1_"+num).innerHTML="(";
        }
        em="answer_double_interval_left1_"+num;
        if(document.getElementById(em)!=null && uajson.adileft1!=null && uajson.adileft1=="[")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="[";
          	document.getElementById("answer_double_interval_left11_"+num).innerHTML="(";
        }
        em="answer_double_interval_right1_"+num;
        if(document.getElementById(em)!=null && uajson.adiright1!=null && uajson.adiright1=="]")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="]";
          	document.getElementById("answer_double_interval_right11_"+num).innerHTML=")";
        }
        em="answer_double_interval_left2_"+num;
        if(document.getElementById(em)!=null && uajson.adileft2!=null && uajson.adileft2=="[")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="[";
          	document.getElementById("answer_double_interval_left21_"+num).innerHTML="(";
        }
        em="answer_double_interval_right2_"+num;
        if(document.getElementById(em)!=null && uajson.adiright2!=null && uajson.adiright2=="]")
        {
          	inf=document.getElementById(em);
          	inf.innerHTML="]";
          	document.getElementById("answer_double_interval_right21_"+num).innerHTML=")";
        }
        em="check_"+num;
        if(document.getElementById(em)!=null && uajson.check!=null && uajson.check!="")
        {
        	if(uajson.check=="1")
          {
          	 inf=document.getElementById(em);
          	 inf.checked=true;
          }
        }
        em="single1_"+num;
        if(document.getElementById(em)!=null && uajson.infix_0!=null && uajson.infix_0!="")
        {
          	if(uajson.infix_0=="1")
          	{
          	 inf=document.getElementById(em);
          	 inf.checked=true;
          	}else if(uajson.infix_0=="2")
          	{
          	 inf=document.getElementById("single2_"+num);
          	 inf.checked=true;
          	}else if(uajson.infix_0=="3")
          	{
          	 inf=document.getElementById("single3_"+num);
          	 inf.checked=true;
          	}else if(uajson.infix_0=="4")
          	{
          	 inf=document.getElementById("single4_"+num);
          	 inf.checked=true;
          	}else if(uajson.infix_0=="5")
          	{
          	 inf=document.getElementById("single5_"+num);
          	 inf.checked=true;
          	}
        }
        if(parseInt(trytimes)>=5){
          displayresult(num,1);
        }else if(result!="0")displayresult(num,1);
      }
      
      function preprocess(str)
      {
      	var leftp=0;
      	var rightp=0;
        for(var k=0;k<str.length;k++)
        {
          if(str.charAt(k)=="(")
           leftp++;
          if(str.charAt(k)==")")
           rightp++;
        }
        var pnum=leftp-rightp;
        if(str.length>1)
        {
         while(pnum>0)
         {
        	str=str+")";
        	pnum--;
         }
         while(pnum<0)
         {
        	str="("+str;
        	pnum++;
         }
        }
        //alert(str);
        return str;
      }
      
      function getuseranswer(num,op)
      {   	
      	var as="";
        var inf="";
        var inf1="";
        var rs="infix_";
        var numstr=String(num);
        if(document.getElementById(rs+numstr)!=null)
        {
        	inf=document.getElementById(rs+numstr).value;
        	inf=preprocess(inf);
        	if(op==1)
        	{
        		as='"infix_0":"'+addstar(inf)+'"';
        	}else
        	{
        		as='"infix_0":"'+inf+'"';
        	}	
        }
        if(document.getElementById("single1_"+num)!=null && document.getElementById("single1_"+num).checked==true)
        {
        		as='"infix_0":"1"';	
        }
        if(document.getElementById("single2_"+num)!=null && document.getElementById("single2_"+num).checked==true)
        {
        		as='"infix_0":"2"';	
        }
        if(document.getElementById("single3_"+num)!=null && document.getElementById("single3_"+num).checked==true)
        {
        		as='"infix_0":"3"';	
        }
        if(document.getElementById("single4_"+num)!=null && document.getElementById("single4_"+num).checked==true)
        {
        		as='"infix_0":"4"';	
        }
        if(document.getElementById("single5_"+num)!=null && document.getElementById("single5_"+num).checked==true)
        {
        		as='"infix_0":"5"';	
        }
        for(var i=1;i<6;i++)
        {
        	rs="infix"+i+"_";
          if(document.getElementById(rs+String(num))!=null)
          {
          	inf=document.getElementById(rs+String(num)).value;
          	inf=preprocess(inf);
          	if(op==1)
        	  {
          	  as=as+',"infix_'+i+'":"'+addstar(inf)+'"';
            }else
            {
            	as=as+',"infix_'+i+'":"'+inf+'"';
            }
          }
        }
        if(document.getElementById("select0_"+num)!=null)
        {
        	inf=document.getElementById("select0_"+num);
        	if(op==1)
        	{
        	  as=as+',"select0":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		as=as+',"select0":"'+inf.innerHTML+'"';
        	}	
        }
        if(document.getElementById("select1_"+num)!=null)
        {
        	inf=document.getElementById("select1_"+num);
        	if(op==1)
        	{
        	  as=as+',"select1":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		as=as+',"select1":"'+inf.innerHTML+'"';
        	}	
        }
        if(document.getElementById("answer_single_interval_right_"+num)!=null)
        {
        	inf=document.getElementById("answer_single_interval_right_"+num);
        	if(op==1)
        	{
        	  as=as+',"asiright":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		as=as+',"asiright":"'+inf.innerHTML+'"';
        	}
        	
        }
        if(document.getElementById("answer_single_interval_left_"+num)!=null)
        {
        	inf=document.getElementById("answer_single_interval_left_"+num);
        	if(op==1)
        	{
        	  as=as+',"asileft":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		 as=as+',"asileft":"'+inf.innerHTML+'"';
        	}	
        }
        if(document.getElementById("answer_double_interval_left1_"+num)!=null)
        {
        	inf=document.getElementById("answer_double_interval_left1_"+num);
        	if(op==1)
        	{
        	  as=as+',"adileft1":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		 as=as+',"adileft1":"'+inf.innerHTML+'"';
        	}	
        }
        if(document.getElementById("answer_double_interval_right1_"+num)!=null)
        {
        	inf=document.getElementById("answer_double_interval_right1_"+num);
        	if(op==1)
        	{
        	  as=as+',"adiright1":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		 as=as+',"adiright1":"'+inf.innerHTML+'"';
        	}	
        }
        if(document.getElementById("answer_double_interval_left2_"+num)!=null)
        {
        	inf=document.getElementById("answer_double_interval_left2_"+num);
        	if(op==1)
        	{
        	  as=as+',"adileft2":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		 as=as+',"adileft2":"'+inf.innerHTML+'"';
        	}		
        }
        if(document.getElementById("answer_double_interval_right2_"+num)!=null)
        {
        	inf=document.getElementById("answer_double_interval_right2_"+num);
        	if(op==1)
        	{
        	  	as=as+',"adiright2":"'+addstar(inf.innerHTML)+'"';
        	}else
        	{
        		 	as=as+',"adiright2":"'+inf.innerHTML+'"';
        	}	
        }
     
        if(document.getElementById("check_"+num)!=null)
        {
        	if(as!="")
        	{
        		as=as+',';
        	}
        	if(document.getElementById("check_"+num).checked==true)
        		as=as+'"check":"1"';
        	else
        		as=as+'"check":"0"';
        }
        var asjson='{'+as+'}';
        return asjson;   
      }
      function checknext()
      { 	
      	if(GetBrowserElement("txt_done").value=="0")return;
      	var k=GetBrowserElement("current").value;
      	var num_questions=GetBrowserElement("num_questions").value;
      	if(parseInt(k)<parseInt(num_questions))
      	 checkanswer(parseInt(k)+1);
      	else
      	{
      		save();
      	}
      }
      function Submit()
      {
      	if(!confirm("Submit your assignment?"))return;
      	btndisab(1);
      	GetBrowserElement("txt_done").value="1";
      	var sta=document.getElementById("sta");
      	sta.value="2";
      	checkanswer(1);
      }
      function btndisab(bdi)
      {
      	if(bdi==1)
      	{
      	 GetBrowserElement("btn_next").disabled=true;
      	 GetBrowserElement("btn_next").style.color="#a5a5a5";
      	 GetBrowserElement("btn_previous").disabled=true;
      	 GetBrowserElement("btn_previous").style.color="#a5a5a5";
      	 GetBrowserElement("btn_submit").disabled=true;
      	 GetBrowserElement("btn_submit").style.color="#a5a5a5";
      	 GetBrowserElement("btn_save").disabled=true;
      	 GetBrowserElement("btn_save").style.color="#a5a5a5";
      	 GetBrowserElement("btn_close").disabled=true;
      	 GetBrowserElement("btn_close").style.color="#a5a5a5";
      	}else
      	{
      	 if(GetBrowserElement("btn_next")!=null)
      	 {
      	  GetBrowserElement("btn_next").disabled=false;
      	  GetBrowserElement("btn_next").style.color="";
      	 }
      	 if(GetBrowserElement("btn_previous")!=null)
      	 {
      	  GetBrowserElement("btn_previous").disabled=false;
      	  GetBrowserElement("btn_previous").style.color="";
      	 }
      	 if(GetBrowserElement("btn_submit")!=null)
      	 {
      	  GetBrowserElement("btn_submit").disabled=false;
      	  GetBrowserElement("btn_submit").style.color="";
      	 }
      	 if(GetBrowserElement("btn_save")!=null)
      	 {
      	  GetBrowserElement("btn_save").disabled=false;
      	  GetBrowserElement("btn_save").style.color="";
       	 }
       	 if(GetBrowserElement("btn_close")!=null)
      	 {
      	  GetBrowserElement("btn_close").disabled=false;
      	  GetBrowserElement("btn_close").style.color="";
      	 }
      	}
      }
      function openw(rpstxt)
      {
      	var rpsjson=eval('('+rpstxt+')');
      	
      	var num_questions=GetBrowserElement("num_questions").value;
      	var surl="takeAssignmentSummary.php?nums="+num_questions+"&cnums="+rpsjson.cnums+"&atid="+rpsjson.atid+"&aid=<? echo($_GET['id']); ?>&cid=<? echo($_GET['cid']); ?>";
      	top.location.href=surl;   
      }
      
      var http_request=false;
      
      function save()
      {
      	btndisab(1);
      	var done=GetBrowserElement("txt_done").value;
      	var txt_started=GetBrowserElement("txt_started").value;
      	var txt_finished=GetBrowserElement("txt_finished").value;
      	var num_questions=GetBrowserElement("num_questions").value;
      	var params="id=<? echo($_GET['id']); ?>";
        params=params+"&txt_started="+txt_started+"&txt_finished="+encodeURIComponent(txt_finished)+"&num_questions="+num_questions+"&txt_done="+done;
        params=params+"&finish=<? echo($_GET['finish']); ?>&cid=<? echo($_GET['cid']); ?>";
        var k=1;
        while(k<= num_questions)
        {
        	var txt_problemType=GetBrowserElement("txt_problemType_"+k).value;
        	var trytimes=GetBrowserElement("trytimes_"+k).value;
        	var result=GetBrowserElement("result_"+k).value;
        	params=params+"&txt_problemType_"+k+"="+txt_problemType;
        	params=params+"&useranswer_"+k+"="+encodeURIComponent(getuseranswer(k,0));
        	params=params+"&active_"+k+"="+trytimes;
        	params=params+"&result_"+k+"="+result;
        	for (var j = 0; j < 6; j++)
          {
          	var txt_array=GetBrowserElement("txt_array_"+j+"_"+k).value;
          	if(j==1)
          	{
          		txt_array=catch_cheater(txt_array);
          	}
          	txt_array=encodeURIComponent(txt_array);
          	params=params+"&txt_array_"+j+"_"+k+"="+txt_array;
          }
          k++;
        }
        var strHtml  = "Saving, please Wait...";
        sAlert(strHtml,400,100);
      	send_request("saveAssignment.php",params,processrequest);
      }
      function saveHomework(num)//modify: 2009-120-04
      {
      	btndisab(1);
      	var done=GetBrowserElement("txt_done").value;
      	var txt_started=GetBrowserElement("txt_started").value;
      	var txt_finished=GetBrowserElement("txt_finished").value;
      	var num_questions=GetBrowserElement("num_questions").value;
      	var params="id=<? echo($_GET['id']); ?>";
        params=params+"&txt_started="+txt_started+"&txt_finished="+encodeURIComponent(txt_finished)+"&num_questions="+num_questions+"&txt_done="+done;
        params=params+"&finish=<? echo($_GET['finish']); ?>&cid=<? echo($_GET['cid']); ?>";
        var k=1;
        while(k<= num_questions)
        {
        	var txt_problemType=GetBrowserElement("txt_problemType_"+k).value;
        	var trytimes=GetBrowserElement("trytimes_"+k).value;
        	var result=GetBrowserElement("result_"+k).value;
        	params=params+"&txt_problemType_"+k+"="+txt_problemType;
        	params=params+"&useranswer_"+k+"="+encodeURIComponent(getuseranswer(k,0));
        	params=params+"&active_"+k+"="+trytimes;
        	params=params+"&result_"+k+"="+result;
        	params=params+"&saveNumber="+num;
        	for (var j = 0; j < 6; j++)
          {
          	var txt_array=GetBrowserElement("txt_array_"+j+"_"+k).value;
          	if(j==1)
          	{
          		txt_array=catch_cheater(txt_array);
          	}
          	txt_array=encodeURIComponent(txt_array);
          	params=params+"&txt_array_"+j+"_"+k+"="+txt_array;
          }
          k++;
        }
//        document.getElementById("sta").value="x";
      	send_request("saveAssignment1.php",params,processrequest);
//      	document.getElementById("sta").value="0";
      }

      function send_request(url,params,pr)
      { 
      	http_request=false;
      	if(window.XMLHttpRequest)
      	{ 
      		http_request=new XMLHttpRequest();
      	  if(http_request.overrideMimeType)
      	  { 
      	  	http_request.overrideMimeType("text/xml");
      	  }
      	}else if(window.ActiveXObject){
      	  try{
      	    http_request=new ActiveXObject("Msxml2.XMLHttp");
      	  }catch(e){
      	   try{
      	     http_request=new ActiveXobject("Microsoft.XMLHttp");
      	   }catch(e){}
      	  }
      	}
      
      	if(!http_request){
      	 window.alert("Fail to create XMLHttp Object.");
      	 return false; 
      	} 
      	http_request.onreadystatechange=pr; 
      	http_request.open("POST",url,true);
      	http_request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;");
      	http_request.send(params);
      	
      }
      function processrequest()
      {
      	if(http_request.readyState<4)
      	{
      		var a1="Saving...";
      	}
      	
        if(http_request.readyState==4){
      	 if(http_request.status==200){
      	    btndisab(0);
      	   	var sta=document.getElementById("sta");
      	   	if(sta.value=="0")
      	   	{
      	    	var sh=document.getElementById("alertFram");
      	    	sh.innerHTML="<div style='background:#3399cc;align:left;color:#ff9900;font-weight: bold'>MathPASS</div><br/>Save Successfully!<br/><a href='#' onClick='doOk();'>Go Back to Continue</a> | <a href='#' onClick='window.close();'>Close the Assignment</a>"
      	    }else if(sta.value=="1")
      	    {
      	     	window.close();
      	    }else if(sta.value=="2") 
      	    {
              openw(http_request.responseText);
      	    }	else {
      	    	;   //modify: 2009-120-04
      	    }
      	 }else {
      	   alert("The page you requested is abnormal.");  
      	 }
       } //end if       
      } //
      
      function parenthover(pid)
      {
      	var pdiv=GetBrowserElement(pid);
      	pdiv.style.display="block";
      	
      }
      function parenthout(pid)
      {
      	var pdiv=GetBrowserElement(pid);
      	pdiv.style.display="none";
      }
      function changep(pid1,pid,pkind)
      {
      	var pdiv1=GetBrowserElement(pid1);
      	var pdiv=GetBrowserElement(pid);
      	if(pkind==1)
      	{
        	if(pdiv1.innerHTML=="(")
        	{
        		pdiv.innerHTML="(";
        		pdiv1.innerHTML="[";
        	}else if(pdiv1.innerHTML=="[")
        	{
        		pdiv.innerHTML="[";
        		pdiv1.innerHTML="(";
        	}
        	if(pdiv1.innerHTML=="Left")
        	{
        		pdiv.innerHTML="Left";
        		pdiv1.innerHTML="Right";
        	}else if(pdiv1.innerHTML=="Right")
        	{
        		pdiv.innerHTML="Right";
        		pdiv1.innerHTML="Left";
        	}
        }else if(pkind==2)
        {
        	 if(pdiv1.innerHTML==")")
        	{
        		pdiv.innerHTML=")";
        		pdiv1.innerHTML="]";
        	}else if(pdiv1.innerHTML=="]")
        	{
        		pdiv.innerHTML="]";
        		pdiv1.innerHTML=")";
        	}
        	 if(pdiv1.innerHTML=="Up")
        	{
        		pdiv.innerHTML="Up";
        		pdiv1.innerHTML="Down";
        	}else if(pdiv1.innerHTML=="Down")
        	{
        		pdiv.innerHTML="Down";
        		pdiv1.innerHTML="Up";
        	}
        }
      	//pdiv.style.display="none";
      }
      function protectwindow()
      {
      	//alert("Welcome to use MathPASS.");
      	return false;
      }
      document.oncontextmenu=protectwindow;
		</script>
		<? global $scripts; echo($scripts); ?>
		<script language="javascript">
		function GenericCode()
		{
		<? global $scriptCode; echo($scriptCode); ?>
		}
		</script>
		
		<style>
		BODY
		{
			padding:5px 0px 0px 0px;
			margin:0px 0px 0px 0px;
			background-color:#F5F8F9;
			text-align:center;
		}
		BUTTON
		{
			display:inline;
		}
		</style>
	</head>
	<body onLoad="javascript:Initialize();<? echo($tOnload); ?>"<? global $bodyProperties;echo($bodyProperties); ?> >
	<?
//		$lay_answerChecker=new LayoverGenerator("lay_answerChecker");
//		$lay_answerChecker->InnerHtml='<Iframe id="ifrm_mathHelp" frameborder="0" src="mathHelp/template.html" width="100%" height="100%"></iframe>';
//		$lay_answerChecker->Render();
//		$lay_answerChecker->Dispose();
	?>
	<form id="frm_body" name="frm_body" method="post" action="takeAssignmentSummary.php">
		<input type="hidden" id="txt_started" name="txt_started" value="<? echo(mktime()); ?>" />
		<input type="hidden" id="txt_question" name="txt_question" value="" />
		<input type="hidden" id="txt_done" name="txt_done" value="0" />
    <input type="hidden" id="txt_finished" name="txt_finished" value="" />
    <input type="hidden" name="test_name" value="<? echo($pgTitle); ?>" />
    <input type="hidden" id="num_questions" name="num_questions" value="<? echo($number); ?>" />
    <input type="hidden" name="problem_set" value="TRUE">
    <input type="hidden" name="display_name" value="<? echo($pgTitle); ?>" />
    <input type="hidden" name="test_name" value="<? echo($pgTitle); ?>"/>
    <input type="hidden" name="current" id="current" value=""/>
    <input type="hidden" name="sta" id="sta" value="0" />
		<p>
<!--
		<table id="tbl_loading" width="750" border="0" cellpadding="100" cellspacing="0">
			<tr>
				<td align="center">
				<img src="pics/loading.gif" alt="Please wait while the page loads..." /></td>
			</tr>
		</table>
		<table id="tbl_installmath" width="750" border="0" cellpadding="100" cellspacing="0" style="display:none;">
			<tr>
				<td align="center">
				"MathPlayer" is required for viewing of mathematical functions and symbols in IE browswer. Please <a target="_blank" href="http://www.dessci.com/en/products/mathplayer/download.htm">click here</a> to go to download page. After
				 installed please close the current IE window and open the assignment again. Thank you.</td>
			</tr>
		</table>
-->
		<table id="tbl_form" width="750" border="0" align="center" cellpadding="0" cellspacing="0" style="display:none; ">
			<tr>
				<td>
				<table width="100%" border="0" cellpadding="0" cellspacing="0">
					<tr>
						<td>
						<img src="pics/logo.png" alt="Math Pass V3.1" /></td>
						<td class="ws1" width="200">
						<?if($openmode==3) echo("This is a finished assignment"); else if($b->User->Type!="0"){ echo("Welcome,<b>".$b->User->FirstName."</b>");} else echo "Welcome,<b>Guest</b>"?></span></td>
					</tr>
				</table>
				</td>
			</tr>
			<tr>
				<td>
				<img src="pics/blank.gif" alt="" height="5" /></td>
			</tr>
			<tr>
				<td style="padding:5px 5px 5px 5px;border-style:solid;border-color:#b0b0b0;border-width:1px;background-color:white;">
				<table id="tbla" width="100%" border="0" cellpadding="0" cellspacing="2">
					<tr>
						<td colspan="2">
						<h3 class="h3"><? global $pageTitle;if($openmode==1){}else if($type==1){$typeWord="Homework --> ";}else if($type==2){$typeWord="Quiz --> ";}else if($type==3){$typeWord="Test --> ";}else{$typeWord="Practice";} echo($typeWord.$pageTitle); ?></h3></td>
					</tr>
					<tr>
						<td colspan="2" id="td_assignmentNavigation">
						<? echo($navigation); ?>
						<p style="margin-top:4px;padding:3px 3px 3px 3px;"><a href="javascript:Last();">Previous</a>&nbsp;|&nbsp;<a href="javascript:Next();" >Next</a></p></td>
					</tr>
					<tr>
						<td class="ws2">
<?
if($_GET["finish"])
{
 $i=0;
 while($i<$number)
 {
	$i=$i+1;
	//generate problems and descriptions
	
		$pType="";
		$q0="";
		$q1="";
		$q2="";
		$q3="";
		$q4="";
		
		$sql="SELECT fk_problem,array_0,array_1,array_2,array_3,array_4,useranswer,active,result";
		$sql.=" FROM assignmenttakequestions";
		$sql.=" WHERE (fk_assignmentTake=" . $finish . " AND number=" . $i . " )";
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$pType=$dr[0];
			$q0=$dr[1];
			$q1=$dr[2];
			$q2=$dr[3];
			$q3=$dr[4];
			$q4=$dr[5];
			$useranswer=$dr[6];
			$active=$dr[7];
			$result1=$dr[8];	
		}
		if($openmode==2)
		{
		  GenProblem(1,$i,$pType,0,$q0,$q1,$q2,$q3,$q4,$useranswer,$active,$result1);
	  }else if($openmode==3)
	  {
	  	GenProblem(1,$i,$pType,0,$q0,$q1,$q2,$q3,$q4,$useranswer,5,$result1);
	  }
	}	
}
if($openmode==1)
{
	$n=0;
	$i=1;
	while($n<count($list))
	{
		 $m=0;
		 while($m<$indivNumber)
		 {
			$m++;
		  GenProblem(0,$i,$list[$n]);
		  $i++;
		 }
		 $n++;
	}
}
if(!($_GET["finish"]) && $openmode!=1)
{
  $sql="SELECT fk_problem,numbers";
  $sql.=" FROM assignmentquestions";
  $sql.=" WHERE ( assignmentquestions.fk_assignment=" . $id . " AND assignmentquestions.active=1 )";
  $sql.=" order by sortnum";
  $ds=$con->Query($sql);
  $u=1;
  while($dr=mysql_fetch_row($ds))
  {
  	for($j=1;$j<=$dr[1];$j++)
  	  GenProblem(0,$u++,$dr[0]);
  }
}
?>         
</td>
						<td width="200" valign="top">
						<table width="100%" border="0" cellpadding="2" cellspacing="2">
							<tr>
								<td class="ws">
								<div id="spn_singleProblemView" class="questionViewOff" onClick="javascript:SingleProblemView();">&nbsp;Single Question View</div>
								<p style="margin:0px 0px 0px 0px;padding:5px 0px 0px 0px;"><div id="spn_multipleProblemView" class="questionViewOff" onClick="javascript:MultipleProblemView();">&nbsp;Multiple Question View</div></p></td>
							</tr>
							<tr>
								<td class="ws">
								<ul style="margin-top:0px;margin-bottom:0px;">
									<li class="black">Started at:&nbsp;<span id="spn_started"></span></li>
									<li class="black">Time spent:&nbsp;<span id="spn_spent"></span></li>
								</ul></td>
							</tr>
							<tr>
								<td class="ws">
								You are working on <? echo($problemDescriptions); ?>. <br/> </td>
							</tr>
							<tr>
								<td>
								</td>
							</tr>
						</table></td>
					</tr>
					<tr>
						<td align="center">
						<button type="button" id="btn_previous" onClick="javascript:Last();" class="button1">Previous</button>&nbsp;	
						<button type="button" id="btn_next" onClick="javascript:Next();" class="button1">Next</button>&nbsp;
						<button type="button" id="btn_save" name="btn_save" onClick="javascript:save();" class="button1">Save Unfinished Work</button>&nbsp;
						<button type="button" id="btn_submit" name="btn_submit" onClick="javascript:Submit();" class="button1">Submit Assignment</button></td>
						<td align= "right" style="padding:0px 14px 0px 0px">
						<button type="button" id="btn_close" onClick="javascript:winClose();" class="button1" class="button1">Close</button></td>
					</tr>
				</table></td>
			</tr>
		</table>
		</p>
	</form>
	</body>
</html>

<?
 $con->Dispose();
 $b->Dispose();
?>
