<?php

//// this function will parse the question string and return
//// an array of strings that will make the math look decent
//// it will serve as a substitute until the third stage of the
//// the project, when I will concentrate on making everthing
//// look pretty

function parse_question($question,$q_type,$num)
{
    $numerator = "1";
    $denominator = "1";
    $short_line = "40";
    $mdm_line = "70";
    $long_line = "140";
    $longer_line = "170";
    if ($q_type <= 139 ||($q_type>=156 and $q_type<=162)||($q_type>=204 and $q_type<=210)||($q_type>=228 and $q_type<=267)||($q_type>=274 and $q_type<=276)||($q_type>=281 and $q_type<=291)||($q_type>=296 and $q_type<=309)||($q_type>=330 and $q_type<=350))
    {
     $question=str_replace(" ","",$question);
     $mathq='<center><div id="question'.$num.'" class="question"></div><center>';
     $mathq.='<script type="text/javascript">';
	   $mathq.=' var rx=convertToPresentDOM("'.$question. '",document);';
		 $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
		 $mathq.='</script>';
     return $mathq;
    }
    else if ($q_type >= 140 && $q_type<=151)
    {
       $question=str_replace(" ","",$question);
       $q_array = explode('@@',$question);
       $mathq='<center>Given <span id="question'.$num.'" class="question"></span>, find <span id="question1_'.$num.'" class="question"></span>.</center>';
       $mathq.='<script type="text/javascript">';
	     $mathq.=' var rx=convertToPresentDOM("'.$q_array[0]. '",document);';
	  	 $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
	  	 $mathq.=' var rx1=convertToPresentDOM("'.$q_array[1]. '",document);';
	  	 $mathq.=' var quest1=document.getElementById("question1_'.$num.'");quest1.appendChild(rx1);';
	  	 $mathq.='</script>';
	  	 return $mathq;
    } 
    else if ($q_type >= 152 && $q_type <= 154)
    {
    
        $q_array = explode('@@',$question);
        $q_array[0] = str_replace('#','&#39;',$q_array[0]);
        $q_array[1]=str_replace(" ","",$q_array[1]);
        $mathq=$q_array[0];
        $mathq.='<center><div id="question'.$num.'" class="question"></div></center>';
        $mathq.= $q_array[2];
        $mathq.='<script type="text/javascript">';
	      $mathq.=' var rx=convertToPresentDOM("'.$q_array[1]. '",document);';
		    $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
		    $mathq.='</script>';
        return $mathq;
    }
    else if ($q_type == 155)
    {
       $question=str_replace(" ","",$question);
       $q_array = explode('@@',$question);
       $mathq='<center>Given <span id="question'.$num.'" class="question"></span>&nbsp; and &nbsp;<span id="question1_'.$num.'" class="question"></span> , find <span id="question2_'.$num.'" class="question"></span>.</center>';
       $mathq.='<script type="text/javascript">';
	     $mathq.=' var rx=convertToPresentDOM("'.$q_array[0]. '",document);';
	  	 $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
	  	 $mathq.=' var rx1=convertToPresentDOM("'.$q_array[1]. '",document);';
	  	 $mathq.=' var quest1=document.getElementById("question1_'.$num.'");quest1.appendChild(rx1);';
	  	 $mathq.=' var rx2=convertToPresentDOM("'.$q_array[2]. '",document);';
	  	 $mathq.=' var quest2=document.getElementById("question2_'.$num.'");quest2.appendChild(rx2);';
	  	 $mathq.='</script>';
	  	 return $mathq;
    }
    else if ($q_type >= 163 && $q_type <= 164)
    {
        $q_array = explode('@@',$question);
        $mathq= '<center>Passes through: ('.$q_array[0].','.$q_array[1].') with slope: ';
        if (strlen($q_array[3]))
        {
         $mathq.='<span id="question'.$num.'" class="question"></span></center>';
         $mathq.='<script type="text/javascript">';
	        $mathq.=' var rx=convertToPresentDOM("'.$q_array[2]. '/'.$q_array[3].'",document);';
		      $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
		      $mathq.='</script>';
        }else
        {
          $mathq.=$q_array[2].'</center>';
        }
        return $mathq;
    }
    else if (($q_type >= 165 && $q_type<=179 )||($q_type==188 )||($q_type>=191 && $q_type<=203 )||($q_type>=211 && $q_type<=216 )||($q_type==268)||($q_type>=321 && $q_type<=329 ))
    {
        $mathq= "<center>".$question."</center>";
        return $mathq;
    }else if(($q_type >= 180 && $q_type<=185)||$q_type==190 ||($q_type>=222 && $q_type<=227 ) ||($q_type>=292 && $q_type<=295 ))
    {
      $mathq= "<div align='left'>".$question."</div>";
      return $mathq;
    }
    else if ($q_type>=186 && $q_type <= 187)
    {
        $q_array = explode('@',$question);
        $mathq = "<div align='left'>".$q_array[0]."</div>\n";
        $mathq .= "<table border='0' cellspacing='1' cellpadding='1' align='center>\n'";
        $mathq .= "<tr><td align='center'><i>f</i>( <i>i</i> ) = ".$q_array[1]." <i>i</i></td></tr>\n";
        $mathq .= "<tr><td><br></tr></td>\n";
        $mathq .= "<tr><td align='center'>\n";
        $mathq .= "<table border='0' cellspacing='0' cellpadding='0'>\n";
        $mathq .= "<tr><td valign='center' rowspan=2><i>g</i>( <i>i</i> ) = </td>\n";
        $mathq .= "<td valign='center' rowspan=2><font size='7'>{</font></td>";
        $mathq .= "<td>".$q_array[2]." <i>i</i></td><td>for <i>i</i> <u>&#60;</u> $".$q_array[3];
        $mathq .= "</td></tr><tr><td>\n";
        $mathq .= $q_array[4]." + ".$q_array[5]."( <i>i</i> - ".$q_array[6]." )&nbsp;&nbsp;&nbsp;</td>\n";
        $mathq .= "<td> for <i>i</i> &#62 $".$q_array[7]."</td></tr></table>\n";
        $mathq .= "</td></tr><tr><td><br></td></tr><tr><td>\n";
        $mathq .= "<p><center>".$q_array[8]."</center></p>";
        $mathq .= "</td></tr></table>";
        return $mathq;
    }
    else if ($q_type == 189)
    {
        $q_array = explode('@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<table border='0' cellspacing='1' cellpadding='1' align='center>\n'";
        $mathq .= "<tr><td align='center'><i>f</i>( <i>i</i> ) = ".$q_array[1]." <i>i</i></td></tr>\n";
        $mathq .= "<tr><td><br></tr></td>\n";
        $mathq .= "<tr><td align='center'>\n";
        $mathq .= "<table border='0' cellspacing='0' cellpadding='0'>\n";
        $mathq .= "<tr><td valign='center' rowspan=2><i>g</i>( <i>i</i> ) = </td>\n";
        $mathq .= "<td valign='center' rowspan=2><font size='7'>{</font></td>";
        $mathq .= "<td>".$q_array[2]." <i>i</i></td><td>for <i>i</i> <u>&#60;</u> $".$q_array[3];
        $mathq .= "</td></tr><tr><td>\n";
        $mathq .= $q_array[4]." + ".$q_array[5]."( <i>i</i> - ".$q_array[6]." )&nbsp;&nbsp;&nbsp;</td>\n";
        $mathq .= "<td> for <i>i</i> &#62 $".$q_array[7]."</td></tr></table>\n";
        $mathq .= "</td></tr><tr><td><br></td></tr><tr><td>\n";
        $mathq .= "<p><center>".$q_array[8]."</center></p>";
        $mathq .= "</td></tr></table>";
        return $mathq;
    }
    else if ($q_type == 217)
    {
        $q_array = explode('@',$question);
        $mathq = "<table border=2 cellspacing=1 cellpadding=4 align=center>\n";
        $mathq .= "<tr><td><br></td><td>Initial Salary</td><td>Raise per Year</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td> Job A </td><td>$$q_array[0]</td><td>$q_array[2]%</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td> Job B </td><td>$$q_array[1]</td><td>$q_array[3]%</td>\n";
        $mathq .= "</tr></table>";
        return $mathq;
    }
    else if ($q_type == 218)
    {
        $q_array = explode('@',$question);
        $mathq = "<table border=2 cellspacing=1 cellpadding=4 align=center>\n";
        $mathq .= "<tr><td>x &nbsp;&nbsp;</td><td>f(x) &nbsp;&nbsp;</td>\n";
        for ($i = 0; $i < 10; $i++)
        {
            $mathq .= "</tr><tr>\n";
            $mathq .= "<td>".$q_array[$i]."</td><td>".$q_array[$i+1]."</td>\n";
            $i++;
        }
        $mathq .= "</tr></table>";
        return $mathq;
    }
    else if ($q_type == 219)
    {
        $q_array = explode('@',$question);
        $mathq = "<table border=2 cellspacing=1 cellpadding=4 align=center>\n";
        $mathq .= "<tr><td><br></td><td>Initial Salary</td><td>Raise</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td> Job A </td><td>$$q_array[0]</td><td>$$q_array[2] every $q_array[3] months</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td> Job B </td><td>$$q_array[1]</td><td>$q_array[4]% per year</td>\n";
        $mathq .= "</tr></table>";
        return $mathq;
    }
    else if ($q_type == 220)
    {
        $q_array = explode('@',$question);
        $mathq = "<table border=2 cellspacing=1 cellpadding=4 align=center>\n";
        $mathq .= "<tr><td>t</td><td>P(t)</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td>$q_array[0]</td><td>$q_array[1]</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td>$q_array[2]</td><td>$q_array[3]</td>\n";
        $mathq .= "</tr></table>";
        return $mathq;
    }
    else if ($q_type == 221)
    {
        $q_array = explode('@',$question);
        $mathq = "<table border=2 cellspacing=1 cellpadding=4 align=center>\n";
        $mathq .= "<tr><td>t</td><td>P(t)</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td>$q_array[0]</td><td>$q_array[1]</td>\n";
        $mathq .= "</tr><tr>\n";
        $mathq .= "<td>$q_array[2]</td><td>$q_array[3]</td>\n";
        $mathq .= "</tr></table>";
        return $mathq;
    }
    else if ($q_type >= 269 && $q_type <= 273)
    {
        $q_array = explode('@@',$question);
        $q_array[1]=str_replace(" ","",$q_array[1]);
        $q_array[2]=str_replace(" ","",$q_array[2]);
        $mathq = 'Given the functions below find '.$q_array[0].'.<br><span id="question'.$num.'" class="question"></span><br/> <span id="question1_'.$num.'" class="question"></span>.</center>';
        $mathq.='<script type="text/javascript">';
	      $mathq.=' var rx=convertToPresentDOM("'.$q_array[1]. '",document);';
	  	  $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
	  	  $mathq.=' var rx1=convertToPresentDOM("'.$q_array[2]. '",document);';
	  	  $mathq.=' var quest1=document.getElementById("question1_'.$num.'");quest1.appendChild(rx1);';
	  	  $mathq.='</script>';
        return $mathq;
    }
    else if ($q_type == 277)
    {
        $q_array = explode('@@',$question);
        $q_array[0]=str_replace(" ","",$q_array[0]);
        $mathq.='<center><div id="question'.$num.'" class="question"></div>'.$q_array[1].'</center>';
        $mathq.='<script type="text/javascript">';
	      $mathq.=' var rx=convertToPresentDOM("'.$q_array[0]. '",document);';
		    $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
		    $mathq.='</script>';
        return $mathq;
    }
    else if ($q_type >= 278 && $q_type <= 280)
    {
        $q_array = explode('@@',$question);
        $q_array[1]=str_replace(" ","",$q_array[1]);
        $mathq.=$q_array[0];
        $mathq.='<span id="question'.$num.'" class="question"></span></center>';
        $mathq.='<script type="text/javascript">';
	      $mathq.=' var rx=convertToPresentDOM("'.$q_array[1]. '",document);';
		    $mathq.=' var quest=document.getElementById("question'.$num.'");quest.appendChild(rx);';
		    $mathq.='</script>';
        return $mathq;
    }
    else if ($q_type == 310)
    {
        $q_array = explode('@@',$question);
        $q_array[0]=str_replace(" ","",$q_array[0]);
        $mathq = "<p><center><span id='question".$num."' class='question'></span></center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= "<div id='question1_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= "<div id='question2_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= "<div id='question3_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= "<div id='question4_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= "<div id='question5_".$num."' class='question'></div>";
        $mathq .= "</td></tr></table>\n";
        $mathq.="<script type='text/javascript'>";
        $mathq.=" var rx=convertToPresentDOM('".$q_array[0]. "',document);";
	  	  $mathq.=" var quest=document.getElementById('question".$num."');quest.appendChild(rx);";   
         for ($i = 1; $i < 6; $i++)
        {
        	$q_array[$i] = ereg_replace("xmlns:mml=http://www.w3.org/1998/Math/MathML", "xmlns:mml=\"http://www.w3.org/1998/Math/MathML\"", $q_array[$i]);
	      $mathq.=" var rx".$i."=createMSXML('".$q_array[$i]. "');";
	      $mathq.=" var root".$i."=rx".$i.".documentElement;";
	  	  $mathq.=" var quest".$i."=document.getElementById('question".$i."_".$num."');if(getOs()==1)quest".$i.".innerHTML=root".$i.".xml;else quest".$i.".appendChild(root".$i.");";
	  	  }
	  	  $mathq.="</script>";
        return $mathq;
    }
    else if ($q_type == 311)
    {
        $q_array = explode('@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= $q_array[1];
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= $q_array[2];
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= $q_array[3];
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= $q_array[4];
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= $q_array[5];
        $mathq .= "</td></tr></table>\n";
        return $mathq;
    }
    else if ($q_type == 312)
    {
        $q_array = explode('@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= $q_array[1];
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= $q_array[2];
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= $q_array[3];
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= $q_array[4];
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= $q_array[5];
        $mathq .= "</td></tr></table>\n";
        return $mathq;
    }
    else if ($q_type == 313)
    {
        $q_array = explode('@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= $q_array[1];
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= $q_array[2];
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= $q_array[3];
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= $q_array[4];
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= $q_array[5];
        $mathq .= "</td></tr></table>\n";
        return $mathq;
    }
    else if ($q_type == 314)
    {
        $mathq = "<p><center>".$question."</center></p>\n";
        return $mathq;
    }
    else if ($q_type == 315)
    {
        $mathq = "<p><center>".$question."</center></p>\n";
        return $mathq;
    }
    else if ($q_type == 316)
    {
        $q_array = explode('@@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= "<div id='question1_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= "<div id='question2_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= "<div id='question3_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= "<div id='question4_".$num."' class='question'></div>";
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= "<div id='question5_".$num."' class='question'></div>";
        $mathq .= "</td></tr></table>\n";
        $mathq.="<script type='text/javascript'>";
         for ($i = 1; $i < 6; $i++)
        {
        $q_array[$i] = ereg_replace("xmlns:mml=http://www.w3.org/1998/Math/MathML", "xmlns:mml=\"http://www.w3.org/1998/Math/MathML\"", $q_array[$i]);
	      $mathq.=" var rx".$i."=createMSXML('".$q_array[$i]. "');";
	      $mathq.=" var root".$i."=rx".$i.".documentElement;";
	  	  $mathq.=" var quest".$i."=document.getElementById('question".$i."_".$num."');if(getOs()==1)quest".$i.".innerHTML=root".$i.".xml;else quest".$i.".appendChild(root".$i.");";
	  	  }
	  	  $mathq.="</script>";
        return $mathq;
    }
    else if ($q_type == 317)
    {
        $mathq = "<p><center>".$question."</center></p>\n";
        return $mathq;
    }
    else if ($q_type == 318)
    {
        $mathq = "<p><center>".$question."</center></p>\n";
        return $mathq;
    }
    else if ($q_type == 319)
    {
        $q_array = explode('@',$question);
        $mathq = "<p><center>".$q_array[0]."</center></p>\n";
        $mathq .= "<br><br>\n";
        $mathq .= "<table border=2 cellspacing=4 cellpadding=6 align=center>\n";
        $mathq .= "<tr><td><font size=4>A</font></td><td>\n";
        $mathq .= $q_array[1];
        $mathq .= "</td></tr>\n<tr><td><font size=4>B</font></td><td>\n";
        $mathq .= $q_array[2];
        $mathq .= "</td></tr>\n<tr><td><font size=4>C</font></td><td>\n";
        $mathq .= $q_array[3];
        $mathq .= "</td></tr>\n<tr><td><font size=4>D</font></td><td>\n";
        $mathq .= $q_array[4];
        $mathq .= "</td></tr>\n<tr><td><font size=4>E</font></td><td>\n";
        $mathq .= $q_array[5];
        $mathq .= "</td></tr></table>\n";
        return $mathq;
    }
    else if ($q_type == 320)
    {
        $mathq = "<p><center>".$question."</center></p>\n";
        return $mathq;
    }
    else
    {
        $final_form = array($numerator,$denominator);
        return $final_form;
    }

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////       parse question table template               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

/*
        $q_array = explode('@',$question);
        $mathq  = "<table border='0' cellpadding='0' cellspacing='1'>\n";
        $mathq .= "<tr valign='center'><td>\n";

        $mathq .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
        $mathq .= "<tr><td align='center'>$q_array[0]</td></tr>\n";
        $mathq .= "<tr><td>\n";
        $mathq .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
        $mathq .= "</td></tr>\n";
        $mathq .= "<tr><td align='center'>$q_array[1]</td></tr></table>\n";
        $mathq .= "</td>\n";

        $mathq .= "<td>$q_array[2]</td>\n";

        $mathq .= "<td>$q_array[3]</td>\n";  //// LHS operation

        $mathq .= "<td><table border='0' cellpadding='0' cellspacing='1'>\n";
        $mathq .= "<tr><td align='center'>$q_array[4]</td></tr>\n";
        $mathq .= "<tr><td>\n";
        $mathq .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
        $mathq .= "</td></tr>\n";
        $mathq .= "<tr><td align='center'>$q_array[5]</td></tr></table></td>\n";

        $mathq .= "<td>&nbsp;=&nbsp;</td>\n";

        $mathq .= "<td><table border='0' cellpadding='0' cellspacing='1'>\n";
        $mathq .= "<tr><td align='center'>$q_array[6]</td></tr>\n";
        $mathq .= "<tr><td>\n";
        $mathq .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
        $mathq .= "</td></tr>\n";
        $mathq .= "<tr><td align='center'>$q_array[7]</td></tr></table></td>\n";

        $mathq .= "<td>$q_array[8]</td>\n";

        $mathq .= "<td>$q_array[9]</td>\n";    //// RHS operation

        $mathq .= "<td><table border='0' cellpadding='0' cellspacing='1'>\n";
        $mathq .= "<tr><td align='center'>$q_array[10]</td></tr>\n";
        $mathq .= "<tr><td>\n";
        $mathq .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
        $mathq .= "</td></tr>\n";
        $mathq .= "<tr><td align='center'>$q_array[11]</td></tr></table></td>\n";

        $mathq .= "</tr></table>\n";
        $final_form = array($mathq,'1');
        return $final_form;
*/
}

function parse_input($my_string,$type,$max_pow = 4)
{
    $debug = FALSE;
    $my_string = trim($my_string);
    $my_string = strtolower($my_string);
    $my_string = trim_parenth($my_string);
    $length = strlen($my_string);
    $char_array = array();
    for ($j = 0; $j < $length; $j++)
    {
        $char_array[] = substr($my_string,$j,1);
    }
    $temp_string = "";
    for ($j = 0; $j < $length; $j++)
    {
        if ($char_array[$j] != ' ')
        $temp_string = $temp_string.$char_array[$j];
    }
    $my_string = $temp_string;
    if ($type == 1)
    {
    //// monomial with x and y
        $x_pow = "0";
        $y_pow = "0";
        $coeff = "1";
        $num_x = 0;
        $num_y = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'x')
                $num_x++;
            if ($char == 'y')
                $num_y++;
        }
        if ($num_x > 1 || $num_y > 1)
            return "Not Simple";
        $den=1;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '/')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $den=-$den;
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'x' && $temp_string != "" && $temp_string != "(")
            {
                 $sub_array[] = $temp_string;
                 $temp_string = "";
            }
            if ($char == 'y' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'x')
            {
                $sub_array[$i] = str_replace('x','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $x_pow = $sub_array[$i];
                else
                    $x_pow = 1;
            }
            else if ($temp_array[0] == 'y')
            {
                $sub_array[$i] = str_replace('y','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $y_pow = $sub_array[$i];
                else
                    $y_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($x_pow != "0")
        {
            if ($x_pow == "1")
                $answer = $answer."x";
            else
                $answer = $answer."x^(".$x_pow.")";
        }
        if ($y_pow != "0")
        {
            if ($y_pow == "1")
                $answer = $answer."y";
            else
                $answer = $answer."y^(".$y_pow.")";
        }
        if ($coeff == "1" && $x_pow == "0" && $y_pow == "0")
            $answer = "1";
        return $answer;
    }
    else if ($type == 2)
    {
    //// monomial with a,b and c
        //// for Type 7.1
        $a_pow = "0";
        $b_pow = "0";
        $c_pow = "0";
        $coeff = "1";
        $num_a = 0;
        $num_b = 0;
        $num_c = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'a')
                $num_a++;
            if ($char == 'b')
                $num_b++;
            if ($char == 'c')
                $num_c++;
        }
        if ($num_a > 1 || $num_b > 1 || $num_c > 1)
            return FALSE;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'a' && $temp_string != "" && $temp_string != "(" )
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            if ($char == 'b' && $temp_string != "" && $temp_string != "(" )
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            if ($char == 'c' && $temp_string != "" && $temp_string != "(" )
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'a')
            {
                $sub_array[$i] = str_replace('a','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $a_pow = $sub_array[$i];
                else
                    $a_pow = 1;
            }
            else if ($temp_array[0] == 'b')
            {
                $sub_array[$i] = str_replace('b','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $b_pow = $sub_array[$i];
                else
                    $b_pow = 1;
            }
            else if ($temp_array[0] == 'c')
            {
                $sub_array[$i] = str_replace('c','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $c_pow = $sub_array[$i];
                else
                    $c_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $i = 0;
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($a_pow != "0")
        {
            if ($a_pow == "1")
                $answer = $answer."a";
            else
                $answer = $answer."a^(".$a_pow.")";
        }
        if ($b_pow != "0")
        {
            if ($b_pow == "1")
                $answer = $answer."b";
            else
                $answer = $answer."b^(".$b_pow.")";
        }
        if ($c_pow != "0")
        {
            if ($c_pow == "1")
                $answer = $answer."c";
            else
                $answer = $answer."c^(".$c_pow.")";
        }
        return $answer;
    }
    else if ($type == 3)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in x
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

        $max_pow++;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $pow_array = array();
        for ($i =0; $i < $max_pow; $i++)
            $pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
             {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
             }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_a_var = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'x')
                    $has_a_var = TRUE;
            }
            if ($has_a_var == FALSE)
            {
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $icoeff_array[$j] = $temp_string;
                $pow_array[$j] = 0;
            }
            else //// the substring includes a variable
            {
                if ($tchar_array[0] == 'x')
                {
                    $has_open_par = FALSE;
                    $has_closed_par = FALSE;
                    $has_multi = FALSE;
                    $has_power = FALSE;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '*')
                            $has_multi = TRUE;
                        if ($tchar_array[$i] == '(')
                            $has_open_par = TRUE;
                        if ($tchar_array[$i] == ')')
                            $has_closed_par = TRUE;
                        if ($tchar_array[$i] == '^')
                            $has_power = TRUE;
                    }
                    if ($has_multi == TRUE)
                    {
                        $temp_array = explode('*',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            $temp_array[$i] = str_replace('x','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                    {
                        $temp_string = str_replace('x','',$temp_string);
                        if ($has_power == FALSE)
                        {
                            $temp_string = str_replace('(','',$temp_string);
                            $temp_string = str_replace(')','',$temp_string);
                            $pow_array[$j] = 1;
                            $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $temp_array = explode(')',$temp_string);
                            if ($temp_array[1] != "")
                            {
                                for ($i = 0; $i < 2; $i++)
                                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                $pow_array[$j] = $temp_array[0];
                                $icoeff_array[$j] = $temp_array[1];
                            }
                            else
                            {
                                $temp_array = explode('(',$temp_array[0]);
                                if ($temp_array[0] == "")
                                {
                                    $pow_array[$j] = $temp_array[1];
                                    $icoeff_array[$j] = 1;
                                }
                                else
                                {
                                    $pow_array[$j] = $temp_array[0];
                                    $icoeff_array[$j] = $temp_array[1];
                                }
                            }
                        }
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        return FALSE;
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        return FALSE;
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('x','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = 1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = -1;
                            else
                                $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('x','',$temp_string);
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = 1;
                        }

                    }
                }
                else if ($tchar_array[0] == '-')
                {
                    if ($tchar_array[1] != 'x')
                    {
                        $temp_array = explode('x',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            if ($temp_array[$i] == NULL)
                                break;
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                            $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                        }
                        $icoeff_array[$j] = $temp_array[0];
                        if ($temp_array[1] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $tchar_array[0] = '';
                        $temp_string = "";
                        for ($i = 1; $i < $temp_length; $i++)
                            $temp_string = $temp_string.$tchar_array[$i];
                        $has_open_par = FALSE;
                        $has_closed_par = FALSE;
                        $has_multi = FALSE;
                        $has_power = FALSE;
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array[$i] == '*')
                                $has_multi = TRUE;
                            if ($tchar_array[$i] == '(')
                                $has_open_par = TRUE;
                            if ($tchar_array[$i] == ')')
                                $has_closed_par = TRUE;
                            if ($tchar_array[$i] == '^')
                                $has_power = TRUE;
                        }
                        if ($has_multi == TRUE)
                        {
                            $temp_array = explode('*',$temp_string);
                            for ($i = 0; $i < 2; $i++)
                            {
                                $temp_array[$i] = str_replace('x','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                 $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                                $temp_string = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                        {
                            $temp_string = str_replace('x','',$temp_string);
                            if ($has_power == FALSE)
                            {
                                $temp_string = str_replace('(','',$temp_string);
                                $temp_string = str_replace(')','',$temp_string);
                                $pow_array[$j] = 1;
                                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                    $temp_string2 = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $temp_array = explode(')',$temp_string);
                                if ($temp_array[1] != "")
                                {
                                    for ($i = 0; $i < 2; $i++)
                                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                    $pow_array[$j] = $temp_array[0];
                                    $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                                }
                                else
                                {
                                    $temp_array = explode('(',$temp_array[0]);
                                    if ($temp_array[0] == "")
                                    {
                                        $pow_array[$j] = $temp_array[1];
                                        $icoeff_array[$j] = -1;
                                    }
                                    else
                                    {
                                        $pow_array[$j] = $temp_array[0];
                                        $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                            for ($i = 1; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                            $temp_string = "-";
                                            for ($i = 0; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                                    }
                                }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        {
                            ////echo $j;
                            ////echo "open but not closed";
                            return FALSE;
                        }
                        else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        {
                            ////echo $j;
                            ////echo "closed but not open";
                            return FALSE;
                        }
                        else
                        {
                            //echo "got here";
                            //echo "<br />$temp_string<br />";
                            if ($has_power == FALSE)
                            {
                                $pow_array[$j] = 1;
                                $pow_array[$j] = 1;
                                $temp_string = str_replace('x','',$temp_string);
                                if ($temp_string == "")
                                    $icoeff_array[$j] = -1;
                                else if ($temp_string == "-")
                                    $icoeff_array[$j] = 1;
                                else
                                    $icoeff_array[$j] = "-".$temp_string;
                            }
                            else
                            {
                                $temp_string = str_replace('x','',$temp_string);
                                $temp_string = str_replace('^','',$temp_string);
                                $pow_array[$j] = $temp_string;
                                $icoeff_array[$j] = -1;
                            }
                        }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(')
                            $num_closed++;
                        if ($tchar_array[$i] == ')')
                            $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                        ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array[$i];
                    $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                    //// puts it in nice form
                    $temp_string = parse_input($temp_string,3);
                    $temp_array = explode('x',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
                else
                {
                    $temp_array = explode('x',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
        {
            $temp = (int)$pow_array[$j];
            if ($temp < 0)
            {
                ////echo "negative power";
                return FALSE;
            }
            if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
            {
                ////echo "two powers the same";
                return FALSE;
            }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
            if ($j == 0)
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j],0);
            }
            else
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."x ".$answer;
                else
                    $answer = $ocoeff_array[$j]."x^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
            $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        return $answer;
    }
    else if ($type == 4)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in y
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

        $max_pow++;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $pow_array = array();
        for ($i =0; $i < $max_pow; $i++)
            $pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                 $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_a_var = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'y')
                    $has_a_var = TRUE;
            }
            if ($has_a_var == FALSE)
            {
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $icoeff_array[$j] = $temp_string;
                $pow_array[$j] = 0;
            }
            else //// the substring includes a variable
            {
                if ($tchar_array[0] == 'y')
                {
                    $has_open_par = FALSE;
                    $has_closed_par = FALSE;
                    $has_multi = FALSE;
                    $has_power = FALSE;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '*')
                            $has_multi = TRUE;
                        if ($tchar_array[$i] == '(')
                            $has_open_par = TRUE;
                        if ($tchar_array[$i] == ')')
                            $has_closed_par = TRUE;
                        if ($tchar_array[$i] == '^')
                            $has_power = TRUE;
                    }
                    if ($has_multi == TRUE)
                    {
                        $temp_array = explode('*',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            $temp_array[$i] = str_replace('y','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                    {
                        $temp_string = str_replace('y','',$temp_string);
                        if ($has_power == FALSE)
                        {
                            $temp_string = str_replace('(','',$temp_string);
                            $temp_string = str_replace(')','',$temp_string);
                            $pow_array[$j] = 1;
                            $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $temp_array = explode(')',$temp_string);
                            if ($temp_array[1] != "")
                            {
                                for ($i = 0; $i < 2; $i++)
                                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                $pow_array[$j] = $temp_array[0];
                                $icoeff_array[$j] = $temp_array[1];
                            }
                            else
                            {
                                $temp_array = explode('(',$temp_array[0]);
                                if ($temp_array[0] == "")
                                {
                                    $pow_array[$j] = $temp_array[1];
                                    $icoeff_array[$j] = 1;
                                }
                                else
                                {
                                    $pow_array[$j] = $temp_array[0];
                                    $icoeff_array[$j] = $temp_array[1];
                                }
                            }
                        }
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        return FALSE;
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        return FALSE;
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('y','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = 1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = -1;
                            else
                                $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('y','',$temp_string);
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = 1;
                        }
                    }
                }
                else if ($tchar_array[0] == '-')
                {
                    if ($tchar_array[1] != 'y')
                    {
                        $temp_array = explode('y',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            if ($temp_array[$i] == NULL)
                                break;
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                            $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                        }
                        $icoeff_array[$j] = $temp_array[0];
                        if ($temp_array[1] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $tchar_array[0] = '';
                        $temp_string = "";
                        for ($i = 1; $i < $temp_length; $i++)
                            $temp_string = $temp_string.$tchar_array[$i];
                        $has_open_par = FALSE;
                        $has_closed_par = FALSE;
                        $has_multi = FALSE;
                        $has_power = FALSE;
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array[$i] == '*')
                                $has_multi = TRUE;
                            if ($tchar_array[$i] == '(')
                                $has_open_par = TRUE;
                            if ($tchar_array[$i] == ')')
                                $has_closed_par = TRUE;
                            if ($tchar_array[$i] == '^')
                                $has_power = TRUE;
                        }
                        if ($has_multi == TRUE)
                        {
                            $temp_array = explode('*',$temp_string);
                            for ($i = 0; $i < 2; $i++)
                            {
                                $temp_array[$i] = str_replace('y','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                 $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                                $temp_string = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                        {
                            $temp_string = str_replace('y','',$temp_string);
                            if ($has_power == FALSE)
                            {
                                $temp_string = str_replace('(','',$temp_string);
                                $temp_string = str_replace(')','',$temp_string);
                                $pow_array[$j] = 1;
                                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                    $temp_string2 = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $temp_array = explode(')',$temp_string);
                                if ($temp_array[1] != "")
                                {
                                    for ($i = 0; $i < 2; $i++)
                                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                    $pow_array[$j] = $temp_array[0];
                                    $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                                }
                                else
                                {
                                    $temp_array = explode('(',$temp_array[0]);
                                    if ($temp_array[0] == "")
                                    {
                                        $pow_array[$j] = $temp_array[1];
                                        $icoeff_array[$j] = -1;
                                    }
                                    else
                                    {
                                        $pow_array[$j] = $temp_array[0];
                                        $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                            for ($i = 1; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                            $temp_string = "-";
                                            for ($i = 0; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                                    }
                                }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        {
                            ////echo $j;
                            ////echo "open but not closed";
                            return FALSE;
                        }
                        else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        {
                            ////echo $j;
                            ////echo "closed but not open";
                            return FALSE;
                        }
                        else
                        {
                            if ($has_power == FALSE)
                            {
                                $pow_array[$j] = 1;
                                $temp_string = str_replace('y','',$temp_string);
                                if ($temp_string == "")
                                    $icoeff_array[$j] = -1;
                                else if ($temp_string == "-")
                                    $icoeff_array[$j] = 1;
                                else
                                    $icoeff_array[$j] = "-".$temp_string;
                            }
                            else
                            {
                                $temp_string = str_replace('y','',$temp_string);
                                $temp_string = str_replace('^','',$temp_string);
                                $pow_array[$j] = $temp_string;
                                $icoeff_array[$j] = -1;
                            }
                        }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(')
                            $num_closed++;
                        if ($tchar_array[$i] == ')')
                            $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                        ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array[$i];
                    $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                    //// puts it in nice form
                    $temp_string = parse_input($temp_string,4);
                    $temp_array = explode('y',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
                else
                {
                    $temp_array = explode('y',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
        {
            $temp = (int)$pow_array[$j];
            if ($temp < 0)
            {
                ////echo "negative power";
                return FALSE;
            }
            if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
            {
                ////echo "two powers the same";
                return FALSE;
            }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
            if ($j == 0)
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j],0);
            }
            else
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."y ".$answer;
                else
                    $answer = $ocoeff_array[$j]."y^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
            $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        return $answer;
    }
    else if ($type == 5)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in a
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

        $max_pow++;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $pow_array = array();
        for ($i =0; $i < $max_pow; $i++)
            $pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_a_var = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'a')
                    $has_a_var = TRUE;
            }
            if ($has_a_var == FALSE)
            {
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $icoeff_array[$j] = $temp_string;
                $pow_array[$j] = 0;
            }
            else //// the substring includes a variable
            {
                if ($tchar_array[0] == 'a')
                {
                    $has_open_par = FALSE;
                    $has_closed_par = FALSE;
                    $has_multi = FALSE;
                    $has_power = FALSE;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '*')
                            $has_multi = TRUE;
                        if ($tchar_array[$i] == '(')
                            $has_open_par = TRUE;
                        if ($tchar_array[$i] == ')')
                            $has_closed_par = TRUE;
                        if ($tchar_array[$i] == '^')
                            $has_power = TRUE;
                    }
                    if ($has_multi == TRUE)
                    {
                        $temp_array = explode('*',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            $temp_array[$i] = str_replace('a','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                    {
                        $temp_string = str_replace('a','',$temp_string);
                        if ($has_power == FALSE)
                        {
                            $temp_string = str_replace('(','',$temp_string);
                            $temp_string = str_replace(')','',$temp_string);
                            $pow_array[$j] = 1;
                            $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $temp_array = explode(')',$temp_string);
                            if ($temp_array[1] != "")
                            {
                                for ($i = 0; $i < 2; $i++)
                                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                $pow_array[$j] = $temp_array[0];
                                $icoeff_array[$j] = $temp_array[1];
                            }
                            else
                            {
                                $temp_array = explode('(',$temp_array[0]);
                                if ($temp_array[0] == "")
                                {
                                    $pow_array[$j] = $temp_array[1];
                                    $icoeff_array[$j] = 1;
                                }
                                else
                                {
                                    $pow_array[$j] = $temp_array[0];
                                    $icoeff_array[$j] = $temp_array[1];
                                }
                            }
                        }
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        return FALSE;
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        return FALSE;
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('a','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = 1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = -1;
                            else
                                $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('a','',$temp_string);
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = 1;
                        }
                    }
                }
                else if ($tchar_array[0] == '-')
                {
                    if ($tchar_array[1] != 'a')
                    {
                        $temp_array = explode('a',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            if ($temp_array[$i] == NULL)
                                break;
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                            $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                        }
                        $icoeff_array[$j] = $temp_array[0];
                        if ($temp_array[1] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $tchar_array[0] = '';
                        $temp_string = "";
                        for ($i = 1; $i < $temp_length; $i++)
                            $temp_string = $temp_string.$tchar_array[$i];
                        $has_open_par = FALSE;
                        $has_closed_par = FALSE;
                        $has_multi = FALSE;
                        $has_power = FALSE;
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array[$i] == '*')
                                $has_multi = TRUE;
                            if ($tchar_array[$i] == '(')
                                $has_open_par = TRUE;
                            if ($tchar_array[$i] == ')')
                                $has_closed_par = TRUE;
                            if ($tchar_array[$i] == '^')
                                $has_power = TRUE;
                        }
                        if ($has_multi == TRUE)
                        {
                            $temp_array = explode('*',$temp_string);
                            for ($i = 0; $i < 2; $i++)
                            {
                                $temp_array[$i] = str_replace('a','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                 $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                                $temp_string = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                        {
                            $temp_string = str_replace('a','',$temp_string);
                            if ($has_power == FALSE)
                            {
                                $temp_string = str_replace('(','',$temp_string);
                                $temp_string = str_replace(')','',$temp_string);
                                $pow_array[$j] = 1;
                                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                    $temp_string2 = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $temp_array = explode(')',$temp_string);
                                if ($temp_array[1] != "")
                                {
                                    for ($i = 0; $i < 2; $i++)
                                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                    $pow_array[$j] = $temp_array[0];
                                    $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                                }
                                else
                                {
                                    $temp_array = explode('(',$temp_array[0]);
                                    if ($temp_array[0] == "")
                                    {
                                        $pow_array[$j] = $temp_array[1];
                                        $icoeff_array[$j] = -1;
                                    }
                                    else
                                    {
                                        $pow_array[$j] = $temp_array[0];
                                        $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                            for ($i = 1; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                            $temp_string = "-";
                                            for ($i = 0; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                                    }
                                }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        {
                            ////echo $j;
                            ////echo "open but not closed";
                            return FALSE;
                        }
                        else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        {
                            ////echo $j;
                            ////echo "closed but not open";
                            return FALSE;
                        }
                        else
                        {
                            if ($has_power == FALSE)
                            {
                                $pow_array[$j] = 1;
                                $temp_string = str_replace('a','',$temp_string);
                                if ($temp_string == "")
                                    $icoeff_array[$j] = -1;
                                else if ($temp_string == "-")
                                    $icoeff_array[$j] = 1;
                                else
                                    $icoeff_array[$j] = "-".$temp_string;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $pow_array[$j] = $temp_string;
                                $icoeff_array[$j] = -1;
                            }
                        }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(')
                            $num_closed++;
                        if ($tchar_array[$i] == ')')
                            $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                        ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array[$i];
                    $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                    //// puts it in nice form
                    $temp_string = parse_input($temp_string,5);
                    $temp_array = explode('a',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
                else
                {
                    $temp_array = explode('a',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
        {
            $temp = (int)$pow_array[$j];
            if ($temp < 0)
            {
                ////echo "negative power";
                return FALSE;
            }
            if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
            {
                ////echo "two powers the same";
                return FALSE;
            }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
            if ($j == 0)
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j],0);
            }
            else
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."a ".$answer;
                else
                    $answer = $ocoeff_array[$j]."a^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
            $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        return $answer;
    }
    else if ($type == 6)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in n
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

        $max_pow++;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $pow_array = array();
        for ($i =0; $i < $max_pow; $i++)
            $pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_a_var = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'n')
                    $has_a_var = TRUE;
            }
            if ($has_a_var == FALSE)
            {
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $icoeff_array[$j] = $temp_string;
                $pow_array[$j] = 0;
            }
            else //// the substring includes a variable
            {
                if ($tchar_array[0] == 'n')
                {
                    $has_open_par = FALSE;
                    $has_closed_par = FALSE;
                    $has_multi = FALSE;
                    $has_power = FALSE;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '*')
                            $has_multi = TRUE;
                        if ($tchar_array[$i] == '(')
                            $has_open_par = TRUE;
                        if ($tchar_array[$i] == ')')
                            $has_closed_par = TRUE;
                        if ($tchar_array[$i] == '^')
                            $has_power = TRUE;
                    }
                    if ($has_multi == TRUE)
                    {
                        $temp_array = explode('*',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            $temp_array[$i] = str_replace('n','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                    {
                        $temp_string = str_replace('n','',$temp_string);
                        if ($has_power == FALSE)
                        {
                            $temp_string = str_replace('(','',$temp_string);
                            $temp_string = str_replace(')','',$temp_string);
                            $pow_array[$j] = 1;
                            $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $temp_array = explode(')',$temp_string);
                            if ($temp_array[1] != "")
                            {
                                for ($i = 0; $i < 2; $i++)
                                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                $pow_array[$j] = $temp_array[0];
                                $icoeff_array[$j] = $temp_array[1];
                            }
                            else
                            {
                                $temp_array = explode('(',$temp_array[0]);
                                if ($temp_array[0] == "")
                                {
                                    $pow_array[$j] = $temp_array[1];
                                    $icoeff_array[$j] = 1;
                                }
                                else
                                {
                                    $pow_array[$j] = $temp_array[0];
                                    $icoeff_array[$j] = $temp_array[1];
                                }
                            }
                        }
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        return FALSE;
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        return FALSE;
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('n','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = 1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = -1;
                            else
                                $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('n','',$temp_string);
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = 1;
                        }
                    }
                }
                else if ($tchar_array[0] == '-')
                {
                    if ($tchar_array[1] != 'n')
                    {
                        $temp_array = explode('n',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            if ($temp_array[$i] == NULL)
                                break;
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                            $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                        }
                        $icoeff_array[$j] = $temp_array[0];
                        if ($temp_array[1] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $tchar_array[0] = '';
                        $temp_string = "";
                        for ($i = 1; $i < $temp_length; $i++)
                            $temp_string = $temp_string.$tchar_array[$i];
                        $has_open_par = FALSE;
                        $has_closed_par = FALSE;
                        $has_multi = FALSE;
                        $has_power = FALSE;
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array[$i] == '*')
                                $has_multi = TRUE;
                            if ($tchar_array[$i] == '(')
                                $has_open_par = TRUE;
                            if ($tchar_array[$i] == ')')
                                $has_closed_par = TRUE;
                            if ($tchar_array[$i] == '^')
                                $has_power = TRUE;
                        }
                        if ($has_multi == TRUE)
                        {
                            $temp_array = explode('*',$temp_string);
                            for ($i = 0; $i < 2; $i++)
                            {
                                $temp_array[$i] = str_replace('n','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                 $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                                $temp_string = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                        {
                            $temp_string = str_replace('n','',$temp_string);
                            if ($has_power == FALSE)
                            {
                                $temp_string = str_replace('(','',$temp_string);
                                $temp_string = str_replace(')','',$temp_string);
                                $pow_array[$j] = 1;
                                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                    $temp_string2 = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $temp_array = explode(')',$temp_string);
                                if ($temp_array[1] != "")
                                {
                                    for ($i = 0; $i < 2; $i++)
                                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                    $pow_array[$j] = $temp_array[0];                                    $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                                }
                                else
                                {
                                    $temp_array = explode('(',$temp_array[0]);
                                    if ($temp_array[0] == "")
                                    {
                                        $pow_array[$j] = $temp_array[1];
                                        $icoeff_array[$j] = -1;
                                    }
                                    else
                                    {
                                        $pow_array[$j] = $temp_array[0];
                                        $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                            for ($i = 1; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                            $temp_string = "-";
                                            for ($i = 0; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                                    }
                                }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        {
                            ////echo $j;
                            ////echo "open but not closed";
                            return FALSE;
                        }
                        else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        {
                            ////echo $j;
                            ////echo "closed but not open";
                            return FALSE;
                        }
                        else
                        {
                            if ($has_power == FALSE)
                            {
                                $pow_array[$j] = 1;
                                $temp_string = str_replace('n','',$temp_string);
                                if ($temp_string == "")
                                    $icoeff_array[$j] = -1;
                                else if ($temp_string == "-")
                                    $icoeff_array[$j] = 1;
                                else
                                    $icoeff_array[$j] = "-".$temp_string;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $pow_array[$j] = $temp_string;
                                $icoeff_array[$j] = -1;
                            }
                        }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(')
                            $num_closed++;
                        if ($tchar_array[$i] == ')')
                            $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                        ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array[$i];
                    $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                    //// puts it in nice form
                    $temp_string = parse_input($temp_string,6);
                    $temp_array = explode('n',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
                else
                {
                    $temp_array = explode('n',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
        {
            $temp = (int)$pow_array[$j];
            if ($temp < 0)
            {
                ////echo "negative power";
                return FALSE;
            }
            if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
            {
                ////echo "two powers the same";
                return FALSE;
            }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
            if ($j == 0)
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j],0);
            }
            else
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."n ".$answer;
                else
                    $answer = $ocoeff_array[$j]."n^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
            $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        return $answer;
    }
    else if ($type == 7)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in x,y
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $max_pow = 36;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $x_pow_array = array();
        $y_pow_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $x_pow_array[] = 0;
        for ($i = 0; $i < $max_pow; $i++)
            $y_pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        ////echo "<br /> parser input/output <br />";
        for ($j = 0; $j < $num_sub; $j++)
        {
            ////echo "<br /> before the parse<br /> $sub_array[$j]<br />";
            $sub_array[$j] = parse_input($sub_array[$j],1);
            ////echo "<br /> after the parse<br /> $sub_array[$j]<br />";
        }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_an_x = FALSE;
            $has_a_y = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
            $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'x')
                $has_an_x = TRUE;
            }
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'y')
                $has_a_y = TRUE;
            }
            if ($has_an_x == FALSE && $has_a_y == FALSE)
            {
                ////  substring is the constant
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                $icoeff_array[$j] = $temp_string;
                $x_pow_array[$j] = 0;
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_x == TRUE && $has_a_y == FALSE)
            {
                $temp_array = explode('x',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $x_pow_array[$j] = 1;
                else
                    $x_pow_array[$j] = $temp_array[1];
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_x == FALSE && $has_a_y == TRUE)
            {
                $temp_array = explode('y',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $y_pow_array[$j] = 1;
                else
                    $y_pow_array[$j] = $temp_array[1];
                $x_pow_array[$j] = 0;
            }
            else // ($has_an_x == TRUE && $has_a_y == TRUE)
            {
                $temp_array = explode('x',$temp_string);
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                $temp_array = explode('y',$temp_array[1]);
                if ($temp_array[0] == NULL)
                    $x_pow_array[$j] = 1;
                else
                {
                    $temp_array[0] = str_replace('^','',$temp_array[0]);
                    $temp_array[0] = str_replace('(','',$temp_array[0]);
                    $temp_array[0] = str_replace(')','',$temp_array[0]);
                    $x_pow_array[$j] = $temp_array[0];
                }
                if ($temp_array[1] == NULL)
                    $y_pow_array[$j] = 1;
                else
                {
                    $temp_array[1] = str_replace('^','',$temp_array[1]);
                    $temp_array[1] = str_replace('(','',$temp_array[1]);
                    $temp_array[1] = str_replace(')','',$temp_array[1]);
                    $y_pow_array[$j] = $temp_array[1];
                }
            }
        }
        //// put coeff's in order i want
        for ($j = 0; $j < $num_sub; $j++)
        {
            $c = $icoeff_array[$j];
            $x = $x_pow_array[$j];
            $y = $y_pow_array[$j];
            if ($x == 5 && $y == 0)
                $ocoeff_array[0] = $c;
            else if ($x == 5 && $y == 1)
                $ocoeff_array[1] = $c;
            else if ($x == 5 && $y == 2)
                $ocoeff_array[2] = $c;
            else if ($x == 5 && $y == 3)
                $ocoeff_array[3] = $c;
            else if ($x == 5 && $y == 4)
                $ocoeff_array[4] = $c;
            else if ($x == 5 && $y == 5)
                $ocoeff_array[5] = $c;
            else if ($x == 4 && $y == 0)
                $ocoeff_array[6] = $c;
            else if ($x == 4 && $y == 1)
                $ocoeff_array[7] = $c;
            else if ($x == 4 && $y == 2)
                $ocoeff_array[8] = $c;
            else if ($x == 4 && $y == 3)
                $ocoeff_array[9] = $c;
            else if ($x == 4 && $y == 4)
                $ocoeff_array[10] = $c;
            else if ($x == 4 && $y == 5)
                $ocoeff_array[11] = $c;
            else if ($x == 3 && $y == 0)
                $ocoeff_array[12] = $c;
            else if ($x == 3 && $y == 1)
                $ocoeff_array[13] = $c;
            else if ($x == 3 && $y == 2)
                $ocoeff_array[14] = $c;
            else if ($x == 3 && $y == 3)
                $ocoeff_array[15] = $c;
            else if ($x == 3 && $y == 4)
                $ocoeff_array[16] = $c;
            else if ($x == 3 && $y == 5)
                $ocoeff_array[17] = $c;
            else if ($x == 2 && $y == 0)
                $ocoeff_array[18] = $c;
            else if ($x == 2 && $y == 1)
                $ocoeff_array[19] = $c;
            else if ($x == 2 && $y == 2)
                $ocoeff_array[20] = $c;
            else if ($x == 2 && $y == 3)
                $ocoeff_array[21] = $c;
            else if ($x == 2 && $y == 4)
                $ocoeff_array[22] = $c;
            else if ($x == 2 && $y == 5)
                $ocoeff_array[23] = $c;
            else if ($x == 1 && $y == 0)
                $ocoeff_array[24] = $c;
            else if ($x == 1 && $y == 1)
                $ocoeff_array[25] = $c;
            else if ($x == 1 && $y == 2)
                $ocoeff_array[26] = $c;
            else if ($x == 1 && $y == 3)
                $ocoeff_array[27] = $c;
            else if ($x == 1 && $y == 4)
                $ocoeff_array[28] = $c;
            else if ($x == 1 && $y == 5)
                $ocoeff_array[29] = $c;
            else if ($x == 0 && $y == 0)
                $ocoeff_array[30] = $c;
            else if ($x == 0 && $y == 1)
                $ocoeff_array[31] = $c;
            else if ($x == 0 && $y == 2)
                $ocoeff_array[32] = $c;
            else if ($x == 0 && $y == 3)
                $ocoeff_array[33] = $c;
            else if ($x == 0 && $y == 4)
                $ocoeff_array[34] = $c;
            else if ($x == 0 && $y == 5)
                $ocoeff_array[35] = $c;
            else
            {
            //// echo "x or y pow greater then 3 or negative";
                return FALSE;
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != 0)
            {
                $coeff = $ocoeff_array[$j];
                if ($j == 0 && $coeff == 1)
                    $coeff = "";
                else if ($j == 0 && $coeff == -1)
                    $coeff = "-";
                if ($j > 0 && $j != 30)
                    coeff_prep($coeff);
                if ($j == 30)
                    coeff_prep($coeff,0);
                if ($j == 0)
                    $answer = $coeff."x^(5) ";
                else if ($j == 1)
                    $answer = $answer.$coeff."x^(5)y ";
                else if ($j == 2)
                    $answer = $answer.$coeff."x^(5)y^(2) ";
                else if ($j == 3)
                    $answer = $answer.$coeff."x^(5)y^(3) ";
                else if ($j == 4)
                    $answer = $answer.$coeff."x^(5)y^(4) ";
                else if ($j == 5)
                    $answer = $answer.$coeff."x^(5)y^(5) ";
                else if ($j == 6)
                    $answer = $answer.$coeff."x^(4) ";
                else if ($j == 7)
                    $answer = $answer.$coeff."x^(4)y ";
                else if ($j == 8)
                    $answer = $answer.$coeff."x^(4)y^(2) ";
                else if ($j == 9)
                    $answer = $answer.$coeff."x^(4)y^(3) ";
                else if ($j == 10)
                    $answer = $answer.$coeff."x^(4)y^(4) ";
                else if ($j == 11)
                    $answer = $answer.$coeff."x^(4)y^(5) ";
                else if ($j == 12)
                    $answer = $answer.$coeff."x^(3) ";
                else if ($j == 13)
                    $answer = $answer.$coeff."x^(3)y ";
                else if ($j == 14)
                    $answer = $answer.$coeff."x^(3)y^(2) ";
                else if ($j == 15)
                    $answer = $answer.$coeff."x^(3)y^(3) ";
                else if ($j == 16)
                    $answer = $answer.$coeff."x^(3)y^(4) ";
                else if ($j == 17)
                    $answer = $answer.$coeff."x^(3)y^(5) ";
                else if ($j == 18)
                    $answer = $answer.$coeff."x^(2) ";
                else if ($j == 19)
                    $answer = $answer.$coeff."x^(2)y ";
                else if ($j == 20)
                    $answer = $answer.$coeff."x^(2)y^(2) ";
                else if ($j == 21)
                    $answer = $answer.$coeff."x^(2)y^(3) ";
                else if ($j == 22)
                    $answer = $answer.$coeff."x^(2)y^(4) ";
                else if ($j == 23)
                    $answer = $answer.$coeff."x^(2)y^(5) ";
                else if ($j == 24)
                    $answer = $answer.$coeff."x ";
                else if ($j == 25)
                    $answer = $answer.$coeff."xy ";
                else if ($j == 26)
                    $answer = $answer.$coeff."xy^(2) ";
                else if ($j == 27)
                    $answer = $answer.$coeff."xy^(3) ";
                else if ($j == 28)
                    $answer = $answer.$coeff."xy^(4) ";
                else if ($j == 29)
                    $answer = $answer.$coeff."xy^(5) ";
                else if ($j == 30)
                    $answer = $answer.$coeff;
                else if ($j == 31)
                    $answer = $answer.$coeff."y";
                else if ($j == 32)
                    $answer = $answer.$coeff."y^(2) ";
                else if ($j == 33)
                    $answer = $answer.$coeff."y^(3) ";
                else if ($j == 34)
                    $answer = $answer.$coeff."y^(4) ";
                else // ($j == 35)
                    $answer = $answer.$coeff."y^(5) ";
            }
        }
        $temp_length = strlen($answer);
        $temp_string = "";
        for ($j = 0; $j < $temp_length; $j++)
        {
            $char = substr($answer,$j,1);
            if ($j == 0)
            {
                if ($char == '+')
                {
                //// do nothing
                }
                else
                    $temp_string = $temp_string.$char;
            }
            else
                $temp_string = $temp_string.$char;
        }
        $answer = $temp_string;
        return $answer;
    }
    else if ($type == 81)
    {
        //// monomial with k and m
        $k_pow = "0";
        $m_pow = "0";
        $coeff = "1";
        $num_k = 0;
        $num_m = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'k')
                $num_x++;
            if ($char == 'm')
                $num_y++;
        }
        if ($num_k > 1 || $num_m > 1)
            return FALSE;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'k' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            if ($char == 'm' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'k')
            {
                $sub_array[$i] = str_replace('k','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $k_pow = $sub_array[$i];
                else
                    $k_pow = 1;
            }
            else if ($temp_array[0] == 'm')
            {
                $sub_array[$i] = str_replace('m','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $m_pow = $sub_array[$i];
                else
                    $m_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($k_pow != "0")
        {
            if ($k_pow == "1")
                $answer = $answer."k";
            else
                $answer = $answer."k^(".$k_pow.")";
        }
        if ($m_pow != "0")
        {
            if ($m_pow == "1")
                $answer = $answer."m";
            else
                $answer = $answer."m^(".$m_pow.")";
        }
        if ($coeff == "1" && $k_pow == "0" && $m_pow == "0")
            $answer = "1";
        return $answer;
    }
    else if ($type == 82 )
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in k,m
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        //echo "got here to 8b";
        $max_pow = 49;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $k_pow_array = array();
        $m_pow_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $k_pow_array[] = 0;
        for ($i = 0; $i < $max_pow; $i++)
            $m_pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        /*
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }*/
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            //echo "<br /> Before Parse monomial is <br />$sub_array[$j]";
            $sub_array[$j] = parse_input($sub_array[$j],81);
            //echo "<br /> After parse monomial is<br />$sub_array[$j]<br />";

        }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_an_k = FALSE;
            $has_an_m = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'k')
                    $has_an_k = TRUE;
            }
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'm')
                    $has_an_m = TRUE;
            }
            if ($has_an_k == FALSE && $has_an_m == FALSE)
            {
                ////  substring is the constant
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                $icoeff_array[$j] = $temp_string;
                $k_pow_array[$j] = 0;
                $m_pow_array[$j] = 0;
            }
            else if ($has_an_k == TRUE && $has_an_m == FALSE)
            {
                $temp_array = explode('k',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $k_pow_array[$j] = 1;
                else
                    $k_pow_array[$j] = $temp_array[1];
                $m_pow_array[$j] = 0;
            }
            else if ($has_an_k == FALSE && $has_an_m == TRUE)
            {
                $temp_array = explode('m',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $m_pow_array[$j] = 1;
                else
                    $m_pow_array[$j] = $temp_array[1];
                $k_pow_array[$j] = 0;
            }
            else // ($has_an_k == TRUE && $has_an_m == TRUE)
            {
                $temp_array = explode('k',$temp_string);
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                $temp_array = explode('m',$temp_array[1]);
                if ($temp_array[0] == NULL)
                    $k_pow_array[$j] = 1;
                else
                {
                    $temp_array[0] = str_replace('^','',$temp_array[0]);
                    $temp_array[0] = str_replace('(','',$temp_array[0]);
                    $temp_array[0] = str_replace(')','',$temp_array[0]);
                    $k_pow_array[$j] = $temp_array[0];
                }
                if ($temp_array[1] == NULL)
                    $m_pow_array[$j] = 1;
                else
                {
                    $temp_array[1] = str_replace('^','',$temp_array[1]);
                    $temp_array[1] = str_replace('(','',$temp_array[1]);
                    $temp_array[1] = str_replace(')','',$temp_array[1]);
                    $m_pow_array[$j] = $temp_array[1];
                }
            }
        }
        //// put coeff's in order i want
        for ($j = 0; $j < $num_sub; $j++)
        {
            $c = $icoeff_array[$j];
            $k = $k_pow_array[$j];
            $m = $m_pow_array[$j];
            ////echo "<br />$c,$k,$m<br />";
            if ($k == 6 && $m == 0)
                $ocoeff_array[0] = $icoeff_array[$j];
            else if ($k == 6 && $m == 1)
                $ocoeff_array[1] = $icoeff_array[$j];
            else if ($k == 6 && $m == 2)
                $ocoeff_array[2] = $icoeff_array[$j];
            else if ($k == 6 && $m == 3)
                $ocoeff_array[3] = $icoeff_array[$j];
            else if ($k == 6 && $m == 4)
                $ocoeff_array[4] = $icoeff_array[$j];
            else if ($k == 6 && $m == 5)
                $ocoeff_array[5] = $icoeff_array[$j];
            else if ($k == 6 && $m == 6)
                $ocoeff_array[6] = $icoeff_array[$j];
            else if ($k == 5 && $m == 0)
                $ocoeff_array[7] = $icoeff_array[$j];
            else if ($k == 5 && $m == 1)
                $ocoeff_array[8] = $icoeff_array[$j];
            else if ($k == 5 && $m == 2)
                $ocoeff_array[9] = $icoeff_array[$j];
            else if ($k == 5 && $m == 3)
                $ocoeff_array[10] = $icoeff_array[$j];
            else if ($k == 5 && $m == 4)
                $ocoeff_array[11] = $icoeff_array[$j];
            else if ($k == 5 && $m == 5)
                $ocoeff_array[12] = $icoeff_array[$j];
            else if ($k == 5 && $m == 6)
                $ocoeff_array[13] = $icoeff_array[$j];
            else if ($k == 4 && $m == 0)
                $ocoeff_array[14] = $icoeff_array[$j];
            else if ($k == 4 && $m == 1)
                $ocoeff_array[15] = $icoeff_array[$j];
            else if ($k == 4 && $m == 2)
                $ocoeff_array[16] = $icoeff_array[$j];
            else if ($k == 4 && $m == 3)
                $ocoeff_array[17] = $icoeff_array[$j];
            else if ($k == 4 && $m == 4)
                $ocoeff_array[18] = $icoeff_array[$j];
            else if ($k == 4 && $m == 5)
                $ocoeff_array[19] = $icoeff_array[$j];
            else if ($k == 4 && $m == 6)
                $ocoeff_array[20] = $icoeff_array[$j];
            else if ($k == 3 && $m == 0)
                $ocoeff_array[21] = $icoeff_array[$j];
            else if ($k == 3 && $m == 1)
                $ocoeff_array[22] = $icoeff_array[$j];
            else if ($k == 3 && $m == 2)
                $ocoeff_array[23] = $icoeff_array[$j];
            else if ($k == 3 && $m == 3)
                $ocoeff_array[24] = $icoeff_array[$j];
            else if ($k == 3 && $m == 4)
                $ocoeff_array[25] = $icoeff_array[$j];
            else if ($k == 3 && $m == 5)
                $ocoeff_array[26] = $icoeff_array[$j];
            else if ($k == 3 && $m == 6)
                $ocoeff_array[27] = $icoeff_array[$j];
            else if ($k == 2 && $m == 0)
                $ocoeff_array[28] = $icoeff_array[$j];
            else if ($k == 2 && $m == 1)
                $ocoeff_array[29] = $icoeff_array[$j];
            else if ($k == 2 && $m == 2)
                $ocoeff_array[30] = $icoeff_array[$j];
            else if ($k == 2 && $m == 3)
                $ocoeff_array[31] = $icoeff_array[$j];
            else if ($k == 2 && $m == 4)
                $ocoeff_array[32] = $icoeff_array[$j];
            else if ($k == 2 && $m == 5)
                $ocoeff_array[33] = $icoeff_array[$j];
            else if ($k == 2 && $m == 6)
                $ocoeff_array[34] = $icoeff_array[$j];
            else if ($k == 1 && $m == 0)
                $ocoeff_array[35] = $icoeff_array[$j];
            else if ($k == 1 && $m == 1)
                $ocoeff_array[36] = $icoeff_array[$j];
            else if ($k == 1 && $m == 2)
                $ocoeff_array[37] = $icoeff_array[$j];
            else if ($k == 1 && $m == 3)
                $ocoeff_array[38] = $icoeff_array[$j];
            else if ($k == 1 && $m == 4)
                $ocoeff_array[39] = $icoeff_array[$j];
            else if ($k == 1 && $m == 5)
                $ocoeff_array[40] = $icoeff_array[$j];
            else if ($k == 1 && $m == 6)
                $ocoeff_array[41] = $icoeff_array[$j];
            else if ($k == 0 && $m == 0)
                $ocoeff_array[42] = $icoeff_array[$j];
            else if ($k == 0 && $m == 1)
                $ocoeff_array[43] = $icoeff_array[$j];
            else if ($k == 0 && $m == 2)
                $ocoeff_array[44] = $icoeff_array[$j];
            else if ($k == 0 && $m == 3)
                $ocoeff_array[45] = $icoeff_array[$j];
            else if ($k == 0 && $m == 4)
                $ocoeff_array[46] = $icoeff_array[$j];
            else if ($k == 0 && $m == 5)
                $ocoeff_array[47] = $icoeff_array[$j];
            else if ($k == 0 && $m == 6)
                $ocoeff_array[48] = $icoeff_array[$j];
            else
            {
                //// echo "k or m pow greater then 6 or negative";
                return FALSE;
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != 0)
            {
                $coeff = $ocoeff_array[$j];
                if ($j == 0)
                {
                    if ($coeff == "-1")
                        $coeff = "- ";
                    else if ($coeff == "1")
                        $coeff = "";
                    else
                    {
                        //// do nothing
                    }
                }
                else if ($j > 0 && $j != 42)
                    coeff_prep($coeff);
                else if ($j == 42)
                    coeff_prep($coeff,0);
                else
                {
                    //// do nothing
                }
                if ($j == 0)
                    $answer = $coeff."k^(6) ";
                else if ($j == 1)
                    $answer = $answer.$coeff."k^(6)m ";
                else if ($j == 2)
                    $answer = $answer.$coeff."k^(6)m^(2) ";
                else if ($j == 3)
                    $answer = $answer.$coeff."k^(6)m^(3) ";
                else if ($j == 4)
                    $answer = $answer.$coeff."k^(6)m^(4) ";
                else if ($j == 5)
                    $answer = $answer.$coeff."k^(6)m^(5) ";
                else if ($j == 6)
                    $answer = $answer.$coeff."k^(6)m^(6) ";
                else if ($j == 7)
                    $answer = $answer.$coeff."k^(5) ";
                else if ($j == 8)
                    $answer = $answer.$coeff."k^(5)m ";
                else if ($j == 9)
                    $answer = $answer.$coeff."k^(5)m^(2) ";
                else if ($j == 10)
                    $answer = $answer.$coeff."k^(5)m^(3) ";
                else if ($j == 11)
                    $answer = $answer.$coeff."k^(5)m^(4) ";
                else if ($j == 12)
                    $answer = $answer.$coeff."k^(5)m^(5) ";
                else if ($j == 13)
                    $answer = $answer.$coeff."k^(5)m^(6) ";
                else if ($j == 14)
                    $answer = $answer.$coeff."k^(4) ";
                else if ($j == 15)
                    $answer = $answer.$coeff."k^(4)m ";
                else if ($j == 16)
                    $answer = $answer.$coeff."k^(4)m^(2) ";
                else if ($j == 17)
                    $answer = $answer.$coeff."k^(4)m^(3) ";
                else if ($j == 18)
                    $answer = $answer.$coeff."k^(4)m^(4) ";
                else if ($j == 19)
                    $answer = $answer.$coeff."k^(4)m^(5) ";
                else if ($j == 20)
                    $answer = $answer.$coeff."k^(4)m^(6) ";
                else if ($j == 21)
                    $answer = $answer.$coeff."k^(3) ";
                else if ($j == 22)
                    $answer = $answer.$coeff."k^(3)m ";
                else if ($j == 23)
                    $answer = $answer.$coeff."k^(3)m^(2) ";
                else if ($j == 23)
                    $answer = $answer.$coeff."k^(3)m^(3) ";
                else if ($j == 25)
                    $answer = $answer.$coeff."k^(3)m^(4) ";
                else if ($j == 26)
                    $answer = $answer.$coeff."k^(3)m^(5) ";
                else if ($j == 27)
                    $answer = $answer.$coeff."k^(3)m^(6) ";
                else if ($j == 28)
                    $answer = $answer.$coeff."k^(2) ";
                else if ($j == 29)
                    $answer = $answer.$coeff."k^(2)m ";
                else if ($j == 30)
                    $answer = $answer.$coeff."k^(2)m^(2) ";
                else if ($j == 31)
                    $answer = $answer.$coeff."k^(2)m^(3) ";
                else if ($j == 32)
                    $answer = $answer.$coeff."k^(2)m^(4) ";
                else if ($j == 33)
                    $answer = $answer.$coeff."k^(2)m^(5) ";
                else if ($j == 34)
                    $answer = $answer.$coeff."k^(2)m^(6) ";
                else if ($j == 35)
                    $answer = $answer.$coeff."k ";
                else if ($j == 36)
                    $answer = $answer.$coeff."km ";
                else if ($j == 37)
                    $answer = $answer.$coeff."km^(2) ";
                else if ($j == 38)
                    $answer = $answer.$coeff."km^(3) ";
                else if ($j == 39)
                    $answer = $answer.$coeff."km^(4) ";
                else if ($j == 40)
                    $answer = $answer.$coeff."km^(5) ";
                else if ($j == 41)
                    $answer = $answer.$coeff."km^(6) ";
                else if ($j == 42)
                    $answer = $answer.$coeff;
                else if ($j == 43)
                    $answer = $answer.$coeff."m ";
                else if ($j == 44)
                    $answer = $answer.$coeff."m^(2) ";
                else if ($j == 45)
                    $answer = $answer.$coeff."m^(3) ";
                else if ($j == 46)
                    $answer = $answer.$coeff."m^(4) ";
                else if ($j == 47)
                    $answer = $answer.$coeff."m^(5) ";
                else // ($j == 48)
                    $answer = $answer.$coeff."m^(6) ";
            }
        }
        return $answer;
    }
    else if ($type == 8)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in k,m,highest power = 3
        ////    type 22
        ////    returns false if there are two negatives pulled
        ////    of the factors and not simplified
        ////    **NOTE** unlike the parser for the x factors
        ////    this factor has to return two different possible
        ////    answers if there is a negative pulled out
        ////    since there is no really easy way to tell which
        ////    factor is reversed
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $neg_out_front = FALSE;
        $neg_position = -1;
        $num_sub = 0;
        $num_par = 0;
        $lacking = FALSE;
        $ignore = FALSE;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {

            //// needs re-written
            $char = $tchar_array[$j];
            ////echo "<br /> j is $j <br /> num_par before loop is $num_par  <br /> char is $char";
            ////echo "<br /> temp_string before loop is $temp_string";
            if ($num_par == 0 && $lacking == FALSE)
            {
                ////echo "<br /> set lacking to true";
                $lacking = TRUE;
            }
            if ($char == '(')
            {
                if ($j != 0 && $num_par == 0 && $tchar_array[$j-1] == '^')
                {
                    ////echo "<br /> set ignore to TRUE";
                    $ignore = TRUE;
                }
                if ($lacking == TRUE && $ignore == FALSE && $num_par == 0)
                {
                    $sub_array[] = $temp_string;
                    $temp_string = "";
                    $num_sub++;
                }
                if ($ignore == FALSE)
                {
                    ////echo "<br /> set lacking to FALSE";
                    $lacking = FALSE;
                }
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                if ($ignore == TRUE)
                {
                    ////echo "<br /> set ignore to FALSE";
                    $ignore = FALSE;
                }
                else if ($lacking == FALSE)
                {
                    $temp_string = $temp_string.$char;
                    $sub_array[] = $temp_string;
                    $char = "";
                    $temp_string = "";
                    $num_sub++;
                }
                else
                {
                    ////echo "<br />set lacking to TRUE";
                    $lacking = TRUE;
                }
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
            ////echo "<br /> temp_string after loop is $temp_string";
            ////echo "<br /> char after loop is $char";
            ////echo "<br /> num_par after loop is $num_par";
            ////echo "<br /> num_sub after loop is $num_sub";
        }
        if ($temp_string != "")
        {
            $sub_array[] = $temp_string;
            $temp_string = "";
            $num_sub++;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != NULL)
            {
                echo "<br /> parse 8 sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        ///////////////////////////////////////////////////////////
        ////   strips the sub_array strings of '*','(',')'
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = str_replace('*','',$sub_array[$i]);
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
        }
        ///////////////////////////////////////////////////////////
        ////    if there is a negative pulled out finds position
        ////    also if there are two negatives pulled out
        ////    returns FALSE
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($sub_array[$i] == "-" || $sub_array[$i] == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                else
                {
                    $neg_out_front = TRUE;
                    $neg_position = $i;
                }
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                ////echo "<br />sub_array[$i] = $sub_array[$i]<br />Now we parse<br />";
                $sub_array[$i] = parse_input($sub_array[$i],82);
                ////echo "<br />And the parse returns <br /> $sub_array[$i]<br />";
            }
        }
        ///////////////////////////////////////////////////////////
        ////    puts () around the factors
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                $temp_length = strlen($sub_array[$i]);
                $tchar_array = array();
                $tchar_array[] = '(';
                for ($j = 0; $j < $temp_length; $j++)
                {
                    if ($j == 0)
                    {
                        $char = substr($sub_array[$i],$j,1);
                        if ($char == '+')
                        {
                            //// do nothing
                        }
                        else
                            $tchar_array[] = $char;
                    }
                    else
                        $tchar_array[] = substr($sub_array[$i],$j,1);
                }
                $tchar_array[] = ')';
                $temp_string = "";
                for ($j = 0; $j < ($temp_length+2);$j++)
                    $temp_string = $temp_string.$tchar_array[$j];
                $sub_array[$i] = $temp_string;
            }
        }

        $answer = array();
        ///////////////////////////////////////////////////////////
        ////    returns two possible answers if negative out front
        ///////////////////////////////////////////////////////////
        if ($neg_out_front == TRUE)
        {
            $position1 = -1;
            $position2 = -1;
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                {
                    if ($position1 == -1)
                        $position1 = $i;
                    else
                        $position2 = $i;
                }
            }
            $temp_string1 = "";
            $temp_string2 = "";
            $tchar_array2 = array();
            $temp_string1 = $sub_array[$position1];
            $temp_string2 = $sub_array[$position2];
            $temp_length = strlen($temp_string1);
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string1,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
            $temp_string1 = $sub_array[$position1];
            $temp_length = strlen($sub_array[$position2]);
            $tchar_array2 = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string2,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
        }
        else // $neg_out_front == FALSE
        {
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                    $answer[] = $sub_array[$i];
            }
        }
        return $answer;
    }
    else if ($type == 9)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in x, highest power = 1
        ////    returns false if there are two negatives pulled
        ////    out of the factors and then not made positive
        ////    i.e. -(3-x)*(-)(4-x)
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        $reversed = array();
        $num_reversed = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $sub_array[$j] = str_replace('*','',$sub_array[$j]);
            $sub_array[$j] = str_replace('(','',$sub_array[$j]);
            $sub_array[$j] = str_replace(')','',$sub_array[$j]);
            $sub_array[$j] = trim($sub_array[$j]);
        }

        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                //echo "temp_string...$temp_string...<br />";
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_a_var = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            //echo "got here";
                            $char = $tchar_array2[$k];
                            //echo "$char...$i<br />";
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 'x')
                            {
                                $has_a_var = TRUE;
                                break;
                            }
                        }
                        if ($has_a_var == TRUE)
                        {
                            //echo "YES!!";
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,3);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array2[$i] == '-')
                            $tchar_array2[$i] = '+';
                        else if ($tchar_array2[$i] == '+')
                            $tchar_array2[$i] = '-';
                        else
                        {
                            //// do nothing
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,3);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            $fixed_reverse = FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,3);
                    if ($reversed[$j] == TRUE && $fixed_reverse == FALSE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,3);
                        $fixed_reversed = TRUE;
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }
    else if ($type == 10)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in x
        ////    returns false if there are two negatives pulled
        ////    out of the factors and then not made positive
        ////    i.e. -(3-x)*(-)(4-x)
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        $reversed = array();
        $num_reversed = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $sub_array[$j] = str_replace('*','',$sub_array[$j]);
            $sub_array[$j] = str_replace('(','',$sub_array[$j]);
            $sub_array[$j] = str_replace(')','',$sub_array[$j]);
            $sub_array[$j] = trim($sub_array[$j]);
        }

        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $has_pow = FALSE;
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                //echo "temp_string...$temp_string...<br />";
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '^')
                        $has_pow = TRUE;
                }
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_lvar = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            //echo "got here";
                            $char = $tchar_array2[$k];
                            $char_plus = $tchar_array[$k+1];
                            $char_plus2 = $tchar_array[$k+2];
                            //echo "$char...$i<br />";
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 'x')
                            {
                                if ($has_pow == TRUE)
                                {
                                    if ($char_plus == '^' || $char_plus2 == '^')
                                    {
                                        $has_lvar = TRUE;
                                        break;
                                    }
                                }
                                else // $has_pow == FALSE
                                {
                                    $has_lvar = TRUE;
                                    break;
                                }
                            }
                        }
                        if ($has_lvar == TRUE)
                        {
                            //echo "YES!!";
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,3);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array2[$i] == '-')
                            $tchar_array2[$i] = '+';
                        else if ($tchar_array2[$i] == '+')
                            $tchar_array2[$i] = '-';
                        else
                        {
                            //// do nothing
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,3);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            $fixed_reverse = FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,3);
                    if ($reversed[$j] == TRUE && $fixed_reverse == FALSE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,3);
                        $fixed_reversed = TRUE;
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////
////    Type 11.1
////
////    monomial in m,n
////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
    else if ($type == 111)
    {
        //// monomial in m,n
        $m_pow = "0";
        $n_pow = "0";
        $coeff = "1";
        $num_m = 0;
        $num_n = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'm')
                $num_m++;
            if ($char == 'n')
                $num_n++;
        }
        if ($num_m > 1 || $num_n > 1)
            return FALSE;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'm' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            if ($char == 'n' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'm')
            {
                $sub_array[$i] = str_replace('m','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $m_pow = $sub_array[$i];
                else
                    $m_pow = 1;
            }
            else if ($temp_array[0] == 'n')
            {
                $sub_array[$i] = str_replace('n','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $n_pow = $sub_array[$i];
                else
                    $n_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($m_pow != "0")
        {
            if ($m_pow == "1")
                $answer = $answer."m";
            else
                $answer = $answer."m^(".$m_pow.")";
        }
        if ($n_pow != "0")
        {
            if ($n_pow == "1")
                $answer = $answer."n";
            else
                $answer = $answer."n^(".$n_pow.")";
        }
        if ($coeff == "1" && $m_pow == "0" && $n_pow == "0")
            $answer = "1";
        return $answer;
    }
    else if ($type == 112)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in m,n
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $max_pow = 10;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $m_pow_array = array();
        $n_pow_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $m_pow_array[] = 0;
        for ($i = 0; $i < $max_pow; $i++)
            $n_pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
            $debug = FALSE;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
                        if ($i > 5)
                            break;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
                ////echo "<br /> Before monomial parse $sub_array[$j] ";
            $sub_array[$j] = parse_input($sub_array[$j],111);
                ////echo "<br /> After monomial parse $sub_array[$j] ";
            }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_an_m = FALSE;
            $has_an_n = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                    ////echo "<br /> character is $tchar_array[$i]";
                if ($tchar_array[$i] == 'm')
                    $has_an_m = TRUE;
            }
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'n')
                                $has_an_n = TRUE;
                    }
            if ($has_an_m == FALSE && $has_an_n == FALSE)
            {
                ////  substring is the constant
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                $icoeff_array[$j] = $temp_string;
                $m_pow_array[$j] = 0;
                $n_pow_array[$j] = 0;
            }
            else if ($has_an_m == TRUE && $has_an_n == FALSE)
            {
                            ////echo "<br />has an m is true has an n is false sub array is $sub_array[$j] ";
                $temp_array = explode('m',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $m_pow_array[$j] = 1;
                else
                    $m_pow_array[$j] = $temp_array[1];
                $n_pow_array[$j] = 0;
            }
            else if ($has_an_m == FALSE && $has_an_n == TRUE)
            {
                            ////echo "<br />has an m is false has an n is true sub array is $sub_array[$j] ";
                $temp_array = explode('n',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $n_pow_array[$j] = 1;
                else
                    $n_pow_array[$j] = $temp_array[1];
                $m_pow_array[$j] = 0;
            }
            else // ($has_an_m == TRUE && $has_an_n == TRUE)
            {
                            ////echo "<br />has an m is true has an n is true sub array is $sub_array[$j] ";
                $temp_array = explode('m',$temp_string);
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                $temp_array = explode('n',$temp_array[1]);
                if ($temp_array[0] == NULL)
                    $m_pow_array[$j] = 1;
                else
                {
                    $temp_array[0] = str_replace('^','',$temp_array[0]);
                    $temp_array[0] = str_replace('(','',$temp_array[0]);
                    $temp_array[0] = str_replace(')','',$temp_array[0]);
                    $m_pow_array[$j] = $temp_array[0];
                }
                if ($temp_array[1] == NULL)
                    $n_pow_array[$j] = 1;
                else
                {
                    $temp_array[1] = str_replace('^','',$temp_array[1]);
                    $temp_array[1] = str_replace('(','',$temp_array[1]);
                    $temp_array[1] = str_replace(')','',$temp_array[1]);
                    $n_pow_array[$j] = $temp_array[1];
                }
            }
        }
        //// put coeff's in order i want
        for ($j = 0; $j < $num_sub; $j++)
        {
            $c = $icoeff_array[$j];
            $m = $m_pow_array[$j];
            $n = $n_pow_array[$j];
            if ($m == 3 && $n == 0)
                $ocoeff_array[0] = $icoeff_array[$j];
            else if ($m == 2 && $n == 0)
                $ocoeff_array[1] = $icoeff_array[$j];
            else if ($m == 2 && $n == 1)
                $ocoeff_array[2] = $icoeff_array[$j];
            else if ($m == 1 && $n == 0)
                $ocoeff_array[3] = $icoeff_array[$j];
            else if ($m == 1 && $n == 1)
                $ocoeff_array[4] = $icoeff_array[$j];
            else if ($m == 1 && $n == 2)
                $ocoeff_array[5] = $icoeff_array[$j];
            else if ($m == 0 && $n == 1)
                $ocoeff_array[6] = $icoeff_array[$j];
            else if ($m == 0 && $n == 2)
                $ocoeff_array[7] = $icoeff_array[$j];
            else if ($m == 0 && $n == 3)
                $ocoeff_array[8] = $icoeff_array[$j];
            else if ($m == 0 && $n == 0)
                $ocoeff_array[9] = $icoeff_array[$j];
            else
            {
                //// echo "m or n pow greater then 3 or negative";
                return FALSE;
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != 0)
            {
                $coeff = $ocoeff_array[$j];
                if ($j > 0 && $j != 9)
                    coeff_prep($coeff);
                if ($j == 9)
                    coeff_prep($coeff,0);
                if ($j == 0)
                    $answer = $coeff."m^(3) ";
                else if ($j == 1)
                    $answer = $answer.$coeff."m^(2) ";
                else if ($j == 2)
                    $answer = $answer.$coeff."m^(2)n ";
                else if ($j == 3)
                    $answer = $answer.$coeff."m ";
                else if ($j == 4)
                    $answer = $answer.$coeff."mn ";
                else if ($j == 5)
                    $answer = $answer.$coeff."mn^(2) ";
                else if ($j == 6)
                    $answer = $answer.$coeff."n ";
                else if ($j == 7)
                    $answer = $answer.$coeff."n^(2) ";
                else if ($j == 8)
                    $answer = $answer.$coeff."n^(3) ";
                else // ($j == 9)
                    $answer = $answer.$coeff;
            }
        }
        $temp_length = strlen($answer);
        $temp_string = "";
        for ($j = 0; $j < $temp_length; $j++)
        {
            $char = substr($answer,$j,1);
            if ($j == 0)
            {
                if ($char == '+')
                {
                    //// do nothing
                }
                else
                    $temp_string = $temp_string.$char;
            }
            else
                $temp_string = $temp_string.$char;
        }
        $answer = $temp_string;
        return $answer;
    }
    else if ($type == 11)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in m,n,highest power = 2
        ////    type 23.3.
        ////    returns false if there are two negatives pulled
        ////    of the factors and not simplified
        ////    **NOTE** unlike the parser for the x factors
        ////    this factor has to return two different possible
        ////    answers if there is a negative pulled out
        ////    since there is no really easy way to tell which
        ////    factor is reversed
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $neg_out_front = FALSE;
        $neg_position = -1;
        $num_sub = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        ///////////////////////////////////////////////////////////
        ////   strips the sub_array strings of '*','(',')'
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = str_replace('*','',$sub_array[$i]);
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
        }
        ///////////////////////////////////////////////////////////
        ////    if there is a negative pulled out finds position
        ////    also if there are two negatives pulled out
        ////    returns FALSE
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($sub_array[$i] == "-" || $sub_array[$i] == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                else
                {
                    $neg_out_front = TRUE;
                    $neg_position = $i;
                }
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                ////echo "<br /> Before the parse<br /> $sub_array[$i]<br />";
                $sub_array[$i] = parse_input($sub_array[$i],112);
                ////echo "<br /> After the parse<br /> $sub_array[$i]<br />";
            }
        }
        ///////////////////////////////////////////////////////////
        ////    puts () around the factors
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                $temp_length = strlen($sub_array[$i]);
                $tchar_array = array();
                $tchar_array[] = '(';
                for ($j = 0; $j < $temp_length; $j++)
                {
                    if ($j == 0)
                    {
                        $char = substr($sub_array[$i],$j,1);
                        if ($char == '+')
                        {
                            //// do nothing
                        }
                        else
                            $tchar_array[] = $char;
                    }
                    else
                        $tchar_array[] = substr($sub_array[$i],$j,1);
                }
                $tchar_array[] = ')';
                $temp_string = "";
                for ($j = 0; $j < ($temp_length+2); $j++)
                    $temp_string = $temp_string.$tchar_array[$j];
                $sub_array[$i] = $temp_string;
            }
        }
        $answer = array();
        ///////////////////////////////////////////////////////////
        ////    returns two possible answers if negative out front
        ///////////////////////////////////////////////////////////
        if ($neg_out_front == TRUE)
        {
            $position1 = -1;
            $position2 = -1;
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                {
                    if ($position1 == -1)
                        $position1 = $i;
                    else
                        $position2 = $i;
                }
            }
            $temp_string1 = "";
            $temp_string2 = "";
            $tchar_array2 = array();
            $temp_string1 = $sub_array[$position1];
            $temp_string2 = $sub_array[$position2];
            $temp_length = strlen($temp_string1);
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string1,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
            $temp_string1 = $sub_array[$position1];
            $temp_length = strlen($sub_array[$position2]);
            $tchar_array2 = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string2,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
        }
        else // $neg_out_front == FALSE
        {
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                    $answer[] = $sub_array[$i];
            }
        }
        return $answer;
    }
    else if ($type == 12)
    {
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        ////
        //// factored terms of x with an x,x^2 or a number out front
        ////
        ////
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $sub_array = array();
        $tchar_array = array();
        $neg_out_front = FALSE;
        $neg_position = -1;
        $num_sub = 0;
        $num_par = 0;
        $lacking = FALSE;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($num_par == 0 && $char != '-' && $char != '(' && $char != '*')
            {
                $lacking = TRUE;
                $num_par--;
            }
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                if ($lacking == FALSE)
                {
                    $temp_string = $temp_string.$char;
                    $sub_array[] = $temp_string;
                    $char = "";
                    $temp_string = "";
                    $num_sub++;
                }
                else // $lacking == TRUE
                {
                    $sub_array[] = $temp_string;
                    $temp_string = "";
                    $num_sub++;
                    $num_par++;
                    $lacking = FALSE;
                }
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = str_replace('*','',$sub_array[$i]);
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $sub_array[$i] = trim($sub_array[$i]);
        }

        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_a_var = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            $char = $tchar_array2[$k];
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 'x')
                            {
                                $has_a_var = TRUE;
                                break;
                            }
                        }
                        if ($has_a_var == TRUE)
                        {
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,3);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    if ($reversed[$i] == TRUE)
                    {
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                                $tchar_array2[$i] = '+';
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,3);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            if ($num_reversed == 2)
                return FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,3);
                    if ($reversed[$j] == TRUE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,3);
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }
    else if ($type == 13)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in m,n,highest power = 2
        ////    type 23.3.
        ////    returns false if there are two negatives pulled
        ////    of the factors and not simplified
        ////    **NOTE** unlike the parser for the x factors
        ////    this factor has to return two different possible
        ////    answers if there is a negative pulled out
        ////    since there is no really easy way to tell which
        ////    factor is reversed
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $neg_out_front = FALSE;
        $neg_position = -1;
        $num_sub = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        ///////////////////////////////////////////////////////////
        ////   strips the sub_array strings of '*','(',')'
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = str_replace('*','',$sub_array[$i]);
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
        }
        ///////////////////////////////////////////////////////////
        ////    if there is a negative pulled out finds position
        ////    also if there are two negatives pulled out
        ////    returns FALSE
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($sub_array[$i] == "-" || $sub_array[$i] == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                else
                {
                    $neg_out_front = TRUE;
                    $neg_position = $i;
                }
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                $sub_array[$i] = parse_input($sub_array[$i],"11b");
            }
        }
        ///////////////////////////////////////////////////////////
        ////    puts () around the factors
        ///////////////////////////////////////////////////////////
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                $temp_length = strlen($sub_array[$i]);
                $tchar_array = array();
                $tchar_array[] = '(';
                for ($j = 0; $j < $temp_length; $j++)
                    $tchar_array[] = substr($sub_array[$i],$j,1);
                $tchar_array[] = ')';
            }
        }
        $answer = array();
        ///////////////////////////////////////////////////////////
        ////    returns two possible answers if negative out front
        ///////////////////////////////////////////////////////////
        if ($neg_out_front == TRUE)
        {
            $position1 = -1;
            $position2 = -1;
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                {
                    if ($position1 == -1)
                        $position1 = $i;
                    else
                        $position2 = $i;
                }
            }
            $temp_string1 = "";
            $temp_string2 = "";
            $tchar_array2 = array();
            $temp_string1 = $sub_array[$position1];
            $temp_string2 = $sub_array[$position2];
            $temp_length = strlen($temp_string1);
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string1,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
            $temp_string1 = $sub_array[$position1];
            $temp_length = strlen($sub_array[$position2]);
            $tchar_array2 = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $tchar_array2[] = substr($temp_string2,$j,1);
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array2[$j] == '+')
                    $tchar_array2[$j] = '-';
                else if ($tchar_array2[$j] == '-')
                    $tchar_array2[$j] = '+';
                else
                {
                    //// do nothing
                }
            }
            $answer[] = $temp_string1;
            $answer[] = $temp_string2;
        }
        else // $neg_out_front == FALSE
        {
            for ($i = 0; $i < $num_sub; $i++)
            {
                if ($neg_position != $i)
                    $answer[] = $sub_array[$i];
            }
        }
        return $answer;
    }
    else if ($type == 14)
    {
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        ////
        //// two factored terms in a,b,c,d
        //// type 29
        ////
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $coeff_array = array();
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $num_par = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = str_replace('*','',$sub_array[$i]);
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($sub_array[$i] == "-" || $sub_array[$i] == "-1")
            {
                $neg_out_front = TRUE;
                $neg_position = $i;
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($neg_position != $i)
            {
                if ($neg_out_front == TRUE) //// they pulled a negative out
                {
                    $num_neg = 0;
                    $temp_string = $sub_array[$i];
                    $temp_length = strlen($temp_string);
                    for ($j = 0; $j < $temp_length; $j++)
                    {
                        $char = substr($temp_string,$j,1);
                        if ($char == '-')
                            $num_neg++;
                    }
                    if ($num_neg == 1)
                        return FALSE;
                    else if ($num_neg == 2)
                        $temp_string = str_replace('-','+',$temp_string);
                    else
                    {
                        //// do nothing
                    }
                }
                $factor_has_an_a = FALSE;
                $factor_has_a_b = FALSE;
                $factor_has_a_c = FALSE;
                $factor_has_a_d = FALSE;
                $temp_array = explode('+',$sub_array[$i]);
                $k = 0;
                if ($temp_array[0] == "" && $temp_array[2] != "")
                    $k = 1;
                for ($k; $k < 3; $k++)
                {
                    if ($temp_array[$k] != "")
                    {
                        $has_an_a = FALSE;
                        $has_a_b = FALSE;
                        $has_a_c = FALSE;
                        $has_a_d = FALSE;
                        $temp_string = $temp_array[$k];
                        $temp_length = strlen($temp_string);
                        for ($j = 0; $j < $temp_length; $j++)
                        {
                            $char = substr($temp_string,$j,1);
                            if ($char == 'a')
                            {
                                $has_an_a = TRUE;
                                $factor_has_an_a = TRUE;
                            }
                            else if ($char == 'b')
                            {
                                $has_a_b = TRUE;
                                $factor_has_a_b = TRUE;
                            }
                            else if ($char == 'c')
                            {
                                $has_a_c = TRUE;
                                $factor_has_a_c = TRUE;
                            }
                            else if ($char == 'd')
                            {
                                $has_a_d = TRUE;
                                $factor_has_a_d = TRUE;
                            }
                            else
                            {
                                //// do nothing
                            }
                        }
                        if ($has_an_a == TRUE && $has_a_b == TRUE)
                            return FALSE;
                        else if ($has_an_a == TRUE && $has_a_c == TRUE)
                            return FALSE;
                        else if ($has_an_a == TRUE && $has_a_d == TRUE)
                            return FALSE;
                        else if ($has_a_b == TRUE && $has_a_c == TRUE)
                            return FALSE;
                        else if ($has_a_b == TRUE && $has_a_d == TRUE)
                            return FALSE;
                        else if ($has_a_c == TRUE && $has_a_d == TRUE)
                            return FALSE;
                        else if ($has_an_a == TRUE)
                        {
                            $temp_string = str_replace('a','',$temp_string);
                            if ($temp_string == "")
                                $coeff_array[0] = 1;
                            else if ($temp_string == "-")
                                $coeff_array[0] = -1;
                            else
                                $coeff_array[0] = $temp_string;
                        }
                        else if ($has_a_b == TRUE)
                        {
                            $temp_string = str_replace('b','',$temp_string);
                            if ($temp_string == "")
                                $coeff_array[1] = 1;
                            else if ($temp_string == "-")
                                $coeff_array[1] = -1;
                            else
                                $coeff_array[1] = $temp_string;
                        }
                        else if ($has_a_c == TRUE)
                        {
                            $temp_string = str_replace('c','',$temp_string);
                            if ($temp_string == "")
                                $coeff_array[2] = 1;
                            else if ($temp_string == "-")
                                $coeff_array[2] = -1;
                            else
                                $coeff_array[2] = $temp_string;
                        }
                        else if ($has_a_d == TRUE)
                        {
                            $temp_string = str_replace('d','',$temp_string);
                            if ($temp_string == "")
                                $coeff_array[3] = 1;
                            else if ($temp_string == "-")
                                $coeff_array[3] = -1;
                            else
                                $coeff_array[3] = $temp_string;
                        }
                        else
                        {
                            //// do nothing
                        }
                    }
                }
                if ($factor_has_an_a == TRUE && $factor_has_a_c == TRUE)
                    return FALSE;
                else if ($factor_has_an_a == TRUE && $factor_has_a_d == TRUE)
                    return FALSE;
                else if ($factor_has_a_b == TRUE && $factor_has_a_c == TRUE)
                    return FALSE;
                else if ($factor_has_a_b == TRUE && $factor_has_a_d == TRUE)
                    return FALSE;
                else
                {
                    //// do nothing
                }
            }
        }
        coeff_prep($coeff_array[1]);
        coeff_prep($coeff_array[3]);
        $answer = array();
        $temp_string = "( ";
        if ($coeff_array[0] != "0")
            $temp_string = $temp_string.$coeff_array[0]."a ";
        if ($coeff_array[1] != "0")
            $temp_string = $temp_string.$coeff_array[1]."b ";
        $temp_string = $temp_string.")";
        $answer[] = $temp_string;
        $temp_string = "( ";
        if ($coeff_array[2] != "0")
            $temp_string = $temp_string.$coeff_array[2]."c ";
        if ($coeff_array[3] != "0")
            $temp_string = $temp_string.$coeff_array[3]."d ";
        $temp_string = $temp_string.")";
        $answer[] = $temp_string;
        return $answer;
    }
    else if ($type == 15)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    two factored terms in y, highest power = 1
        ////    returns false if there are two negatives pulled
        ////    out of the factors and then not made positive
        ////    i.e. -(3-x)*(-)(4-x)
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        $reversed = array();
        $num_reversed = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $sub_array[$j] = str_replace('*','',$sub_array[$j]);
            $sub_array[$j] = str_replace('(','',$sub_array[$j]);
            $sub_array[$j] = str_replace(')','',$sub_array[$j]);
            $sub_array[$j] = trim($sub_array[$j]);
        }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_a_var = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            $char = $tchar_array2[$k];
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 'y')
                            {
                                $has_a_var = TRUE;
                                break;
                            }
                        }
                        if ($has_a_var == TRUE)
                        {
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,3);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array2[$i] == '-')
                            $tchar_array2[$i] = '+';
                        else if ($tchar_array2[$i] == '+')
                            $tchar_array2[$i] = '-';
                        else
                        {
                            //// do nothing
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,3);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            $fixed_reverse = FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,4);
                    if ($reversed[$j] == TRUE && $fixed_reverse == FALSE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,4);
                        $fixed_reversed = TRUE;
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }
    else if ($type == 16)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    three factored terms in x, highest power = 1
        ////    returns false if there are two negatives pulled
        ////    out of the factors and then not made positive
        ////    i.e. -(3-x)*(-)(4-x)(x-2)
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        $reversed = array();
        $num_reversed = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $sub_array[$j] = str_replace('*','',$sub_array[$j]);
            $sub_array[$j] = str_replace('(','',$sub_array[$j]);
            $sub_array[$j] = str_replace(')','',$sub_array[$j]);
            $sub_array[$j] = trim($sub_array[$j]);
        }

        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_a_var = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            $char = $tchar_array2[$k];
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 'x')
                            {
                                $has_a_var = TRUE;
                                break;
                            }
                        }
                        if ($has_a_var == TRUE)
                        {
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,3);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    if ($reversed[$i] == TRUE)
                    {
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                                $tchar_array2[$i] = '+';
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,3);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            if ($num_reversed == 2)
                return FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,3);
                    if ($reversed[$j] == TRUE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,3);
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }

    else if ($type == 17)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in t
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

        $max_pow++;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $pow_array = array();
        for ($i =0; $i < $max_pow; $i++)
            $pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_a_var = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
                $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 't')
                    $has_a_var = TRUE;
            }
            if ($has_a_var == FALSE)
            {
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $icoeff_array[$j] = $temp_string;
                $pow_array[$j] = 0;
            }
            else //// the substring includes a variable
            {
                if ($tchar_array[0] == 't')
                {
                    $has_open_par = FALSE;
                    $has_closed_par = FALSE;
                    $has_multi = FALSE;
                    $has_power = FALSE;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '*')
                            $has_multi = TRUE;
                        if ($tchar_array[$i] == '(')
                            $has_open_par = TRUE;
                        if ($tchar_array[$i] == ')')
                            $has_closed_par = TRUE;
                        if ($tchar_array[$i] == '^')
                            $has_power = TRUE;
                    }
                    if ($has_multi == TRUE)
                    {
                        $temp_array = explode('*',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            $temp_array[$i] = str_replace('t','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                    {
                        $temp_string = str_replace('t','',$temp_string);
                        if ($has_power == FALSE)
                        {
                            $temp_string = str_replace('(','',$temp_string);
                            $temp_string = str_replace(')','',$temp_string);
                            $pow_array[$j] = 1;
                            $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $temp_array = explode(')',$temp_string);
                            if ($temp_array[1] != "")
                            {
                                for ($i = 0; $i < 2; $i++)
                                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                $pow_array[$j] = $temp_array[0];
                                $icoeff_array[$j] = $temp_array[1];
                            }
                            else
                            {
                                $temp_array = explode('(',$temp_array[0]);
                                if ($temp_array[0] == "")
                                {
                                    $pow_array[$j] = $temp_array[1];
                                    $icoeff_array[$j] = 1;
                                }
                                else
                                {
                                    $pow_array[$j] = $temp_array[0];
                                    $icoeff_array[$j] = $temp_array[1];
                                }
                            }
                        }
                    }
                    else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        return FALSE;
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        return FALSE;
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('t','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = 1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = -1;
                            else
                                $icoeff_array[$j] = $temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('t','',$temp_string);
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = 1;
                        }
                    }
                }
                else if ($tchar_array[0] == '-')
                {
                    if ($tchar_array[1] != 't')
                    {
                        $temp_array = explode('t',$temp_string);
                        for ($i = 0; $i < 2; $i++)
                        {
                            if ($temp_array[$i] == NULL)
                                break;
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                            $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                        }
                        $icoeff_array[$j] = $temp_array[0];
                        if ($temp_array[1] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $tchar_array[0] = '';
                        $temp_string = "";
                        for ($i = 1; $i < $temp_length; $i++)
                            $temp_string = $temp_string.$tchar_array[$i];
                        $has_open_par = FALSE;
                        $has_closed_par = FALSE;
                        $has_multi = FALSE;
                        $has_power = FALSE;
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array[$i] == '*')
                                $has_multi = TRUE;
                            if ($tchar_array[$i] == '(')
                                $has_open_par = TRUE;
                            if ($tchar_array[$i] == ')')
                                $has_closed_par = TRUE;
                            if ($tchar_array[$i] == '^')
                                $has_power = TRUE;
                        }
                        if ($has_multi == TRUE)
                        {
                            $temp_array = explode('*',$temp_string);
                            for ($i = 0; $i < 2; $i++)
                            {
                                $temp_array[$i] = str_replace('t','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                 $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                                $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                                $temp_string = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == TRUE)
                        {
                            $temp_string = str_replace('t','',$temp_string);
                            if ($has_power == FALSE)
                            {
                                $temp_string = str_replace('(','',$temp_string);
                                $temp_string = str_replace(')','',$temp_string);
                                $pow_array[$j] = 1;
                                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                    $temp_string2 = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $temp_array = explode(')',$temp_string);
                                if ($temp_array[1] != "")
                                {
                                    for ($i = 0; $i < 2; $i++)
                                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                                    $pow_array[$j] = $temp_array[0];
                                    $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                                }
                                else
                                {
                                    $temp_array = explode('(',$temp_array[0]);
                                    if ($temp_array[0] == "")
                                    {
                                        $pow_array[$j] = $temp_array[1];
                                        $icoeff_array[$j] = -1;
                                    }
                                    else
                                    {
                                        $pow_array[$j] = $temp_array[0];
                                        $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                            for ($i = 1; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                            $temp_string = "-";
                                            for ($i = 0; $i < $temp_length; $i++)
                                                $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                                    }
                                }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                        {
                            ////echo $j;
                            ////echo "open but not closed";
                            return FALSE;
                        }
                        else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                        {
                            ////echo $j;
                            ////echo "closed but not open";
                            return FALSE;
                        }
                        else
                        {
                            if ($has_power == FALSE)
                            {
                                $pow_array[$j] = 1;
                                $temp_string = str_replace('t','',$temp_string);
                                if ($temp_string == "")
                                    $icoeff_array[$j] = -1;
                                else if ($temp_string == "-")
                                    $icoeff_array[$j] = 1;
                                else
                                    $icoeff_array[$j] = "-".$temp_string;
                            }
                            else
                            {
                                $temp_string = str_replace('^','',$temp_string);
                                $pow_array[$j] = $temp_string;
                                $icoeff_array[$j] = -1;
                            }
                        }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(')
                            $num_closed++;
                        if ($tchar_array[$i] == ')')
                            $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                        ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                        if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array[$i];
                    $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                    //// puts it in nice form
                    $temp_string = parse_input($temp_string,3);
                    $temp_array = explode('t',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
                else
                {
                    $temp_array = explode('t',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                        if ($temp_array[$i] == NULL)
                            break;
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                    }
                    $icoeff_array[$j] = $temp_array[0];
                    if ($temp_array[1] == NULL)
                        $pow_array[$j] = 1;
                    else
                        $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
        {
            $temp = (int)$pow_array[$j];
            if ($temp < 0)
            {
                ////echo "negative power";
                return FALSE;
            }
            if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
            {
                ////echo "two powers the same";
                return FALSE;
            }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
            if ($j == 0)
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j],0);
            }
            else
            {
                if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."t ".$answer;
                else
                    $answer = $ocoeff_array[$j]."t^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
            $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        return $answer;
    }
    else if ($type == 18)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    three factored terms in t, highest power = 1
        ////    returns false if there are two negatives pulled
        ////    out of the factors and then not made positive
        ////    i.e. -(3-t)*(-)(4-t)(t-2)
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $length = strlen($my_string);
        $temp_string = "";
        $tchar_array = array();
        $sub_array = array();
        $num_sub = 0;
        $neg_out_front = FALSE;
        $neg_position = -1;
        $reversed = array();
        $num_reversed = 0;
        $num_par = 0;
        for ($j = 0; $j < $length; $j++)
        {
            $tchar_array[] = substr($my_string,$j,1);
        }
        for ($j = 0; $j < $length; $j++)
        {
            $char = $tchar_array[$j];
            if ($char == '(')
            {
                $num_par++;
            }
            if ($char == ')')
            {
                $num_par--;
            }
            if ($num_par == 0 && $temp_string != "" )
            {
                $temp_string = $temp_string.$char;
                $sub_array[] = $temp_string;
                $char = "";
                $temp_string = "";
                $num_sub++;
            }
            else if ($char == '-' && $temp_string == "")
            {
                $sub_array[] = $char;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                 $i++;
            }
        }
        $i = 0;
        for ($j = 0; $j < $num_sub; $j++)
        {
            $sub_array[$j] = str_replace('*','',$sub_array[$j]);
            $sub_array[$j] = str_replace('(','',$sub_array[$j]);
            $sub_array[$j] = str_replace(')','',$sub_array[$j]);
            $sub_array[$j] = trim($sub_array[$j]);
        }

        for ($j = 0; $j < $num_sub; $j++)
        {
            $reversed[] = FALSE;
            $temp_string = $sub_array[$j];
            if ($temp_string == "-" || $temp_string == "-1")
            {
                if ($neg_out_front == TRUE)
                    return FALSE;
                $neg_out_front = TRUE;
                $neg_position = $j;
            }
            else
            {
                $tchar_array2 = array();
                $temp_length = strlen($temp_string);
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array2[] = substr($temp_string,$i,1);
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array2[$i] == '-')
                    {
                        $has_a_var = FALSE;
                        for ($k = $i+1; $k < $temp_length; $k++)
                        {
                            $char = $tchar_array2[$k];
                            if ($char == '-')
                                break;
                            if ($char == '+')
                                break;
                            if ($char == 't')
                            {
                                //echo "got this";
                                $has_a_var = TRUE;
                                break;
                            }
                        }
                        if ($has_a_var == TRUE)
                        {
                            $reversed[$j] = TRUE;
                            $num_reversed++;
                        }
                    }
                }
            }
        }
        if ($neg_out_front == FALSE)
        {
            $temp_string = "";
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = $sub_array[$j];
                $temp_string = parse_input($temp_string,17);
                if ($num_reverse == 2)
                {
                    $tchar_array2 = array();
                    $temp_length = strlen($temp_string);
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array2[] = substr($temp_string,$i,1);
                    if ($reversed[$i] == TRUE)
                    {
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                                $tchar_array2[$i] = '+';
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                    }
                    $temp_string = "";
                    for ($i = 0; $i < $temp_length; $i++)
                        $temp_string = $temp_string.$tchar_array2[$i];
                    parse_input($temp_string,17);
                }
                $tchar_array3 = array();
                $temp_length = strlen($temp_string);
                $tchar_array3[] = '(';
                for ($i = 0; $i < $temp_length; $i++)
                    $tchar_array3[] = substr($temp_string,$i,1);
                $tchar_array3[] = ')';
                $temp_string = "";
                for ($i = 0; $i < ($temp_length+2); $i++)
                    $temp_string = $temp_string.$tchar_array3[$i];
                $sub_array[$j] = $temp_string;
            }
        }
        else // they pulled a negative out of a factor
        {
            if ($num_reversed == 2)
                return FALSE;
            for ($j = 0; $j < $num_sub; $j++)
            {
                $temp_string = "";
                if ($j != $neg_position)
                {
                    $temp_string = $sub_array[$j];
                    $temp_string = parse_input($temp_string,17);
                    if ($reversed[$j] == TRUE)
                    {
                        $tchar_array2 = array();
                        $temp_length = strlen($temp_string);
                        for ($i = 0; $i < $temp_length; $i++)
                            $tchar_array2[] = substr($temp_string,$i,1);
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($tchar_array2[$i] == '-')
                            {
                                ////echo "switched this";
                                $tchar_array2[$i] = '+';
                            }
                            else if ($tchar_array2[$i] == '+')
                                $tchar_array2[$i] = '-';
                            else
                            {
                                //// do nothing
                            }
                        }
                        $temp_string = "";
                        for ($i = 0; $i < $temp_length; $i++)
                        {
                            if ($i == 0 && $tchar_array2[$i] == '+')
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string.$tchar_array2[$i];
                        }
                        parse_input($temp_string,17);
                    }
                    $tchar_array3 = array();
                    $temp_length = strlen($temp_string);
                    $tchar_array3[] = '(';
                    for ($i = 0; $i < $temp_length; $i++)
                        $tchar_array3[] = substr($temp_string,$i,1);
                    $tchar_array3[] = ')';
                    $temp_string = "";
                    for ($i = 0; $i < ($temp_length+2); $i++)
                        $temp_string = $temp_string.$tchar_array3[$i];
                    $sub_array[$j] = $temp_string;
                }
            }
        }
        $answer = array();
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $neg_position)
                $answer[] = $sub_array[$i];
        }
        return $answer;
    }
    else if ($type == 19)
    {
        //// sqrt x,y
        $char_array = array();
        $temp_string = "";
        $sub_array = array();
        $num_sub = 0;
        $num_parenth = 0;
        $num_s = 0;
        $num_q = 0;
        $num_r = 0;
        $num_t = 0;
        $num_sqrt = 0;
        $sqrt_pos = -1;
        for ($j=0; $j < $length; $j++)
            $char_array[] = substr($my_string,$j,1);
        for ($j=0; $j < $length; $j++)
        {
            if ($char_array[$j] == 's' && $char_array[$j+1] == 'q')
            {
                if ($char_array[$j+2] == 'r' && $char_array[$j+3] == 't')
                {
                    ///// do nothing
                }
                else
                    return FALSE;
            }
        }
        if ($char_array[0] == 's')
        {
            $sqrt_pos = 0;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 's')
                {
                    $num_s++;
                    if ($num_s == 2)
                        return FALSE;
                }
                else if ($tchar == 'q')
                {
                    $num_q++;
                    if ($num_q == 2)
                        return FALSE;
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r == 2)
                        return FALSE;
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t == 2)
                         return FALSE;
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_parenth == 0 && $num_sqrt == 0)
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                        $num_sqrt = 1;
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        else
        {
            $sqrt_pos = 1;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 's')
                {
                    $num_s++;
                    if ($num_s > 1)
                    {
                        return FALSE;
                    }
                    else
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                    }
                }
                else if ($tchar == 'q')
                {
                    $num_q++;
                    if ($num_q > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_t > 0 && $num_parenth == 0 )
                    {
                        if ($num_sqrt == 0)
                        {
                            $num_sqrt = 1;
                            $sub_array[] = $temp_string;
                            $num_sub++;
                            $temp_string = "";
                        }
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = parse_input($sub_array[$i],1);
        }
        $temp_string = "";
        $answer = "";
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $sqrt_pos)
                $temp_string = $temp_string.$sub_array[$i];
        }
        $answer = $temp_string;
        $answer = $answer."*sqrt(".$sub_array[$sqrt_pos].")";
        return $answer;
    }
    else if ($type == 20)
    {
        //// cuberoot
        $char_array = array();
        $temp_string = "";
        $sub_array = array();
        $num_sub = 0;
        $num_parenth = 0;
        $num_c = 0;
        $num_b = 0;
        $num_r = 0;
        $num_t = 0;
        $num_cbrt = 0;
        $cbrt_pos = -1;
        for ($j=0; $j < $length; $j++)
            $char_array[] = substr($my_string,$j,1);
        for ($j=0; $j < $length; $j++)
        {
            if ($char_array[$j] == 'c' && $char_array[$j+1] == 'b')
            {
                if ($char_array[$j+2] == 'r' && $char_array[$j+3] == 't')
                {
                    ///// do nothing
                }
                else
                    return FALSE;
            }
        }
        if ($char_array[0] == 'c')
        {
            $cbrt_pos = 0;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 'c')
                {
                    $num_c++;
                    if ($num_c == 2 )
                        return FALSE;
                }
                else if ($tchar == 'b')
                {
                    $num_b++;
                    if ($num_b == 2)
                        return FALSE;
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r == 2)
                        return FALSE;
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t == 2)
                         return FALSE;
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_parenth == 0 && $num_cbrt == 0)
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                        $num_cbrt = 1;
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        else
        {
            $cbrt_pos = 1;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 'c')
                {
                    $num_c++;
                    if ($num_c > 1)
                    {
                        return FALSE;
                    }
                    else
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                    }
                }
                else if ($tchar == 'b')
                {
                    $num_b++;
                    if ($num_b > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_t > 0 && $num_parenth == 0 )
                    {
                        if ($num_cbrt == 0)
                        {
                            $num_cbrt = 1;
                            $sub_array[] = $temp_string;
                            $num_sub++;
                            $temp_string = "";
                        }
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = parse_input($sub_array[$i],1);
        }
        $temp_string = "";
        $answer = "";
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $cbrt_pos)
                $temp_string = $temp_string.$sub_array[$i];
        }
        $answer = $temp_string;
        $answer = $answer."*cbrt(".$sub_array[$cbrt_pos].")";
        return $answer;
    }
    else if ($type == 21)
    {
        //// fourth root
        //// sqrt x,y
        $char_array = array();
        $temp_string = "";
        $sub_array = array();
        $num_sub = 0;
        $num_parenth = 0;
        $num_f = 0;
        $num_h = 0;
        $num_r = 0;
        $num_t = 0;
        $num_fhrt = 0;
        $fhrt_pos = -1;
        for ($j=0; $j < $length; $j++)
            $char_array[] = substr($my_string,$j,1);
        for ($j=0; $j < $length; $j++)
        {
            if ($char_array[$j] == 'f' && $char_array[$j+1] == 'h')
            {
                if ($char_array[$j+2] == 'r' && $char_array[$j+3] == 't')
                {
                    ///// do nothing
                }
                else
                    return FALSE;
            }
        }
        if ($char_array[0] == 'f')
        {
            $fhrt_pos = 0;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 'f')
                {
                    $num_f++;
                    if ($num_f > 1)
                        return FALSE;
                }
                else if ($tchar == 'h')
                {
                    $num_h++;
                    if ($num_h > 1)
                        return FALSE;
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r > 1)
                        return FALSE;
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t > 1)
                         return FALSE;
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_parenth == 0 && $num_fhrt == 0)
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                        $num_fhrt = 1;
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        else
        {
            $fhrt_pos = 1;
            for ($j = 0; $j < $length; $j++)
            {
                $tchar = $char_array[$j];
                if ($tchar == 'f')
                {
                    $num_f++;
                    if ($num_f > 1)
                    {
                        return FALSE;
                    }
                    else
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                    }
                }
                else if ($tchar == 'h')
                {
                    $num_h++;
                    if ($num_h > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 'r')
                {
                    $num_r++;
                    if ($num_r > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == 't')
                {
                    $num_t++;
                    if ($num_t > 1)
                    {
                        return FALSE;
                    }
                }
                else if ($tchar == '(')
                {
                    $num_parenth++;
                    $temp_string = $temp_string.$tchar;
                }
                else if ($tchar == ')')
                {
                    $num_parenth--;
                    $temp_string = $temp_string.$tchar;
                }
                else
                {
                    if ($num_t > 0 && $num_parenth == 0 )
                    {
                        if ($num_fhrt == 0)
                        {
                            $num_fhrt = 1;
                            $sub_array[] = $temp_string;
                            $num_sub++;
                            $temp_string = "";
                        }
                    }
                    $temp_string = $temp_string.$tchar;
                }
            }
            $sub_array[] = $temp_string;
            $num_sub++;
            $temp_string = "";
        }
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = parse_input($sub_array[$i],1);
        }
        $temp_string = "";
        $answer = "";
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $fhrt_pos)
                $temp_string = $temp_string.$sub_array[$i];
        }
        $answer = $temp_string;
        $answer = $answer."*fhrt(".$sub_array[$fhrt_pos].")";
        return $answer;
    }
    else if ($type == 22)
    {
        //// polynomial with sqrt
        $num_sub = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $sqrt_pos = -1;
        for ($j = 0; $j < $length; $j++)
            $char_array[] = substr($my_string,$j,1);
        $temp_string = $char_array[0];
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $num_sub++;
        $temp_string = "";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                   $i++;
            }
        }
        $i = 0;
        for ($i = 0; $i < $num_sub; $i++)
        {
            $tchar_array = array();
            $temp_length = strlen($sub_array[$i]);
            for ($j = 0; $j < $temp_length; $j++)
                $tchar_array[] = substr($sub_array[$i],$j,1);
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array[$j] == 's')
                {
                    if ($sqrt_pos == -1)
                    {
                        $sqrt_pos = $i;
                    }
                    else
                        return FALSE;
                }
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $sqrt_pos)
            {
                $sub_array[$i] = parse_input($sub_array[$i],1);
            }
            else
            {
                $sub_array[$i] = parse_input($sub_array[$i],19);
            }
        }
        $answer = "";
        $answer = $sub_array[$sqrt_pos];
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $sqrt_pos)
            {
                if (substr($sub_array[$i],0,1) != '-')
                    $sub_array[$i] = " + ".$sub_array[$i];
                else
                    $sub_array[$i] = " ".$sub_array[$i];
                $answer = $answer.$sub_array[$i];
            }
        }
        return $answer;
    }
    else if ($type == 23)
    {
        //// polynomial with sqrt and single number factor pulled out front
        $char_array = array();
        $temp_string = "";
        $num_parenth = 0;
        $sub_array = array();
        $poly_pos = -1;
        $num_sub = 0;
        $new_sub_array = array();
        $pulled_out_a_neg = FALSE;
        for ($j = 0; $j < $length; $j++)
            $char_array[] = substr($my_string,$j,1);
        for ($j = 0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '(')
            {
                if ($j != 0 && $num_parenth == 0)
                {
                    $sub_array[] = $temp_string;
                    $num_sub++;
                    $temp_string = "";
                }
                $num_parenth++;
            }
            else if ($char == ')')
            {
                $num_parenth--;
                $temp_string = $temp_string.$char;
                if ($j != 0 && $num_parenth == 0)
                {
                    $sub_array[] = $temp_string;
                    $num_sub++;
                    $temp_string = "";
                }
                $char = '';
            }
            else
            {
                //// do nothing
            }

            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $num_sub++;
        $temp_string = "";
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($sub_array[$i] == "-" || $sub_array[$i] == "(-)")
            {
                $pulled_out_a_neg = TRUE;
            }
        }
        for ($i = 0; $i < $num_sub; $i++)
        {
            $parenth_in_first = FALSE;
            $parenth_in_last = FALSE;
            $tchar_array = array();
            $temp_length = strlen($sub_array[$i]);
            for ($j = 0; $j < $temp_length; $j++)
                $tchar_array[] = substr($sub_array[$i],$j,1);
            if ($tchar_array[0] == '(')
            {
                $parenth_in_first = TRUE;
            }
            if ($tchar_array[$temp_length-1] == ')')
            {
                $parenth_in_last = TRUE;
            }
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($tchar_array[$j] == 's')
                {
                    if ($poly_pos == -1)
                    {
                        $poly_pos = $i;
                    }
                    else
                        return FALSE;
                }
            }
            $temp_string = "";
            for ($j = 0; $j < $temp_length; $j++)
            {
                if ($parenth_in_first == TRUE && $j == 0)
                {
                    //// do nothing
                }
                else if ($parenth_in_last == TRUE && $j == ($temp_length-1))
                {
                    //// do nothing
                }
                else
                {
                    $char = $tchar_array[$j];
                    if ($pulled_out_a_neg == TRUE && $i == $poly_pos)
                    {
                        if ($char == '-')
                        {
                            if ($j == 0)
                            {
                                //// do nothing
                            }
                            else if ($j == 1 && $parenth_in_first == TRUE)
                            {
                                //// do nothing
                            }
                            else
                                $temp_string = $temp_string."+";
                        }
                        else if ($char == '+')
                        {
                            $temp_string = $temp_string."-";
                        }
                        else if ($j == 1 && $parenth_in_first == TRUE)
                        {
                            $temp_string = $temp_string."-".$char;
                        }
                        else if ($j == 0)
                        {
                            $temp_string = $temp_string."-".$char;
                        }
                        else
                            $temp_string = $temp_string.$char;
                    }
                    else
                        $temp_string = $temp_string.$char;
                }
            }
            $sub_array[$i] = $temp_string;
        }
        $temp_string = "";
        for ($i = 0; $i < $num_sub; $i++)
        {
            if ($i != $poly_pos && $sub_array[$i] != "")
            {
                if ($temp_string == "")
                    $temp_string = $sub_array[$i];
                else
                    $temp_string = $temp_string."*".$sub_array[$i];
            }
        }
        $new_sub_array[] = $temp_string;
        $new_sub_array[] = $sub_array[$poly_pos];
        $new_sub_array[0] = parse_input($new_sub_array[0],1);
        $new_sub_array[1] = parse_input($new_sub_array[1],22);
        $answer = $new_sub_array[0]."(".$new_sub_array[1].")";
        return $answer;
    }
    else if ($type == 24)
    {
        //// monomial with x and h
        $x_pow = "0";
        $h_pow = "0";
        $coeff = "1";
        $num_x = 0;
        $num_h = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'x')
                $num_x++;
            if ($char == 'h')
                $num_h++;
        }
        if ($num_x > 1 || $num_h > 1)
            return FALSE;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'x' && $temp_string != "" && $temp_string != "(")
            {
                 $sub_array[] = $temp_string;
                 $temp_string = "";
            }
            if ($char == 'h' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'x')
            {
                $sub_array[$i] = str_replace('x','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $x_pow = $sub_array[$i];
                else
                    $x_pow = 1;
            }
            else if ($temp_array[0] == 'h')
            {
                $sub_array[$i] = str_replace('h','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $h_pow = $sub_array[$i];
                else
                    $h_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($x_pow != "0")
        {
            if ($x_pow == "1")
                $answer = $answer."x";
            else
                $answer = $answer."x^(".$x_pow.")";
        }
        if ($h_pow != "0")
        {
            if ($h_pow == "1")
                $answer = $answer."h";
            else
                $answer = $answer."h^(".$h_pow.")";
        }
        if ($coeff == "1" && $x_pow == "0" && $h_pow == "0")
            $answer = "1";
        return $answer;
    }
    else if ($type == 25)
    {
        //// monomial with a and h
        $a_pow = "0";
        $h_pow = "0";
        $coeff = "1";
        $num_a = 0;
        $num_h = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == 'a')
                $num_a++;
            if ($char == 'h')
                $num_h++;
        }
        if ($num_a > 1 || $num_h > 1)
            return FALSE;
        for ($j=0; $j < $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '*')
            {
                $sub_array[]=$temp_string;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == ')' && $char_array[$j+1] == '(')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
                $j++;
                $char = $char_array[$j];
            }
            if ($char == '(' && $temp_string != "" && $temp_string != "(" && $char_array[$j-1] != '^')
            {
                $sub_array[]=$temp_string;
                $num_sub++;
                $temp_string = "";
            }
            if ($char == 'a' && $temp_string != "" && $temp_string != "(")
            {
                 $sub_array[] = $temp_string;
                 $temp_string = "";
            }
            if ($char == 'h' && $temp_string != "" && $temp_string != "(")
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $sub_array[] = "NULL";
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        while ($sub_array[$i] != "NULL")
        {
            $sub_array[$i] = str_replace('(','',$sub_array[$i]);
            $sub_array[$i] = str_replace(')','',$sub_array[$i]);
            $temp_length = strlen($sub_array[$i]);
            $temp_array = array();
            for ($j = 0; $j < $temp_length; $j++)
            {
                $temp_array[] = substr($sub_array[$i],$j,1);
            }
            if ($temp_array[0] == 'a')
            {
                $sub_array[$i] = str_replace('a','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $a_pow = $sub_array[$i];
                else
                    $a_pow = 1;
            }
            else if ($temp_array[0] == 'h')
            {
                $sub_array[$i] = str_replace('h','',$sub_array[$i]);
                $sub_array[$i] = str_replace('^','',$sub_array[$i]);
                if ($sub_array[$i] != "")
                    $h_pow = $sub_array[$i];
                else
                    $h_pow = 1;
            }
            else
            {
                $coeff = $sub_array[$i];
            }
            $i++;
        }
        $answer = "";
        if ($coeff != "1")
            $answer = $answer.$coeff;
        if ($a_pow != "0")
        {
            if ($a_pow == "1")
                $answer = $answer."a";
            else
                $answer = $answer."a^(".$a_pow.")";
        }
        if ($h_pow != "0")
        {
            if ($h_pow == "1")
                $answer = $answer."h";
            else
                $answer = $answer."h^(".$h_pow.")";
        }
        if ($coeff == "1" && $a_pow == "0" && $h_pow == "0")
            $answer = "1";
        return $answer;
    }
    else if ($type == 26)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in x,h
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $max_pow = 36;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $x_pow_array = array();
        $h_pow_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $x_pow_array[] = 0;
        for ($i = 0; $i < $max_pow; $i++)
            $h_pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        ////echo "<br /> parser input/output <br />";
        for ($j = 0; $j < $num_sub; $j++)
        {
            ////echo "<br /> before the parse<br /> $sub_array[$j]<br />";
            $sub_array[$j] = parse_input($sub_array[$j],24);
            ////echo "<br /> after the parse<br /> $sub_array[$j]<br />";
        }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_an_x = FALSE;
            $has_a_h = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
            $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'x')
                $has_an_x = TRUE;
            }
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'h')
                $has_a_h = TRUE;
            }
            if ($has_an_x == FALSE && $has_a_h == FALSE)
            {
                ////  substring is the constant
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                $icoeff_array[$j] = $temp_string;
                $x_pow_array[$j] = 0;
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_x == TRUE && $has_a_h == FALSE)
            {
                $temp_array = explode('x',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $x_pow_array[$j] = 1;
                else
                    $x_pow_array[$j] = $temp_array[1];
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_x == FALSE && $has_a_h == TRUE)
            {
                $temp_array = explode('h',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $h_pow_array[$j] = 1;
                else
                    $h_pow_array[$j] = $temp_array[1];
                $x_pow_array[$j] = 0;
            }
            else // ($has_an_x == TRUE && $has_a_h == TRUE)
            {
                $temp_array = explode('x',$temp_string);
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                $temp_array = explode('h',$temp_array[1]);
                if ($temp_array[0] == NULL)
                    $x_pow_array[$j] = 1;
                else
                {
                    $temp_array[0] = str_replace('^','',$temp_array[0]);
                    $temp_array[0] = str_replace('(','',$temp_array[0]);
                    $temp_array[0] = str_replace(')','',$temp_array[0]);
                    $x_pow_array[$j] = $temp_array[0];
                }
                if ($temp_array[1] == NULL)
                    $h_pow_array[$j] = 1;
                else
                {
                    $temp_array[1] = str_replace('^','',$temp_array[1]);
                    $temp_array[1] = str_replace('(','',$temp_array[1]);
                    $temp_array[1] = str_replace(')','',$temp_array[1]);
                    $h_pow_array[$j] = $temp_array[1];
                }
            }
        }
        //// put coeff's in order i want
        for ($j = 0; $j < $num_sub; $j++)
        {
            $c = $icoeff_array[$j];
            $x = $x_pow_array[$j];
            $h = $h_pow_array[$j];
            if ($x == 5 && $h == 0)
                $ocoeff_array[0] = $c;
            else if ($x == 5 && $h == 1)
                $ocoeff_array[1] = $c;
            else if ($x == 5 && $h == 2)
                $ocoeff_array[2] = $c;
            else if ($x == 5 && $h == 3)
                $ocoeff_array[3] = $c;
            else if ($x == 5 && $h == 4)
                $ocoeff_array[4] = $c;
            else if ($x == 5 && $h == 5)
                $ocoeff_array[5] = $c;
            else if ($x == 4 && $h == 0)
                $ocoeff_array[6] = $c;
            else if ($x == 4 && $h == 1)
                $ocoeff_array[7] = $c;
            else if ($x == 4 && $h == 2)
                $ocoeff_array[8] = $c;
            else if ($x == 4 && $h == 3)
                $ocoeff_array[9] = $c;
            else if ($x == 4 && $h == 4)
                $ocoeff_array[10] = $c;
            else if ($x == 4 && $h == 5)
                $ocoeff_array[11] = $c;
            else if ($x == 3 && $h == 0)
                $ocoeff_array[12] = $c;
            else if ($x == 3 && $h == 1)
                $ocoeff_array[13] = $c;
            else if ($x == 3 && $h == 2)
                $ocoeff_array[14] = $c;
            else if ($x == 3 && $h == 3)
                $ocoeff_array[15] = $c;
            else if ($x == 3 && $h == 4)
                $ocoeff_array[16] = $c;
            else if ($x == 3 && $h == 5)
                $ocoeff_array[17] = $c;
            else if ($x == 2 && $h == 0)
                $ocoeff_array[18] = $c;
            else if ($x == 2 && $h == 1)
                $ocoeff_array[19] = $c;
            else if ($x == 2 && $h == 2)
                $ocoeff_array[20] = $c;
            else if ($x == 2 && $h == 3)
                $ocoeff_array[21] = $c;
            else if ($x == 2 && $h == 4)
                $ocoeff_array[22] = $c;
            else if ($x == 2 && $h == 5)
                $ocoeff_array[23] = $c;
            else if ($x == 1 && $h == 0)
                $ocoeff_array[24] = $c;
            else if ($x == 1 && $h == 1)
                $ocoeff_array[25] = $c;
            else if ($x == 1 && $h == 2)
                $ocoeff_array[26] = $c;
            else if ($x == 1 && $h == 3)
                $ocoeff_array[27] = $c;
            else if ($x == 1 && $h == 4)
                $ocoeff_array[28] = $c;
            else if ($x == 1 && $h == 5)
                $ocoeff_array[29] = $c;
            else if ($x == 0 && $h == 0)
                $ocoeff_array[30] = $c;
            else if ($x == 0 && $h == 1)
                $ocoeff_array[31] = $c;
            else if ($x == 0 && $h == 2)
                $ocoeff_array[32] = $c;
            else if ($x == 0 && $h == 3)
                $ocoeff_array[33] = $c;
            else if ($x == 0 && $h == 4)
                $ocoeff_array[34] = $c;
            else if ($x == 0 && $h == 5)
                $ocoeff_array[35] = $c;
            else
            {
            //// echo "x or h pow greater then 3 or negative";
                return FALSE;
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != 0)
            {
                $coeff = $ocoeff_array[$j];
                if ($j == 0 && $coeff == 1)
                    $coeff = "";
                else if ($j == 0 && $coeff == -1)
                    $coeff = "-";
                if ($j > 0 && $j != 30)
                    coeff_prep($coeff);
                if ($j == 30)
                    coeff_prep($coeff,0);
                if ($j == 0)
                    $answer = $coeff."x^(5) ";
                else if ($j == 1)
                    $answer = $answer.$coeff."x^(5)h ";
                else if ($j == 2)
                    $answer = $answer.$coeff."x^(5)h^(2) ";
                else if ($j == 3)
                    $answer = $answer.$coeff."x^(5)h^(3) ";
                else if ($j == 4)
                    $answer = $answer.$coeff."x^(5)h^(4) ";
                else if ($j == 5)
                    $answer = $answer.$coeff."x^(5)h^(5) ";
                else if ($j == 6)
                    $answer = $answer.$coeff."x^(4) ";
                else if ($j == 7)
                    $answer = $answer.$coeff."x^(4)h ";
                else if ($j == 8)
                    $answer = $answer.$coeff."x^(4)h^(2) ";
                else if ($j == 9)
                    $answer = $answer.$coeff."x^(4)h^(3) ";
                else if ($j == 10)
                    $answer = $answer.$coeff."x^(4)h^(4) ";
                else if ($j == 11)
                    $answer = $answer.$coeff."x^(4)h^(5) ";
                else if ($j == 12)
                    $answer = $answer.$coeff."x^(3) ";
                else if ($j == 13)
                    $answer = $answer.$coeff."x^(3)h ";
                else if ($j == 14)
                    $answer = $answer.$coeff."x^(3)h^(2) ";
                else if ($j == 15)
                    $answer = $answer.$coeff."x^(3)h^(3) ";
                else if ($j == 16)
                    $answer = $answer.$coeff."x^(3)h^(4) ";
                else if ($j == 17)
                    $answer = $answer.$coeff."x^(3)h^(5) ";
                else if ($j == 18)
                    $answer = $answer.$coeff."x^(2) ";
                else if ($j == 19)
                    $answer = $answer.$coeff."x^(2)h ";
                else if ($j == 20)
                    $answer = $answer.$coeff."x^(2)h^(2) ";
                else if ($j == 21)
                    $answer = $answer.$coeff."x^(2)h^(3) ";
                else if ($j == 22)
                    $answer = $answer.$coeff."x^(2)h^(4) ";
                else if ($j == 23)
                    $answer = $answer.$coeff."x^(2)h^(5) ";
                else if ($j == 24)
                    $answer = $answer.$coeff."x ";
                else if ($j == 25)
                    $answer = $answer.$coeff."xh ";
                else if ($j == 26)
                    $answer = $answer.$coeff."xh^(2) ";
                else if ($j == 27)
                    $answer = $answer.$coeff."xh^(3) ";
                else if ($j == 28)
                    $answer = $answer.$coeff."xh^(4) ";
                else if ($j == 29)
                    $answer = $answer.$coeff."xh^(5) ";
                else if ($j == 30)
                    $answer = $answer.$coeff;
                else if ($j == 31)
                    $answer = $answer.$coeff."h";
                else if ($j == 32)
                    $answer = $answer.$coeff."h^(2) ";
                else if ($j == 33)
                    $answer = $answer.$coeff."h^(3) ";
                else if ($j == 34)
                    $answer = $answer.$coeff."h^(4) ";
                else // ($j == 35)
                    $answer = $answer.$coeff."h^(5) ";
            }
        }
        $temp_length = strlen($answer);
        $temp_string = "";
        for ($j = 0; $j < $temp_length; $j++)
        {
            $char = substr($answer,$j,1);
            if ($j == 0)
            {
                if ($char == '+')
                {
                //// do nothing
                }
                else
                    $temp_string = $temp_string.$char;
            }
            else
                $temp_string = $temp_string.$char;
        }
        $answer = $temp_string;
        return $answer;
    }
    else if ($type == 27)
    {
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ////
        ////    polynomial in a,h
        ////    returns false if there are negative exponents
        ////    returns false if there are two terms with the
        ////    same power
        ////
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        $max_pow = 36;
        //// initialize the input coeff array
        $icoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $icoeff_array[] = "0";
        //// initialize the output coeff array
        $ocoeff_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $ocoeff_array[] = "0";
        //// initialize the pow array
        //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
        $a_pow_array = array();
        $h_pow_array = array();
        for ($i = 0; $i < $max_pow; $i++)
            $a_pow_array[] = 0;
        for ($i = 0; $i < $max_pow; $i++)
            $h_pow_array[] = 0;
        $char_array = array();
        $sub_array = array();
        $temp_string = "";
        $char_array[0] = ' ';
        $num_sub = 0;
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        for ($j = 1; $j <= $length; $j++)
        {
            $char = $char_array[$j];
            if ($char == '+')
            {
                $sub_array[] = $temp_string;
                $j++;
                $char = $char_array[$j];
                $temp_string = "";
                $num_sub++;
            }
            if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
            {
                $sub_array[] = $temp_string;
                $temp_string = "";
                $num_sub++;
            }
            $temp_string = $temp_string.$char;
        }
        $sub_array[] = $temp_string;
        $temp_string = "";
        $num_sub++;
        $i = 0;
        if ($debug == TRUE)
        {
            while ($sub_array[$i] != "NULL")
            {
                echo "<br /> sub_array $i is $sub_array[$i]";
                $i++;
            }
        }
        $i = 0;
        ////echo "<br /> parser input/output <br />";
        for ($j = 0; $j < $num_sub; $j++)
        {
            ////echo "<br /> before the parse<br /> $sub_array[$j]<br />";
            $sub_array[$j] = parse_input($sub_array[$j],25);
            ////echo "<br /> after the parse<br /> $sub_array[$j]<br />";
        }
        for ($j = 0; $j < $num_sub; $j++)
        {
            $has_an_a = FALSE;
            $has_a_h = FALSE;
            $temp_string = $sub_array[$j];
            $temp_length = strlen($temp_string);
            $tchar_array = array();
            for ($i = 0; $i < $temp_length; $i++)
            $tchar_array[] = substr($temp_string,$i,1);
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'a')
                $has_an_a = TRUE;
            }
            for ($i = 0; $i < $temp_length; $i++)
            {
                if ($tchar_array[$i] == 'h')
                $has_a_h = TRUE;
            }
            if ($has_an_a == FALSE && $has_a_h == FALSE)
            {
                ////  substring is the constant
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                $icoeff_array[$j] = $temp_string;
                $a_pow_array[$j] = 0;
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_a == TRUE && $has_a_h == FALSE)
            {
                $temp_array = explode('a',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $a_pow_array[$j] = 1;
                else
                    $a_pow_array[$j] = $temp_array[1];
                $y_pow_array[$j] = 0;
            }
            else if ($has_an_a == FALSE && $has_a_h == TRUE)
            {
                $temp_array = explode('h',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                if ($temp_array[1] == NULL)
                    $h_pow_array[$j] = 1;
                else
                    $h_pow_array[$j] = $temp_array[1];
                $a_pow_array[$j] = 0;
            }
            else // ($has_an_a == TRUE && $has_a_h == TRUE)
            {
                $temp_array = explode('a',$temp_string);
                if ($temp_array[0] != NULL)
                {
                    if ($temp_array[0] == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_array[0];
                }
                else
                    $icoeff_array[$j] = 1;
                $temp_array = explode('h',$temp_array[1]);
                if ($temp_array[0] == NULL)
                    $a_pow_array[$j] = 1;
                else
                {
                    $temp_array[0] = str_replace('^','',$temp_array[0]);
                    $temp_array[0] = str_replace('(','',$temp_array[0]);
                    $temp_array[0] = str_replace(')','',$temp_array[0]);
                    $a_pow_array[$j] = $temp_array[0];
                }
                if ($temp_array[1] == NULL)
                    $h_pow_array[$j] = 1;
                else
                {
                    $temp_array[1] = str_replace('^','',$temp_array[1]);
                    $temp_array[1] = str_replace('(','',$temp_array[1]);
                    $temp_array[1] = str_replace(')','',$temp_array[1]);
                    $h_pow_array[$j] = $temp_array[1];
                }
            }
        }
        //// put coeff's in order i want
        for ($j = 0; $j < $num_sub; $j++)
        {
            $c = $icoeff_array[$j];
            $a = $a_pow_array[$j];
            $h = $h_pow_array[$j];
            if ($a == 5 && $h == 0)
                $ocoeff_array[0] = $c;
            else if ($a == 5 && $h == 1)
                $ocoeff_array[1] = $c;
            else if ($a == 5 && $h == 2)
                $ocoeff_array[2] = $c;
            else if ($a == 5 && $h == 3)
                $ocoeff_array[3] = $c;
            else if ($a == 5 && $h == 4)
                $ocoeff_array[4] = $c;
            else if ($a == 5 && $h == 5)
                $ocoeff_array[5] = $c;
            else if ($a == 4 && $h == 0)
                $ocoeff_array[6] = $c;
            else if ($a == 4 && $h == 1)
                $ocoeff_array[7] = $c;
            else if ($a == 4 && $h == 2)
                $ocoeff_array[8] = $c;
            else if ($a == 4 && $h == 3)
                $ocoeff_array[9] = $c;
            else if ($a == 4 && $h == 4)
                $ocoeff_array[10] = $c;
            else if ($a == 4 && $h == 5)
                $ocoeff_array[11] = $c;
            else if ($a == 3 && $h == 0)
                $ocoeff_array[12] = $c;
            else if ($a == 3 && $h == 1)
                $ocoeff_array[13] = $c;
            else if ($a == 3 && $h == 2)
                $ocoeff_array[14] = $c;
            else if ($a == 3 && $h == 3)
                $ocoeff_array[15] = $c;
            else if ($a == 3 && $h == 4)
                $ocoeff_array[16] = $c;
            else if ($a == 3 && $h == 5)
                $ocoeff_array[17] = $c;
            else if ($a == 2 && $h == 0)
                $ocoeff_array[18] = $c;
            else if ($a == 2 && $h == 1)
                $ocoeff_array[19] = $c;
            else if ($a == 2 && $h == 2)
                $ocoeff_array[20] = $c;
            else if ($a == 2 && $h == 3)
                $ocoeff_array[21] = $c;
            else if ($a == 2 && $h == 4)
                $ocoeff_array[22] = $c;
            else if ($a == 2 && $h == 5)
                $ocoeff_array[23] = $c;
            else if ($a == 1 && $h == 0)
                $ocoeff_array[24] = $c;
            else if ($a == 1 && $h == 1)
                $ocoeff_array[25] = $c;
            else if ($a == 1 && $h == 2)
                $ocoeff_array[26] = $c;
            else if ($a == 1 && $h == 3)
                $ocoeff_array[27] = $c;
            else if ($a == 1 && $h == 4)
                $ocoeff_array[28] = $c;
            else if ($a == 1 && $h == 5)
                $ocoeff_array[29] = $c;
            else if ($a == 0 && $h == 0)
                $ocoeff_array[30] = $c;
            else if ($a == 0 && $h == 1)
                $ocoeff_array[31] = $c;
            else if ($a == 0 && $h == 2)
                $ocoeff_array[32] = $c;
            else if ($a == 0 && $h == 3)
                $ocoeff_array[33] = $c;
            else if ($a == 0 && $h == 4)
                $ocoeff_array[34] = $c;
            else if ($a == 0 && $h == 5)
                $ocoeff_array[35] = $c;
            else
            {
            //// echo "a or h pow greater then 3 or negative";
                return FALSE;
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != 0)
            {
                $coeff = $ocoeff_array[$j];
                if ($j == 0 && $coeff == 1)
                    $coeff = "";
                else if ($j == 0 && $coeff == -1)
                    $coeff = "-";
                if ($j > 0 && $j != 30)
                    coeff_prep($coeff);
                if ($j == 30)
                    coeff_prep($coeff,0);
                if ($j == 0)
                    $answer = $coeff."a^(5) ";
                else if ($j == 1)
                    $answer = $answer.$coeff."a^(5)h ";
                else if ($j == 2)
                    $answer = $answer.$coeff."a^(5)h^(2) ";
                else if ($j == 3)
                    $answer = $answer.$coeff."a^(5)h^(3) ";
                else if ($j == 4)
                    $answer = $answer.$coeff."a^(5)h^(4) ";
                else if ($j == 5)
                    $answer = $answer.$coeff."a^(5)h^(5) ";
                else if ($j == 6)
                    $answer = $answer.$coeff."a^(4) ";
                else if ($j == 7)
                    $answer = $answer.$coeff."a^(4)h ";
                else if ($j == 8)
                    $answer = $answer.$coeff."a^(4)h^(2) ";
                else if ($j == 9)
                    $answer = $answer.$coeff."a^(4)h^(3) ";
                else if ($j == 10)
                    $answer = $answer.$coeff."a^(4)h^(4) ";
                else if ($j == 11)
                    $answer = $answer.$coeff."a^(4)h^(5) ";
                else if ($j == 12)
                    $answer = $answer.$coeff."a^(3) ";
                else if ($j == 13)
                    $answer = $answer.$coeff."a^(3)h ";
                else if ($j == 14)
                    $answer = $answer.$coeff."a^(3)h^(2) ";
                else if ($j == 15)
                    $answer = $answer.$coeff."a^(3)h^(3) ";
                else if ($j == 16)
                    $answer = $answer.$coeff."a^(3)h^(4) ";
                else if ($j == 17)
                    $answer = $answer.$coeff."a^(3)h^(5) ";
                else if ($j == 18)
                    $answer = $answer.$coeff."a^(2) ";
                else if ($j == 19)
                    $answer = $answer.$coeff."a^(2)h ";
                else if ($j == 20)
                    $answer = $answer.$coeff."a^(2)h^(2) ";
                else if ($j == 21)
                    $answer = $answer.$coeff."a^(2)h^(3) ";
                else if ($j == 22)
                    $answer = $answer.$coeff."a^(2)h^(4) ";
                else if ($j == 23)
                    $answer = $answer.$coeff."a^(2)h^(5) ";
                else if ($j == 24)
                    $answer = $answer.$coeff."a ";
                else if ($j == 25)
                    $answer = $answer.$coeff."ah ";
                else if ($j == 26)
                    $answer = $answer.$coeff."ah^(2) ";
                else if ($j == 27)
                    $answer = $answer.$coeff."ah^(3) ";
                else if ($j == 28)
                    $answer = $answer.$coeff."ah^(4) ";
                else if ($j == 29)
                    $answer = $answer.$coeff."ah^(5) ";
                else if ($j == 30)
                    $answer = $answer.$coeff;
                else if ($j == 31)
                    $answer = $answer.$coeff."h";
                else if ($j == 32)
                    $answer = $answer.$coeff."h^(2) ";
                else if ($j == 33)
                    $answer = $answer.$coeff."h^(3) ";
                else if ($j == 34)
                    $answer = $answer.$coeff."h^(4) ";
                else // ($j == 35)
                    $answer = $answer.$coeff."h^(5) ";
            }
        }
        $temp_length = strlen($answer);
        $temp_string = "";
        for ($j = 0; $j < $temp_length; $j++)
        {
            $char = substr($answer,$j,1);
            if ($j == 0)
            {
                if ($char == '+')
                {
                //// do nothing
                }
                else
                    $temp_string = $temp_string.$char;
            }
            else
                $temp_string = $temp_string.$char;
        }
        $answer = $temp_string;
        return $answer;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             X is not equal to                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else if ($type == 28)
    {
        $my_array = explode(',',$my_string);
        $answer = $my_array;
        return $answer;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Polynomial in x to a power               ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else if ($type == 29)
    {
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        if ($char_array[0] != '(')
        {
            $my_string = parse_input($my_string,3);
            return $my_string;
        }
        else
        {
            $my_array = explode('^',$my_string);
            $my_array[0] = parse_input($my_array[0],3);
            $my_array[1] = parse_input($my_array[1],3);
            $return_string = "(".$my_array[0].")^(".$my_array[1].")";
            return $return_string;
        }
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////        sqrt of a polynomial in x                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else if ($type == 30)
    {
        $new_string = "";
        for ($j = 0 ; $j < $length ; $j++)
        {
            $char_array[]=substr($my_string,$j,1);
        }
        if ($char_array[0] != 's' && $char_array[0] != 'c')
        {
           $my_string = parse_input($my_string,3);
           return $my_string;
        }
        else
        {
            for ($j = 4; $j < $length; $j++)
            {
                $new_string .= $char_array[$j];
            }
            $new_string = parse_input($new_string,3);
            if ($char_array[0] == 's')
            {
                $return_string = "sqrt(".$new_string.")";
            }
            else
            {
                $return_string = "cbrt(".$new_string.")";
            }
            return $return_string;
        }
    }
    else if ($type == 31)
    {
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    ////
    ////    polynomial in l
    ////    returns false if there are negative exponents
    ////    returns false if there are two terms with the
    ////    same power
    ////
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    $max_pow++;
    //// initialize the input coeff array
    $icoeff_array = array();
    for ($i = 0; $i < $max_pow; $i++)
    {
        $icoeff_array[] = "0";
    }
    //// initialize the output coeff array
    $ocoeff_array = array();
    for ($i = 0; $i < $max_pow; $i++)
    {
        $ocoeff_array[] = "0";
    }
    //// initialize the pow array
    //// pow_array[i] = pow of variable corrisponding to icoeff_array[i]
    $pow_array = array();
    for ($i =0; $i < $max_pow; $i++)
    {
        $pow_array[] = 0;
    }
    $char_array = array();
    $sub_array = array();
    $temp_string = "";
    $char_array[0] = ' ';
    $num_sub = 0;
    for ($j = 0 ; $j < $length ; $j++)
    {
        $char_array[]=substr($my_string,$j,1);
    }
    for ($j = 1; $j <= $length; $j++)
    {
        $char = $char_array[$j];
        if ($char == '+')
        {
                $sub_array[] = $temp_string;
            $j++;
            $char = $char_array[$j];
            $temp_string = "";
            $num_sub++;
        }
        if ($char == '-' && $char_array[$j-1] != '^' && $char_array[$j-1] != '(' && $j != 1)
        {
            $sub_array[] = $temp_string;
            $temp_string = "";
            $num_sub++;
        }
        $temp_string = $temp_string.$char;
    }
    $sub_array[] = $temp_string;
    $temp_string = "";
    $num_sub++;
    $i = 0;
    if ($debug == TRUE)
    {
        while ($sub_array[$i] != "NULL")
        {
            echo "<br /> sub_array $i is $sub_array[$i]";
            $i++;
        }
    }
    $i = 0;
    for ($j = 0; $j < $num_sub; $j++)
    {
        $has_a_var = FALSE;
        $temp_string = $sub_array[$j];
        $temp_length = strlen($temp_string);
        $tchar_array = array();
        for ($i = 0; $i < $temp_length; $i++)
        {
            $tchar_array[] = substr($temp_string,$i,1);
        }
        for ($i = 0; $i < $temp_length; $i++)
        {
            if ($tchar_array[$i] == 'l')
            {
                $has_a_var = TRUE;
            }
        }
        if ($has_a_var == FALSE)
        {
            $temp_string = str_replace('(','',$temp_string);
            $temp_string = str_replace(')','',$temp_string);
            $icoeff_array[$j] = $temp_string;
            $pow_array[$j] = 0;
        }
        else //// the substring includes a variable
        {
            if ($tchar_array[0] == 'l')
            {
            $has_open_par = FALSE;
            $has_closed_par = FALSE;
            $has_multi = FALSE;
            $has_power = FALSE;
            for ($i = 0; $i < $temp_length; $i++)
            {
                    if ($tchar_array[$i] == '*')
            $has_multi = TRUE;
            if ($tchar_array[$i] == '(')
                $has_open_par = TRUE;
            if ($tchar_array[$i] == ')')
                $has_closed_par = TRUE;
            if ($tchar_array[$i] == '^')
                $has_power = TRUE;
               }
            if ($has_multi == TRUE)
            {
                $temp_array = explode('*',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                $temp_array[$i] = str_replace('l','',$temp_array[$i]);
                $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                         $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                        $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                        }
                        if ($temp_array[0] == NULL)
                            $pow_array[$j] = 1;
                        else
                            $pow_array[$j] = $temp_array[0];
                        $icoeff_array[$j] = $temp_array[1];
            }
            else if ($has_open_par == TRUE && $has_closed_par == TRUE)
            {
                $temp_string = str_replace('l','',$temp_string);
                if ($has_power == FALSE)
                {
                $temp_string = str_replace('(','',$temp_string);
                    $temp_string = str_replace(')','',$temp_string);
                $pow_array[$j] = 1;
                $icoeff_array[$j] = $temp_string;
                }
                else
                {
                    $temp_string = str_replace('^','',$temp_string);
                    $temp_array = explode(')',$temp_string);
                    if ($temp_array[1] != "")
                    {
                    for ($i = 0; $i < 2; $i++)
                        $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $pow_array[$j] = $temp_array[0];
                    $icoeff_array[$j] = $temp_array[1];
                    }
                    else
                    {
                        $temp_array = explode('(',$temp_array[0]);
                    if ($temp_array[0] == "")
                    {
                            $pow_array[$j] = $temp_array[1];
                    $icoeff_array[$j] = 1;
                }
                else
                {
                    $pow_array[$j] = $temp_array[0];
                    $icoeff_array[$j] = $temp_array[1];
                }
                    }
                }
                }
            else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                return FALSE;
            else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                return FALSE;
            else
            {
                if ($has_power == FALSE)
                {
                    $pow_array[$j] = 1;
                    $temp_string = str_replace('l','',$temp_string);
                    if ($temp_string == "")
                        $icoeff_array[$j] = 1;
                    else if ($temp_string == "-")
                        $icoeff_array[$j] = -1;
                    else
                        $icoeff_array[$j] = $temp_string;
                }
                else
                {
                $temp_string = str_replace('l','',$temp_string);
                    $temp_string = str_replace('^','',$temp_string);
                    $pow_array[$j] = $temp_string;
                    $icoeff_array[$j] = 1;
                }
            }
            }
            else if ($tchar_array[0] == '-')
            {
            if ($tchar_array[1] != 'l')
            {
                    $temp_array = explode('l',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    if ($temp_array[$i] == NULL)
                        break;
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                $icoeff_array[$j] = $temp_array[0];
                if ($temp_array[1] == NULL)
                    $pow_array[$j] = 1;
                else
                    $pow_array[$j] = $temp_array[1];
            }
            else
            {
                $tchar_array[0] = '';
                $temp_string = "";
                for ($i = 1; $i < $temp_length; $i++)
                    $temp_string = $temp_string.$tchar_array[$i];
                $has_open_par = FALSE;
                $has_closed_par = FALSE;
                $has_multi = FALSE;
                $has_power = FALSE;
                for ($i = 0; $i < $temp_length; $i++)
                {
                    if ($tchar_array[$i] == '*')
                        $has_multi = TRUE;
                    if ($tchar_array[$i] == '(')
                        $has_open_par = TRUE;
                    if ($tchar_array[$i] == ')')
                        $has_closed_par = TRUE;
                    if ($tchar_array[$i] == '^')
                        $has_power = TRUE;
                }
                if ($has_multi == TRUE)
                {
                    $temp_array = explode('*',$temp_string);
                    for ($i = 0; $i < 2; $i++)
                    {
                    $temp_array[$i] = str_replace('l','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                             $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                            $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                            }
                            if ($temp_array[0] == NULL)
                                $pow_array[$j] = 1;
                            else
                                $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                            $temp_length = strlen($temp_array[1]);
                            for ($i = 0; $i < $temp_length; $i++)
                                $tchar_array2[] = substr($temp_array[1],$i,1);
                            $temp_string = "";
                            if ($tchar_array2[0] == '-')
                            {
                            for ($i = 1; $i < $temp_length; $i++)
                                $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            else
                            {
                            $temp_string = "-";
                            for ($i = 0; $i < $temp_length; $i++)
                                $temp_string = $temp_string.$tchar_array2[$i];
                            }
                            $icoeff_array[$j] = $temp_string;
                }
            else if ($has_open_par == TRUE && $has_closed_par == TRUE)
            {
                $temp_string = str_replace('l','',$temp_string);
                if ($has_power == FALSE)
                {
                    $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                $pow_array[$j] = 1;
                $tchar_array2 = array();
                                $temp_length = strlen($temp_string);
                                for ($i = 0; $i < $temp_length; $i++)
                                    $tchar_array2[] = substr($temp_string,$i,1);
                                $temp_string2 = "";
                                if ($tchar_array2[0] == '-')
                                {
                                for ($i = 1; $i < $temp_length; $i++)
                                    $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                else
                                {
                                $temp_string2 = "-";
                                for ($i = 0; $i < $temp_length; $i++)
                                    $temp_string2 = $temp_string2.$tchar_array2[$i];
                                }
                                $icoeff_array[$j] = $temp_string2;
                }
                else
                {
                    $temp_string = str_replace('^','',$temp_string);
                    $temp_array = explode(')',$temp_string);
                    if ($temp_array[1] != "")
                    {
                        for ($i = 0; $i < 2; $i++)
                            $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                        $pow_array[$j] = $temp_array[0];
                        $tchar_array2 = array();
                                    $temp_length = strlen($temp_array[1]);
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $tchar_array2[] = substr($temp_array[1],$i,1);
                                    $temp_string = "";
                                    if ($tchar_array2[0] == '-')
                                    {
                                    for ($i = 1; $i < $temp_length; $i++)
                                        $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    else
                                    {
                                    $temp_string = "-";
                                    for ($i = 0; $i < $temp_length; $i++)
                                        $temp_string = $temp_string.$tchar_array2[$i];
                                    }
                                    $icoeff_array[$j] = $temp_string;
                    }
                    else
                    {
                        $temp_array = explode('(',$temp_array[0]);
                        if ($temp_array[0] == "")
                        {
                            $pow_array[$j] = $temp_array[1];
                            $icoeff_array[$j] = -1;
                        }
                        else
                        {
                            $pow_array[$j] = $temp_array[0];
                            $tchar_array2 = array();
                                        $temp_length = strlen($temp_array[1]);
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $tchar_array2[] = substr($temp_array[1],$i,1);
                                        $temp_string = "";
                                        if ($tchar_array2[0] == '-')
                                        {
                                        for ($i = 1; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        else
                                        {
                                        $temp_string = "-";
                                        for ($i = 0; $i < $temp_length; $i++)
                                            $temp_string = $temp_string.$tchar_array2[$i];
                                        }
                                        $icoeff_array[$j] = $temp_string;
                            }
                        }
                            }
                        }
                        else if ($has_open_par == TRUE && $has_closed_par == FALSE)
                    {
                        ////echo $j;
                        ////echo "open but not closed";
                        return FALSE;
                    }
                    else if ($has_open_par == FALSE && $has_closed_par == TRUE)
                    {
                        ////echo $j;
                        ////echo "closed but not open";
                        return FALSE;
                    }
                    else
                    {
                        if ($has_power == FALSE)
                        {
                            $pow_array[$j] = 1;
                            $temp_string = str_replace('l','',$temp_string);
                            if ($temp_string == "")
                                $icoeff_array[$j] = -1;
                            else if ($temp_string == "-")
                                $icoeff_array[$j] = 1;
                            else
                                $icoeff_array[$j] = "-".$temp_string;
                        }
                        else
                        {
                            $temp_string = str_replace('^','',$temp_string);
                            $pow_array[$j] = $temp_string;
                            $icoeff_array[$j] = -1;
                        }
                    }
                    }
                }
                else if ($tchar_array[0] == '(')
                {
                    //// checks to make sure the number of open ('s = num of closed )'s
                    $num_open = 0;
                    $num_closed = 0;
                    for ($i = 0; $i < $temp_length; $i++)
                    {
                    if ($tchar_array[$i] == '(')
                        $num_closed++;
                    if ($tchar_array[$i] == ')')
                        $num_open++;
                    }
                    if ($num_open != $num_closed)
                    {
                    ////echo "open ('s not equal to closed )'s";
                        return FALSE;
                    }
                    //// replaces ")(" with '*'
                    for ($i = 1; $i < $temp_length; $i++)
                    {
                    if ($tchar_array[$i] == '(' && $tchar_array[$i-1] != '^' && $tchar_array[$i-1] != '(')
                            $tchar_array[$i] = '*';
                }
                $temp_string = "";
                for ($i = 0; $i < $temp_length; $i++)
                    $temp_string = $temp_string.$tchar_array[$i];
                $temp_string = str_replace('(','',$temp_string);
                $temp_string = str_replace(')','',$temp_string);
                //// puts it in nice form
                $temp_string = parse_input($temp_string,3);
                $temp_array = explode('l',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    if ($temp_array[$i] == NULL)
                        break;
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                $icoeff_array[$j] = $temp_array[0];
                if ($temp_array[1] == NULL)
                    $pow_array[$j] = 1;
                else
                    $pow_array[$j] = $temp_array[1];
                }
                else
                {
                $temp_array = explode('l',$temp_string);
                for ($i = 0; $i < 2; $i++)
                {
                    if ($temp_array[$i] == NULL)
                        break;
                    $temp_array[$i] = str_replace('(','',$temp_array[$i]);
                    $temp_array[$i] = str_replace(')','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('^','',$temp_array[$i]);
                    $temp_array[$i] = str_replace('*','',$temp_array[$i]);
                }
                $icoeff_array[$j] = $temp_array[0];
                if ($temp_array[1] == NULL)
                    $pow_array[$j] = 1;
                else
                    $pow_array[$j] = $temp_array[1];
                }
            }
        }
        for ($j=0; $j<$num_sub; $j++)
    {
        $temp = (int)$pow_array[$j];
        if ($temp < 0)
        {
            ////echo "negative power";
            return FALSE;
        }
        if ($ocoeff_array[$temp] != 0 && $ocoeff_array[$temp] != NULL)
        {
            ////echo "two powers the same";
        return FALSE;
        }
            if ($icoeff_array[$j] != "0")
                $ocoeff_array[$pow_array[$j]] = $icoeff_array[$j];
        }
        for ($j=0;$j < $max_pow ;$j++)
        {
        if ($j == 0)
        {
                if ($ocoeff_array[$j] != "0")
                coeff_prep($ocoeff_array[$j],0);
        }
            else
        {
            if ($ocoeff_array[$j] != "0")
                    coeff_prep($ocoeff_array[$j]);
            }
        }
        $answer = "";
        for ($j = 0; $j < $max_pow; $j++)
        {
            if ($ocoeff_array[$j] != "0" )
            {
                if ($j == 0)
                    $answer = $ocoeff_array[$j];
                else if ($j == 1)
                    $answer = $ocoeff_array[$j]."l ".$answer;
                else
                    $answer = $ocoeff_array[$j]."l^($j) ".$answer;
            }
        }
        $answer = trim($answer);
        $temp_string = $answer;
        $temp_length = strlen($temp_string);
        $tchar_array1 = array();
        for ($j = 0; $j < $temp_length; $j++)
        {
             $tchar_array1[] = substr($temp_string,$j,1);
        }
        $temp_string = "";
        if ($tchar_array1[0] == '+')
        {
            for ($j = 1; $j < $temp_length; $j++)
                $temp_string = $temp_string.$tchar_array1[$j];
            $answer = $temp_string;
        }
        $answer = str_replace('l','L',$answer);
        return $answer;
    }
    else if ($type == 32)
    {
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    ////
    ////    Two factors in L
    ////
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    $char_array = array();
    $sub_array = array();
    $num_sub = 0;
    $temp_string = "";
    $num_sub = 0;
        $open_paranth = FALSE;
        $num_paranth = 0;

    for ($j = 0 ; $j < $length ; $j++)
        {
        $char_array[]=substr($my_string,$j,1);
        }


        for ($j = 0; $j < $length; $j++)
        {
            $temp_char = $char_array[$j];

            if ($temp_char != '' && $temp_char != ' ')
            {

                if ($temp_char == '(' && $open_paranth == FALSE)
                {
                    $open_paranth = TRUE;
                    $num_paranth++;
                    if ($temp_string != " " && $temp_string != "")
                    {
                        $sub_array[] = $temp_string;
                        $num_sub++;
                        $temp_string = "";
                    }
                }
                if ($temp_char == ')')
                {
                    $num_paranth--;
                    if ($num_paranth == 0)
                    {
                        $open_paranth = FALSE;
                        if ($temp_string != "" && $temp_string != "")
                        {
                            $temp_string .= $temp_char;
                            $j++;
                            $temp_char = $char_array[$j];
                            if ($temp_char == '(')
                            {
                                $open_paranth = TRUE;
                                $num_paranth++;
                            }
                            $sub_array[] = $temp_string;
                            $num_sub++;
                            $temp_string = "";
                        }
                    }
                }
                if ($temp_char == '+' || $temp_char == '-')
                {
                    if ($open_paranth == FALSE)
                    {
                        if ($temp_string != " " && $temp_string != "")
                        {
                            $sub_array[] = $temp_string;
                            $num_sub++;
                            $temp_string = "";
                        }
                    }
                }

                $temp_string .= $temp_char;
            }
        }
        if ($temp_string != '' && $temp_string != ' ')
        {
            $num_sub++;
            $sub_array[] = $temp_string;
        }

        $answer = "";
        $split = "@";

        for ($i = 0; $i < $num_sub; $i++)
        {
            $sub_array[$i] = parse_input($sub_array[$i],31);
            $answer .=  $sub_array[$i];
            if ($sub_array[$i] != "")
            {
                $answer .= $split;
            }
        }

        return $answer;
    }
    else
        return FALSE;
}

function parse_interval_answer($ai_array)
{
    $a_string = "";

    $num = $ai_array[1];
    if (strlen($num))
    {
        $left_bound = $ai_array[0];
        if ($left_bound == 0)
            $left_bound = "(";
        else
            $left_bound = "[";

        $right_bound = $ai_array[5];
        if ($right_bound == 0)
            $right_bound = ")";
        else
            $right_bound = "]";

        $left_denom = $ai_array[2];
        if ($left_denom == 1 || $left_denom == NULL)
            $left_denom = "";
        else
            $left_denom = " / $left_denom";

        $right_denom = $ai_array[4];
        if ($right_denom == 1 || $right_denom == NULL)
            $right_denom = "";
        else
            $right_denom = " / $right_denom";

        $left_num = $ai_array[1];
        $left_num = trim($left_num);
        $left_num = strtolower($left_num);

        $right_num = $ai_array[3];
        $right_num = trim($right_num);
        $right_num = strtolower($right_num);

        $a_string .= "$left_bound $left_num $left_denom , ";
        $a_string .= "$right_num $right_denom $right_bound";
    }
    else
    {
        $num = $ai_array[7];
        if (!strlen($num))
            return "";
        $left1_bound = $ai_array[6];
        if ($left1_bound == 0)
            $left1_bound = "(";
        else
            $left1_bound = "[";

        $right1_bound = $ai_array[11];
        if ($right1_bound == 0)
            $right1_bound = ")";
        else
            $right1_bound = "]";

        $left1_denom = $ai_array[8];
        if ($left1_denom == 1 || $left1_denom == NULL)
            $left1_denom = "";
        else
            $left1_denom = " / $left1_denom";

        $right1_denom = $ai_array[10];
        if ($right1_denom == 1 || $right1_denom == NULL)
            $right1_denom = "";
        else
            $right1_denom = " / $right1_denom";

        $left1_num = $ai_array[7];
        $left1_num = trim($left1_num);
        $left1_num = strtolower($left1_num);

        $right1_num = $ai_array[9];
        $right1_num = trim($right1_num);
        $right1_num = strtolower($right1_num);

        $left2_bound = $ai_array[12];
        if ($left2_bound == 0)
            $left2_bound = "(";
        else
            $left2_bound = "[";

        $right2_bound = $ai_array[17];
        if ($right2_bound == 0)
            $right2_bound = ")";
        else
            $right2_bound = "]";

        $left2_denom = $ai_array[14];
        if ($left2_denom == 1 || $left2_denom == NULL)
            $left2_denom = "";
        else
            $left2_denom = " / $left2_denom";

        $right2_denom = $ai_array[16];
        if ($right2_denom == 1 || $right2_denom == NULL)
            $righ2t_denom = "";
        else
            $right2_denom = " / $right2_denom";

        $left2_num = $ai_array[13];
        $left2_num = trim($left2_num);
        $left2_num = strtolower($left2_num);

        $right2_num = $ai_array[15];
        $right2_num = trim($right2_num);
        $right2_num = strtolower($right2_num);

        $a_string .= "$left1_bound $left1_num $left1_denom , $right1_num $right1_denom $right1_bound";
        $a_string .= " <font face=arial>U</font> ";
        $a_string .= "$left2_bound $left2_num $left2_denom , $right2_num $right2_denom $right2_bound";
        $a_string = trim($a_string);
    }
    return $a_string;
}

function parse_domain_answer($a_array)
{
    $a_string = "";

    $num = $a_array[1];
    if (strlen($num))
    {
        $left_bound = $a_array[0];
        if ($left_bound == 0)
            $left_bound = "(";
        else
            $left_bound = "[";

        $right_bound = $a_array[5];
        if ($right_bound == 0)
            $right_bound = ")";
        else
            $right_bound = "]";

        $left_denom = $a_array[2];
        if ($left_denom == 1 || $left_denom == NULL)
            $left_denom = "";
        else
            $left_denom = " / $left_denom";

        $right_denom = $a_array[4];
        if ($right_denom == 1 || $right_denom == NULL)
            $right_denom = "";
        else
            $right_denom = " / $right_denom";

        $left_num = $a_array[1];
        $left_num = trim($left_num);
        $left_num = strtolower($left_num);

        $right_num = $a_array[3];
        $right_num = trim($right_num);
        $right_num = strtolower($right_num);

        $a_string .= "$left_bound $left_num $left_denom , $right_num $right_denom $right_bound";
    }
    return $a_string;
}

function parse_domain_answer_output($num,$denom)
{
        $num =  str_replace('inf','&#8734;',$num);
        $a_out = "<table border=0 cellspacing=2 cellpadding=0 align='center'>\n";
        $a_out .= "<tr><td>x is in $num</td>";
        if ($denom != "not_used")
        {
            $a_out .= "<td> and </td><td> x &#8800; $denom</td>\n";
        }
        $a_out .= "</tr></table>";
        return $a_out;
}

function parse_inequality_output($num)
{
    $num = str_replace('inf', '&#8734',$num);
    $num = str_to_math($num);
    $a_out = "<center>".$num."</center>";
    return $a_out ;
}

function parse_linear_equation_answer_input($a_array)
{
    $a_string    = "";
    $split       = '@';
    $slope_num   = $a_array[0];
    $slope_denom = $a_array[1];
    $yint_num    = $a_array[2];
    $yint_denom  = $a_array[3];
    $y_num       = $a_array[4];
    $y_denom     = $a_array[5];
    $x_num       = $a_array[6];
    $x_denom     = $a_array[7];
    if (strlen($slope_num))
    {
        $a_string .= $slope_num.$split;
    }
    else
    {
        $a_string .= "not_used".$split;
    }
    if (strlen($slope_denom))
    {
        $a_string .= $slope_denom.$split;
    }
    else
    {
        $a_string .= "1".$split;
    }
    if (strlen($yint_num))
    {
        $a_string .= $yint_num.$split;
    }
    else
    {
        $a_string .= "not_used".$split;
    }
    if (strlen($yint_denom))
    {
        $a_string .= $yint_denom.$split;
    }
    else
    {
        $a_string .= "1".$split;
    }
    if (strlen($y_num))
    {
        $a_string .= $y_num.$split;
    }
    else
    {
        $a_string .= "not_used".$split;
    }
    if (strlen($y_denom))
    {
        $a_string .= $y_denom.$split;
    }
    else
    {
        $a_string .= "1".$split;
    }
    if (strlen($x_num))
    {
        $a_string .= $x_num.$split;
    }
    else
    {
        $a_string .= "not_used".$split;
    }
    if (strlen($x_denom))
    {
        $a_string .= $x_denom.$split;
    }
    else
    {
        $a_string .= "1".$split;
    }
    if ($a_string == "not_used@1@not_used@1@not_used@1@not_used@1@")
    {
        return "";
    }
    else
    {
        return $a_string;
    }
}

function parse_linear_equation_answer($my_string)
{
    $answer = "<center>";
    $answer .= "<table border='0' cellspacing='0' cellpadding='1'>";
    $answer .= "<tr><td align='center'>";
    $a_array = explode('@',$my_string);
    $slope_num = $a_array[0];
    $slope_denom = $a_array[1];
    $yint_num = $a_array[2];
    $yint_denom = $a_array[3];
    $y_num = $a_array[4];
    $y_denom = $a_array[5];
    $x_num = $a_array[6];
    $x_denom = $a_array[7];
    if ($x_num != "not_used")
    {
        if ($x_denom == 1)
        {
            $answer .= "x = ".$x_num;
        }
        else
        {
            $answer .= "x = </td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$x_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$x_denom</td></tr>";
            $answer .= "</table>";
        }
    }
    else if ($y_num != "not_used")
    {
        if ($y_denom == 1)
        {
            $answer .= "y = ".$y_num;
        }
        else
        {
            $answer .= "y = </td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$y_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$y_denom</td></tr>";
            $answer .= "</table>";
        }
    }
    else
    {
        $answer .= "y = </td><td>";
        if ($slope_denom == 1)
        {
            if ($slope_num == 1)
            {
                $answer .= "";
            }
            else if ($slope_num == -1)
            {
                $answer .= "-";
            }
            else
            {
                $answer .= "( ".$slope_num." )";
            }
        }
        else
        {
            $answer .= "<font size=6>( </font></td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$slope_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$slope_denom</td></tr>";
            $answer .= "</table>";
            $answer .= "</td><td><font size=6> )</font>";
        }
        $answer .= "</td><td> x";
        if ($yint_denom == 1)
        {
            if ($yint_num == 0)
            {
                $answer .= "";
            }
            else
            {
                $answer .= " + </td><td>";
                $answer .= "( ".$yint_num." )";
            }
        }
        else
        {
            $answer .= " + </td><td>";
            $answer .= "<font size=6>( </font></td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$yint_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$yint_denom</td></tr>";
            $answer .= "</table>";
            $answer .= "</td><td><font size=6> )</font>";
        }
    }

    $answer .= "</td></tr></table></center>\n";
    return $answer;
}

function parse_linear_equation_reform_answer($my_string,$x_var,$y_var)
{
    $answer = "<center>";
    $answer .= "<table border='0' cellspacing='0' cellpadding='1'>";
    $answer .= "<tr><td align='center'>";
    $a_array = explode('@',$my_string);
    $slope_num = $a_array[0];
    $slope_denom = $a_array[1];
    $yint_num = $a_array[2];
    $yint_denom = $a_array[3];
    $y_num = $a_array[4];
    $y_denom = $a_array[5];
    $x_num = $a_array[6];
    $x_denom = $a_array[7];
    if ($x_num != "not_used")
    {
        if ($x_denom == 1)
        {
            $answer .= "$x_var = ".$x_num;
        }
        else
        {
            $answer .= "$x_var = </td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$x_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=18 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$x_denom</td></tr>";
            $answer .= "</table>";
        }
    }
    else if ($y_num != "not_used")
    {
        if ($y_denom == 1)
        {
            $answer .= "$y_var = ".$y_num;
        }
        else
        {
            $answer .= "$y_var = </td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$y_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=18 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$y_denom</td></tr>";
            $answer .= "</table>";
        }
    }
    else
    {
        $answer .= "$y_var = </td><td>";
        if ($slope_denom == 1)
        {
            if ($slope_num == 1)
            {
                $answer .= "";
            }
            else if ($slope_num == -1)
            {
                $answer .= "-";
            }
            else
            {
                $answer .= "( ".$slope_num." )";
            }
        }
        else
        {
            $answer .= "<font size=6>( </font></td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$slope_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=18 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$slope_denom</td></tr>";
            $answer .= "</table>";
            $answer .= "</td><td><font size=6> )</font>";
        }
        $answer .= "</td><td> $x_var";
        if ($yint_denom == 1)
        {
            if ($yint_num == 0)
            {
                $answer .= "";
            }
            else
            {
                $answer .= " + </td><td>";
                $answer .= "( ".$yint_num." )";
            }
        }
        else
        {
            $answer .= " + </td><td>";
            $answer .= "<font size=6>( </font></td><td>";
            $answer .= "<table border=0 cellspacing=0 cellpadding=1>";
            $answer .= "<tr><td align='center'>$yint_num</td></tr>";
            $answer .= "<tr><td align='center'>";
            $answer .= "<span class='midline'><img src='Images/1px.gif' width=18 height='1'></span>";
            $answer .= "</td></tr>";
            $answer .= "<tr><td align='center'>$yint_denom</td></tr>";
            $answer .= "</table>";
            $answer .= "</td><td><font size=6> )</font>";
        }
    }

    $answer .= "</td></tr></table></center>\n";
    return $answer;
}

function parse_compare_tax_answer($a_array)
{
    $num = $a_array[0];
    $answer = "";
    if ($num == 1)
    {
        $answer = "The Graduated Tax is Larger.";
    }
    else if ($num == 2)
    {
        $answer = "The Flat Tax is Larger.";
    }
    else if ($num == 3)
    {
        $answer = "The Taxes are Equal.";
    }

    return $answer;
}

function parse_tax_equation_answer($a_array)
{
    $low_tax  = $a_array[0];
    $bound1   = $a_array[1];
    $const1   = $a_array[2];
    $high_tax = $a_array[3];
    $const2   = $a_array[4];
    $bound2   = $a_array[5];
    if (!(strlen($low_tax)))
    {
        $answer = "";
    }
    else
    {
        $split = "@";
        $answer = $low_tax.$split.$bound1.$split.$const1.$split;
        $answer .= $high_tax.$split.$const2.$split.$bound2;
    }

    return $answer;
}

function parse_tax_equation_answer_output($my_string)
{
    $q_array = explode('@',$my_string);

    $r_string = "<table border='0' cellspacing='0' cellpadding='0' align='center'>\n";
    $r_string .= "<tr><td valign='center' rowspan=2><i>g</i>( <i>i</i> ) = </td>\n";
    $r_string .= "<td valign='center' rowspan=2><font size='7'>{</font></td>";
    $r_string .= "<td>".$q_array[0]." <i>i</i></td><td>for <i>i</i> <u>&#60;</u> $".$q_array[1];
    $r_string .= "</td></tr><tr><td>\n";
    $r_string .= $q_array[2]." + ".$q_array[3]."( <i>i</i> - ".$q_array[4]." )&nbsp;&nbsp;&nbsp;</td>\n";
    $r_string .= "<td> for <i>i</i> &#62 $".$q_array[5]."</td></tr></table>\n";

    return $r_string;
}

function parse_sci_answer_output($num,$denom)
{
    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    if ($denom != 0 && $denom != 1)
    {
        $out_string .= "$num * 10<sup>$denom</sup>";
    }
    else if ($denom == 1)
    {
        $out_string .= "$num * 10";
    }
    else
    {
        $out_string .= $num;
    }
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_common_log_form_answer_output($num,$denom)
{
    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    $out_string .= "log &nbsp;";
    $out_string .= $num;
    $out_string .= "&nbsp; = &nbsp;";
    $out_string .= $denom;
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_easy_exp_form_answer_output($num,$denom)
{
    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;
    if ($denom == 1E-6)
    {
        $denom = "0.000001";
    }
    else if ($denom == 1E-5)
    {
        $denom = "0.00001";
    }

    $out_string  = "<p><center>";
    $out_string .= "10<sup>";
    $out_string .= $num;
    $out_string .= "</sup>&nbsp; = &nbsp;";
    $out_string .= $denom;
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_initial_pop_form_answer_output($num,$denom)
{
    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    $out_string .= "Initial Population: &nbsp;";
    $out_string .= $num;
    $out_string .= "&nbsp;&nbsp;&nbsp; Growth Rate:";
    $out_string .= $denom;
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_growth_rate_percent_form_answer_output($num)
{
    $num = str_replace(' ','',$num);
    $num = $num + 0;

    $out_string  = "<p><center>";
    $out_string .= $num;
    $out_string .= "&nbsp; % ";
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_growth_vs_decay_answer($num)
{
    $answer = "<p><center>";
    if ($num == 1)
    {
        $answer .= "The equation represents growth.";
    }
    else // ($num == 2)
    {
        $answer .= "The equation represents decay.";
    }
    $answer .= "</center></p>";
    return $answer;
}

function parse_exp_equation_answer($num,$denom)
{

    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    $out_string .= "P(t) = &nbsp;";
    $out_string .= $num;
    $out_string .= " * (";
    $out_string .= $denom;
    $out_string .= ")<sup>t</sup></center></p>";

    return $out_string;

}

function parse_compare_salary_answer($num)
{
    $answer = "<p><center>";
    if ($num == 1)
    {
        $answer .= "Job A";
    }
    else if ($num == 2)
    {
        $answer .= "Job B";
    }
    else // ($num == 3)
    {
        $answer .= "They would pay the same";
    }
    $answer .= "</center></p>";
    return $answer;
}

function parse_growth_type_answer($num)
{
    $answer = "<p><center>";
    if ($num == 1)
    {
        $answer .= "Linear Growth";
    }
    else if ($num == 2)
    {
        $answer .= "Linear Decay";
    }
    else if ($num == 3)
    {
        $answer .= "Exponential Growth";
    }
    else // ($num == 4)
    {
        $answer .= "Exponential Decay";
    }
    $answer .= "</center></p>";
    return $answer;
}

function parse_exp_equation_2_answer($num,$denom)
{

    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    $out_string .= "A(t) = &nbsp;";
    $out_string .= $num;
    $out_string .= " * (";
    $out_string .= $denom;
    $out_string .= ")<sup>t</sup></center></p>";

    return $out_string;

}

function parse_expand_the_log_input($a_array)
{

    $coeff1_num    = $a_array[0];
    $coeff1_denom  = $a_array[1];
    $base1         = $a_array[2];
    $inside1_num   = $a_array[3];
    $inside1_denom = $a_array[4];

    $coeff2_num    = $a_array[5];
    $coeff2_denom  = $a_array[6];
    $base2         = $a_array[7];
    $inside2_num   = $a_array[8];
    $inside2_denom = $a_array[9];

    $coeff3_num    = $a_array[10];
    $coeff3_denom  = $a_array[11];
    $base3         = $a_array[12];
    $inside3_num   = $a_array[13];
    $inside3_denom = $a_array[14];

    $coeff4_num    = $a_array[15];
    $coeff4_denom  = $a_array[16];
    $base4         = $a_array[17];
    $inside4_num   = $a_array[18];
    $inside4_denom = $a_array[19];

    $coeff5_num    = $a_array[20];
    $coeff5_denom  = $a_array[21];
    $base5         = $a_array[22];
    $inside5_num   = $a_array[23];
    $inside5_denom = $a_array[24];

    $coeff6_num    = $a_array[25];
    $coeff6_denom  = $a_array[26];
    $base6         = $a_array[27];
    $inside6_num   = $a_array[28];
    $inside6_denom = $a_array[29];

    $split      = "@";
    $line_split = "#";

    $coeff1_num = str_replace(' ','',$coeff1_num);
    $coeff1_denom = str_replace(' ','',$coeff1_denom);
    $base1 = str_replace(' ','',$base1);
    $inside1_num = str_replace(' ','',$inside1_num);
    $inside1_denom = str_replace(' ','',$inside1_denom);

    $coeff2_num = str_replace(' ','',$coeff2_num);
    $coeff2_denom = str_replace(' ','',$coeff2_denom);
    $base2 = str_replace(' ','',$base2);
    $inside2_num = str_replace(' ','',$inside2_num);
    $inside2_denom = str_replace(' ','',$inside2_denom);

    $coeff3_num = str_replace(' ','',$coeff3_num);
    $coeff3_denom = str_replace(' ','',$coeff3_denom);
    $base3 = str_replace(' ','',$base3);
    $inside3_num = str_replace(' ','',$inside3_num);
    $inside3_denom = str_replace(' ','',$inside3_denom);

    $coeff4_num = str_replace(' ','',$coeff4_num);
    $coeff4_denom = str_replace(' ','',$coeff4_denom);
    $base4 = str_replace(' ','',$base4);
    $inside4_num = str_replace(' ','',$inside4_num);
    $inside4_denom = str_replace(' ','',$inside4_denom);

    $coeff5_num = str_replace(' ','',$coeff5_num);
    $coeff5_denom = str_replace(' ','',$coeff5_denom);
    $base5 = str_replace(' ','',$base5);
    $inside5_num = str_replace(' ','',$inside5_num);
    $inside5_denom = str_replace(' ','',$inside5_denom);

    $coeff6_num = str_replace(' ','',$coeff6_num);
    $coeff6_denom = str_replace(' ','',$coeff6_denom);
    $base6 = str_replace(' ','',$base6);
    $inside6_num = str_replace(' ','',$inside6_num);
    $inside6_denom = str_replace(' ','',$inside6_denom);

    $coeff1_num    = strtolower($coeff1_num);
    $coeff1_denom  = strtolower($coeff1_denom);
    $base1         = strtolower($base1);
    $inside1_num   = strtolower($inside1_num);
    $inside1_denom = strtolower($inside1_denom);

    $coeff2_num    = strtolower($coeff2_num);
    $coeff2_denom  = strtolower($coeff2_denom);
    $base2         = strtolower($base2);
    $inside2_num   = strtolower($inside2_num);
    $inside2_denom = strtolower($inside2_denom);

    $coeff3_num    = strtolower($coeff3_num);
    $coeff3_denom  = strtolower($coeff3_denom);
    $base3         = strtolower($base3);
    $inside3_num   = strtolower($inside3_num);
    $inside3_denom = strtolower($inside3_denom);

    $coeff4_num    = strtolower($coeff4_num);
    $coeff4_denom  = strtolower($coeff4_denom);
    $base4         = strtolower($base4);
    $inside4_num   = strtolower($inside4_num);
    $inside4_denom = strtolower($inside4_denom);

    $coeff5_num    = strtolower($coeff5_num);
    $coeff5_denom  = strtolower($coeff5_denom);
    $base5         = strtolower($base5);
    $inside5_num   = strtolower($inside5_num);
    $inside5_denom = strtolower($inside5_denom);

    $coeff6_num    = strtolower($coeff6_num);
    $coeff6_denom  = strtolower($coeff6_denom);
    $base6         = strtolower($base6);
    $inside6_num   = strtolower($inside6_num);
    $inside6_denom = strtolower($inside6_denom);


    if (!strlen($inside1_num))
    {
        $inside1_num = "n/a";
        if (!strlen($coeff1_num))
        {
            $coeff1_num = "n/a";
        }
        if (!strlen($coeff1_denom))
        {
            $coeff1_denom = "n/a";
        }
        if (!strlen($base1))
        {
            $base1 = "n/a";
        }
        if (!strlen($inside1_denom))
        {
            $inside1_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff1_num))
        {
            $coeff1_num = "1";
        }
        if (!strlen($coeff1_denom))
        {
            $coeff1_denom = "1";
        }
        if (!strlen($base1))
        {
            $base1 = "1";
        }
        if (!strlen($inside1_denom))
        {
            $inside1_denom = "1";
        }
    }

    if (!strlen($inside2_num))
    {
        $inside2_num = "n/a";
        if (!strlen($coeff2_num))
        {
            $coeff2_num = "n/a";
        }
        if (!strlen($coeff2_denom))
        {
            $coeff2_denom = "n/a";
        }
        if (!strlen($base2))
        {
            $base2 = "n/a";
        }
        if (!strlen($inside2_denom))
        {
            $inside2_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff2_num))
        {
            $coeff2_num = "1";
        }
        if (!strlen($coeff2_denom))
        {
            $coeff2_denom = "1";
        }
        if (!strlen($base2))
        {
            $base2 = "1";
        }
        if (!strlen($inside2_denom))
        {
            $inside2_denom = "1";
        }
    }
    if (!strlen($inside3_num))
    {
        $inside3_num = "n/a";
        if (!strlen($coeff3_num))
        {
            $coeff3_num = "n/a";
        }
        if (!strlen($coeff3_denom))
        {
            $coeff3_denom = "n/a";
        }
        if (!strlen($base3))
        {
            $base3 = "n/a";
        }
        if (!strlen($inside3_denom))
        {
            $inside3_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff3_num))
        {
            $coeff3_num = "1";
        }
        if (!strlen($coeff3_denom))
        {
            $coeff3_denom = "1";
        }
        if (!strlen($base3))
        {
            $base3 = "1";
        }
        if (!strlen($inside3_denom))
        {
            $inside3_denom = "1";
        }
    }
    if (!strlen($inside4_num))
    {
        $inside4_num = "n/a";
        if (!strlen($coeff4_num))
        {
            $coeff4_num = "n/a";
        }
        if (!strlen($coeff4_denom))
        {
            $coeff4_denom = "n/a";
        }
        if (!strlen($base4))
        {
            $base4 = "n/a";
        }
        if (!strlen($inside4_denom))
        {
            $inside4_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff4_num))
        {
            $coeff4_num = "1";
        }
        if (!strlen($coeff4_denom))
        {
            $coeff4_denom = "1";
        }
        if (!strlen($base4))
        {
            $base4 = "1";
        }
        if (!strlen($inside4_denom))
        {
            $inside4_denom = "1";
        }
    }

    if (!strlen($inside5_num))
    {
        $inside5_num = "n/a";
        if (!strlen($coeff5_num))
        {
            $coeff5_num = "n/a";
        }
        if (!strlen($coeff5_denom))
        {
            $coeff5_denom = "n/a";
        }
        if (!strlen($base5))
        {
            $base5 = "n/a";
        }
        if (!strlen($inside5_denom))
        {
            $inside5_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff5_num))
        {
            $coeff5_num = "1";
        }
        if (!strlen($coeff5_denom))
        {
            $coeff5_denom = "1";
        }
        if (!strlen($base5))
        {
            $base5 = "1";
        }
        if (!strlen($inside5_denom))
        {
            $inside5_denom = "1";
        }
    }

    if (!strlen($inside6_num))
    {
        $inside6_num = "n/a";
        if (!strlen($coeff6_num))
        {
            $coeff6_num = "n/a";
        }
        if (!strlen($coeff6_denom))
        {
            $coeff6_denom = "n/a";
        }
        if (!strlen($base6))
        {
            $base6 = "n/a";
        }
        if (!strlen($inside6_denom))
        {
            $inside6_denom = "n/a";
        }
    }
    else
    {
        if (!strlen($coeff6_num))
        {
            $coeff6_num = "1";
        }
        if (!strlen($coeff6_denom))
        {
            $coeff6_denom = "1";
        }
        if (!strlen($base6))
        {
            $base6 = "1";
        }
        if (!strlen($inside6_denom))
        {
            $inside6_denom = "1";
        }
    }

    $num_na = 0;

    if ($coeff1_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff1_denom == "n/a")
    {
        $num_na++;
    }
    if ($base1 == "n/a")
    {
        $num_na++;
    }
    if ($inside1_num == "n/a")
    {
        $num_na++;
    }
    if ($inside1_denom == "n/a")
    {
        $num_na++;
    }

    if ($coeff2_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff2_denom == "n/a")
    {
        $num_na++;
    }
    if ($base2 == "n/a")
    {
        $num_na++;
    }
    if ($inside2_num == "n/a")
    {
        $num_na++;
    }
    if ($inside2_denom == "n/a")
    {
        $num_na++;
    }

    if ($coeff3_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff3_denom == "n/a")
    {
        $num_na++;
    }
    if ($base3 == "n/a")
    {
        $num_na++;
    }
    if ($inside3_num == "n/a")
    {
        $num_na++;
    }
    if ($inside3_denom == "n/a")
    {
        $num_na++;
    }

    if ($coeff4_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff4_denom == "n/a")
    {
        $num_na++;
    }
    if ($base4 == "n/a")
    {
        $num_na++;
    }
    if ($inside4_num == "n/a")
    {
        $num_na++;
    }
    if ($inside4_denom == "n/a")
    {
        $num_na++;
    }

    if ($coeff5_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff5_denom == "n/a")
    {
        $num_na++;
    }
    if ($base5 == "n/a")
    {
        $num_na++;
    }
    if ($inside5_num == "n/a")
    {
        $num_na++;
    }
    if ($inside5_denom == "n/a")
    {
        $num_na++;
    }

    if ($coeff6_num == "n/a")
    {
        $num_na++;
    }
    if ($coeff6_denom == "n/a")
    {
        $num_na++;
    }
    if ($base6 == "n/a")
    {
        $num_na++;
    }
    if ($inside6_num == "n/a")
    {
        $num_na++;
    }
    if ($inside6_denom == "n/a")
    {
        $num_na++;
    }

    if ($num_na == 30)
    {
        return "";
    }
    else
    {
        $my_string = "";

        $my_string .= $coeff1_num.$split;
        $my_string .= $coeff1_denom.$split;
        $my_string .= $base1.$split;
        $my_string .= $inside1_num.$split;
        $my_string .= $inside1_denom.$line_split;

        $my_string .= $coeff2_num.$split;
        $my_string .= $coeff2_denom.$split;
        $my_string .= $base2.$split;
        $my_string .= $inside2_num.$split;
        $my_string .= $inside2_denom.$line_split;

        $my_string .= $coeff3_num.$split;
        $my_string .= $coeff3_denom.$split;
        $my_string .= $base3.$split;
        $my_string .= $inside3_num.$split;
        $my_string .= $inside3_denom.$line_split;

        $my_string .= $coeff4_num.$split;
        $my_string .= $coeff4_denom.$split;
        $my_string .= $base4.$split;
        $my_string .= $inside4_num.$split;
        $my_string .= $inside4_denom.$line_split;

        $my_string .= $coeff5_num.$split;
        $my_string .= $coeff5_denom.$split;
        $my_string .= $base5.$split;
        $my_string .= $inside5_num.$split;
        $my_string .= $inside5_denom.$line_split;

        $my_string .= $coeff6_num.$split;
        $my_string .= $coeff6_denom.$split;
        $my_string .= $base6.$split;
        $my_string .= $inside6_num.$split;
        $my_string .= $inside6_denom;

        return $my_string;
    }
}

function parse_expand_the_log_output($num)
{
    $my_string = "";

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align=center>\n";
    $my_string .= "<tr><td>";

    $my_array = explode('#',$num);

    $row_1 = explode('@',$my_array[0]);
    $row_2 = explode('@',$my_array[1]);
    $row_3 = explode('@',$my_array[2]);
    $row_4 = explode('@',$my_array[3]);
    $row_5 = explode('@',$my_array[4]);
    $row_6 = explode('@',$my_array[5]);

    for ($i =0; $i < 6; $i++)
    {
        $row_1[$i] = str_to_math($row_1[$i]);
        $row_2[$i] = str_to_math($row_2[$i]);
        $row_3[$i] = str_to_math($row_3[$i]);
        $row_4[$i] = str_to_math($row_4[$i]);
        $row_5[$i] = str_to_math($row_5[$i]);
        $row_6[$i] = str_to_math($row_6[$i]);
    }

    if ($row_1[0] != "n/a")
    {
        if ($row_1[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_1[0] </td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_1[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_1[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_1[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_1[0]</td><td>";
            }

        }
        if ($row_1[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_1[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_1[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_1[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_1[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_1[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_1[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        $my_string .= "</td></tr></table>";

        return $my_string;
    }
    else if ($row_2[0] != "n/a")
    {
        if ($row_2[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_2[0]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_2[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_2[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_2[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_2[0]</td><td>";
            }

        }
        if ($row_2[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_2[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_2[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_2[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_2[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_2[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_2[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        if ($row_3[0] < 0)
        {
            $my_string .= " - </td><td>";
            $row_3[0] = (-1) * $row_3[0];
        }
        else
        {
            $my_string .= " + </td><td>";
        }

        if ($row_3[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_3[0]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_3[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_3[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_3[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_3[0]</td><td>";
            }

        }
        if ($row_3[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_3[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_3[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_3[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_3[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_3[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_3[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        $my_string .= "</td></tr></table>";

        return $my_string;
    }
    else
    {
        if ($row_4[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_4[0]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_4[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_4[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_4[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_4[0]</td><td>";
            }

        }
        if ($row_4[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_4[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_4[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_4[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_4[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_4[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_4[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        if ($row_5[0] < 0)
        {
            $my_string .= " - </td><td>";
            $row_5[0] = (-1) * $row_5[0];
        }
        else
        {
            $my_string .= " + </td><td>";
        }

        if ($row_5[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_5[0]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_5[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_5[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_5[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_5[0]</td><td>";
            }

        }
        if ($row_5[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_5[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_5[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_5[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_5[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_5[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_5[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        if ($row_6[0] < 0)
        {
            $my_string .= " - </td><td>";
            $row_6[0] = (-1) * $row_6[0];
        }
        else
        {
            $my_string .= " + </td><td>";
        }

        if ($row_6[1] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_6[0]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_6[1]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            if ($row_6[0] == 1)
            {
                $my_string .= "</td><td>";
            }
            else if ($row_6[0] == -1)
            {
                $my_string .= "-</td><td>";
            }
            else
            {
                $my_string .= "$row_6[0]</td><td>";
            }

        }
        if ($row_6[2] == "e")
        {
            $my_string .= "ln </td><td>";
        }
        else if ($row_6[2] == 10)
        {
            $my_string .= "log </td><td>";
        }
        else
        {
            $my_string .= "log<sub> $row_6[2]</sub></td><td>";
        }

        $my_string .= "(</td><td>";

        if ($row_6[4] != 1)
        {
            $my_string .= "<table border='0' cellpadding='0' cellspacing='1'>\n";
            $my_string .= "<tr><td align='center'>$row_6[3]</td></tr>\n";
            $my_string .= "<tr><td>\n";
            $my_string .= "<span class='midline'><img src='Images/1px.gif' width=12 height='1'></span>";
            $my_string .= "</td></tr>\n";
            $my_string .= "<tr><td align='center'>$row_6[4]</td></tr></table>\n";
            $my_string .= "</td><td>\n";
        }
        else
        {
            $my_string .= "$row_6[3]</td><td>";
        }

        $my_string .= ")</td><td>";

        $my_string .= "</td></tr></table></center>";

        return $my_string;

    }
    return "";
}


function parse_write_single_log_input($a_array)
{
    $num1   = $a_array[0];
    $num2   = $a_array[1];
    $num3   = $a_array[2];
    $base   = $a_array[3];
    $denom1 = $a_array[4];
    $denom2 = $a_array[5];
    $denom3 = $a_array[6];

    $num1   = strtolower($num1);
    $num2   = strtolower($num2);
    $num3   = strtolower($num3);
    $base   = strtolower($base);
    $denom1 = strtolower($denom1);
    $denom2 = strtolower($denom2);
    $denom3 = strtolower($denom3);

    $num1   = str_replace(' ','',$num1);
    $num2   = str_replace(' ','',$num2);
    $num3   = str_replace(' ','',$num3);
    $base   = str_replace(' ','',$base);
    $denom1 = str_replace(' ','',$denom1);
    $denom2 = str_replace(' ','',$denom2);
    $denom3 = str_replace(' ','',$denom3);

    $num_ones = 0;

    if (!strlen($num1))
    {
        $num1 = 1;
        $num_ones++;
    }
    if (!strlen($num2))
    {
        $num2 = 1;
        $num_ones++;
    }
    if (!strlen($num3))
    {
        $num3 = 1;
        $num_ones++;
    }
    if (!strlen($base))
    {
        $base = 1;
        $num_ones++;
    }
    if (!strlen($denom1))
    {
        $denom1 = 1;
        $num_ones++;
    }
    if (!strlen($denom2))
    {
        $denom2 = 1;
        $num_ones++;
    }
    if (!strlen($denom3))
    {
        $denom3 = 1;
        $num_ones++;
    }

    if ($num_ones == 7)
    {
        return "";
    }

    $split = '@';
    $line_split = '##';

    $my_string = "";

    $my_string .= $base.$line_split;

    $my_string .= $num1.$split.$num2.$split.$num3.$line_split;

    $my_string .= $denom1.$split.$denom2.$split.$denom3;

    return $my_string;
}

function parse_write_a_single_log_output($num)
{
    $r_array = explode('##',$num);
    $base = $r_array[0];
    $n_array = explode('@',$r_array[1]);
    $d_array = explode('@',$r_array[2]);

    if ($base == 'e')
    {
        $log_base = "<font size=3> ln </font>";
    }
    else if ($base == 10)
    {
        $log_base = "<font size=3> log </font>";
    }
    else
    {
        $log_base = "<font size=3> log<sub> $base</sub> </font>";
    }

    $num_string = "";
    $denom_string = "";

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align=center>\n";
    $my_string .= "<tr><td rowspan=3> $log_base</td>";
    for ($i = 0; $i < 3; $i++)
    {
        $n_array[$i] = str_to_math($n_array[$i]);

        if ($n_array[$i] != 1)
        {
            $num_string .= "$n_array[$i]</sup>";
        }
    }
    if ($num_string == "")
    {
        $num_string = 1;
    }
    $my_string .= "<td align=center>$num_string</td></tr>";
    if ($d_array[0] == 1 && $d_array[1] == 1 && $d_array[2] == 1)
    {
        $my_string .= "</table>";
    }
    else
    {
        $my_string .= "<tr><td align=center>";
        $my_string .= "<span class='midline'><img src='Images/1px.gif' width=80 height='1'></span>";
        $my_string .= "</td></tr><td align=center>";
        for ($i = 0; $i < 3; $i++)
        {
            $d_array[$i] = str_to_math($d_array[$i]);
            if ($d_array[$i] != 1)
            {
                $denom_string .= "$d_array[$i]</sup>";
            }
        }
        if ($denom_string == "")
        {
            $denom_string = 1;
        }
        $my_string .= "$denom_string</td></tr>";
        $my_string .= "</table></center>";
    }
    return $my_string;
}


function parse_quadratic_input($a_array)
{
    $num1   = $a_array[0];
    $num2   = $a_array[1];
    $num3   = $a_array[2];
    $num4   = $a_array[3];
    $num5   = $a_array[4];

    $split = "@";

    if (!strlen($num1) && !strlen($num2))
    {
        $num1 = "n/a";
        $num2 = "n/a";
    }
    else if (!strlen($num2))
    {
        $num2 = "1";
    }

    if (!strlen($num3) && !strlen($num4))
    {
        $num3 = "n/a";
        $num4 = "n/a";
    }
    else if (!strlen($num4))
    {
        $num4 = "1";
    }

    if (!strlen($num5))
    {
        $num5 = "0";
    }
    else
    {
        $num5 = "1";
    }

    if ($num1 == "n/a" && $num2 == "n/a" && $num3 == "n/a" && $num4 == "n/a" && $num5 == 0)
    {
        $my_string = "";
        return $my_string;
    }

    $my_string = $num1.$split.$num2.$split.$num3.$split.$num4.$split.$num5;

    return $my_string;

}

function parse_quadratic_output($num)
{

    $my_string = "";

    $n_array = explode('@',$num);

    if ($n_array[4] == 1)
    {
        $my_string = "<br><center>The equation has no real solutions.</center>";
        return $my_string;
    }

    if ($n_array[0] != "n/a")
    {
        $temp_string1 = simple_out($n_array[0],$n_array[1]);
        $first_string = TRUE;
    }
    if ($n_array[2] != "n/a")
    {
        $temp_string2 = simple_out($n_array[2],$n_array[3]);
        $second_string = TRUE;
    }

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
    $my_string .= "<tr>";
    if ($first_string == TRUE)
    {
        $my_string .= "<td> x = </td><td> $temp_string1 </td>\n";
    }
    if ($first_string == TRUE && $second_string == TRUE)
    {
        $my_string .= "<td> &nbsp;&nbsp;&nbsp; - or - &nbsp;&nbsp;&nbsp;</td>\n";
    }
    if ($second_string == TRUE)
    {
        $my_string .= "<td> x = </td><td> $temp_string2 </td>\n";
    }
    $my_string .= "</tr></table></center>";

    return $my_string;

}

function parse_exp_equation_3_answer($num,$denom)
{

    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    $num   = $num + 0;
    $denom = $denom + 0;

    $out_string  = "<p><center>";
    $out_string .= "N(t) = &nbsp;";
    $out_string .= $num;
    $out_string .= " *  <font size=4>e</font>&nbsp;";
    $out_string .= "<sup>$denom";
    $out_string .= "&nbsp; t</sup></center></p>";

    return $out_string;

}

function parse_end_behavior_1_answer($num)
{
    $num = str_replace(' ','',$num);

    $out_string  = "<p><center>";
    $out_string .= "x<sup> $num </sup>";
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_end_behavior_2_answer($num)
{
    $inf     = "<font size=4>&#8734;</font>";
    $goes_to = "<font size=4>&rarr;</font>";

    $out_string = "";


    if ($num == 1)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; f(x) $goes_to $inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; f(x) $goes_to $inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 2)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; f(x) $goes_to -$inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; f(x) $goes_to -$inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 3)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; f(x) $goes_to $inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; f(x) $goes_to -$inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 4)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; f(x) $goes_to -$inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; f(x) $goes_to $inf";
        $out_string .= "</td></tr></table>";
    }
    else
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; f(x) $goes_to 0<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; f(x) $goes_to 0";
        $out_string .= "</td></tr></table>";
    }

    return $out_string;
}

function parse_proportion_1_answer($num)
{
    $answer = "<p><center>";
    if ($num == 1)
    {
        $answer .= "The function is directly proportional.";
    }
    else if ($num == 2)
    {
        $answer .= "The function is inversly proportional.";
    }
    else // ($num == 3)
    {
        $answer .= "They would pay the same";
    }
    $answer .= "</center></p>";
    return $answer;
}

function parse_proportion_2_answer($num,$denominator)
{
    $answer = "<p><center> f ( x ) is";
    if ($num == 1)
    {
        $answer .= " mulitplied by ";
    }
    else if ($num == 2)
    {
        $answer .= " divided by ";
    }
    $answer .= $denominator;
    $answer .= " .";
    $answer .= "</center></p>";
    return $answer;
}

function parse_zero_behavior_answer($num)
{
    $answer = "<p><center>";
    if ($num == 1)
    {
        $answer .= "The function crosses the x-axis.";
    }
    else if ($num == 2)
    {
        $answer .= "The function touches but does not cross the x-axis.";
    }
    else // ($num == 3)
    {
        $answer .= "They would pay the same";
    }
    $answer .= "</center></p>";
    return $answer;
}


function parse_quadratic_2_output($num)
{
    $my_string = "";

    $n_array = explode('@',$num);

    if ($n_array[4] == 1)
    {
        $my_string = "<br><center>The equation has no real zeros.</center>";
        return $my_string;
    }

    if ($n_array[0] != "n/a")
    {
        $n_array[0] = str_to_math($n_array[0]);
        $temp_string1 = simple_out($n_array[0],$n_array[1],23);
        $first_string = TRUE;
    }
    if ($n_array[2] != "n/a")
    {
        $n_array[2] = str_to_math($n_array[2]);
        $temp_string2 = simple_out($n_array[2],$n_array[3],23);
        $second_string = TRUE;
    }

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
    $my_string .= "<tr>";
    if ($first_string == TRUE)
    {
        $my_string .= "<td> x = </td><td> $temp_string1 </td>\n";
    }
    if ($first_string == TRUE && $second_string == TRUE)
    {
        $my_string .= "<td> &nbsp;&nbsp;&nbsp; - or - &nbsp;&nbsp;&nbsp;</td>\n";
    }
    if ($second_string == TRUE)
    {
        $my_string .= "<td> x = </td><td> $temp_string2 </td>\n";
    }
    $my_string .= "</tr></table></center>";

    return $my_string;

}

function parse_standard_form_input($a_array)
{
    $num1 = $a_array[0];
    $num2 = $a_array[1];
    $num3 = $a_array[2];
    $num4 = $a_array[3];

    $num2 = str_replace(' ','',$num2);
    $num4 = str_replace(' ','',$num4);

    if (!(strlen($num2)) && !(strlen($num4)) )
    {
        return "";
    }
    else
    {
        $split = '@';
        $my_num = $num1.$split.$num2.$split.$num3.$split.$num4;
        return $my_num;
    }
}

function parse_standard_form_output($num)
{
    $num_array = explode('@',$num);

    $my_string = "<p><center>f( x ) = ( x ";
    if ($num_array[0] == 1)
    {
        $my_string .= "+ ";
    }
    else
    {
        $my_string .= "- ";
    }
    $my_string .= $num_array[1]." )<sup> 2</sup> ";
    if ($num_array[2] == 1)
    {
        $my_string .= "+ ";
    }
    else
    {
        $my_string .= "- ";
    }
    $my_string .= $num_array[3]."</center></p>";

    return $my_string;

}

function parse_translation_input($a_array)
{
    $num1 = $a_array[0];
    $num2 = $a_array[1];
    $num3 = $a_array[2];
    $num4 = $a_array[3];
    $num5 = $a_array[4];
    $num6 = $a_array[5];
    $num7 = $a_array[6];

    $num3 = str_replace(' ','',$num3);
    $num6 = str_replace(' ','',$num6);

    if (!(strlen($num1)))
    {
        $num2 = "n/a";
        $num3 = "n/a";
    }
    if (!(strlen($num4)))
    {
        $num5 = "n/a";
        $num6 = "n/a";
    }
    if (!(strlen($num7)))
    {
        $num7 = 0;
    }
    else
    {
        $num7 = 1;
    }
    if ($num7 ==0 && $num2 == "n/a" && $num5 == "n/a")
    {
        return "";
    }
    else
    {
        $split = '@';
        $numerator = $num2.$split.$num3.$split.$num5.$split.$num6.$split.$num7;
        return $numerator;
    }
}

function parse_translation_output($num)
{
    $num_array = explode('@',$num);

    $my_string = "<table border=2 cellspacing=2 cellpadding=2 align=center>\n";
    $my_string .= "<tr><td>";
    if ($num_array[0] != "n/a")
    {
        $my_string .= "Translated ";
        if ($num_array[0] == 1)
        {
            $my_string .= "left ";
        }
        else
        {
            $my_string .= "right ";
        }
        $my_string .= $num_array[1]." units.";
        $my_string .= "</td></tr><tr><td>";
    }
    if ($num_array[2] != "n/a")
    {
        $my_string .= "Translated ";
        if ($num_array[2] == 1)
        {
            $my_string .= "up ";

        }
        else
        {
            $my_string .= "down ";
        }
        $my_string .= $num_array[3]." units.";
        $my_string .= "</td></tr><tr><td>";
    }
    if ($num_array[4] != 0)
    {
        $my_string .= "Reflected about the x-axis";
        $my_string .= "</td></tr><tr><td>";
    }
    $my_string .= "</td></tr></table>";

    return $my_string;

}

function parse_length_width_output($num)
{
    $my_string = "";

    $n_array = explode('@',$num);

    if ($n_array[0] != "n/a")
    {
        $n_array[0] = str_to_math($n_array[0]);
        $temp_string1 = simple_out($n_array[0],$n_array[1],23);
        $first_string = TRUE;
    }
    if ($n_array[2] != "n/a")
    {
        $n_array[2] = str_to_math($n_array[2]);
        $temp_string2 = simple_out($n_array[2],$n_array[3],23);
        $second_string = TRUE;
    }

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
    $my_string .= "<tr>";
    if ($first_string == TRUE)
    {
        $my_string .= "<td> L = </td><td> $temp_string1 </td>\n";
    }
    if ($first_string == TRUE && $second_string == TRUE)
    {
        $my_string .= "<td> &nbsp;&nbsp;&nbsp; - and - &nbsp;&nbsp;&nbsp;</td>\n";
    }
    if ($second_string == TRUE)
    {
        $my_string .= "<td> W = </td><td> $temp_string2 </td>\n";
    }
    $my_string .= "</tr></table></center>";

    return $my_string;
}

function parse_end_behavior_3_answer($num,$denom)
{
    $num   = str_replace(' ','',$num);
    $denom = str_replace(' ','',$denom);

    if ($denom == 1)
    {
        $denom = "";
    }
    else if ($denom == -1)
    {
        $denom = "-";
    }

    $out_string  = "<p><center>";
    $out_string .= "$denom x<sup> $num </sup>";
    $out_string .= "</center></p>";

    return $out_string;
}

function parse_end_behavior_4_answer($num)
{
    $inf     = "<font size=4>&#8734;</font>";
    $goes_to = "<font size=4>&rarr;</font>";

    $out_string = "";

    if ($num == 1)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; P(x) $goes_to $inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; P(x) $goes_to $inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 2)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; P(x) $goes_to -$inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; P(x) $goes_to -$inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 3)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; P(x) $goes_to $inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; P(x) $goes_to -$inf";
        $out_string .= "</td></tr></table>";
    }
    else if ($num == 4)
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; P(x) $goes_to -$inf<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; P(x) $goes_to $inf";
        $out_string .= "</td></tr></table>";
    }
    else
    {
        $out_string .= "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
        $out_string .= "<tr align='center'><td>\n";
        $out_string .= "As x $goes_to $inf ; P(x) $goes_to 0<br>";
        $out_string .= "&nbsp;As x $goes_to -$inf ; P(x) $goes_to 0";
        $out_string .= "</td></tr></table>";
    }

    return $out_string;
}

function parse_multiple_choice_output($num)
{
    $return_string = "<p><center>";

    if ($num == 1)
    {
        $return_string .= "A";
    }
    else if ($num == 2)
    {
        $return_string .= "B";
    }
    else if ($num == 3)
    {
        $return_string .= "C";
    }
    else if ($num == 4)
    {
        $return_string .= "D";
    }
    else
    {
        $return_string .= "E";
    }

    $return_string .= "</center></p>";

    return $return_string;
}

function parse_projectile_2_output($num)
{
    $my_string = "";

    $n_array = explode('@',$num);

    if ($n_array[4] == 1)
    {
        $my_string = "<br><center>It never happens.</center>";
        return $my_string;
    }

    if ($n_array[0] != "n/a")
    {
        $n_array[0] = str_to_math($n_array[0]);
        $temp_string1 = simple_out($n_array[0],$n_array[1],12);
        $first_string = TRUE;
    }
    if ($n_array[2] != "n/a")
    {
        $n_array[2] = str_to_math($n_array[2]);
        $temp_string2 = simple_out($n_array[2],$n_array[3],12);
        $second_string = TRUE;
    }

    $my_string = "<table border=0 cellspacing=0 cellpadding=2 align='center'>\n";
    $my_string .= "<tr>";
    if ($first_string == TRUE)
    {
        $my_string .= "<td> t = </td><td> $temp_string1 </td>\n";
    }
    if ($first_string == TRUE && $second_string == TRUE)
    {
        $my_string .= "<td> &nbsp;&nbsp;&nbsp; - or - &nbsp;&nbsp;&nbsp;</td>\n";
    }
    if ($second_string == TRUE)
    {
        $my_string .= "<td> t = </td><td> $temp_string2 </td>\n";
    }
    $my_string .= "</tr></table></center>";

    return $my_string;
}

function parse_projectile_2_input($ai_array)
{
    $num1 = $ai_array[0];
    $num2 = $ai_array[1];
    $num3 = $ai_array[2];
    $num4 = $ai_array[3];
    $num5 = $ai_array[4];

    $split = "@";

    if (!strlen($num1) && !strlen($num2))
    {
        $num1 = "n/a";
        $num2 = "n/a";
    }
    else if (!strlen($num2))
    {
        $num2 = "1";
    }

    if (!strlen($num3) && !strlen($num4))
    {
        $num3 = "n/a";
        $num4 = "n/a";
    }
    else if (!strlen($num4))
    {
        $num4 = "1";
    }

    if (!strlen($num5))
    {
        $num5 = "0";
    }
    else
    {
        $num5 = "1";
    }

    if ($num1 == "n/a" && $num2 == "n/a" && $num3 == "n/a" && $num4 == "n/a" && $num5 == 0)
    {
        $my_string = "";
        return $my_string;
    }

    $my_string = $num1.$split.$num2.$split.$num3.$split.$num4.$split.$num5;

    return $my_string;
}

function check_neg_pow($my_string)
{
    $my_string = strtolower($my_string);
    $my_string = trim($my_string);
    $my_string = trim_parenth($my_string);
    $size = strlen($my_string);
    if ($size == 0)
    {
        $result = FALSE;
        return $result;
    }
    $char_array = array();
    for ($i = 0; $i < $size; $i++)
    {
        $char_array[] = substr($my_string,$i,1);
    }

    $pow = array();
    $variable = array();
    for ($i = 0; $i < ($size - 2); $i++)
    {
        if (!is_numeric($char_array[$i]) && $char_array[$i+1] == '^')
        {
            $pow_string = "";
            $parenth = 0;
            $check_parenth = FALSE;
            $variable[] = $char_array[$i];
            //// echo "<br>found power in my_string variable is ".$char_array[$i]."<br>";
            for ($j = 2; $i + $j < $size; $j++)
            {
                if ($char_array[$i+$j] == '-')
                {
                    $pow_string .= $char_array[$i+$j];
                }
                else if ($char_array[$i + $j] == '(')
                {
                    $pow_string .= $char_array[$i + $j];
                    $check_parenth = TRUE;
                    $parenth--;
                }
                else if ($char_array[$i + $j] == ')')
                {
                    $pow_string .= $char_array[$i + $j];
                    $parenth++;
                }
                else if (!is_numeric($char_array[$i+$j]) )
                {
                    if ($parenth == 0)
                    {
                        break;
                    }
                    else
                    {
                        $pow_string .= $char_array[$i + $j];
                    }
                }
                else
                {
                    $pow_string .= $char_array[$i+$j];
                }

                if ($check_parenth == TRUE)
                {
                    if ($parenth == 0)
                    {
                        break;
                    }
                }
            }
            //// echo "<br> ".$char_array[$i]." power is $pow_string";
            $pow[] = $pow_string;
            $i = $i + $j - 1;
        }
    }
    $array_size = count($pow);
    $found_negative = FALSE;
    for ($i = 0; $i < $array_size; $i++)
    {
        $temp_string = $pow[$i];
        for ($j = 0; $j < strlen($temp_string); $j++)
        {
            if ($temp_string[$j] == '-')
            {
                if ($found_negative == FALSE)
                {
                    $found_negative = array();
                    $found_negative[] = $variable[$i];
                }
                else
                {
                    $found_negative[] = $variable[$i];
                }
            }
        }
    }
    return $found_negative;
}

function check_reduce_pow($my_string)
{
    $my_string = strtolower($my_string);
    $my_string = trim($my_string);
    $my_string = trim_parenth($my_string);
    $size = strlen($my_string);
    if ($size == 0)
    {
        $result = FALSE;
        return $result;
    }
    $char_array = array();
    for ($i = 0; $i < $size; $i++)
    {
        $char_array[] = substr($my_string,$i,1);
    }

    $pow = array();
    $variable = array();
    for ($i = 0; $i < ($size - 2); $i++)
    {
        if (!is_numeric($char_array[$i]) && $char_array[$i+1] == '^')
        {
            $pow_string = "";
            $parenth = 0;
            $check_parenth = FALSE;
            $variable[] = $char_array[$i];
            ////echo "<br>found power in my_string variable is ".$char_array[$i]."<br>";
            for ($j = 2; $i + $j < $size; $j++)
            {
                if ($char_array[$i+$j] == '-')
                {
                    $pow_string .= $char_array[$i+$j];
                }
                else if ($char_array[$i + $j] == '(')
                {
                    $pow_string .= $char_array[$i + $j];
                    $check_parenth = TRUE;
                    $parenth--;
                }
                else if ($char_array[$i + $j] == ')')
                {
                    $pow_string .= $char_array[$i + $j];
                    $parenth++;
                }
                else if (!is_numeric($char_array[$i+$j]) )
                {
                    if ($parenth == 0)
                    {
                        break;
                    }
                    else
                    {
                        $pow_string .= $char_array[$i + $j];
                    }
                }
                else
                {
                    $pow_string .= $char_array[$i+$j];
                }

                if ($check_parenth == TRUE)
                {
                    if ($parenth == 0)
                    {
                        break;
                    }
                }
            }
            //// echo "<br> ".$char_array[$i]." power is $pow_string";
            $pow[] = $pow_string;
            $i = $i + $j - 1;
        }
    }
    $array_size = count($pow);
    $found_reducable = FALSE;
    for ($i = 0; $i < $array_size; $i++)
    {
        $temp_array = explode('/',$pow[$i]);
        if (count($temp_array) != 1)
        {
            $num   = $temp_array[0];
            $denom = $temp_array[1];

            $num   = str_replace(' ','',$num);
            $num   = str_replace('(','',$num);
            $denom = str_replace(' ','',$denom);
            $denom = str_replace(')','',$denom);

            $num = $num + 0;
            $denom = $denom + 0;

            if (reduce($num,$denom,100))
            {
                if ($found_reducable == FALSE)
                {
                    $found_reducable = array();
                    $found_reducable[] = $variable[$i];
                }
                else
                {
                    $found_reducable[] = $variable[$i];
                }
            }
        }
    }
    return $found_reducable;
}

function parse_variables($my_string)
{
    $my_string = strtolower($my_string);
    $my_string = trim($my_string);
    $my_string = trim_parenth($my_string);
    $size = strlen($my_string);
    $non_variables = array('+','-','*','(',')','/','.',',','^');
    if ($size == 0)
    {
        return FALSE;
    }
    $char_array = array();
    $variables = array();
    for ($i = 0; $i < $size; $i++)
    {
        $char_array[] = substr($my_string,$i,1);
    }
    for ($i = 0; $i < $size; $i++)
    {
        $char = $char_array[$i];
        if (!is_numeric($char))
        {
            if (!is_in($non_variables,$char))
            {
                $variables[] = $char;
            }
        }
    }
    return $variables;
}

function parse_duplicate($my_array)
{
    $size = count($my_array);
    if ($size < 2)
    {
        return FALSE;
    }
    for ($i = 0; $i < $size; $i++)
    {
        $temp = $my_array[$i];
        for ($j = 0; $j < $size; $j++)
        {
            if ($j == $i)
            {
                continue;
            }
            if ($my_array[$i] == $my_array[$j])
            {
                return TRUE;
            }
        }
    }
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Parse monomial                      ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         October 20th 2005                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   $mon_array = parse_monomial($my_string);
////
////   in:  $my_string - a monomial
////
////   out:  $mon_array = array(coefficient,variable,power)
////            if monomial has more then one variable
////            variable and power will be arrays
////
////   ** NOTE ** only single character variables
////              are compatible with this parser
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function parse_monomial($my_string)
{
    $debug = FALSE;
    if ($debug == TRUE)
    {
        echo "<br><center><strong> BEGIN DEBUG INFO FOR PARSE MONOMIAL ";
        echo "</strong></center><br>";
        echo "PARSE MONOMIAL WAS PASSED $my_string<br>";
    }
    $size = strlen($my_string);
    if ($size == 0)
    {
        if ($debug)
        {
            echo "<br><center> ***WARNING*** Passed parse_monomial a string ";
            echo "of length zero.  </center><br>";
            echo "<br><center><strong> END DEBUG INFO FOR PARSE MONOMIAL ";
            echo "</strong></center><br>";
        }
        return FALSE;
    }

    $char_array            = array();
    $coeff                 = array();
    $variables             = array();
    $powers                = array();
    $open_parenth          = 0;
    $last_char_var         = FALSE;
    $in_parenth_power      = FALSE;
    $in_single_power       = FALSE;
    $in_parenth_var        = FALSE;

    $operators = array('-','*','+','(',')','/','^');

    $o_group = array('(','[');
    $c_group = array(')',')');

    $my_string = str_replace(' ','',$my_string);

    for($i = 0; $i < $size; $i++)
    {
        $char_array[] = substr($my_string,$i,1);
    }
    for ($i = 0; $i < $size; $i++)
    {
        $char = $char_array[$i];
        if ($char == NULL)
        {
            continue;
        }
        if ($last_char_var)
        {
            if ($char == '^' && is_in($o_group,$char_array[$i+1]))
            {
                $in_parenth_power = TRUE;
                $char = $char_array[$i+1];
                $i++;
            }
            else if ($char == '^')
            {
                $in_single_power = TRUE;
                $char = $char_array[$i+1];
                $i++;
            }
            else
            {
                $powers[] = 1;
            }
            $last_char_var = FALSE;
        }
        if (!is_numeric($char) && !is_in($operators,$char))
        {
            if (!$in_parenth_power && !$in_single_power)
            {
                if ($open_parenth > 0)
                {
                    $temp_string   .= $char;
                    $in_parenth_var = TRUE;
                    continue;
                }
                $variables[]   = $char;
                if (strlen($temp_string))
                {
                    if ($temp_string != "*")
                    {
                        $coeff[] = $temp_string;
                    }
                    $temp_string   = "";
                }
                $last_char_var = TRUE;
                continue;
            }
            else if (!$in_parenth_power)
            {
                if ($char_array[$i-1] == '^')
                {
                    $powers[]        = $char;
                    $in_single_power = FALSE;
                    continue;
                }
                else
                {
                    $variables[]     = $char;
                    $last_char_var   = TRUE;
                    $powers[]        = $temp_string;
                    $temp_string     = "";
                    $is_single_power = FALSE;
                    continue;
                }
            }
            else // in_parenth_power
            {
                $temp_string .= $char;
                continue;
            }
        }
        else if (!is_numeric($char))
        {
            if (!$in_parenth_power && !$in_single_power && !$in_parenth_var)
            {
                if (is_in($o_group,$char))
                {
                    if (strlen($temp_string))
                    {
                        $coeff[]     = $temp_string;
                        $temp_string = "";
                    }
                    $open_parenth++;
                }
                if (is_in($c_group,$char))
                {
                    $open_parenth--;
                }
                $temp_string .= $char;
                continue;
            }
            else if (!$in_parenth_power && !$in_parenth_var)
            {
                $powers[]        = $temp_string;
                if (is_in($o_group,$char))
                {
                    $open_parenth++;
                }
                $temp_string     = $char;
                $in_single_power = FALSE;
                continue;
            }
            else if (!$in_parenth_var)
            {
                if (is_in($o_group,$char))
                {
                    $open_parenth++;
                }
                if (is_in($c_group,$char))
                {
                    $open_parenth--;
                }
                if ($open_parenth == 0)
                {
                    $powers[]         = $temp_string.$char;
                    $temp_string      = "";
                    $in_parenth_power = FALSE;
                    continue;
                }
                else
                {
                    $temp_string .= $char;
                    continue;
                }
            }
            else
            {
                if (is_in($o_group,$char))
                {
                    $open_parenth++;
                }
                if (is_in($c_group,$char))
                {
                    $open_parenth--;
                    if ($open_parenth == 0)
                    {
                        $variables[]    = $temp_string.$char;
                        $temp_string    = "";
                        $in_parenth_var = FALSE;
                        $last_char_var  = TRUE;
                        continue;
                    }
                }
                $temp_string .= $char;
                continue;
            }
        }
        else
        {
            $temp_string .= $char;
            continue;
        }
    }
    if (strlen($temp_string))
    {
        if ($in_single_power)
        {
            $powers[]        = $temp_string;
            $in_single_power = FALSE;
            $temp_string     = "";
        }
        else
        {
            $coeff[]     = $temp_string;
            $temp_string = "";
        }
    }
    if (count($variables) == (1 + count($powers)))
    {
        $powers[] = 1;
    }

    $coeff_size = count($coeff);

    for($i = 0; $i < $coeff_size; $i++)
    {
        if ($coeff[$i] == '-')
        {
            $coeff[$i] = -1;
        }
        else
        {
            $coeff[$i] = trim_parenth($coeff[$i]) + 0;
        }
    }

    if ($coeff_size == 0)
    {
        $coeff = array(1);
    }

    if ($debug)
    {
        $coeff_size = count($coeff);
        $variable_size = count($variables);
        $powers_size = count($powers);
        for ($i = 0; $i < $coeff_size; $i++)
        {
            echo "<br> coeff $i is ".$coeff[$i];
        }
        for ($i = 0; $i < $variable_size; $i++)
        {
            echo "<br> variable $i is ".$variables[$i];
        }
        for ($i = 0; $i < $powers_size; $i++)
        {
            echo "<br> power $i is ".$powers[$i];
        }
        echo "<center><strong> END INFO FOR PARSE_MONOMIAL </strong></center>";
    }
    $mon_array = array($coeff,$variables,$powers);
    return $mon_array;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////          Parse Polynomial                     ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         October 20th 2005                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   parse a polynomail into monomials
////
////   $my_array = parse_polynomial($my_string);
////
////   in:  $my_string - a polynomial
////
////   out:  $my_array = an array of monomials (strings)
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function parse_polynomial($my_string)
{
    $debug = FALSE;
    if ($debug)
    {
        echo "<br><center><strong>\n";
        echo "DEBUG INFO FOR PARSE POLYNOMIAL\n";
        echo "</strong></center><br>\n";
    }
    if (!strlen($my_string))
    {
        if ($debug)
        {
            echo "<br><center><strong>\n";
            echo "*** WARNING *** <br> Passed parse_polynomial a string ";
            echo "of length zero. <br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR PARSE POLYNOMIAL\n";
            echo "</strong></center><br>\n";
        }
        return FALSE;
    }

    $size        = strlen($my_string);
    $char_array  = array();
    $poly_array  = array();
    $operators   = array('+','-');
    $paranths    = 0;
    $temp_string = "";

    $my_string = str_replace(' ','',$my_string);

    for ($i = 0; $i < $size; $i++)
    {
        $char_array[] = substr($my_string,$i,1);
    }
    for ($i = 0; $i < $size; $i++)
    {
        $char = $char_array[$i];
        if ($char == NULL)
        {
            continue;
        }
        if ($char == '(')
        {
            $paranths++;
            $temp_string .= $char;
            continue;
        }
        if ($char == ')')
        {
            $paranths--;
            $temp_string .= $char;
            continue;
        }
        if ($paranths == 0 && strlen($temp_string) && is_in($operators,$char))
        {
            $poly_array[] = $temp_string;
            if ($char == '-')
            {
                $temp_string  = $char;
            }
            else
            {
                $temp_string = "";
            }
            continue;
        }
        else
        {
            $temp_string .= $char;
            continue;
        }
    }

    $poly_array[] = $temp_string;

    if ($debug)
    {
        $size = count($poly_array);
        echo "<br> parse_polynomial was passed ".$my_string."<br>";
        for ($i = 0; $i < $size; $i++)
        {
            echo "<br> monomial $i is ".$poly_array[$i];
            echo "<br>";
        }
        echo "<br><center><strong>\n";
        echo "END DEBUG INFO FOR PARSE_POLYNOMIAL\n";
        echo "</strong></center><br>";
    }

    return $poly_array;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Compare Monomials                   ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         October 20th 2005                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   checks two monomials to see if they are like terms
////
////   $my_bool = compare_monomials($mono1,$mono2);
////
////   in:  $mono1, $mono2 two monomials (strings)
////
////   out:  $my_bool = TRUE if monomials are like terms
////                    FALSE if monomials are non-like terms
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function compare_monomials($mono1,$mono2)
{
    $debug = FALSE;
    if ($debug)
    {
        echo "<br><center><strong>\n";
        echo "DEBUG INFO FOR COMPARE MONOMIALS\n";
        echo "</strong></center><br>";
        echo "<br> monomial 1 is ".$mono1;
        echo "<br> monomial 2 is ".$mono2;
        echo "<br>\n";
    }

    if (!strlen($mono1) || !strlen($mono2))
    {
        if ($debug)
        {
           echo "<br><center><strong>\n";
            echo "*** WARNING *** <br>";
            echo "COMPARE MONOMIALS WAS PASSED MONOMIAL OF STRING LENGTH ";
            echo "ZERO. RETURNING FALSE<br>\n";
            echo "</strong></center><br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR COMPARE MONOMIALS\n";
            echo "</strong></center><br>\n";
        }
        return FALSE;
    }

    $mono_array_1 = array();
    $mono_array_2 = array();
    $mono_size_1  = 0;
    $mono_size_2  = 0;
    $used_locale  = array();

    $mono_array_1 = parse_monomial($mono1);
    $mono_array_2 = parse_monomial($mono2);

    $mono_size_1 = count($mono_array_1[1]);
    $mono_size_2 = count($mono_array_2[1]);

    if ($mono_size_1 != $mono_size_2)
    {
        if ($debug)
        {
            echo "<br>MONOMIALS HAVE DIFFERENT NUMBER OF VARIABLES<br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR COMPARE MONOMIALS\n";
            echo "</center></strong><br>";
        }
        return FALSE;
    }

    for ($j = 0; $j < $mono_size_1; $j++)
    {
        $mono_array_1[1][$j] = trim_parenth($mono_array_1[1][$j]);
        $mono_array_1[2][$j] = trim_parenth($mono_array_1[2][$j]);
        $mono_array_2[1][$j] = trim_parenth($mono_array_2[1][$j]);
        $mono_array_2[2][$j] = trim_parenth($mono_array_2[2][$j]);
    }

    for ($j = 0; $j < $mono_size_1; $j++)
    {
        $sim_var = FALSE;
        for ($k = 0; $k < $mono_size_2; $k++)
        {
            if (is_in($used_locale,$k))
            {
                continue;
            }
            if ($mono_array_1[1][$j] == $mono_array_2[1][$k])
            {
                if ($mono_array_1[2][$j] == $mono_array_2[2][$k])
                {
                    $used_locale[$j] = $k;
                    $sim_var = TRUE;
                    break;
                }
            }
        }
        if (!$sim_var)
        {
            if ($debug)
            {
                $temp_string  = $mono_array_1[1][$j]."^";
                $temp_string .= $mono_array_1[2][$j];
                $temp_string  = str_to_math($temp_string);

                echo "<br> COULD NOT FIND VARIABLE MATCH FOR ";
                echo $temp_string;
                echo "<br>";
                echo "<br><center><strong>\n";
                echo "END DEBUG INFO FOR COMPARE MONOMIALS\n";
                echo "</center></strong><br>";

            }
            return FALSE;
        }
    }

    if ($debug)
    {
        echo "<br> MONOMIALS ARE LIKE TERMS ";
        echo "<br>";
        echo "<br><center><strong>\n";
        echo "END DEBUG INFO FOR COMPARE MONOMIALS\n";
        echo "</center></strong><br>";
    }

    return TRUE;
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Check Combine Power                 ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         October 18th 2005                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   checks a polynomial to see if you can combine
////   some of the terms with like powers
////
////   $my_array = check_combine_power($my_string);
////
////   in:  $my_string - a polynomial
////
////   out:  $my_array = if you can combine powers
////            returns an array of terms(strings) that
////            can be combined with the zero entry being
////            the number of terms that can be combined
////            if you cant combine powers returns false
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function check_combine_power($my_string)
{
    $debug = FALSE;
    if ($debug)
    {
        echo "<br><center><strong>\n";
        echo "BEGIN DEBUG INFO FOR CHECK COMBINE POWER\n";
        echo "</strong></center><br>\n";
        echo "<br> CHECK COMBINE POWER WAS PASSED $my_string\n";
    }
    if (!strlen($my_string))
    {
        if ($debug)
        {
            echo "<br><center><strong>\n";
            echo "*** WARNING *** <br>\n";
            echo "CHECK COMBINE POWERS WAS PASSED A STRING OF ";
            echo "LENGTH ZERO<br>\n";
            echo "</strong></center><br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR CHECK COMBINE POWER\n";
            echo "</strong></center><br>\n";
        }
        return FALSE;
    }

    $poly      = array();
    $result    = array();
    $result[0] = 0;
    $size      = 0;

    $poly = parse_polynomial($my_string);
    $size = count($poly);

    if ($size < 2)
    {
        $result = FALSE;
        if ($debug)
        {
            echo "<br><strong>\n";
            echo "POLYNOMIAL ONLY HAS ONE TERM RETURNING FALSE\n";
            echo "</strong><br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR CHECK COMBINE POWER\n";
            echo "</strong></center><br>\n";
        }
        return $result;
    }

    for ($i = 0; $i < ($size-1); $i++)
    {
        $mono1 = $poly[$i];
        for ($j = ($i+1); $j < $size; $j++)
        {
            $mono2 = $poly[$j];
            if (compare_monomials($mono1,$mono2))
            {
                $result[0]++;
                $result[] = $mono1;
                $result[] = $mono2;
                if ($debug)
                {
                    echo "<br> Found like terms <br>\n";
                    echo "$mono1 is a like term of $mono2\n";
                    echo "<br>\n";
                }
            }
        }
    }

    if ($debug)
    {
        echo "<br> Total number of like terms is ".$result[0];
        echo "<br>\n";
        echo "<br><center><strong>\n";
        echo "END DEBUG INFO FOR CHECK COMBINE POWER\n";
        echo "</strong></center><br>";
    }
    if ($result[0] == 0)
    {
        $result = FALSE;
    }
    return $result;
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////          Root to Powers                       ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////           March 19th 2006                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   switches the roots in a string to powers
////
////   in:  $my_str
////
////   out:  $new_str
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function rt_to_pow($my_str)
{
    $new_str = "";
    $debug   = FALSE;

    $o_group = array('(','[');
    $c_group = array(')',']');

    if ($debug)
    {
        echo "<h1> START DEBUG FOR ROOT TO POWERS</h1>";
        echo "Root to powers was passed:";
        echo $my_str;
        echo "<br><br>";
    }

    $size = strlen($my_str);
    if ($size == 0)
    {
        if ($debug)
        {
            echo "<br>Root to powers was passed a string of length 0";
            echo "<br> Returning False";
            echo "<h1> END DEBUG FOR ROOT TO POWERS</h1>";
        }
        return FALSE;
    }

    $my_str = " ".$my_str;
    $pos = strpos($my_str,'sqrt');

    while($pos > 0)
    {
        $char = $my_str[$pos+4];
        $my_str = substr_replace($my_str,$char,$pos,5);
        $new_pos = $pos;

        $parenth = 1;
        while ($parenth > 0 && $new_pos < $size)
        {
            $new_pos++;
            $char = $my_str[$new_pos];
            if (is_in($o_group,$char))
            {
                $parenth++;
            }
            else if (is_in($c_group,$char))
            {
                $parenth--;
            }
        }
        if ($debug)
        {
            echo "<br> close of root is :".$new_pos;
        }
        $char = $my_str[$new_pos+1];
        if ($char != '^')
        {
            $new_char = $my_str[$new_pos];
            $my_str = substr_replace($my_str,$new_char."^(1/2)",$new_pos,1);
        }
        else
        {
            $pow_pos = $new_pos + 2;
            $parenth = 1;
            while ($parenth > 0 && $pow_pos < $size)
            {
                $pow_pos++;
                $char = $my_str[$pow_pos];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
            }
            $pow_length = $pow_pos - $new_pos - 3;
            $pow_string = substr($my_str,$new_pos+3,$pow_length);
            $pow_string = " ".$pow_string;

            if ($debug)
            {
                echo "<br>pow string before:".$pow_string;
            }

            if (strpos($pow_string,'/'))
            {
                $num_denom = explode('/',$pow_string);
                $denom = $num_denom[1] + 0;
                $denom = $denom * 2;
                $pow_string = $num_denom[0]."/".$denom;
            }
            else
            {
                $pow_string = $pow_string."/2";
            }

            if ($debug)
            {
                $pow_starts = $new_pos+3;
                echo "<br>pow pos:".$pow_pos;
                echo "<br>pow length:".$pow_length;
                echo "<br>pow starts:".$pow_starts;
                echo "<br>pow string:".$pow_string;
            }
            $pow_string = trim($pow_string);
            $my_str = substr_replace($my_str,$pow_string,$new_pos+3,$pow_length);
        }
        if ($debug)
        {
            echo "<br>pos:".$pos;
            echo "<br>my_str:".$my_str;
        }
        $pos = strpos($my_str,'sqrt');
    }

    $pos = strpos($my_str,'cbrt');

    while($pos > 0)
    {
        $char = $my_str[$pos+4];
        $my_str = substr_replace($my_str,$char,$pos,5);

        $new_pos = $pos;

        $parenth = 1;
        while ($parenth > 0 && $new_pos < $size)
        {
            $new_pos++;
            $char = $my_str[$new_pos];
            if (is_in($o_group,$char))
            {
                $parenth++;
            }
            else if (is_in($c_group,$char))
            {
                $parenth--;
            }
        }
        if ($debug)
        {
            echo "<br> close of root is :".$new_pos;
        }
        $char = $my_str[$new_pos+1];
        if ($char != '^')
        {
            $new_char = $my_str[$new_pos];
            $my_str = substr_replace($my_str,$new_char."^(1/3)",$new_pos,1);
        }
        else
        {
            $pow_pos = $new_pos + 2;
            $parenth = 1;
            while ($parenth > 0 && $pow_pos < $size)
            {
                $pow_pos++;
                $char = $my_str[$pow_pos];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
            }
            $pow_length = $pow_pos - $new_pos - 3;
            $pow_string = substr($my_str,$new_pos+3,$pow_length);
            $pow_string = " ".$pow_string;
            if ($debug)
            {
                echo "<br>pow string before:".$pow_string;
            }

            if (strpos($pow_string,'/'))
            {
                $num_denom = explode('/',$pow_string);
                $denom = $num_denom[1] + 0;
                $denom = $denom * 3;
                $pow_string = $num_denom[0]."/".$denom;
            }
            else
            {
                $pow_string = $pow_string."/3";
            }

            if ($debug)
            {
                $pow_starts = $new_pos+3;
                echo "<br>pow pos:".$pow_pos;
                echo "<br>pow length:".$pow_length;
                echo "<br>pow starts:".$pow_starts;
                echo "<br>pow string:".$pow_string;
            }
            $pow_string = trim($pow_string);
            $my_str = substr_replace($my_str,$pow_string,$new_pos+3,$pow_length);
        }
        if ($debug)
        {
            echo "<br>pos:".$pos;
            echo "<br>my_str:".$my_str;
        }
        $pos = strpos($my_str,'cbrt');
    }

    $pos = strpos($my_str,'ftrt');

    while($pos > 0)
    {
        $char = $my_str[$pos+4];
        $my_str = substr_replace($my_str,$char,$pos,5);

        $new_pos = $pos;

        $parenth = 1;
        while ($parenth > 0 && $new_pos < $size)
        {
            $new_pos++;
            $char = $my_str[$new_pos];
            if (is_in($o_group,$char))
            {
                $parenth++;
            }
            else if (is_in($c_group,$char))
            {
                $parenth--;
            }
        }
        if ($debug)
        {
            echo "<br> close of root is :".$new_pos;
        }
        $char = $my_str[$new_pos+1];
        if ($char != '^')
        {
            $new_char = $my_str[$new_pos];
            $my_str = substr_replace($my_str,$new_char."^(1/4)",$new_pos,1);
        }
        else
        {
            $pow_pos = $new_pos + 2;
            $parenth = 1;
            while ($parenth > 0 && $pow_pos < $size)
            {
                $pow_pos++;
                $char = $my_str[$pow_pos];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
            }
            $pow_length = $pow_pos - $new_pos - 3;
            $pow_string = substr($my_str,$new_pos+3,$pow_length);
            $pow_string = " ".$pow_string;

            if ($debug)
            {
                echo "<br>pow string before:".$pow_string;
            }

            if (strpos($pow_string,'/'))
            {
                $num_denom = explode('/',$pow_string);
                $denom = $num_denom[1] + 0;
                $denom = $denom * 4;
                $pow_string = $num_denom[0]."/".$denom;
            }
            else
            {
                $pow_string = $pow_string."/4";
            }

            if ($debug)
            {
                $pow_starts = $new_pos+3;
                echo "<br>pow pos:".$pow_pos;
                echo "<br>pow length:".$pow_length;
                echo "<br>pow starts:".$pow_starts;
                echo "<br>pow string:".$pow_string;
            }

            $pow_string = trim($pow_string);
            $my_str = substr_replace($my_str,$pow_string,$new_pos+3,$pow_length);
        }
        if ($debug)
        {
            echo "<br>pos:".$pos;
            echo "<br>my_str:".$my_str;
        }
        $pos = strpos($my_str,'ftrt');
    }

    $new_str = trim($my_str);

    if ($debug)
    {
       echo "<br>Root to Powers returned:";
       echo $new_str;
       echo "<br>";
       echo "<h1> END DEBUG FOR ROOT TO POWERS</h1>";
    }
    return $new_str;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Equiv Monomials                     ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////           March 19th 2006                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   checks two monomials to see if they are equivelent
////
////   $my_bool = equiv_monomials($mono1,$mono2);
////
////   in:  $mono1, $mono2 two monomials (strings)
////
////   out:  $my_bool = TRUE if monomials are equivenlent
////                    FALSE if monomials are not
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function equiv_monomials($mono1,$mono2)
{
    $debug = FALSE;
    if ($debug)
    {
        echo "<br><center><strong>\n";
        echo "DEBUG INFO FOR EQUIV MONOMIALS\n";
        echo "</strong></center><br>";
        echo "<br> monomial 1 is ".$mono1;
        echo "<br> monomial 2 is ".$mono2;
        echo "<br>\n";
    }

    if (!strlen($mono1) || !strlen($mono2))
    {
        if ($debug)
        {
            echo "<br><center><strong>\n";
            echo "*** WARNING *** <br>";
            echo "EQUIV MONOMIALS WAS PASSED MONOMIAL OF STRING LENGTH ";
            echo "ZERO. RETURNING FALSE<br>\n";
            echo "</strong></center><br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR EQUIV MONOMIALS\n";
            echo "</strong></center><br>\n";
        }
        return FALSE;
    }

    $mono_array_1 = array();
    $mono_array_2 = array();
    $mono_size_1  = 0;
    $mono_size_2  = 0;
    $used_locale  = array();

    $mono_array_1 = parse_monomial($mono1);
    $mono_array_2 = parse_monomial($mono2);

    $mono_size_1 = count($mono_array_1[1]);
    $mono_size_2 = count($mono_array_2[1]);

    for ($j = 0; $j < $mono_size_1; $j++)
    {
        $mono_array_1[1][$j] = trim_parenth($mono_array_1[1][$j]);
        $mono_array_1[2][$j] = trim_parenth($mono_array_1[2][$j]);
    }

    for ($j = 0; $j < $mono_size_2; $j++)
    {
        $mono_array_2[1][$j] = trim_parenth($mono_array_2[1][$j]);
        $mono_array_2[2][$j] = trim_parenth($mono_array_2[2][$j]);
    }

    $coeff_size1 = count($mono_array_1[0]);
    $coeff_size2 = count($mono_array_2[0]);

    if ($debug)
    {
        echo "<br>coeff_size1:".$coeff_size1;
        echo "<br>coeff_size2:".$coeff_size2;
        echo "<br>coeff1";
        for ($i = 0; $i < $coeff_size1; $i++)
        {
            echo "<br>".$i.": ".$coeff1_array[$i];
        }
        echo "<br>coeff2";
        for ($i = 0; $i < $coeff_size2; $i++)
        {
            echo "<br>".$i.": ".$coeff2_array[$i];
        }
    }

    if ($coeff_size1 == 0)
    {
        $coeff1_array = array(1);
    }
    else if ($coeff_size1 == 1)
    {
        if ($mono_array_1[0] == NULL)
        {
            $coeff1_array = array(1);
        }
        else
        {
            $coeff1_array = array($mono_array_1[0][0]);
        }
    }
    else
    {
        $coeff1_array = $mono_array_1[0];
    }

    if ($coeff_size2 == 0)
    {
        $coeff2_array = array(1);
    }
    else if ($coeff_size2 == 1)
    {
        $coeff2_array = array($mono_array_2[0][0]);
    }
    else
    {
        $coeff2_array = $mono_array_2[0];
    }

    for ($j = 0; $j < $mono_size_1; $j++)
    {
        $length = strlen($mono_array_1[1][$j]);
        if ($length == 1)
        {
            continue;
        }
        $temp_array = parse_monomial($mono_array_1[1][$j]);

        $t_coeff_array = $temp_array[0];
        $t_coeff_size  = count($t_coeff_array);
        for ($k = 0; $k < $t_coeff_size; $k++)
        {
            $coeff1_array[] = $t_coeff_array[$k];
        }
        $t_mono_size = count($temp_array[1]);
        $mono_array_1[1][$j] = $temp_array[1][0];
        $mono_array_1[2][$j] = ($temp_array[2][0] + 0)
                             * ($mono_array_1[2][$j] + 0);
        if ($t_mono_size > 1)
        {
            for ($k = 1; $k < $t_mono_size; $k++)
            {
                $in = $mono_size_1 + $k;
                $mono_array_1[1][$in] = $temp_array[1][$k];
                $mono_array_1[2][$in] = $temp_array[2][$k]
                                      * $mono_array_1[2][$in];
            }
        }
        $mono_size_1 = count($mono_array_1[1]);
    }
    for ($j = 0; $j < $mono_size_2; $j++)
    {
        $length = strlen($mono_array_2[1][$j]);
        if ($length == 1)
        {
            continue;
        }
        $temp_array = parse_monomial($mono_array_2[1][$j]);

        $t_coeff_array = $temp_array[0];
        $t_coeff_size  = count($t_coeff_array);
        for ($k = 0; $k < $t_coeff_size; $k++)
        {
            $coeff2_array[] = $t_coeff_array[$k];
        }
        $t_mono_size = count($temp_array[1]);
        $mono_array_2[1][$j] = $temp_array[1][0];
        $mono_array_2[2][$j] = ($temp_array[2][0] + 0)
                             * ($mono_array_2[2][$j] + 0);
        if ($t_mono_size > 1)
        {
            for ($k = 1; $k < $t_mono_size; $k++)
            {
                $in = $mono_size_2 + $k;
                $mono_array_2[1][$in] = $temp_array[1][$k];
                $mono_array_2[2][$in] = ($temp_array[2][$k] + 0)
                                      * ($mono_array_2[2][$in] + 0);
            }
        }
        $mono_size_2 = count($mono_array_2[1]);
    }

    //// combine all coefficients

    $coeff_size1 = count($coeff1_array);
    $coeff_size2 = count($coeff2_array);

    if ($debug)
    {
        echo "<br>coeff_size1:".$coeff_size1;
        echo "<br>coeff_size2:".$coeff_size2;
        echo "<br>coeff1";
        for ($i = 0; $i < $coeff_size1; $i++)
        {
            echo "<br>".$i.": ".$coeff1_array[$i];
        }
        echo "<br>coeff2";
        for ($i = 0; $i < $coeff_size2; $i++)
        {
            echo "<br>".$i.": ".$coeff2_array[$i];
        }
    }

    $coeff1 = 1;
    $coeff2 = 1;

    for ($i = 0; $i < $coeff_size1; $i++)
    {
        $coeff1 = $coeff1 * ($coeff1_array[$i] + 0);
    }
    for ($i = 0; $i < $coeff_size2; $i++)
    {
        $coeff2 = $coeff2 * $coeff2_array[$i];
    }

    $mono_size_1 = count($mono_array_1[1]);
    $mono_size_2 = count($mono_array_2[1]);

    if ($debug)
    {
        echo "<br>coeff1:".$coeff1;
        echo "<br>coeff2:".$coeff2;
        echo "<br> mono1: ";
        for ($i = 0; $i < $mono_size_1; $i++)
        {
            echo "<br>var".$i.":".$mono_array_1[1][$i];
            echo "<br>pow".$i.":".$mono_array_1[2][$i];
        }
        echo "<br> mono2: ";
        for ($i = 0; $i < $mono_size_2; $i++)
        {
            echo "<br>var".$i.":".$mono_array_2[1][$i];
            echo "<br>pow".$i.":".$mono_array_2[2][$i];
        }
    }

    if ($mono_size_1 != $mono_size_2)
    {
        if ($debug)
        {
            echo "<br>MONOMIALS HAVE DIFFERENT NUMBER OF VARIABLES<br>\n";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR EQUIV MONOMIALS\n";
            echo "</center></strong><br>";
        }
        return FALSE;
    }

    if ($coeff1 != $coeff2)
    {
        if ($debug)
        {
            echo "<br> COEFFICIENTS WHERE NOT EQUAL ";
            echo "<br><center><strong>\n";
            echo "END DEBUG INFO FOR EQUIV MONOMIALS\n";
            echo "</center></strong><br>";
        }
        return FALSE;
    }

    for ($j = 0; $j < $mono_size_1; $j++)
    {
        $sim_var = FALSE;
        for ($k = 0; $k < $mono_size_2; $k++)
        {
            if (is_in($used_locale,$k))
            {
                continue;
            }
            if ($mono_array_1[1][$j] == $mono_array_2[1][$k])
            {
                if ($mono_array_1[2][$j] == $mono_array_2[2][$k])
                {
                    $used_locale[$j] = $k;
                    $sim_var = TRUE;
                    break;
                }
            }
        }
        if (!$sim_var)
        {
            if ($debug)
            {
                $temp_string  = $mono_array_1[1][$j]."^";
                $temp_string .= $mono_array_1[2][$j];
                $temp_string  = str_to_math($temp_string);

                echo "<br> COULD NOT FIND VARIABLE MATCH FOR ";
                echo $temp_string;
                echo "<br>";
                echo "<br><center><strong>\n";
                echo "END DEBUG INFO FOR EQUIV MONOMIALS\n";
                echo "</center></strong><br>";

            }
            return FALSE;
        }
    }

    if ($debug)
    {
        echo "<br> MONOMIALS ARE EQUAL ";
        echo "<br>";
        echo "<br><center><strong>\n";
        echo "END DEBUG INFO FOR EQUIV MONOMIALS\n";
        echo "</center></strong><br>";
    }

    return TRUE;
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Equiv Polynomials                   ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////           March 19th 2006                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   checks two polynomials to see if they are equivelent
////
////   $my_bool = equiv_polynomials($poly1,$poly2);
////
////   in:  $poly1, $poly2 two polynomials (strings)
////
////   out:  $my_bool = TRUE if polynomials are equivenlent
////                    FALSE if polynomials are not
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function equiv_polynomials($poly1,$poly2)
{
    $debug = FALSE;

    if ($debug)
    {
        echo "<h2> BEGIN DEBUG FOR EQUIV POLYNOMIALS </h2>";
        echo "<br> equiv_polynomials was passed: ";
        echo "<br> poly1: ".$poly1;
        echo "<br> poly2: ".$poly2;
    }

    //// switch roots to powers

    $poly1 = rt_to_pow($poly1);
    $poly2 = rt_to_pow($poly2);

    //// break both polynomials up into monomials

    $poly_array1 = parse_polynomial($poly1);
    $poly_array2 = parse_polynomial($poly2);

    //// get size of poly1 and poly2

    $size1 = count($poly_array1);
    $size2 = count($poly_array2);

    if ($size1 != $size2)
    {
        if ($debug)
        {
            echo "POLYNOMIALS DO NOT HAVE THE SAME NUMBER OF MONOMIALS";
            echo "<br>RETURNING FALSE";
            echo "<h2> END DEBUG FOR EQUIV POLYNOMIALS </h2>";
        }
        return FALSE;
    }

    $used_locale = array();

    for ($i = 0; $i < $size1; $i++)
    {
        $mono1 = $poly_array1[$i];
        for ($j = 0; $j < $size2; $j++)
        {
            $mono2 = $poly_array2[$j];
            if (is_in($used_locale,$j))
            {
                continue;
            }
            else
            {
                $equal = equiv_monomials($mono1,$mono2);
                if ($equal)
                {
                    $used_locale[] = $j;
                    break;
                }
            }
        }
        if ($j == $size2)
        {
            if ($debug)
            {
                echo "<br>POLYNOMIALS ARE DIFFERENT";
                echo "<br>COULD NOT FIND A MATCH FOR".$mono1;
                echo "<br>RETURNING FALSE";
                echo "<h2> END DEBUG FOR EQUIV POLYNOMIALS </h2>";
            }
            return FALSE;
        }
    }

    if ($debug)
    {
        echo "<br> POLYNOMIALS ARE EQUAL";
        echo "<br> RETURNING TRUE";
        echo "<h2> END DEBUG FOR EQUIV POLYNOMIALS </h2>";
    }

    return TRUE;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           Equiv Terms                         ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////           March 19th 2006                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   checks two terms are equal
////
////   $my_bool = equiv_terms($term1,$term2);
////
////   in:  $term1, $term2 factors can be
////        monomials, polynomials,
////        cannot handle polynomials or division of any kind
////        (strings)
////
////   out:  $my_bool = TRUE if terms are equivenlent
////                    FALSE if terms are not
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function equiv_terms($term1,$term2)
{
    $debug  = FALSE;
    $debug2 = FALSE;
    if ($debug)
    {
        echo "<h2>DEBUG INFO FOR EQUIV TERMS</h2>";
        echo "<br> term 1 is ".$term1;
        echo "<br> term 2 is ".$term2;
        echo "<br>\n";
    }

    if (!strlen($term1) || !strlen($term2))
    {
        if ($debug)
        {
            echo "<h2>*** WARNING *** </h2>";
            echo "EQUIV TERMS WAS PASSED MONOMIAL OF STRING LENGTH ";
            echo "ZERO. RETURNING FALSE";
            echo "<h2>END DEBUG INFO FOR EQUIV TERMSS</h2>";
        }
        return FALSE;
    }

    $term_array_1 = array();
    $term_array_2 = array();
    $term_size_1  = 0;
    $term_size_2  = 0;
    $used_locale  = array();
    $f_array1     = array();
    $f_array2     = array();
    $f_array1[]   = "";
    $f_array2[]   = "";

    $term1 = str_replace('*','',$term1);
    $term2 = str_replace('*','',$term2);
    
    $term1 = str_replace('[','(',$term1);
    $term2 = str_replace('[','(',$term2);

    $term1 = str_replace(']',')',$term1);
    $term2 = str_replace(']',')',$term2);


    $term_array_1 = parse_monomial($term1);
    $term_array_2 = parse_monomial($term2);

    $term_size_1 = count($term_array_1[1]);
    $term_size_2 = count($term_array_2[1]);

    $coeff_size1 = count($term_array_1[0]);
    $coeff_size2 = count($term_array_2[0]);

    if ($coeff_size1 == 0)
    {
        $coeff1_array = array(1);
    }
    else if ($coeff_size1 == 1)
    {
        if ($term_array_1[0] == NULL)
        {
            $coeff1_array = array(1);
        }
        else
        {
            $coeff1_array = array($term_array_1[0][0]);
        }
    }
    else
    {
        $coeff1_array = $term_array_1[0];
    }

    if ($coeff_size2 == 0)
    {
        $coeff2_array = array(1);
    }
    else if ($coeff_size2 == 1)
    {
        $coeff2_array = array($term_array_2[0][0]);
    }
    else
    {
        $coeff2_array = $term_array_2[0];
    }

    if ($debug2)
    {
        echo "<br>coeff_size1:".$coeff_size1;
        echo "<br>coeff_size2:".$coeff_size2;
        echo "<br>coeff1";
        for ($i = 0; $i < $coeff_size1; $i++)
        {
            echo "<br>".$i.": ".$coeff1_array[$i];
        }
        echo "<br>coeff2";
        for ($i = 0; $i < $coeff_size2; $i++)
        {
            echo "<br>".$i.": ".$coeff2_array[$i];
        }
        echo "<br>term 1:";
        for ($i = 0; $i < $term_size_1;$i++)
        {
            echo "<br> factor ".$i." : ".$term_array_1[1][$i];
            echo "<br> power  ".$i." : ".$term_array_1[2][$i];
        }
        echo "<br>term 2:";
        for ($i = 0; $i < $term_size_2;$i++)
        {
            echo "<br> factor ".$i." : ".$term_array_2[1][$i];
            echo "<br> power  ".$i." : ".$term_array_2[2][$i];
        }
        echo "<br><br>";
    }

    for ($j = 0; $j < $term_size_1; $j++)
    {
        $term_array_1[1][$j] = trim_parenth($term_array_1[1][$j]);
        $term_array_1[2][$j] = trim_parenth($term_array_1[2][$j]);
    }

    for ($j = 0; $j < $term_size_2; $j++)
    {
        $term_array_2[1][$j] = trim_parenth($term_array_2[1][$j]);
        $term_array_2[2][$j] = trim_parenth($term_array_2[2][$j]);
    }

    $opers = array('-','+');
    $in    = 1;

    for ($j = 0; $j < $term_size_1; $j++)
    {
        $length = strlen($term_array_1[1][$j]);
        if ($length == 1)
        {
            $f_array1[0] .= $term_array_1[1][$j];
            $temp_pow     = $term_array_1[2][$j];

            if ($temp_pow != 1)
            {
                $temp_pow = trim_parenth($temp_pow);
                $temp_pow = "(".$temp_pow.")";
                $f_array1[0] .= "^".$temp_pow;
            }
            continue;
        }
        $temp_string = $term_array_1[1][$j];
        $temp_string = trim_parenth($temp_string);
        $t_length    = strlen($temp_string);
        for ($k = 1; $k < $t_length; $k++)
        {
            if (is_in($opers,$temp_string[$k]))
            {
                $f_array1[$in][0] = $term_array_1[1][$j];
                $f_array1[$in][1] = $term_array_1[2][$j];
                $in++;
                break;
            }
        }
        if ($k < $t_length)
        {
            continue;
        }

        $temp_array = parse_monomial($temp_string);

        if ($debug)
        {
            echo "<br> temp_string".$temp_string;
        }

        $t_coeff_array = $temp_array[0];
        $t_coeff_size  = count($t_coeff_array);
        for ($k = 0; $k < $t_coeff_size; $k++)
        {
            $coeff1_array[] = $t_coeff_array[$k];
        }

        $t_term_size = count($temp_array[1]);

        for ($k = 0; $k < $t_term_size; $k++)
        {
            $temp_var = $temp_array[1][$k];
            $temp_pow = $temp_array[2][$k];

            $temp_var = trim_parenth($temp_var);
            $temp_pow = trim_parenth($temp_pow);

            if ($debug)
            {
                echo "<br>temp_var ".$k.": ".$temp_var;
                echo "<br>temp_pow ".$k.": ".$temp_pow;
            }

            $f_array1[0] .= $temp_var;
            if ($temp_pow != 1)
            {
                $temp_pow = "(".$temp_pow.")";
                $f_array1[0] .= "^".$temp_pow;
            }
        }
    }

    $in    = 1;

    for ($j = 0; $j < $term_size_2; $j++)
    {
        $length = strlen($term_array_2[1][$j]);
        if ($length == 1)
        {
            $f_array2[0] .= $term_array_2[1][$j];
            $temp_pow     = $term_array_2[2][$j];

            if ($temp_pow != 1)
            {
                $temp_pow = trim_parenth($temp_pow);
                $temp_pow = "(".$temp_pow.")";
                $f_array2[0] .= "^".$temp_pow;
            }
            continue;
        }
        $temp_string = $term_array_2[1][$j];
        $t_length    = strlen($temp_string);
        for ($k = 1; $k < $t_length; $k++)
        {
            if (is_in($opers,$temp_string[$k]))
            {
                $f_array2[$in][0] = $term_array_2[1][$j];
                $f_array2[$in][1] = $term_array_2[2][$j];
                $in++;
                break;
            }
        }
        if ($k < $t_length)
        {
            continue;
        }

        $temp_array = parse_monomial($term_array_2[1][$j]);

        $t_coeff_array = $temp_array[0];
        $t_coeff_size  = count($t_coeff_array);
        for ($k = 0; $k < $t_coeff_size; $k++)
        {
            $coeff2_array[] = $t_coeff_array[$k];
        }

        $t_term_size = count($temp_array[1]);

        for ($k = 0; $k < $t_term_size; $k++)
        {
            $temp_var = $temp_array[1][$k];
            $temp_pow = $temp_array[2][$k];

            $temp_var = trim_parenth($temp_var);
            $temp_pow = trim_parenth($temp_pow);

            $f_array2[0] .= $temp_var;
            if ($temp_pow != 1)
            {
                $temp_pow = "(".$temp_pow.")";
                $f_array2[0] .= "^".$temp_pow;
            }
        }
    }

    if ($debug)
    {
        echo "<br> f_array1[0]: ".$f_array1[0];
        echo "<br> f_array2[0]: ".$f_array2[0];
    }

    $term_array_1 = $f_array1;
    $term_array_2 = $f_array2;

    //// combine all coefficients

    $coeff_size1 = count($coeff1_array);
    $coeff_size2 = count($coeff2_array);

    if ($debug2)
    {
        echo "<br>coeff_size1:".$coeff_size1;
        echo "<br>coeff_size2:".$coeff_size2;
        echo "<br>coeff1";
        for ($i = 0; $i < $coeff_size1; $i++)
        {
            echo "<br>".$i.": ".$coeff1_array[$i];
        }
        echo "<br>coeff2";
        for ($i = 0; $i < $coeff_size2; $i++)
        {
            echo "<br>".$i.": ".$coeff2_array[$i];
        }
    }

    $coeff1 = 1;
    $coeff2 = 1;

    for ($i = 0; $i < $coeff_size1; $i++)
    {
        $coeff1 = $coeff1 * ($coeff1_array[$i] + 0);
    }
    for ($i = 0; $i < $coeff_size2; $i++)
    {
        $coeff2 = $coeff2 * $coeff2_array[$i];
    }

    $term_size_1 = count($term_array_1);
    $term_size_2 = count($term_array_2);

    if ($debug2)
    {
        echo "<br>coeff1:".$coeff1;
        echo "<br>coeff2:".$coeff2;
        echo "<br> term1: ";
        echo "<br> factor 0: ".$term_array_1[0];
        for ($i = 1; $i < $term_size_1; $i++)
        {
            echo "<br>factor ".$i.": ".$term_array_1[$i][0];
            echo "<br>factor power ".$i.": ".$term_array_1[$i][1];
        }
        echo "<br> term2: ";
        echo "<br> factor 0: ".$term_array_2[0];
        for ($i = 1; $i < $term_size_2; $i++)
        {
            echo "<br>factor ".$i.":".$term_array_2[$i][0];
            echo "<br>factor power ".$i.": ".$term_array_2[$i][1];

        }
    }

    if ($term_size_1 != $term_size_2)
    {
        if ($debug)
        {
            echo "<br>TERMS HAVE DIFFERENT NUMBER OF FACTORS<br>\n";
            echo "<h2>END DEBUG INFO FOR EQUIV TERMS</h2>";
        }
        return FALSE;
    }

    if ($coeff1 != $coeff2)
    {
        if ($debug)
        {
            echo "<br> COEFFICIENTS WHERE NOT EQUAL ";
            echo "<br> RETURNING FALSE";
            echo "<h2>END DEBUG INFO FOR EQUIV TERMS</h2>";
        }
        return FALSE;
    }

    if ($term_array_1[0] == "")
    {
        $term_array_1[0] = 1;
    }
    if ($term_array_2[0] == "")
    {
        $term_array_2[0] = 1;
    }

    if (!equiv_monomials($term_array_1[0],$term_array_2[0]))
    {
        if ($debug)
        {
            echo "<br> NON-POLYNOMIAL TERMS NOT EQUAL";
            echo "<br> RETURNING FALSE";
            echo "<h2> END DEBUG FOR EQUIV TERMS </h2> ";
        }
        return FALSE;
    }

    for ($j = 1; $j < $term_size_1; $j++)
    {
        $poly1 = $term_array_1[$j][0];
        for ($k = 1; $k < $term_size_2; $k++)
        {
            if (is_in($used_locale,$k))
            {
                continue;
            }
            $poly2 = $term_array_2[$k][0];
            if (equiv_polynomials($poly1,$poly2))
            {
                if ($term_array_1[$j][1] == $term_array_2[$k][1])
                {
                    $used_locale[$j] = $k;
                    break;
                }
            }
        }
        if ($k == $term_size_2)
        {
            if ($debug)
            {
                echo "<br> TERMS ARE DIFFERENT";
                echo "<br> Could not find like polynomial for:";
                echo $poly1;
                echo "<br> RETURNING FALSE;";
                echo "<h2> END DEBUG FOR EQUIV TERMS </h2>";
            }
            return FALSE;
        }
    }

    if ($debug)
    {
        echo "<br> TERMS ARE EQUAL ";
        echo "<h2>END DEBUG INFO FOR EQUIV TERMSS</h2>";
    }

    return TRUE;
}

?>