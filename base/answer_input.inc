<?php

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////             answer_input functions                ////
////                                                   ////
////              Originally Created by                ////
////               Gregory P Richards                  ////
////                                                   ////
////                                                   ////
////                 Last Updated                      ////
////                                                   ////
////                    On                             ////
////                July 2nd 2005                      ////
////                                                   ////
////                    By                             ////
////               Gregory P Richards                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function answer_input($number, $a_array)
{
  $i="		<table id='MathEditI' class='MathEditI'><tr><td><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp</div></td></tr>";
  $i.="   <tr><td><input name='infix_".$number."' type='text' class='in' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
  return $i;
}

function equation_answer_input($number, $a_array)
{
  $i="		<table id='MathEditI' class='MathEditI3'><tr><td></td><td width='350px'><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="  <tr><td>&nbsp;</td><td> <input name='infix_".$number."' type='text' class='in' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><tr></table>";
  return $i;
}

function interval_answer_input($number, $a_array)
{
    $i= "<table border=1 cellspacing=0>\n";
    $i.= "<tr bgcolor='#cccccc'>\n";
    $i.= "<td class='cat' background='titlebar.gif' width=700 ";
    $i.= "colspan=2 align='center'>Answer for Question #$number</td>\n";
    $i.= "</tr>\n";
    $i.= "<tr><td>\n";
    $i.= "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.= "<font size='4'>X is in&nbsp; </font></td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_left_".$number."' name='answer_single_interval_left_".$number."' onMouseOver=parenthover('answer_single_interval_left1_".$number."') onMouseOut=parenthout('answer_single_interval_left1_".$number."')>";
    $i.= "(";
    $i.= "</div><div class='parenthese1' id='answer_single_interval_left1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_left_".$number."',1) onMouseOut=parenthout(this.id)>";
    $i.= "[";
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td style='font-size=20pt' >&nbsp;,&nbsp;</td><td align='center'>\n";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_right_".$number."' name='answer_single_interval_right_".$number."' onMouseOver=parenthover('answer_single_interval_right1_".$number."') onMouseOut=parenthout('answer_single_interval_right1_".$number."')>";
    $i.= ")";
    $i.= "</div><div class='parenthese1' id='answer_single_interval_right1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_right_".$number."',2) onMouseOut=parenthout(this.id)>";
    $i.= "]";
    $i.= "</div></td>";
    $i.= "</tr>\n";
    $i.= "</table>\n";
    $i.= "<tr align='center'><td style='font-size:20pt'>-&nbsp;or&nbsp;-</td>";
    $i.= "</tr>";
    $i.= "</td></tr>\n";
    $i.= "<tr><td>\n";
    $i.= "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.= "<font size='4'>X is in&nbsp; </font></td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_double_interval_left1_".$number."' name='answer_double_interval_left1_".$number."' onMouseOver=parenthover('answer_double_interval_left11_".$number."') onMouseOut=parenthout('answer_double_interval_left11_".$number."')>";
    $i.= "(";
    $i.= "</div><div class='parenthese1' id='answer_double_interval_left11_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_double_interval_left1_".$number."',1) onMouseOut=parenthout(this.id)>";
    $i.= "[";
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present2_".$number."' onClick='showinfix(\"infix2_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix2_".$number."' type='text' class='in1' id='infix2_".$number."' onKeyUp=doIP('infix2_".$number."','present2_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td style='font-size=20pt'>,</td><td align='center'>\n";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present3_".$number."' onClick='showinfix(\"infix3_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix3_".$number."' type='text' class='in1' id='infix3_".$number."' onKeyUp=doIP('infix3_".$number."','present3_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_double_interval_right1_".$number."' name='answer_double_interval_right1_".$number."' onMouseOver=parenthover('answer_double_interval_right11_".$number."') onMouseOut=parenthout('answer_double_interval_right11_".$number."')>";
    $i.= ")";
    $i.= "</div><div class='parenthese1' id='answer_double_interval_right11_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_double_interval_right1_".$number."',2) onMouseOut=parenthout(this.id)>";
    $i.= "]";
    $i.= "</div></td><td style='font-size=20pt'>&#8746;";
    $i.= "&nbsp;</td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_double_interval_left2_".$number."' name='answer_double_interval_left2_".$number."' onMouseOver=parenthover('answer_double_interval_left21_".$number."') onMouseOut=parenthout('answer_double_interval_left21_".$number."')>";
    $i.= "(";
    $i.= "</div><div class='parenthese1' id='answer_double_interval_left21_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_double_interval_left2_".$number."',1) onMouseOut=parenthout(this.id)>";
    $i.= "[";
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present4_".$number."' onClick='showinfix(\"infix4_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="   <tr><td><input name='infix4_".$number."' type='text' class='in1' id='infix4_".$number."' onKeyUp=doIP('infix4_".$number."','present4_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td style='font-size=20pt'>,</td><td align='center'>\n";
   $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present5_".$number."' onClick='showinfix(\"infix5_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
   $i.="   <tr><td><input name='infix5_".$number."' type='text' class='in1' id='infix5_".$number."' onKeyUp=doIP('infix5_".$number."','present5_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_double_interval_right2_".$number."' name='answer_double_interval_right2_".$number."' onMouseOver=parenthover('answer_double_interval_right21_".$number."') onMouseOut=parenthout('answer_double_interval_right21_".$number."')>";
    $i.= ")";
    $i.= "</div><div class='parenthese1' id='answer_double_interval_right21_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_double_interval_right2_".$number."',2) onMouseOut=parenthout(this.id)>";
    $i.= "]";
    $i.= "</div></td></tr>";
    $i.= "</table>\n";
    $i.= "</tr></td>\n";
    $i.= "</table>\n";
    return $i;
}

function simple_interval_answer_input($number, $a_array)
{
    $i.= "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.= "<font size='4'>X is in&nbsp; </font></td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_left_".$number."' name='answer_single_interval_left_".$number."' onMouseOver=parenthover('answer_single_interval_left1_".$number."') onMouseOut=parenthout('answer_single_interval_left1_".$number."')>";
    $i.= "(";
    $i.= "</div><div class='parenthese1' id='answer_single_interval_left1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_left_".$number."',1) onMouseOut=parenthout(this.id)>";
    $i.= "[";
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td style='font-size=20pt' >&nbsp;,&nbsp;</td><td align='center'>\n";
    $i.="		<table class='MathEditI1'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.= "</td>\n";
    $i.= "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_right_".$number."' name='answer_single_interval_right_".$number."' onMouseOver=parenthover('answer_single_interval_right1_".$number."') onMouseOut=parenthout('answer_single_interval_right1_".$number."')>";
    $i.= ")";
    $i.= "</div><div class='parenthese1' id='answer_single_interval_right1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_right_".$number."',2) onMouseOut=parenthout(this.id)>";
    $i.= "]";
    $i.= "</div></td>";
    $i.= "</tr>\n";
    $i.= "</table>\n";
    return $i;
}
function domain_answer_input($number, $a_array)
{
   $i= "<table border='0' cellspacing=0>\n";
   $i.=  "<tr bgcolor='#cccccc'>\n";
   $i.=  "<td class='cat' background='titlebar.gif' width='100%' colspan=2";
    $i.=  "align='center'>\n";
    $i.=  "Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";
    $i.=  "<tr><td>";
    $i.=  "<table border='1' cellspacing='0' cellpadding='0'>\n";
    $i.=  "<tr><td >\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td style='font-size:18px'>&nbsp; X is in&nbsp; \n";
    $i.=  "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_left_".$number."' name='answer_single_interval_left_".$number."' onMouseOver=parenthover('answer_single_interval_left1_".$number."') onMouseOut=parenthout('answer_single_interval_left1_".$number."')>";
    if ($a_array != NULL && $a_array[0] == 0)
    {
        $i.= "(";
    }else if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.= "[";
    }else
    {
    	$i.= "(";
    }
    $i.= "</div><div class='parenthese1' id='answer_single_interval_left1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_left_".$number."',1) onMouseOut=parenthout(this.id)>";
    if ($a_array != NULL && $a_array[0] == 0)
    {
        $i.= "[";
    }else if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.= "(";
    }else
    {
    	$i.= "[";
    }
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1' cellpadding='0'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td style='font-size=24pt'>&nbsp;,&nbsp;</td><td>\n";
    $i.="		<table class='MathEditI1' cellpadding='0'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_right_".$number."' name='answer_single_interval_right_".$number."' onMouseOver=parenthover('answer_single_interval_right1_".$number."') onMouseOut=parenthout('answer_single_interval_right1_".$number."')>";
    if ($a_array != NULL && $a_array[5] == 0)
    {
        $i.= ")";
    }else if ($a_array != NULL && $a_array[5] == 1)
    {
        $i.= "]";
    }else
    {
    	$i.= ")";
    }
    $i.= "</div><div class='parenthese1' id='answer_single_interval_right1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_right_".$number."',2) onMouseOut=parenthout(this.id)>";
    if ($a_array != NULL && $a_array[5] == 0)
    {
        $i.= "]";
    }else if ($a_array != NULL && $a_array[5] == 1)
    {
        $i.= ")";
    }else
    {
    	$i.= "]";
    }
    $i.= "</div></td>";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";
    $i.=  "</tr></td>";
    $i.=  "<tr><td align='center' style='font-size:18px'>- And/Or - \n";
    $i.=  "</td></tr><tr><td>\n";
    $i.=" <table class='MathEditI2' cellspacing='0' cellpadding='0'><tr><td style='font-size:18px;'> X&#8800;</td><td width='60px'><div class='dis1' id='present2_".$number."' onClick='showinfix(\"infix2_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="  <tr><td>&nbsp</td><td> <input name='infix2_".$number."' type='text' class='in1' id='infix2_".$number."' onKeyUp=doIP('infix2_".$number."','present2_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    $i.=  "</tr></td>\n";
    $i.=  "</table>\n";
    return $i;
}

function domain_answer_input1($number, $a_array)
{
   $i= "<table border='0' cellspacing=0>\n";
   $i.=  "<tr bgcolor='#cccccc'>\n";
   $i.=  "<td class='cat' background='titlebar.gif' width='100%' colspan=2";
    $i.=  "align='center'>\n";
    $i.=  "Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";
    $i.=  "<tr><td>";
    $i.=  "<table border='1' cellspacing='0' cellpadding='0'>\n";
    $i.=  "<tr><td >\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td style='font-size:18px'>&nbsp; X is in&nbsp; \n";
    $i.=  "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_left_".$number."' name='answer_single_interval_left_".$number."' onMouseOver=parenthover('answer_single_interval_left1_".$number."') onMouseOut=parenthout('answer_single_interval_left1_".$number."')>";
    if ($a_array != NULL && $a_array[0] == 0)
    {
        $i.= "(";
    }else if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.= "[";
    }else
    {
    	$i.= "(";
    }
    $i.= "</div><div class='parenthese1' id='answer_single_interval_left1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_left_".$number."',1) onMouseOut=parenthout(this.id)>";
    if ($a_array != NULL && $a_array[0] == 0)
    {
        $i.= "[";
    }else if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.= "(";
    }else
    {
    	$i.= "[";
    }
    $i.= "</div></td><td align='center'>";
    $i.="		<table class='MathEditI1' cellpadding='0'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td style='font-size=24pt'>&nbsp;,&nbsp;</td><td>\n";
    $i.="		<table class='MathEditI1' cellpadding='0'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td>\n";
    $i.= "<div class='parenthese' id='answer_single_interval_right_".$number."' name='answer_single_interval_right_".$number."' onMouseOver=parenthover('answer_single_interval_right1_".$number."') onMouseOut=parenthout('answer_single_interval_right1_".$number."')>";
    if ($a_array != NULL && $a_array[5] == 0)
    {
        $i.= ")";
    }else if ($a_array != NULL && $a_array[5] == 1)
    {
        $i.= "]";
    }else
    {
    	$i.= ")";
    }
    $i.= "</div><div class='parenthese1' id='answer_single_interval_right1_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'answer_single_interval_right_".$number."',2) onMouseOut=parenthout(this.id)>";
    if ($a_array != NULL && $a_array[5] == 0)
    {
        $i.= "]";
    }else if ($a_array != NULL && $a_array[5] == 1)
    {
        $i.= ")";
    }else
    {
    	$i.= "]";
    }
    $i.= "</div></td>";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";
    $i.=  "</tr></td>";
    $i.=  "<tr><td align='center' style='font-size:18px'>- And/Or - \n";
    $i.=  "</td></tr><tr><td>\n";
    $i.=" <table class='MathEditI4' cellspacing='0' cellpadding='0'><tr><td style='font-size:18px;'> X&#8800;&nbsp;&nbsp;</td><td width='60px'><div class='dis1' id='present2_".$number."' onClick='showinfix(\"infix2_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td><td width='50px'> &nbsp;-And- &nbsp;</td><td style='font-size:18px;'> X&#8800;&nbsp;&nbsp;</td><td width='60px'><div class='dis1' id='present3_".$number."' onClick='showinfix(\"infix3_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="  <tr><td>&nbsp</td><td> <input name='infix2_".$number."' type='text' class='in1' id='infix2_".$number."' onKeyUp=doIP('infix2_".$number."','present2_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><td width='60px'> &nbsp;</td><td>&nbsp</td><td> <input name='infix3_".$number."' type='text' class='in1' id='infix3_".$number."' onKeyUp=doIP('infix3_".$number."','present3_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    $i.=  "</tr></td>\n";
    $i.=  "</table>\n";
    return $i;
}

function linear_equation_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=700 colspan=2 ";
    $i.=  "align='center'>Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp Y = &nbsp</font></td>\n";
    $i.=  "<td><font size='7'>(</font></td><td>\n";
    $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td><td><font size='7'>)</font></td>\n";
    $i.=  "<td><font size='5'>&nbsp X + &nbsp;</font></td><td>";
    $i.=  "<font size='7'>(</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n<td><font size='7'>)</font>\n";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='4'> - Or - </font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp Y = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present2_".$number."' onClick='showinfix(\"infix2_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix2_".$number."' type='text' class='in1' id='infix2_".$number."' onKeyUp=doIP('infix2_".$number."','present2_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='4'> - Or - </font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp X = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present3_".$number."' onClick='showinfix(\"infix3_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix3_".$number."' type='text' class='in1' id='infix3_".$number."' onKeyUp=doIP('infix3_".$number."','present3_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    return $i;

}

function linear_equation_reform_answer_input($number,$x_var,$y_var, $a_array)
{

    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=700 colspan=2 ";
    $i.=  "align='center'>Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp $y_var = &nbsp</font></td>\n";
    $i.=  "<td><font size='7'>(</font></td><td>\n";
     $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in1' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td><td><font size='7'>)</font></td>\n";
    $i.=  "<td><font size='5'>&nbsp $x_var + &nbsp;</font></td><td>";
    $i.=  "<font size='7'>(</font></td>\n";
    $i.=  "<td>\n";
   $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in1' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "<td><font size='7'>)</font>\n";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='4'> - Or - </font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp $y_var = &nbsp</font></td>\n";
    $i.=  "<td>\n";
     $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present2_".$number."' onClick='showinfix(\"infix2_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix2_".$number."' type='text' class='in1' id='infix2_".$number."' onKeyUp=doIP('infix2_".$number."','present2_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='4'> - Or - </font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' cellpadding='0'><tr><td>\n";
    $i.=  "<font size='5'>&nbsp $x_var = &nbsp</font></td>\n";
    $i.=  "<td>\n";
     $i.="		<table id='MathEditI' class='MathEditI1'><tr><td><div class='dis1' id='present3_".$number."' onClick='showinfix(\"infix3_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix3_".$number."' type='text' class='in1' id='infix3_".$number."' onKeyUp=doIP('infix3_".$number."','present3_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    return $i;
}

function simple_answer_input($number, $a_array)
{
    $i.=  "<input name='infix_".$number."' type='text' class='in' id='infix_".$number."' size='26'></input>";
    return $i;
}

function compare_tax_answer_input($number, $a_array)
{
    $i.=  "<table border=0 cellspacing=0 width=400>\n";
    $i.=  "<tr>";
    $i.=  "<td>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";  
    $i.=  " value=1>A.The Graduated Tax is Larger.</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<input type=radio id='single2_".$number."' name='single_".$number."' ";
   
    $i.=  " value=2>B.The Flat Tax is Larger.</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<input type=radio id='single3_".$number."' name='single_".$number."' ";
    $i.=  " value=3>C.The Taxes are Equal.</td></tr>\n";
    $i.=  "</table>\n";
    return $i;
}

function tax_equation_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=800 align='center'>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>";
    $i.=  "<table border='0' cellspacing='0' cellpadding='1' align='center'>\n";
    $i.=  "<tr><td valign='center' rowspan='2'><i>g</i>( <i>i</i> ) = </td>\n";
    $i.=  "<td valign='center' rowspan='2'><font size='7'>{</font></td>";
    $i.=  "<td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=400> <i>i</i></td><td>for <i>i</i> <u>&#60;</u> $";
    $i.=  "<input type=text  id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=400></td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<input type=text id='infix2_".$number."' name='infix2_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[2];
    $i.=  "' ";
    $i.=  "maxlength=400> + ";
    $i.=  "<input type=text  id='infix3_".$number."' name='infix3_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[3];
    $i.=  "' ";
    $i.=  "maxlength=400> ( <i>i</i> - ";
    $i.=  "<input type=text  id='infix4_".$number."' name='infix4_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[4];
    $i.=  "' ";
    $i.=  "maxlength=400> )&nbsp;&nbsp;&nbsp; </td><td>\n";
    $i.=  " for <i>i</i> &#62; $";
    $i.=  "<input type=text id='infix5_".$number."' name='infix5_".$number."'";
    $i.=  $number;
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[5];
    $i.=  "' ";
    $i.=  "maxlength=400></td>\n";
    $i.=  "</tr></table>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    return $i;
}

function sci_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 ";
    $i.=  "cellpadding=0><tr><td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=8 ";
    $i.=  "value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td><td><font size=5>&nbsp; * 10</font></td><td>";
    $i.=  "<input type=text id='infix1_".$number."' name='infix_".$number."'";
    $i.=  " size=3 ";
    $i.=  "value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80><br><br></td>";
    $i.=  "</tr></table></td></tr></table>\n";
    return $i;
}

function common_log_form_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 ";
    $i.=  " cellpadding=0><tr><td>";
    $i.=  "<font size=5>log &nbsp;</font></td><td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=12 ";
    $i.=  "value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td><td><font size=5>&nbsp; = &nbsp;";
    $i.=  "</font></td><td>";
    $i.=  "<input type=text id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=12 ";
    $i.=  "value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</tr></table></td></tr></table>\n";
    return $i;

}

function easy_exp_form_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 ";
    $i.=  " cellpadding=0><tr><td>";
    $i.=  "<font size=5>10</font></td><td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=4 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80><br><br></td><td><font size=5>&nbsp;";
    $i.=  " = &nbsp;</font></td><td>";
    $i.=  "<input type=text id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=12 ";
    $i.=  "value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</tr></table></td></tr></table>\n";
    return $i;

}

function growth_vs_decay_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=400 >";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n<tr>";
    $i.=  "<td align='center'>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>The equation represents growth.</td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  "  CHECKED ";
    }
    $i.=  " value=2>The equation represents decay.</td>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
    return $i;
}

function initial_pop_growth_rate_answer_input($number, $a_array)
{
    $i.=  "<table border=0 cellspacing=1 cellpadding=1><tr><td>";
    $i.=  "<font size=5>Initial Population:</font></td><td>";
    $i.=  "<input type=text  id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80>&nbsp;&nbsp;&nbsp;</td><tr><td><font size=5>";
    $i.=  " Growth Rate:</font></td><td>";
    $i.=  "<input type=text  id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</tr></table>";
    return $i;
}

function simple_answer_percentage_input($number, $a_array)
{
    $i.=  "&nbsp;&nbsp;<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=8 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80>&nbsp;%<br/>";
    return $i;
}

function exponential_equation_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0 width='400px'>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' >";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 ";
    $i.=  " cellpadding=0><tr><td>";
    $i.=  "<font size=5>P(t) = &nbsp;</font></td><td>";
    $i.=  "<input type=text  id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td><td><font size=5>&nbsp; * (&nbsp; </font></td><td>";
    $i.=  "<input type=text  id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80><font size=5> )<sup>t</sup></font>&nbsp;&nbsp;</td>";
    $i.=  "</tr></table></td></tr></table>\n";
    return $i;
}

function compare_salary_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=400 >";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n<tr>";
    $i.=  "<td align='center'>";
     $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>Job A &nbsp;&nbsp;&nbsp;&nbsp;</td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>Job B &nbsp;&nbsp;&nbsp;</td>\n";
    $i.=  "<td align=center>\n";
     $i.=  "<input type=radio id='single3_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 3)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=3>They would pay the same.</td>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
    return $i;
}

function growth_type_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=400 >";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n<tr>";
    $i.=  "<td align='center'>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>Linear Growth &nbsp;&nbsp;&nbsp;&nbsp;</td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>Linear Decay &nbsp;&nbsp;&nbsp;</td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single3_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 3)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=3>Exponential Growth &nbsp;&nbsp;&nbsp;</td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single4_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 4)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=4>Exponential Decay</td>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
    return $i;
}

function exponential_equation_2_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 ";
    $i.=  " cellpadding=0><tr><td>";
    $i.=  "<font size=5>A(t) = &nbsp;</font></td><td>";
    $i.=  "<input type=text name=answer_numerator_";
    $i.=  $number;
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td><td><font size=5>&nbsp; * (&nbsp;";
    $i.=  " </font></td><td>";
    $i.=  "<input type=text name=answer_denominator_";
    $i.=  $number;
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80><font size=5> )<sup>t</sup></font>&nbsp;&nbsp;</td>";
    $i.=  "</tr></table></td></tr></table>\n";
    return $i;
}

function simple_answer_money_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>";
    $i.=  "$ &nbsp;<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=8 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</table>\n";
    return $i;
}

function simple_answer_t_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>";
    $i.=  "t = &nbsp;<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=8 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</table>\n";
    return $i;
}

function expanded_logarithm_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0  width=850>\n";
    $i.=  "<tr bgcolor=#cccccc align=center>\n";
    $i.=  "<td class='cat' background='titlebar.gif'>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>";

    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n";
    $i.=  "<tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff1_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff1_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base1_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[2];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside1_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[3];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside1_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[4];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>)</font>";

    $i.=  "</td></tr></table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td><font size=6><b> - or - </b></font>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>";

    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n";
    $i.=  "<tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff2_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[5];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff2_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[6];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base2_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[7];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside2_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[8];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside2_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[9];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>) +&nbsp;</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff3_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[10];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff3_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[11];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base3_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[12];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside3_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[13];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside3_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[14];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>)</font>";

    $i.=  "</td></tr></table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>";
    $i.=  "<font size=6><b> - or - </b></font>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>";

    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n";
    $i.=  "<tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff4_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[15];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff4_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[16];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base4_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[17];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside4_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[18];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside4_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[19];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>) +&nbsp;</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff5_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[20];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff5_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[21];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base5_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[22];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside5_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[23];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside5_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[24];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>) +&nbsp;</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff6_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[25];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_coeff6_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[26];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>log</font>\n";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr><td><br></td></tr><tr><td><br></td></tr>";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_base6_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[27];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>(</font>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=0>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside6_num_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[28];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=50 height='1'>";
    $i.=  "</span>";
    $i.=  "</td></tr>\n";
    $i.=  "<tr align=center><td>\n";
    $i.=  "<input type=text name=answer_inside6_denom_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[29];
    $i.=  "' ";
    $i.=  " maxlength=12>";
    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td><td>\n";

    $i.=  "<font size=7>)</font>";

    $i.=  "</td></tr></table>\n";

    $i.=  "</td></tr>";
    $i.=  "</table>\n";
    return $i;
}

function single_logarithm_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td><table border=0 cellpadding=2 cellspacing=0>\n";

    $i.=  "<tr><td rowspan=3>";

    $i.=  "<font size=7> log</font>";

    $i.=  "</td><td></td><td rowspan=3><font size=7>(&nbsp;</td><td>";

    $i.=  "<input type=text name=answer_num1_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td><td>* &nbsp;&nbsp;</td><td>\n";

    $i.=  "<input type=text name=answer_num2_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td><td>* &nbsp;&nbsp;</td><td>\n";

    $i.=  "<input type=text name=answer_num3_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[2];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td><td rowspan=3><font size=7>)</font></td></tr>\n";

    $i.=  "<tr><td></td><td colspan=5>";

    $i.=  "<span class='midline'>";
    $i.=  "<img src='Images/1px.gif' width=250 height='1'>";
    $i.=  "</span>";

    $i.=  "</td></tr>\n";

    $i.=  "<tr><td>";

    $i.=  "<input type=text name=answer_base_";
    $i.=  $number;
    $i.=  " size=2";
    $i.=  " value='";
    $i.=  $a_array[3];
    $i.=  "' ";
    $i.=  " maxlength=6>";

    $i.=  "</td><td>\n";

    $i.=  "<input type=text name=answer_denom1_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[4];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td><td>* &nbsp;&nbsp;</td><td>\n";

    $i.=  "<input type=text name=answer_denom2_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[5];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td><td>* &nbsp;&nbsp;</td><td>\n";

    $i.=  "<input type=text name=answer_denom3_";
    $i.=  $number;
    $i.=  " size=5";
    $i.=  " value='";
    $i.=  $a_array[6];
    $i.=  "' ";
    $i.=  " maxlength=20>";

    $i.=  "</td></tr></table>";

    $i.=  "</td></tr>";
    $i.=  "</table>\n";
    return $i;
}

function simple_answer_x_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  "Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>";
    $i.=  "&nbsp; x = &nbsp;<input type=text name=answer_numerator_";
    $i.=  $number;
    $i.=  " size=8 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td>";
    $i.=  "</table>\n";
    return $i;
}


function quadratic_equation_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' ";
    $i.=  " width=700 colspan=2 align='center'>";
    $i.=  " Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' ";
    $i.=  " cellpadding='0' width='100%'>";
    $i.=  "<tr><td align='right'>\n";
    $i.=  "<font size='5'>&nbsp X = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI2'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in2' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td><font size='5'> - or - </font>";
    $i.=  "</td><td align=right><font size=5>";
    $i.=  " X = &nbsp;</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI1' class='MathEditI2'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in2' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='5'>- or - &nbsp;&nbsp;&nbsp;</font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td align='center'>\n";

    $i.=  "<input type=checkbox id='check_".$number."' name='check_".$number."'";
    $i.=  "' ";
    $i.=  "><font size=5> The equation has no real solutions. </font>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    return $i;
}

function exponential_equation_3_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0 width='400px'>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif'>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td>";
    $i.=  "<table border=0 cellspacing=0 cellpadding=0><tr><td>";
    $i.=  "<font size=5>N(t) = &nbsp;</font></td><td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=6 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80></td><td>";
    $i.=  "<font size=5>&nbsp; *</font><font size=7> e</font></td><td>";
    $i.=  "<input type=text id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size=12 ";
    $i.=  " value='";
    $i.=  $a_array[1];
    $i.=  "' ";
    $i.=  "maxlength=80><font size=5> t </font><br><br></td>";
    $i.=  "</tr></table></td></tr></table>\n";
     return $i;
}

function end_behavior_1_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=200>";
    $i.=  " Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 cellpadding=0>";
    $i.=  "<tr><td>";
    $i.=  "<font size=5><i>x</i></font></td><td>";
    $i.=  "<input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size=2 ";
    $i.=  " value='";
    $i.=  $a_array[0];
    $i.=  "' ";
    $i.=  "maxlength=80><br><br></td><td>";
    $i.=  "<font size=5>&nbsp; &asymp; &nbsp;f(<i>x</i>)</font></td>";
    $i.=  "</tr></table></td></tr></table>\n";
     return $i;
}

function end_behavior_2_answer_input($number, $a_array)
{
    $inf     = "<font size=4>&#8734;</font>";
    $goes_to = "<font size=4>&rarr;</font>";

    $i.=  "<table border=3 cellspacing=0 width='450px'>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' >";
    $i.=  "Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td><table border=0 cellspacing=0 cellpadding=0>";
    $i.=  "<tr><td>";
    $i.=  "<table border=2 cellspacing=0 cellpadding=4 align='center'>\n";
    $i.=  "<tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>1.";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; f(x) $goes_to $inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; f(x) $goes_to $inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>2.";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; f(x) $goes_to -$inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; f(x) $goes_to -$inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr><tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single3_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 3)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=3>3.";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; f(x) $goes_to $inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; f(x) $goes_to -$inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single4_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 4)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=4>4.";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; f(x) $goes_to -$inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; f(x) $goes_to $inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr><tr><td colspan=2 align='center'>";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single5_".$number."'  name='single_".$number."' ";
    $i.=  $number;
    if ($a_array != NULL && $a_array[0] == 5)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=5>5.";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; f(x) $goes_to 0<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; f(x) $goes_to 0";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
     return $i;
}

function end_behavior_3_answer_input($number, $a_array)
{
      $i="		<table id='MathEditI' class='MathEditI3'><tr><td>P(x)&asymp;</td><td width='350px'><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="  <tr><td>&nbsp;</td><td> <input name='infix_".$number."' type='text' class='in' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><tr></table>";
  return $i;
}

function end_behavior_4_answer_input($number, $a_array)
{
    $inf     = "<font size=4>&#8734;</font>";
    $goes_to = "<font size=4>&rarr;</font>";

    $i.=  "<table border=3 cellspacing=0 width='450px'>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' >";
    $i.=  "Answer for Question #$number</td></tr>\n";
    $i.=  "<tr align='center'><td>";
    $i.=  "<table border=0 cellspacing=0 cellpadding=0><tr><td>";
    $i.=  "<table border=0 cellspacing=0 cellpadding=4 align='center'>\n";
    $i.=  "<tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>\n";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; P(x) $goes_to $inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; P(x) $goes_to $inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>\n";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; P(x) $goes_to -$inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; P(x) $goes_to -$inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr><tr><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single3_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 3)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=3>\n";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; P(x) $goes_to $inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; P(x) $goes_to -$inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td><td>\n";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single4_".$number."'  name='single_".$number."' ";
    $i.=  $number;
    if ($a_array != NULL && $a_array[0] == 4)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=4>\n";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; P(x) $goes_to -$inf<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; P(x) $goes_to $inf";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr><tr><td colspan=2 align='center'>";

    $i.=  "<table border=0 cellspacing=0 cellpadding=2>\n";
    $i.=  "<tr align='center'><td>\n";
    $i.=  "<input type=radio id='single5_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 5)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=5>\n";
    $i.=  "</td><td>\n";
    $i.=  "As x $goes_to $inf ; P(x) $goes_to 0<br>";
    $i.=  "&nbsp;As x $goes_to -$inf ; P(x) $goes_to 0";
    $i.=  "</td></tr></table>";

    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
     return $i;
}

function proportion_1_answer_input($number, $a_array)
{
    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n";
    $i.=  "<tr><td align='left'>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>1.The function is directly proportional.</td></tr>";
    $i.=  "<tr><td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>2.The function is inversely proportional.</td>\n";
    $i.=  "</td></tr></table>\n";
     return $i;
}

function proportion_2_answer_input($number, $a_array)
{

  $i="		<table id='MathEditI' class='MathEditI3'><tr><td>f(x) will be</td><td width='300px'><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="  <tr><td>&nbsp;</td><td> <input name='infix_".$number."' type='text' class='in3' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><tr></table>";
  return $i;
}

function zero_behavior_answer_input($number, $a_array)
{

    $i.=  "<table border=0 cellspacing=0 cellpadding=1>\n<tr><td align='left'>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1>1.The function crosses the x-axis.</td></tr>";
    $i.=  "<tr><td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2>2.The function touches but does not cross the x-axis.</td>\n";
    $i.=  "</td></tr></table>\n";
     return $i;
}

function quadratic_equation_2_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' ";
    $i.=  " width=700 colspan=2 align='center'>";
    $i.=  " Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' ";
    $i.=  " cellpadding='0' width='100%'>";
    $i.=  "<tr><td align='right'>\n";
    $i.=  "<font size='5'>&nbsp X = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI2'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in2' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td><font size='5'> - or - </font>";
    $i.=  "</td><td align=right><font size=5>";
    $i.=  " X = &nbsp;</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI1' class='MathEditI2'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in2' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='5'>- or - &nbsp;&nbsp;&nbsp;</font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td align='center'>\n";

    $i.=  "<input type=checkbox id='check_".$number."' name='check_".$number."'";
    $i.=  "' ";
    $i.=  "><font size=5> The function has no real zeros. </font>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";

    return $i;
}

function standard_form_answer_input($number, $a_array)
{
  $i="		<table id='MathEditI' class='MathEditI5'><tr><td>f(x)=</td><td width='350px'><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="  <tr><td>&nbsp;</td><td> <input name='infix_".$number."' type='text' class='in' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><tr></table>";
  return $i;
}
function translation_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=700>";
    $i.=  " Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<table cellspacing=2 cellpadding=4 width='100%'>\n";
    $i.=  "<tr>";
    $i.=  "<td><font size=5>Translated &nbsp;</font></td>\n";
    $i.= "<td><div class='orient' id='select0_".$number."' name='select0_".$number."' onMouseOver=parenthover('select01_".$number."') onMouseOut=parenthout('select01_".$number."')>";
    $i.= "Left";
    $i.= "</div><div class='orient1' id='select01_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'select0_".$number."',1) onMouseOut=parenthout(this.id)>";
    $i.= "Right";
    $i.= "</div></td>";
    $i.=  "<td><input type=text id='infix_".$number."' name='infix_".$number."'";
    $i.=  " size='12' ";
    $i.=  " value='";
    $i.=  $a_array[2];
    $i.=  "' ";
    $i.=  "maxlength='12'>";
    $i.=  "<font size=5> units.</font></td></tr>";

     $i.=  "<tr>";
    $i.=  "<td><font size=5>Translated &nbsp;</font></td>\n";
    $i.= "<td><div class='orient' id='select1_".$number."' name='select1_".$number."' onMouseOver=parenthover('select11_".$number."') onMouseOut=parenthout('select11_".$number."')>";
    $i.= "Up";
    $i.= "</div><div class='orient1' id='select11_".$number."' onMouseOver=parenthover(this.id) onClick=changep(this.id,'select1_".$number."',2) onMouseOut=parenthout(this.id)>";
    $i.= "Down";
    $i.= "</div></td>";
    $i.=  "<td><input type=text id='infix1_".$number."' name='infix1_".$number."'";
    $i.=  " size='12' ";
    $i.=  " value='";
    $i.=  $a_array[2];
    $i.=  "' ";
    $i.=  "maxlength='12'>";
    $i.=  "<font size=5> units.</font></td></tr>";
    
    $i.=  "<tr>";
    $i.=  "<td colspan='3'>";
    $i.=  "<input type=checkbox id='check_".$number."' name='check_".$number."'";
    $i.=  " value='1'><font size=5>Reflected about the x-axis</font>\n";
    $i.=  "</td>\n";

    $i.=  "</tr></table>\n";
    $i.=  "</tr></table>\n";
     return $i;

}

function length_width_answer_input($number, $a_array)
{
    $i.=  "<table border='0' cellspacing='0' cellpadding='0' width='100%'>";
    $i.=  "<tr><td align='right'>\n";
    $i.=  "<font size='5'>&nbsp L = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI2'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in2' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td><font size='5'> - and - </font></td>";
    $i.=  "<td align=right><font size=5>";
    $i.=  " W = &nbsp;</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI2'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in2' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";


     return $i;
}


function multiple_choice_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor=#cccccc>\n";
    $i.=  "<td class='cat' background='titlebar.gif' width=400 >";
    $i.=  "Answer for Question #$number</td></tr>\n";
    $i.=  "<tr><td>\n";
    $i.=  "<table border=2 cellspacing=4 cellpadding=8>\n";
    $i.=  "<tr><td align='center'>";
    $i.=  "<input type=radio id='single1_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 1)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=1><font size=4>A</font></td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single2_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 2)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=2><font size=4>B</font></td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single3_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 3)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=3><font size=4>C</font></td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single4_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 4)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=4><font size=4>D</font></td>\n";
    $i.=  "<td align=center>\n";
    $i.=  "<input type=radio id='single5_".$number."'  name='single_".$number."' ";
    if ($a_array != NULL && $a_array[0] == 5)
    {
        $i.=  " CHECKED ";
    }
    $i.=  " value=5><font size=4>E</font></td>\n";
    $i.=  "</td></tr></table>\n";
    $i.=  "</td></tr></table>\n";
     return $i;
}

function projectile_2_answer_input($number, $a_array)
{
    $i.=  "<table border=3 cellspacing=0>\n";
    $i.=  "<tr bgcolor='#cccccc'>\n";
    $i.=  "<td class='cat' background='titlebar.gif' ";
    $i.=  " width=700 colspan=2 align='center'>";
    $i.=  " Answer for Question #$number</td>\n";
    $i.=  "</tr>\n";

    $i.=  "<tr><td>\n";
    $i.=  "<table border='0' cellspacing='0' ";
    $i.=  " cellpadding='0' width='100%'>";
    $i.=  "<tr><td align='right'>\n";
    $i.=  "<font size='5'>&nbsp t = &nbsp</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI' class='MathEditI2'><tr><td><div class='dis1' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix_".$number."' type='text' class='in2' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "<td><font size='5'> - or - </font>";
    $i.=  "</td><td align=right><font size=5>";
    $i.=  " t = &nbsp;</font></td>\n";
    $i.=  "<td>\n";
    $i.="		<table id='MathEditI1' class='MathEditI2'><tr><td><div class='dis1' id='present1_".$number."' onClick='showinfix(\"infix1_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
    $i.="   <tr><td><input name='infix1_".$number."' type='text' class='in2' id='infix1_".$number."' onKeyUp=doIP('infix1_".$number."','present1_".$number."') onBlur='hideinfix(this.id)' size='26'></input></td></tr></table>";
    $i.=  "</td>\n";
    $i.=  "</tr>\n";
    $i.=  "</table>\n";

    $i.=  "</td></tr>\n";
    $i.=  "<tr><td align='center'>\n";
    $i.=  "<font size='5'>- or - &nbsp;&nbsp;&nbsp;</font>\n";
    $i.=  "</td></tr>\n";

    $i.=  "<tr><td align='center'>\n";

    $i.=  "<input type=checkbox id='check_".$number."' name='check_".$number."'";
    $i.=  "' ";
    $i.=  "><font size=5> It never happens. </font>";

    $i.=  "</td></tr>\n";
    $i.=  "</table>\n";
    return $i;
}

function projectile_1_answer_input($number, $a_array)
{
      $i="		<table id='MathEditI' class='MathEditI3'><tr><td>h=</td><td width='350px'><div class='dis' id='present".$number."' onClick='showinfix(\"infix_".$number."\")'>&nbsp;&nbsp;&nbsp;&nbsp;</div></td></tr>";
  $i.="  <tr><td>&nbsp;</td><td> <input name='infix_".$number."' type='text' class='in' id='infix_".$number."' onKeyUp=doIP('infix_".$number."','present".$number."') onBlur='hideinfix(this.id)' size='26'></input></td><tr></table>";
  return $i;
}

?>

