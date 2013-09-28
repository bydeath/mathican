<?php




////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////                                                            ////
////                   A couple of notes                        ////
////                                                            ////
////    every function returns an array                         ////
////    the array is in the form                                ////
////              (question,                                    ////
////               answer numerator,                            ////
////               answer denominator,                          ////
////               answer2 numerator,                           ////
////               answer2 denominator,                         ////
////               special instructions)                        ////
////                                                            ////
////    for a complete list of specific question types          ////
////       see developer documentation                          ////
////                                                            ////
////    a written discription of each problem will be included  ////
////    in the "faq-for-teachers" file that is yet to be        ////
////    completed.                                              ////
////                                                            ////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #1 generator               ////
////         Multiplication of Fractions 1             ////
////             Simple Fractions                      ////
////               a/b * (c*b)/d                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

if( !function_exists( "bcdiv" ) )
{
    function bcdiv( $first, $second, $scale = 0 )
    {
        $res = $first / $second;
        return round( $res, $scale );
    }
}
if( !function_exists( "bcmul" ) )
{
  function bcmul($_ro, $_lo, $_scale=0)
  {
    return round($_ro*$_lo, $_scale);
  }
}
//gmp_gcd($a+$d,$a*$b)
if( !function_exists( "gmp_gcd" ) )
{
	function gmp_gcd($a, $b)
	{
	    if ($a == 0 || $b == 0)
	        return abs( max(abs($a), abs($b)) );      
	    $r = $a % $b;
	    return ($r != 0) ? gmp_gcd($b, $r) : abs($b);
	}
}
function gen_1()
{
    $a = rand(1,4);
    $b = rand(3,6);
    while($a == $b)
    {
        $a = rand(1,4);
    }
    $c = rand(1,4);
    while ($c == $b)
    {
        $c = rand(1,4);
    }
    $d = rand(1,7);
    while ($d == $c || $d == $b)
    {
        $d = rand(1,7);
    }
    $a = r_prime($a);
    $b = r_prime($b);
    $c = r_prime($c);
    $d = r_prime($d);
    $temp = $c * $b;
    if ($randy == 1)
    {
        $question = $a."/".$b."#".$temp."/".$d;
    }
    else // randy == 2
    {
        $question = $temp."/".$d."#".$a."/".$b;
    }
    $temp = $a * $c;
    reduce($temp,$d);
    if($d!=1)
     $temp=$temp."/".$d;
    $answer = array($question,$temp,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #2 generator               ////
////         Multiplication of Fractions 2             ////
////             Compound Fractions                    ////
////          A 1/2 * b / ( c * (A * 2 + 1))           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_2()
{
    $A = rand(2,5);
    $b = rand(2,5);
    $c = rand(2,4);
    $temp = $c*($A *2+1);
    while ($b == $temp)
    {
       $b = rand(2,5);
    }
    $temp2 = $b;
    reduce($b,$temp);
    $question = $A."'1/2 # ".$b."/".$temp;
    $temp = $c * 2;
    $b = $temp2;
    reduce($b,$temp);
    if($temp!=1)
     $b=$b."/".$temp;
    $answer = array($question,$b,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #3 generator               ////
////           Division of Fractions 1                 ////
////           A  /  1/b                               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_3()
{
    $A = rand(5,15);
    $b = rand(2,4);
    $temp = $A * $b;
    $question = $A." @ 1/".$b;
    $answer = array($question,$temp,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #4 generator               ////
////           Division of Fractions 2                 ////
////           A  1/2  /  b * (2 * A + 1 )             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_4()
{
    $A = rand(1,6);
    $b = rand(2,5);
    $temp = $b * ( 2 * $A +1) ;
    $question = $A."'1/2 @ ".$temp;
    $temp = 2 * $b;
    $answer = array($question,"1/".$temp,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #5 generator               ////
////           Division of Fractions 3                 ////
////           A b/c  / D e/f                          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_5()
{
    $randy = rand(1,2);
    $A = rand(1,6);
    $D = rand(1,6);
     while ($A == $D)
    {
        $D = rand (1,6);
    }
    $b = rand(1,2);
    $e = rand(1,2);
    if ($randy == 1)
    {
        if ($b == 2 || $e == 2)
        {
            $c = rand(2,4);
            $f = rand(2,4);
            $c = r_prime($c);
            $f = r_prime($f);
            $f = $f * $c;
        }
        else
        {
            $c = rand(2,7);
            $f = rand(2,4);
            $f = $f * $c;
        }
    }
    else
    {
        if ($b == 2 || $e == 2)
        {
            $f = rand(2,4);
            $c = rand(2,4);
            $c = r_prime($f);
            $f = r_prime($f);
            $c = $c * $f;
        }
        else
        {
            $f = rand(2,7);
            $c = rand(2,4);
            $c = $f * $c;
        }
    }
    $question = $A."'".$b."/".$c."@".$D."'".$e."/".$f;
    $numerator = $f * ($A * $c + $b);
    $denominator = $c * ($D * $f + $e);
    reduce($numerator,$denominator,25);
    $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////       Question type #6 generator                  ////
////        Addition of Fractions 1                    ////
////          Simple Fractions                         ////
////            a / b + c / d                          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_6()
{
    $a = rand(1,6);
    $b = rand(($a+1),7);
    $c = rand(1,6);
    $d = rand(($c+1),7);
    reduce($a,$b);
    reduce($c,$d);
    $question = $a."/".$b." + ".$c."/".$d;
    $numerator = $a*$d+$b*$c;
    $denominator = $b * $d;
    reduce($numerator,$denominator,9);
    If($Denominator!=1)
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////       Question type #7 generator                  ////
////         Addition of Fractions 2                   ////
////          Compound Fractions                       ////
////          A b / c + D e / f                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_7()
{
    $A = rand(1,5);
    $b = rand(1,6);
    $c = rand(($b+1),7);
    $D = rand(1,5);
    $e = rand(1,6);
    $f = rand(($e+1),7);
    reduce($b,$c);
    reduce($e,$f);
    $question = $A."'".$b."/".$c."+".$D."'".$e."/".$f."";
    $numerator = $f*($A*$c+$b) + $c*($D*$f+$e);
    $denominator = $c * $f;
    reduce($numerator,$denominator,9);
    if($denominator!=1)
    $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////       Question type #8 generator                  ////
////         Subtraction of Fractions 1                ////
////           Simple Fractions                        ////
////             a / b - c / d                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_8()
{
    $a = rand(1,6);
    $b = rand(($a+1),7);
    $c = rand(1,6);
    $d = rand(($c+1),7);
    reduce($a,$b);
    reduce($c,$d);
    $question = $a."/".$b." - ".$c."/".$d;
    $numerator = $a * $d - $b * $c;
    $denominator = $b * $d;
    reduce($numerator,$denominator,10);
    if ($numerator == 0)
    {
        $answer = array($question,"0","1",0,0,0);
    }
    else
    {
    	  $numerator=$numerator."/".$denominator;
        $answer = array($question,$numerator,1,0,0,0);
    }
    return $answer;
 }

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question type #9 generator                 ////
////        Subtraction of Fractions 2                 ////
////         Compound Fractions                        ////
////         A b / c - D e / f                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_9( )
{
    $A = rand(1,5);
    $b = rand(1,6);
    $c = rand(($b+1),7);
    $D = rand(1,5);
    $e = rand(1,6);
    $f = rand(($e+1),7);
    reduce($b,$c);
    reduce($e,$f);
    $question = $A."'".$b."/".$c."-".$D."'".$e."/".$f;
    $numerator = $f*($A*$c+$b) - $c*($D*$f+$e);
    $denominator = $f * $c;
    reduce($numerator,$denominator,10);
    if ($numerator == 0)
    {
        $answer = array($question,"0","1",0,0,0);
    }
    else
    {
        if($denominator!=1)
         $numerator=$numerator."/".$denominator;
        $answer = array($question,$numerator,1,0,0,0);
    }
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #10 generator              ////
////            Properties of Fractions 1              ////
////              a - b^2 / c^2 - c^2                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_10( )
{
    $a = rand(2,24);
    $b = rand(2,6);
    $c = rand(2,5);
    $temp = $b * $b;
    while ($temp == $a)
    {
        $a = rand(2,24);
    }
    $c_squared = $c * $c;
    $question ="(". $a." - ".$b."^2 )/(".$c_squared." - ".$c."^2)";
    $answer = array($question,"undefined","1",0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #11 generator              ////
////           Properties of Fractions 2               ////
////               a^2 - a^2 / b                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_11()
{
    $a = rand(2,5);
    $b = rand(2,5);
    while ($a == $b)
    {
        $b = rand(2,5);
    }
    $a_squared = $a * $a;
    $question = "(".$a."^2 - ".$a_squared.")/".$b;
    $answer = array($question,"0","1",0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question type #12 generator              ////
////           Properties of Fractions 3               ////
////             a^2 - b^2 / c^2                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_12()
{
    $a = rand(2,5);
    $b = rand(2,5);
    $c = rand(2,25);
    while ($a == $b)
    {
        $b = rand(2,5);
    }
    $question ="(".$a."^2 - ".$b."^2)/".$c;
    $numerator = $a*$a - $b*$b;
    $denominator = $c;
    reduce($numerator,$denominator);
    if($denominator!=1)
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////            Question type #13 generator            ////
////              Order of Operations 1                ////
////             a + (b * (c + d * (e - f)))           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_13()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,9);
    $d = rand(2,9);
    $e = rand(2,9);
    $f = rand(2,9);
    rand_switch_sign($d,2);
    $numerator = $a + ($b * ($c + $d * ($e - $f)));
    $numerator = (string)$numerator;
    $f = (-1) * $f;
    coeff_prep($b);
    coeff_prep($d);
    coeff_prep($f,0);
    $question = $a.$b."*[".$c.$d."(".$e." ".$f.")]";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////            Question type #14 generator            ////
////              Order of Operations 2                ////
////             [ a  ( c +- b ) +- d]^2               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_14()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(4,9);
    $b = rand(1,4);
    $c = rand($b+2,9);
    $temp = $a * ($c - $b);
    $d = rand($temp - 4, $temp - 1);
    $temp = $temp - $d;
    $numerator = pow($temp,2);
    $numerator = (string)$numerator;
    $b = (-1) * $b;
    $d = (-1) * $d;
    coeff_prep($b,0);
    coeff_prep($d,0);
    $question = "[".$a."*(".$c." ".$b.") ".$d."]^2";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////            Question type #15 generator            ////
////              Order of Operations 3                ////
////             a +- e ( (b * c) / b * d )            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_15()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,10);
    $b = rand(2,6);
    $c = rand(2,6);
    $d = rand(2,8);
    $e = 1;
    rand_switch_sign($a,2);
    rand_switch_sign($e,2);
    $coeff1 = $a;
    $coeff2 = $e;
    $coeff3 = $b * $c;
    $coeff4 = $b;
    $coeff5 = $d;
    coeff_prep($coeff2);
    $question  = $coeff1." ".$coeff2."( ".$coeff3;
    $question .= " @ ".$coeff4." # ".$coeff5." )";
    $numerator = $a + ($e * $c * $d);
    $numerator = (string)$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////            Question type #16 generator            ////
////              Order of Operations 4                ////
////             a [ (b *  c) / b ( d +- e) ]          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_16()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,6);
    $b = rand(2,6);
    $c = rand(2,6);
    $d = rand(2,6);
    $e = rand(1,5);
    while ($d == $e)
    {
        $e = rand(1,5);
    }
    $e = (-1) * $e;
    $coeff1 = $a;
    $coeff2 = $b * $c;
    $coeff3 = $b;
    $coeff4 = $d;
    $coeff5 = $e;
    coeff_prep($coeff5,0);
    $question = $coeff1."*[".$coeff2." @ ".$coeff3."(";
    $question .= $coeff4." ".$coeff5.")]";
    $numerator = $a * $c * ($d + $e);
    $numerator = (string)$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question type #17 generator               ////
////          Exponent Manipulation 1                  ////
////        (a * x^b * y^c) * (d * x^e * y^f)          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_17( )
{
    $a = 0;
    $b = 0;
    $c = 0;
    $d = 0;
    $e = 0;
    $f = 0;
    $g = 1;
    $h = 1;
    $range_1 = 0;
    $range_2 = 0;
    $numerator = "";
    $denominator = "";
    $question = "";
    $range_1=7;
    $range_2=9;
    $a = rand(2,$range_1);
    $b = rand(2,$range_2);
    $c = rand(2,$range_2);
    $d = rand(2,$range_1);
    $e = rand(2,$range_2);
    $f = rand(2,$range_2);
    rand_switch_sign($a,3);
    rand_switch_sign($b);
    rand_switch_sign($c);
    rand_switch_sign($d,3);
    rand_switch_sign($e);
    rand_switch_sign($f);
    $coeff = $a * $d;
    $x_pow = $g*$b + $h*$e;
    $y_pow = $g*$c + $h*$f;
	$b1=$b;
	$e1=$e;
	$c1=$c;
	$f1=$f;
	if($b<0)
	{
       $b1="~".abs($b);
    }
	if($e<0)
	{
	  $e1="~".abs($e);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
	if($f<0)
	{
	  $f1="~".abs($f);
	}
	 $question = "(".$a."*x^".$b1."*y^".$c1.")*(".$d."*x^".$e1."*y^".$f1.")";
   if ($x_pow == 0)
    {
        if ($y_pow == 0)
        {
            $numerator = $coeff;
            $denominator = "1";
        }
        else if ($y_pow == 1)
        {
            $numerator = $coeff."*y";
            $denominator = "1";
        }
        else // y_pow != 1 && y_pow != 0
        {
            if ($y_pow > 0)
            {
                $numerator = $coeff."*y^".$y_pow;
                $denominator = "1";
            }
            else
            {
                $y_pow = $y_pow * (-1);
                $numerator = $coeff;
                $denominator = "y^".$y_pow;
            }
        }
    }
    else if ($x_pow == 1)
    {
        if ($y_pow == 0)
        {
            $numerator = $coeff."*x";
            $denominator = "1";
        }
        else if ($y_pow == 1)
        {
            $numerator = $coeff."*x*y";
            $denominator = "1";
        }
        else // $y_pow != 1 && $y_pow !=0
        {
            if ($y_pow > 0 )
            {
                $numerator = $coeff."*x*y^".$y_pow;
                $denominator = "1";
            }
            else
            {
                $y_pow = $y_pow *(-1);
                $numerator = $coeff."*x";
                $denominator = "y^".$y_pow;
            }
        }
    }
    else // x_pow > 1
    {
        $numerator = (string)$coeff;
        if ($y_pow == 0)
        {
            if ($x_pow > 0)
            {
                $numerator = $numerator."*x^".$x_pow;
                $denominator = "1";
            }
            else // ($x_pow < 0)
            {
                $x_pow = $x_pow * (-1);
                $denominator = "x^".$x_pow;
            }
        }
        else if ($y_pow == 1)
        {
            if ($x_pow > 0)
            {
                $numerator = $numerator."*x^".$x_pow."*y";
                $denominator = "1";
            }
            else  // $x_pow < 0
            {
                $x_pow = $x_pow * (-1);
                $numerator = $numerator."*y";
                $denominator = "x^".$x_pow;
            }
        }
        else // $y_pow != 1 && $y_pow != 0
        {
            if ($y_pow > 0)
            {
                if ($x_pow > 0)
                {
                    $numerator = $numerator."*x^".$x_pow."*y^".$y_pow;
                    $denominator = "1";
                }
                else // $x_pow < 0
                {
                    $x_pow = $x_pow * (-1);
                    $numerator = $numerator."*y^".$y_pow;
                    $denominator = "x^".$x_pow;
                }
            }
            else // $y_pow < 0
            {
                $y_pow = $y_pow * (-1);
                if ($x_pow > 0)
                {
                    $numerator = $numerator."*x^".$x_pow;
                    $denominator = "y^".$y_pow;
                }
                else // $x_pow < 0
                {
                    $x_pow = $x_pow * (-1);
                    $denominator = "x^".$x_pow."*y^".$y_pow;
                }
            }
        }
    }
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question type #18 generator               ////
////           Exponent Manipulation 2                 ////
////     (a * x^b * y^c)^g * (d * x^e * y^f)^h         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_18( )
{
    $a = 0;
    $b = 0;
    $c = 0;
    $d = 0;
    $e = 0;
    $f = 0;
    $g = 1;
    $h = 1;
    $range_1 = 0;
    $range_2 = 0;
    $numerator = "";
    $denominator = "";
    $question = "";
    $range_1=4;
    $range_2=4;
    $g = rand(1,3);
    $h = rand(1,3);
    while ($g==1 && $h==1)
    {
        $h = rand(1,3);
    }
    $a = rand(2,$range_1);
    $b = rand(2,$range_2);
    $c = rand(2,$range_2);
    $d = rand(2,$range_1);
    $e = rand(2,$range_2);
    $f = rand(2,$range_2);
    rand_switch_sign($a,3);
    rand_switch_sign($b);
    rand_switch_sign($c);
    rand_switch_sign($d,3);
    rand_switch_sign($e);
    rand_switch_sign($f);
    $coeff = pow($a,$g) *pow($d,$h);
    $x_pow = $g*$b + $h*$e;
    $y_pow = $g*$c + $h*$f;
	$b1=$b;
	$e1=$e;
	$c1=$c;
	$f1=$f;
	if($b<0)
	{
       $b1="~".abs($b);
    }
	if($e<0)
	{
	  $e1="~".abs($e);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
	if($f<0)
	{
	  $f1="~".abs($f);
	}
    if ($g == 1)
    {
        $question = "(".$a."*x^".$b1."*y^".$c1.")";
        $question = $question."*(".$d."*x^".$e1."*y^".$f1.")^".$h;
    }
    else if ($h == 1)
    {
        $question = "(".$a."*x^".$b1."*y^".$c1.")^".$g;
        $question = $question."*(".$d."*x^".$e1."*y^".$f1.")";
    }
    else
    {
        $question = "(".$a."*x^".$b1."*y^".$c1.")^".$g;
        $question = $question."*(".$d."*x^".$e1."*y^".$f1.")^".$h;
    }

   if ($x_pow == 0)
    {
        if ($y_pow == 0)
        {
            $numerator = $coeff;
            $denominator = "1";
        }
        else if ($y_pow == 1)
        {
            $numerator = $coeff."*y";
            $denominator = "1";
        }
        else // y_pow != 1 && y_pow != 0
        {
            if ($y_pow > 0)
            {
                $numerator = $coeff."*y^".$y_pow;
                $denominator = "1";
            }
            else
            {
                $y_pow = $y_pow * (-1);
                $numerator = $coeff;
                $denominator = "y^".$y_pow;
            }
        }
    }
    else if ($x_pow == 1)
    {
        if ($y_pow == 0)
        {
            $numerator = $coeff."*x";
            $denominator = "1";
        }
        else if ($y_pow == 1)
        {
            $numerator = $coeff."*x*y";
            $denominator = "1";
        }
        else // $y_pow != 1 && $y_pow !=0
        {
            if ($y_pow > 0 )
            {
                $numerator = $coeff."*x*y^".$y_pow;
                $denominator = "1";
            }
            else
            {
                $y_pow = $y_pow *(-1);
                $numerator = $coeff."*x";
                $denominator = "y^".$y_pow;
            }
        }
    }
    else // x_pow > 1
    {
        $numerator = (string)$coeff;
        if ($y_pow == 0)
        {
            if ($x_pow > 0)
            {
                $numerator = $numerator."*x^".$x_pow;
                $denominator = "1";
            }
            else // ($x_pow < 0)
            {
                $x_pow = $x_pow * (-1);
                $denominator = "x^".$x_pow;
            }
        }
        else if ($y_pow == 1)
        {
            if ($x_pow > 0)
            {
                $numerator = $numerator."*x^".$x_pow."*y";
                $denominator = "1";
            }
            else  // $x_pow < 0
            {
                $x_pow = $x_pow * (-1);
                $numerator = $numerator."*y";
                $denominator = "x^".$x_pow;
            }
        }
        else // $y_pow != 1 && $y_pow != 0
        {
            if ($y_pow > 0)
            {
                if ($x_pow > 0)
                {
                    $numerator = $numerator."*x^".$x_pow."*y^".$y_pow;
                    $denominator = "1";
                }
                else // $x_pow < 0
                {
                    $x_pow = $x_pow * (-1);
                    $numerator = $numerator."*y^".$y_pow;
                    $denominator = "x^".$x_pow;
                }
            }
            else // $y_pow < 0
            {
                $y_pow = $y_pow * (-1);
                if ($x_pow > 0)
                {
                    $numerator = $numerator."*x^".$x_pow;
                    $denominator = "y^".$y_pow;
                }
                else // $x_pow < 0
                {
                    $x_pow = $x_pow * (-1);
                    $denominator = "x^".$x_pow."*y^".$y_pow;
                }
            }
        }
    }
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question type #19 generator             ////
////             Exponent Manipulation 3               ////
////        (x^".$a."*y^".$b.")/(x^".$c."*y)^".$d      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_19( )
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $x_pow = 0;
    $y_pow = 0;
    $a = rand(2,5);
    $b = rand(3,6);
    $c = rand(2,5);
    $d = 2;
    while ($c == $a )
    {
        $c = rand(2,5);
    }
    rand_switch_sign($a,4,0);
    rand_switch_sign($b,4,0);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
	$b1=$b;
	$a1=$a;
	$c1=$c;
	$d1=$d;
	if($d<0)
	{
       $d1="~".abs($d);
    }
	if($b<0)
	{
       $b1="~".abs($b);
    }
	if($a<0)
	{
	  $a1="~".abs($a);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
    $question = "(x^".$a1."*y^".$b1.")/(x^".$c1."*y)^".$d1;
    $x_pow = $a - $c*$d;
    $y_pow = $b - $d;
    $numerator = "1";
    $denominator = "1";
   if ($x_pow == 0)
    {
        ////  do nothing
    }
    else if ($x_pow == 1)
    {
        $numerator = "x";
    }
    else if ($x_pow == -1)
    {
        $denominator = "x";
    }
    else if ($x_pow > 0)
    {
        $numerator = "x^".$x_pow;
    }
    else
    {
        $x_pow = (-1)*$x_pow;
        $denominator = "x^".$x_pow;
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else  // $y_pow < 0
    {
        $y_pow = (-1)*$y_pow;
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
     if($denominator!="1")
      $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question type #20 generator             ////
////             Exponent Manipulation 4               ////
////        (x^".$a."*y)^".$b."/(x^".$c."*y)^".$d      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_20( )
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $x_pow = 0;
    $y_pow = 0;
    $a = rand(2,4);
    $b = rand(3,6);
    $c = rand(3,5);
    $d = 2;
    $b = $b * (-1);
    while ($c == $a)
    {
        $c = rand(3,5);
    }
    rand_switch_sign($c,2);
	$b1=$b;
	$a1=$a;
	$c1=$c;
	$d1=$d;
	if($d<0)
	{
       $d1="~".abs($d);
    }
	if($b<0)
	{
       $b1="~".abs($b);
    }
	if($a<0)
	{
	  $a1="~".abs($a);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
    $question = "(x^".$a1."*y)^".$b1."/(x^".$c1."*y)^".$d1;
    $x_pow = $a*$b-$c*$d;
    $y_pow = $b -$d;
    $numerator = "1";
    $denominator = "1";
    if ($x_pow == 0)
    {
        ////  do nothing
    }
    else if ($x_pow == 1)
    {
        $numerator = "x";
    }
    else if ($x_pow == -1)
    {
        $denominator = "x";
    }
    else if ($x_pow > 0)
    {
        $numerator = "x^".$x_pow;
    }
    else
    {
        $x_pow = (-1)*$x_pow;
        $denominator = "x^".$x_pow;
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else  // $y_pow < 0
    {
        $y_pow = (-1)*$y_pow;
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    $answer = array($question,$numerator."/(".$denominator.")",1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question type #21 generator             ////
////            Exponent Manipulation  5               ////
////   (a^".$a."*b^".$b.")^".$d."/(c^".$c.")^".$d      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_21()
{
    $question = "";
    $denominator = "";
    $numerator = "";
    $a = rand(2,5);
    $b = rand(2,4);
    $c = rand(2,5);
    $d = rand(2,5);
    $d = $d *(-1);
    rand_switch_sign($a,3,0);
    rand_switch_sign($c,3,0);
	$b1=$b;
	$a1=$a;
	$c1=$c;
	$d1=$d;
	if($d<0)
	{
       $d1="~".abs($d);
    }
	if($b<0)
	{
       $b1="~".abs($b);
    }
	if($a<0)
	{
	  $a1="~".abs($a);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
    $question = "((a^".$a1."*b^".$b1.")/(c^".$c1."))^".$d1;
    $a_pow = $a*$d;
    $b_pow = $b*$d;
    $c_pow = (-1)*$c*$d;
    $numerator = "1";
    $denominator = "1";
    if ($a_pow == 0)
    {
        //// do nothing
    }
    else if ($a_pow == 1)
    {
        $numerator = "a";
    }
    else if ($a_pow == -1)
    {
        $denominator = "a";
    }
    else if ($a_pow > 0)
    {
        $numerator = "a^".$a_pow;
    }
    else
    {
        $a_pow = $a_pow * (-1);
        $denominator = "a^".$a_pow;
    }
    if ($b_pow == 0)
    {
        //// do nothing
    }
    else if ($b_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "b";
        }
        else
        {
            $numerator = $numerator."*b";
        }
    }
    else if ($b_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "b";
        }
        else
        {
            $denominator = $denominator."*b";
        }
    }
    else if ($b_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "b^".$b_pow;
        }
        else
        {
            $numerator = $numerator."*b^".$b_pow;
        }
    }
    else
    {
        $b_pow = $b_pow * (-1);
        if ($denominator == "1")
        {
            $denominator = "b^".$b_pow;
        }
        else
        {
            $denominator = $denominator."*b^".$b_pow;
        }
    }
    if ($c_pow == 0)
    {
        //// do nothing
    }
    else if ($c_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "c";
        }
        else
        {
            $numerator = $numerator."*c";
        }
    }
    else if ($c_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "c";
        }
        else
        {
            $denominator = $denominator."*c";
        }
    }
    else if ($c_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "c^".$c_pow;
        }
        else
        {
            $numerator = $numerator."*c^".$c_pow;
        }
    }
    else
    {
        $c_pow = $c_pow * (-1);
        if ($denominator == "1")
        {
            $denominator = "c^".$c_pow;
        }
        else
        {
            $denominator = $denominator."*c^".$c_pow;
        }
    }
    $answer = array($question,$numerator."/(".$denominator.")",1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question type #22 generator             ////
////            Exponent Manipulation  6               ////
////   ($a*x^ $c *y^ $d )^ $f /( $b * x^ $e )^ $f      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_22()
{
    $question = "";
    $denominator = "";
    $numerator = "";
    $randy = rand(1,2);
    $a = rand(2,7);
    $b = rand(2,7);
    $c = rand(2,4);
    $d = rand(2,4);
    $e = 1;
    $e_sign = 0;
    while ($a == $b)
    {
        $b = rand(2,7);
    }
    if ($a >= 5 || $b >= 5)
    {
        $f = 1;
    }
    else
    {
        $f = rand(2,3);
    }
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    if ($e > 0)
    {
        $e_sign = 1;
        $e = "";
    }
    $f = $f * (-1);
    $x_pow = 0;
    $y_pow = 0;
	$f1=$f;
	$e1=$e;
	$c1=$c;
	$d1=$d;
	if($d<0)
	{
       $d1="~".abs($d);
    }
	if($e<0)
	{
       $e1="^~".abs($e);
    }
	if($f<0)
	{
	  $f1="~".abs($f);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
    if ($randy == 1)
    {
        $question = "((".$a."*x^".$c1."*y^".$d1.")/(".$b."*x".$e1."))^".$f1;
        if ($e_sign == 1)
        {
            $e = 1;
        }
        $x_pow = $c*$f - $e* $f;
        $y_pow = $d* $f;
    }
    else // $randy == 2
    {
        $question = "((".$a."*x^".$c1."*y^".$d1.")/(".$b."*y".$e1."))^".$f1;
        if ($e_sign == 1)
        {
            $e = 1;
        }
        $x_pow = $c*$f;
        $y_pow = $d* $f- $e* $f;
    }
    $f = $f * (-1);
    $numerator = pow($b,$f);
    $denominator = pow($a,$f);
    reduce($numerator,$denominator);
    $numerator = (string)$numerator;
    $denominator = (string)$denominator;
    if ($x_pow == 0)
    {
        //// do nothing
    }else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        $y_pow = $y_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    $answer = array($question,$numerator."/(".$denominator.")",1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question type #23 generator             ////
////            Exponent Manipulation  7               ////
////   ($a*x^$c*y^$d)^$g /($b*x^$e*y^$f)^$g            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_23()
{
    $question = "";
    $denominator = "";
    $numerator = "";
    $a = rand(2,6);
    $b = rand(2,6);
    $c = rand(2,5);
    $d = rand(2,5);
    $e = rand(2,5);
    $f = rand(2,5);
    if ($a == 6)
    {
        $a = rand(6,12);
    }
    if ($b == 6)
    {
        $b = rand(6,12);
    }
    while ($a == $b)
    {
        $b = rand(2,12);
    }
    if ($a >= 6 || $b >= 6)
    {
        $g = -1;
    }
    else // $a and $b are less than 5
    {
        $g = rand(2,3);
        $g = $g * (-1);
    }
    while ($c == $e)
    {
        $e = rand(2,5);
    }
    while ($d == $f)
    {
        $f = rand(2,5);
    }
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    rand_switch_sign($f,2);
	$f1=$f;
	$e1=$e;
	$c1=$c;
	$d1=$d;
	$g1=$g;
	if($d<0)
	{
       $d1="~".abs($d);
    }
	if($e<0)
	{
       $e1="~".abs($e);
    }
	if($g<0)
	{
	  $g1="~".abs($g);
	}
	if($c<0)
	{
	  $c1="~".abs($c);
	}
	if($f<0)
	{
	  $f1="~".abs($f);
	}
    $question = "((".$a."*x^".$c1."*y^".$d1;
    $question = $question.")/(".$b."*x^".$e1."*y^".$f1."))^".$g1;
    $x_pow = $c*$g-$e*$g;
    $y_pow = $d*$g-$f*$g;
    $g = $g * (-1);
    $numerator = pow($b,$g);
    $denominator = pow($a,$g);
    reduce($numerator,$denominator);
    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        $y_pow = $y_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    $answer = array($question,$numerator."/(".$denominator.")",1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question type #24 generator               ////
////       Numerical Exponent Manipulation 1           ////
////            - a^b                                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_24( )
{
    $a = rand(2,4);
    if ($a == 4)
    {
        $b = 2;
    }
    else
    {
        $b = rand(1,2);
        $b = $b *2;
    }
    $question = "-".$a."^".$b;
    $a = pow($a,$b);
    $numerator = "-".$a;
    $denominator = "1";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question type #25 generator                ////
////     Numerical Exponent Manipulation 2             ////
////            +- b^c^(d/c)                           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_25( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand (1,2);
    $b = rand (2,6);
    if ($b == 2)
    {
        $c = rand(2,5);
    }
    if ($b == 3)
    {
        $c = rand(2,4);
    }
    else
    {
        $c = rand(2,3);
    }
    $d = rand(1,2);
    if ($d == 2)
    {
        if ($b < 4)
        {
            if ($c == 2 || $c == 4)
            {
                $d = 3;
            }
            else
            {
                $d = rand(1,2);
                if ($d == 1)
                {
                    $d = 2;
                }
                else
                {
                    $d = 4;
                }
            }
        }
        else
        {
            if ($c == 2 || $c == 4)
            {
                $d = 3;
            }
            else
            {
                $d = 2;
            }
        }
    }
    $temp = pow($b,$c);
    if ($a == 1)
    {
        $question = "-".$temp."^(".$d."/".$c.")";
        $temp = pow($b,$d);
        $numerator = "-".$temp;
    }
    else
    {
        $question = $temp."^(".$d."/".$c.")";
        $temp = pow($b,$d);
        $numerator = (string)$temp;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question type #26 generator                ////
////     Numerical Exponent Manipulation 3             ////
////             b^c^(-d/c)                            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_26( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand (1,2);
    $b = rand (2,6);
    if ($b == 2)
    {
        $c = rand(2,5);
    }
    if ($b == 3)
    {
        $c = rand(2,4);
    }
    else
    {
        $c = rand(2,3);
    }
    $d = rand(1,2);
    if ($d == 2)
    {
        if ($b < 4)
        {
            if ($c == 2 || $c == 4)
            {
                $d = 3;
            }
            else
            {
                $d = rand(1,2);
                if ($d == 1)
                {
                    $d = 2;
                }
                else
                {
                    $d = 4;
                }
            }
        }
        else
        {
            if ($c == 2 || $c == 4)
            {
                $d = 3;
            }
            else
            {
                $d = 2;
            }
        }
    }
    $temp = pow($b,$c);
    $temp = (string)$temp;
    $question = $temp."^(-".$d."/".$c.")";
    $temp = pow($b,$d);
    $denominator = (string)$temp;
    $numerator = "1";
    $answer = array($question,$numerator."/".$denominator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////             Question Type #27 Generator           ////
////          Numerical Exponent Manipulation 4        ////
////               (a^c / b ^ c) ^ (+- d/c)            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_27()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,4);
    if ($a != 1)
    {
        $a = rand(2,5);
    }
    $b = rand(2,5);
    while ($b == $a)
    {
        $b = rand(2,5);
    }
    $c = rand(2,3);
    if ($c == 2)
    {
        $d = 3;
    }
    else
    {
        $d = 2;
    }
    $neg_chance = rand(1,3);
    $numerator = pow($a,$c);
    $denominator = pow($b,$c);
    if ($neg_chance == 1)
    {
        $question = "(".$numerator."/".$denominator.")^(-".$d."/".$c.")";
        $numerator = pow($b,$d);
        $denominator = pow($a,$d);
    }
    else
    {
        $question =  "(".$numerator."/".$denominator.")^(".$d."/".$c.")";
        $numerator = pow($a,$d);
        $denominator = pow($b,$d);
    }
    reduce($numerator,$denominator);
    if($denominator!=1)
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question Type #28 Generator             ////
////       Fractional Exponent Manipulation 1          ////
////         ($a*x^($e/$c))($b*x^($f/$c))              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_28()
{
    $numerator = "";
    $denominator = "1";
    $question = "";
    $a = rand (2,4);
    $b = rand (2,4);
    $c = rand (3,5);
    $d = rand (1,2);
    $temp = $c*$d;
    $e = rand (1,$temp-1);
    while ($e == $c)
    {
        $e = rand(1,$temp-1);
    }$f = $temp - $e;
    $question = "(".$a."*x^(".$e."/".$c."))*(".$b."*x^(".$f."/".$c."))";
    $temp = $a * $b;
    if ($d == 1)
    {
        $numerator = $temp."*x";
    }
    else
    {
        $numerator = $temp."*x^2";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question Type #29 Generator             ////
////       Fractional Exponent Manipulation 2          ////
////         ($ax^($c/$d)y^($e/$f))                    ////
////                  *                                ////
////      ($bx^($g/$x_denom)y^($i/$y_denom))           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_29( )
{
    $x_pow = "";
    $y_pow = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $isneg_x_num = 0;
    $isneg_y_num = 0;
    $a = rand(2,5);
    $b = rand(2,5);
    $c = rand(1,2);
    $d = rand($c+1,5);
    $e = rand(1,2);
    if ($e == 2)
    {
        $f = 2*rand(1,2) + 1;
    }
    else
    {
        $f = rand(2,5);
    }
    $h = rand(1,3);
    $j = rand(1,3);
    $x_denom = $h*$d;
    {
        $y_denom = $f*$j;
    }
    $g = rand(2,$x_denom+1);
    $i = rand(2,$y_denom+1);
    while ($g == $x_denom)
    {
        $g = rand(2,$x_denom+1);
    }
    while ($i == $y_denom)
    {
        $i = rand(2,$y_denom+1);
    }
    rand_switch_sign($c,4,0);
    rand_switch_sign($g);
    rand_switch_sign($i,4,0);
    $x_num   = $c*$h + $g;
    $y_num   = $j*$e + $i;
    $question = "(".$a."x^(".$c."/".$d.")*y^(".$e."/".$f."))";
    $question = $question."*(".$b."x^(".$g."/".$x_denom.")*";
    $question = $question."y^(".$i."/".$y_denom."))";
    reduce($x_num,$x_denom);
    reduce($y_num,$y_denom);
    if ($x_num < 0)
    {
        $isneg_x_num = 1;
        $x_num = (-1)*$x_num;
    }
    if ($y_num < 0)
    {
        $isneg_y_num = 1;
        $y_num = $y_num * (-1);
    }
    if ($x_num == 0)
    {
        $x_pow = "0";
    }
    else if ($x_denom == 1)
    {
        $x_pow = "(".$x_num.")";
    }
    else
    {
        $x_pow = "(".$x_num."/".$x_denom.")";
    }
    if ($y_num == 0)
    {
        $y_pow = "0";
    }
    else if ($y_denom == 1)
    {
        $y_pow = "(".$y_num.")";
    }
    else
    {
        $y_pow = "(".$y_num."/".$y_denom.")";
    }
    $temp = $a*$b;
    $numerator = (string)$temp;
    if ($x_pow == "0")
    {
        //// do nothing
    }
    else if ($x_pow == "1" && $isneg_x_num != 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == "1")
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($isneg_x_num == 0)
    {
        if ($numerator == "1")
        {
        	if($x_pow!="(1)")
            $numerator = "x^".$x_pow;
          else
           $numerator = "x";
        }
        else
        {
           if($x_pow!="(1)") 
            $numerator = $numerator."*x^".$x_pow;
           else
            $numerator = $numerator."*x";
        }
    }
    else // ($x_pow < 0)
    {
        if ($denominator == "1")
        {
        	if($x_pow!="(1)")
            $denominator = "x^".$x_pow;
          else
           $denominator = "x";
        }
        else
        {
        	 if($x_pow!="(1)") 
             $denominator =  $denominator."*x^".$x_pow;
           else
             $denominator =  $denominator."*x";
        }
    }
    if ($y_pow == "0")
    {
        //// do nothing
    }
    else if ($y_pow == "1" && $isneg_y_num != 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == "1")
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($isneg_y_num == 0)
    {
        if ($numerator == "1")
        {
            if($y_pow!="(1)") 
             $numerator = "y^".$y_pow;
           else
            $numerator =  "y";
        }
        else
        {
            if($y_pow!="(1)") 
             $numerator =  $numerator."*y^".$y_pow;
           else
             $numerator =  $numerator."*y";
        }
    }
    else // ($y_pow < 0)
    {
        if ($denominator == "1")
        {
           if($y_pow!="(1)") 
             $denominator = "y^".$y_pow;
           else
             $denominator =  "y";
        }
        else
        {
        	 if($y_pow!="(1)") 
             $denominator =  $denominator."*y^".$y_pow;
           else
             $denominator =  $denominator."*y";
        }
    }
    if($denominator!="1")
     $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #30 Generator               ////
////       Fractional Exponent Manipulation 3          ////
////      ( b^a * x^(c*a) * y^(d*a) )^(1/a)            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_30( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,4);
    if ($a == 2)
    {
        $b = rand(2,7);
    }
    else if ($a == 3)
    {
        $b = rand(2,4);
    }
    else // $a == 4
    {
        $b = rand(2,3);
    }
    $c = rand(2,5);
    $d = rand(2,5);
    $coeff = pow($b,$a);
    $x_pow = $c * $a;
    $y_pow = $d * $a;
    $question = "(".$coeff."*x^(".$x_pow.")*y^(".$y_pow."))^(1/".$a.")";
    $numerator = $b."*x^".$c."*y^".$d;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #31 Generator               ////
////       Fractional Exponent Manipulation 4          ////
////   ($coeff * x^+-$x_pow * y^(+-$y_pow))^($e/$a)    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_31( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(3,5);
    if ($a == 5)
    {
        $b = 2;
    }
    else
    {
        $b = rand(2,3);
    }
    $c = rand(1,3);
    $d = rand(1,3);
    if ($a != 4)
    {
        $e = rand(1,$a-1);
    }
    else
    {
        $e = 2 * rand(1,2) - 1;
    }
    $randy = rand(1,2);
    $x_pow = $c * $a;
    $y_pow = $d * $a;
    $coeff = pow($b,$a);
    if ($randy == 1) // y_pow is negative
    {
        $question = "(".$coeff."*x^(".$x_pow.")*y^(-".$y_pow."))^(".$e."/".$a.")";
    }
    else  // $x_pow is negative
    {
        $question = "(".$coeff."*x^(-".$x_pow.")*y^(".$y_pow."))^(".$e."/".$a.")";
    }
    $coeff = pow($b,$e);
    $x_pow = $c * $e;
    $y_pow = $d * $e;
    if ($randy == 1) // y is in the denominator
    {
    	  if($x_pow!=1)
         $numerator = $coeff."*x^".$x_pow;
        else
        	$numerator = $coeff."*x";
        if($y_pow!=1)
         $denominator = "y^".$y_pow;
        else
         $denominator = "y";
    }
    else // x is in the denominator
    {
        if($y_pow!=1)
         $numerator = $coeff."*y^".$y_pow;
        else
         $numerator = $coeff."*y";
        if($x_pow!=1)
         $denominator = "x^".$x_pow;
        else
         $denominator = "x";
    }
    $answer = array($question,$numerator."/".$denominator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #32 Generator               ////
////       Fractional Exponent Manipulation 5          ////
////        ($b*x^(-$c/$a)*y^($d/$temp))^$a            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_32( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(4,5);
    if ($a == 5)
    {
        $b = 2;
    }
    else
    {
        $b = rand(2,3);
    }
    if ($a == 5)
    {
        $c = rand(1,3);
    }
    else
    {
        $c = 2 * rand(1,2) - 1;
    }
    if ($a == 4)
    {
        $d = 2 * rand(1,2) - 1;
    }
    else
    {
        $d = rand(1,3);
    }
    $e = rand(1,3);
    if ($e == 1)
    {
        if ($a == 5)
        {
            $e = 3;
        }
        else
        {
            $e = rand(2,3);
        }
    }
    else
    {
        $e = 1;
    }
    $temp = $e * $a;
    $question = "(".$b."*x^(-".$c."/".$a.")*y^"."(".$d."/".$temp."))^(".$a.")";
    $coeff = pow($b,$a);
    $x_pow = $c;
    reduce($d,$e);
    if ($e == 1)
    {
        $y_pow = "(".$d.")";
    }
    else
    {
        $y_pow = "(".$d."/".$e.")";
    }
    if($y_pow != "(1)")
    {
        $numerator = $coeff."*y^".$y_pow;
    }
    else
    {
        $numerator = $coeff."*y";
    }
    if($x_pow != "1")
    {
        $denominator = "x^(".$x_pow.")";
    }
    else
    {
        $denominator = "x";
    }
    $answer = array($question,$numerator."/".$denominator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #33 Generator               ////
////       Fractional Exponent Manipulation 6          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_33( )
{
    $x_pow = 1;
    $y_pow = 1;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,2);
    $a = rand(3,9);
    $samecoeff = 1;
    if ($randy == 1)
    {
        $b = $a;
    }
    else // $randy == 2
    {
        $b = rand(3,9);
        $samecoeff = 0;
        while ($b == $a)
        {
            $b = rand(3,9);
        }
    }
    $c = rand(2,5);
    $d = rand(2,5);
    $e = rand(2,4);
    $f = rand(2,4);
    if ($b > 5)
    {
        $g = 2;
    }
    else
    {
        $g = rand(2,3);
    }
    $q_num ="(". $a."*x^(-".$c.")*y^(".$d."))";
    $coeff = pow($b,$g);
    $x_pow = $e * $g;
    $y_pow = $f * $g;
    $randy = rand(1,3);
    if ($randy == 1)
    {
        $q_denom = "(".$coeff."*x^(-".$x_pow.")*y^".$y_pow.")^(1/".$g.")";
        $e = (-1) * $e;
    }
    else if ($randy == 2)
    {
        $q_denom = "(".$coeff."*x^(".$x_pow.")*y^(-".$y_pow."))^(1/".$g.")";
        $f = (-1) * $f;
    }
    else
    {
        $q_denom = "(".$coeff."*x^(-".$x_pow.")*y^(-".$y_pow."))^(1/".$g.")";
        $f = (-1) * $f;
        $e = (-1) * $e;
    }
    $question = $q_num."/".$q_denom;
    $x_pow = ((-1)*$c) - $e;
    $y_pow = $d - $f;
    if ($samecoeff == 1)
    {
        $numerator = "1";
        $denominator = "1";
    }
    else
    {
        reduce($a,$b);
        $numerator = (string)$a;
        $denominator = (string)$b;
    }
    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        $y_pow = $y_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
   if($denominator!="1")
      $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #34 Generator               ////
////       Fractional Exponent Manipulation 7          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_34( )
{
    $x_pow = 1;
    $y_pow = 1;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,10);
    $b = rand(2,10);
    while ($b == $a)
    {
        $b = rand(2,10);
    }
    $c = rand(2,5);
    $d = rand(2,5);
    $e = rand(2,5);
    $f = rand(2,5);
    if ($a >= 5)
    {
        $g = 2;
    }
    else
    {
        $g = rand(2,3);
    }
    rand_switch_sign($c,4);
    rand_switch_sign($d,4);
    rand_switch_sign($e,4);
    rand_switch_sign($f,4);
    $coeff = pow($a,$g);
    $x_pow = $c * $g;
    $y_pow = $d * $g;
    $q_num = "(".$coeff."*x^(".$x_pow.")*y^(".$y_pow."))^(1/".$g.")";
    $q_denom ="(" .$b."*x^(".$e.")*y^(".$f."))";
    $question = $q_num."/".$q_denom;
    reduce($a,$b);
    $numerator = (string)$a;
    $denominator = (string)$b;
    $x_pow = $c - $e;
    $y_pow = $d - $f;
    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        $y_pow = $y_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    if($denominator!="1")
      $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #35 Generator               ////
////       Fractional Exponent Manipulation 8          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_35( )
{
    $x_pow = 1;
    $y_pow = 1;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $samecoeff = 1;
    $randy = rand(1,2);
    $a = rand(2,3);
    if ($randy == 1)
    {
        $samecoeff = 1;
    }
    else
    {
        $samecoeff = 0;
    }
    $c = rand(2,5);
    $d = rand(2,5);
    $e = rand(3,5);
    $f = rand(3,5);
    if ($a == 3)
    {
        $g = 3;
    }
    else
    {
        $g = rand(1,2);
        $g = 2*$g +1;
    }
    rand_switch_sign($e,2);
    rand_switch_sign($f,2);
    $coeff = pow($a,$g);
    $x_pow = $c * $g;
    $y_pow = $d * $g;
    $q_num = "(-".$coeff."*x^(".$x_pow.")*y^(".$y_pow."))^(1/".$g.")";
    if ($samecoeff == 1)
    {
        $numerator = "1";
        $denominator = "1";
        $q_denom = "(-".$a."*x^(".$e.")*y^(".$f."))";
    }
    else
    {
        $numerator = "-".$a;
        $denominator = "1";
        $q_denom = "(x^(".$e.")*y^(".$f."))";
    }
    $question = $q_num."/".$q_denom;
    $x_pow = $c - $e;
    $y_pow = $d - $f;
    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if ($y_pow == 0)
    {
        //// do nothing
    }
    else if ($y_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "y";
        }
        else
        {
            $numerator = $numerator."*y";
        }
    }
    else if ($y_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "y";
        }
        else
        {
            $denominator = $denominator."*y";
        }
    }
    else if ($y_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        $y_pow = $y_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    if($denominator!="1")
      $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #36 Generator               ////
////       Fractional Exponent Manipulation 9          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_36( )
{
    $x_pow = 0;
    $y_pow = 0;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "";
    $randy = rand(1,2);
    $a = rand(2,6);
    $b = rand(2,7);
    $c = rand(4,9);
    $d = rand(1,$c-2);
    $qn_coeff = $a;
    $qd_coeff = pow($a,2);
    if ($randy == 1)
    {
        $qn_x_pow = $b;
        $temp = 4 * $b + 1;
        $a_x_pow = "(".$temp."/4)";
    }
    else
    {
        $qn_x_pow = (-1) * $b;
        $temp = 4 * $b - 1;
        $a_x_pow = "(".$temp."/4)";
    }
    $qn_y_pow = $c;
    $qd_x_pow = "(-1/2)";
    $qd_y_pow = 2 * $d;
    $a_y_pow = $c - $d;
    $q_num = "(".$qn_coeff."x^(".$qn_x_pow.")*y^".$qn_y_pow.")";
    $q_denom = "(".$qd_coeff."y^".$qd_y_pow."*x^".$qd_x_pow.")^(1/2)";
    if ($randy == 1)
    {
        $numerator = "x^".$a_x_pow."*y^".$a_y_pow;
        $denominator = "1";
    }
    else
    {
        $numerator = "y^".$a_y_pow;
        $denominator = "x^".$a_x_pow;
    }
    $question = $q_num."/".$q_denom;
     if($denominator!="1")
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #37 Generator               ////
////       Fractional Exponent Manipulation 10         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_37( )
{
    $x_pow = 0;
    $y_pow = 0;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,6);
    $b = rand(2,7);
    $c = rand(3,6);
    $d = rand(2,6);
    $qn_coeff = pow($a,2);
    $qn_x_pow = 2 * $b;
    $qn_y_pow = 2 * $c + 1;
    $qd_x_pow = (-1) * $d;
    $qd_y_pow = "(3/2)";
    $a_coeff = $a;
    $a_x_pow = $b + $d;
    $a_y_pow = $c - 1;
    $q_num = "(".$qn_coeff."x^(".$qn_x_pow.")*y^(".$qn_y_pow."))^(1/2)";
    $q_denom = "(x^(".$qd_x_pow.")*y^".$qd_y_pow.")";
    $numerator = $a_coeff."x^".$a_x_pow."y^".$a_y_pow;
    $denominator = "1";
    $question = $q_num."/".$q_denom;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #38 Generator               ////
////       Fractional Exponent Manipulation 11         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_38( )
{
    $x_pow = 0;
    $y_pow = 0;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $isnegative = 0;
    $a = rand(2,5);
    if ($a >= 4)
    {
        $b = 2;
    }
    else if ($a == 3)
    {
        $b = rand(3,4);
    }
    else // $a == 2
    {
        $b = rand(3,6);
    }
    $c = 1;
    if ($b == 2 || $b == 4 )
    {
        $d = 2 * rand(1,2) + 1;
    }
    else if ($b == 6)
    {
        $d = 5;
    }
    else
    {
        $d = 2 * rand(1,2);
    }
    $randy = rand(1,2);
    if ($randy == 1)
    {
        $isnegative = 1;
    }
    $e = 1;
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    if ($isnegative == 1)
    {
        $q_num = "(".$a."x^(".$c."/".$b."))";
        $q_denom = "(x^(".$d."/".$b."))";
		    $question = "(".$q_num."/".$q_denom.")^(-".$b.")";
        $temp = pow($a,$b);
        $b = (-1) * $b;
        $denominator = (string)$temp;
        $numerator = "1";
        $e = -1;
    }
    else // $isnegative != 1
    {
        $q_num = "(".$a."x^(".$c."/".$b."))";
        $q_denom = "(x^(".$d."/".$b."))";
		$question = "(".$q_num."/".$q_denom.")^(".$b.")";
        $temp = pow($a,$b);
        $numerator = (string)$temp;
        $denominator = "1";
        $e = 1;
    }
    
    $x_pow = $c*$e - $d*$e;
    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    if($denominator!="1")
      $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #39 Generator               ////
////       Fractional Exponent Manipulation 12         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_39( )
{
    $x_pow = 0;
    $y_pow = 0;
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $is_num_neg = 0;
    $is_denom_neg = 0;
    $is_exp_neg = 0;
    $a = rand(2,5);
    $b = rand(1,3);
    while ($a == $b)
    {
        $b = rand(1,3);
    }
    $c = rand(2,5);
    $d = rand(2,5);
    while ($c == $d)
    {
        $d = rand(2,5);
    }
    $e = 2;
    if ($a <= 3)
    {
        $e = rand(2,4);
    }
    $randy = rand(1,2);
    if ($randy == 1)
    {
        $is_num_neg = 1;
    }
    if ($b != 1)
    {
        $randy = rand(1,2);
        if ($randy == 1)
        {
            $is_denom_neg = 1;
        }
    }
    $randy = rand(1,4);
    if ($randy != 1)
    {
        $is_exp_neg = 1;
    }
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    $numerator = 1;
    $denominator = 1;
    $coeff = pow($a,$e);
    $x_pow = $c * $e;
    if ($is_num_neg == 1)
    {
        $q_num = "(".$coeff."^(-1)*x^(".$x_pow."))";
        $denominator = $denominator * $a;
    }
    else
    {
        $q_num = "(".$coeff."x^(".$x_pow."))";
        $numerator = $numerator * $a;
    }
    $coeff = pow($b,$e);
    $x_pow = $d * $e;
    if ($is_denom_neg == 1)
    {
       $q_denom = "(".$coeff."^(-1)*x^(".$x_pow."))";
       $numerator = $numerator * $b;
    }
    else
    {
        if ($b != 1)
        {
          $q_denom = "(".$coeff."x^(".$x_pow."))";
         }
        else
        {
            $q_denom = "(x^(".$x_pow."))";
        }
        $denominator = $denominator * $b;
    }
	if ($is_exp_neg == 1)
    {
           $question ="(". $q_num."/".$q_denom.")^(-1/(".$e."))";
    }
     else
     {
          $question = "(". $q_num."/".$q_denom.")^(1/(".$e."))";
     }
	
    if ($is_exp_neg == 1)
    {
        $temp = $numerator;
        $numerator = $denominator;
        $denominator = $temp;
        $e = -1;
    }
    else
    {
        $e = 1;
    }
    $numerator = (string)$numerator;
    $denominator = (string)$denominator;
    $x_pow = $c*$e - $d*$e;

    if ($x_pow == 0)
    {
        //// do nothing
    }
    else if ($x_pow == 1)
    {
        if ($numerator == "1")
        {
            $numerator = "x";
        }
        else
        {
            $numerator = $numerator."*x";
        }
    }
    else if ($x_pow == -1)
    {
        if ($denominator == "1")
        {
            $denominator = "x";
        }
        else
        {
            $denominator = $denominator."*x";
        }
    }
    else if ($x_pow > 0)
    {
        if ($numerator == "1")
        {
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        $x_pow = $x_pow*(-1);
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
        }
    }
    $answer = array($question,$numerator."/(".$denominator.")",1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////           Question Type #40 Generator             ////
////         Polynomial Addition/Subtraction           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_40()
{
    $num_zeros = 0;
    $first_term = "";
    $second_term = "";
    $operator = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    if ($a != 1)
    {
        $a = rand(1,12);
    }
    else
    {
        $a = 0;
    }
    $b = rand(1,5);
    if ($b != 1 || $a == 0)
    {
        $b = rand(1,12);
    }
    else
    {
        $b = 0;
    }
    $c = rand(1,5);
    if ($c != 1)
    {
        $c = rand(1,12);
    }
    else
    {
        $c = 0;
    }
    $d = rand(1,5);
    if ($d != 1 || $c == 0)
    {
        $d = rand(1,12);
    }
    else
    {
        $d = 0;
    }
    $e = rand(1,2);
    if ($e != 1)
    {
        $e = 0;
    }
    else
    {
        $e = rand(1,12);
    }
    $f = rand(1,4);
    if ($f != 1 || $e == 0)
    {
        $f = rand(1,12);
    }
    else
    {
        $f = 0;
    }
    $g = rand(1,4);
    if ($g != 1)
    {
        $g = rand(1,12);
    }
    else
    {
        $g = 0;
    }
    $h = rand(1,4);
    if ($h != 1 || $g == 0)
    {
        $h = rand(1,12);
    }
    else
    {
        $h = 0;
    }
    $randy = rand(1,2);
    if ($randy == 1)
    {
        $operator = "+";
    }
    else
    {
        $operator = "-";
    }
    $first_term = "(";
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    rand_switch_sign($g,3);
    rand_switch_sign($h,3);
    if ($a != 0)
    {
        if ($a == 1)
        {
            $first_term = $first_term."x^(3)";
        }
        else if ($a == -1)
        {
            $first_term = $first_term."-x^(3)";
        }
        else
        {
            $first_term = $first_term.$a."x^(3)";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($b != 0)
    {
        if ($b > 0 && $num_zeros != 1)
        {
            $first_term = $first_term."+";
        }
        if ($b == 1)
        {
            $first_term = $first_term."x^(2)";
        }
        else if ($b == -1)
        {
            $first_term = $first_term."-x^(2)";
        }
        else
        {
            $first_term = $first_term.$b."x^(2)";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($c != 0)
    {
        if ($c > 0 && $num_zeros != 2)
        {
            $first_term = $first_term."+";
        }
        if ($c == 1)
        {
            $first_term = $first_term."x";
        }
        else if ($c == -1)
        {
            $first_term = $first_term."-x";
        }
        else
        {
            $first_term = $first_term.$c."x";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($d != 0)
    {
        if ($d > 0)
        {
            $first_term = $first_term."+";
        }
        $first_term = $first_term.$d;
    }
    $first_term = $first_term.")";
    $num_zeros = 0;
    $second_term = "(";
    if ($e != 0)
    {
        if ($e == 1)
        {
            $second_term = $second_term."x^(3)";
        }
        else if ($e == -1)
        {
            $second_term = $second_term."-x^(3)";
        }
        else
        {
            $second_term = $second_term.$e."x^(3)";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($f != 0)
    {
        if ($f > 0 && $num_zeros != 1)
        {
            $second_term = $second_term."+";
        }
        if ($f == 1)
        {
            $second_term = $second_term."x^(2)";
        }
        else if ($f == -1)
        {
            $second_term = $second_term."-x^(2)";
        }
        else
        {
            $second_term = $second_term.$f."x^(2)";
        }
    }
    if ($g != 0)
    {
        if ($g > 0)
        {
            $second_term = $second_term."+";
        }
        if ($g == 1)
        {
            $second_term = $second_term."x";
        }
        else if ($g == -1)
        {
            $second_term = $second_term."-x";
        }
        else
        {
            $second_term = $second_term.$g."x";
        }
    }
    if ($h != 0)
    {
        if ($h > 0)
        {
            $second_term = $second_term."+";
        }
        $second_term = $second_term.$h;
    }
    $second_term = $second_term.")";
    $question = $first_term." ".$operator." ".$second_term;
    if ($operator == "-")
    {
        $e = $e * (-1);
        $f = $f * (-1);
        $g = $g * (-1);
        $h = $h * (-1);
    }
    $temp1 = $a + $e;
    $temp2 = $b + $f;
    $temp3 = $c + $g;
    $temp4 = $d + $h;
    $num_zeros = 0;
    if ($temp1 != 0)
    {
        if ($temp1 == 1)
        {
            $numerator = "x^3";
        }
        else if ($temp1 == -1)
        {
            $numerator = "-x^3";
        }
        else
        {
            $numerator = $temp1."x^3";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($temp2 != 0 )
    {
        if ($temp2 > 0 && $num_zeros != 1)
        {
            $numerator = $numerator."+";
        }
        if ($temp2 == 1)
        {
            $numerator = $numerator."x^2";
        }
        else if ($temp2 == -1)
        {
            $numerator = $numerator."-x^2";
        }
        else
        {
            $numerator = $numerator.$temp2."x^2";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($temp3 != 0)
    {
        if ($temp3 > 0 && $num_zeros != 2)
        {
            $numerator = $numerator."+";
        }
        if ($temp3 == 1)
        {
            $numerator = $numerator."x";
        }
        else if ($temp3 == -1)
        {
            $numerator = $numerator."-x";
        }
        else
        {
            $numerator = $numerator.$temp3."x";
        }
    }
    else
    {
        $num_zeros++;
    }
    if ($num_zeros == 3)
    {
        $numerator = (string)$temp4;
    }
    else if ($temp4 != 0)
    {
        if ($temp4 > 0)
        {
            $numerator = $numerator."+";
        }
        $numerator = $numerator.$temp4;
    }
    else
    {
        $num_zeros = 4;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #41 Generator               ////
////         Polynomial Multiplication 1               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_41( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,4);
    $b = rand(2,4);
    $c = rand(2,9);
    $d = rand(2,9);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $coeff1 = $a * $b;
    $coeff2 = $a * $d + $b * $c;
    $coeff3 = $c * $d;
    if ($c > 0)
    {
        $c = "+".$c;
    }
    if ($d > 0)
    {
        $d = "+".$d;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    $question = "(".$a."n".$c.")*(".$b."n".$d.")";
    if ($coeff2 != 0)
    {
        if ($coeff2 == "+1")
        {
            $numerator = $coeff1."*n^2+n".$coeff3;
        }
        else if ($coeff2 == -1)
        {
            $numerator = $coeff1."*n^2-n".$coeff3;
        }
        else
        {
            $numerator = $coeff1."*n^2".$coeff2."*n".$coeff3;
        }
    }
    else
    {
        $numerator = $coeff1."*n^2".$coeff3;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #42 Generator               ////
////         Polynomial Multiplication 2               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_42( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,4);
    $b = rand(2,4);
    $c = rand(2,9);
    $d = rand(2,9);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $coeff1 = $a * $b;
    $coeff2 = $a * $d + $b * $c;
    $coeff3 = $c * $d;
    if ($c > 0)
    {
        $c = "+".$c;
    }
    if ($d > 0)
    {
        $d = "+".$d;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    $question = "(".$a."y".$c.")*(".$b."y".$d.")";
    if ($coeff2 != 0)
    {
        if ($coeff2 == "+1")
        {
            $numerator = $coeff1."*y^(2)+y".$coeff3;
        }
        else if ($coeff2 == -1)
        {
            $numerator = $coeff1."*y^(2)-y".$coeff3;
        }
        else
        {
            $numerator = $coeff1."*y^(2)".$coeff2."*y".$coeff3;
        }
    }
    else
    {
        $numerator = $coeff1."*y^(2)".$coeff3;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #43 Generator               ////
////         Polynomial Multiplication 3               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_43( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,4);
    $b = rand(2,4);
    $c = rand(2,4);
    $d = rand(2,4);
    rand_switch_sign($c,4);
    rand_switch_sign($d,4);
    $coeff1 = $a * $b;
    $coeff2 = $a * $d + $b * $c;
    $coeff3 = $c * $d;
    if ($c > 0)
    {
        $c = "+".$c;
    }
    if ($d > 0)
    {
        $d = "+".$d;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    if ( ($a == $b) && ($c == $d) )
    {
        $question = "(".$a."x".$c."y)^2";
    }
    else
    {
        $question = "(".$a."x".$c."y)*(".$b."x".$d."y)";
    }
    if ($coeff2 != 0)
    {
        if ($coeff2 == "+1")
        {
            $numerator = $coeff1."*x^(2)+x*y".$coeff3."*y^(2)";
        }
        else if ($coeff2 == -1)
        {
            $numerator = $coeff1."*x^(2)-x*y".$coeff3."*y^(2)";
        }
        else
        {
            $numerator = $coeff1."*x^(2)".$coeff2."*x*y".$coeff3."*y^(2)";
        }
    }
    else
    {
        $numerator = $coeff1."*x^(2)".$coeff3."*y^(2)";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #44 Generator               ////
////         Polynomial Multiplication 4               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_44( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,5);
    rand_switch_sign($b,4);
    $coeff1 = $a * $a;
    $coeff2 = 2 * ($a * $b);
    $coeff3 = $b * $b;
    if ($b > 0)
    {
        $b = "+".$b;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    $question = "(".$a."x".$b."y)^2";
    if ($coeff2 != 0)
    {
        if ($coeff2 == "+1")
        {
            $numerator = $coeff1."*x^(2)+x*y".$coeff3."*y^(2)";
        }
        else if ($coeff2 == -1)
        {
            $numerator = $coeff1."*x^(2)-x*y".$coeff3."*y^(2)";
        }
        else
        {
            $numerator = $coeff1."*x^(2)".$coeff2."*x*y".$coeff3."*y^(2)";
        }
    }
    else
    {
        $numerator = $coeff1."*x^(2)".$coeff3."*y^(2)";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #45 Generator               ////
////         Polynomial Multiplication 5               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_45( )
{
    $answer = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,5);
    $c = rand(1,5);
    $d = rand(2,5);
    $e = rand(2,5);
    rand_switch_sign($b,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    $coeff1 = $a * $c;
    $coeff2 = $b * $c + $a * $d;
    $coeff3 = $b * $d + $a * $e;
    $coeff4 = $b * $e;
    if ($b > 0)
    {
        $b = "+".$b;
    }
    if ($d > 0)
    {
        $d = "+".$d;
    }
    if ($e > 0)
    {
        $e = "+".$e;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    if ($coeff4 > 0)
    {
        $coeff4 = "+".$coeff4;
    }
    if ($c == 1)
    {
        $question = "(".$a."x".$b.")*(x^(2)".$d."x".$e.")";
    }
    else
    {
        $question = "(".$a."x".$b.")*(".$c."x^(2)".$d."x".$e.")";
    }
    $numerator = $coeff1."*x^(3)";
    if ($coeff2 != 0)
    {
        if ($coeff2 == "+1")
        {
            $numerator = $numerator."+x^(2)";
        }
        else if ($coeff2 == -1)
        {
            $numerator = $numerator."-x^(2)";
        }
        else
        {
            $numerator = $numerator.$coeff2."*x^(2)";
        }
    }
    if ($coeff3 != 0)
    {
        if ($coeff3 == "+1")
        {
            $numerator = $numerator."+x";
        }
        else if ($coeff3 == -1)
        {
            $numerator = $numerator."-x";
        }
        else
        {
            $numerator = $numerator.$coeff3."*x";
        }
    }
    $numerator = $numerator.$coeff4;

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #46 Generator               ////
////         Polynomial Multiplication 6               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_46( )
{
    $answer = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(2,5);
    $d = rand(2,5);
    $e = rand(1,5);
    rand_switch_sign($b,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    $coeff1 = $a * $c;
    $coeff2 = $a * $d;
    $coeff3 = $a * $e;
    $coeff4 = $b * $c;
    $coeff5 = $b * $d;
    $coeff6 = $b * $e;
    if ($b > 0)
    {
        $b = "+".$b;
    }
    if ($d > 0)
    {
        $d = "+".$d;
    }
    if ($e > 0)
    {
        $e = "+".$e;
    }
    if ($coeff2 > 0)
    {
        $coeff2 = "+".$coeff2;
    }
    if ($coeff3 > 0)
    {
        $coeff3 = "+".$coeff3;
    }
    if ($coeff4 > 0)
    {
        $coeff4 = "+".$coeff4;
    }
    if ($coeff5 > 0)
    {
        $coeff5 = "+".$coeff5;
    }
    if ($coeff6 > 0)
    {
        $coeff6 = "+".$coeff6;
    }
    if ($a == 1)
    {
        $question = "(".$c."y^(2)".$d."y".$e.")*(y^(3)".$b.")";
    }
    else
    {
        $question = "(".$c."y^(2)".$d."y".$e.")*(".$a."y^(3)".$b.")";
    }
    $numerator = $coeff1."*y^5".$coeff2."*y^4".$coeff3."*y^3".$coeff4."*y^2";
    $numerator = $numerator.$coeff5."*y".$coeff6;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #47 Generator               ////
////         Polynomial Multiplication 7               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_47( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = 0;
    $e = 0;
    $f = 0;
    $d = $a;
    $e = (-1) * $b;
    $f = $c;
    $coeff1 = $d * $a;
    $coeff2 = $d * $b + $e * $a;
    $coeff3 = $f * $a + $e * $b + $d * $c;
    $coeff4 = $b * $f + $e * $c;
    $coeff5 = $c * $f;
    coeff_prep($b);
    coeff_prep($a);
    coeff_prep($e);
    coeff_prep($d);
    $question = "(".$c." ".$b."x ".$a."x^2)*(".$f." ".$e."x ".$d."x^2)";
    if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = $coeff1."x^4";
    if ($coeff_2 != 0)
    {
        coeff_prep($coeff2);
        $numerator = $numerator.$coeff2."*x^3 ";
    }
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $numerator = $numerator.$coeff3."*x^2 ";
    }
    if ($coeff4 != 0)
    {
        coeff_prep($coeff4);
        $numerator = $numerator.$coeff4."*x ";
    }
    coeff_prep($coeff5,0);
    $numerator = $numerator.$coeff5;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #48 Generator               ////
////         Polynomial Multiplication 8               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_48( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = 0;
    $e = 0;
    $f = 0;
    $d = (-1) * $a;
    $e = $b;
    $f = (-1) * $c;
    $coeff1 = $d * $a;
    $coeff2 = $d * $b + $e * $a;
    $coeff3 = $f * $a + $e * $b + $d * $c;
    $coeff4 = $b * $f + $e * $c;
    $coeff5 = $c * $f;
    coeff_prep($b);
    coeff_prep($a);
    coeff_prep($e);
    coeff_prep($d);
    $question = "(".$c." ".$b."x ".$a."x^2)*(".$f." ".$e."x ".$d."x^2)";
    if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = $coeff1."x^4";
    if ($coeff_2 != 0)
    {
        coeff_prep($coeff2);
        $numerator = $numerator.$coeff2."x^3 ";
    }
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $numerator = $numerator.$coeff3."x^2 ";
    }
    if ($coeff4 != 0)
    {
        coeff_prep($coeff4);
        $numerator = $numerator.$coeff4."x ";
    }
    coeff_prep($coeff5,0);
    $numerator = $numerator.$coeff5;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #49 Generator               ////
////         Polynomial Multiplication 9               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_49( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $b = rand(2,5);
    rand_switch_sign($b,2);
    $coeff2 = $b * 3;
    $temp = pow($b,2);
    $coeff3 = $temp * 3;
    $coeff4 = pow($b,3);
    coeff_prep($b);
    coeff_prep($coeff2);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    $question = "(a ".$b.")^3";
    $numerator = "a^3".$coeff2."a^2".$coeff3."a ".$coeff4;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #50 Generator               ////
////         Polynomial Multiplication 10              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_50( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,5);
    rand_switch_sign($b,2);
    $coeff1 = pow($a,3);
    $temp = pow($a,2);
    $coeff2 = $temp * $b * 3;
    $temp = pow($b,2);
    $coeff3 = $temp * $a * 3;
    $coeff4 = pow($b,3);
    coeff_prep($b);
    coeff_prep($coeff2);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    $question = "(".$a."x ".$b.")^3";
    $numerator = $coeff1."x^3".$coeff2."x^2".$coeff3."x ".$coeff4;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #51 Generator               ////
////         Polynomial Multiplication 11              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_51( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $b = rand(2,5);
    rand_switch_sign($b,2);
    $coeff2 = $b * 3;
    $temp = pow($b,2);
    $coeff3 = $temp * 3;
    $coeff4 = pow($b,3);
    coeff_prep($b);
    coeff_prep($coeff2);
    coeff_prep($coeff3);
    coeff_prep($coeff4);
    $question = "(x ".$b."y)^3";
    $numerator = "x^3".$coeff2."x^2y".$coeff3."xy^2".$coeff4."y^3";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #52 Generator               ////
////                Factoring 1                        ////
////             Pull out the GCF                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_52( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,6);
    $b = rand(2,6);
    $c = rand(2,6);
    $d = rand(1,4);
    $e = rand(2,6);
    $f = rand(1,4);
    $d = 2 * $d;
    $f = 2 * $f + 1;
    while ($d == 6 && $f == 3)
    {
        $f = rand(1,4);
        $f = 2 * $f + 1;
    }
    $f = (-1) * $f;
    $q_coeff1 = $a;
    $q_coeff2 = $d * $a;
    $q_coeff3 = $f * $a;
    $k_pow1 = $b;
    $k_pow2 = $b + $e;
    $k_pow3 = $b;
    $m_pow1 = $c;
    $m_pow2 = $c;
    $m_pow3 = $c + 1;
    $a_coeff1 = $a;
    $a_coeff2 = 1;
    $a_coeff3 = $d;
    $a_coeff4 = $f;
    $a_k_pow1 = $b;
    $a_k_pow2 = $e;
    $a_m_pow1 = $c;
    coeff_prep($q_coeff2);
    coeff_prep($q_coeff3);
    coeff_prep($a_coeff3);
    coeff_prep($a_coeff4);
    $q1 = $q_coeff1."k^(".$k_pow1.")*m^(".$m_pow1.")";
    $q2 = $q_coeff2."k^(".$k_pow2.")*m^(".$m_pow2.")";
    $q3 = $q_coeff3."k^(".$k_pow3.")*m^(".$m_pow3.")";
    $question = $q1.$q2.$q3;
    $n1 = $a_coeff1."k^".$a_k_pow1."m^".$a_m_pow1."(";
    $n2 = $a_coeff2.$a_coeff3."k^".$a_k_pow2."";
    $n3 = $a_coeff4."m )";
    $numerator = $n1.$n2.$n3;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #53 Generator               ////
////                Factoring 2                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_53()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $temp =  pow($a,2);
    $question = "x^2 - ".$temp;
    $numerator = "(x-".$a.")(x+".$a.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #54 Generator               ////
////                Factoring 3                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_54( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(1,9);
    $temp_a = $a;
    $temp_b = $b;
    while (reduce($temp_a,$temp_b))
    {
        $b = rand(1,9);
        $temp_a = $a;
        $temp_b = $b;
    }
    $temp1 = pow($a,2);
    $temp2 = pow($b,2);
    $question = $temp1."x^2 - ".$temp2;
    $numerator = "(".$a."x-".$b.")(".$a."x+".$b.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #55 Generator               ////
////                Factoring 4                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_55( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    $temp_a = $a;
    $temp_b = $b;
    while (reduce($temp_a,$temp_b))
    {
        $b = rand(2,9);
        $temp_a = $a;
        $temp_b = $b;
    }
    $temp1 = pow($a,2);
    $temp2 = pow($b,2);
    $question = $temp1."m^4 - ".$temp2."n^4";
    $numerator = "(".$a."m^2-".$b."n^2)(".$a."m^2+".$b."n^2)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #56 Generator               ////
////                Factoring 5                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_56()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    $temp =  (-1) * $b;
    while ($a == $temp)
    {
        $b = rand(1,9);
        rand_switch_sign($b,2);
        $temp = (-1) * $b;
    }
    $coeff1 = $a + $b;
    $coeff2 = $a * $b;
    coeff_prep($a,0);
    coeff_prep($b,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "x^(2) ".$coeff1."x ".$coeff2;
    $numerator = "(x ".$a.")(x ".$b.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #57 Generator               ////
////                Factoring 6                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_57( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,6);
    $b = rand(2,4);
    $b = r_prime($b);
    $c = rand(1,6);
    $temp_b = $b;
    $temp_c = $c;
    while (reduce($temp_b,$temp_c))
    {
        $c = rand(1,6);
        $temp_b = $b;
        $temp_c = $c;
    }
    rand_switch_sign($a,2);
    rand_switch_sign($c,2);
    $temp = $a * $b + $c;
    while ($temp == 0)
    {
        $a = rand(1,6);
        $b = rand(2,4);
        $b = r_prime($b);
        $c = rand(1,6);
        $temp_b = $b;
        $temp_c = $c;
        while (reduce($temp_b,$temp_c))
        {
            $c = rand(1,6);
            $temp_b = $b;
            $temp_c = $c;
        }
        rand_switch_sign($a,2);
        rand_switch_sign($c,2);
        $temp = $a * $b + $c;
    }
    $coeff1 = $temp;
    $coeff2 = $c * $a;
    coeff_prep($a,0);
    coeff_prep($c,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = $b."x^2".$coeff1."x ".$coeff2;
    $numerator = "(".$b."x ".$c.")(x ".$a.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #58 Generator               ////
////                Factoring 7                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_58( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,7);
    $b = rand(1,4);
    $c = rand(2,5);
    while ($c == $a)
    {
        $c = rand(2,5);
    }
    $d = rand(1,9);
    $temp_a = $a;
    $temp_b = $b;
    $temp_c = $c;
    $temp_d = $d;
    while (reduce($temp_a,$temp_b))
    {
        $b = rand(1,4);
        $temp_a = $a;
        $temp_b = $b;
    }
    while (reduce($temp_c,$temp_d))
    {
        $d = rand(1,9);
        $temp_c = $c;
        $temp_d = $d;
    }
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    $temp = $a * $d + $b * $c;
    while ($temp == 0)
    {
        $a = rand(2,9);
        $b = rand(1,4);
        $c = rand(2,5);
        while ($c == $a)
        {
            $c = rand(2,5);
        }
        $d = rand(1,4);
        $temp_a = $a;
        $temp_b = $b;
        $temp_c = $c;
        $temp_d = $d;
        while (reduce($temp_a,$temp_b))
        {
            $b = rand(1,4);
            $temp_a = $a;
            $temp_b = $b;
        }
        while (reduce($temp_c,$temp_d))
        {
            $d = rand(1,9);
            $temp_c = $c;
            $temp_d = $d;
        }
        rand_switch_sign($b,2);
        rand_switch_sign($d,2);
        $temp = $a * $d + $b * $c;
    }
    $coeff1 = $a * $c;
    $coeff2 = $temp;
    $coeff3 = $d * $b;
    coeff_prep($b,0);
    coeff_prep($d,0);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = $coeff1."x^2 ".$coeff2."x ".$coeff3;
    $numerator = "(".$a."x ".$b.")(".$c."x ".$d.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #59 Generator               ////
////                Factoring 8                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_59()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,10);
    $b = rand(1,9);
    $c = rand(1,9);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    $temp = $c * (-1);
    while ($b == $temp)
    {
        $c = rand(1,9);
        rand_switch_sign($c,2);
        $temp = $c * (-1);
    }
    $coeff1 = $a * ($b + $c);
    $coeff2 = $a * $b * $c;
    coeff_prep($b,0);
    coeff_prep($c,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = $a."x^2 ".$coeff1."x ".$coeff2;
    $numerator = $a."(x ".$b.")(x ".$c.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #60 Generator               ////
////                Factoring 9                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_60( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(2,9);
    $c = rand(1,9);
    $temp_b = $b;
    $temp_c = $c;
    while (reduce($temp_b,$temp_c))
    {
        $c = rand(1,9);
        $temp_b = $b;
        $temp_c = $c;
    }
    rand_switch_sign($a,2);
    rand_switch_sign($c,2);
    $temp = $a * $b + $c;
    while ($temp == 0)
    {
        $a = rand(1,9);
        $b = rand(2,9);
        $c = rand(1,9);
        $temp_b = $b;
        $temp_c = $c;
        while (reduce($temp_b,$temp_c))
        {
            $c = rand(1,9);
            $temp_b = $b;
            $temp_c = $c;
        }
        rand_switch_sign($a,2);
        rand_switch_sign($c,2);
        $temp = $a * $b + $c;
    }
    $coeff1 = $temp;
    $coeff2 = $c * $a;
    coeff_prep($a,0);
    coeff_prep($c,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    $question = $b."x^3 ".$coeff1."x^2 ".$coeff2."x";
    $numerator = "x(".$b."x".$c.")(x".$a.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #61 Generator               ////
////                Factoring 10                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_61( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    $temp =  (-1) * $b;
    while ($a == $temp)
    {
        $b = rand(1,9);
        rand_switch_sign($b,2);
        $temp = (-1) * $b;
    }
    $coeff1 = $a + $b;
    $coeff2 = $a * $b;
    coeff_prep($a,0);
    coeff_prep($b,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    $question = "x^3 ".$coeff1."x^2 ".$coeff2."x";
    $numerator = "x(x".$a.")(x".$b.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #62 Generator               ////
////                Factoring 11                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_62( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    $temp =  (-1) * $b;
    while ($a == $temp)
    {
        $b = rand(1,9);
        rand_switch_sign($b,2);
        $temp = (-1) * $b;
    }
    $coeff1 = $a + $b;
    $coeff2 = $a * $b;
    coeff_prep($a,0);
    coeff_prep($b,0);
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    $question = "x^4 ".$coeff1."x^3 ".$coeff2."x^2";
    $numerator = "x^2(x".$a.")(x".$b.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #63 Generator               ////
////                Factoring 12                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_63( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $q_coeff = (-1) * pow($a,3);
    $coeff1 = (-1) * $a;
    $coeff2 = $a;
    $coeff3 = pow($a,2);
    coeff_prep($q_coeff,0);
    coeff_prep($coeff1,0);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = "x^3".$q_coeff;
    $numerator = "(x".$coeff1.")(x^2".$coeff2."x".$coeff3.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #64 Generator               ////
////                Factoring 13                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_64( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $q_coeff = pow($a,3);
    $coeff1 = $a;
    $coeff2 = (-1) * $a;
    $coeff3 = pow($a,2);
    coeff_prep($q_coeff,0);
    coeff_prep($coeff1,0);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = "x^3".$q_coeff;
    $numerator = "(x".$coeff1.")(x^2".$coeff2."x".$coeff3.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #65 Generator               ////
////                Factoring 14                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_65( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = 2*rand(1,2); // $a = rand(2,5);
    $b = 2* rand(1,3)-1; // $b = rand(1,5);  this is line 4755
    // while ($a == $b)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 2 && $b == 4)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 4 && $b == 2)
    // {
    // $b = rand(1,5);
    // }   this is line 4767
    $q_coeff1 = pow($a,3);
    $q_coeff2 = (-1) * pow($b,3);
    $coeff1 = (-1) * $b;
    $coeff2 = pow($a,2);
    $coeff3 = $a * $b;
    $coeff4 = pow($b,2);
    coeff_prep($q_coeff2,0);
    coeff_prep($coeff1,0);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    $question = $q_coeff1."x^3".$q_coeff2;
    $numerator = "(".$a."x".$coeff1.")(".$coeff2."x^2".$coeff3."x".$coeff4.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #66 Generator               ////
////                Factoring 15                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_66( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = 2*rand(1,2); //$a = rand(2,5);
    $b = 2*rand(1,3)- 1 ;    // $b = rand(1,5);
    // while ($a == $b)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 2 && $b == 4)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 4 && $b == 2)
    // {
    // $b = rand(1,5);
    // }
    $q_coeff1 = pow($a,3);
    $q_coeff2 = pow($b,3);
    $coeff1 = $b;
    $coeff2 = pow($a,2);
    $coeff3 = (-1) * $a * $b;
    $coeff4 = pow($b,2);
    coeff_prep($q_coeff2,0);
    coeff_prep($coeff1,0);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    $question = $q_coeff1."x^3".$q_coeff2;
    $numerator = "(".$a."x".$coeff1.")(".$coeff2."x^2".$coeff3."x".$coeff4.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #67 Generator               ////
////                Factoring 16                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_67( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = 2*rand(1,2); // $a = rand(1,5);
    $b = 2*rand(1,3)-1;   // $b = rand(1,5);
    // while ($a == $b)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 2 && $b == 4)
    // {
    // $b = rand(1,5);
    // }
    // while ($a == 4 && $b == 2)
    // {
    // $b = rand(1,5);
    //}
    $q_coeff1 = "";
    if ($a != 1)
    {
        $q_coeff1 = pow($a,3);
    }
    $q_coeff2 = (-1) * pow($b,3);
    $coeff1 = "";
    if ($a != 1)
    {
        $coeff1 = (string)$a;
    }
    $coeff2 = (-1) * $b;
    $coeff3 = "";
    if ($a != 1)
    {
        $coeff3 = pow($a,2);
    }
    $coeff4 = $a * $b;
    $coeff5 = pow($b,2);
    coeff_prep($q_coeff2);
    coeff_prep($coeff2);
    coeff_prep($coeff4);
    coeff_prep($coeff5);
    $question = $q_coeff1."m^3".$q_coeff2."n^3";
    $numerator = "(".$coeff1."m".$coeff2."n)(".$coeff3."m^2".$coeff4."mn".$coeff5."n^2)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #68 Generator               ////
////                Factoring 17                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_68( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $b = rand(1,5);
    while ($a == $b)
    {
        $b = rand(1,5);
    }
    while ($a == 2 && $b == 4)
    {
        $b = rand(1,5);
    }
    while ($a == 4 && $b == 2)
    {
        $b = rand(1,5);
    }
    $q_coeff1 = "";
    if ($a != 1)
    {
        $q_coeff1 = pow($a,3);
    }
    $q_coeff2 = pow($b,3);
    $coeff1 = "";
    if ($a != 1)
    {
        $coeff1 = (string)$a;
    }
    $coeff2 = $b;
    $coeff3 = "";
    if ($a != 1)
    {
        $coeff3 = pow($a,2);
    }
    $coeff4 = (-1) * $a * $b;
    $coeff5 = pow($b,2);
    coeff_prep($q_coeff2);
    coeff_prep($coeff2);
    coeff_prep($coeff4);
    coeff_prep($coeff5);
    $question = $q_coeff1."m^3".$q_coeff2."n^3";
    $numerator = "(".$coeff1."m".$coeff2."n)(".$coeff3."m^2".$coeff4."mn".$coeff5."n^2)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #69 Generator               ////
////                Factoring 18                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_69( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,2);
    $a = rand(1,4);
    $a = 2 * $a;
    $b = rand(2,4);
    $b = 2 * $b + 1;
    $randier = rand(1,2);
    if ($randier == 1)
    {
        $temp = $a;
        $a = $b;
        $b = $temp;
    }
    if ($randy == 1)
    {
        rand_switch_sign($a,2);
        $q_coeff1 = "";
        $q_coeff2 = $a;
        $q_coeff3 = $b;
        $q_coeff4 = $a * $b;
        $coeff1 = "";
        $coeff2 = $b;
        $coeff3 = "";
        $coeff4 = $a;
        coeff_prep($q_coeff2);
        coeff_prep($q_coeff3);
        coeff_prep($q_coeff4,0);
        coeff_prep($coeff2,0);
        coeff_prep($coeff4,0);
    }
    else
    {
        $q_coeff1 = $b;
        $q_coeff2 = 1;
        $q_coeff3 = $a * $b;
        $q_coeff4 = $a;
        $coeff1 = "";
        $coeff2 = $a;
        $coeff3 = $b;
        $coeff4 = "+ 1";
        coeff_prep($q_coeff2);
        coeff_prep($q_coeff3);
        coeff_prep($q_coeff4,0);
        coeff_prep($coeff2,0);
    }
    $question = $q_coeff1."x^3 ".$q_coeff2."x^2 ".$q_coeff3."x ".$q_coeff4;
    $numerator = "(".$coeff1."x^2".$coeff2.")(".$coeff3."x".$coeff4.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #70 Generator               ////
////                Factoring 19                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_70( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,6);
    $b = rand(2,6);
    $c = rand(1,6);
    if ($c != 1)
    {
        $temp_a = $a;
        $temp_c = $c;
        while (reduce($temp_a,$temp_c))
        {
            $c = rand(2,6);
            $temp_a = $a;
            $temp_c = $c;
        }
    }
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b * $a;
    $q_coeff3 = $c;
    $q_coeff4 = $c * $b;
    $coeff1 = $a;
    $coeff2 = $c;
    $coeff3 = "";
    $coeff4 = $b;
    coeff_prep($q_coeff2);
    coeff_prep($q_coeff3);
    coeff_prep($q_coeff4,0);
    coeff_prep($coeff2,0);
    coeff_prep($coeff4,0);
    $question = $q_coeff1."x^2".$q_coeff2."x ".$q_coeff3."x ".$q_coeff4;
    $numerator = "(".$coeff1."x".$coeff2.")(".$coeff3."x".$coeff4.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #71 Generator               ////
////                Factoring 20                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_71( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(1,5);
    $c = rand(2,5);
    $d = rand(1,5);
    while ($a == $b)
    {
        $b = rand(1,5);
    }
    while ($a == 2 && $b == 4)
    {
        $b = rand(1,5);
    }
    while ($a == 4 && $b == 2)
    {
        $b = rand(1,5);
    }
    while ($c == $d)
    {
        $d = rand(1,5);
    }
    while ($c == 2 && $d == 4)
    {
        $d = rand(1,5);
    }
    while ($c == 4 && $c == 2)
    {
        $d = rand(1,5);
    }
    $q_coeff1 = $a * $c;
    $q_coeff2 = $a * $d;
    $q_coeff3 = $b * $d;
    $q_coeff4 = $b * $c;
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $c;
    $coeff4 = $d;
    coeff_prep($q_coeff2);
    coeff_prep($q_coeff3);
    coeff_prep($q_coeff4);
    coeff_prep($coeff2);
    coeff_prep($coeff4);
    $question = $q_coeff1."ac ".$q_coeff2."ad ".$q_coeff3."bd ".$q_coeff4."bc";
    $numerator = "(".$coeff1."a".$coeff2."b)(".$coeff3."c".$coeff4."d)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #72 Generator               ////
////                Factoring 21                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_72( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(1,9);
    while ($a == $b)
    {
        $b = rand(1,9);
    }
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    coeff_prep($a,0);
    coeff_prep($b,0);
    $question = "x *(x ".$b.") ".$a."(x ".$b.")";
    $numerator = "(x".$a.")(x".$b.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #73 Generator               ////
////                Factoring 22                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_73( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,2);
    $a = rand(1,3);
    $a = pow(2,$a);
    $b = rand(1,3);
    $b = pow(2,$b);
    $c = 2 * rand(1,9) + 1;
    rand_switch_sign($c,2);
    $coeff1 = $a + $c;
    $coeff2 = $a * $b ;
    coeff_prep($b,0);
    coeff_prep($coeff2,0);
    if ($randy == 1)
    {
        coeff_prep($c);
        $question = $a."(x ".$b.")^(2) ".$c."x*(x ".$b.")";
    }
    else // $randy == 2
    {
        coeff_prep($a,0);
        $question = $c."x *(x ".$b.")".$a."(x ".$b.")^(2)";
    }
    if ($coeff1 == 1)
    {
        $numerator = "(x ".$b.")(x ".$coeff2.")";
    }
    else if ($coeff1 == -1)
    {
        $numerator = "(x ".$b.")(-x ".$coeff2.")";
    }
    else
    {
        $numerator = "(x ".$b.")(".$coeff1."x ".$coeff2.")";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #74 Generator               ////
////                Factoring 23                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_74( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,9);
    $d = rand(2,9);
    while ($d == $b)
    {
        $d = rand(2,9);
    }
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    $temp1 = $b + $d;
    $temp2 = $a+1;
    if ($temp1 != 1 && $temp1 != -1)
    {
        while (reduce($temp1,$temp2))
        {
            $d = rand(2,9);
            while ($d == $b)
            {
                $d = rand(2,9);
            }
            rand_switch_sign($d,2);
            $temp1 = $b + $d;
            $temp2 = $a+1;
        }
    }
    $coeff1 = $a + 1;
    coeff_prep($b,0);
    coeff_prep($c,0);
    coeff_prep($d,0);
    coeff_prep($temp1,0);
    $question = "(".$a."y ".$b.")*(y ".$c.")";
    $question = $question." + (y ".$d.")*(y ".$c.")";
    $numerator = "(y ".$c.")(".$coeff1."y ".$temp1.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #75 Generator               ////
////                Factoring 24                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_75( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = 2 * rand(1,4);
    $b = rand(1,3);
    $b = 2 * $b + 1;
    if ($a == 6 && $b == 3)
    {
        $b = rand(1,2);
        if ($b == 2)
        {
            $b = 5;
        }
    }
    if ($a == 2)
    {
        $c = 2 * rand(2,6) - 1;
        while ($c == 7)
        {
            $c = 2 * rand(2,5) - 1;
        }
    }
    else if ($a == 4)
    {
        $c = rand(1,3);
        if ($c != 1)
        {
            $c = 2 * rand(2,5) - 1;
        }
        while ($c == 5)
        {
            $c = 2 * rand(2,5) - 1;
        }
    }
    else if ($a == 6)
    {
        $c = rand(1,3);
        if ($c != 1)
        {
            $c = 2 * rand(3,6) - 1;
        }
        while ($c == 9)
        {
            $c = 2 * rand(2,6) - 1;
        }
    }
    else // $a == 8
    {
        $c = 2 * rand(2,6) - 1;
        while ($c == 7)
        {
            $c = 2 * rand(2,6) - 1;
        }
    }
    if ($c == 3 || $c == 9)
    {
        $d = 2 * rand(3,4) - 1;
    }
    else
    {
        $d = 2 * rand(1,6) - 1;
        while ($d == $c)
        {
            $d = 2 * rand(2,6) - 1;
        }
    }
    while ($d == $b)
    {
        if ($c == 3 || $c == 9)
        {
            $d = 2 * rand(3,4) - 1;
        }
        else
        {
            $d = 2 * rand(1,6) - 1;
            while ($d == $c)
            {
                $d = 2 * rand(2,6) - 1;
            }
        }
    }
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    $temp1 = $a + $c;
    $temp2 = $b + $d;
    while (reduce($temp1,$temp2))
    {
        $d = rand(1,4);
        if ($d == 3)
        {
            $d = 4;
        }
        else
        {
            $d = 2 * $d;
        }
        rand_switch_sign($d,2);
        $temp1 = $a + $c;
        $temp2 = $b + $d;
    }
    $coeff1 = $temp1;
    $coeff2 = $temp2;
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    coeff_prep($b,0);
    coeff_prep($d,0);
    coeff_prep($coeff2,0);
    $question1 = "(".$a."x ".$b.")*(".$c."x ".$d.")^(2)";
    $question2 = "(".$a."x ".$b.")^2*(".$c."x ".$d.")";
    $question = $question1." + ".$question2;
    $numerator1 = "(".$a."x".$b.")*(".$c."x".$d.")";
    $numerator2 = "*(".$coeff1."x".$coeff2.")";
    $numerator = $numerator1.$numerator2;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #76 Generator               ////
////     Simplifing Rational Expressions 1             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_76()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,4);
    if ($randy == 1)
    {
        $q_num = "x^2 - 1";
        $q_denom = "x^3 - 1";
        $numerator = "x+1";
        $denominator = "x^2+x+1";
    }
    else if ($randy == 2)
    {
        $q_num = "x^2 - 1";
        $q_denom = "x^3 + 1";
        $numerator = "x-1";
        $denominator = "x^2-x+1";
    }
    else if ($randy == 3)
    {
        $q_num = "x^3 - 1 ";
        $q_denom = "x^2 - 1";
        $numerator = "x^2+x+1";
        $denominator = "x+1";
    }
    else // $randy == 4
    {
        $q_num = "x^3 + 1";
        $q_denom = "x^2 - 1";
        $numerator = "x^2-x+1";
        $denominator = "x-1";
    }
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #77 Generator               ////
////     Simplifing Rational Expressions 2             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_77()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,2);
    $a = rand(2,4);
    $b = rand(2,8);
    while ($a == $b)
    {
        $b = rand(2,8);
    }
    rand_switch_sign($b,2);
    if ($randy == 1)
    {
        $temp = pow($a,3);
        $q_num = "x^3 - ".$temp;
        $n_coeff1 = $a;
        $n_coeff2 = pow($a,2);
        $d_coeff1 = $b;
        $a = $a * (-1);
        $q_coeff1 = $b + $a;
        $q_coeff2 = $b * $a;
        coeff_prep($q_coeff1);
        coeff_prep($q_coeff2,0);
        coeff_prep($n_coeff1);
        coeff_prep($n_coeff2,0);
        coeff_prep($d_coeff1);
        $q_denom = "x^2 ".$q_coeff1."x ".$q_coeff2;
        $numerator = "x^2 ".$n_coeff1."x ".$n_coeff2;
        $denominator = "x ".$d_coeff1;
    }
    else //$randy == 2
    {
        $temp = pow($a,3);
        $q_num = "x^3 + ".$temp;
        $n_coeff1 = $a * (-1);
        $n_coeff2 = pow($a,2);
        $d_coeff1 = $b;
        $q_coeff1 = $b + $a;
        $q_coeff2 = $b * $a;
        coeff_prep($q_coeff1);
        coeff_prep($q_coeff2,0);
        coeff_prep($n_coeff1);
        coeff_prep($n_coeff2,0);
        coeff_prep($d_coeff1);
        $q_denom = "x^2 ".$q_coeff1."x ".$q_coeff2;
        $numerator = "x^2".$n_coeff1."x".$n_coeff2;
        $denominator = "x".$d_coeff1;
    }
    $question ="(". $q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #78 Generator               ////
////     Simplifing Rational Expressions 3             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_78()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    while ($a == $c)
    {
        $c = rand(2,9);
    }
    while ($c == $b)
    {
        $c = rand(2,9);
        while ($a == $c)
        {
            $c = rand(2,9);
        }
    }
    $qn_coeff1 = $a + $b;
    $qn_coeff2 = $a * $b;
    $qd_coeff1 = $a + $c;
    $qd_coeff2 = $a * $c;
    $n_coeff1 = $b;
    $d_coeff1 = $c;
    coeff_prep($qn_coeff1);
    coeff_prep($qn_coeff2,0);
    coeff_prep($qd_coeff1);
    coeff_prep($qd_coeff2,0);
    coeff_prep($n_coeff1);
    coeff_prep($d_coeff1);
    $q_num = "x^2 ".$qn_coeff1."x ".$qn_coeff2;
    $q_denom = "x^2 ".$qd_coeff1."x ".$qd_coeff2;
    $numerator = "x".$n_coeff1;
    $denominator = "x".$d_coeff1;
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #79 Generator               ////
////     Simplifing Rational Expressions 4             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_79()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    rand_switch_sign($b,2);
    $qn_coeff1 = (-1) * pow($a,2);
    $qd_coeff1 = $a + $b;
    $qd_coeff2 = $a * $b;
    $n_coeff1 = (-1) * $a;
    $d_coeff1 = $b;
    coeff_prep($qn_coeff1,0);
    coeff_prep($qd_coeff1);
    coeff_prep($qd_coeff2,0);
    coeff_prep($n_coeff1,0);
    coeff_prep($d_coeff1,0);
    $q_num = "x^2 ".$qn_coeff1;
    $q_denom = "x^2 ".$qd_coeff1."x ".$qd_coeff2;
    $numerator = "x".$n_coeff1;
    $denominator = "x".$d_coeff1;
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #80 Generator               ////
////     Simplifing Rational Expressions 5             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_80()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(1,3);
    $b = 2*$b;
    $c = rand(1,3);
    $c = 2 * $c + 1;
    if ($c == 3 && $b == 6)
    {
        $c = rand(1,2);
        if ($c == 1)
        {
            $c = 5;
        }
        else
        {
            $c = 7;
        }
    }
    $d = rand(2,9);
    while ($d == $a)
    {
        $d = rand(2,9);
    }
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    $qn_coeff1 = $b;
    $qn_coeff2 = $c + ($b * $a);
    $qn_coeff3 = $c * $a;
    $qd_coeff1 = $d + $a;
    $qd_coeff2 = $a * $d;
    $n_coeff1 = $b;
    $n_coeff2 = $c;
    $d_coeff1 = $d;
    coeff_prep($qn_coeff2);
    coeff_prep($qn_coeff3,0);
    coeff_prep($qd_coeff1);
    coeff_prep($qd_coeff2,0);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    $q_num = $qn_coeff1."x^3 ".$qn_coeff2."x^2 ".$qn_coeff3."x";
    $q_denom = "x^3 ".$qd_coeff1."x^2 ".$qd_coeff2."x";
    $numerator = $n_coeff1."x".$n_coeff2;
    $denominator = "x".$d_coeff1;
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #81 Generator               ////
////     Simplifing Rational Expressions 6             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_81( )
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,3);
    $b = rand(1,3);
    while ($a == $b)
    {
        $b = rand(1,3);
    }
    $c = rand($b+1,9);
    $b = $b * (-1);
    rand_switch_sign($c,2);
    $qn_coeff1 = "";
    if ($a != 1)
    {
        $qn_coeff1 = $a;
    }
    $qn_coeff2 = ($c * $a) + $b;
    $qn_coeff3 = $c * $b;
    $qd_coeff1 = (-1) * $b;
    $qd_coeff2 = (-1) * $a;
    $n_coeff1 = (-1)*$c;
    coeff_prep($qn_coeff2);
    coeff_prep($qn_coeff3,0);
    coeff_prep($qd_coeff2);
    coeff_prep($n_coeff1,0);
    $q_num = $qn_coeff1."x^2 ".$qn_coeff2."x ".$qn_coeff3;
    $q_denom = $qd_coeff1.$qd_coeff2."x";
    $numerator = "-x ".$n_coeff1;
    $question = "(".$q_num.")/(".$q_denom.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #82 Generator               ////
////     Simplifing Rational Expressions 7             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_82( )
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    rand_switch_sign($b,2);
    $qn_coeff1 = $a + $b;
    $qn_coeff2 = $a * $b;
    $qd_coeff1 = pow($a,2);
    $n_coeff1 = $b;
    $d_coeff1 = $a;
    coeff_prep($qn_coeff1);
    coeff_prep($qn_coeff2,0);
    coeff_prep($n_coeff1);
    $q_num = "x^2 ".$qn_coeff1."x ".$qn_coeff2;
    $q_denom = $qd_coeff1."- x^2";
    $numerator = "x".$n_coeff1;
    $denominator = $d_coeff1."-x";
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #83 Generator               ////
////   Adding/Subtracting Rational Expressions 1       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_83()
{
    $q_num1 = "x";
    $q_num2 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(1,9);
    $b = rand(1,3);
    while ($a == $b)
    {
        $b = rand(1,3);
    }
    $c = rand(2,9);
    $d = rand(2,9);
    $temp = 1 - $b * $c - $d;
    $temp1 = pow($temp,2);
    $temp2 = 4 * $b * $c * $d;
    while ( $temp1 > $temp2 )
    {
        $b = rand(1,3);
        while ($a == $b)
        {
            $b = rand(1,3);
        }
        $c = rand(2,9);
        $d = rand(2,9);
        $temp = 1 - $b * $c - $d;
        $temp1 = pow($temp,2);
        $temp2 = 4 * $b * $c * $d;
    }
    $qd1_coeff1 = $a - $b;
    $qd1_coeff2 = (-1) * $a * $b;
    $qd2_coeff1 = $a;
    $qn2_coeff1 = $c;
    $qn2_coeff2 = (-1) * $d;
    $n_coeff1 = $c;
    $n_coeff2 = 1 - $b * $c - $d;
    $n_coeff3 = $b * $d;
    $d_coeff1 = $a;
    $d_coeff2 = (-1) * $b;
    $d2_coeff1 = $a - $b;
    $d2_coeff2 = $a * (-1) * $b;
    coeff_prep($qd1_coeff1);
    coeff_prep($qd1_coeff2,0);
    coeff_prep($qd2_coeff1,0);
    coeff_prep($qn2_coeff2,0);
    coeff_prep($n_coeff2);
    coeff_prep($n_coeff3,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($d_coeff2,0);
    coeff_prep($d2_coeff1);
    coeff_prep($d2_coeff2,0);
    $q_num2 = $qn2_coeff1."x ".$qn2_coeff2;
    $q_denom1 = "x^2 ".$qd1_coeff1."x ".$qd1_coeff2;
    $q_denom2 = "x ".$qd2_coeff1;
    $numerator = $n_coeff1."x^2".$n_coeff2."x".$n_coeff3;
    $denominator = "(x".$d_coeff1.")(x".$d_coeff2.")";
    $numerator2 = $numerator;
    $denominator2 = "x^2".$d2_coeff1."x".$d2_coeff2;
    $question = "(".$q_num1.")/(".$q_denom1.")+(".$q_num2.")/(".$q_denom2.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #84 Generator               ////
////   Adding/Subtracting Rational Expressions 2       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_84( )
{
    $q_num1 = "";
    $q_num2 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = 2 * rand(1,4);
    $b = 2 * rand(1,4) - 1;
    $c = 2 * rand(1,4) - 1;
    $d = 2 * rand(1,4) + 1;
    $qn1_coeff1 = $d;
    $qn2_coeff1 = (-1) * $c;
    $qd1_coeff1 = (-1) * $b;
    $qd2_coeff1 = $a - $b;
    $qd2_coeff2 = (-1) * $a * $b;
    $n_coeff1 = ($d - 1);
    $n_coeff2 = $d * $a + $c;
    $d_coeff1 = $a;
    $d_coeff2 = (-1) * $b;
    $d2_coeff1 = $a - $b;
    $d2_coeff2 = (-1) * $a * $b;
    coeff_prep($qn2_coeff1,0);
    coeff_prep($qd1_coeff1,0);
    coeff_prep($qd2_coeff1);
    coeff_prep($qd2_coeff2,0);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($d_coeff2,0);
    coeff_prep($d2_coeff1);
    coeff_prep($d2_coeff2,0);
    $q_num1 = (string)$qn1_coeff1;
    $q_num2 = "x ".$qn2_coeff1;
    $q_denom1 = "x ".$qd1_coeff1;
    $q_denom2 = "x^2 ".$qd2_coeff1."x ".$qd2_coeff2;
    $numerator = $n_coeff1."x ".$n_coeff2;
    $numerator2 = $numerator;
    $denominator = "(x".$d_coeff1.")(x".$d_coeff2.")";
    $denominator2 = "x^(2)".$d2_coeff1."x".$d2_coeff2;
    $question = "(".$q_num1.")/(".$q_denom1.")-(".$q_num2.")/(".$q_denom2.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #85 Generator               ////
////   Adding/Subtracting Rational Expressions 3       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_85( )
{
    $q_num1 = "";
    $q_num2 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(2,4);
    $b = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    $c = rand($a,9);
    $qn2_coeff1 = (-1)*$c;
    $qd1_coeff1 = (-1) * $b;
    $qd2_coeff1 = $a - $b;
    $qd2_coeff2 = (-1) * $a * $b;
    $n_coeff1 = ($a -1);
    $n_coeff2 = $c;
    $d_coeff1 = $a;
    $d_coeff2 = (-1) * $b;
    $d2_coeff1 = $a - $b;
    $d2_coeff2 = $a * $b * (-1);
    coeff_prep($qn2_coeff1,0);
    coeff_prep($qd1_coeff1,0);
    coeff_prep($qd2_coeff1);
    coeff_prep($qd2_coeff2,0);
    coeff_prep($n_coeff1);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($d_coeff2,0);
    coeff_prep($d2_coeff1);
    coeff_prep($d2_coeff2,0);
    $q_num1 = "x";
    $q_num2 = "x ".$qn2_coeff1;
    $q_denom1 = "x ".$qd1_coeff1;
    $q_denom2 = "x^2 ".$qd2_coeff1."x ".$qd2_coeff2;
    $numerator = "x^2".$n_coeff1."x".$n_coeff2;
    $numerator2 = $numerator;
    $denominator = "(x".$d_coeff1.")(x ".$d_coeff2.")";
    $denominator2 = "x^2".$d2_coeff1."x".$d2_coeff2;
    $question = "(".$q_num1.")/(".$q_denom1.")-(".$q_num2.")/(".$q_denom2.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #86 Generator               ////
////   Adding/Subtracting Rational Expressions 4       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_86()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 =  "";
    $a = rand(2,9);
    $b = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    $c = rand(2,5);
    while ($c == $a || $c == $b)
    {
        $c = rand(2,5);
    }
    $d = rand(2,9);
    while ($d == $c)
    {
        $d = rand(2,9);
    }
    $qn2_coeff1 = $d;
    $qd1_coeff1 = $a - $b;
    $qd1_coeff2 = (-1) * $a * $b;
    $qd2_coeff1 = $a + $c;
    $qd2_coeff2 = $a * $c;
    $n_coeff1 = $c - $d;
    $n_coeff2 = $d * $b;
    $d_coeff1 = $a;
    $d_coeff2 = (-1)*$b;
    $d_coeff3 = $c;
    $d2_coeff1 = $d_coeff1 + $d_coeff2 + $d_coeff3;
    $d2_coeff2 = $d_coeff1 * $d_coeff2 + $d_coeff2 * $d_coeff3 + $d_coeff1 * $d_coeff3;
    $d2_coeff3 = $d_coeff1 * $d_coeff2 * $d_coeff3;
    coeff_prep($qd1_coeff1);
    coeff_prep($qd1_coeff2,0);
    coeff_prep($qd2_coeff1);
    coeff_prep($qd2_coeff2,0);
    coeff_prep($n_coeff1);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($d_coeff2,0);
    coeff_prep($d_coeff3,0);
    coeff_prep($d2_coeff1);
    coeff_prep($d2_coeff2);
    coeff_prep($d2_coeff3,0);
    $q_num1 = "t";
    $q_num2 = (string)$qn2_coeff1;
    $q_denom1 = "t^2 ".$qd1_coeff1."t ".$qd1_coeff2;
    $q_denom2 = "t^2 ".$qd2_coeff1."t ".$qd2_coeff2;
    $question = "(".$q_num1.")/(".$q_denom1.")-(".$q_num2.")/(".$q_denom2.")";
    $numerator = "t^2".$n_coeff1."t".$n_coeff2;
    $numerator2 = $numerator;
    $denominator = "(t".$d_coeff1.")(t".$d_coeff2.")(t".$d_coeff3.")";
    $denominator2 = "t^3".$d2_coeff1."t^2".$d2_coeff2."t".$d2_coeff3;
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #87 Generator               ////
////   Adding/Subtracting Rational Expressions 5       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_87()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(2,8);
    $b = rand(2,8);
    while ($a == $b)
    {
        $b = rand(2,8);
    }
    $c = rand(4,8);
    $d = rand(2,4);
    $e = rand(2,6);
    $f = rand(2,8);
    $temp = $c - $d + $e;
    while ($temp == 0 || $temp == 1)
    {
        $e = rand(2,9);
        $temp = $c - $d + $e;
    }
    $qn1_coeff1 = $c;
    $qn2_coeff1 = $d;
    $qn3_coeff1 = $e;
    $qn3_coeff2 = (-1) * $f;
    $qd1_coeff1 = $a;
    $qd2_coeff1 = (-1) * $b;
    $qd3_coeff1 = $a - $b;
    $qd3_coeff2 = (-1) * $a * $b;
    $n_coeff1 = $c - $d + $e;
    $n_coeff2 = (-1) * ($c * $b + $d * $a + $f);
    $d_coeff1 = $a;
    $d_coeff2 = (-1) * $b;
    $d2_coeff1 = $d_coeff1 + $d_coeff2;
    $d2_coeff2 = $d_coeff1 * $d_coeff2;
    coeff_prep($qn3_coeff2,0);
    coeff_prep($qd1_coeff1,0);
    coeff_prep($qd2_coeff1,0);
    coeff_prep($qd3_coeff1);
    coeff_prep($qd3_coeff2,0);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($d_coeff2,0);
    coeff_prep($d2_coeff1);
    coeff_prep($d2_coeff2);
    $q_num1 = (string)$qn1_coeff1;
    $q_num2 = (string)$qn2_coeff1;
    $q_num3 = $qn3_coeff1."x ".$qn3_coeff2;
    $q_denom1 = "x ".$qd1_coeff1;
    $q_denom2 = "x ".$qd2_coeff1;
    $q_denom3 = "x^2 ".$qd3_coeff1."x ".$qd3_coeff2;
    $question = "(".$q_num1.")/(".$q_denom1.")-(".$q_num2.")/(".$q_denom2.")+(".$q_num3.")/(".$q_denom3.")";
    $numerator = $n_coeff1."x ".$n_coeff2;
    $numerator2 = $numerator;
    $denominator = "(x".$d_coeff1.")(x".$d_coeff2.")";
    $denominator2 = "x^2".$d2_coeff1."x".$d2_coeff2;
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #88 Generator               ////
////   Adding/Subtracting Rational Expressions 6       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_88()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,4);
    $b = rand(2,9);
    $c = rand(1,4);
    $a = 2 * $a;
    $c = 2 * $c + 1;
    $qn1_coeff1 = $a;
    $qn2_coeff1 = $c;
    $qd1_coeff1 = (-1) * $b;
    $qd2_coeff1 = $b;
    $n_coeff1 = $a;
    $n_coeff2 = (-1) * $c;
    $d_coeff1 = (-1) * $b;
    coeff_prep($qd1_coeff1,0);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    $q_num1 = $qn1_coeff1."x";
    $q_num2 = $qn2_coeff1;
    $q_denom1 = "x ".$qd1_coeff1;
    $q_denom2 = $qd2_coeff1." - x";
    $question = "(".$q_num1.")/(".$q_denom1.")+(".$q_num2.")/(".$q_denom2.")";
    $numerator = $n_coeff1."x".$n_coeff2;
    $denominator = "x".$d_coeff1;
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #89 Generator               ////
////        Compound Rational Expressions 1            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_89()
{
    $q_num1 = "1";
    $q_num2 = "1";
    $q_num3 = "1";
    $q_denom1 = "x";
    $q_denom2 = "y";
    $q_denom3 = "xy";
    $question = "(".$q_num1."/".$q_denom1."+".$q_num2."/".$q_denom2.")/(";
    $question .= $q_num3."/".$q_denom3.")";
    $numerator = "x+y";
    $denominator = "1";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #90 Generator               ////
////        Compound Rational Expressions 2            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_90()
{
    $q_num1 = "1";
    $q_num2 = "1";
    $q_num3 = "1";
    $q_num4 = "1";
    $q_denom2 = "x";
    $q_denom4 = "x";
    $question = "(".$q_num1."+".$q_num2."/".$q_denom2.")/(".$q_num3."-";
    $question .= $q_num4."/".$q_denom4.")";
    $numerator = "x+1";
    $denominator = "x-1";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #91 Generator               ////
////        Compound Rational Expressions 3            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_91()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(4,9);
    $b = rand(4,9);
    $c = rand(2,9);
    $d = rand(2,6);
    $qn1_coeff1 = 1;
    $qn2_coeff1 = $b;
    $qn3_coeff1 = $c;
    $qd1_coeff1 = $a;
    $qd3_coeff1 = $a * $d;
    $n_coeff1 = $d;
    $n_coeff2 = $a * $b;
    $d_coeff1 = $c;
    $n2_coeff1 = $d;
    $n2_coeff2 = $d * $a * $b;
    coeff_prep($qn3_coeff1,0);
    coeff_prep($n_coeff2,0);
    coeff_prep($d_coeff1,0);
    coeff_prep($n2_coeff2,0);
    $q_num1 = $qn1_coeff1;
    $q_num2 = $qn2_coeff1;
    $q_num3 = "x ".$qn3_coeff1;
    $q_denom1 = $qd1_coeff1;
    $q_denom2 = "x";
    $q_denom3 = $qd3_coeff1;
    $numerator = $n_coeff1."(x".$n_coeff2.")";
    $numerator2 = $n2_coeff1."x".$n2_coeff2;
    $denominator = "x (x".$d_coeff1.")";
    $denominator2 = "x^2".$d_coeff1."x";
    $question ="(" .$q_num1."/".$q_denom1."+".$q_num2."/".$q_denom2.")/(";
    $question .= "(".$q_num3.")/".$q_denom3.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #92 Generator               ////
////        Compound Rational Expressions 4            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_92()
{
    $q_num1 = "1";
    $q_num2 = "1";
    $q_num3 = "1";
    $q_denom1 = "";
    $q_denom2 = "y";
    $q_denom3 = "y";
    $a = rand(2,9);
    $qn3_coeff1 = $a;
    $n_coeff1 = (-1) * $a;
    $d_coeff1 = $a;
    coeff_prep($qn3_coeff1,0);
    coeff_prep($d_coeff1,0);
    $q_denom1 = "y ".$qn3_coeff1;
    $numerator = $n_coeff1;
    $denominator = "y".$d_coeff1;
    $question = "(".$q_num1."/(".$q_denom1.")-".$q_num2."/".$q_denom2.")/(";
    $question .= $q_num3."/".$q_denom3.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #93 Generator               ////
////        Compound Rational Expressions 5            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_93()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_num4 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $q_denom4 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $a = 2 * $a - 1;
    $b = 2 * $b;
    $c = 2 * $c - 1;
    $d = 2 * $d;
    while ($a == 3 && $b == 6)
    {
        $b = rand(1,4);
        $b = 2 * $b;
    }
    while ($c == 3 && $d == 6)
    {
        $d = rand(1,4);
        $d = 2 * $d;
    }
    $q_num1 = $a;
    $q_num2 = $b;
    $q_num3 = $c;
    $q_num4 = $d;
    $q_denom1 = "x";
    $q_denom2 = " ";
    $q_denom3 = "x^2";
    $q_denom4 = " ";
    if ($b == 1)
    {
        $b = "";
    }
    if ($d == 1)
    {
        $d = "";
    }
    if ($a == 1)
    {
        $numerator = "x - ".$b."x^2";
    }
    else
    {
        $numerator = $a."x - ".$b."x^2";
    }
    $numerator2 = "x(".$a."-".$b."x)";
    $denominator = $c."+".$d."x^2";
    $denominator2 = $denominator;
    $question = "(".$q_num1."/(".$q_denom1.")-".$q_num2.")/(".$q_num3."/";
    $question .= $q_denom3."+".$q_num4.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #94 Generator               ////
////        Compound Rational Expressions 6            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_94()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_num4 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $q_denom4 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $a = 2 * $a - 1;
    $b = 2 * $b;
    $c = 2 * $c - 1;
    $d = 2 * $d;
    while ($a == 3 && $b == 6)
    {
        $b = rand(1,4);
        $b = 2 * $b;
    }
    while ($c == 3 && $d == 6)
    {
        $d = rand(1,4);
        $d = 2 * $d;
    }
    $q_num1 = $a;
    $q_num2 = $b;
    $q_num3 = $c;
    $q_num4 = $d;
    $q_denom1 = "x^2";
    $q_denom2 = " ";
    $q_denom3 = "x";
    $q_denom4 = " ";
    if ($b == 1)
    {
        $b = "";
    }
    if ($d == 1)
    {
        $d = "";
    }
    $numerator = $a." - ".$b."x^2";
    $numerator2 = $numerator;
    if ($c == 1)
    {
        $denominator = "x+".$d."x^2";
    }
    else
    {
        $denominator = $c."x+".$d."x^2";
    }
    $denominator2 = "x(".$c."+".$d."x)";
    $question = "(".$q_num1."/(".$q_denom1.")-".$q_num2.")/(".$q_num3."/";
    $question .= $q_denom3."+".$q_num4.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #95 Generator               ////
////        Compound Rational Expressions 7            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_95()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_num4 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $q_denom4 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $a = 2 * $a - 1;
    $b = 2 * $b;
    $c = 2 * $c - 1;
    $d = 2 * $d;
    while ($a == 3 && $b == 6)
    {
        $b = rand(1,4);
        $b = 2 * $b;
    }
    while ($c == 3 && $d == 6)
    {
        $d = rand(1,4);
        $d = 2 * $d;
    }
    $q_num1 = $a;
    $q_num2 = $b;
    $q_num3 = $c;
    $q_num4 = $d;
    $q_denom1 = "x^3";
    $q_denom2 = " ";
    $q_denom3 = "x^2";
    $q_denom4 = " ";
    if ($b == 1)
    {
        $b = "";
    }
    $numerator = $a."+".$b."x^3";
    $numerator2 = $numerator;
    if ($d == 1)
    {
        $d = "";
    }
    if ($c == 1)
    {
        $denominator = "x+".$d."x^3";
    }
    else
    {
        $denominator = $c."x+".$d."x^3";
    }
    $denominator2 = "x(".$c."+".$d."x^2)";
    $question = "(".$q_num1."/".$q_denom1."+".$q_num2.")/(".$q_num3."/";
    $question .= $q_denom3."+".$q_num4.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #96 Generator               ////
////        Compound Rational Expressions 8            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_96()
{
    $q_num1 = "";
    $q_num2 = "";
    $q_num3 = "";
    $q_num4 = "";
    $q_denom1 = "";
    $q_denom2 = "";
    $q_denom3 = "";
    $q_denom4 = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $denominator2 = "";
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $a = 2 * $a - 1;
    $b = 2 * $b;
    $c = 2 * $c - 1;
    $d = 2 * $d;
    while ($a == 3 && $b == 6)
    {
        $b = rand(1,4);
        $b = 2 * $b;
    }
    while ($c == 3 && $d == 6)
    {
        $d = rand(1,4);
        $d = 2 * $d;
    }
    if ($d == 4 && $c == 1)
    {
        $d = 2;
    }
    $q_num1 = $b;
    $q_num2 = $a;
    $q_num3 = $d;
    $q_num4 = $c;
    $q_denom1 = " ";
    $q_denom2 = "x";
    $q_denom3 = " ";
    $q_denom4 = "x^2";
    if ($b == 1)
    {
        $b = "";
    }
    if ($a == 1)
    {
        $numerator = $b."x^2-x";
    }
    else
    {
        $numerator = $b."x^2-".$a."x";
    }
    $numerator2 = "x(".$b."x-".$a.")";
    if ($d == 1)
    {
        $d = "";
    }
    $denominator = $d."x^2 -".$c;
    $denominator2 = $denominator;
    $question = "(".$q_num1."-".$q_num2."/".$q_denom2.")/(".$q_num3."-";
    $question .= $q_num4."/".$q_denom4.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $numerator2="(".$numerator2.")/(".$denominator2.")";
    $answer = array($question,$numerator,1,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #97 Generator               ////
////  Rational Expressions and Negative Exponents 1    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_97()
{
    $q_num = "x^(-1) + y^(-1)";
    $q_denom = "x^(-1) - y^(-1)";
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator = "y+x";
    $denominator = "y-x";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #98 Generator               ////
////  Rational Expressions and Negative Exponents 2    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_98()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,5);
    $q_pow = (-1) * $a;
    $a_pow = $a;
    $q_num = "x^(".$q_pow.")";
    $q_denom = "x^(".$q_pow.") + y^(".$q_pow.")";
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator = "y^".$a_pow;
    $denominator = "x^".$a_pow." + y^".$a_pow;
    $numerator=$numerator."/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #99 Generator               ////
////  Rational Expressions and Negative Exponents 3    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_99()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,3);
    $b = $a + 1;
    $c = $b + 1;
    $qxn_pow = (-1) * $a;
    $qxd_pow = (-1) * $b;
    $qy_pow = (-1) * $c;
    $ay_pow = $c;
    $ax_pow = $b;
    $q_num = "x^(".$qxn_pow.")";
    $q_denom = "x^(".$qxd_pow.") + y^(".$qy_pow.")";
    $question = "(".$q_num.")/(".$q_denom.")";
    $numerator = "x*y^".$ay_pow;
    $denominator = "x^".$ax_pow." + y^".$ay_pow;
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #100 Generator              ////
////        Rational Expressions and GCF 1             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_100()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(2,9);
    while ($a == $b)
    {
        $b = rand(2,9);
    }
    rand_switch_sign($b,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $a_coeff1 = $a + $b;
    if ($randy == 1)
    {
        $pow1 = 2;
        $pow2 = 3;
    }
    else
    {
        $pow1 = 3;
        $pow2 = 4;
    }
    coeff_prep($q_coeff2,0);
    coeff_prep($a_coeff1,0);
    $q_num = $q_coeff1."(x ".$q_coeff2.")^".$pow1." + (x ".$q_coeff2.")^".$pow2;
    $q_denom = "(x ".$q_coeff2.")^".$pow1;
    $numerator = "x ".$a_coeff1;
    $question = "(".$q_num.")/(".$q_denom.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #101 Generator              ////
////        Rational Expressions and GCF 2             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_101()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,4);
    $b = rand(1,9);
    $c = rand(1,4);
    $a = 2 * $a;
    $c = 2 * $c - 1;
    rand_switch_sign($b,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;
    $a_coeff1 = $a;
    $a_coeff2 = $a * $b + $c;
    coeff_prep($q_coeff2,0);
    coeff_prep($q_coeff3);
    coeff_prep($a_coeff2,0);
    $q_num = $q_coeff1."(x ".$q_coeff2.")^(2)".$q_coeff3."(x ".$q_coeff2.")";
    $q_denom = "(x ".$q_coeff2.")";
    $numerator = $a_coeff1."x ".$a_coeff2;
    $question = "(".$q_num.")/".$q_denom;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #102 Generator              ////
////        Rational Expressions and GCF 3             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_102()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,4);
    $b = rand(1,9);
    $c = rand(1,4);
    $a = 2 * $a;
    $c = 2 * $c - 1;
    rand_switch_sign($b,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;
    $a_coeff1 = $a;
    $a_coeff2 = $a * $b + $c;
    coeff_prep($q_coeff2,0);
    coeff_prep($q_coeff3);
    coeff_prep($a_coeff2,0);
    $q_num = $q_coeff1."(x ".$q_coeff2.")^(4)".$q_coeff3."(x ".$q_coeff2.")^3";
    $q_denom = "(x ".$q_coeff2.")^3";
    $numerator = $a_coeff1."x ".$a_coeff2;
    $question ="(". $q_num.")/".$q_denom;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #103 Generator              ////
////           Simplifying Roots 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_103()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,6);
    $b = rand(2,5);
    $c = rand(1,4);
    $q_coeff1 = pow($a,2);
    $qx_pow = 2 * $b + 1;
    $qy_pow = 2 * $c;
    $a_coeff1 = $a;
    $ax_pow = $b;
    if ($c != 1)
    {
        $ay_pow = "^".$c;
    }
    else
    {
        $ay_pow = "*";
    }
    $question = "sqrt( ".$q_coeff1."x^".$qx_pow."y^".$qy_pow." )";
    $numerator = $a_coeff1."x^".$ax_pow."y".$ay_pow."sqrt( x )";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #104 Generator              ////
////           Simplifying Roots 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_104()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,3);
    $c = rand(2,5);
    $d = rand(1,5);
    $q_coeff1 = pow($a,2) * $b;
    $qx_pow = 2 * $c + 1;
    $qy_pow = 2 * $d;
    $a_coeff1 = $a;
    $a_coeff2 = $b;
    $ax_pow = $c;
    if ($d != 1)
    {
        $ay_pow = "^".$d;
    }
    else
    {
        $ay_pow = "*";
    }
    $question = "sqrt( ".$q_coeff1."x^".$qx_pow."y^".$qy_pow." )";
    $numerator = $a_coeff1."x^".$ax_pow."y".$ay_pow."sqrt( ".$a_coeff2."x )";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #105 Generator              ////
////           Simplifying Roots 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_105()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $q_coeff1 = (-1) * pow($a,3);
    $a_coeff1 = (-1) * $a;
    $question = "root( ".$q_coeff1." ,3)";
    $numerator = $a_coeff1;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #106 Generator              ////
////           Simplifying Roots 4                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_106()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $randy = rand(1,2);
    $a = rand(2,5);
    $b = rand(2,4);
    $c = rand(1,2);
    $q_coeff1 = pow($a,3);
    $qx_pow = 3 * $b;
    if ($randy == 1)
    {
        $qx_pow = $qx_pow + $c;
    }
    $a_coeff1 = $a;
    $ax_pow1 = $b;
    $ax_pow2 = 0;
    if ($randy == 1)
    {
        $ax_pow2 = $c;
    }
    $question = "root(".$q_coeff1."x^".$qx_pow.",3)";
    $numerator = $a_coeff1."x^".$ax_pow1;
    if ($randy == 1)
    {
        if ($c == 1)
        {
            $numerator = $numerator."root(x,3)";
        }
        else
        {
            $numerator = $numerator."root(x^2,3)";
        }
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #107 Generator              ////
////           Simplifying Roots 5                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_107()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,4);
    $c = rand(1,3);
    $q_coeff1 = pow($a,4);
    $qx_pow = 4 * $b + $c;
    $a_coeff1 = $a;
    $ax_pow1 = $b;
    $ax_pow2 = $c;
    $question = "root( ".$q_coeff1."x^".$qx_pow.",4 )";
    $numerator = $a_coeff1."x^".$ax_pow1;
    if ($ax_pow2 == 1)
    {
        $numerator = $numerator."root(x,4)";
    }
    else
    {
        $numerator = $numerator."root(x^".$ax_pow2.",4)";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #108 Generator              ////
////             Roots and Fractions 1                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_108()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,3);
    $b = rand(2,4);
    if ($b == 4)
    {
        $b++;
    }
    $c = rand(1,4);
    $d = rand(2,11);
    $e = rand(2,4);
    while ($d == 4 || $d == 9 || $d == 8)
    {
        $d = rand(2,11);
    }
    while ($b == $c)
    {
        $c = rand(1,4);
    }
    $b = 2 * $b + 1;
    $c = 2 * $c + 1;
    $q_coeff1 = $a * $e;
    $q_coeff2 = $e * $b;
    $q_coeff3 = $d;
    $q_coeff4 = $e * $c;
    $a_coeff1 = $a;
    $a_coeff2 = $b;
    $a_coeff3 = $d;
    $a_coeff4 = $c;
    coeff_prep($q_coeff2);
    coeff_prep($a_coeff2);
    $q_num = $q_coeff1." ".$q_coeff2."sqrt( ".$q_coeff3." )";
    $q_denom = $q_coeff4;
    $numerator = $a_coeff1." ".$a_coeff2."sqrt( ".$a_coeff3." )";
    $denominator = $a_coeff4;
    $question = "(".$q_num.")/".$q_denom;
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #109 Generator              ////
////             Roots and Fractions 2                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_109()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(2,10);
    $d = rand(2,11);
    while ($d == 4 || $d == 9 || $d == 8 )
    {
        $d = rand(2,11);
    }
    $a = 2 * $a - 1;
    $b = 2 * $b;
    $q_coeff1 = $a * $c;
    $q_coeff2 = $b * $c;
    $q_coeff3 = $d;
    $q_coeff4 = $c;
    $a_coeff1 = $a;
    $a_coeff2 = $b;
    $a_coeff3 = $d;
    coeff_prep($q_coeff2);
    coeff_prep($a_coeff2);
    $q_num = $q_coeff1." ".$q_coeff2."sqrt( ".$q_coeff3." )";
    $q_denom = $q_coeff4;
    $numerator = $a_coeff1." ".$a_coeff2."sqrt( ".$a_coeff3." )";
    $denominator = "1";
    $question ="(". $q_num.")/".$q_denom;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #110 Generator              ////
////          Multiplication of Roots 1                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_110( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,7);
    $b = rand(2,5);
    $c = rand(2,7);
    $d = rand(1,3);
    $d = 2 * $d + 1;
    rand_switch_sign($a,2);
    rand_switch_sign($c,2);
    $q_coeff1 = $a;
    $q_coeff2 = 2 * pow($b,2);
    $q_coeff3 = $c;
    $q_coeff4 = $d;
    $a_coeff1 = $a * $c * $b;
    $a_coeff2 = 2 * $d;
    $question = "( ".$q_coeff1."sqrt(".$q_coeff2.") )*( ".$q_coeff3."sqrt(".$q_coeff4.") )";
    $numerator = $a_coeff1."sqrt(".$a_coeff2.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #111 Generator              ////
////          Multiplication of Roots 2                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_111( )
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,7);
    $b = rand(1,4);
    $c = rand(2,5);
    $d = rand(2,7);
    $e = rand(1,4);
    while ($b == $e)
    {
        $e = rand(1,4);
    }
    $b = r_prime($b);
    $e = r_prime($e);
    rand_switch_sign($a,2);
    rand_switch_sign($d,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b * $c;
    $q_coeff3 = $d;
    $q_coeff4 = $e * $c;
    $a_coeff1 = $a * $d * $c;
    $a_coeff2 = $b * $e;
    $question = "(".$q_coeff1."sqrt( ".$q_coeff2.") )*( ".$q_coeff3."sqrt(".$q_coeff4.") )";
    $numerator = $a_coeff1."sqrt(".$a_coeff2.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #112 Generator              ////
////          Multiplication of Roots 3                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_112()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,6);
    $b = rand(1,7);
    $c = rand(1,7);
    while ($b == $c)
    {
        $c = rand(1,7);
    }
    $a = r_prime($a);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $a;
    $q_coeff4 = $c;
    $a_coeff1 = $a + $b * $c;
    $a_coeff2 = $b + $c;
    $a_coeff3 = $a;
    coeff_prep($q_coeff2,0);
    coeff_prep($q_coeff4,0);
    coeff_prep($a_coeff2);
    $question = "( sqrt( ".$q_coeff1." ) ".$q_coeff2.")*( sqrt( ".$q_coeff3." ) ".$q_coeff4.")";
    $numerator = $a_coeff1.$a_coeff2."sqrt( ".$a_coeff3." )";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #113 Generator              ////
////          Multiplication of Roots 3                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_113()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(1,5);
    $c = rand(2,5);
    $b = r_prime($b);
    rand_switch_sign($c,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;
    $a_coeff1 = pow($a,2) * $b + pow($c,2);
    $a_coeff2 = 2 * $a * $c;
    $a_coeff3 = $b;
    coeff_prep($q_coeff3,0);
    coeff_prep($a_coeff2);
    $question = "( ".$q_coeff1."sqrt( ".$q_coeff2." ) ".$q_coeff3.")^2";
    $numerator = $a_coeff1." ".$a_coeff2."sqrt( ".$a_coeff3." )";
    $answer = array($question,$numerator,$denominator,"1");
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #114 Generator              ////
////         Rationalize the Denominator 1             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_114()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,3);
    $b = rand(1,3);
    $c = rand(2,5);
    $a = 2 * $a + 1;
    if ($b == 3)
    {
        $b = 8;
    }
    else
    {
        $b = 2 * $b;
    }
    $c = r_prime($c);
    while ($a == $c)
    {
        $a = 2 * rand(1,4) + 1;
    }
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;
    $a_coeff1 = $a;
    $a_coeff2 = $c;
    $a_coeff3 = $b * $c;
    $q_num = $q_coeff1;
    $q_denom = $q_coeff2."sqrt( ".$q_coeff3." )";
    $numerator = $a_coeff1."sqrt( ".$a_coeff2." )";
    $denominator = $a_coeff3;
    $question = $q_num."/(".$q_denom.")";
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #115 Generator              ////
////         Rationalize the Denominator 2             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_115()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,5);
    $b = rand(2,7);
    $c = rand(2,5);
    while ($a == $c)
    {
        $c = rand(2,5);
    }
    $a = 2 * r_prime($a);
    $c = r_prime($c);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;
    $a_coeff1 = $a * $c;
    $a_coeff2 = $b * $c;
    $q_num = "sqrt( ".$q_coeff1." )";
    $q_denom = $q_coeff2."sqrt( ".$q_coeff3." )";
    $numerator = "sqrt( ".$a_coeff1." )";
    $denominator = $a_coeff2;
    $numerator="(".$numerator.")/".$denominator;
    $question = $q_num."/(".$q_denom.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #116 Generator              ////
////         Rationalize the Denominator 3             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_116()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $a = rand(2,9);
    $b = rand(2,5);
    $c = 0;
    if ($b == 2)
    {
        $c = 1;
    }
    else if ($b == 5)
    {
        $c = rand(1,3);
    }
    else
    {
        $c = rand(1,2);
    }
    $b = r_prime($b);
    rand_switch_sign($c,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $q_coeff3 = $c;

    $denom = $b - pow($c,2);
    reduce($a,$denom);
    if ($a == 1)
    {
        $a = "";
    }

    $a_coeff1 = $a;
    $a_coeff2 = $b;
    $a_coeff3 = (-1) * $c;
    $a_coeff4 = $denom;

    $a2_coeff1 = $a;
    $a2_coeff2 = $b;
    $a2_coeff3 = $a * (-1) * $c;

    coeff_prep($q_coeff3,0);
    coeff_prep($a_coeff3,0);
    coeff_prep($a2_coeff3,0);
    $q_num = $q_coeff1;
    $q_denom = "sqrt( ".$q_coeff2." ) ".$q_coeff3;
    $numerator = $a_coeff1." ( sqrt( ".$a_coeff2." ) ".$a_coeff3." )";
    $numerator2 = $a2_coeff1."sqrt( ".$a2_coeff2." ) ".$a2_coeff3;
    $denominator = $a_coeff4;
    $question = $q_num."/(".$q_denom.")";
    if($denominator!=1)
     $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,$numerator2,$denominator,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #117 Generator              ////
////         Rationalize the Denominator 4             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_117()
{
    $q_num = "";
    $q_denom = "";
    $question = "";
    $numerator = "";
    $numerator2 = "";
    $denominator = "";
    $a = rand(2,9);
    $b = rand(2,9);
    rand_switch_sign($b,2);
    $q_coeff1 = $a;
    $q_coeff2 = $b;
    $a_coeff1 = $a;
    $a_coeff2 = (-1) * $b;
    $a_coeff3 = (-1) * pow($b,2);
    $a2_coeff1 = $a;
    $a2_coeff2 = (-1) * $b * $a;
    coeff_prep($q_coeff2,0);
    coeff_prep($a_coeff2,0);
    coeff_prep($a_coeff3,0);
    $q_num = $q_coeff1;
    $q_denom = "sqrt( x ) ".$q_coeff2;
    $numerator = $a_coeff1."( sqrt( x ) ".$a_coeff2." )";
    $numerator2 = $a2_coeff1."sqrt( x ) ".$a2_coeff2;
    $denominator = "x".$a_coeff3;
    $question = $q_num."/(".$q_denom.")";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,$numerator2,$denominator,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #118 Generator              ////
////          Linear equations 1                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_118()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,12);
    $b = rand(1,17);
    $c = rand(1,17);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $numerator = $c - $b;
    if ($numerator == 0)
    {
        $denominator = "1";
    }
    else
    {
        $denominator = $a;
    }
    reduce($numerator,$denominator);
    coeff_prep($b,0);
	$c1=$c;
	if($c<0)
	$c1='~'.abs($c);
    $question = $a."x ".$b." = ".$c1;
    if($denominator!="1")
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #119 Generator              ////
////          Linear equations 2                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_119()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,12);
    $b = rand(1,17);
    $c = rand(2,12);
    $d = rand(1,17);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    while ($a == $c)
    {
        $a = rand(2,12);
        rand_switch_sign($a,3);
    }
    $numerator = $d - $b;
    $denominator = $a - $c;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    coeff_prep($b,0);
    coeff_prep($d,0);
	$c1=$c;
	if($c<0)
	$c1='~'.abs($c);
    $question = $a."x ".$b." = ".$c1."*x ".$d;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #120 Generator              ////
////          Linear equations 3                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_120()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,5);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    $e = rand(2,5);
    $f = rand(1,9);
    $g = rand(1,9);
    $h = rand(1,9);
    rand_switch_sign($a,4);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,4);
    rand_switch_sign($g,3);
    rand_switch_sign($h,3);
    while ( ($a * $c) - ($e * $g) == 0)
    {
        $a = rand(2,9);
        rand_switch_sign($a,4);
    }
    $numerator = ($e * $f) - ($a * $b) + $h - $d;
    $denominator = ($a * $c) - ($e * $g);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,90);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    coeff_prep($c);
    coeff_prep($d,0);
    coeff_prep($g);
    coeff_prep($h,0);
	$e1=$e;
	if($e<0)
	$e1='~'.abs($e);
  $question = $a."( ".$b.$c."x )".$d." = ".$e1."( ".$f.$g."x )".$h;
  if($denominator!=1)
      $numerator=$numerator."/".$denominator;
  $answer = array($question,$numerator,1,0,0,0);
  return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #121 Generator              ////
////          Linear equations 4                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_121()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(2,5);
    $b = rand(1,9);
    $c = rand(2,5);
    $d = rand(2,7);
    $e = rand(1,9);
    $f = rand(30,100);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($e,3);
    $numerator = $f - ($a * $b) - ($a * $c * $e);
    $denominator = 1 + ($a * $c * $d);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    coeff_prep($a);
    coeff_prep($c);
    coeff_prep($e,0);
    $question = "x".$a."*[ ".$b.$c."( ".$d."x ".$e." )] = ".$f;
    if($denominator!="1")
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #122 Generator              ////
////     Linear equations and Fractions 1              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_122()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $b = rand(2,5);
    $a = rand(1,$b-1);
    $f = rand(2,5);
    $e = rand(1,$f-1);
    $c = 0;
    $d = 0;
    $g = 0;
    $h = 0;
    $signLHS = 1;
    $signRHS = 1;
    $d = 1;
    $h = 1;
    $c = rand(1,7);
    $g = rand(1,7);
    while ( ($a * $f) - ($e * $b) == 0)
    {
        $f++;
    }
    reduce($a,$b,12);
    reduce($e,$f,12);
    reduce($c,$d,12);
    reduce($g,$h,12);
    rand_switch_sign($signLHS,3);
    rand_switch_sign($signRHS,3);
    $numerator = ($b * $f) * ( ($signRHS * $g * $d) - ($signLHS * $c * $h) );
    $denominator = ($d * $h) * ( ($a * $f) - ($e * $b) );
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    if ($signLHS < 0)
    {
        $signLHS = "-";
    }
    else
    {
        $signLHS = "+";
    }
    if ($signRHS < 0)
    {
        $signRHS = "-";
    }
    else
    {
        $signRHS = "+";
    }
    $question .= $a."/".$b."*x".$signLHS.$c."=";
    $question .= $e."/".$f."x".$signRHS.$g;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #123 Generator              ////
////     Linear equations and Fractions 2              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_123()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $b = rand(2,5);
    $a = rand(1,$b-1);
    $f = rand(2,5);
    $e = rand(1,$f-1);
    $c = 0;
    $d = 0;
    $g = 0;
    $h = 0;
    $signLHS = 1;
    $signRHS = 1;
    $d = 1;
    $h = rand(2,5);
    $c = rand(1,7);
    $g = rand(1,$h-1);
    while ( ($a * $f) - ($e * $b) == 0)
    {
        $f++;
    }
    reduce($a,$b,12);
    reduce($e,$f,12);
    reduce($c,$d,12);
    reduce($g,$h,12);
    rand_switch_sign($signLHS,3);
    rand_switch_sign($signRHS,3);
    $numerator = ($b * $f) * ( ($signRHS * $g * $d) - ($signLHS * $c * $h) );
    $denominator = ($d * $h) * ( ($a * $f) - ($e * $b) );
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    if ($signLHS < 0)
    {
        $signLHS = "-";
    }
    else
    {
        $signLHS = "+";
    }
    if ($signRHS < 0)
    {
        $signRHS = "-";
    }
    else
    {
        $signRHS = "+";
    }
    $question .= $a."/".$b."*x".$signLHS.$c."=";
    $question .= $e."/".$f."*x".$signRHS.$g."/".$h;
    if($denominator!="1")
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #124 Generator              ////
////     Linear equations and Fractions 3              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_124()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $b = rand(2,5);
    $a = rand(1,$b-1);
    $f = rand(2,5);
    $e = rand(1,$f-1);
    $c = 0;
    $d = 0;
    $g = 0;
    $signLHS = 1;
    $signRHS = 1;
    $d = rand(2,5);
    $h = 1;
    $c = rand(1,$d-1);
    $g = rand(1,7);
    while ( ($a * $f) - ($e * $b) == 0)
    {
        $f++;
    }
    reduce($a,$b,12);
    reduce($e,$f,12);
    reduce($c,$d,12);
    reduce($g,$h,12);
    rand_switch_sign($signLHS,3);
    rand_switch_sign($signRHS,3);
    $numerator = ($b * $f) * ( ($signRHS * $g * $d) - ($signLHS * $c * $h) );
    $denominator = ($d * $h) * ( ($a * $f) - ($e * $b) );
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    if ($signLHS < 0)
    {
        $signLHS = "-";
    }
    else
    {
        $signLHS = "+";
    }
    if ($signRHS < 0)
    {
        $signRHS = "-";
    }
    else
    {
        $signRHS = "+";
    }
    $question .= $a."/".$b."*x".$signLHS.$c."/".$d."=";
    $question .= $e."/".$f."*x".$signRHS.$g;
    if($denominator!="1")
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #125 Generator              ////
////     Linear equations and Fractions 4              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_125()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $b = rand(2,5);
    $a = rand(1,$b-1);
    $f = rand(2,5);
    $e = rand(1,$f-1);
    $c = 0;
    $d = 0;
    $g = 0;
    $h = 0;
    $signLHS = 1;
    $signRHS = 1;
    $d = rand(2,5);
    $h = rand(2,5);
    $c = rand(1,$d-1);
    $g = rand(1,$h-1);
    while ( ($a * $f) - ($e * $b) == 0)
    {
        $f++;
    }
    reduce($a,$b,12);
    reduce($e,$f,12);
    reduce($c,$d,12);
    reduce($g,$h,12);
    rand_switch_sign($signLHS,3);
    rand_switch_sign($signRHS,3);
    $numerator = ($b * $f) * ( ($signRHS * $g * $d) - ($signLHS * $c * $h) );
    $denominator = ($d * $h) * ( ($a * $f) - ($e * $b) );
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    if ($signLHS < 0)
    {
        $signLHS = "-";
    }
    else
    {
        $signLHS = "+";
    }
    if ($signRHS < 0)
    {
        $signRHS = "-";
    }
    else
    {
        $signRHS = "+";
    }
    $question .= $a."/".$b."*x".$signLHS.$c."/".$d."=";
    $question .= $e."/".$f."*x".$signRHS.$g."/".$h;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #126 Generator              ////
////     Linear Equations and fractions 5              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_126()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $b = rand(2,7);
    $a = rand(1,$b-1);
    $d = rand(2,7);
    $c = rand(1,$c-1);
    $e = rand(1,5);
    $f = rand(1,7);
    $g = rand(2,7);
    while ( (($a * $d * $g) + ($c * $b * $g) - ($b * $d)) == 0)
    {
        $g++;
    }
    reduce($a,$b,12);
    reduce($c,$d,12);
    rand_switch_sign($e,3);
    $numerator = ($b * $d * $f) - ($c * $b * $g * $e);
    $denominator = ($a * $d * $g) + ($c * $b * $g) - ($b * $d);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
       $numerator = $numerator * (-1);
       $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    coeff_prep($e,0);
    coeff_prep($f,0);
    $question = $a."/".$b."*x+".$c."/".$d."*(x".$e.")=(x ".$f.")/".$g;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #127 Generator              ////
////          Quasi-Linear Equations 1                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_127()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,9);
    $b = rand(1,12);
    $c = rand(1,9);
    $d = rand(1,12);
    rand_switch_sign($b,3);
    rand_switch_sign($d,3);
    while ( ($d - $b) == 0)
    {
        $d++;
        if ($d == 0)
        {
            $d++;
        }
    }
    $numerator = $a - $c;
    $denominator = $d - $b;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    if ($b < 0)
    {
        $LHS = "-";
        $b = $b * (-1);
    }
    else
    {
        $LHS = "+";
    }
    if ($d < 0)
    {
        $RHS = "-";
        $d = $d * (-1);
    }
    else
    {
        $RHS = "+";
    }
    $question .=$a."/x".$LHS.$b."=".$c."/x".$RHS.$d;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #128 Generator              ////
////          Quasi-Linear Equations 2                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_128()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,9);
    $c = rand(2,9);
    $b = rand(1,$c-1);
    $d = rand(1,12);
    reduce($b,$c,12);
    rand_switch_sign($d,3);
    $numerator = $a * $c - $b;
    $denominator = $d * $c;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    if ($d < 0)
    {
        $RHS = "-";
        $d = $d * (-1);
    }
    else
    {
        $RHS = "+";
    }
    $question = $a."/x"."=".$b."/(".$c."x)".$RHS.$d;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #129 Generator              ////
////           Quasi Linear Equations 3                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_129()
{
		do{
	    $question = "";
	    $numerator = "";
	    $denominator = "";
	    $a = rand(1,9);
	    $b = rand(1,9);
	    $c = rand(1,9);
	    $d = rand(1,9);
	    while ( ($a - $c) == 0 )
	    {
	        $a++;
	    }
	    rand_switch_sign($b,3);
	    rand_switch_sign($d,3);
	    $numerator = ($c * $b) - ($a * $d);
	    $denominator = $a - $c;
	    if ($numerator < 0 && $denominator < 0)
	    {
	        $numerator = $numerator * (-1);
	        $denominator = $denominator * (-1);
	    }
	    else if ($numerator > 0 && $denominator < 0)
	    {
	        $numerator = $numerator * (-1);
	        $denominator = $denominator * (-1);
	    }
	    reduce($numerator,$denominator,175);
	    if ($numerator == 0)
	    {
	        $numerator = "no solution";
	        $denominator = 1;
	    }
	    coeff_prep($b,0);
	    coeff_prep($d,0);
	  }while($b==$d);
    $question = $a."/"."(x".$b.")=".$c."/(x".$d.")";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #130 Generator              ////
////           Quasi Linear Equations 4                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_130()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,6);
    $b = rand(1,4);
    $d = rand(2,6);
    $c = rand(1,$d-1);
    $f = rand(2,6);
    $e = rand(1,$f-1);
    reduce($c,$d,12);
    reduce($e,$f,12);
    rand_switch_sign($c,3);
    rand_switch_sign($b,3);
    $numerator = ($e * $d) - ($a * $f * $d) - ($c * $f * $b);
    $denominator = $c * $f;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "0";
        $denominator = 1;
    }
    if ($denominator == 1)
    {
        if ($numerator == ((-1) * $b) )
        {
            $numerator = "no solution";
        }
    }
    if ($c < 0)
    {
        $LHS = "-";
        $c = $c * (-1);
    }
    else
    {
        $LHS = "+";
    }
    $coeff1 = $f * $b;
    $split = '@';
    coeff_prep($b,0);
    coeff_prep($coeff1,0);
    $question= $a."/(x".$b.")".$LHS.$c."/".$d."=".$e."/(".$f."x".$coeff1.")";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #131 Generator              ////
////           Quasi Linear Equations 5                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_131()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,5);
    $b = rand(1,5);
    $d = rand(2,6);
    $c = rand(1,$d-1);
    $e = rand(1,5);
    reduce($c,$d,12);
    rand_switch_sign($b,3);
    rand_switch_sign($e,3);
    while ( (($a * $d * $d ) - ($e * $c)) == 0)
    {
        $a++;
    }
    $numerator = ($b * $e * $c) - ( $a * $e * $d);
    $denominator = ($d * $d * $a) - ($e * $c);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $denominator = 1;
    }
    if ($numerator == ((-1) * $b) && $denominator == 1)
    {
        $numerator = "no solution";
        $denominator = "1";
    }
    if ($numerator == ((-1) * $e) && $denominator == $d)
    {
        $numertor = "no solution";
        $denominator = "1";
    }
    coeff_prep($b,0);
    coeff_prep($e,0);
    if ($c == 1)
    {
        $coeff1 = "";
    }
    else
    {
        $coeff1 = $c;
    }
    $question = $a."/(x".$b.")+".$coeff1."x"."/(".$d."x".$e.")=".$c."/".$d;
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #132 Generator              ////
////           Quasi Linear Equations 6                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_132()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,7);
    $b = rand(1,5);
    $c = rand(1,7);
    $d = rand(1,7);
    $numerator = $d + ($a * $b) - ($c * $b);
    $denominator = $a + $c;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "0";
        $denominator = 1;
    }
    if ($denominator == 1)
    {
        if ($numerator == $b || $numerator == ((-1) * $b))
        {
            $numerator = "no solution";
        }
    }
    $coeff1 = $b;
    $coeff2 = (-1) * $b;
    $coeff3 = (-1) * $b * $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    $question .= $a."/(x".$coeff1.")+".$c."/(x".$coeff2.")=".$d."/(x^2 ".$coeff3.")";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #133 Generator              ////
////           Quasi-Linear Equations 7                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_133()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,7);
    $b = rand(2,5);
    $c = rand(1,7);
    $d = rand(1,7);
    $e = rand(1,7);
    rand_switch_sign($c,3);
    rand_switch_sign($e,3);
    while ( ($c - ($a * $d) - ($b * $e) ) == 0)
    {
        $c++;
        if ($c == 0)
        {
            $c++;
        }
    }
    $numerator = $d * $e;
    $denominator = $c - ($a * $d) - ($b * $e);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    if ($denominator == $b && $numerator == ( (-1) * $d) )
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    $coeff1 = $a * $b;
    coeff_prep($c,0);
    coeff_prep($d,0);
    if ($e < 0)
    {
        $RHS = "-";
        $e = $e * (-1);
    }
    else
    {
        $RHS = "+";
    }
    $question = "(".$coeff1."x".$c.")/(".$b."x".$d.")=".$a.$RHS.$e."/x";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #134 Generator              ////
////          Quasi-Linear Equations 8                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_134()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $c = rand(2,6);
    $e = rand(2,6);
    $f = rand(2,6);
    $a = rand(1,2);
    if ($a == 2)
    {
        $a = rand(1,5);
    }
    $b = rand(1,2);
    if ($b == 2)
    {
        $b = rand(1,$c-1);
    }
    $d = rand(1,2);
    if ($d == 2)
    {
        $d = rand(2,$e-1);
    }
    $f = rand(1,2);
    if ($f == 2)
    {
        $f = rand(2,5);
    }
    $g = rand(1,6);
    reduce($b,$c,12);
    reduce($d,$e,12);
    rand_switch_sign($b,3);
    rand_switch_sign($d,3);
    rand_switch_sign($g,3);
    while ( (($a * $c * $e ) + ($b * $e) + ($d * $c) - ($f * $c * $e) ) == 0)
    {
        $a++;
    }
    $numerator = (-1) * ($g) * (($a * $c * $e) + ($d * $c) + ($b * $e));
    $denominator = ($a * $c * $e ) + ($b * $e) + ($d * $c) - ($f * $c * $e);
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($numerator > 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    reduce($numerator,$denominator,175);
    if ($numerator == 0)
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    if ($denominator == 1 && $numerator == ( (-1) * $g) )
    {
        $numerator = "no solution";
        $denominator = 1;
    }
    if ($b < 0)
    {
        $LHS1 = "-";
        $b = (-1) * $b;
    }
    else
    {
        $LHS1 = "+";
    }
    if ($d < 0)
    {
        $LHS2 = "-";
        $d = (-1) * $d;
    }
    else
    {
        $LHS2 = "+";
    }
    coeff_prep($g,0);
    $question = $a."/x".$LHS1.$b."/(".$c."x)".$LHS2.$d."/(".$e."x)=".$f."/(x".$g.")";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #135 Generator              ////
////           Linear Inequalities 1                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_135()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,9);
    $b = rand(0,9);
    $c = rand(1,9);
    $num_inequality = rand(1,4);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $coeff1 = $b;
    if ($b == 0)
    {
        $coeff1 = "";
    }
    else
    {
        coeff_prep($coeff1,0);
    }
    $inf = " INF ";
	$c1=$c;
	if($c<0)
	{
       $c1="~".abs($c);
    }
	$question = $a."*x".$coeff1.gen_inequality($num_inequality).$c1;
    if ($a < 0)
    {
        $num_inequality = $num_inequality + 2;
        if ($num_inequality > 4)
        {
            $num_inequality = $num_inequality - 4;
        }
    }
    $num_bound = $c - $b;
    $denom_bound = $a;
    if ($num_bound < 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound > 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound == 0)
    {
        $denom_bound = 1;
    }
    reduce($num_bound,$denom_bound,12);
    $num_bound = trim($num_bound);
    $denom_bound = trim($denom_bound);
    if ($denom_bound != 1)
    {
        $bound = "$num_bound / $denom_bound";
    }
    else
    {
        $bound = $num_bound;
    }
    $bound = trim($bound);
    if ($num_inequality == 1)
    {
        $numerator = "(-$inf , $bound )";
    }
    else if ($num_inequality == 2)
    {
        $numerator = "(-$inf , $bound ]";
    }
    else if ($num_inequality == 3)
    {
        $numerator = "( $bound , $inf )";
    }
    else // ($num_inequality == 4)
    {
        $numerator = "[ $bound , $inf )";
    }
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #136 Generator              ////
////           Linear Inequalities 2                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_136()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $b = rand(1,5);
    $d = rand(1,5);
    $f = rand(1,5);
    $h = rand(1,5);
    $num_inequality = rand(1,4);
    if ($b == 1)
    {
        $a = rand(2,9);
    }
    else
    {
        $a = rand(1,$b-1);
    }
    if ($d == 1)
    {
        $c = rand(0,9);
    }
    else
    {
        $c = rand(0,$d-1);
    }
    if ($f == 1)
    {
        $e = rand(2,9);
    }
    else
    {
        $e = rand(1,$f-1);
    }
    if ($c == 0)
    {
        $lower_bound = 1;
    }
    else
    {
        $lower_bound = 0;
    }
    if ($h == 1)
    {
        $g = rand($lower_bound,9);
    }
    else
    {
        $g = rand($lower_bound,$g-1);
    }
    if ($c == 0)
    {
        $d = 1;
    }
    if ($g == 0)
    {
        $h = 1;
    }
    if ($b != 1)
    {
        reduce($a,$b,12);
    }
    if ($d != 1 && $c != 0)
    {
        reduce($c,$d,12);
    }
    if ($f != 1)
    {
        reduce($e,$f,12);
    }
    if ($h != 1 && $g != 0)
    {
        reduce($g,$h,12);
    }
    while ( ($a == $e) && ($b == $f) )
    {
        if ($b != 1)
        {
            $b = $b + 1;
        }
        else
        {
            $a = $a + 1;
        }
        if ($b != 1)
        {
            reduce($a,$b,12);
        }
    }
    rand_switch_sign($a,3);
    rand_switch_sign($e,3);
    if ($c != 0)
    {
        rand_switch_sign($c,3);
    }
    if ($g != 0)
    {
        rand_switch_sign($g,3);
    }
    while ( (($a * $f) - ($b * $e)) == 0)
    {
        $f++;
    }
    $num_bound = ($d * $g * $b * $f) - ($c * $h * $b * $f);
    $denom_bound = ($d * $h * $a * $f) - ($d * $h * $b * $e);
    if ($num_bound < 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound > 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound == 0)
    {
        $denom_bound = 1;
    }
    reduce($num_bound,$denom_bound,12);
    if ($denom_bound != 1)
    {
        $bound = "$num_bound / $denom_bound";
    }
    else
    {
        $bound = "$num_bound";
    }
    $bound = trim($bound);
    if ( (($a * $f) - ($b * $e)) < 0)
    {
        $switch_inequality = TRUE;
    }
    else
    {
        $switch_inequality = FALSE;
    }
    $left = "";
    $right = "";
     if ($c == 0)
    {
        $coeff2 = "0";
    }
    else if ($d == 1)
    {
        $coeff2 = "";
    }
    else
    {
        $coeff2 = "/$d";
    }
	  if ($c < 0)
    {
    	  $c = $c * (-1);
        $left = "-".$c.$coeff2;   
    }
    else if ($c != 0)
    {
        $left = "+".$c.$coeff2;
    }
	 if ($g == 0)
    {
        $coeff4 = "0";
    }
    else if ($h == 1)
    {
        $coeff4 = "";
    }
    else
    {
        $coeff4 = "/$h";
    }
    if ($g < 0)
    {
        $g = $g * (-1);
        $right = "-".$g.$coeff4;
    }
    else if ($g != 0)
    {
        $right = "+".$g.$coeff4;
    }
    if ($b == 1)
    {
        $coeff1 = "";
    }
    else
    {
        $coeff1 = "/$b";
    }

    if ($f == 1)
    {
        $coeff3 = "";
    }
    else
    {
        $coeff3 = "/$f";
    }
   
    $inf = " INF ";
	  $e1=$e;
	  if($e<0)
	  {
       $e1="~".abs($e);
    }
    $question .= $a.$coeff1."*x".$left.gen_inequality($num_inequality);
    $question .=$e1.$coeff3."*x".$right;
    if ($switch_inequality == TRUE)
    {
        $num_inequality = $num_inequality + 2;
        if ($num_inequality > 4)
        {
            $num_inequality = $num_inequality - 4;
        }
    }
    if ($num_bound < 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound > 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound == 0)
    {
        $denom_bound = 1;
    }
    reduce($num_bound,$denom_bound,12);
    $num_bound = trim($num_bound);
    $denom_bound = trim($denom_bound);
    if ($denom_bound != 1)
    {
        $bound = "$num_bound / $denom_bound";
    }
    else
    {
        $bound = $num_bound;
    }
    $bound = trim($bound);
    if ($num_inequality == 1)
    {
        $numerator = "(-$inf , $bound )";
    }
    else if ($num_inequality == 2)
    {
        $numerator = "(-$inf , $bound ]";
    }
    else if ($num_inequality == 3)
    {
        $numerator = "( $bound , $inf )";
    }
    else // ($num_inequality == 4)
    {
        $numerator = "[ $bound , $inf )";
    }
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #137 Generator              ////
////           Linear Inequalities 3                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_137()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(2,9);
    $c = rand(2,5);
    $d = rand(1,6);
    $e = rand(1,5);
    $num_inequality = rand(1,4);
    rand_switch_sign($c,3);
    rand_switch_sign($b,3);
    rand_switch_sign($e,3);
    while ( ($b - ($c * $e)) == 0)
    {
        $b++;
    }
    if ( ($b - ($c * $e)) < 0)
    {
        $switch_inequality = TRUE;
    }
    else
    {
        $switch_inequality = FALSE;
    }
    $num_bound = $c * $d - $a;
    $denom_bound = $b - ($c * $e);
    if ($num_bound < 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound > 0 && $denom_bound < 0)
    {
        $num_bound = $num_bound * (-1);
        $denom_bound = $denom_bound * (-1);
    }
    else if ($num_bound == 0)
    {
        $denom_bound = 1;
    }
    reduce($num_bound,$denom_bound,25);
    $num_bound = trim($num_bound);
    $denom_bound = trim($denom_bound);
    if ($denom_bound != 1)
    {
        $bound = "$num_bound / $denom_bound";
    }
    else
    {
        $bound = $num_bound;
    }
    $bound = trim($bound);
    coeff_prep($b);
    coeff_prep($e);
    $inf = " INF ";
	$c1=$c;
	if($c<0)
	{
       $c1="~".abs($c);
    }
    $question = $a.$b."x".gen_inequality($num_inequality).$c1."( ".$d.$e."x)";
    if ($switch_inequality == TRUE)
    {
        $num_inequality = $num_inequality + 2;
        if ($num_inequality > 4)
            $num_inequality = $num_inequality - 4;
    }
    if ($num_inequality == 1)
    {
        $numerator = "(-$inf , $bound )";
    }
    else if ($num_inequality == 2)
    {
        $numerator = "(-$inf , $bound ]";
    }
    else if ($num_inequality == 3)
    {
        $numerator = "( $bound , $inf )";
    }
    else // ($num_inequality == 4)
    {
        $numerator = "[ $bound , $inf )";
    }
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #138 Generator              ////
////           Linear Inequalities 4                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_138()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(1,9);
    $b = rand(2,9);
    $c = rand(1,9);
    $d = rand(1,9);
    while ($a == $d)
    {
        $d = rand(1,9);
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($d,3);
    rand_switch_sign($c,3);
    $num_inequality = rand(1,4);
    if ($num_inequality != 1)
    {
        $num_inequality1 = rand(1,2);
        $num_inequality2 = rand(1,2);
        if ($d < $a)
        {
            $temp = $d;
            $d = $a;
            $a = $temp;
        }
    }
    else
    {
        $num_inequality1 = rand(3,4);
        $num_inequality2 = rand(3,4);
        if ($a < $d)
        {
            $temp = $d;
            $d = $a;
            $a = $temp;
        }
    }
    $coeff1 = $c;
    coeff_prep($coeff1,0);
    $inf = " INF ";
	$b1=$b;
	if($b<0)
	{
       $b1="~".abs($b);
    }
	$d1=$d;
	if($d<0)
	{
       $d1="~".abs($d);
    }
    $question = $a.gen_inequality($num_inequality1).$b1."x".$coeff1.gen_inequality($num_inequality2).$d1;
    if ($b < 0)
    {
        $num_inequality1 = $num_inequality1 + 2;
        if ($num_inequality1 > 4)
        {
            $num_inequality1 = $num_inequality1 - 4;
        }
        $num_inequality2 = $num_inequality2 + 2;
        if ($num_inequality2 > 4)
        {
            $num_inequality2 = $num_inequality2 - 4;
        }
    }
    $num_bound1 = $a - $c;
    $denom_bound1 = $b;
    $num_bound2 = $d - $c;
    $denom_bound2 = $b;
    if ($num_bound1 < 0 && $denom_bound1 < 0)
    {
        $num_bound1 = $num_bound1 * (-1);
        $denom_bound1 = $denom_bound1 * (-1);
    }
    else if ($num_bound1 > 0 && $denom_bound1 < 0)
    {
        $num_bound1 = $num_bound1 * (-1);
        $denom_bound1 = $denom_bound1 * (-1);
    }
    else if ($num_bound1 == 0)
    {
        $denom_bound1 = 1;
    }
    if ($num_bound2 < 0 && $denom_bound2 < 0)
    {
        $num_bound2 = $num_bound2 * (-1);
        $denom_bound2 = $denom_bound2 * (-1);
    }
    else if ($num_bound2 > 0 && $denom_bound2 < 0)
    {
        $num_bound2 = $num_bound2 * (-1);
        $denom_bound2 = $denom_bound2 * (-1);
    }
    else if ($num_bound2 == 0)
    {
        $denom_bound2 = 1;
    }
    reduce($num_bound1,$denom_bound1,12);
    reduce($num_bound2,$denom_bound2,12);
    if ( ($num_bound1 * $denom_bound2) > ($num_bound2 * $denom_bound1))
    {
        $temp = $num_bound2;
        $num_bound2 = $num_bound1;
        $num_bound1 = $temp;
        $temp = $denom_bound1;
        $denom_bound1 = $denom_bound2;
        $denom_bound2 = $temp;
    }
    $num_bound1 = trim($num_bound1);
    $denom_bound1 = trim($denom_bound1);
    if ($denom_bound1 != 1)
    {
        $bound1 = "$num_bound1 / $denom_bound1";
    }
    else
    {
        $bound1 = $num_bound1;
    }
    $bound1 = trim($bound1);
    $num_bound2 = trim($num_bound2);
    $denom_bound2 = trim($denom_bound2);
    if ($denom_bound2 != 1)
    {
        $bound2 = "$num_bound2 / $denom_bound2";
    }
    else
    {
        $bound2 = $num_bound2;
    }
    $bound2 = trim($bound2);
    if ($num_inequality1 == 1 || $num_inequality2 == 3 )
    {
        $numerator = "( $bound1 , ";
    }
    else if ($num_inequality1 == 2 || $num_inequality2 == 4)
    {
        $numerator = "[ $bound1 , ";
    }
    if ($num_inequality1 == 3 || $num_inequality2 == 1 )
    {
        $numerator .= "$bound2 )";
    }
    else if ($num_inequality1 == 4 || $num_inequality2 == 2)
    {
        $numerator .= "$bound2 ]";
    }
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #139 Generator              ////
////           Linear Inequalities 5                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_139()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $b = rand(4,8);
    $d = rand(2,5);
    $f = rand(2,5);
    $a = rand(1,3);
    $c = rand(1,$d-1);
    $e = rand(4,$b-1);
    $num_inequality1 = rand(1,2);
    $num_inequality2 = rand(1,2);
    $denom1 = $b;
    $denom2 = $b;
    reduce($a,$denom1);
    reduce($e,$denom2);
    rand_switch_sign($c,3);
    $coeff1 = $c;
    coeff_prep($coeff1,0);
    $inf = " INF ";
    $question = $a."/".$denom1.gen_inequality($num_inequality1)."(x".$coeff1.")/".$d.gen_inequality($num_inequality2).$e."/".$denom2;
    $num_bound1 = ($a * $d) - ($c * $denom1);
    $denom_bound1 = $denom1;
    $num_bound2 = ($e * $d) - ($c * $denom2);
    $denom_bound2 = $denom2;
    if ($num_bound1 == 0)
    {
        $denom_bound1 = 1;
    }
    reduce($num_bound1,$denom_bound1,12);
    $num_bound1 = trim($num_bound1);
    $denom_bound1 = trim($denom_bound1);
    if ($denom_bound1 != 1)
    {
        $bound1 = "$num_bound1 / $denom_bound1";
    }
    else
    {
        $bound1 = $num_bound1;
    }
    $bound1 = trim($bound1);
    if ($num_bound2 == 0)
    {
        $denom_bound2 = 1;
    }
    reduce($num_bound2,$denom_bound2,12);
    $num_bound2 = trim($num_bound2);
    $denom_bound2 = trim($denom_bound2);
    if ($denom_bound2 != 1)
    {
        $bound2 = "$num_bound2 / $denom_bound2";
    }
    else
    {
        $bound2 = $num_bound2;
    }
    $bound2 = trim($bound2);
    if ($num_inequality1 == 1)
    {
        $numerator = "( $bound1 , ";
    }
    else if ($num_inequality1 == 2)
    {
        $numerator = "[ $bound1 , ";
    }
    if ($num_inequality2 == 1)
    {
        $numerator .= " $bound2 )";
    }
    else if ($num_inequality2 == 2)
    {
        $numerator .= " $bound2 ]";
    }
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #140 Generator              ////
////           Function Evaluation 1                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_140()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Linear Functions                     ////
    ////                f(x) = a x + b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    $point = rand(1,9);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($point,3);
    $point = $point + 1;
    $numerator = $a * $point + $b;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b,0);
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }
    $question = $func_name."(x)=".$a1."x ".$b.$split.$func_name."(".$point.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #141 Generator              ////
////           Function Evaluation 2                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_141()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Quadratic Functions                   ////
    ////           f(x) = a x^2 + b x + c                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,9);
    $point = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($point,3);
    rand_switch_sign($b,3);
    $b = $b + 1;
    $point = $point + 1;
    $numerator = $a * $point * $point + $b * $point + $c;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    $coeff = $b;
    coeff_prep($coeff);
    coeff_prep($c,0);
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }
    
    $question = $func_name."(x)=".$a1."x^2";
    if ($b != 0)
    {
        $question .= $coeff."x ";
    }
    $question .= $c.$split.$func_name."(".$point.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #142 Generator              ////
////           Function Evaluation 3                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_142()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Linear Rational Functions                ////
    ////         f(x) = (a x + b) / (c x + d)              ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,7);
    $d = rand(1,7);
    $point = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($point,3);
    $point = $point + 1;
    $numerator = $a * $point + $b;
    $denominator = $c * $point + $d;
    if ($numerator < 0 && $denominator < 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    else if ($denominator < 0 && $numerator > 0)
    {
        $numerator = $numerator * (-1);
        $denominator = $denominator * (-1);
    }
    if ($denominator == 0)
    {
        $numerator = "undefined";
        $denominator = 1;
    }
    else if ($numerator == 0)
    {
        $denominator = 1;
    }
    else
    {
        reduce($numerator,$denominator,20);
    }
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "~";
    }
    if ($c == 1)
    {
        $c = "";
    }
    else if ($c == -1)
    {
        $c = "-";
    }
    coeff_prep($b,0);
    coeff_prep($d,0);
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }
    
    $question = $func_name."(x)=(".$a1."x ".$b.")/(".$c."x ".$d.")".$split.$func_name."(".$point.")";
    if($denominator!=1)
      $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #143 Generator              ////
////           Function Evaluation 4                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_143()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Linear Functions                     ////
    ////                f(x) = a x + b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    $point = rand(1,9);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($point,3);
    $num_coeff = $a * $point + $b;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b,0);
    coeff_prep($num_coeff,0);
    coeff_prep($point,0);
    $numerator = $a."x ".$num_coeff;
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    $question = $func_name."(x)=".$a1."x ".$b.$split.$func_name."(x".$point.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #144 Generator              ////
////           Function Evaluation 5                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_144()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Quadratic Functions 1                 ////
    ////               f(x) = a x^2 + c                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,6);
    $c = rand(1,6);
    $point = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($point,3);
    $num_coeff1 = 2 * $a * $point;
    $num_coeff2 = $a * $point * $point + $c;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($num_coeff1);
    coeff_prep($num_coeff2,0);
    coeff_prep($c,0);
    coeff_prep($point,0);
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    $numerator = $a."x^2 ".$num_coeff1."x ".$num_coeff2;
    $question = $func_name."(x)=".$a1."x^2 ";
    $question .= $c.$split.$func_name."(x".$point.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #145 Generator              ////
////           Function Evaluation 6                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_145()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Quadractic Functions 2                   ////
    ////         f(x) = a x^2 + b x  + c                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,7);
    $point = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($point,3);
    if ( (2 * $a * $point + $b) == 0)
    {
        $a++;
    }
    if ($a == 0)
    {
        $a++;
    }
    $num_coeff1 = 2 * $a * $point + $b;
    $num_coeff2 = $c + ($b * $point) + ($a * $point * $point);
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b);
    coeff_prep($c,0);
    coeff_prep($point,0);
    coeff_prep($num_coeff1);
    coeff_prep($num_coeff2,0);
    $numerator = $a."x^2 ".$num_coeff1."x ".$num_coeff2;
   $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    
    $question = $func_name."(x)=".$a1."x^2 ".$b."x ".$c.$split.$func_name."(x".$point.")";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #146 Generator              ////
////            Function Evaluation 7                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_146()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Linear Functions                     ////
    ////                f(x) = a x + b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $num_coeff1 = $a;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b,0);
    coeff_prep($num_coeff1);
    $numerator = $a."a ".$num_coeff1."h ".$b;
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    $question = $func_name."(x)=".$a1."x ".$b.$split.$func_name."(a + h)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #147 Generator              ////
////            Function Evaluation 8                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_147()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Quadratic Functions 1                 ////
    ////               f(x) = a x^2 + c                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,6);
    $c = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $num_coeff1 = 2 * $a;
    $num_coeff2 = $a;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($num_coeff1);
    coeff_prep($num_coeff2);
    coeff_prep($c,0);
    $numerator = $a."a^2 ".$num_coeff1."ah ".$num_coeff2."h^2 ".$c;
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    $question = $func_name."(x)=".$a1."x^2";
    $question .= $c.$split.$func_name."(a+h)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #148 Generator              ////
////            Function Evaluation 9                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_148()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Quadractic Functions 2                   ////
    ////         f(x) = a x^2 + b x  + c                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,7);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $num_coeff1 = 2 * $a;
    $num_coeff2 = $a;
    $num_coeff3 = $b;
    $num_coeff4 = $b;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b);
    coeff_prep($c,0);
    coeff_prep($num_coeff1);
    coeff_prep($num_coeff2);
    coeff_prep($num_coeff3);
    coeff_prep($num_coeff4);
    $numerator = $a."a^2 ".$num_coeff1."ah ".$num_coeff2."h^2 ".$num_coeff3."a ".$num_coeff4."h ".$c;
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    $question = $func_name."(x)=".$a1."x^2 ".$b."x".$c.$split.$func_name."(a+h)";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #149 Generator              ////
////       Evaluating the Differemce Quotient 1        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_149()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "p";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Linear Functions                     ////
    ////                f(x) = a x + b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $num_coeff1 = $a;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b,0);
    $numerator = "$num_coeff1";
    $question = $func_name."(x)=".$a."x ".$b.$split."(".$func_name."(a+h)-".$func_name."(a))/h";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #150 Generator              ////
////       Evaluating the Differemce Quotient 2        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_150()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "p";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Quadratic Functions 1                 ////
    ////               f(x) = a x^2 + c                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,6);
    $c = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $num_coeff1 = 2 * $a;
    $num_coeff2 = $a;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($num_coeff2);
    coeff_prep($c,0);
    $numerator = $num_coeff1."a ".$num_coeff2."h ";
    $question = $func_name."(x)=".$a."x^2 ";
    $question .= $c.$split."(".$func_name."(a+h)-".$func_name."(a))/h";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #151 Generator              ////
////       Evaluating the Differemce Quotient 3        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_151()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "p";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Quadractic Functions 2                   ////
    ////         f(x) = a x^2 + b x  + c                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,7);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $num_coeff1 = 2 * $a;
    $num_coeff2 = $a;
    $num_coeff3 = $b;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b);
    coeff_prep($c,0);
    coeff_prep($num_coeff2);
    coeff_prep($num_coeff3,0);
    $numerator = $num_coeff1."a ".$num_coeff2."h ".$num_coeff3;
    $question = $func_name."(x)=".$a."x^2".$b."x".$c.$split."(".$func_name."(a+h)-".$func_name."(a))/h";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #152 Generator              ////
////  Function Evaluation - Word Problems 1            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_152()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $point = 0;
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_full_name = "cost";
        $func_name = "C";
        $variable_full_name = "made";
        $variable = "n";
        $last_statement = "are made?";
    }
    else if ($func_name == 2)
    {
        $func_full_name = "income";
        $func_name = "I";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    else // ($func_name == 3)
    {
        $func_full_name = "profit";
        $func_name = "P";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    $biz_name = rand(1,6);
    if ($biz_name == 1)
    {
        $biz_name = "Lane#s";
    }
    else if ($biz_name == 2)
    {
        $biz_name = "Tom#s";
    }
    else if ($biz_name == 3)
    {
        $biz_name = "Christensen#s";
    }
    else if ($biz_name == 4)
    {
        $biz_name = "Richards#";
    }
    else if ($biz_name == 5)
    {
        $biz_name = "Laurie#s";
    }
    else
    {
        $biz_name = "Mary#s";
    }
    $biz_type = rand(1,6);
    if ($biz_type == 1)
    {
        $biz_type = "Fish Store";
        $item_type = "fish hooks";
    }
    else if ($biz_type == 2)
    {
        $biz_type = "Pool Company";
        $item_type ="inground pools";
    }
    else if ($biz_type == 3)
    {
        $biz_type = "Restaurant";
        $item_type = "meals";
    }
    else if ($biz_type == 4)
    {
        $biz_type = "Tire Company";
        $item_type = "tires";
    }
    else if ($biz_type == 5)
    {
        $biz_type = "Yoga Center";
        $item_type = "floor mats";
    }
    else
    {
        $biz_type = "Awning Retailer";
        $item_type = "awnings";
    }
    $question .= $biz_name." ".$biz_type." has done some research and found that their ";
    $question .= $func_full_name.", <i>".$func_name."</i>, can be written as a function ";
    $question .= "of the number of ".$item_type." ".$variable_full_name.", ".$variable.". If ".$split;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Linear Functions                     ////
    ////                f(x) = a x + b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    $point = rand(2,12);
    rand_switch_sign($b,3);
    $num_coeff1 = $a * $point + $b;
    if ($a == 1)
    {
        $a = "";
    }
    coeff_prep($b,0);
    $numerator = "$num_coeff1";
    $question .= $func_name."(".$variable.")=".$a.$variable.$b.$split;
    $question .= "What would the ".$func_full_name." be if ".$point." ".$item_type." ".$last_statement;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #153 Generator              ////
////  Function Evaluation - Word Problems 2            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_153()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $point = 0;
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_full_name = "cost";
        $func_name = "C";
        $variable_full_name = "made";
        $variable = "n";
        $last_statement = "are made?";
    }
    else if ($func_name == 2)
    {
        $func_full_name = "income";
        $func_name = "I";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    else // ($func_name == 3)
    {
        $func_full_name = "profit";
        $func_name = "P";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    $biz_name = rand(1,6);
    if ($biz_name == 1)
    {
        $biz_name = "Lane#s";
    }
    else if ($biz_name == 2)
    {
        $biz_name = "Tom#s";
    }
    else if ($biz_name == 3)
    {
        $biz_name = "Christensen#s";
    }
    else if ($biz_name == 4)
    {
        $biz_name = "Richards#";
    }
    else if ($biz_name == 5)
    {
        $biz_name = "Laurie#s";
    }
    else
    {
        $biz_name = "Mary#s";
    }
    $biz_type = rand(1,6);
    if ($biz_type == 1)
    {
        $biz_type = "Fish Store";
        $item_type = "fish hooks";
    }
    else if ($biz_type == 2)
    {
        $biz_type = "Pool Company";
        $item_type ="inground pools";
    }
    else if ($biz_type == 3)
    {
        $biz_type = "Restaurant";
        $item_type = "meals";
    }
    else if ($biz_type == 4)
    {
        $biz_type = "Tire Company";
        $item_type = "tires";
    }
    else if ($biz_type == 5)
    {
        $biz_type = "Yoga Center";
        $item_type = "floor mats";
    }
    else
    {
        $biz_type = "Awning Retailer";
        $item_type = "awnings";
    }
    $question .= $biz_name." ".$biz_type." has done some research and found that their ";
    $question .= $func_full_name.", <i>".$func_name."</i>, can be written as a function ";
    $question .= "of the number of ".$item_type." ".$variable_full_name.", ".$variable.". If ".$split;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Quadratic Functions 1                 ////
    ////               f(x) = a x^2 + c                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,6);
    $c = rand(1,6);
    $point = rand(2,9);
    rand_switch_sign($c,3);
    $num_coeff1 = $a * $point * $point + $c;
    if ($a == 1)
    {
        $a = "";
    }
    coeff_prep($c,0);
    $numerator = $num_coeff1;
    $question .= $func_name."(".$variable.")=".$a."$variable^2 ";
    $question .= $c.$split;
    $question .= "What would the ".$func_full_name." be if ".$point." ".$item_type." ".$last_statement;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #154 Generator              ////
////  Function Evaluation - Word Problems 3            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_154()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $point = 0;
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_full_name = "cost";
        $func_name = "C";
        $variable_full_name = "made";
        $variable = "n";
        $last_statement = "are made?";
    }
    else if ($func_name == 2)
    {
        $func_full_name = "income";
        $func_name = "I";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    else // ($func_name == 3)
    {
        $func_full_name = "profit";
        $func_name = "P";
        $variable_full_name = "sold";
        $variable = "n";
        $last_statement = "are sold?";
    }
    $biz_name = rand(1,6);
    if ($biz_name == 1)
    {
        $biz_name = "Lane#s";
    }
    else if ($biz_name == 2)
    {
        $biz_name = "Tom#s";
    }
    else if ($biz_name == 3)
    {
        $biz_name = "Christensen#s";
    }
    else if ($biz_name == 4)
    {
        $biz_name = "Richards#";
    }
    else if ($biz_name == 5)
    {
        $biz_name = "Laurie#s";
    }
    else
    {
        $biz_name = "Mary#s";
    }
    $biz_type = rand(1,6);
    if ($biz_type == 1)
    {
        $biz_type = "Fish Store";
        $item_type = "fish hooks";
    }
    else if ($biz_type == 2)
    {
        $biz_type = "Pool Company";
        $item_type ="inground pools";
    }
    else if ($biz_type == 3)
    {
        $biz_type = "Restaurant";
        $item_type = "meals";
    }
    else if ($biz_type == 4)
    {
        $biz_type = "Tire Company";
        $item_type = "tires";
    }
    else if ($biz_type == 5)
    {
        $biz_type = "Yoga Center";
        $item_type = "floor mats";
    }
    else
    {
        $biz_type = "Awning Retailer";
        $item_type = "awnings";
    }
    $question .= $biz_name." ".$biz_type." has done some research and found that their ";
    $question .= $func_full_name.", <i>".$func_name."</i>, can be written as a function ";
    $question .= "of the number of ".$item_type." ".$variable_full_name.", ".$variable.". If ".$split;
    $a = rand(1,7);
    $b = rand(1,7);
    $c = rand(1,7);
    $point = rand(2,7);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $num_coeff1 = $a * $point * $point + $b * $point + $c;
    if ($a == 1)
    {
        $a = "";
    }
    coeff_prep($b);
    coeff_prep($c,0);
    $numerator = $num_coeff1;
    $question .= $func_name."(".$variable.")=".$a."$variable^2 ".$b."$variable ".$c.$split;
    $question .= "What would the ".$func_full_name." be if ".$point." ".$item_type." ".$last_statement;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #155 Generator              ////
////           Numerical Composition                   ////
///         Find F(G(a)) with "a" a const.             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_155()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = "@@";
    $f_func_name = rand(1,4);
    $g_func_name = rand(1,4);
    if ($g_func_name == $f_func_name)
    {
        $g_func_name++;
    }
    if ($f_func_name == 1)
    {
        $f_func_name = "F";
    }
    else if ($f_func_name == 2)
    {
        $f_func_name = "G";
    }
    else if ($f == 3)
    {
        $f_func_name = "H";
    }
    else // ($f_func_name == 4)
    {
        $f_func_name = "C";
    }
    if ($g_func_name == 1)
    {
        $g_func_name = "P";
    }
    else if ($g_func_name == 2)
    {
        $g_func_name = "M";
    }
    else if ($g_func_name == 3)
    {
        $g_func_name = "T";
    }
    else if ($g_func_name == 4)
    {
        $g_func_name = "N";
    }
    else // ($f_func_name == 4 && $g_func_name == 5)
    {
        $g_func_name = "I";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Possible G functions                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $g = rand(1,3);
    $a2 = rand(2,5);
    $b2 = rand(1,5);
    $c2 = rand(2,5);
    $point = rand(1,3);
    rand_switch_sign($a2,3);
    rand_switch_sign($b2,3);
    rand_switch_sign($c2,3);
    rand_switch_sign($point,2);
    if ($point < 3)
    {
        $randy = rand(1,2);
        if ($randy == 1)
            $point++;
    }
    if ($g == 1)
    {
        $g_point = $a2 * $point + $b2;
        coeff_prep($b2,0);
        $g_func = $a2."x ".$b2;
    }
    else if ($g == 2)
    {
        $g_point = $a2 * $point * $point + $c2;
        coeff_prep($c2,0);
        $g_func = $a2."x^2 ".$c2;
    }
    else // ($g == 3)
    {
        $g_point = $a2 * $point * $point + $b2 * $point + $c2;
        coeff_prep($b2);
        coeff_prep($c2,0);
        $g_func = $a2."x^2 ".$b2."x ".$c2;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Possible F functions                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $f = rand(1,3);
    $a = rand(2,5);
    $b = rand(1,5);
    $c = rand(1,5);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    if ($f == 1)
    {
        $numerator = $a * $g_point + $b;
        coeff_prep($b,0);
        $f_func = $a."x ".$b;
    }
    else if ($f == 2)
    {
        $numerator = $a * $g_point * $g_point + $c;
        coeff_prep($c,0);
        $f_func = $a."x^2 ".$c;
    }
    else // ($f == 3)
    {
        $numerator = $a * $g_point * $g_point + $b * $g_point + $c;
        coeff_prep($b);
        coeff_prep($c,0);
        $f_func = $a."x^2 ".$b."x ".$c;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Question Creation                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .=$f_func_name."(x)=".$f_func.$split;
    $question .= $g_func_name."(x)=".$g_func.$split;
    $question .= $f_func_name."(".$g_func_name;
    $question .= "(".$point."))";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #156 Generator              ////
////             Find the Domain 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_156()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question = $func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                polynomials                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(2,5);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $randy = rand(1,4);
	$a1=$a;
	if($a<0)
	{
       $a1="~".abs($a);
    }
    if ($randy == 1)
    {
        coeff_prep($b,0);
        $question .= $a1."x ".$b;
    }
    else if ($randy == 2)
    {
        coeff_prep($c,0);
        $question .= $a1."x^2 ".$c;
    }
    else if ($randy == 3)
    {
        coeff_prep($b);
        coeff_prep($c,0);
        $question .= $a1."x^2 ".$b."x ".$c;
    }
    else // ($randy == 4)
    {
        $question .= $a1."x^".$d;
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #157 Generator              ////
////             Find the Domain 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_157()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question = $func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Rational 1 factor                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(2,8);
    $c = rand(1,9);
    rand_switch_sign($c,3);
    $coeff1 = $b;
    $coeff2 = $c;
    coeff_prep($coeff2,0);
    $question .= $a."/(".$coeff1."x ".$coeff2.")";
    reduce($c,$b,25);
    $c = (-1) * $c;
    if ($b == 1)
    {
        $denominator = "$c";
    }
    else
    {
        $denominator = "$c/$b";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #158 Generator              ////
////             Find the Domain 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_158()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Rational 2 Factors                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////      Set up random function for numerator         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(2,5);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $randy = rand(1,4);
    $rand_func = "";
    if ($randy == 1)
    {
       coeff_prep($b,0);
       $rand_func = $a."x ".$b;
    }
    else if ($randy == 2)
    {
        coeff_prep($c,0);
        $rand_func = $a."x^2 ".$c;
    }
    else if ($randy == 3)
    {
        coeff_prep($b);
        coeff_prep($c,0);
        $rand_func = $a."x^2 ".$b."x ".$c;
    }
    else // ($randy == 4)
    {
        $rand_func = $a."x^".$d;
    }
    $question .= "(".$rand_func.")/(";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               Set up denominator                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $randy = rand(1,2);
    if ($randy == 1)
    {
        $a = rand(2,5);
        $b = rand(1,5);
        $c = rand(2,6);
        $d = rand(1,5);
        rand_switch_sign($b,3);
        rand_switch_sign($d,3);
        $temp = $b * $d - $a * $c;
        if ($temp == 0)
        {
            $a++;
        }
        $coeff1 = $a * $c;
        $coeff2 = $a * $d + $b * $c;
        $coeff3 = $b * $d;
        if ($coeff2 == 0)
        {
            $coeff2 = "0";
        }
        else
        {
            coeff_prep($coeff2);
        }
        coeff_prep($coeff3,0);
        $question .= $coeff1."x^2 ";
        if ($coeff2 != "0")
        {
            $question .= $coeff2."x ";
        }
        $question .= $coeff3;
        reduce($b,$a,25);
        reduce($d,$c,25);
        $b = (-1) * $b;
        $d = (-1) * $d;
        if ($d == $b && $a == $c)
        {
            if ($a != 1)
            {
                $denominator = "$b/$a ";
            }
            else
            {
                $denominator = "$b ";
            }
        }
        else
        {
            if ($a != 1)
            {
                $denominator = "$b/$a ,";
            }
            else
            {
                $denominator = "$b ,";
            }
            if ($c != 1)
            {
                $denominator .= "$d/$c";
            }
            else
            {
                $denominator .= "$d";
            }
        }
    }
    else // ($randy == 2)
    {
        $a = rand(1,9);
        $b = rand(1,9);
        rand_switch_sign($a,3);
        rand_switch_sign($b,3);
        $coeff1 = $a + $b;
        $coeff2 = $a * $b;
        if ($coeff1 == 0)
        {
            $coeff1 = "0";
        }
        else
        {
            coeff_prep($coeff1);
        }
        coeff_prep($coeff2,0);
        $question .="x^2 ";
        if ($coeff1 != "0")
        {
            $question .= $coeff1."x ";
        }
        $question .= $coeff2;
        $a = (-1) * $a;
        $b = (-1) * $b;
        if ($a == $b)
        {
            $denominator = "$a";
        }
        else
        {
            $denominator = "$a , $b";
        }
    }
	$question .=")";
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #159 Generator              ////
////              Find the Domain 4                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_159()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 odd roots                         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $root_number = 3;
    $func = rand(1,2);
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    coeff_prep($b,0);
    if ($func == 1)
    {
        $question .= "root(x ".$b.",3)";
    }
    else // $func == 2)
    {
        $question .= "root(".$a."x ".$b.",3)";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #160 Generator              ////
////              Find the Domain 5                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_160()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 Even Roots                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $root_number = rand(1,2);
    $a = rand(1,9);
    $b = rand(1,9);
    $func = rand(1,2);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
    if ($func == 1)
    {
        $question .= "sqrt(".$coeff1."x ".$coeff2.")";
    }
    else // ($func == 2)
    {
        $question .= "root(".$coeff1."x ".$coeff2.",4)";
    }
    $b = (-1) * $b;
    $my_numerator = $b;
    $my_denominator = $a;
    $switch = FALSE;
    if ($my_denominator < 0)
    {
        $switch = TRUE;
    }
    if ($my_numerator < 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    else if ($my_numerator > 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    reduce($my_numerator,$my_denominator,9);
    if ($switch == TRUE)
    {
        $numerator = "( -INF , ".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= "]";
    }
    else // ($switch == FALSE)
    {
        $numerator = "[".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ", INF)";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #161 Generator              ////
////             Find the Domain 6                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_161()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Sqrt,ftrt in denominator                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////      Set up random function for numerator         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(2,5);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $randy = rand(1,4);
    $rand_func = "";
    if ($randy == 1)
    {
       coeff_prep($b,0);
       $rand_func = $a."x ".$b;
    }
    else if ($randy == 2)
    {
        coeff_prep($c,0);
        $rand_func = $a."x^2 ".$c;
    }
    else if ($randy == 3)
    {
        coeff_prep($b);
        coeff_prep($c,0);
        $rand_func = $a."x^2 ".$b."x ".$c;
    }
    else // ($randy == 4)
    {
        $rand_func = $a."x^".$d;
    }
    $question .= "(".$rand_func.")/";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            Set up the actual Question             ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $root_number = rand(1,2);
    $a = rand(1,9);
    $b = rand(1,9);
    $func = rand(1,2);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
    if ($func == 1)
    {
        $question .= "sqrt(".$coeff1."x ".$coeff2.")";
    }
    else // ($func == 2)
    {
        $question .= "root(".$coeff1."x ".$coeff2.",4)";
    }
    $b = (-1) * $b;
    $my_numerator = $b;
    $my_denominator = $a;
    $switch = FALSE;
    if ($my_denominator < 0)
    {
        $switch = TRUE;
    }
    if ($my_numerator < 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    else if ($my_numerator > 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    reduce($my_numerator,$my_denominator,9);
    if ($switch == TRUE)
    {
        $numerator = "(-INF , ".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ")";
    }
    else // ($switch == FALSE)
    {
        $numerator = "(".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= " , INF)";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #162 Generator              ////
////             Find the Domain 7                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_162()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) =";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Square Root in Numerator              ////
    ////     Linear or Quadratic in the denominator        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $randy = rand(1,2);
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $denom_array = array();
    if ($randy == 1)
    {
        $coeff1 = $a + $b;
        $coeff2 = $a * $b;
        if ($coeff1 == 0)
        {
            $coeff1 = "0";
        }
        else
        {
            coeff_prep($coeff1);
        }
        coeff_prep($coeff2,0);
        $question1 .="x^2 ";
        if ($coeff1 != "0")
        {
            $question1 .= $coeff1."x ";
        }
        $question1 .= $coeff2.$split;
        $a = (-1) * $a;
        $b = (-1) * $b;
        if ($a == $b)
        {
            $denominator = "$a";
            $denom_array[0] = $a;
        }
        else
        {
            $denominator = "$a , $b";
            $denom_array[0] = $a;
            $denom_array[1] = $b;
        }
    }
    else //($randy == 2)
    {
        $coeff1 = $b;
        coeff_prep($coeff1,3);
        $question1 .= "x ".$coeff1;
        $b = (-1) * $b;
        $denominator = "$b";
        $denom_array[0] = $b;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Set up Rational in Numerator            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $root_number = rand(1,2);
    $a = rand(1,9);
    $b = rand(1,9);
    $func = rand(1,2);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
    if ($func == 1)
    {
        $question .= "sqrt(".$coeff1."x ".$coeff2.")";
    }
    else // ($func == 2)
    {
        $question .= "root(".$coeff1."x ".$coeff2.",4)";
    }
	$question.="/(".$question1.")";
    $b = (-1) * $b;
    $my_numerator = $b;
    $my_denominator = $a;
    $switch = FALSE;
    if ($my_denominator < 0)
    {
        $switch = TRUE;
    }
    if ($my_numerator < 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    else if ($my_numerator > 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    reduce($my_numerator,$my_denominator,9);
    $exclude_bound = FALSE;
    $pos = -1;
    if ($my_denominator == 1)
    {
        if ($my_numerator == $denom_array[0])
        {
            $exclude_bound = TRUE;
            $pos = 0;
        }
        if ($my_numerator == $denom_array[1])
        {
            $exclude_bound = TRUE;
            $pos = 1;
        }
    }
    if ($exclude_bound == FALSE)
    {
        $pos_array = array(FALSE,FALSE);
        if ($switch == TRUE)
        {
            $numerator = "(-INF , ".$my_numerator;
            if ($my_denominator != 1)
            {
                $numerator .= "/".$my_denominator;
            }
            $numerator .= "]";
            if ($my_denominator == 1)
            {
                if ($denom_array[0] > $my_numerator)
                {
                    $pos_array[0] = TRUE;
                }
                if ($denom_array[1] > $my_numerator && $denom_array[1] != NULL)
                {
                    $pos_array[1] = TRUE;
                }
            }
            else
            {
                if ( ($denom_array[0] * $my_denominator) > $my_numerator)
                {
                    $pos_array[0] = TRUE;
                }
                if ( ($denom_array[1] * $my_denominator) > $my_numerator && $denom_array[1] != NULL)
                {
                    $pos_array[1] = TRUE;
                }
            }
        }
        else // ($switch == FALSE)
        {
            $numerator = "[ ".$my_numerator;
            if ($my_denominator != 1)
            {
                $numerator .= "/".$my_denominator;
            }
            $numerator .= ", INF)";
            if ($my_denominator == 1)
            {
                if ($denom_array[0] < $my_numerator)
                {
                    $pos_array[0] = TRUE;
                }
                if ($denom_array[1] < $my_numerator && $denom_array[1] != NULL)
                {
                    $pos_array[1] = TRUE;
                }
            }
            else
            {
                if ( ($denom_array[0] * $my_denominator) < $my_numerator)
                {
                    $pos_array[0] = TRUE;
                }
                if ( ($denom_array[1] * $my_denominator) < $my_numerator && $denom_array[1] != NULL)
                {
                    $pos_array[1] = TRUE;
                }
            }
        }
        if ($pos_array[0] == TRUE && $pos_array[1] == FALSE)
        {
            if ($denom_array[1] == NULL)
            {
                $denominator = "not_used";
            }
            else
            {
                $denominator = $denom_array[1];
            }
        }
        if ($pos_array[1] == TRUE && $pos_array[0] == FALSE)
        {
            $denominator = $denom_array[0];
        }
        if ($pos_array[1] == TRUE && $pos_array[0] == TRUE)
        {
            $denominator = "not_used";
        }
    }
    else // ($exclude_bound == TRUE)
    {
        if ($switch == TRUE)
        {
            $numerator = "( -INF ,".$my_numerator;
            if ($my_denominator != 1)
            {
                $numerator .= "/".$my_denominator;
            }
            $numerator .= ")";
        }
        else // ($switch == FALSE)
        {
            $numerator = "( ".$my_numerator;
            if ($my_denominator != 1)
            {
                $numerator .= "/".$my_denominator;
            }
            $numerator .= ", INF)";
        }
        if ($pos == 1)
        {
            $denominator = $denom_array[0];
        }
        else // ($pos == 0)
        {
            if ($denom_array[1] == NULL)
            {
                $denominator = "not_used";
            }
            else
            {
                $denominator = $denom_array[1];
            }
        }
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #163 Generator              ////
////             Equations of a Line 1                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_163()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split="@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         through (a,b) with slope c                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    $c = rand(1,7);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $question = $a.$split.$b.$split.$c;
    $slope = $c;
    $yint = $b - $c * $a;
    $numerator = $slope.$split."1".$split.$yint.$split."1".$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #164 Generator              ////
////             Equations of a Line 2                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_164()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split="@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         through (a,c) with slope d/e              ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    $e = rand(1,12);
    reduce($d,$e);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    if ($e == 1)
    {
        $question = $a.$split.$c.$split.$d;
    }
    else
    {
        $question = $a.$split.$c.$split.$d.$split.$e;
    }
    $yint_num = $e * $c - $d * $a;
    if ($yint_num == 0)
    {
        $yint_denom = 1;
    }
    else
    {
        $yint_denom = $e;
        reduce($yint_num,$yint_denom,12);
    }
    $numerator = $d.$split.$e.$split.$yint_num.$split.$yint_denom.$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #165 Generator              ////
////            Equations of a Line 3                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_165()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         Goes through (a,b) , (c,d)                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $slope_num = $d - $b;
    $slope_denom = $c - $a;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $a = $a * (-1);
        $slope_denom = $c - $a;
    }
    $question = "Passes through: ( $a , $b ) and ( $c , $d )";
    if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $b.$split."1".$split."not_used".$split."1";
    }
    else if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else
    {
        $yint_num = ($b * ($c - $a)) - ($a * ($d - $b));
        $yint_denom = $c - $a;
        if ($slope_denom < 0)
        {
            $slope_denom = $slope_denom * (-1);
            $slope_num = $slope_num * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,24);
        }
        reduce($slope_num,$slope_denom,24);
        $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #166 Generator              ////
////            Equations of a Line 4                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_166()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = "@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////        Has a slope: a Has a y-int:b               ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $question = "Slope: $a; y-intercept: $b";
    $numerator = $a.$split."1".$split.$b.$split."1".$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #167 Generator              ////
////            Equations of a Line 5                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_167()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = "@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            X-int: $a; Y-int: $b                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $b = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $question = "X-intercept: $a; Y-intercept: $b";
    $slope_num = (-1) * $b;
    $slope_denom = $a;
    if ($slope_denom < 0)
    {
        $slope_num = $slope_num * (-1);
        $slope_denom = $slope_denom * (-1);
    }
    reduce($slope_num,$slope_denom,12);
    $numerator = $slope_num.$split.$slope_denom.$split.$b.$split."1".$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #168 Generator              ////
////             Equations of a Line 6                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_168()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = "@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 Subtype 1                         ////
    ////             Goes Through (a,c)                    ////
    ////          Parallel to dx + ey + f = 0              ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    $e = rand(1,12);
    $f = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    $x_coeff = $d;
    $y_coeff = $e;
    $const = $f;
    if ($x_coeff == 1)
    {
        $x_coeff = "";
    }
    else if ($x_coeff == -1)
    {
        $x_coeff = "-";
    }
    coeff_prep($y_coeff);
    coeff_prep($const,0);
    $question = "Passes through ( $a , $c );<br> Parallel to the line ";
    $question .= $x_coeff."x ".$y_coeff."y ".$const." = 0";
    $slope_num = (-1) * $d;
    $slope_denom = $e;
    $yint_num = $c * $e + $d * $a;
    $yint_denom = $e;
    if ($slope_denom < 0)
    {
        $slope_num = (-1) * $slope_num;
        $slope_denom = (-1) * $slope_denom;
        $yint_num = (-1) * $yint_num;
        $yint_denom = (-1) * $yint_denom;
    }
    if ($yint_num == 0)
    {
        $yint_denom = 1;
    }
    else
    {
        reduce($yint_num,$yint_denom,12);
    }
    reduce($slope_num,$slope_denom,12);
    $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #169 Generator              ////
////             Equations of a Line 7                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_169()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = "@@";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Goes Through (a,c)                    ////
    ////       Perpendicular to dx + ey + f = 0            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    $e = rand(1,12);
    $f = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    $x_coeff = $d;
    $y_coeff = $e;
    $const = $f;
    if ($x_coeff == 1)
    {
        $x_coeff = "";
    }
    else if ($x_coeff == -1)
    {
        $x_coeff = "-";
    }
    coeff_prep($y_coeff);
    coeff_prep($const,0);
    $question = "Passes through ( $a , $c );<br> Perpendicular to the line ";
    $question .= $x_coeff."x ".$y_coeff."y ".$const." = 0";
    $slope_num = $e;
    $slope_denom = $d;
    $yint_num = $c * $d - $e * $a;
    $yint_denom = $d;
    if ($slope_denom < 0)
    {
        $slope_num = (-1) * $slope_num;
        $slope_denom = (-1) * $slope_denom;
        $yint_num = (-1) * $yint_num;
        $yint_denom = (-1) * $yint_denom;
    }
    if ($yint_num == 0)
    {
        $yint_denom = 1;
    }
    else
    {
        reduce($yint_num,$yint_denom,12);
    }
    reduce($slope_num,$slope_denom,12);
    $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #170 Generator              ////
////            Equations of a Line 8                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_170()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Goes Through (a,c)                    ////
    ////     Parallel to the line passing through          ////
    ////              (d,e) and (f,g)                      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    $e = rand(1,12);
    $f = rand(1,12);
    $g = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    rand_switch_sign($g,3);
    $slope_num = $g - $e;
    $slope_denom = $f - $d;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $f = (-1) * $f;
        $slope_denom = $f - $d;
    }
    $question = "Passes through ( $a , $c );<br>Parallel to ";
    $question .= "the line passing through ( $d , $e ) and ( $f , $g)";
    if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= "not_used".$split."1".$split.$d.$split."1";
    }
    else if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $g.$split."1".$split."not_used".$split."1";
    }
    else
    {
        $yint_denom = $slope_denom;
        $yint_num = ($c * ($f - $d)) - ($a * ($g - $e));
        if ($slope_denom < 0)
        {
            $slope_num = $slope_num * (-1);
            $slope_denom = $slope_denom * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        reduce($slope_num,$slope_denom,24);
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,24);
        }
        $numerator = $slope_num.$split.$slope_denom.$split;
        $numerator .= $yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split;
        $numerator .= "not_used".$split."1";
   }
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #171 Generator              ////
////            Equations of a Line 9                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_171()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Goes Through (a,c)                    ////
    ////   Perpendicular to the line passing through       ////
    ////              (d,e) and (f,g)                      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    $e = rand(1,12);
    $f = rand(1,12);
    $g = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    rand_switch_sign($g,3);
    $slope_num = $f - $d;
    $slope_denom = $e - $g;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $f = (-1) * $f;
        $slope_num = $f - $d;
    }
    $question = "Passes through ( $a , $c );<br>Perpendicular to ";
    $question .= "the line passing through ( $d , $e ) and ( $f , $g)";
    if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $c.$split."1".$split."not_used".$split."1";
    }
    else
    {
        $yint_denom = $slope_denom;
        $yint_num = ($c * ($e - $g)) - ($a * ($f - $d));
        if ($slope_denom < 0)
        {
            $slope_num = $slope_num * (-1);
            $slope_denom = $slope_denom * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        reduce($slope_num,$slope_denom,24);
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,24);
        }
        $numerator = $slope_num.$split.$slope_denom.$split;
        $numerator .= $yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split;
        $numerator .= "not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #172 Generator              ////
////             Equations of a Line 10                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_172()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////    Through (a,c) parallel to the x-axis           ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Parallel to the x-axis";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= $c.$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #173 Generator              ////
////             Equations of a Line 11                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_173()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////    Through (a,c) parallel to the y-axis           ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Parallel to the y-axis";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= "not_used".$split."1".$split.$a.$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #174 Generator              ////
////             Equations of a Line 12                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_174()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////    Through (a,c) perpendicular to the x-axis      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Perpendicular to the x-axis";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= "not_used".$split."1".$split.$a.$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #175 Generator              ////
////             Equations of a Line 13                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_175()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////   Through (a,c) perpendicular to the y-axis       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Perpendicular to the y-axis";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= $c.$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #176 Generator              ////
////           Equations of a Line 14                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_176()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////     Passes through (a,c) parallel to x=d          ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Parallel to x = $d";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= "not_used".$split."1".$split.$a.$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #177 Generator              ////
////           Equations of a Line 15                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_177()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////     Passes through (a,c) parallel to y=d          ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Parallel to y = $d";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= $c.$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #178 Generator              ////
////           Equations of a Line 16                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_178()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////     Passes through (a,c) perpendicular to x=d     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Perpendicular to x = $d";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= $c.$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #179 Generator              ////
////           Equations of a Line 17                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_179()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,12);
    $c = rand(1,12);
    $d = rand(1,12);
    rand_switch_sign($a,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $question = "Passes through ( $a , $c );<br>";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////  Passes through (a,c) perpendicular to y=d        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Perpendicular to y = $d";
    $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
    $numerator .= "not_used".$split."1".$split.$a.$split."1";
    $answer = array($question,$numerator,$denominator,0,0,32);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #180 Generator              ////
////      Equations of a Line - Word Problems 1        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_180()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Simple Interest                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,3);
    $c = rand(5,8);
    $e = rand(1,7);
    $b = $e * 100 * rand(10,15);
    $d = $e * 100 * rand(16,20);
    $name = rand(1,6);
    if ($name == 1)
    {
        $name = "Tom";
    }
    else if ($name == 2)
    {
        $name = "Julie";
    }
    else if ($name == 3)
    {
        $name = "Rob";
    }
    else if ($name == 4)
    {
        $name = "Luara J.";
    }
    else if ($name == 5)
    {
        $name = "Amy";
    }
    else // ($name == 6)
    {
        $name = "Arnold";
    }
    $question = " $name opens a bank account that earns simple interest.";
    $question .= "(i.e. the amount in the account increases by a fixed amount";
    $question .= " each year.)  After $a years there is $b dollars in the account, ";
    $question .= " and after $c years there is $d dollars in the account.";
    $question .= "<br> What is a linear equation that relates the amount in ";
    $question .= "the account(A) to the number of years the account has been ";
    $question .= "open(n)?";
    $x_var = "n";
    $y_var = "A";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         Goes through (a,b) , (c,d)                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $slope_num = $d - $b;
    $slope_denom = $c - $a;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $a = $a * (-1);
        $slope_denom = $c - $a;
    }
    if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $b.$split."1".$split."not_used".$split."1";
    }
    else if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else
    {
        $yint_num = ($b * ($c - $a)) - ($a * ($d - $b));
        $yint_denom = $c - $a;
        if ($slope_denom < 0)
        {
            $slope_denom = $slope_denom * (-1);
            $slope_num = $slope_num * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,33);
        }
        reduce($slope_num,$slope_denom,33);
        $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #181 Generator              ////
////      Equations of a Line - Word Problems 2        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_181()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Value of a House                      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = 1900 + 5 * rand(11,15);
    $b = 1000 * rand(15,25);
    $c = 1900 + 5 * rand(16,20);
    $d = 10000 * rand(15,25);
    $name = rand(1,6);
    if ($name == 1)
    {
        $name = "Joe";
    }
    else if ($name == 2)
    {
        $name = "Terrence";
    }
    else if ($name == 3)
    {
        $name = "Jeff";
    }
    else if ($name == 4)
    {
        $name = "Greg";
    }
    else if ($name == 5)
    {
        $name = "Randy";
    }
    else // ($name == 6)
    {
        $name = "Noah";
    }
    $question = " Your uncle $name bought a house in $a for ";
    $question .= "$b dollars.  If the house value grew linearly and in $c ";
    $question .= "the house had a value of $d dollars, what would the ";
    $question .= "linear equation relating the value of the house(V) ";
    $question .= "to the time your uncle has owned the house(t) be?";
    $c = $c - $a;
    $a = $a - $a;
    $x_var = "t";
    $y_var = "V";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         Goes through (a,b) , (c,d)                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $slope_num = $d - $b;
    $slope_denom = $c - $a;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $a = $a * (-1);
        $slope_denom = $c - $a;
    }
    if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $b.$split."1".$split."not_used".$split."1";
    }
    else if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else
    {
        $yint_num = ($b * ($c - $a)) - ($a * ($d - $b));
        $yint_denom = $c - $a;
        if ($slope_denom < 0)
        {
            $slope_denom = $slope_denom * (-1);
            $slope_num = $slope_num * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,33);
        }
        reduce($slope_num,$slope_denom,33);
        $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #182 Generator              ////
////      Equations of a Line - Word Problems 3        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_182()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Profit of a bussiness                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = 5 * rand(11,15);
    $b = 100 * rand(9,20);
    $c = 5 * rand(16,22);
    $d = 100 * rand(32,44);
    $item_name = "";
    $name = rand(1,5);
    if ($name == 1)
    {
        $name = "The World of Coffee Makers";
        $item_name = "coffe makers";
    }
    else if ($name == 2)
    {
        $name = "John`s Fishing Rod Emporium";
        $item_name = "fishing rods";
    }
    else if ($name == 3)
    {
        $name = "Rose`s Luxury Tennis Rackets";
        $item_name = "tennis rackets";
    }
    else if ($name == 4)
    {
        $name = " The World of Frying Pans";
        $item_name = "frying pans";
    }
    else // ($name == 5)
    {
        $name = "Winston`s House of Leaf Rakes";
        $item_name = "rakes";
    }
    $question = " $name sold $a $item_name in the month ";
    $question .= "of February, and in March they sold $c $item_name. ";
    $question .= "If their profits for February and March where $b dollars ";
    $question .= "and $d dollars respectively, what is the linear equation ";
    $question .= "that relates their profit(P) to the number of $item_name ";
    $question .= "made(n)?";
    $x_var = "n";
    $y_var = "P";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         Goes through (a,b) , (c,d)                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $slope_num = $d - $b;
    $slope_denom = $c - $a;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $a = $a * (-1);
        $slope_denom = $c - $a;
    }
    if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $b.$split."1".$split."not_used".$split."1";
    }
    else if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else
    {
        $yint_num = ($b * ($c - $a)) - ($a * ($d - $b));
        $yint_denom = $c - $a;
        if ($slope_denom < 0)
        {
            $slope_denom = $slope_denom * (-1);
            $slope_num = $slope_num * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,33);
        }
        reduce($slope_num,$slope_denom,33);
        $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #183 Generator              ////
////      Equations of a Line - Word Problems 4        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_183()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Loss of Value                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = 0;
    $b = 100 * rand(30,45);
    $c = rand(2,5);
    $d = 100 * rand(2,6);
    $name = rand(1,5);
    if ($name == 1)
    {
        $name = "The World of Coffee Makers";
    }
    else if ($name == 2)
    {
        $name = "John`s Fishing Rod Emporium";
    }
    else if ($name == 3)
    {
        $name = "Rose`s Luxury Tennis Rackets";
    }
    else if ($name == 4)
    {
        $name = " The World of Frying Pans";
    }
    else // ($name == 5)
    {
        $name = "Winston`s House of Leaf Rakes";
    }
    $question = " $name buys a computer for $b dollars. ";
    $question .= "After $c years the computer will be worth $d dollars. ";
    $question .= "What is the linear equation that relates the value of the ";
    $question .= "computer(V) to the age of the computer(a)?";
    $x_var = "a";
    $y_var = "V";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////         Goes through (a,b) , (c,d)                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $slope_num = $d - $b;
    $slope_denom = $c - $a;
    if ($slope_num == 0 && $slope_denom == 0)
    {
        $a = $a * (-1);
        $slope_denom = $c - $a;
    }
    if ($slope_num == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;
        $numerator .= $b.$split."1".$split."not_used".$split."1";
    }
    else if ($slope_denom == 0)
    {
        $numerator = "not_used".$split."1".$split."not_used".$split."1".$split;;
        $numerator .= "not_used".$split."1".$split.$a.$split."1";
    }
    else
    {
        $yint_num = ($b * ($c - $a)) - ($a * ($d - $b));
        $yint_denom = $c - $a;
        if ($slope_denom < 0)
        {
            $slope_denom = $slope_denom * (-1);
            $slope_num = $slope_num * (-1);
            $yint_num = $yint_num * (-1);
            $yint_denom = $yint_denom * (-1);
        }
        if ($yint_num == 0)
        {
            $yint_denom = 1;
        }
        else
        {
            reduce($yint_num,$yint_denom,33);
        }
        reduce($slope_num,$slope_denom,33);
        $numerator = $slope_num.$split.$slope_denom.$split.$yint_num.$split.$yint_denom.$split;
        $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    }
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #184 Generator              ////
////        Equations of a Line Word Problems 5        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_184()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(120,330);
    $b = rand(150,300);
    $name = rand(1,5);
    if ($name == 1)
    {
        $name = "KSU";
    }
    else if ($name == 2)
    {
        $name = "Shirley`s School of Hair";
    }
    else if ($name == 3)
    {
        $name = "PCU";
    }
    else if ($name == 4)
    {
        $name = "Tom`s School of Modern Art";
    }
    else if ($name == 5)
    {
        $name = "Bob`s School of Deep Sea Fishing";
    }
    else // ($name == 6)
    {
        $name = "Julie's School of Geometry";
    }
    $question = " If the cost of taking courses at ";
    $question .= "$name is $a dollars per class plus a registration fee ";
    $question .= "of $b dollars, what is the linear equation that relates ";
    $question .= "the Cost of taking courses(C) to the number of courses(n)?";
    $x_var = "n";
    $y_var = "C";
    $numerator = $a.$split."1".$split.$b.$split."1".$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #185 Generator              ////
////        Equations of a Line Word Problems 6        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_185()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Population of a Town                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $b = 100 * rand(105,225);
    $a = 10 * rand(50,75);
    $question = " If a town starts with an initial population ";
    $question .= "of $b and $a people leave each year, what is the linear ";
    $question .= "equation that relates the population(P) to the number ";
    $question .= "of years since the town began(n)?";
    $a = (-1) * $a;
    $x_var = "n";
    $y_var = "P";
    $numerator = $a.$split."1".$split.$b.$split."1".$split;
    $numerator .= "not_used".$split."1".$split."not_used".$split."1";
    $answer = array($question,$numerator,$denominator,$x_var,$y_var,33);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #186 Generator              ////
////         Graduate Tax vs. Flat Tax 1               ////
////            Find the Amount of Tax                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_186()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(13,20);
    $b = rand(10,$a-1);
    $c = rand($a+5,30);
    $d = 10000 * rand(1,4);
    $e = 1000 * rand(10,60);
    $flat_tax = $a * 0.01;
    $graduated_tax_low = $b * 0.01;
    $graduated_tax_high = $c * 0.01;
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $question = "Suppose a flat tax and graduated tax can be represented by the ";
    $question .= "following functions, <i>f</i>(i) and <i>g</i>(i) respectively.".$split;
    $question .= $flat_tax.$split.$graduated_tax_low.$split.$d.$split.$q_const1.$split;
    $question .= $graduated_tax_high.$split.$d.$split.$d.$split;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Find the Flat Tax                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Find what the flat tax would be for an income of ";
    $question .= "$$e.";
    $numerator = bcmul($flat_tax,$e,12);
    $numerator = bcmul($numerator,1,2);
    $denominator2 = $numerator - 0.001;
    $numerator2 = $numerator + 0.001;
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,$numerator2,$denominator2,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #186 Generator              ////
////         Graduate Tax vs. Flat Tax 2               ////
////            Find the Amount of Tax                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_187()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(13,20);
    $b = rand(10,$a-1);
    $c = rand($a+5,30);
    $d = 10000 * rand(1,4);
    $e = 1000 * rand(10,60);
    $flat_tax = $a * 0.01;
    $graduated_tax_low = $b * 0.01;
    $graduated_tax_high = $c * 0.01;
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $question = "Suppose a flat tax and graduated tax can be represented by the ";
    $question .= "following functions, <i>f</i>(i) and <i>g</i>(i) respectively.".$split;
    $question .= $flat_tax.$split.$graduated_tax_low.$split.$d.$split.$q_const1.$split;
    $question .= $graduated_tax_high.$split.$d.$split.$d.$split;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            Find the Graduated Tax                 ////
    ////           Mathematical Description                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question .= "Find what the graduated tax would be for an income of ";
    $question .= "$$e.";
    if ($e <= $d)
    {
        $numerator = bcmul($graduated_tax_low,$e,12);
        $numerator = bcmul($numerator,1,2);
        $denominator2 = $numerator - 0.001;
        $numerator2 = $numerator + 0.001;
    }
    else
    {
        $numerator = $e - $d;
        $numerator = bcmul($numerator,$graduated_tax_high,12);
        $numerator = bcmul($numerator,1,2);
        $numerator = $numerator + $q_const1;
        $denominator2 = $numerator - 0.001;
        $numerator2 = $numerator + 0.001;
    }
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,$numerator2,$denominator2,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #188 Generator              ////
////         Graduate Tax vs. Flat Tax 3               ////
////            Find the Amount of Tax                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_188()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(13,20);
    $b = rand(10,$a-1);
    $c = rand($a+5,30);
    $d = 10000 * rand(1,4);
    $e = 1000 * rand(10,60);
    $flat_tax = $a * 0.01;
    $graduated_tax_low = $b * 0.01;
    $graduated_tax_high = $c * 0.01;
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Find the Graduated Tax                  ////
    ////              Verbal Description                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question = "Suppose there is a graduated tax such that ";
    $question .= "the tax is $b% on the first $$d of income and ";
    $question .= "$c% on income above $$d. Find the tax ";
    $question .= "on an income of $$e.";
    if ($e <= $d)
    {
        $numerator = bcmul($graduated_tax_low,$e,12);
        $numerator = bcmul($numerator,1,2);
        $denominator2 = $numerator - 0.001;
        $numerator2 = $numerator + 0.001;
    }
    else
    {
        $numerator = $e - $d;
        $numerator = bcmul($numerator,$graduated_tax_high,12);
        $numerator = bcmul($numerator,1,2);
        $numerator = $numerator + $q_const1;
        $denominator2 = $numerator - 0.001;
        $numerator2 = $numerator + 0.001;
    }
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,$numerator2,$denominator2,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #189 Generator              ////
////         Graduate Tax vs. Flat Tax 4               ////
////            Which Tax is Larger                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_189()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(13,20);
    $b = rand(10,$a-1);
    $c = rand($a+5,30);
    $d = 10000 * rand(1,4);
    $e = 1000 * rand(10,60);
    $flat_tax = $a * 0.01;
    $graduated_tax_low = $b * 0.01;
    $graduated_tax_high = $c * 0.01;
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $question = "Suppose a flat tax and graduated tax can be represented by the ";
    $question .= "following functions, <i>f</i>(i) and <i>g</i>(i) respectively.".$split;
    $question .= $flat_tax.$split.$graduated_tax_low.$split.$d.$split.$q_const1.$split;
    $question .= $graduated_tax_high.$split.$d.$split.$d.$split;
    $question .= "Which tax is greater for an income of $$e?";
    $f_tax = bcmul($flat_tax,$e,12);
    $f_tax = bcmul($f_tax,1,2);
    if ($e <= $d)
    {
        $g_tax = bcmul($graduated_tax_low,$e,12);
        $g_tax = bcmul($numerator,1,2);
    }
    else
    {
        $g_tax = $e - $d;
        $g_tax = bcmul($g_tax,$graduated_tax_high,12);
        $g_tax = bcmul($g_tax,1,2);
        $g_tax = $g_tax + $q_const1;
    }
    if ($g_tax > $f_tax)
    {
        $numerator2 = 1;
        $numerator = "The Graduated Tax is Larger.";
    }
    else if ($g_tax < $f_tax)
    {
        $numerator2 = 2;
        $numerator = "The Flat Tax is Larger.";
    }
    else
    {
        $numerator2 = 3;
        $numerator = "The Taxes are Equal.";
    }
    $answer = array($question,$numerator,$denominator,$numerator2,1,2);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #190 Generator              ////
////         Graduate Tax vs. Flat Tax 5               ////
////      Find the Equation of a Graduated Tax         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_190()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $b = rand(10,18);
    $c = rand($b+5,30);
    $d = 10000 * rand(1,4);
    $e = 1000 * rand(10,60);
    $graduated_tax_low = $b * 0.01;
    $graduated_tax_high = $c * 0.01;
    $q_const1 = bcmul($graduated_tax_low,$d,12);
    $q_const1 = bcmul($q_const1,1,2);
    $question = "Suppose there is a graduated tax such that ";
    $question .= "the tax is $b% on the first $$d of income and ";
    $question .= "$c% on income above $$d. Find the equation ";
    $question .= "of such a tax.";
    $numerator = $graduated_tax_low.$split.$d.$split.$q_const1.$split;
    $numerator .= $graduated_tax_high.$split.$d.$split.$d;
    $answer = array($question,$numerator,$denominator,0,0,3);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #191 Generator              ////
////             Converting Units 1                    ////
////              Metric to English                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_191()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Kilometers to Miles                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,15);
    $question = "How many miles are there in $a kilometer(s)?";
    $numerator = bcdiv($a,1.609347,12);
    $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #192 Generator              ////
////             Converting Units 2                    ////
////              Metric to English                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_192()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Meters to Feet                       ////
    ////            Kiliometers to Feet                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $new_randy = rand(1,2);
    if ($new_randy == 1)
    {
        $a = rand(1,15);
        $question = "How many feet are there in $a meter(s)?";
        $numerator = bcdiv($a,0.3048,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    else // ($new_randy == 2)
    {
        $a = rand(1,4);
        $question = "How many feet are there in $a kilometers(s)?";
        $numerator = bcdiv($a,0.0003048,16);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #193 Generator              ////
////             Converting Units 3                    ////
////              Metric to English                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_193()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Meters to Inches                      ////
    ////           Centimeters to Inches                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $new_randy = rand(1,2);
    if ($new_randy == 1)
    {
        $a = rand(1,6);
        $question = "How many inches are there in $a meter(s)?";
        $numerator = bcdiv($a,0.0254,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    else // ($new_rand == 2)
    {
        $a = rand(5,25);
        $question = "How many inches are there in $a centimeter(s)?";
        $numerator = bcdiv($a,2.54,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #194 Generator              ////
////             Converting Units 4                    ////
////              English to Metric                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_194()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Miles to Kilometers                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,15);
    $question = "How many kilometers are there in $a mile(s)?";
    $numerator = bcmul($a,1.609347,12);
    $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #195 Generator              ////
////             Converting Units 5                    ////
////              English to Metric                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_195()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Feet to Meters                       ////
    ////            Feet to Kilometers                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $new_randy = rand(1,2);
    if ($new_randy == 1)
    {
        $a = rand(4,35);
        $question = "How many meters are there in $a feet?";
        $numerator = bcmul($a,0.3048,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    else // ($new_randy == 2)
    {
        $rand = rand(1,2);
        if ($rand == 1)
        {
            $a = rand(3048,12000);
            }
        else
        {
            $a = rand(31,120);
        }
        $question = "How many kilometers are there in $a feet?";
        $numerator = bcmul($a,0.0003048,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #196 Generator              ////
////             Converting Units 6                    ////
////              English to Metric                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_196()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Inches to Meters                      ////
    ////           Inches to Centimeters                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $new_randy = rand(1,2);
    if ($new_randy == 1)
    {
        $rand = rand(1,2);
        if ($rand == 1)
        {
            $a = rand(254,1000);
        }
        else
        {
            $a = rand(5,100);
        }
        $question = "How many meters are there in $a inch(es)?";
        $numerator = bcmul($a,0.0254,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    else // ($new_rand == 2)
    {
        $a = rand(5,25);
        $question = "How many centimeters are there in $a inch(es)?";
        $numerator = bcmul($a,2.54,12);
        $numerator = round($numerator + 0.0001 / pow(10, 3), 3);
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #197 Generator              ////
////             Converting Units 7                    ////
////                 LightYears                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_197()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Light Years to Kilometers               ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(10,60) / 10;
    $question = "How many kilometers is $a lightyear(s)?";
    $a = $a * 9.46;
    $b = 0;
    while ($a >= 10)
    {
        $b++;
        $a = $a / 10;
    }
    $a = round($a + 0.0001 / pow(10, 2), 2);
    $numerator = $a;
    $denominator = $b + 12;
    $answer = array($question,$numerator,$denominator,0,0,4);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #198 Generator              ////
////             Converting Units 8                    ////
////                 LightYears                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_198()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Kilometers to Lightyears                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(95,1892) / 10;
    $b = 12;
    while ($a >= 10)
    {
        $b++;
        $a = $a / 10;
    }
    $question = "How many lightyears is $a * 10<sup>$b</sup> kilometers?";
    $b = $b - 12;
    $a = bcdiv($a,9.46,12) * pow(10,$b);
    $b = 0;
    while ($a >= 10)
    {
         $b++;
         $a = $a / 10;
    }
    $a = round($a + 0.0001 / pow(10,2),2);
    $numerator = $a;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,0,0,4);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #199 Generator              ////
////             Order of Magnitude 1                  ////
////            Number of times Larger                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_199()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Richter Scale                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(25,55);
    $b = rand($a,86);
    $a = $a / 10;
    $b = $b / 10;
    $question = "Compare two earthquakes that register ";
    $question .= " $a on the Richter Scale and $b on the ";
    $question .= "Richter Scale.  How many times larger is ";
    $question .= "the second earthquake?";
    $diff = $b - $a;
    $numerator = pow(10,$diff);
    $numerator = round($numerator + 0.0001 / pow(10,3),3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #200 Generator              ////
////             Order of Magnitude 2                  ////
////            Number of times Larger                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_200()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 PH Scale                          ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(10,50);
    $b = rand($a,70);
    $a = $a / 10;
    $b = $b / 10;
    $question = "Compare two sample of water that have a PH of ";
    $question .= "$a and $b respectively.  How many times more ";
    $question .= "acidic is the first sample?";
    $diff = $b - $a;
    $numerator = pow(10,$diff);
    $numerator = round($numerator + 0.0001 / pow(10,3),3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #201 Generator              ////
////             Order of Magnitude 3                  ////
////       Difference in Order of Magnitude            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_201()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               Richter Scale                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(25,55);
    $b = rand($a,86);
    $a = $a / 10;
    $b = $b / 10;
    $question = "Compare two earthquakes that register ";
    $question .= " $a on the Richter Scale and $b on the ";
    $question .= "Richter Scale.  How many orders of magnitude ";
    $question .= "larger is ";
    $question .= "the second earthquake?";
    $diff = $b - $a;
    $numerator = $diff;
    $numerator = round($numerator + 0.0001 / pow(10,3),3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #202 Generator              ////
////             Order of Magnitude 4                  ////
////       Difference in Order of Magnitude            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_202()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 PH Scale                          ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(10,50);
    $b = rand($a,70);
    $a = $a / 10;
    $b = $b / 10;
    $question = "Compare two sample of water that have a PH of ";
    $question .= "$a and $b respectively.  How many orders of ";
    $question .= "magnitude more ";
    $question .= "acidic is the first sample?";
    $diff = $b - $a;
    $numerator = $diff;
    $numerator = round($numerator + 0.0001 / pow(10,3),3);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #203 Generator              ////
////             Order of Magnitude 5                  ////
////       Difference in Order of Magnitude            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_203()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                Metric Scale                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,13);
    $b = rand($a+1,17);
    $prefix = array();
    if ($a == 1)
    {
        $prefix[0] = "atto";
        $a = -18;
    }
    else if ($a == 2)
    {
        $prefix[0] = "femto";
        $a = -15;
    }
    else if ($a == 3)
    {
        $prefix[0] = "pico";
        $a = -12;
    }
    else if ($a == 4)
    {
        $prefix[0] = "nano";
        $a = -9;
    }
    else if ($a == 5)
    {
        $prefix[0] = "micro";
        $a = -6;
    }
    else if ($a == 6)
    {
        $prefix[0] = "milli";
        $a = -3;
    }
    else if ($a == 7)
    {
        $prefix[0] = "centi";
        $a = -2;
    }
    else if ($a == 8)
    {
        $prefix[0] = "deci";
        $a = -1;
    }
    else if ($a == 9)
    {
        $prefix[0] = "";
        $a = 0;
    }
    else if ($a == 10)
    {
        $prefix[0] = "deka";
        $a = 1;
    }
    else if ($a == 11)
    {
        $prefix[0] = "hecto";
        $a = 2;
    }
    else if ($a == 12)
    {
        $prefix[0] = "kilo";
        $a = 3;
    }
    else if ($a == 13)
    {
        $prefix[0] = "mega";
        $a = 6;
    }
    if ($b == 1)
    {
        $prefix[1] = "atto";
        $b = -18;
    }
    else if ($b == 2)
    {
        $prefix[1] = "femto";
        $b = -15;
    }
    else if ($b == 3)
    {
        $prefix[1] = "pico";
        $b = -12;
    }
    else if ($b == 4)
    {
        $prefix[1] = "nano";
        $b = -9;
    }
    else if ($b == 5)
    {
        $prefix[1] = "micro";
        $b = -6;
    }
    else if ($b == 6)
    {
        $prefix[1] = "milli";
        $b = -3;
    }
    else if ($b == 7)
    {
        $prefix[1] = "centi";
        $b = -2;
    }
    else if ($b == 8)
    {
        $prefix[1] = "deci";
        $b = -1;
    }
    else if ($b == 9)
    {
        $prefix[1] = "";
        $b = 0;
    }
    else if ($b == 10)
    {
        $prefix[1] = "deka";
        $b = 1;
    }
    else if ($b == 11)
    {
        $prefix[1] = "hecto";
        $b = 2;
    }
    else if ($b == 12)
    {
        $prefix[1] = "kilo";
        $b = 3;
    }
    else if ($b == 13)
    {
        $prefix[1] = "mega";
        $b = 6;
    }
    else if ($b == 14)
    {
        $prefix[1] = "giga";
        $b = 9;
    }
    else if ($b == 15)
    {
        $prefix[1] = "tera";
        $b = 12;
    }
    else if ($b == 16)
    {
        $prefix[1] = "peta";
        $b = 15;
    }
    else if ($b == 17)
    {
        $prefix[1] = "exa";
        $b = 18;
    }
    $question = "How many orders of magnitudes larger is a ";
    $question .= $prefix[1];
    $question .= "meter then a ";
    $question .= $prefix[0];
    $question .= "meter?";
    $numerator = $b - $a;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #204 Generator              ////
////               Common Log 1                        ////
////            Write in Log Form                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_204()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,13) - 7;
    $pow = $a;
    if ($a == -5)
    {
        $rhs = "0.00001";
    }
    else if ($a == -6)
    {
        $rhs = "0.000001";
    }
    else
    {
        $rhs = pow(10,$a);
    }
	$pow1=$pow;
	if($pow<0)
	{
       $pow1="~".abs($pow);
    }
    $question = "10^".$pow1."=".$rhs;
    $numerator = $rhs;
    $denominator = $pow;
    $answer = array($question,$numerator,$denominator,0,0,5);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #205 Generator              ////
////               Common Log 2                        ////
////             Write in Exp Form                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_205()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,13) - 7;
    $pow = $a;
    if ($a == -5)
    {
        $rhs = "0.00001";
    }
    else if ($a == -6)
    {
        $rhs = "0.000001";
    }
    else
    {
        $rhs = pow(10,$a);
    }
    $pow1=$pow;
	if($pow<0)
	{
       $pow1="~".abs($pow);
    }
    $question = "log(".$rhs.")=".$pow1;
    $numerator = $pow;
    $denominator = $rhs;
    $answer = array($question,$numerator,$denominator,0,0,6);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #206 Generator              ////
////               Common Log 3                        ////
////              Find log x easy                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_206()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(1,13) - 7;
    $pow = $a;
    if ($a == -5)
    {
        $rhs = "0.00001";
    }
    else if ($a == -6)
    {
        $rhs = "0.000001";
    }
    else
    {
        $rhs = pow(10,$a);
    }
    $question = "log(".$rhs.")";
    $numerator = $pow;
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #207 Generator              ////
////               Common Log 4                        ////
////             Find Log x messy                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_207()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(5,45000)/10;
    $pow = $a;
    $answer = log10($a);
    $question = "log(".$a.")";
    $numerator = $answer;
    $numerator = round($numerator + 0.0001 / pow(10,3),3);
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #208 Generator              ////
////           Exponential Models 1                    ////
////         Identify the Growth Rate                  ////
////          and initial population                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_208()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(50,15000);
    $b = rand(101,500) / 100;
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "P";
    }
    else if ($var == 2)
    {
        $var = "N";
    }
    else if ($var == 3)
    {
        $var = "Q";
    }
    else if ($var == 4)
    {
        $var = "A";
    }
    else // ($var == 5)
    {
        $var = "y";
    }
    $question = $var." = ".$a." * (".$b.")^t";
    $numerator = $a;
    $denominator = $b - 1;
    $answer = array($question,$numerator,$denominator,0,0,7);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #209 Generator              ////
////            Exponential Models 2                   ////
////     Identify Growth Rate as a Percentage          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_209()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $a = rand(50,15000);
    $randy = rand(1,2);
    if ($randy == 1)
    {
        $b = rand(101,199) / 100;
    }
    else
    {
        $b = rand(200,500) / 100;
    }
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "P";
    }
    else if ($var == 2)
    {
        $var = "N";
    }
    else if ($var == 3)
    {
        $var = "Q";
    }
    else if ($var == 4)
    {
        $var = "A";
    }
    else // ($var == 5)
    {
        $var = "y";
    }
    $question = $var." = ".$a." * (".$b.")^t";
    $numerator = ($b - 1) * 100;
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,8);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #210 Generator              ////
////            Exponential Models 3                   ////
////             Growth vs. Decay                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_210()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(50,15000);
    $b = rand(1,200) / 100;
    if ($b == 1)
    {
        $b = 1.01;
    }
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "P";
    }
    else if ($var == 2)
    {
        $var = "N";
    }
    else if ($var == 3)
    {
        $var = "Q";
    }
    else if ($var == 4)
    {
        $var = "A";
    }
    else // ($var == 5)
    {
        $var = "y";
    }
    $question = $var." = ".$a." * (".$b.")^t";
    if ($b < 1)
    {
        $numerator = 2;
    }
    else
    {
        $numerator = 1;
    }
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,9);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #211 Generator              ////
////            Exponential Models 4                   ////
////            Write the Equation 1                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_211()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(50,15000);
    $b = rand(1,300) / 100;
    if ($b == 1)
    {
        $b = 1.01;
    }

    if ($b > 1)
    {
        $rate = "growth";
    }
    else
    {
        $rate = "decay";
    }
    $question = "An ideal exponential population model that has an initial population of ";
    $question .= "$a and a $rate factor of $b.";
    $numerator = $a;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,0,0,10);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #212 Generator              ////
////            Exponential Models 5                   ////
////            Write the Equation 2                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_212()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(50,15000);
    $question = "The pollution level in a certain lake can be represented by an<br> ";
    $question .= "exponential equation involving the polution(P) and the time(t)";
    $question .= " in years.<br>  At t = 0, P = $a, and ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////        Growth/Decay Rate as a Percent             ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $b = rand(20,90);
    $rand = rand(1,2);
    if ($rand == 1)
    {
        $question .= "the pollution decreases by $b% a year.";
        $b = 1 - ($b / 100);
    }
    else
    {
        $question .= "the pollution increases by $b% a year.";
        $b = 1 + ($b / 100);
    }
    $numerator = $a;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,0,0,10);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #213 Generator              ////
////            Exponential Models 6                   ////
////            Write the Equation 3                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_213()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(50,15000);
    $question = "The pollution level in a certain lake can be represented by an<br> ";
    $question .= "exponential equation involving the polution(P) and the time(t)";
    $question .= " in years.<br>  At t = 0, P = $a, and ";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Growth rate as words                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $b = rand(2,4);
    if ($b == 2)
    {
        $question .= "the pollution doubles each year.";
    }
    else if ($b == 3)
    {
        $question .= "the pollution triples each year.";
    }
    else if ($b == 4)
    {
        $question .= "the pollution quadruples each year.";
    }
    $numerator = $a;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,0,0,10);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #214 Generator              ////
////      Exponential Models - Word Problems 1         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_214()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(50,400);
    $b = rand(10,40);
    $c = rand(5,20);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               Lake Pollution                      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $pol = rand(1,4);
    if ($pol == 1)
    {
        $pol = "pizza boxes";
    }
    else if ($pol == 2)
    {
        $pol = "gobbledygook";
    }
    else if ($pol == 3)
    {
        $pol = "college algebra text books";
    }
    else
    {
        $pol = "castanets";
    }
    $question = "A bunch of hooligans dump $a pounds of ";
    $question .= "$pol into a lake.  If the $pol dissipates ";
    $question .= "at a rate of $b% a year, how many ";
    $question .= "pounds of $pol will be left ";
    $question .= "after $c years?";
    $b = 1 - ($b / 100);
    $numerator = $a * pow($b,$c);
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #215 Generator              ////
////      Exponential Models - Word Problems 2         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_215()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(50,400);
    $b = rand(10,40);
    $c = rand(5,20);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          Population on a island                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $an = rand(1,6);
    if ($an == 1)
    {
        $an = "rabbits";
    }
    else if ($an == 2)
    {
        $an = "pink elephants";
    }
    else if ($an == 3)
    {
        $an = "hippos";
    }
    else if ($an == 4)
    {
        $an = "rainbow snakes";
    }
    else if ($an == 5)
    {
        $an = "penguins";
    }
    else
    {
        $an = "dodo birds";
    }
    $question = "$a $an are shipped to an island.";
    $question .= " If the $an have a growth rate of $b% a year, ";
    $question .= "how many will be on the island in $c years?";
    $b = 1 + ($b / 100);
    $numerator = $a * pow($b,$c);
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = floor($numerator);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #216 Generator              ////
////      Exponential Models - Word Problems 3         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_216()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(50,400);
    $b = rand(10,40);
    $c = rand(5,20);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               New Substance                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $question = "A new substance is discovered by scientists.";
    $question .= " If the new substance decays at a rate of ";
    $question .= "$b% an hour.  How much will be left from a ";
    $question .= "sample of $a after $c hours?";
    $b = 1 - ($b / 100);
    $numerator = $a * pow($b,$c);
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #217 Generator              ////
////      Exponential Models - Word Problems 4         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_217()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(35,55) * 1000;
    $b = $a - (rand(5,10) * 1000);
    $c = rand(30,100) / 10;
    $d = $c + rand(20,35) / 10;
    $question = $a.$split.$b.$split.$c.$split.$d;
    $c = 1 + $c / 100;
    $d = 1 + $d / 100;
    $salary_1 = $a * pow($c,7);
    $salary_2 = $b * pow($d,7);
    if ($salary_1 > $salary_2)
    {
         $numerator = 1;
    }
    else if ($salary_1 < $salary_2)
    {
         $numerator = 2;
    }
    else
    {
         $numerator = 3;
    }
    $answer = array($question,$numerator,$denominator,0,0,11);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #218 Generator              ////
////           Linear vs. Exponential 1                ////
////             Identify Growth Type                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
function gen_218()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $randy = rand(1,4);

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               Linear Growth                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    if ($randy == 1)
    {
        $a = rand(20,120);
        $b = rand(1,20);
        $value = array();
        for ($i = 0; $i < 5; $i++)
        {
            $value[] = $a * $i + $b;
        }
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                Linear Decay                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else if ($randy == 2)
    {
        $a = rand(20,99) / 100 ;
        $b = rand(1,5);
        $value = array();
        for ($i = 0; $i < 5; $i++)
        {
            $value[] = (-1) * $a * $i + $b;
        }
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Exponential Growth                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else if ($randy == 3)
    {
        $a = rand(1,20);
        $b = rand(2,10);
        $value = array();
        for ($i = 0; $i < 5; $i++)
        {
            $value[] = $a * (pow($b,$i));
        }
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Exponential Decay                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    else // ($randy == 4)
    {
        $a = rand(1,20);
        $b = 1 / rand(2,5);
        $value = array();
        for ($i = 0; $i < 5; $i++)
        {
            $value[] = $a * (pow($b,$i));
        }
    }
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $i.$split.$value[$i].$split;
    }
    $numerator = $randy;
    $answer = array($question,$numerator,$denominator,0,0,12);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #219 Generator              ////
////           Liner vs. Exponential 2                 ////
////              Compare Salary                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_219()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(35,55) * 1000;
    $b = $a - (rand(5,15) * 1000);
    $c = 500 * rand(1,3);
    $d = rand(1,2) * 3;
    $e = rand(60,100) / 10;
    $question = $a.$split.$b.$split.$c.$split.$d.$split.$e;
    $c = $c * 12 / $d;
    $e = 1 + $e / 100;
    $salary_1 = $a + $c * 7;
    $salary_2 = $b * pow($e,7);
    if ($salary_1 > $salary_2)
    {
         $numerator = 1;
    }
    else if ($salary_1 < $salary_2)
    {
         $numerator = 2;
    }
    else
    {
         $numerator = 3;
    }
    $answer = array($question,$numerator,$denominator,0,0,11);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #220 Generator              ////
////         Find the Exponential Equation 1           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_220()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(10,100);
    $question = "0".$split.$a.$split;
    $numerator = $a;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Exponential Growth                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $b = rand(150,300) / 100;
    $temp = $b * $a;
    $question .= "1".$split.$temp;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,1,1,10);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #221 Generator              ////
////         Find the Exponential Equation 2           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_221()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(10,100);
    $question = "0".$split.$a.$split;
    $numerator = $a;
    $b = rand(20,90) / 100;
    $temp = $b * $a;
    $question .= "1".$split.$temp;
    $denominator = $b;
    $answer = array($question,$numerator,$denominator,1,1,10);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #222 Generator              ////
////             Compund Interest 1                    ////
////             Find the Equation 1                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_222()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(1000,10000);
    $b = rand(10,150) / 10;
    $question = "If you invested $$a in a bank account that earns";
    $question .= " a rate of $b% compounded annually, how much money";
    $question .= " would be in the account after t years?";
    $numerator = $a;
    $denominator = 1 + ($b / 100);
    $answer = array($question,$numerator,$denominator,0,0,13);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #223 Generator              ////
////             Compund Interest 2                    ////
////             Find the Equation 2                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_223()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////        Compunded Semi-annualy, quarterly          ////
    ////              monthly or daily                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1000,10000);
    $b = rand(10,150) / 10;
    $c = rand(1,4);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "semi_annually";
        $times = 2;
    }
    else if ($c == 2)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 3)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 4)
    {
        $compounded = "daily";
        $times = 356;
    }
    $question = "If you invested $$a in a bank account that earns";
    $question .= " a rate of $b% compounded $compounded, how much money";
    $question .= " would be in the account after t years?";
    $numerator = $a;
    $b = $b / 100;
    $denominator = 1 + ($b / $times);
    $denominator = pow($denominator,$times);
    $denominator = round($denominator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,13);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #224 Generator              ////
////             Compund Interest 3                    ////
////                 Find A(0)                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_224()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(100000,500000);
    $b = rand(10,150) / 10;
    $t = rand(15,25);
    $c = rand(1,5);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "annually";
        $times = 1;
    }
    else if ($c == 2)
    {
        $compounded = "semi-annually";
        $times = 2;
    }
    else if ($c == 3)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 4)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 5)
    {
        $compounded = "daily";
        $times = 365;
    }
    $question = "How much would you have to invest today at ";
    $question .= "$b% compounded $compounded to have $$a in $t years?";
    $b = $b / 100;
    $rate = 1 + ($b / $times);
    $effective_rate = pow($rate,$times);
    $divisor = pow($effective_rate,$t);
    $numerator = $a / $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #225 Generator              ////
////             Compund Interest 4                    ////
////                 Find A(t)                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_225()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1000,5000);
    $b = rand(10,150) / 10;
    $t = rand(15,25);
    $c = rand(1,5);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "annually";
        $times = 1;
    }
    else if ($c == 2)
    {
        $compounded = "semi-annually";
        $times = 2;
    }
    else if ($c == 3)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 4)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 5)
    {
        $compounded = "daily";
        $times = 365;
    }
    $question = "How much would you have in your bank account in $t years if you invested";
    $question .= " $$a today at $b% compounded $compounded?";
    $b = $b / 100;
    $rate = 1 + ($b / $times);
    $effective_rate = pow($rate,$times);
    $divisor = pow($effective_rate,$t);
    $numerator = $a * $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #226 Generator              ////
////             Compund Interest 5                    ////
////                   Find t                          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_226()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1000,5000);
    $b = rand(10,150) / 10;
    $d = rand(15000,250000);
    $c = rand(1,5);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "annually";
        $times = 1;
    }
    else if ($c == 2)
    {
        $compounded = "semi-annually";
        $times = 2;
    }
    else if ($c == 3)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 4)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 5)
    {
        $compounded = "daily";
        $times = 365;
    }
    $question = "About how long would it take for $$a to grow to $$d if ";
    $question .= "it is invested in a bank account earning $b% compounded $compounded?";
    $question .= "<br><i>Please round to the nearest second decimal place</i>";
    $b = $b / 100;
    $rate = 1 + ($b / $times);
    $LHS = $d / $a;
    $LHS = log($LHS);
    $divisor = $times * log($rate);
    $numerator = $LHS / $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = $numerator." years";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #227 Generator              ////
////             Compund Interest 6                    ////
////        Find the effective interest rate           ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_227()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $b = rand(10,150) / 10;
    $c = rand(2,5);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "annually";
        $times = 1;
    }
    else if ($c == 2)
    {
        $compounded = "semi-annually";
        $times = 2;
    }
    else if ($c == 3)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 4)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 5)
    {
        $compounded = "daily";
        $times = 365;
    }
    $question = "What is the effective interest rate of a bank account that advertises ";
    $question .= "a rate of $b% compounded $compounded?";
    $b = $b / 100;
    $rate = 1 + ($b / $times);
    $effective_rate = pow($rate,$times) - 1;
    $numerator = $effective_rate * 100;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = $numerator."%";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////  Question template for Expand the log problems    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

/*
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a"."#";
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a"."#";
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a"."#";
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a"."#";
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a"."#";
        $numerator .= "n/a".$split."n/a".$split."n/a".$split."n/a".$split."n/a";
*/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #228 Generator              ////
////              Expand the Log 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_228()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "x";
    }
    else if ($var == 2)
    {
        $var = "y";
    }
    else if ($var == 3)
    {
        $var = "z";
    }
    else if ($var == 4)
    {
        $var = "t";
    }
    else // ($var == 5)
    {
        $var = "a";
    }
    $base = rand(1,10);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                  log ax                           ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,15);
    if ($base == 1)
    {
        $question = "ln".$a.$var;
        $base = "e";
        $numerator .= "ln($a)+ln($var)";
    }
    else if ($base == 10)
    {
        $question = "log(".$a.$var.")";
        $numerator .= "log($a)+log($var)";
    }else
    {
        $question = "log[".$base."](".$a.$var.")";
        $numerator .= "log[$base]($a)+log[$base]($var)";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #229 Generator              ////
////              Expand the Log 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_229()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "x";
    }
    else if ($var == 2)
    {
        $var = "y";
    }
    else if ($var == 3)
    {
        $var = "z";
    }
    else if ($var == 4)
    {
        $var = "t";
    }
    else // ($var == 5)
    {
        $var = "a";
    }
    $base = rand(1,10);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           log (a/x) or log (x/a)                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,15);
    $up_or_down = rand(1,2);
    if ($up_or_down == 1)
    {
        if ($base == 1)
        {
            $question = "ln(".$a."/".$var.")";
            $base = "e";
            $numerator .= "ln($a)-ln($var)";
        }
        else if ($base == 10)
        {
            $question = "log(".$a."/".$var.")";
            $numerator .= "log($a)-log($var)";
        }
        else
        {
            $question = "log[".$base."](".$a."/".$var.")";
            $numerator .= "log[$base]($a)-log[$base]($var)";
        }
        
    }
    else
    {
        if ($base == 1)
        {
            $question = "ln(".$a."/".$var.")";
            $base = "e";
            $numerator .= "ln($a)-ln($var)";
        }
        else if ($base == 10)
        {
             $question = "log(".$a."/".$var.")";
             $numerator .= "log($a)-log($var)";
        }
        else
        {
           $question = "log[".$base."](".$a."/".$var.")";
           $numerator .= "log[$base]($a)-log[$base]($var)";
        }
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #230 Generator              ////
////              Expand the Log 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_230()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "x";
    }
    else if ($var == 2)
    {
        $var = "y";
    }
    else if ($var == 3)
    {
        $var = "z";
    }
    else if ($var == 4)
    {
        $var = "t";
    }
    else // ($var == 5)
    {
        $var = "a";
    }
    $base = rand(1,10);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                 log x^a                           ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,15);
    rand_switch_sign($a,3);
    if ($base == 1)
    {
        $question = "ln ".$var."^(".$a.")";
        $base = "e";
        $numerator .= "$a*ln($var)";
    }
        else if ($base == 10)
    {
        $question = "log(".$var."^(".$a.")";
        $numerator .= "$a*log($var)";
    }
    else
    {
        $question = "log[".$base."](".$var."^(".$a."))";
        $numerator .= "$a*log[$base]($var)";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #231 Generator              ////
////              Expand the Log 4                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_231()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $var = rand(1,5);
    if ($var == 1)
    {
        $var = "x";
    }
    else if ($var == 2)
    {
        $var = "y";
    }
    else if ($var == 3)
    {
        $var = "z";
    }
    else if ($var == 4)
    {
        $var = "t";
    }
    else // ($var == 5)
    {
        $var = "a";
    }
    $base = rand(1,10);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                log root(a)                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,3);
    if ($base == 1)
    {
        $question = "ln*";
        $base = "e";
        $numerator .="1/$a*ln($var)";
    }
    else if ($base == 10)
    {
        $question = "log(";
        $numerator .="1/$a*log($var)";
    }
    else
    {
        $question = "log[".$base."](";
        $numerator .="1/$a*log[$base]($var)";
    }
    if ($a == 2)
    {
        $question .= "sqrt($var)";
    }
    else
    {
        $question .= "root(".$var.",3)";
    }
	  if ($base != "e")
    {
      $question .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #232 Generator              ////
////              Expand the Log 5                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_232()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $base = rand(1,10);
    $a = rand(2,3);
    if ($base == 1)
    {
        $question = "ln*".$split;
        $base = "e";
        $numerator .= "1/$a*ln(x$b)";
    }
    else if ($base == 10)
    {
        $question = "log(";
        $numerator .= "1/$a*log(x$b)";
    }
    else
    {
        $question = "log[".$base."](";
        $numerator .= "1/$a*log[$base](x$b)";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////                log root(x + a)                    ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    
    $b = rand(1,15);
    rand_switch_sign($b,3);
    coeff_prep($b,0);
    if ($a == 2)
    {
        $question .= "sqrt(x".$b.")";
    }
    else
    {
        $question .= "root(x".$b.",3)";
    }
	if ($base != "e")
    {
      $question .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #233 Generator              ////
////              Expand the Log 6                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_233()
{
    $question = "";
    $numerator = "";
    $nume="";
    $denominator = "1";
    $base = rand(1,10);
    $a = rand(1,9);
    $b = rand(1,9);
    if ($base == 1)
    {
        $question = "ln*".$split;
        $base = "e";
        $nume="ln";
        
    }
    else if ($base == 10)
    {
        $question = "log(";
        $nume="log(";
    }
    else
    {
        $question = "log[".$base."](";
        $nume="log[".$base."](";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            log (x+c)^a(x+d)^b                     ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    
    $c = rand(1,9);
    $d = rand(1,9);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $c = $c + 1;
    if ($c == $d)
    {
        $c = $c + 1;
    }
    if ($c == 0)
    {
        $exp1 = "x";
    }
    else
    {
        coeff_prep($c,0);
        $exp1 = "x".$c;
    }
    coeff_prep($d,0);
    $exp2 = "x".$d;
    if ($a != 1)
    {
        $question .= "(".$exp1.")^($a)*";
        $numerator="$a*$nume($exp1)";
    }
    else
    {
        $question .= "(".$exp1.")*";
        $numerator="$nume($exp1)";
    }
    if ($base != "e")
    {
      $numerator .= ")";
    }
    if ($b != 1)
    {
        $question .= "(".$exp2.")^($b)";
        $numerator.="+$b*$nume($exp2)";
    }
    else
    {
        $question .= "(".$exp2.")";
       $numerator.="+$nume($exp2)";
    }
	  if ($base != "e")
    {
      $question .= ")";
      $numerator .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #234 Generator              ////
////              Expand the Log 7                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_234()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $base = rand(1,10);
    if ($base == 1)
    {
        $question = "ln*".$split;
        $base = "e";
        $nume="ln";
        
    }
    else if ($base == 10)
    {
        $question = "log(";
        $nume="log(";
    }
    else
    {
        $question = "log[".$base."](";
        $nume="log[".$base."](";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            log (x+a)(x+b) / x^c                   ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(2,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    if ($a == $b)
    {
        $a++;
        if ($a == 0)
        {
            $a++;
        }
    }
    $coeff1 = $a + $b;
    $coeff2 = $a * $b;
    $exp = "x^2 ";
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        $exp .= $coeff1."x ";
    }
    coeff_prep($coeff2,0);
    $exp .= $coeff2;
    coeff_prep($a,0);
    coeff_prep($b,0);
    $exp1 = "x".$a;
    $exp2 = "x".$b;
    $question .="(".$exp.")/(x^".$c.")";
	  if ($base != "e")
    {
      $question .= ")";
      $numerator="$nume($exp1))+$nume($exp2))-$c*$nume(x))";
    }else
    {
      $numerator="$nume($exp1)+$nume($exp2)-$c*$nume(x)";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #235 Generator              ////
////              Expand the Log 8                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_235()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $base = rand(1,10);
    if ($base == 1)
    {
        $question = "ln*".$split;
        $base = "e";
        $nume="ln";   
    }
    else if ($base == 10)
    {
        $question = "log(";
        $nume="log(";
    }
    else
    {
        $question = "log[".$base."](";
        $nume="log[".$base."](";
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////          log x^a / root(x^2 + b)                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,3);
    $question .= "(x^".$a.")/";
    if ($c == 2)
    {
        $question .= "sqrt(x^2 + $b)";
    }
    else
    {
        $question .= "root(x^2 + $b,3)";
    }
  	if($base != "e")
    {
      $question .= ")";
      $numerator="$a*$nume(x))-1/$c*$nume(x^2+b))";
    }else
    {
      $numerator="$a*$nume(x)-1/$c*$nume(x^2+b)";
    }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #236 Generator              ////
////               Expand the Log 9                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_236()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $base = rand(1,10);
    if ($base == 1)
    {
        $question = "ln(";
        $base = "e";
        $nume="ln(";   
    }
    else if ($base == 10)
    {
        $question = "log(";
        $nume="log(";
    }
    else
    {
        $question = "log[".$base."](";
        $nume="log[".$base."](";
    }
    $a = rand(1,11);
    $b = rand(1,11);
    $c = rand(1,11);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    $x_on_top = TRUE;
    $y_on_top = TRUE;
    $z_on_top = TRUE;
    if ($a < 0)
    {
        $x_on_top = FALSE;
        $a = (-1) * $a;
    }
    if ($b < 0)
    {
        $y_on_top = FALSE;
        $b = (-1) * $b;
    }
    if ($c < 0)
    {
        $z_on_top = FALSE;
        $c = (-1) * $c;
    }
    if ($a == 11)
    {
        $x_exp = "*sqrt(x)";
    }
    else if ($a == 1)
    {
        $x_exp = "x";
    }
    else
    {
        $x_exp = "x^$a";
    }
    if ($b == 11)
    {
        $y_exp = "*sqrt(y)";
    }
    else if ($b == 1)
    {
        $y_exp = "y";
    }
    else
    {
        $y_exp = "y^$b";
    }
    if ($c == 11)
    {
        $z_exp = "*sqrt(z)";
    }
    else if ($c == 1)
    {
        $z_exp = "z";
    }
    else
    {
        $z_exp = "z^$c";
    }
    $num = "";
    $denom = "";
    if ($x_on_top == TRUE)
    {
        $num .= $x_exp;
    }
    else
    {
        $a = $a * (-1);
        $denom .= $x_exp;
    }

    if ($y_on_top == TRUE)
    {
        $num .= $y_exp;
    }
    else
    {
        $b = $b * (-1);
        $denom .= $y_exp;
    }
    if ($z_on_top == TRUE)
    {
        $num .= $z_exp;
    }
    else
    {
        $c = $c * (-1);
        $denom .= $z_exp;
    }
    if ($num == "")
    {
        $num = "1";
    }
    if ($denom == "")
    {
        $question .= $num;
    }else{
      $question .= "(".$num.")/(".$denom.")";
	  }
   $b1=$b;
   if($b>0)
   {
   	$b1="+".$b;
   }
   $c1=$c;
   if($c>0)
   {
   	$c1="+".$c;
   }
  if ($a == 11)
  {
    if ($b == 11)
    {
        if ($c == 11)
        {
         $numerator .= "1/2*$nume x)+1/2*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "1/2*$nume x)+1/2*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "1/2*$nume x)+1/2*$nume y)+$c1*$nume z)";
       }
    }
    else if ($b == -11)
    {
       if ($c == 11)
       {
         $numerator .= "1/2*$nume x)-1/2*$nume y)+1/2*$nume z)";
       }
       else if ($c == -11)
       {
         $numerator .= "1/2*$nume x)-1/2*$nume y)-1/2*$nume z)";
       }
       else
       {
       	 $numerator .= "1/2*$nume x)-1/2*$nume y)$c1*$nume z)";
       }
    }
    else
    {
        if ($c == 11)
        {
         $numerator .= "1/2*$nume x)$b1*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "1/2*$nume x)$b1*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "1/2*$nume x)$b1*$nume y)$c1*$nume z)";
       }
    }
  }
  else if ($a == -11)
  {
    if ($b == 11)
    {
        if ($c == 11)
        {
         $numerator .= "-1/2*$nume x)+1/2*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "-1/2*$nume x)+1/2*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "-1/2*$nume x)+1/2*$nume y)$c1*$nume z)";
       }
    }
    else if ($b == -11)
    {
       if ($c == 11)
       {
         $numerator .= "-1/2*$nume x)-1/2*$nume y)+1/2*$nume z)";
       }
       else if ($c == -11)
       {
         $numerator .= "-1/2*$nume x)-1/2*$nume y)-1/2*$nume z)";
       }
       else
       {
       	 $numerator .= "-1/2*$nume x)-1/2*$nume y)$c1*$nume z)";
       }
    }
    else
    {
        if ($c == 11)
        {
         $numerator .= "-1/2*$nume x)$b1*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "-1/2*$nume x)$b1*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "-1/2*$nume x)$b1*$nume y)$c1*$nume z)";
       }
    }
  }
  else
  {
    if ($b == 11)
    {
        if ($c == 11)
        {
         $numerator .= "$a*$nume x)+1/2*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "$a*$nume x)+1/2*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "$a*$nume x)+1/2*$nume y)$c1*$nume z)";
       }
    }
    else if ($b == -11)
    {
       if ($c == 11)
       {
         $numerator .= "$a*$nume x)-1/2*$nume y)+1/2*$nume z)";
       }
       else if ($c == -11)
       {
         $numerator .= "$a*$nume x)-1/2*$nume y)-1/2*$nume z)";
       }
       else
       {
       	 $numerator .= "$a*$nume x)-1/2*$nume y)$c1*$nume z)";
       }
    }
    else
    {
        if ($c == 11)
        {
         $numerator .= "$a*$nume x)$b1*$nume y)+1/2*$nume z)";
        }
        else if ($c == -11)
        {
         $numerator .= "$a*$nume x)$b1*$nume y)-1/2*$nume z)";
        }
       else
       {
       	 $numerator .= "$a*$nume x)$b1*$nume y)$c1*$nume z)";
       }
    }
  }
    $answer = array($question,$numerator,$denominator,0,0,14);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #237 Generator              ////
////            Write as a Single Log 1                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_237()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $log_base = "";
    $base = rand(1,10);
    if ($base == 1)
    {
        $log_base= "ln";
        $base = "e";
    }
    else if ($base == 10)
    {
        $log_base = "log(";
    }
    else
    {
        $log_base = "log[".$base."](";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(1,10);
    $b = rand(1,5);
    if ($b > 3)
    {
        $c = 2;
    }
    else if ($b == 3)
    {
        $c = rand(2,3);
    }
    else
    {
        $c = rand(2,9);
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($a > 0)
    {
       if ($a == 1)
       {
          $num1 = "x";
       }
       else
       {
          $num1 = "x^($a)";
       }
       if ($b > 0)
       {
        $num2 = pow($c,$b);
        $numerator = "$log_base($num2*$num1)";
       }
       else
       {
        $b = $b * (-1);
        $denom2 = pow($c,$b);
        $b = $b * (-1);
        $numerator = "$log_base($num1/$denom2)";
       }
    }
    else
    {
        $a = $a * (-1);
        if ($a == 1)
        {
            $denom1 = "x";
        }
        else
        {
            $denom1 = "x^($a)";
        }
        $a = $a * (-1);
        if ($b > 0)
        {
        $num2 = pow($c,$b);
        $numerator = "$log_base($num2/$denom1)";
       }
       else
       {
        $b = $b * (-1);
        $denom2 = pow($c,$b);
        $b = $b * (-1);
        $numerator = "$log_base(1/($denom2*$denom1))";
       }
    }
   
    $rand = rand(1,2);
    if ($rand == 1)
    {
        coeff_prep($b);
        $question .= $a.$log_base."(x)";
        
	       if ($base != "e")
        {
          $question .= ")";
        }
		    $question .=$b.$log_base."($c)";
    }
    else
    {
        coeff_prep($a);
        $question .= $b.$log_base."($c)";
		    if ($base != "e")
        {
          $question .= ")";
        }
		    $question .=$a.$log_base."(x)";
    }
	  if ($base != "e")
    {
        $question .= ")";
        $numerator .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #238 Generator              ////
////            Write as a Single Log 2                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_238()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $log_base = "";
    $base = rand(1,10);
    if ($base == 1)
    {
        $log_base= "ln";
        $base = "e";
    }
    else if ($base == 10)
    {
        $log_base = "log(";
    }
    else
    {
        $log_base = "log[".$base."](";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    if ($a == $b)
    {
        $a++;
    }
    coeff_prep($a,0);
    coeff_prep($b,0);
    $exp1 = "( x ".$a." )";
    $exp2 = "( x ".$b." )";
    if ($c == 1)
    {
      if ($d == 1)
      {
          $numerator = "$log_base($exp1*$exp2)";
      }
      else if ($d == -1)
      {
          $numerator = "$log_base($exp1/$exp2)";
      }
      else if ($d > 0)
      {
          $numerator = "$log_base($exp1*$exp2^$d)";
      }
      else
      {
          $numerator = "$log_base($exp1/$exp2^$d)";
      }
    }
    else if ($c == -1)
    {
      if ($d == 1)
      {
          $numerator = "$log_base($exp2/$exp1)";
      }
      else if ($d == -1)
      {
          $numerator = "$log_base(1/$exp1*$exp2)";
      }
      else if ($d > 0)
      {
          $numerator = "$log_base($exp2^$d/$exp1)";
      }
      else
      {
          $numerator = "$log_base(1/($exp1*$exp2^$d))";
      }
    }
    else if ($c > 0)
    {
      if ($d == 1)
      {
          $numerator = "$log_base($exp1^$c*$exp2)";
      }
      else if ($d == -1)
      {
          $numerator = "$log_base($exp1^$c/$exp2)";
      }
      else if ($d > 0)
      {
          $numerator = "$log_base($exp1^$c*$exp2^$d)";
      }
      else
      {
          $numerator = "$log_base($exp1^$c/$exp2^$d)";
      }
    }
    else
    {
      if ($d == 1)
      {
          $numerator = "$log_base($exp2/$exp1^$c)";
      }
      else if ($d == -1)
      {
          $numerator = "$log_base(1/($exp1^$c*$exp2))";
      }
      else if ($d > 0)
      {
          $numerator = "$log_base($exp2^$d/$exp1^$c)";
      }
      else
      {
          $numerator = "$log_base(1/($exp1^$c*$exp2^$d))";
      }
    }
    coeff_prep($d);
    $question = $c.$log_base."$exp1";
	  if($base != "e")
    {
       $question .= ")";
        $numerator .= ")";
    }
	  $question .=$d.$log_base."$exp2";
	  if($base != "e")
    {
      $question .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #239 Generator              ////
////            Write as a Single Log 3                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_239()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $log_base = "";
    $base = rand(1,10);
     if ($base == 1)
    {
        $log_base= "ln";
        $base = "e";
    }
    else if ($base == 10)
    {
        $log_base = "log(";
    }
    else
    {
        $log_base = "log[".$base."](";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,9);
    rand_switch_sign($a,2);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    if ($a > 0)
    {
      if ($b > 0)
      {
          if ($c > 0)
          {
           $numerator = "$log_base(a^$a*b^$b*c^$c)";
          }
          else
          {
           $c = $c * (-1);
           $numerator = "$log_base(a^$a*b^$b/c^$c)";
           $c = $c * (-1);
         }
      }
      else
      {
          $b = $b * (-1);
          if ($c > 0)
          {
           $numerator = "$log_base(a^$a*c^$c/b^$b)";
          }
          else
          {
           $c = $c * (-1);
           $numerator = "$log_base(a^$a/(b^$b*c^$c))";
           $c = $c * (-1);
          }
          $b = $b * (-1);
      }
    }
    else
    {
        $a = $a * (-1);
        if ($b > 0)
        {
          if ($c > 0)
          {
           $numerator = "$log_base(b^$b*c^$c/a^$a)";
          }
          else
          {
           $c = $c * (-1);
           $numerator = "$log_base(b^$b/(a^$a*c^$c))";
           $c = $c * (-1);
         }
       }
       else
       {
          $b = $b * (-1);
          if ($c > 0)
          {
           $numerator = "$log_base(c^$c/(a^$a*b^$b))";
          }
          else
          {
           $c = $c * (-1);
           $numerator = "$log_base(1/(a^$a*b^$b*c^$c))";
           $c = $c * (-1);
          }
          $b = $b * (-1);
        }
        $a = $a * (-1);
    }

    coeff_prep($b);
    coeff_prep($c);
    $rand = rand(1,2);
	  if ($base != "e")
    {
       $pa1 = ")";
       $numerator .= ")";
    }else
	  {
	   $pa1 = " ";
	  }
	
    if ($rand == 1)
    {
        $question .= $a.$log_base."(a)".$pa1.$b.$log_base."(b)".$pa1.$c.$log_base."(c)".$pa1;
    }
    else // ($rand == 2)
    {
        $question .= $a.$log_base."(a)".$pa1.$c.$log_base."(c)".$pa1.$b.$log_base."(b)".$pa1;
    }
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #240 Generator              ////
////            Write as a Single Log 4                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_240()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $log_base = "";
    $base = rand(1,10);
    if ($base == 1)
    {
        $log_base= "ln";
        $base = "e";
    }
    else if ($base == 10)
    {
        $log_base = "log(";
    }
    else
    {
        $log_base = "log[".$base."](";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(2,3);
    $b = rand(1,4);
    $b = r_prime($b);
    $c = 1;
    rand_switch_sign($c,2);
    $question .= "$c/$a*$log_base( $b x )";
    if ($a == 2)
    {
        if ($c < 0)
        {
         $numerator = "$log_base(1/sqrt($b*x))";
        }
        else
        {
         $numerator = "$log_base(sqrt($b*x))";
        }
    }
    else
    {
        if ($c < 0)
        {
         $numerator = "$log_base(1/root($b*x,3))";
        }
        else
        {
         $numerator = "$log_base(root($b*x,3))";
        }
    }
    if ($base != "e")
    {
       $numerator .= ")";
    }
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #241 Generator              ////
////           Write as a Single Log 5                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_241()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $base = rand(1,10);
     if ($base == 1)
    {
        $log_base= "ln";
        $base = "e";
    }
    else if ($base == 10)
    {
        $log_base = "log";
    }
    else
    {
        $log_base = "log[".$base."]";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(2,5);
    $b = rand(2,4);
    $c = rand(2,4);
    $d = rand(2,9);
    $e = rand(1,9);
    $f = rand(1,9);
    $g = rand(1,9);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    rand_switch_sign($f,2);
    rand_switch_sign($g,2);
    if ($e == $f)
    {
        $e++;
        if ($e == 0)
        {
            $e++;
        }
    }
    if ($g == $f)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
    }
    if ($g == $e)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
        if ($g == $f)
        {
            $g = $g - 1;
            if ($g == 0)
            {
                $g = $g - 1;
            }
        }
    }
    coeff_prep($e,0);
    coeff_prep($f,0);
    coeff_prep($g,0);
    $exp1 = "( x ".$e.")";
    $exp2 = "( x ".$f.")";
    $exp3 = "( x ".$g.")";
    $temp1=$exp1."^".abs($b * $a);
    $temp2=$exp2."^".abs($c * $a);
    $temp3=$exp3."^".abs($d);
    if ($b < 0)
    {
        if ($c < 0)
        {
         if ($d < 0)
         {
          $numerator = "$log_base(1/($temp1*$temp2*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp3/($temp1*$temp2))";
         }
       }
       else
       {
         if ($d < 0)
         {
          $numerator = "$log_base($temp2/($temp1*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp2*$temp3/$temp1)";
         }
       }
    }
    else
    {
        if ($c < 0)
        {
         if ($d < 0)
         {
          $numerator = "$log_base($temp1/($temp2*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp1*$temp3/$temp2)";
         }
       }
       else
       {
         if ($d < 0)
         {
          $numerator = "$log_base($temp1*$temp2/$temp3)";
         }
         else
         {
          $numerator = "$log_base($temp1*$temp2*$temp3)";
         }
       }
    }
    if ($base != "e")
    {
       $numerator .= ")";
    }
    coeff_prep($c);
    coeff_prep($d);
    if($base=="e")
      $question .= $a."*[".$b."*".$log_base.$exp1.$c."*".$log_base.$exp2."]".$d."*".$log_base.$exp3;
    else
      $question .= $a."*[".$b."*".$log_base."(".$exp1.")".$c."*".$log_base."(".$exp2.")]".$d."*".$log_base."(".$exp3.")";
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #242 Generator              ////
////           Write as a Single Log 6                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_242()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $base = rand(1,10);
    if ($base == 1)
    {
        $base = "e";
        $log_base = " ln ";
    }
    else if ($base == 10)
    {
        $log_base = " log ";
    }
    else
    {
        $log_base = " log[ $base ]";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $a = rand(2,5);
    $b = rand(2,4);
    $c = rand(2,4);
    $d = rand(2,4);
    $e = rand(1,9);
    $f = rand(1,9);
    $g = rand(1,9);
    rand_switch_sign($b,2);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    rand_switch_sign($f,2);
    rand_switch_sign($g,2);
    if ($e == $f)
    {
        $e++;
        if ($e == 0)
        {
            $e++;
        }
    }
    if ($g == $f)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
    }
    if ($g == $e)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
        if ($g == $f)
        {
            $g = $g - 1;
            if ($g == 0)
            {
                $g = $g - 1;
            }
        }
    }
    coeff_prep($e,0);
    coeff_prep($f,0);
    coeff_prep($g,0);
    $exp1 = "( x ".$e.")";
    $exp2 = "( x ".$f.")";
    $exp3 = "( x ".$g.")";
    $temp1=$exp1."^".abs($b * $a);
    $temp2=$exp2."^".abs($c * $a);
    $temp3=$exp3."^".abs($d * $a);
    if ($b < 0)
    {
        if ($c < 0)
        {
         if ($d < 0)
         {
          $numerator = "$log_base(1/($temp1*$temp2*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp3/($temp1*$temp2))";
         }
       }
       else
       {
         if ($d < 0)
         {
          $numerator = "$log_base($temp2/($temp1*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp2*$temp3/$temp1)";
         }
       }
    }
    else
    {
        if ($c < 0)
        {
         if ($d < 0)
         {
          $numerator = "$log_base($temp1/($temp2*$temp3))";
         }
         else
         {
          $numerator = "$log_base($temp1*$temp3/$temp2)";
         }
       }
       else
       {
         if ($d < 0)
         {
          $numerator = "$log_base($temp1*$temp2/$temp3)";
         }
         else
         {
          $numerator = "$log_base($temp1*$temp2*$temp3)";
         }
       }
    }
    if ($base != "e")
    {
       $numerator .= ")";
    }
    coeff_prep($c);
    coeff_prep($d);
    if($base=="e")
     $question .= $a."*[".$b."*".$log_base.$exp1.$c."*".$log_base.$exp2.$d."*".$log_base.$exp3."]";
    else
     $question .= $a."*[".$b."*".$log_base."(".$exp1.")".$c."*".$log_base."(".$exp2.")".$d."*".$log_base."(".$exp3.")]";
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #243 Generator              ////
////           Write as a Single Log 7                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_243()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $line_split = '##';
    $base = rand(1,10);
    if ($base == 1)
    {
        $base = "e";
        $log_base = " ln ";
    }
    else if ($base == 10)
    {
        $log_base = " log ";
    }
    else
    {
        $log_base = " log[$base]";
    }
    $num1 = 1;
    $num2 = 1;
    $num3 = 1;
    $denom1 = 1;
    $denom2 = 1;
    $denom3 = 1;
    $c = 2 * rand(2,4);
    $d = rand(2,9);
    $e = rand(1,9);
    $f = rand(1,9);
    $g = rand(1,9);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    rand_switch_sign($f,2);
    rand_switch_sign($g,2);
    if ($e == $f)
    {
        $e++;
        if ($e == 0)
        {
            $e++;
        }
    }
    if ($g == $f)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
    }
    if ($g == $e)
    {
        $g = $g - 1;
        if ($g == 0)
        {
            $g = $g - 1;
        }
        if ($g == $f)
        {
            $g = $g - 1;
            if ($g == 0)
            {
                $g = $g - 1;
            }
        }
    }
    coeff_prep($e,0);
    coeff_prep($f,0);
    coeff_prep($g,0);
    $exp1 = "( x ".$e.")";
    $exp2 = "( x ".$f.")";
    $exp3 = "( x ".$g.")";
    $temp1="sqrt".$exp1;
    $temp2=$exp2."^".abs($c/2);
    $temp3=$exp3."^".abs($d);
    if ($c < 0)
    {
      if ($d < 0)
      {
       $numerator = "$log_base($temp1/($temp2*$temp3))";
      }
      else
      {
       $numerator = "$log_base($temp1*$temp3/$temp2)";
      }
    }
    else
    {
      if ($d < 0)
      {
       $numerator = "$log_base($temp1*$temp2/$temp3)";
      }
      else
      {
       $numerator = "$log_base($temp1*$temp2*$temp3)";
      }
    }
    if ($base != "e")
    {
       $numerator .= ")";
    }
    coeff_prep($c);
    coeff_prep($d);
    if($base=="e")
     $question .= "1/2*[$log_base $exp1 $c $log_base $exp2 ] $d $log_base $exp3 ";
    else
     $question .= "1/2*[$log_base ( $exp1) $c *$log_base( $exp2 )] $d* $log_base ($exp3 )";
    $answer = array($question,$numerator,$denominator,0,0,15);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #244 Generator              ////
////           Exponential Equations 1                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_244()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,8);
    $b = rand(9,25);
    $c = rand(1,2);
    if ($c == 1)
    {
        $question .= "$a^x= $b";
        $numerator = log($b) / log($a);
    }
    else
    {
        $question .= "$b^~x = $a";
        $numerator = (-1) * log($a) / log($b);
    }
    $numerator = round($numerator + 0.0001 / pow(10,5),5);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #245 Generator              ////
////           Exponential Equations 2                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_245()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,6);
    $b = rand(2,6);
    $c = rand(2,9);
    $d = rand(1,9);
    rand_switch_sign($c,2);
    rand_switch_sign($d,2);
    if ($b == $a)
    {
        $b++;
    }
    $numerator = ((log($b) / log($a)) - $d) / $c;
    coeff_prep($d,0);
    $question .= "$a^($c x $d)= $b";
    $numerator = round($numerator + 0.0001 / pow(10,5),5);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #246 Generator              ////
////           Exponential Equations 3                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_246()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,5);
    $b = rand(3,6);
    if ($a == $b)
    {
        $b++;
    }
    $c = rand(10,100);
    $d = rand(1,2);
    if ($d == 1)
    {
        $question .= "$a^(x / $c)= $b";
        $numerator = $c * log($b) / log($a);
    }
    else
    {
        $question .= "$a^(-x / $c)= $b";
        $numerator = (-1) * $c * log($b) / log($a);
    }
    $numerator = round($numerator + 0.0001 / pow(10,5),5);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #247 Generator              ////
////            Exponential Equations 4                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_247()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,4);
    $b = rand(10,25);
    $c = rand(2,12);
    $question .= "$a e^($c x)= $b";
    $numerator = log($b / $a) / $c;
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #248 Generator              ////
////            Exponential Equations 5                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_248()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(2,200);
    rand_switch_sign($a,3);
    rand_switch_sign($b,2);
    $numerator = (log($c) - $b ) / $a;
    coeff_prep($b,0);
    $question .= "e^($a x $b)= $c";
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #249 Generator              ////
////          Exponential Equations 6                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_249()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,6);
    $b = rand(3,4);
    $d = rand(7,15);
    $c = rand(2,5);
    $question .= "$a + $b^($c x)= $d";
    $numerator = (log($d - $a) / log($b)) / $c;
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #250 Generator              ////
////          Exponential Equations 7                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_250()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,5);
    $b = rand(1,9);
    $c = rand(2,10);
    $d = rand(2,5);
    $e = rand(15,100);
    if ( ($e / $a - $b) < 0)
    {
        $e = $e * $a;
    }
    $question = "$a( $b + $c^($d x) ) = $e";
    $numerator = ( log( ($e / $a) - $b) / log($c) ) / $d;
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #251 Generator              ////
////           Exponential Equations 8                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_251()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,10);
    $b = rand(2,9);
    $c = rand(1,9);
    $d = rand(3,6);
    $e = rand(2,9);
    $f = rand(1,9);
    rand_switch_sign($c,3);
    rand_switch_sign($f,3);
    if ($f == $c)
    {
        $f++;
        if ($f == 0)
        {
            $f++;
        }
    }
    if ($a == $d)
    {
        $a++;
    }
    $numerator = ($f * log($d) - $c * log($a)) / ($b * log($a) - $e * log($d) );
    coeff_prep($c,0);
    coeff_prep($f,0);
    $question .= "$a^($b x $c)= $d^($e x $f)";
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #252 Generator              ////
////           Exponential Equations 9                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_252()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(25,125);
    $b = rand(2,10);
    $question .= "$a/(1 + e^(-x))=$b";
    $numerator = (-1) * log( ($a / $b) - 1);
    $numerator = round($numerator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #253 Generator              ////
////               Log Equations 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_253()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(2,6);
    $base = rand(2,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $question = "$log_base ( x ) = $a";
    $numerator = pow($base,$a);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #254 Generator              ////
////               Log Equations 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_254()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(2,10);
    $b = rand(1,20);
    $base = rand(2,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    rand_switch_sign($b,2);
    $numerator = pow($base,$a) - $b;
    coeff_prep($b,0);
    $question = "$log_base (( x $b )) = $a";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #255 Generator              ////
////               Log Equations 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_255()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $a = rand(2,10);
    $b = rand(1,20);
    $base = rand(2,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    rand_switch_sign($b,2);
    $numerator = pow($base,$a) - $b;
    coeff_prep($b,0);
    $question = "$a - $log_base (( x $b )) = 0";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #256 Generator              ////
////              Log Equations 4                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_256()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $randy = rand(1,3);
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(2,4);
    if ($a == $b)
    {
        $b++;
    }
    $base = rand(2,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    if ($randy == 1)
    {
        $a = $a * (-1);
        $b = $b * (-1);
    }
    else if ($randy == 2)
    {
        $a = $a * (-1);
    }
    $log_number = pow($base,$c);
    $coeff1 = $a + $b;
    $coeff2 = $a * $b + $log_number;
    $question = "$log_base (( x^(2)";
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        $question .= $coeff1." x ";
    }
    coeff_prep($coeff2,0);
    $question .= $coeff2." )) = $c";
    $a = (-1) * $a;
    $b = (-1) * $b;
    $numerator = "$a@@1@@$b@@1@@0";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #257 Generator              ////
////               Log Equations 5                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_257()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $base = rand(1,5);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $a = rand(1,9);
    $b = rand(2,9);
    rand_switch_sign($a,2);
    $num_temp = ((-1) * $a) + $b;
    if ($num_temp < 0 || $num_temp == 0)
    {
        $numerator = "n/a@@n/a@@n/a@@n/a@@1";
    }
    else
    {
        $numerator = "$num_temp@@1@@n/a@@n/a@@0";
    }
    coeff_prep($a,0);
	if($base==1)
	{
        $question = "$log_base ( x ) + $log_base ( x $a) = $log_base ( ".$b."x )";
    }else
	{
	    $question = "$log_base (( x )) + $log_base (( x $a )) = $log_base (( ".$b."x ))";
	}
	$answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #258 Generator              ////
////               Log Equations 6                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_258()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $base = rand(1,5);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(1,9);
    if ($b == $a)
    {
        $b++;
    }
    rand_switch_sign($c,2);
    $num_temp = ($b * $c) / ($a - $b);
    $num_temp2 = $num_temp + $c;
    if ($num_temp < 0 || $num_temp == 0 || $num_temp2 < 0 || $num_temp2 == 0)
    {
        $numerator = "n/a@@n/a@@n/a@@n/a@@1";
    }
    else
    {
        $num = $b * $c;
        $denom = $a - $b;
        if ($num < 0 && $denom < 0)
        {
            $num = (-1) * $num;
            $denom = (-1) * $denom;
        }
        reduce($num,$denom,81);
        $numerator = $num."@@".$denom."@@n/a@@n/a@@0";
    }
    coeff_prep($c,0);
	if($base == 1)
     $question = "$log_base ( $a ) + $log_base ( x ) = $log_base ( $b ) + $log_base ( x $c )";
	else
	 $question = "$log_base (( $a )) + $log_base (( x )) = $log_base (( $b )) + $log_base (( x $c ))";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #259 Generator              ////
////               Log Equations 7                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_259()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $base = rand(1,5);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $a = 2 * rand(1,4);
    $b = 2 * rand(1,4);
    if ($b == $a)
    {
        $a = $a + 2;
    }
    $a = (-1) * $a;
    $b = (-1) * $b;
    $coeff1 = (-1) * ($a + $b) / 2;
    $coeff2 = (-1) * ($a * $b) / 2;
    $a = (-1) * $a;
    $b = (-1) * $b;
    $num_temp1 = $coeff1 * $a + $coeff2;
    $num_temp2 = $coeff1 * $b + $coeff2;
    if ($num_temp1 < 0 || $num_temp1 == 0)
    {
        $a_doesnt_work = TRUE;
    }
    if ($num_temp2 < 0 || $num_temp2 == 0)
    {
        $b_doesnt_work = TRUE;
    }
    if ($a_doesnt_work == TRUE && $b_doesnt_work == TRUE)
    {
        $numerator = "n/a@@n/a@@n/a@@n/a@@1";
    }
    if ($a_doesnt_work == TRUE)
    {
        $numerator = "n/a@@n/a@@";
    }
    else
    {
        $numerator = "$a@@1@@";
    }
    if ($b_doesnt_work == TRUE)
    {
        $numerator .= "n/a@@n/a@@0";
    }
    else
    {
        $numerator .= "$b@@1@@0";
    }
    coeff_prep($coeff2,0);
	if($base==1)
      $question = "2 $log_base ( x ) = $log_base ( 2 ) + $log_base ( $coeff1 x $coeff2 ) ";
	else
	  $question = "2 $log_base (( x )) = $log_base (( 2 )) + $log_base (( $coeff1 x $coeff2 )) ";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #260 Generator              ////
////               Log Equations 8                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_260()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $base = rand(1,5);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $a = rand(1,9);
    $b = rand(1,9);
    if ($b == $a)
    {
        $a++;
    }
    $b = (-1) * $b;
    $coeff1 = $a + $b;
    $coeff2 = (-1) * $a * $b;
    $b = $b * (-1);
    $numerator = "$b@@1@@n/a@@n/a@@0";
    coeff_prep($coeff1,0);
	if($base==1)
       $question = "$log_base ( x ) + $log_base ( x $coeff1) = $log_base ( $coeff2 )";
	else
	    $question = "$log_base (( x )) + $log_base (( x $coeff1)) = $log_base (( $coeff2 ))";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #261 Generator              ////
////               Log Equations 9                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_261()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,3);
    $base = rand(2,5);
    $c2 = pow($base,$c);
    $num_temp = ($a + ($c2 * $b) / ($c2 - 1));
    if ( ($num_temp - $b) < 0 || ($num_temp - $b) == 0)
    {
        $numerator = "n/a@@n/a@@n/a@@n/a@@1";
    }
    else
    {
        $num = $a + $c2 * $b;
        $denom = $c2 - 1;
        reduce($num,$denom,124);
        $numerator = $num."@@".$denom."@@n/a@@n/a@@0";
    }
    $log_base = "log[$base]";
    $b = $b * (-1);
    coeff_prep($a,0);
    coeff_prep($b,0);
    $question = "$log_base (( x $a )) - $log_base (( x $b )) = $c ";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #261 Generator              ////
////               Log Equations 10                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_262()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(1,9);
    $b = rand(2,9);
    if ($a == $b)
    {
        $b++;
    }
    $base = $a * $b;
    $b = $b * (-1);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $coeff1 = (-1) * ($a + $b);
    $numerator = "$a@@1@@n/a@@n/a@@0";
    coeff_prep($coeff1,0);
    $question = "$log_base (( x )) + $log_base (( x $coeff1 )) = 1";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #263 Generator              ////
////               Log Equations 11                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_263()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(2,5);
    $b = rand(9,12);
    $c = rand(1,3);
    if ($a == $b)
    {
        $b++;
    }
    while ($c == $b)
    {
        $c = rand(1,5);
    }
    $base = ($b * $c) - ($a * $c) - ($c * $c);
    while ($base < 2)
    {
        $b++;
        while ($c == $b)
        {
            $c = rand(1,5);
        }
        $base = ($b * $c) - ($a * $c) - ($c * $c);
    }
    $coeff1 = (-1) * ($b - $c);
    $coeff2 = (-1) * ($a + $c);
    $numerator = "$b@@1@@n/a@@n/a@@0";
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    $question = "$log_base (( x $coeff1 )) + $log_base ((x $coeff2 )) = 1";
    $answer = array($question,$numerator,$denominator,0,0,16);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #264 Generator              ////
////            Domain of Logarithms 1                 ////
////          Straight Forward Questions               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_264()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $split = "@";
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    $a = rand(1,9);
    $b = rand(1,9);
    $base = rand(1,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
	if($base==1)
      $question .= "$log_base (".$coeff1."x ".$coeff2.")";
	else
	    $question .= "$log_base ((".$coeff1."x ".$coeff2."))";
    $b = (-1) * $b;
    $my_numerator = $b;
    $my_denominator = $a;
    $switch = FALSE;
    if ($my_denominator < 0)
    {
        $switch = TRUE;
    }
    if ($my_numerator < 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    else if ($my_numerator > 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    reduce($my_numerator,$my_denominator,9);
    if ($switch == TRUE)
    {
        $numerator = "( -INF , ".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ")";
    }
    else // ($switch == FALSE)
    {
        $numerator = "(".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ", INF)";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #265 Generator              ////
////           Domain of Logarithms 2                  ////
////             Little Trickier                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_265()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $split = '@';
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    $a = rand(1,9);
    $b = rand(1,9);
    $base = rand(1,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $pow = 2 * rand(1,3);
    $coeff1 = (-1) * $a;
    coeff_prep($coeff1,0);
	if($base==1)
      $question .= "$log_base ( (x $coeff1)^($pow))";
	else
	  $question .= "$log_base (( (x $coeff1)^($pow)))";
    $denominator = $a;
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #265 Generator              ////
////           Domain of Logarithms 3                  ////
////             Little Trickier                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_266()
{
    $question = "";
    $numerator = "(-INF,INF)";
    $denominator = "not_used";
    $split = '@';
    $func_name = rand(1,5);
    if ($func_name == 1)
    {
        $func_name = "f";
    }
    else if ($func_name == 2)
    {
        $func_name = "g";
    }
    else if ($func_name == 3)
    {
        $func_name = "h";
    }
    else if ($func_name == 4)
    {
        $func_name = "C";
    }
    else
    {
        $func_name = "m";
    }
    $question =$func_name."(x) = ";
    $a = rand(1,9);
    $b = rand(1,9);
    $base = rand(1,10);
    if ($base == 10)
    {
        $log_base = "log ";
    }
    else if ($base == 1)
    {
        $log_base = "ln ";
    }
    else
    {
        $log_base = "log[$base]";
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $pow = 2 * rand(1,3) - 1;
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "-";
    }
	if($base==1)
      $question .= "$log_base ( (".$coeff1."x ".$coeff2.")^($pow))";
	else
	  $question .= "$log_base (( (".$coeff1."x ".$coeff2.")^($pow)))";
    $b = (-1) * $b;
    $my_numerator = $b;
    $my_denominator = $a;
    $switch = FALSE;
    if ($my_denominator < 0)
    {
        $switch = TRUE;
    }
    if ($my_numerator < 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    else if ($my_numerator > 0 && $my_denominator < 0)
    {
        $my_numerator = $my_numerator * (-1);
        $my_denominator = $my_denominator * (-1);
    }
    reduce($my_numerator,$my_denominator,9);
    if ($switch == TRUE)
    {
        $numerator = "( -INF , ".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ")";
    }
    else // ($switch == FALSE)
    {
        $numerator = "(".$my_numerator;
        if ($my_denominator != 1)
        {
            $numerator .= "/".$my_denominator;
        }
        $numerator .= ", INF)";
    }
    $answer = array($question,$numerator,$denominator,0,0,31);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #267 Generator              ////
////       Translation of Exponential Base             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_267()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(5,1500);
    $b = rand(101,500) / 100;
    $c = rand(1,10);
    if ($c != 1)
    {
        $question = "N(t) = $a * ( $b ) ^($c t)";
    }
    else
    {
        $question = "N(t) = $a * ( $b ) ^(t)";
    }
    $numerator = $a;
    $denominator = $c * log($b);
    $denominator = round($denominator + 0.0001 / pow(10,4),4);
    $answer = array($question,$numerator,$denominator,0,0,17);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #268 Generator              ////
////            Compound Interest 7                    ////
////            Doubling / Tripling                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_268()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1000,5000);
    $b = rand(10,150) / 10;
    $c = rand(1,5);
    $compounded = "";
    $times = 0;
    if ($c == 1)
    {
        $compounded = "annually";
        $times = 1;
    }
    else if ($c == 2)
    {
        $compounded = "semi-annually";
        $times = 2;
    }
    else if ($c == 3)
    {
        $compounded = "quarterly";
        $times = 4;
    }
    else if ($c == 4)
    {
        $compounded = "monthly";
        $times = 12;
    }
    else // ($c == 5)
    {
        $compounded = "daily";
        $times = 365;
    }
    if ($randy == 1)
    {
        $dollars = "double";
        $d = 2 * $a;
    }
    else
    {
        $dollars = "triple";
        $d = 3 * $a;
    }
    $question = "About how long would it take for $$a to $dollars if ";
    $question .= "it is invested in a bank account earning $b% compounded $compounded?";
    $b = $b / 100;
    $rate = 1 + ($b / $times);
    $LHS = $d / $a;
    $LHS = log($LHS);
    $divisor = $times * log($rate);
    $numerator = $LHS / $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = $numerator." years";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #269 Generator              ////
////          Composition of functions 1               ////
////            Linear with Linear                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_269()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    if ($c == $d)
    {
        $c++;
    }
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    $func = rand(1,2);
    $coeff1 = $a * $c;
    $coeff2 = $a * $d + $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = "$coeff1 x $coeff2";
    coeff_prep($b,0);
    coeff_prep($d,0);
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    if ($func == 1)
    {
        $question = "(g <span style='font-size:x-small'>o</span> f)(x)".$split."f(x)=$c x $d".$split. "g(x)=$a x $b";
    }
    else
    {
        $question = "(f <span style='font-size:x-small'>o</span> g)(x)".$split."f(x)=$a x $b".$split. "g(x)=$c x $d";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #270 Generator              ////
////          Composition of functions 2               ////
////            Linear & Quadratic                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
function gen_270()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              ax+b o cx^2 + d                      ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    if ($c == $d)
    {
        $c++;
    }
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    $func = rand(1,2);
    $coeff1 = $a * $c;
    $coeff2 = $a * $d + $b;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = "$coeff1 x^2 $coeff2";
    coeff_prep($b,0);
    coeff_prep($d,0);
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    if ($func == 1)
    {
        $question = "(g <span style='font-size:x-small'>o</span> f)(x)".$split."f(x)=$c x^(2)$d".$split."g(x)=$a x $b";
    }
    else
    {
        $question = "(f <span style='font-size:x-small'>o</span> g)(x)".$split."f(x)=$a x $b".$split."g(x)=$c x^(2)$d";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #271 Generator              ////
////          Composition of functions 3               ////
////            Linear & Quadratic                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_271()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             cx^2 + d o ax+b                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = rand(1,5);
    if ($a == $b)
    {
        $a++;
    }
    if ($c == $d)
    {
        $c++;
    }
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    $coeff1 = $c * $a * $a;
    $coeff2 = 2 * $c * $a * $b;
    $coeff3 = $c * $b * $b + $d;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = "$coeff1 x^2 $coeff2 x $coeff3";
    coeff_prep($b,0);
    coeff_prep($d,0);
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    $linear = "$a x $b";
    $quad = "$c x^(2)$d";
    $func = rand(1,2);
    if ($func == 1)
    {
        $question = "(g <span style='font-size:x-small'>o</span> f)(x)".$split."f(x)=".$linear.$split."g(x)=".$quad;
    }
    else
    {
        $question = "(f <span style='font-size:x-small'>o</span> g)(x)".$split."f(x)=".$quad.$split."g(x)=".$linear;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #272 Generator              ////
////          Composition of functions 4               ////
////            Linear & Quadratic                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_272()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           ax + b o cx^2 + dx + e                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    $e = rand(1,9);
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    $coeff1 = $a * $c;
    $coeff2 = $a * $d;
    $coeff3 = $a * $e + $b;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = "$coeff1 x^2 $coeff2 x $coeff3";
    coeff_prep($b,0);
    coeff_prep($d);
    coeff_prep($e,0);
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    $linear = "$a x $b";
    $quad = "$c x^(2)$d x $e";
    $func = rand(1,2);
     if ($func == 1)
    {
        $question = "(g <span style='font-size:x-small'>o</span> f)(x)".$split."f(x)=".$linear.$split."g(x)=".$quad;
    }
    else
    {
        $question = "(f <span style='font-size:x-small'>o</span> g)(x)".$split."f(x)=".$quad.$split."g(x)=".$linear;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #273 Generator              ////
////          Composition of functions 5               ////
////            Linear & Quadratic                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_273()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = rand(1,5);
    $e = rand(1,5);
    rand_switch_sign($b,2);
    rand_switch_sign($d,2);
    rand_switch_sign($e,2);
    $coeff1 = $c * $a * $a;
    $coeff2 = 2 * $c * $a * $b + $d * $a;
    $coeff3 = $c * $b * $b + $d * $b + $e;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    $numerator = "$coeff1 x^2 $coeff2 x $coeff3";
    coeff_prep($b,0);
    coeff_prep($d);
    coeff_prep($e,0);
    if ($a == 1)
    {
        $a = "";
    }
    if ($c == 1)
    {
        $c = "";
    }
    $linear = "$a x $b";
    $quad = "$c x^(2)$d x $e";
    $func = rand(1,2);
      if ($func == 1)
    {
        $question = "(g <span style='font-size:x-small'>o</span> f)(x)".$split."f(x)=".$linear.$split."g(x)=".$quad;
    }
    else
    {
        $question = "(f <span style='font-size:x-small'>o</span> g)(x)".$split."f(x)=".$quad.$split."g(x)=".$linear;
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #274 Generator              ////
////             Power Functions 1                     ////
////              End Behavior 1                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_274()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(2,7);
    $d = rand(2,7);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($a == $b)
    {
        $a++;
        if ($a == 0)
        {
            $a = 1;
        }
    }
    coeff_prep($a,0);
    coeff_prep($b,0);
    $question = "f(x) = (x $a )^$c*(x $b )^$d";
    $numerator = $c + $d;
    $answer = array($question,$numerator,$denominator,0,0,18);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #275 Generator              ////
////             Power Functions 2                     ////
////              End Behavior 2                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_275()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $randy = rand(1,3);
    if ($randy == 1)
    {
        $a = 2 * rand(1,4);
    }
    else if ($randy == 2)
    {
        $a = 2 * rand(1,4) + 1;
    }
    else
    {
        $a = (-1) * rand(2,9);
    }
    $question = "f(x) = x^($a)";
    if ($randy == 1)
    {
        $numerator = 1;
    }
    else if ($randy == 2)
    {
        $numerator = 3;
    }
    else
    {
        $numerator = 5;
    }
    $answer = array($question,$numerator,$denominator,0,0,19);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #276 Generator              ////
////             Power Functions 2                     ////
////              End Behavior 3                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_276()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $randy = rand(1,5);
    $b = rand(2,5);
    if ($randy == 1)
    {
        $a = 2 * rand(1,4);
    }
    else if ($randy == 2)
    {
        $a = 2 * rand(1,4) + 1;
    }
    else if ($randy == 3)
    {
        $a = (-1) * rand(2,9);
        rand_switch_sign($b,2);
    }
    else if ($randy == 4)
    {
        $a = 2 * rand(1,4);
        $b = (-1) * $b;
    }
    else
    {
        $a = 2 * rand(1,4) + 1;
        $b = (-1) * $b;
    }
    $question = "f(x)= $b x^( $a )";
    if ($randy == 1)
    {
        $numerator = 1;
    }
    else if ($randy == 2)
    {
        $numerator = 3;
    }
    else if ($randy == 3)
    {
        $numerator = 5;
    }
    else if ($randy == 4)
    {
        $numerator = 2;
    }
    else
    {
        $numerator = 4;
    }
    $answer = array($question,$numerator,$denominator,0,0,19);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #277 Generator              ////
////           Power Functions 4                       ////
////            Behavior of Zeros                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_277()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(2,7);
    $d = rand(2,7);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($a == $b)
    {
        $a++;
        if ($a == 0)
        {
            $a = 1;
        }
    }
    $first_zero = (-1) * $a;
    $second_zero = (-1) * $b;
    coeff_prep($a,0);
    coeff_prep($b,0);
    $question = "f(x)=(x $a )^($c)*(x $b )^($d)";
    $randy = rand(1,2);
    if ($randy == 1)
    {
       $question .= "$split x=$first_zero";
        if (fmod($c,2) == 0)
        {
            $numerator = 2;
        }
        else
        {
            $numerator = 1;
        }
    }
    else
    {
        $question .= "$split x =$second_zero";
        if (fmod($d,2) == 0)
        {
            $numerator = 2;
        }
        else
        {
            $numerator = 1;
        }
    }
    $answer = array($question,$numerator,$denominator,0,0,22);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #278 Generator              ////
////        Inverse vs. Direct proportion              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_278()
{
    $question = "";
    $numerator = 1;
    $denominator = "1";
    $split = '@@';
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,9);
    rand_switch_sign($c,3);
    $rand = rand(1,2);
    if ($rand == 1)
    {
        $a = $a * (-1);
        $numerator = 2;
    }
    $var = rand(1,2);
    if ($var == 1)
    {
        $question = "State if the output of the function f as given by the rule below";
        $question .= " is directly or inversely proportional";
        $question .= " to x if <br><br><center>f(x,y)=$split $c *x^($a)*y^($b)";
    }
    else
    {
        $question = "State if the output of the function f as given by the rule below";
        $question .= " is directly or inversely proportional";
        $question .= " to y if <br><br><center>f(x,y)=$split $c *x^($b)*y^($a)";
    }
    $answer = array($question,$numerator,$denominator,0,0,20);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #279 Generator              ////
////              Inverse proportion                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_279()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $pow = rand(2,3);
    $a = rand(2,9);
    $b = rand(2,9);
    $c = rand(2,5);
    $rand = rand(1,2);
    reduce($a,$b);
    if ($b == 1)
    {
        $b = "";
    }
    if ($rand == 1)
    {
        $question .= "If x is divided by $c what happens to f(x) if <br/><br/><center>";
        $numerator=pow($c,$pow);
    }
    else // $rand == 2
    {
        $question .= "If x is multiplied by $c what happens to f(x) if <br/><br/><center>";
        $numerator="1/".pow($c,$pow);
    }
    $numerator.="*f(x)";
    $question .= "$split f(x)=$a/($b x^ $pow)";
    $answer = array($question,$numerator,$denominator,0,0,21);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #280 Generator              ////
////               Direct Proportion                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_280()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $pow = rand(2,3);
    $a = rand(2,9);
    $c = rand(2,5);
    $rand = rand(1,2);
    if ($rand == 1)
    {
        $question .= "If x is multiplied by $c what happens to f(x) if <br/><br/><center>";
        $numerator=pow($c,$pow);
    }
    else // $rand == 2
    {
        $question .= "If x is divided by $c what happens to f(x) if <br/><br/><center>";
        $numerator="1/".pow($c,$pow);
    }
    $question .= "$split f(x)=$a x^$pow";
    $numerator.="*f(x)";
    $answer = array($question,$numerator,$denominator,0,0,21);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #281 Generator              ////
////            Quadratic Functions 1                  ////
////             Solve by Factoring                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_281()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a + $b;
    $coeff2 = $a * $b;
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        coeff_prep($coeff2,0);
        $question = "f ( x ) = x^2 $coeff1 x $coeff2";
    }
    else
    {
        coeff_prep($coeff2,0);
        $question = "f ( x ) = x^2 $coeff2";
    }
    $a = (-1) * $a;
    $b = (-1) * $b;
    $numerator = $a.$split."1".$split.$b.$split."1".$split."0";
    $answer = array($question,$numerator,$denominator,0,0,23);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #282 Generator              ////
////            Quadractic Functions 2                 ////
////             Solve by Formula                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_282()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = rand(1,9);
    if ($a > 6)
    {
        $c = rand(1,2);
    }
    else if ($a > 4)
    {
        $c = rand(1,3);
    }
    else
    {
        $c = rand(1,4);
    }
    $b = rand(1,4);
    $b = r_prime($b);
    rand_switch_sign($a,3);
    rand_switch_sign($b,5);
    if ($b < 0)
    {
        $numerator = "n/a".$split."n/a".$split."n/a".$split."n/a".$split."1";
    }
    else
    {
        $my_a = $a;
        $num1 = $my_a." + sqrt($b)";
        $num2 = $my_a." - sqrt($b)";
        $denom = $c;
        $numerator = $num1.$split.$denom.$split.$num2.$split.$denom.$split."0";
    }
    $coeff1 = $c * $c;
    $coeff2 = 2 * (-1) * $c * $a;
    $coeff3 = $a * $a - $b;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
	
    $question = "f ( x ) = $coeff1 x^2 $coeff2 x $coeff3";
    $answer = array($question,$numerator,$denominator,0,0,23);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #283 Generator              ////
////            Quadractic Functions 3                 ////
////            Completing the square 1                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_283()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,15);
    $b = 2 * rand(1,10) + 1;
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "f( x ) = x^2 $coeff1 x $coeff2";
    if ($a < 0)
    {
        $a = (-1) * $a;
    }
    $numerator = $a;
    $denominator = 2;
    reduce($numerator,$denominator,20);
    $numerator = pow($numerator,2);
    $denominator = pow($denominator,2);
    if($denominator!=1 && $denominator!="1")
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #284 Generator              ////
////            Quadractic Functions 4                 ////
////            Completing the square 2                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_284()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              Leading Coefficient                  ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a = rand(2,5);
    $b = rand(1,15);
    $c = 2 * rand(1,10) + 1;
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $coeff1 = $b;
    $coeff2 = $c;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "f( x ) = $a x^2 $coeff1 x $coeff2";
    if ($b < 0)
    {
        $b = (-1) * $b;
    }
    $numerator = $b;
    $denominator = 2* $a;
    reduce($numerator,$denominator,20);
    $numerator = $a * pow($numerator,2);
    $denominator = pow($denominator,2);
    reduce($numerator,$denominator,100);
    if($denominator!=1 && $denominator!="1")
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #285 Generator              ////
////             Quadratic Functions 5                 ////
////              Find the Vertex                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_285()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(1,9);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($a,3);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               x^2 + bx + c                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $coeff1 = $b;
    $coeff2 = $c;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "f ( x ) = x^2 $coeff1 x $coeff2";
    $numerator = (-1) * $b;
    $denominator = 2;
    reduce($numerator,$denominator);
    if($denominator!=1 && $denominator!="1")
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #286 Generator              ////
////             Quadratic Functions 6                 ////
////              Find the Vertex                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_286()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(2,9);
    $b = rand(1,9);
    $c = rand(1,9);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($a,3);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              a x^2 + bx + c                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $c;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
	$coeff1_1=$coeff1;
	if($coeff1<0)
	{
	 $coeff1_1="~".abs($coeff1);
	}
    $question = "f ( x ) = $coeff1_1 x^2 $coeff2 x $coeff3";
    $numerator = (-1) * $b;
    $denominator = 2 * $a;
    if ($denominator < 0)
    {
        $numerator = (-1) * $numerator;
        $denominator = (-1) * $denominator;
    }
    reduce($numerator,$denominator);
    if($denominator!=1 && $denominator!="1")
     $numerator=$numerator."/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #287 Generator              ////
////            Quadratic Functions 7                  ////
////                Find Max/Min                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_287()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(2,9);
    $b = 2 * rand(1,4);
    $c = rand(1,9);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($a,3);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////               x^2 + bx + c                        ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $coeff1 = $b;
    $coeff2 = $c;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "f ( x ) = x^2 $coeff1 x $coeff2";
    $numerator = (-1) * $b;
    $denominator = 2;
    reduce($numerator,$denominator);
    $vertex = $numerator / $denominator;
    $max = $vertex * $vertex + $b * $vertex + $c;
    $numerator = $max;
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #288 Generator              ////
////            Quadratic Functions 8                  ////
////                Find Max/Min                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_288()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $a = rand(2,9);
    $b = 2 * rand(1,4);
    $c = rand(1,9);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($a,3);
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////              a x^2 + bx + c                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $c;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
	 $coeff1_1=$coeff1;
	 if($coeff1<0)
	 {
	  $coeff1_1="~".abs($coeff1);
	 }
    $question = "f ( x ) = $coeff1_1 x^2 $coeff2 x $coeff3";
    $numerator = (-1) * $b;
    $denominator = 2 * $a;
    if ($denominator < 0)
    {
        $numerator = (-1) * $numerator;
        $denominator = (-1) * $denominator;
    }
    reduce($numerator,$denominator);
    $vertex = $numerator / $denominator;
    $max = $a * $vertex * $vertex + $b * $vertex + $c;
    $numerator = $max;
    $denominator = 1;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #289 Generator              ////
////           Quadratic Functions 9                   ////
////               Standard Form                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
function gen_289()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,9);
    $b = rand(1,9);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff2 = 2 * $a;
    $coeff3 = pow($a,2) + $b;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = "f( x ) = x^2 $coeff2 x $coeff3";
    if ($a < 0)
    {
        $numerator = "(x".$a.")^2";
    }
    else
    {
        $numerator = "(x+".$a.")^2";
    }
    if ($b < 0 )
    {
        $numerator .= $b;
    }
    else
    {
        $numerator .= "+".$b;
    }
    $answer = array($question,$numerator,$denominator,0,0,24);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #290 Generator              ////
////           Quadratic Functions 10                  ////
////               Translations 1                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_290()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,2);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    if ($c == 1)
    {
        $question = "f( x ) = (x $coeff1)^2 $coeff2";
    }
    else
    {
        $question = "f( x ) = ~ (x $coeff1)^2 $coeff2";
    }
    if ($a < 0)
    {
        $a = $a * (-1);
        $numerator = "Right".$split.$a.$split;
    }
    else
    {
        $numerator = "Left".$split.$a.$split;
    }
    if ($b < 0)
    {
        $b = $b * (-1);
        $numerator .= "Up".$split.$b.$split;
    }
    else
    {
        $numerator .= "Down".$split.$b.$split;
    }
    if ($c == 1)
    {
        $numerator .= "0";
    }
    else
    {
        $numerator .= "1";
    }
    $answer = array($question,$numerator,$denominator,0,0,25);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #291 Generator              ////
////           Quadratic Functions  11                 ////
////               Translations 2                      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_291()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,2);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($c == 1)
    {
        $coeff1 = 2 * $a;
        $coeff2 = pow($a,2) + $b;
        coeff_prep($coeff1);
        coeff_prep($coeff2,0);
        $question = "f( x ) = x^2 $coeff1 x $coeff2";
    }
    else
    {
        $coeff1 = (-1) * 2 * $a;
        $coeff2 = (-1) * pow($a,2) + $b;
        coeff_prep($coeff1);
        coeff_prep($coeff2,0);
        $question = "f( x ) = ~ x^2 $coeff1 x $coeff2";
    }
    if ($a < 0)
    {
        $a = $a * (-1);
        $numerator = "Right".$split.$a.$split;
    }
    else
    {
        $numerator = "Left".$split.$a.$split;
    }
    if ($b < 0)
    {
        $b = $b * (-1);
        $numerator .= "Up".$split.$b.$split;
    }
    else
    {
        $numerator .= "Down".$split.$b.$split;
    }
    if ($c == 1)
    {
        $numerator .= "0";
    }
    else
    {
        $numerator .= "1";
    }
    $answer = array($question,$numerator,$denominator,0,0,25);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #292 Generator              ////
////    Quadratic Functions - Word Problems 1          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_292()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = 2 * rand(12,50);
    $question = "If you are given $a feet of fence.  What ";
    $question .= "would the formula for the area of a rectangular fenced in garden plot be in terms ";
    $question .= "of the length(L) of one of its sides?";
    $a = $a / 2;
    $numerator = "$a * L - L^2";
    $numerator2 = "L($a - L)";
    $answer = array($question,$numerator,$denominator,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #293 Generator              ////
////    Quadratic Functions - Word Problems 2          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_293()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = 2 * rand(12,50);
    $question = "A gardner wants to grow some veggies in an enclosed plot along the ";
    $question .= "side of her new barn.  If she has $a feet of fence ";
    $question .= "and assuming she will use the barn as one side of the plot, ";
    $question .= "what is the formula for the area of the plot in terms of ";
    $question .= "the length(L) of one of the sides perpendicular to the barn?";
    $numerator = "$a * L - 2 * L^2";
    $numerator2 = "L($a - 2 * L)";
    $answer = array($question,$numerator,$denominator,$numerator2,1,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #294 Generator              ////
////    Quadratic Functions - Word Problems 3          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_294()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = 4 * rand(10,25);
    $question = "If you are given $a feet of fence.  What ";
    $question .= "dimensions would give you the maximum area ";
    $question .= "of a rectangular fenced in garden plot?";
    $a = $a / 4;
    $numerator = $a;
    $denominator=$a;
    $answer = array($question,$numerator,$denominator,0,0,26);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #295 Generator              ////
////    Quadratic Functions - Word Problems 4          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_295()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $a = 4 * rand(10,25);
    $question = "A gardner wants to grow some veggies in an enclosed plot along the ";
    $question .= "side of her new barn.  If she has $a feet of fence ";
    $question .= "and assuming she will use the barn as one side of the plot, ";
    $question .= "what are the dimensions that will provide her with the maximum";
    $question .= " area in the garden?<br> <i> Assume L is the length of one of the sides ";
    $question .= "perpendicular to the barn</i>";
    $a1 = $a / 4;
    $a2 = $a / 2;
    $numerator = $a2;
    $denominator=$a1;
    $answer = array($question,$numerator,$denominator,0,0,26);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #296 Generator              ////
////          Non-Linear Inequalities 1                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_296()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    if ($temp1 < $temp2)
    {
        $numerator = $left_bound.$temp1." , ".$temp2.$right_bound;
    }
    else
    {
        $numerator = $left_bound.$temp2." , ".$temp1.$right_bound;
    }
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    $inequality = gen_inequality($rand);
    $question = "(x $coeff1 )*( x $coeff2 ) $inequality 0 ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #297 Generator              ////
////          Non-Linear Inequalities 2                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_297()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    $numerator = "$inf";
    if ($temp1 < $temp2)
    {
        $numerator = "( - ".$inf." , ".$temp1.$right_bound;
        $numerator .= $union.$left_bound.$temp2." , ".$inf.")";
    }
    else
    {
        $numerator = "( - "."$inf "." , ".$temp2.$right_bound;
        $numerator .= $union.$left_bound.$temp1." , ".$inf.")";
    }
    $inequality = gen_inequality($rand);
    $coeff1 = $a;
    $coeff2 = $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    $question = "( x $coeff1 )*( x $coeff2 ) $inequality 0";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #298 Generator              ////
////          Non-Linear Inequalities 3                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_298()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    if ($temp1 < $temp2)
    {
        $numerator = $left_bound.$temp1." , ".$temp2.$right_bound;
    }
    else
    {
        $numerator = $left_bound.$temp2." , ".$temp1.$right_bound;
    }
    $coeff1 = $a + $b;
    $coeff2 = $b * $a;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $inequality = gen_inequality($rand);
    $question = "x^2 $coeff1 x  $coeff2 $inequality 0 ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #299 Generator              ////
////          Non-Linear Inequalities 4                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_299()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    $numerator = "$inf";
    if ($temp1 < $temp2)
    {
        $numerator = "( - ".$inf." , ".$temp1.$right_bound;
        $numerator .= $union.$left_bound.$temp2." , ".$inf.")";
    }
    else
    {
        $numerator = "( - "."$inf "." , ".$temp2.$right_bound;
        $numerator .= $union.$left_bound.$temp1." , ".$inf.")";
    }
    $inequality = gen_inequality($rand);
    $coeff1 = $a+ $b;
    $coeff2 = $b * $a;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    $question = "x^2 $coeff1 x $coeff2 $inequality 0";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #300 Generator              ////
////          Non-Linear Inequalities 5                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_300()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $b = (-1) * $a;
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    if ($temp1 < $temp2)
    {
        $numerator = $left_bound.$temp1." , ".$temp2.$right_bound;
    }
    else
    {
        $numerator = $left_bound.$temp2." , ".$temp1.$right_bound;
    }
    $coeff2 = pow($a,2);
    $inequality = gen_inequality($rand);
    $question = "x^2 $inequality $coeff2 ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #301 Generator              ////
////          Non-Linear Inequalities 6                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_301()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $b = (-1) * $a;
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    $numerator = "$inf";
    if ($temp1 < $temp2)
    {
        $numerator = "( - ".$inf." , ".$temp1.$right_bound;
        $numerator .= $union.$left_bound.$temp2." , ".$inf.")";
    }
    else
    {
        $numerator = "( - "."$inf "." , ".$temp2.$right_bound;
        $numerator .= $union.$left_bound.$temp1." , ".$inf.")";
    }
    $inequality = gen_inequality($rand);
    $coeff2 = pow($a,2);
    $question = "x^2 $inequality $coeff2";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #302 Generator              ////
////          Non-Linear Inequalities 7                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_302()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    if ($temp1 < $temp2)
    {
        $numerator = $left_bound.$temp1." , ".$temp2.$right_bound;
    }
    else
    {
        $numerator = $left_bound.$temp2." , ".$temp1.$right_bound;
    }
    $coeff1 = (-1) * ($a + $b);
    $coeff2 = $b * $a;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "~";
    }
	$coeff1_1=$coeff1;
	if($coeff1<-1)
	{
	 $coeff1_1="~".abs($coeff1);
	}
    $inequality = gen_inequality($rand);
    $question = "x^2 $coeff2 $inequality $coeff1_1 x ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #303 Generator              ////
////          Non-Linear Inequalities 8                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_303()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $a = rand(1,9);
    $b = rand(1,9);
    if ($a == $b)
    {
        $a++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $temp1 = (-1) * $a;
    $temp2 = (-1) * $b;
    $numerator = "$inf";
    if ($temp1 < $temp2)
    {
        $numerator = "( - ".$inf." , ".$temp1.$right_bound;
        $numerator .= $union.$left_bound.$temp2." , ".$inf.")";
    }
    else
    {
        $numerator = "( - "."$inf "." , ".$temp2.$right_bound;
        $numerator .= $union.$left_bound.$temp1." , ".$inf.")";
    }
    $inequality = gen_inequality($rand);
    $coeff1 = (-1) * ($a + $b);
    $coeff2 = $b * $a;
    coeff_prep($coeff2,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "~";
    }
	$coeff1_1=$coeff1;
	if($coeff1<-1)
	{
	 $coeff1_1="~".abs($coeff1);
	}
    $question = "x^2 $coeff2 $inequality $coeff1_1 x";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #304 Generator              ////
////          Non-Linear Inequalities 9                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_304()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $b = rand(1,3);
    $a = rand($b+1,7);
    rand_switch_sign($b,3);
    $coeff1 = $b;
    $coeff2 = (-1) * pow($a,2);
    $coeff3 = $coeff2 * $b;
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $minus_a = (-1) * $a;
    $minus_b = (-1) * $b;
    $numerator = "( - ".$inf." , ".$minus_a.$right_bound.$union;
    $numerator .= $left_bound.$minus_b." , ".$a.$right_bound;
    $inequality = gen_inequality($rand);
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = "x^3 $coeff1 x^2 $coeff2 x $coeff3 $inequality 0 ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #305 Generator              ////
////          Non-Linear Inequalities 10               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_305()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $b = rand(1,3);
    $a = rand($b+1,7);
    rand_switch_sign($b,3);
    $coeff1 = $b;
    $coeff2 = (-1) * pow($a,2);
    $coeff3 = $coeff2 * $b;
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $minus_a = (-1) * $a;
    $minus_b = (-1) * $b;
    $numerator = $left_bound.$minus_a." , ".$minus_b.$right_bound.$union;
    $numerator .= $left_bound.$a." , ".$inf." )";
    $inequality = gen_inequality($rand);
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $question = "x^3 $coeff1 x^2 $coeff2 x $coeff3 $inequality 0 ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #306 Generator              ////
////          Non-Linear Inequalities 11               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_306()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $b = rand(1,3);
    $a = rand($b+1,7);
    rand_switch_sign($b,3);
    $coeff1 = $b;
    $coeff2 = (-1) * pow($a,2);
    $coeff3 = $coeff2 * $b;
    $rand = rand(1,2);
    if ($rand == 2)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $minus_a = (-1) * $a;
    $minus_b = (-1) * $b;
    $numerator = "( - ".$inf." , ".$minus_a.$right_bound.$union;
    $numerator .= $left_bound.$minus_b." , ".$a.$right_bound;
    $inequality = gen_inequality($rand);
    $coeff1 = (-1) * $coeff1;
    $coeff2 = (-1) * $coeff2;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "~";
    }
	$coeff1_1=$coeff1;
	if($coeff1<-1)
	{
	 $coeff1_1="~".abs($coeff1);
	}
    $question = "x^3 $coeff3 $inequality $coeff1_1 x^2 $coeff2 x  ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #307 Generator              ////
////          Non-Linear Inequalities 12               ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_307()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $inf = " INF ";
    $union = " union ";
    $b = rand(1,3);
    $a = rand($b+1,7);
    rand_switch_sign($b,3);
    $coeff1 = $b;
    $coeff2 = (-1) * pow($a,2);
    $coeff3 = $coeff2 * $b;
    $rand = rand(3,4);
    if ($rand == 4)
    {
        $left_bound = '[';
        $right_bound = ']';
    }
    else
    {
        $left_bound = '(';
        $right_bound = ')';
    }
    $minus_a = (-1) * $a;
    $minus_b = (-1) * $b;
    $numerator = $left_bound.$minus_a." , ".$minus_b.$right_bound.$union;
    $numerator .= $left_bound.$a." , ".$inf." )";
    $inequality = gen_inequality($rand);
    $coeff1 = (-1) * $coeff1;
    $coeff2 = (-1) * $coeff2;
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    if ($coeff1 == 1)
    {
        $coeff1 = "";
    }
    else if ($coeff1 == -1)
    {
        $coeff1 = "~";
    }
	$coeff1_1=$coeff1;
	if($coeff1<-1)
	{
	 $coeff1_1="~".abs($coeff1);
	}
    $question = "x^3 $coeff3 $inequality $coeff1_1 x^2 $coeff2 x  ";
    $answer = array($question,$numerator,$denominator,0,0,1);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #308 Generator              ////
////              Polynomials 1                        ////
////              End Behavior 1                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_308()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $highest_pow = rand(3,6);
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    $e = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    coeff_prep($a,0);
    coeff_prep($b);
    coeff_prep($c);
    coeff_prep($d);
    if($e!=1)
     $numerator = $e."*x^".$highest_pow;
    else
     $numerator = "x^".$highest_pow;
    if ($e == 1)
    {
        $e = "";
    }
    else if ($e == -1)
    {
        $e = "~";
    }
	$e1=$e;
	if($e1<-1)
	{
	 $e1="~".abs($e1);
	}
    $question = "P( x ) = $e1 x^$highest_pow ";
    if ($highest_pow == 3)
    {
        $question .= " $b x^2 $c x $a";
    }
    else if ($highest_pow == 4)
    {
        $question .= " $b x^3 $d x^2 $c x $a";
    }
    else if ($highest_pow == 5)
    {
        $question .= " $b x^3 $d x $a";
    }
    else // ($highest_pow == 6)
    {
        $question .= " $b x^4 $c x^3 $d x $a";
    }
    $answer = array($question,$numerator,1,0,0,27);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #309 Generator              ////
////               Polynomials 2                       ////
////              End Behavior 2                       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_309()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $highest_pow = rand(3,6);
    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);
    $d = rand(1,9);
    $e = rand(1,6);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    coeff_prep($a,0);
    coeff_prep($b);
    coeff_prep($c);
    coeff_prep($d);
    if ($highest_pow == 4 || $highest_pow == 6)
    {
        $pow = 1;
    }
    else
    {
        $pow = 0;
    }
    if ($e > 0)
    {
        if ($pow == 1)
        {
            $numerator = 1;
        }
        else
        {
            $numerator = 3;
        }
    }
    else
    {
        if ($pow == 1)
        {
            $numerator = 2;
        }
        else
        {
            $numerator = 4;
        }
    }
    if ($e == 1)
    {
        $e = "";
    }
    else if ($e == -1)
    {
        $e = "~";
    }
	$e1=$e;
	if($e1<-1)
	{
	 $e1="~".abs($e1);
	}
    $question = "P( x ) = $e1 x^ $highest_pow ";
    if ($highest_pow == 3)
    {
        $question .= " $b x^2 $c x $a";
    }
    else if ($highest_pow == 4)
    {
        $question .= " $b x^3 $d x^2 $c x $a";
    }
    else if ($highest_pow == 5)
    {
        $question .= " $b x^4 $d x^2 $c x $a";
    }
    else // ($highest_pow == 6)
    {
        $question .= " $b x^5 $c x^2 $d x $a";
    }
    $answer = array($question,$numerator,$denominator,0,0,28);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #310 Generator              ////
////               Polynomials 3                       ////
////           Possible Rational Roots                 ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_310()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $a = rand(1,5);
    $b = rand(1,5);
    while ($a == $b)
    {
        $b = rand(1,5);
    }
    $a = r_prime($a);
    $b = r_prime($b);
    $c = rand(2,9);
    $d = rand(1,9);
    if ($c == $a)
    {
        $c++;
    }
    if ($c == $b)
    {
        $c++;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $coeff1 = $c;
    $coeff2 = $d;
    $coeff3 = $b;
    coeff_prep($coeff1);
    coeff_prep($coeff2);
    coeff_prep($coeff3,0);
    $mathml="<mml:math xmlns:mml=http://www.w3.org/1998/Math/MathML>";
    $pm = "<mml:mo>\u00b1</mml:mo>";
    if ($a < 0)
    {
        $a = (-1) * $a;
    }
    if ($b < 0)
    {
        $b = (-1) * $b;
    }
    if ($c < 0)
    {
        $c = (-1) * $c;
    }
    $set_array = array();
    $choice_array = array();
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////        Randomizes correct choice set              ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $set_array[] = "$pm <mml:mn>1</mml:mn>";
    $set_array[] = "$pm <mml:mfrac><mml:mn>1</mml:mn><mml:mn>$a</mml:mn></mml:mfrac>";
    $set_array[] = "$pm <mml:mn>$b</mml:mn>";
    $set_array[] = "$pm <mml:mfrac><mml:mn>$b</mml:mn><mml:mn>$a</mml:mn></mml:mfrac>";
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,4) - 1;
        $right_switch = rand(1,4) - 1;
        $temp = $set_array[$left_switch];
        $set_array[$left_switch] = $set_array[$right_switch];
        $set_array[$right_switch] = $temp;
    }
    $correct_choice = "<mml:mo>{</mml:mo>";
    for ($i = 0; $i < 4; $i++)
    {
        $correct_choice .= $set_array[$i];
        if ($i != 3)
        {
            $correct_choice .= "<mml:mo> ,</mml:mo>";
        }
        else
        {
            $correct_choice .= "<mml:mo> }</mml:mo></mml:math>";
        }
    }
    $choice_array[] = $correct_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes First Bad Choice                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $set_array[0] = "$pm <mml:mn>1</mml:mn>";
    $set_array[1] = "$pm <mml:mfrac><mml:mn>1</mml:mn><mml:mn>$b</mml:mn></mml:mfrac>";
    $set_array[2] = "$pm <mml:mn>$a</mml:mn>";
    $set_array[3] = "$pm <mml:mfrac><mml:mn>$a</mml:mn><mml:mn>$b</mml:mn></mml:mfrac>";
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,4) - 1;
        $right_switch = rand(1,4) - 1;
        $temp = $set_array[$left_switch];
        $set_array[$left_switch] = $set_array[$right_switch];
        $set_array[$right_switch] = $temp;
    }
    $bad_choice = "<mml:mo>{</mml:mo>";
    for ($i = 0; $i < 4; $i++)
    {
        $bad_choice .= $set_array[$i];
        if ($i != 3)
        {
            $bad_choice .= "<mml:mo>,</mml:mo>";
        }
        else
        {
            $bad_choice .= "<mml:mo>}</mml:mo></mml:math>";
        }
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes Second Bad Choice                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $set_array[0] = "$pm <mml:mn>1</mml:mn>";
    $set_array[1] = "$pm <mml:mn>$b</mml:mn>";
    $set_array[2] = "$pm <mml:mn>$a</mml:mn>";
    $set_array[3] = "$pm <mml:mn>$c</mml:mn>";
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,4) - 1;
        $right_switch = rand(1,4) - 1;
        $temp = $set_array[$left_switch];
        $set_array[$left_switch] = $set_array[$right_switch];
        $set_array[$right_switch] = $temp;
    }
    $bad_choice = "<mml:mo>{</mml:mo>";
    for ($i = 0; $i < 4; $i++)
    {
        $bad_choice .= $set_array[$i];
        if ($i != 3)
        {
            $bad_choice .= "<mml:mo>,</mml:mo>";
        }
        else
        {
            $bad_choice .= "<mml:mo>}</mml:mo></mml:math>";
        }
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes Third Bad Choice                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $set_array[0] = "$pm <mml:mn>1</mml:mn>";
    $set_array[1] = "$pm <mml:mfrac><mml:mn>1</mml:mn><mml:mn>$b</mml:mn></mml:mfrac>";
    $set_array[2] = "$pm <mml:mfrac><mml:mn>1</mml:mn><mml:mn>$a</mml:mn></mml:mfrac>";
    $set_array[3] = "$pm <mml:mfrac><mml:mn>$a</mml:mn><mml:mn>$b</mml:mn></mml:mfrac>";
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,4) - 1;
        $right_switch = rand(1,4) - 1;
        $temp = $set_array[$left_switch];
        $set_array[$left_switch] = $set_array[$right_switch];
        $set_array[$right_switch] = $temp;
    }
    $bad_choice = "<mml:mo>{</mml:mo>";
    for ($i = 0; $i < 4; $i++)
    {
        $bad_choice .= $set_array[$i];
        if ($i != 3)
        {
            $bad_choice .= "<mml:mo>,</mml:mo>";
        }
        else
        {
            $bad_choice .= "<mml:mo>}</mml:mo></mml:math>";
        }
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes Fourth Bad Choice                ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $set_array[0] = "$pm <mml:mn>1</mml:mn>";
    $set_array[1] = "$pm <mml:mn>$b</mml:mn>";
    $set_array[2] = "$pm <mml:mn>$a</mml:mn>";
    $set_array[3] = "$pm <mml:mfrac><mml:mn>$a</mml:mn><mml:mn>$b</mml:mn></mml:mfrac>";
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,4) - 1;
        $right_switch = rand(1,4) - 1;
        $temp = $set_array[$left_switch];
        $set_array[$left_switch] = $set_array[$right_switch];
        $set_array[$right_switch] = $temp;
    }
    $bad_choice = "<mml:mo>{</mml:mo>";
    for ($i = 0; $i < 4; $i++)
    {
        $bad_choice .= $set_array[$i];
        if ($i != 3)
        {
            $bad_choice .= "<mml:mo>,</mml:mo> ";
        }
        else
        {
            $bad_choice .= "<mml:mo>}</mml:mo></mml:math>";
        }
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;

        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    $question = "P(x) = $a x^3 $coeff1 x^2 $coeff2 x $coeff3";
    $question .= $split;
    for ($i = 0; $i < 4; $i++)
    {
        $question .= $mathml.$choice_array[$i].$split;
    }
    $question .= $mathml.$choice_array[4];
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #311 Generator              ////
////               Polynomials 4                       ////
////              Synth Division 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_311()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $choice_array = array();
    $correct_choice = "";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $coeff1 = $b;
    $coeff2 = $c;
    $coeff3 = (-1) * $d;
    coeff_prep($coeff1);
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    if ($a == 1)
    {
        $coeff4 = "";
    }
    else if ($a == -1)
    {
        $coeff4 = "-";
    }
    else
    {
        $coeff4 = $a;
    }
    $question = "( $coeff4 x<sup> 4</sup> $coeff1 x<sup> 2</sup> ";
    $question .= "$coeff2 ) divided by ( x $coeff3 )";
    $choice_array = array();
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            Correct Answer                         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $d * $a1;
    $a3 = $d * $a2 + $b;
    $a4 = $d * $a3;
    $R  = $d * $a4 + $c;
    coeff_prep($a2);
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $correct_choice = " $a1 x<sup> 3</sup> $a2 x<sup> 2</sup>";
    if($a3 != 0)
    {
        coeff_prep($a3);
        $correct_choice .= " $a3 x";
    }
    if ($a4 != 0)
    {
        coeff_prep($a4,0);
        $correct_choice .= " $a4 ";
    }
    $correct_choice .= ", R = $R";
    $choice_array[] = $correct_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 1                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = (-1) * $d * $a1;
    $a3 = (-1) * $d * $a2 + $b;
    $a4 = (-1) * $d * $a3;
    $R  = (-1) * $d * $a4 + $c;
    coeff_prep($a2);
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 3</sup> $a2 x<sup> 2</sup>";
    if ($a3 != 0)
    {
        coeff_prep($a3);
        $bad_choice .= " $a3 x";
    }
    if ($a4 != 0)
    {
        coeff_prep($a4,0);
        $bad_choice .= " $a4";
    }
    $bad_choice .= " , R = $R";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 2                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $d * $a1 + $b;
    $R  = $d * $a2 + $c;
    coeff_prep($a2,0);
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x $a2 , R = $R";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 3                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $d * $a1 + $b;
    $a3 = $d * $a2;
    $R  = $d * $a3 + $c;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        coeff_prep($a2);
        $bad_choice .= " $a2 x";
    }
    if ($a3 != 0)
    {
        coeff_prep($a3,0);
        $bad_choice .= " $a3";
    }
    $bad_choice .=  " , R = $R";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 4                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $d * $a1;
    $a3 = $d * $a2 + $b + 1;
    $a4 = $d * $a3;
    $R  = $d * $a4 + $c;
    coeff_prep($a2);
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 3</sup> $a2 x<sup> 2</sup>";
    if ($a3 != 0)
    {
        coeff_prep($a3);
        $bad_choice .= " $a3 x";
    }
    if ($a4 != 0)
    {
         coeff_prep($a4,0);
         $bad_choice .= " $a4";
    }
    $bad_choice .= " , R = $R";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;

        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    $question .= $split;
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $choice_array[$i].$split;
    }
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #312 Generator              ////
////               Polynomials 5                       ////
////              Synth Division 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_312()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $choice_array = array();
    $correct_choice = "";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = rand(1,5);
    $e = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    if ($a == 1)
    {
        $coeff1 = "";
    }
    else if ($a == -1)
    {
        $coeff1 = "-";
    }
    else
    {
        $coeff1 = $a;
    }
    $coeff2 = $b;
    $coeff3 = $c;
    $coeff4 = $d;
    $coeff5 = (-1) * $e;
    coeff_prep($coeff2);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    coeff_prep($coeff5,0);
    $question = "( $coeff1 x<sup> 3</sup> $coeff2 x<sup> 2</sup>";
    $question .= " $coeff3 x $coeff4 ) divided by ( x $coeff5)";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            Correct Answer                         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b;
    $a3 = $e * $a2 + $c;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $correct_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        coeff_prep($a2);
        $correct_choice .= " $a2 x";
    }
    if ($a3 != 0)
    {
        coeff_prep($a3,0);
        $correct_choice .= " $a3";
    }
    $correct_choice .= ", R = $R";
    $choice_array[] = $correct_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 1                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = (-1) * $e * $a1 + $b;
    $a3 = (-1) * $e * $a2 + $c;
    $R  = (-1) * $e * $a4 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 3</sup>";
        if ($a2 != 0)
        {
            coeff_prep($a2);
            $bad_choice .= " $a2 x";
        }
        if ($a3 != 0)
        {
            coeff_prep($a3,0);
            $bad_choice .= " $a3";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 2                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $c;
    $a3 = $e * $a2 + $b;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 3                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b - 1;
    $a3 = $e * $a2 + $c;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 4                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b + 1;
    $a3 = $e * $a2 + $c;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;

        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    $question .= $split;
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $choice_array[$i].$split;
    }
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #313 Generator              ////
////               Polynomials 6                       ////
////              Synth Division 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_313()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $choice_array = array();
    $correct_choice = "";
    $a = rand(1,5);
    $b = rand(1,5);
    $c = rand(1,5);
    $d = rand(1,5);
    $e = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    if ($a == 1)
    {
        $coeff1 = "";
    }
    else if ($a == -1)
    {
        $coeff1 = "-";
    }
    else
    {
        $coeff1 = $a;
    }
    $coeff2 = $b;
    $coeff3 = $c;
    $coeff4 = $d;
    $coeff5 = (-1) * $e;
    coeff_prep($coeff2);
    coeff_prep($coeff3);
    coeff_prep($coeff4,0);
    coeff_prep($coeff5,0);
    $question = "( $coeff1 x<sup> 4</sup> $coeff2 x<sup> 3</sup>";
    $question .= " $coeff3 x $coeff4 ) divided by ( x $coeff5)";
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////            Correct Answer                         ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b;
    $a3 = $e * $a2;
    $a4 = $e * $a3 + $c;
    $R  = $e * $a4 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $correct_choice = " $a1 x<sup> 3</sup>";
    if ($a2 != 0)
    {
        coeff_prep($a2);
        $correct_choice .= " $a2 x<sup> 2</sup>";
    }
    if ($a3 != 0)
    {
        coeff_prep($a3);
        $correct_choice .= " $a3 x";
    }
    if ($a4 != 0)
    {
        coeff_prep($a4,0);
        $correct_choice .= " $a4";
    }
    $correct_choice .= " , R = $R";
    $choice_array[] = $correct_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 1                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = (-1) * $e * $a1 + $b;
    $a3 = (-1) * $e * $a2;
    $a4 = (-1) * $e * $a3 + $c;
    $R  = (-1) * $e * $a4 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 3</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x<sup> 2</sup>";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff);
        $bad_choice .= " $a3 x";
    }
    if ($a4 != 0)
    {
        $coeff = $a4;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 3</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x<sup> 2</sup>";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff);
            $bad_choice .= " $a3 x";
        }
        if ($a4 != 0)
        {
            $coeff = $a4;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 2                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b;
    $a3 = $e * $a2 + $c;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 3                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = (-1) * $e * $a1 + $b;
    $a3 = (-1) * $e * $a2 + $c;
    $R  = (-1) * $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////           Bad Answer 4                            ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    $a1 = $a;
    $a2 = $e * $a1 + $b - 1;
    $a3 = $e * $a2 + $c;
    $R  = $e * $a3 + $d;
    if ($a1 == 1)
    {
        $a1 = "";
    }
    else if ($a1 == -1)
    {
        $a1 = "-";
    }
    $bad_choice = " $a1 x<sup> 2</sup>";
    if ($a2 != 0)
    {
        $coeff = $a2;
        coeff_prep($coeff);
        $bad_choice .= " $coeff x";
    }
    if ($a3 != 0)
    {
        $coeff = $a3;
        coeff_prep($coeff,0);
        $bad_choice .= " $coeff";
    }
    $bad_choice .= " , R = $R";
    if ($bad_choice == $correct_choice)
    {
        $R++;
        $bad_choice = " $a1 x<sup> 2</sup>";
        if ($a2 != 0)
        {
            $coeff = $a2;
            coeff_prep($coeff);
            $bad_choice .= " $coeff x";
        }
        if ($a3 != 0)
        {
            $coeff = $a3;
            coeff_prep($coeff,0);
            $bad_choice .= " $coeff";
        }
        $bad_choice .= " , R = $R";
    }
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;

        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    $question .= $split;
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $choice_array[$i].$split;
    }
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #314 Generator              ////
////               Polynomials 7                       ////
////                Synth Div 4                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_314()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $e = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    $b++;
    $c++;
    $d++;
    if ($a > 4)
    {
        $a = 4;
    }
    if ($b > 4)
    {
        $b = 4;
    }
    if ($c > 4)
    {
        $c = 4;
    }
    if ($d > 4)
    {
        $d = 4;
    }
    $numerator = $e * $e * $e * $a + $e * $e * $b + $e * $c + $d;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    $question .= "Find P( $e ) if <br><br>";
    $question .= "P( x ) = $a x<sup> 3</sup> ";
    if ($b != 0)
    {
        coeff_prep($b);
        $question .= "$b x<sup> 2</sup> ";
    }
    if ($c != 0)
    {
        coeff_prep($c);
        $question .= "$c x ";
    }
    if ($d != 0)
    {
        coeff_prep($d,0);
        $question .= "$d ";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #315 Generator              ////
////               Polynomials 8                       ////
////                Synth Div 5                        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_315()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    $d = rand(1,4);
    $e = rand(1,4);
    $f = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    rand_switch_sign($f,3);
    $b++;
    $c++;
    $d++;
    $e++;
    if ($b > 4)
    {
        $b = 4;
    }
    if ($c > 4)
    {
        $c = 4;
    }
    if ($d > 4)
    {
        $d = 4;
    }
    if ($e > 4)
    {
        $e = 4;
    }
    $numerator = pow($f,4) * $a + pow($f,3) * $b + pow($f,2) * $c + $d * $f + $e;
    if ($a == 1)
    {
        $a = "";
    }
    else if ($a == -1)
    {
        $a = "-";
    }
    $question = "Find P( $f ) if<br><br>";
    $question .= "P( x ) = $a x<sup> 4</sup> ";
    if ($b != 0)
    {
        coeff_prep($b);
        $question .= "$b x<sup> 3</sup> ";
    }
    if ($c != 0)
    {
        coeff_prep($c);
        $question .= "$c x<sup> 2</sup> ";
    }
    if ($d != 0)
    {
        coeff_prep($d);
        $question .= "$d x ";
    }
    if ($e != 0)
    {
        coeff_prep($e,0);
        $question .= "$e";
    }
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #316 Generator              ////
////               Polynomials 9                       ////
////             List Real Zeros 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_316()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@@';
    $mathml="<mml:math xmlns:mml=http://www.w3.org/1998/Math/MathML>";
    $pm = "<mml:mo>\u00b1</mml:mo>";
    
    $choice_array = array();
    $correct_choice = "";
    $a = rand(1,3);
    $b = rand(1,2);
    $c = r_prime(rand(1,3));
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    $coeff1 = (-1) * (2 * $b + $a);
    $coeff2 = pow($b,2) - $c + 2 * $b * $a;
    $coeff3 = (-1) * $a * (pow($b,2) - $c);
    $question = "P( x ) = x<sup> 3</sup>";
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        $question .= "$coeff1 x<sup> 2</sup> ";
    }
    if ($coeff2 != 0)
    {
        coeff_prep($coeff2);
        $question .= "$coeff2 x ";
    }
    coeff_prep($coeff3,0);
    $question .= "$coeff3";
    $question .= $split;
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    ////                                                       ////
    ////                Correct Choice                         ////
    ////                                                       ////
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    $correct_choice = "$mathml <mml:mo>{</mml:mo><mml:mn>$a</mml:mn><mml:mo> ,</mml:mo> <mml:mn>$b</mml:mn>$pm<mml:msqrt><mml:mn>$c</mml:mn></mml:msqrt><mml:mo>}</mml:mo></mml:math>";
    $choice_array[] = $correct_choice;
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    ////                                                       ////
    ////              Bad Choices                              ////
    ////                                                       ////
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    $d = rand(1,3);
    $e = rand(1,3);
    $f = r_prime(rand(4,6));
    if ($d == $b)
    {
        $d++;
    }
    rand_switch_sign($d,3);
    rand_switch_sign($e,3);
    $bad_choice = "$mathml <mml:mo>{</mml:mo><mml:mn>$d</mml:mn><mml:mo> ,</mml:mo> <mml:mn>$b</mml:mn><mml:mo>}</mml:mo></mml:math>";
    $choice_array[] = $bad_choice;
    reduce($e,$f);
    $bad_choice = "$mathml <mml:mo>{</mml:mo><mml:mn>$a</mml:mn><mml:mo> ,</mml:mo> <mml:mfrac><mml:mn>$e</mml:mn> <mml:mn>$f</mml:mn></mml:mfrac><mml:mo>}</mml:mo></mml:math>";
    $choice_array[] = $bad_choice;
    if ($b == 1)
    {
        $h = 2;
    }
    else
    {
        $h = 1;
    }
    rand_switch_sign($h,3);
    $bad_choice = "$mathml <mml:mo>{</mml:mo><mml:mn>$d</mml:mn><mml:mo> ,</mml:mo> <mml:mn>$h</mml:mn>$pm<mml:msqrt><mml:mn>$c</mml:mn></mml:msqrt><mml:mo>}</mml:mo></mml:math>";
    $choice_array[] = $bad_choice;
    $bad_choice = "$mathml <mml:mo>{</mml:mo><mml:mn>$a</mml:mn><mml:mo> ,</mml:mo> <mml:mn>$b</mml:mn>$pm<mml:msqrt><mml:mn>$f</mml:mn></mml:msqrt><mml:mo>}</mml:mo></mml:math>";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;
        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $choice_array[$i].$split;
    }
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #317 Generator              ////
////               Polynomials 10                      ////
////             List Real Zeros 2                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_317()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,4);
    $b = rand(1,4);
    $c = rand(1,4);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    $numerator = "$a";
    if ($b != $a)
    {
        $numerator .= " , $b";
    }
    if ($c != $a && $c != $b)
    {
        $numerator .= " , $c";
    }
    $coeff1 = (-1) * ($a+ $b + $c);
    $coeff2 = ($a * $b) + $c * ($a + $b);
    $coeff3 = (-1) * $a * $b * $c;
    $question = "P( x ) = x<sup> 3</sup> ";
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        $question .= "$coeff1 x<sup> 2</sup> ";
    }
    if ($coeff2 != 0)
    {
        coeff_prep($coeff2);
        $question .= "$coeff2 x ";
    }
    coeff_prep($coeff3,0);
    $question .= "$coeff3";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #317 Generator              ////
////               Polynomials 11                      ////
////             List Real Zeros 3                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_318()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,3);
    $b = rand(1,3);
    $c = rand(1,3);
    $d = rand(1,3);
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    rand_switch_sign($c,3);
    rand_switch_sign($d,3);
    $numerator = $a;
    if ($a != $b)
    {
        $numerator .= " , $b";
    }
    if ($a != $c && $b != $c)
    {
        $numerator .= " , $c";
    }
    if ($a != $d && $b != $d && $c != $d)
    {
        $numerator .= " , $d";
    }
    $coeff1 = (-1) * ($a + $b + $c + $d);
    $coeff2 = $a * $b + $a * $c + $a * $d + $b * $c + $b * $d + $c * $d;
    $coeff3 = (-1) * ($a * $b * $c + $a * $b * $d + $a * $c * $d + $b * $c * $d);
    $coeff4 = $a * $b * $c * $d;
    $question = "P( x ) = x<sup> 4</sup> ";
    if ($coeff1 != 0)
    {
        coeff_prep($coeff1);
        $question .= "$coeff1 x<sup> 3</sup> ";
    }
    if ($coeff2 != 0)
    {
        coeff_prep($coeff2);
        $question .= "$coeff2 x<sup> 2</sup> ";
    }
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $question .= "$coeff3 x ";
    }
    coeff_prep($coeff4,0);
    $question .= "$coeff4";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #319 Generator              ////
////               Polynomials 12                      ////
////           Construct the polynomial                ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_319()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $choice_array = array();
    $correct_choice = "";
    $a = rand(1,6);
    $b = rand(1,6);
    if ($a == $b)
    {
        $b++;
    }
    $c = rand(1,5);
    if ($c == $a)
    {
        $c++;
    }
    if ($c == $b)
    {
        $c++;
    }
    if ($c == 1)
    {
        $c = 0;
    }
    rand_switch_sign($a,3);
    rand_switch_sign($b,3);
    if ($c != 0)
    {
        rand_switch_sign($c,3);
    }
    $question = "Zeros at $a , $b , $c . ";
    $question .= $split;
    if ($c == 0)
    {
        $correct_choice = "x";
    }
    else
    {
        $coeff1 = (-1) * $c;
        coeff_prep($coeff1,0);
        $correct_choice = "( x $coeff1 )";
    }
    $coeff1 = (-1) * $a;
    $coeff2 = (-1) * $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    $correct_choice .= "( x $coeff1 )( x $coeff2 )";
    $choice_array[] = $correct_choice;
    if ($c == 0)
    {
        $bad_choice = "x";
    }
    else
    {
        $coeff1 = (-1) * $c;
        coeff_prep($coeff1,0);
        $bad_choice = "( x $coeff1 )";
    }
    $coeff2 = (-1) * $a;
    $coeff3 = $b;
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    $bad_choice .= "( x $coeff2 )( x $coeff3 )";
    $choice_array[] = $bad_choice;
    if ($c == 0)
    {
        $bad_choice = "x";
    }
    else
    {
        $coeff1 = (-1) * $c;
        coeff_prep($coeff1,0);
        $bad_choice = "( x $coeff1 )";
    }
    $coeff2 = $a;
    $coeff3 = $b;
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    $bad_choice .= "( x $coeff2 )( x $coeff3 )";
    $choice_array[] = $bad_choice;
    $d = rand(1,4);
    if ($d == $c)
    {
        $d++;
    }
    rand_switch_sign($d,3);
    $coeff1 = (-1) * $d;
    $coeff2 = (-1) * $a;
    $coeff3 = (-1) * $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    $bad_choice = "( x $coeff1 )( x $coeff2 )( x $coeff3 )";
    $choice_array[] = $bad_choice;
    $coeff1 = $d;
    $coeff2 = $a;
    $coeff3 = (-1) * $b;
    coeff_prep($coeff1,0);
    coeff_prep($coeff2,0);
    coeff_prep($coeff3,0);
    $bad_choice = "( x $coeff1 )( x $coeff2 )( x $coeff3 )";
    $choice_array[] = $bad_choice;
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////       Randomizes The Choice Array                 ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        $left_switch = rand(1,5) - 1;
        $right_switch = rand(1,5) - 1;
        $temp = $choice_array[$left_switch];
        $choice_array[$left_switch] = $choice_array[$right_switch];
        $choice_array[$right_switch] = $temp;
    }
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ////                                                   ////
    ////             Wraps things up                       ////
    ////                                                   ////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    for ($i = 0; $i < 5; $i++)
    {
        if ($choice_array[$i] == $correct_choice)
        {
             $numerator = $i + 1;
             break;
        }
    }
    for ($i = 0; $i < 5; $i++)
    {
        $question .= $choice_array[$i].$split;
    }
    $answer = array($question,$numerator,$denominator,0,0,29);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #320 Generator              ////
////            Cont. Compund Interest 1               ////
////                 Find A(0)                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_320()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(100000,500000);
    $b = rand(10,150) / 10;
    $t = rand(15,25);
    $question = "How much would you have to invest today at ";
    $question .= "$b% compounded continuously to have $$a in $t years?";
    $b = $b / 100;
    $divisor = exp($b * $t);
    $numerator = $a / $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #321 Generator              ////
////           Cont. Compund Interest 2                ////
////                 Find A(t)                         ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_321()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1000,5000);
    $b = rand(10,150) / 10;
    $t = rand(15,25);
    $question = "How much would you have in your bank account in $t years if you invested";
    $question .= " $$a today at $b% compounded continuously?";
    $b = $b / 100;
    $divisor = exp($b *$t);
    $numerator = $a * $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = "$".$numerator;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #322 Generator              ////
////           Cont. Compund Interest 3                ////
////                   Find t                          ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_322()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1000,5000);
    $b = rand(10,150) / 10;
    $d = rand(15000,25000);
    $question = "About how long would it take for $$a to grow to $$d if ";
    $question .= "it is invested in a bank account earning $b% compounded continuously?";
    $question .= "<br><i>Please round to the nearest second decimal place</i>";
    $b = $b / 100;
    $LHS = $d / $a;
    $LHS = log($LHS);
    $divisor = $b;
    $numerator = $LHS / $divisor;
    $numerator = round($numerator + 0.0001 / pow(10,2),2);
    $numerator = $numerator." years";
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #323 Generator              ////
////            Projectile Problem 1                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_323()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $v = 32 * rand(3,7);
    $question = "A baseball is thrown straight upwards with ";
    $question .= "an initial velocity of $v ft/s.<br>";
    $question .= "At what time(s) does the ball reach ";
    $b = 16 * rand(1,4) + pow($v,2) / 64;
    $question .= "$b feet?";
    $numerator = "n/a".$split."n/a".$split."n/a".$split."n/a".$split."1";
    $answer = array($question,$numerator,$denominator,0,0,30);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #324 Generator              ////
////            Projectile Problem 2                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_324()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $v = 32 * rand(3,7);
    $question = "A baseball is thrown straight upwards with ";
    $question .= "an initial velocity of $v ft/s.<br>";
    $question .= "At what time(s) does the ball reach ";
    $time_to_max = $v / 32;
    $time_diff = rand(1,$time_to_max - 1);
    $num1 = $time_to_max - $time_diff;
    $num2 = $time_to_max + $time_diff;
    $height = (-1) * 16 * $num1 * $num1 + $v * $num1;
    $question .= "$height feet?";
    $numerator = $num1.$split."1".$split.$num2.$split."1".$split."0";
    $answer = array($question,$numerator,$denominator,0,0,30);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #325 Generator              ////
////            Projectile Problem 3                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_325()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $v = 8 * rand(4,8);
    $question = "A baseball is thrown straight upwards with ";
    $question .= "an initial velocity of $v ft/s.<br>";
    $question .= "When does the ball hit the ground again?";
    $numerator = $v;
    $denominator = 16;
    reduce($numerator,$denominator);
    $numerator = $numerator.$split.$denominator.$split."n/a".$split."n/a".$split."0";
    $answer = array($question,$numerator,$denominator,0,0,30);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #326 Generator              ////
////            Projectile Problem 4                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_326()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@@';
    $v = 8 * rand(4,8);
    $question = "A baseball is thrown straight upwards with ";
    $question .= "an initial velocity of $v ft/s.<br>";
    $question .= "When does the ball reach its maximum height?";
    $numerator = $v;
    $denominator = 32;
    reduce($numerator,$denominator);
    $numerator = $numerator.$split.$denominator.$split."n/a".$split."n/a".$split."0";
    $answer = array($question,$numerator,$denominator,0,0,30);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #327 Generator              ////
////            Projectile Problem 5                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_327()
{
    $question = "";
    $numerator = "";
    $denominator = "";
    $split = '@';
    $v = 8 * rand(4,8);
    $question = "A baseball is thrown straight upwards with ";
    $question .= "an initial velocity of $v ft/s.<br>";
    $question .= "What is the maximum height of the ball?";
    $numerator = pow($v,2);
    $denominator = 64;
    reduce($numerator,$denominator);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #328 Generator              ////
////             Decibal Problem 1                     ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_328()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(1,13);
    $power = $a - 16;
    $question = "What is the decibal level of <i>I</i> = 10";
    $question .= "<sup> $power</sup> watts/cm<sup> 2</sup>?";
    $numerator = $a * 10;
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #329 Generator              ////
////             decibal problems 2                    ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_329()
{
    $question = "";
    $numerator = "";
    $denominator = "1";
    $split = '@';
    $a = rand(2,20);
    $question = "How many decibals louder is $a * <i>I</i> then <i>I</i>";
    $question .= "<br> <i> Please round the second decimal place</i>";
    $numerator = 10 * log10($a);
    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question Type #330 Generator               ////
////        Factoring GCD with Neg Powers 1            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_330()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";
    $split       = "@";

    $a = rand(3,9);
    $b = rand(2,$a);

    $pow1 = $a + $b;

    $question = "x^(-$a) + x^(-$pow1)";

    $numerator = "1 + x^($b)";
    $denominator = "x^($pow1)";
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question Type #331 Generator               ////
////        Factoring GCD with Frac Powers             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_331()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";
    $split       = "@";

    $a = 2 * rand(1,4) + 1;
    $b = rand(2,6);

    $pow2 = $a + 2 * $b;

    $question = "x^($a/2) + x^($pow2/2)";

    $numerator = "x^($a/2) ( 1 + x^($b) )";

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question Type #332 Generator               ////
////        Factoring GCD with Neg Powers 2            ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_332()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";
    $split       = "@";

    $a = 2 * rand(1,4) + 1;
    $b = rand(2,6);

    $pow2 = $a + 2 * $b;

    $question = "x^(-$a/2) + x^(-$pow2/2)";

    $numerator   = "1 + x^($b) ";
    $denominator = "x^($pow2/2)";
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,$numerator2,$denominator2,0);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question Type #333 Generator             ////
////     Factoring Binomial GCD with Neg Powers 1      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_333()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 + rand(1,4);
    $c = rand(2,9);
    $d = 2 * rand(1,4);

    while (gmp_gcd($a+$d,$a*$b) > 1)
    {
        $d = 2 * rand(1,4);
    }

    $coeff1 = 1;
    $coeff2 = $b;
    $coeff3 = $a + $d;
    $coeff4 = $b * $a;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    $pow1    = $c+1;

    $question = "$a ( $factor1 )^(-$c) + $d x ( $factor1 )^(-$pow1)";

    $numerator   = $factor2;
    $denominator = "( ".$factor1." )^($pow1)";
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question Type #334 Generator             ////
////     Factoring Binomial GCD with Frac Powers       ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_334()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 + rand(1,4);
    $c = 2 * rand(1,4) - 1;
    $d = 2 * rand(1,4);

    while (gmp_gcd($a+$d,$a*$b) > 1)
    {
        $d = 2 * rand(1,4);
    }

    $coeff1 = 1;
    $coeff2 = $b;
    $coeff3 = $a + $d;
    $coeff4 = $b * $a;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    $pow1    = $c + 2;

    $question = "$a ( $factor1 )^($pow1/2) + $d x ( $factor1 )^($c/2)";

    $numerator   = "( ".$factor1." )^($c/2) ( ".$factor2." )";
    $denominator = 1;

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question Type #335 Generator             ////
////     Factoring Binomial GCD with Neg Powers 2      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_335()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 + rand(1,4);
    $c = 2 * rand(1,4) - 1;
    $d = 2 * rand(1,4);

    while (gmp_gcd($a+$d,$a*$b) > 1)
    {
        $d = 2 * rand(1,4);
    }

    $coeff1 = 1;
    $coeff2 = $b;
    $coeff3 = $a + $d;
    $coeff4 = $b * $a;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    $pow1    = $c + 2;

    $question = "$a ( $factor1 )^(-$c/2) + $d x ( $factor1 )^(-$pow1/2)";

    $numerator   = $factor2;
    $denominator = "( ".$factor1." )^($pow1/2)";
    $numerator="(".$numerator.")/".$denominator;
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #336 Generator              ////
////     Factoring Binomial GCD - DiffQ 1              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_336()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 * rand(1,4);
    $m = rand(3,9);
    $n = rand(3,9);

    /// deal with problems with gcd
    while (gmp_gcd($a,$b) > 1)
    {
        $b = 2 * rand(1,4);
    }

    $coeff1 = $a;
    $coeff2 = (-1) * $b;
    $coeff3 = $a * ($m + $n);
    $coeff4 = (-1) * $b * $n;
    $coeff5 = $a * $m;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    $pow1    = $n - 1;
    $pow2    = $m;
    $pow3    = $n;
    $pow4    = $m - 1;

    $question  = "$n x^($pow1) *( $factor1 )^($pow2) ";
    $question .= "+ $coeff5 x^($pow3)* ( $factor1 )^($pow4)";

    if (gmp_gcd($b*$n,$a*($m+$n)) > 1)
    {
        $coeff6 = gmp_gcd($b*$n,$a*($m + $n));
        $coeff3 = $coeff3 / $coeff6;
        $coeff4 = $coeff4 / $coeff6;

        $coeff2_array = array($coeff3,$coeff4);

        $factor2 = poly_prep($coeff2_array,$var_array);
    }
    else
    {
        $coeff6 = "";
    }

    $numerator   = "$coeff6 x^($pow1)*( $factor1 )^($pow4)*( $factor2 )";
    $denominator = "1";

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #337 Generator              ////
////     Factoring Binomial GCD - DiffQ 2              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_337()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 * rand(1,4);
    $m = rand(3,9);
    $n = rand(3,9);

    /// deal with problems with gcd
    while (gmp_gcd($a,$b) > 1)
    {
        $b = 2 * rand(1,4);
    }

    $coeff1 = $a;
    $coeff2 = (-1) * $b;
    $coeff3 = (-1) * $a * ($m + $n);
    $coeff4 = $b * $n;
    $coeff5 = $a * $m;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    $pow1    = (-1) * ($n + 1);
    $pow2    = (-1) * $m;
    $pow3    = (-1) * $n;
    $pow4    = (-1) * ($m + 1);
    $pow5    = $n + 1;
    $pow6    = $m + 1;


    $question  = "-$n x^($pow1) *( $factor1 )^($pow2) ";
    $question .= "- $coeff5 x^($pow3)* ( $factor1 )^($pow4)";

    if (gmp_gcd($b*$n,$a*($m+$n)) > 1)
    {
        $coeff6 = (-1) * gmp_gcd($b*$n,$a*($m + $n));
        $coeff3 = $coeff3 / $coeff6;
        $coeff4 = $coeff4 / $coeff6;

        $coeff2_array = array($coeff3,$coeff4);

        $factor2 = poly_prep($coeff2_array,$var_array);
        
        $coeff7 = (-1) *  $coeff6;
        $coeff8 = (-1) * $coeff3;
        $coeff9 = (-1) * $coeff4;
        
        $coeff3_array = array($coeff8,$coeff9);
        
        $factor3 = poly_prep($coeff3_array,$var_array);
        $numerator2 = "$coeff7 ( $factor3 )";
    }
    else
    {
        $coeff6 = "";
        $numerator2 = "";
    }

    $numerator   = "$coeff6 ( $factor2 )";
    $denominator = "x^($pow5)*( $factor1 )^($pow6)";
    $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,$numerator2,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #338 Generator              ////
////     Factoring Binomial GCD - DiffQ 3              ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_338()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $p = rand(1,5);
    $q = rand(1,5);
    $c = rand(1,7);
    $d = rand(1,7);
    $s = rand(3,9);

    while ($c == $s)
    {
        $c = rand(1,7);
    }
    while ($d == $s)
    {
        $d = rand(1,7);
    }

    $a = $p * $s;
    $b = $q * $s;

    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $p * $d;

    $num1   = $c;
    $num2   = $c - $s;
    $num3   = $d - $s;
    $num4   = $d;

    $denom1 = $s;
    $denom2 = $s;
    $denom3 = $s;
    $denom4 = $s;

    reduce($num1,$denom1);
    reduce($num2,$denom2);
    reduce($num3,$denom3);
    reduce($num4,$denom4);

    coeff_prep($coeff3);

    $coeff_array = array($coeff1,$coeff2);
    $var_array   = array('x');

    $factor1 = poly_prep($coeff_array,$var_array);

    if ($denom1 != 1)
    {
        $frac1 = $num1."/".$denom1;
    }
    else
    {
        $frac1 = $num1;
    }

    if ($denom2 != 1)
    {
        $frac2 = $num2."/".$denom2;
    }
    else
    {
        $frac2 = $num2;
    }

    if ($denom3 != 1)
    {
        $frac3 = $num3."/".$denom3;
    }
    else
    {
        $frac3 = $num3;
    }

    if ($denom4 != 1)
    {
        $frac4 = $num4."/".$denom4;
    }
    else
    {
        $frac4 = $num4;
    }

    $question  = "( ".$frac1." )*";
    $question .= "x^(".$frac2.")*";
    $question .= "( ".$factor1." )^(".$frac4.")";
    $question .= $coeff3."x^(".$frac1.")*";
    $question .= "( ".$factor1." )^(".$frac3.")";

    $coeff1 = $p * ( $c + $d );
    $coeff2 = $q * $c;
    $f_out  = 1;

    $coeff1_array = array($coeff1,$coeff2);

    $gcd1 = gmp_gcd($coeff1,$coeff2);
    $max1 = get_max($coeff1_array);

    if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
    {
        $f_out  = $gcd1;
        $coeff1 = $coeff1 / $f_out;
        $coeff2 = $coeff2 / $f_out;

        $coeff1_array = array($coeff1,$coeff2);
    }

    $factor2 = poly_prep($coeff1_array,$var_array);

    if ($f_out == 1)
    {
        $f_out = "";
    }

    if ($num2 < 0)
    {
        $num2        = $num2 * (-1);
        if ($denom2 != 1)
        {
            $frac2 = $num2."/".$denom2;
        }
        else
        {
            $frac2 = $num2;
        }
        $denominator = "x^(".$frac2.")";
    }
    else
    {
        $numerator = "x^(".$frac2.")";
    }

    if ($num3 < 0)
    {
        $num3         = $num3 * (-1);
        if ($denom3 != 1)
        {
            $frac3 = $num3."/".$denom3;
        }
        else
        {
            $frac3 = $num3;
        }
        $denominator .= "( ".$factor1." )^(".$frac3.")";
    }
    else
    {
        $numerator .= "( ".$factor1." )^(".$frac3.")";
    }

    $numerator = $f_out.$numerator."( ".$factor2." )";

    if (!strlen($denominator))
    {
        $denominator = "1";
    }
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #339 Generator              ////
////        Factoring - Psuedo Quadratic 1             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_339()
{
    $question     = "";
    $numerator    = "";
    $numerator2   = "";
    $denominator  = "1";
    $denominator2 = "1";
    $debug        = FALSE;

    $a     = rand(1,9);
    $b     = rand(1,9);
    $r     = rand(1,9);
    $s     = rand(1,9);
    $f_out = 1;
    $out   = FALSE;

    rand_switch_sign($b,3);
    rand_switch_sign($r,3);
    rand_switch_sign($s,3);

    if ($debug)
    {
        echo "<br> a $a <br>";
        echo "<br> b $b <br>";
        echo "<br> s $s <br>";
        echo "<br> r $r <br>";
    }

    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $r + $s;
    $coeff4 = $r * $s;
    $coeff5 = $a;
    $coeff6 = $b + $r;
    $coeff7 = $a;
    $coeff8 = $b + $s;

    coeff_prep($coeff4,0);

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff5,$coeff6);
    $coeff3_array = array($coeff7,$coeff8);

    $var_array = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);
    $factor3 = poly_prep($coeff3_array,$var_array);

    $question = "( ".$factor1." )^(2) ";
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $question .= $coeff3."( ".$factor1." ) ";
    }
    $question .= $coeff4;

    if ($coeff6 != 0 && $coeff8 != 0)
    {
        $f_out1 = 1;
        $f_out2 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $gcd2 = gmp_gcd(abs($coeff7),abs($coeff8));

        $max1 = get_max(array($coeff5,$coeff6));
        $max2 = get_max(array($coeff7,$coeff8));

        if ($debug)
        {
            echo "<br> gcd1 $gcd1 <br>";
            echo "<br> gcd2 $gcd2 <br>";
            echo "<br> max1 $max1 <br>";
            echo "<br> max2 $max2 <br>";
        }

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }
        if ($gcd2 > 1 && ($gcd2 < $max2 || $gcd2 == $max2))
        {
            $f_out2 = $gcd2;
            $coeff7 = $coeff7 / $f_out2;
            $coeff8 = $coeff8 / $f_out2;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out2;
        }

        if ($coeff5 == $coeff7 && $coeff6 == $coeff8)
        {
            $numerator = "( ".$factor2." )^(2)";
            $numerator2 = "( ".$factor2." )( ".$factor2." )";
        }
        else
        {
            $numerator  = "( ".$factor2." )( ".$factor3." )";
            $numerator2 = $numerator;
        }

        if ($out)
        {
            $numerator = $f_out.$numerator;
        }
    }
    else if ($coeff6 == 0 && $coeff8 == 0)
    {
        $coeff9 = pow($a,2);
        $numerator  = $coeff9."x^(2)";
        $numerator2 = $numerator;
    }
    else if ($coeff8 == 0) // coeff6 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $max1 = get_max(array($coeff5,$coeff6));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff7  = $coeff7 * $f_out;
            $factor3 = $coeff7." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }
    else // coeff6 == 0 && coeff8 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff7),abs($coeff8));
        $max1 = get_max(array($coeff7,$coeff8));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff7 = $coeff7 / $f_out1;
            $coeff8 = $coeff8 / $f_out1;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff5  = $coeff5 * $f_out;
            $factor2 = $coeff5." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }

    if ($debug)
    {
        echo "<br> numerator $numerator <br>";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #340 Generator              ////
////        Factoring - Psuedo Quadratic 2             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_340()
{
    $question     = "";
    $numerator    = "";
    $numerator2   = "";
    $denominator  = "1";
    $denominator2 = "1";
    $debug        = FALSE;

    $a     = rand(1,9);
    $b     = rand(1,9);
    $r     = rand(1,9);
    $s     = rand(1,9);
    $p     = r_prime(rand(1,4));
    $q     = 1;
    $f_out = 1;
    $out   = FALSE;

    rand_switch_sign($b,3);
    rand_switch_sign($r,3);
    rand_switch_sign($s,3);

    if ($debug)
    {
        echo "<br> q $q <br>";
        echo "<br> p $p <br>";
        echo "<br> a $a <br>";
        echo "<br> b $b <br>";
        echo "<br> s $s <br>";
        echo "<br> r $r <br>";
    }

    $coeff0 = $p * $q;
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $q * $r + $p * $s;
    $coeff4 = $r * $s;
    $coeff5 = $q * $a;
    $coeff6 = $q * $b + $s;
    $coeff7 = $p * $a;
    $coeff8 = $p * $b + $r;

    coeff_prep($coeff4,0);

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff5,$coeff6);
    $coeff3_array = array($coeff7,$coeff8);

    $var_array = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);
    $factor3 = poly_prep($coeff3_array,$var_array);

    $question = "$coeff0 ( ".$factor1." )^(2) ";
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $question .= $coeff3."( ".$factor1." ) ";
    }
    $question .= $coeff4;

    if ($coeff6 != 0 && $coeff8 != 0)
    {
        $f_out1 = 1;
        $f_out2 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $gcd2 = gmp_gcd(abs($coeff7),abs($coeff8));

        $max1 = get_max(array($coeff5,$coeff6));
        $max2 = get_max(array($coeff7,$coeff8));

        if ($debug)
        {
            echo "<br> gcd1 $gcd1 <br>";
            echo "<br> gcd2 $gcd2 <br>";
            echo "<br> max1 $max1 <br>";
            echo "<br> max2 $max2 <br>";
        }

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }
        if ($gcd2 > 1 && ($gcd2 < $max2 || $gcd2 == $max2))
        {
            $f_out2 = $gcd2;
            $coeff7 = $coeff7 / $f_out2;
            $coeff8 = $coeff8 / $f_out2;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out2;
        }

        if ($coeff5 == $coeff7 && $coeff6 == $coeff8)
        {
            $numerator = "( ".$factor2." )^(2)";
            $numerator2 = "( ".$factor2." )( ".$factor2." )";
        }
        else
        {
            $numerator  = "( ".$factor2." )( ".$factor3." )";
            $numerator2 = $numerator;
        }

        if ($out)
        {
            $numerator = $f_out.$numerator;
        }
    }
    else if ($coeff6 == 0 && $coeff8 == 0)
    {
        $coeff9 = $p * $q * pow($a,2);
        $numerator  = $coeff9."x^(2)";
        $numerator2 = $numerator;
    }
    else if ($coeff8 == 0) // coeff6 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $max1 = get_max(array($coeff5,$coeff6));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff7  = $coeff7 * $f_out;
            $factor3 = $coeff7." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }
    else // coeff6 == 0 && coeff8 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff7),abs($coeff8));
        $max1 = get_max(array($coeff7,$coeff8));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff7 = $coeff7 / $f_out1;
            $coeff8 = $coeff8 / $f_out1;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff5  = $coeff5 * $f_out;
            $factor2 = $coeff5." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }

    if ($debug)
    {
        echo "<br> numerator $numerator <br>";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #341 Generator              ////
////        Factoring - Psuedo Quadratic 3             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_341()
{
    $question     = "";
    $numerator    = "";
    $numerator2   = "";
    $denominator  = "1";
    $denominator2 = "1";
    $debug        = FALSE;

    $a     = rand(1,9);
    $b     = rand(1,9);
    $r     = rand(1,9);
    $s     = rand(1,9);
    $p     = rand(2,9);
    $q     = 1;
    $f_out = 1;
    $out   = FALSE;

    rand_switch_sign($b,3);
    rand_switch_sign($r,3);
    rand_switch_sign($s,3);

    if ($debug)
    {
        echo "<br> q $q <br>";
        echo "<br> p $p <br>";
        echo "<br> a $a <br>";
        echo "<br> b $b <br>";
        echo "<br> s $s <br>";
        echo "<br> r $r <br>";
    }

    $coeff0 = $p * $q;
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $q * $r + $p * $s;
    $coeff4 = $r * $s;
    $coeff5 = $q * $a;
    $coeff6 = $q * $b + $s;
    $coeff7 = $p * $a;
    $coeff8 = $p * $b + $r;

    coeff_prep($coeff4,0);

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff5,$coeff6);
    $coeff3_array = array($coeff7,$coeff8);

    $var_array = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);
    $factor3 = poly_prep($coeff3_array,$var_array);

    $question = "$coeff0 ( ".$factor1." )^(2) ";
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $question .= $coeff3."( ".$factor1." ) ";
    }
    $question .= $coeff4;

    if ($coeff6 != 0 && $coeff8 != 0)
    {
        $f_out1 = 1;
        $f_out2 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $gcd2 = gmp_gcd(abs($coeff7),abs($coeff8));

        $max1 = get_max(array($coeff5,$coeff6));
        $max2 = get_max(array($coeff7,$coeff8));

        if ($debug)
        {
            echo "<br> gcd1 $gcd1 <br>";
            echo "<br> gcd2 $gcd2 <br>";
            echo "<br> max1 $max1 <br>";
            echo "<br> max2 $max2 <br>";
        }

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }
        if ($gcd2 > 1 && ($gcd2 < $max2 || $gcd2 == $max2))
        {
            $f_out2 = $gcd2;
            $coeff7 = $coeff7 / $f_out2;
            $coeff8 = $coeff8 / $f_out2;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out2;
        }

        if ($coeff5 == $coeff7 && $coeff6 == $coeff8)
        {
            $numerator = "( ".$factor2." )^(2)";
            $numerator2 = "( ".$factor2." )( ".$factor2." )";
        }
        else
        {
            $numerator  = "( ".$factor2." )( ".$factor3." )";
            $numerator2 = $numerator;
        }

        if ($out)
        {
            $numerator = $f_out.$numerator;
        }
    }
    else if ($coeff6 == 0 && $coeff8 == 0)
    {
        $coeff9 = $p * $q * pow($a,2);
        $numerator  = $coeff9."x^(2)";
        $numerator2 = $numerator;
    }
    else if ($coeff8 == 0) // coeff6 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $max1 = get_max(array($coeff5,$coeff6));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff7  = $coeff7 * $f_out;
            $factor3 = $coeff7." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }
    else // coeff6 == 0 && coeff8 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff7),abs($coeff8));
        $max1 = get_max(array($coeff7,$coeff8));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff7 = $coeff7 / $f_out1;
            $coeff8 = $coeff8 / $f_out1;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff5  = $coeff5 * $f_out;
            $factor2 = $coeff5." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }

    if ($debug)
    {
        echo "<br> numerator $numerator <br>";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #342 Generator              ////
////        Factoring - Psuedo Quadratic 4             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_342()
{
    $question     = "";
    $numerator    = "";
    $numerator2   = "";
    $denominator  = "1";
    $denominator2 = "1";
    $debug        = FALSE;

    $a     = rand(1,9);
    $b     = rand(1,9);
    $r     = r_prime(rand(1,4));
    $s     = r_prime(rand(1,4));
    $p     = r_prime(rand(1,4));
    $q     = r_prime(rand(1,4));
    $f_out = 1;
    $out   = FALSE;

    rand_switch_sign($b,3);
    rand_switch_sign($r,3);
    rand_switch_sign($s,3);

    if ($debug)
    {
        echo "<br> q $q <br>";
        echo "<br> p $p <br>";
        echo "<br> a $a <br>";
        echo "<br> b $b <br>";
        echo "<br> s $s <br>";
        echo "<br> r $r <br>";
    }

    $coeff0 = $p * $q;
    $coeff1 = $a;
    $coeff2 = $b;
    $coeff3 = $q * $r + $p * $s;
    $coeff4 = $r * $s;
    $coeff5 = $q * $a;
    $coeff6 = $q * $b + $s;
    $coeff7 = $p * $a;
    $coeff8 = $p * $b + $r;

    coeff_prep($coeff4,0);

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff5,$coeff6);
    $coeff3_array = array($coeff7,$coeff8);

    $var_array = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);
    $factor3 = poly_prep($coeff3_array,$var_array);

    $question = "$coeff0 ( ".$factor1." )^(2) ";
    if ($coeff3 != 0)
    {
        coeff_prep($coeff3);
        $question .= $coeff3."( ".$factor1." ) ";
    }
    $question .= $coeff4;

    if ($coeff6 != 0 && $coeff8 != 0)
    {
        $f_out1 = 1;
        $f_out2 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $gcd2 = gmp_gcd(abs($coeff7),abs($coeff8));

        $max1 = get_max(array($coeff5,$coeff6));
        $max2 = get_max(array($coeff7,$coeff8));

        if ($debug)
        {
            echo "<br> gcd1 $gcd1 <br>";
            echo "<br> gcd2 $gcd2 <br>";
            echo "<br> max1 $max1 <br>";
            echo "<br> max2 $max2 <br>";
        }

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }
        if ($gcd2 > 1 && ($gcd2 < $max2 || $gcd2 == $max2))
        {
            $f_out2 = $gcd2;
            $coeff7 = $coeff7 / $f_out2;
            $coeff8 = $coeff8 / $f_out2;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out2;
        }

        if ($coeff5 == $coeff7 && $coeff6 == $coeff8)
        {
            $numerator = "( ".$factor2." )^(2)";
            $numerator2 = "( ".$factor2." )( ".$factor2." )";
        }
        else
        {
            $numerator  = "( ".$factor2." )( ".$factor3." )";
            $numerator2 = $numerator;
        }

        if ($out)
        {
            $numerator = $f_out.$numerator;
        }
    }
    else if ($coeff6 == 0 && $coeff8 == 0)
    {
        $coeff9 = $p * $q * pow($a,2);
        $numerator  = $coeff9."x^(2)";
        $numerator2 = $numerator;
    }
    else if ($coeff8 == 0) // coeff6 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff5),abs($coeff6));
        $max1 = get_max(array($coeff5,$coeff6));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff5 = $coeff5 / $f_out1;
            $coeff6 = $coeff6 / $f_out1;

            $coeff2_array = array($coeff5,$coeff6);
            $factor2      = poly_prep($coeff2_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff7  = $coeff7 * $f_out;
            $factor3 = $coeff7." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }
    else // coeff6 == 0 && coeff8 != 0
    {
        $f_out1 = 1;

        $gcd1 = gmp_gcd(abs($coeff7),abs($coeff8));
        $max1 = get_max(array($coeff7,$coeff8));

        if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
        {
            $f_out1 = $gcd1;
            $coeff7 = $coeff7 / $f_out1;
            $coeff8 = $coeff8 / $f_out1;

            $coeff3_array = array($coeff7,$coeff8);
            $factor3      = poly_prep($coeff3_array,$var_array);

            $out   = TRUE;
            $f_out = $f_out * $f_out1;
        }

        if ($out)
        {
            $coeff5  = $coeff5 * $f_out;
            $factor2 = $coeff5." x";
        }

        $numerator  = "( ".$factor2." )( ".$factor3." )";
        $numerator2 = $numerator;
    }

    if ($debug)
    {
        echo "<br> numerator $numerator <br>";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #343 Generator              ////
////        Factoring - Psuedo Quadratic 5             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_343()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = rand(1,9);
    $b = rand(1,9);

    $coeff1 = $a + $b;
    $coeff2 = $a * $b;

    $coeff_array = array(1,$coeff1,$coeff2);
    $var_array   = array('x^(4)','x^(2)');

    $question = poly_prep($coeff_array,$var_array);

    $coeff1 = 1;
    $coeff2 = $a;
    $coeff3 = 1;
    $coeff4 = $b;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);

    $var_array = array('x^(2)');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    if ($a == $b)
    {
        $numerator = "( ".$factor1." )^(2)";
    }
    else
    {
        $numerator = "( ".$factor1." )( ".$factor2." )";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #344 Generator              ////
////        Factoring - Psuedo Quadratic 6             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_344()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = r_prime(rand(1,4));
    $b = r_prime(rand(1,4));
    $p = r_prime(rand(1,4));
    $q = r_prime(rand(1,4));

    $coeff1 = $p * $q;
    $coeff2 = $p * $b + $q * $a;
    $coeff3 = $a * $b;

    $coeff_array = array($coeff1,$coeff2,$coeff3);
    $var_array   = array('x^(4)','x^(2)');

    $question = poly_prep($coeff_array,$var_array);

    $coeff1 = $p;
    $coeff2 = $a;
    $coeff3 = $q;
    $coeff4 = $b;
    $f_out  = 1;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);

    $gcd1 = gmp_gcd($coeff1,$coeff2);
    $gcd2 = gmp_gcd($coeff3,$coeff4);
    $max1 = get_max($coeff1_array);
    $max2 = get_max($coeff2_array);

    if ($gcd1 > 1 && ($gcd1 < $max1 || $gcd1 == $max1))
    {
        $f_out1 = $gcd1;
        $coeff1 = $coeff1 / $f_out1;
        $coeff2 = $coeff2 / $f_out1;

        $coeff1_array = array($coeff1,$coeff2);
        $f_out        = $f_out * $f_out1;
    }

    if ($gcd2 > 1 && ($gcd2 < $max2 || $gcd2 == $max2))
    {
        $f_out2 = $gcd2;
        $coeff3 = $coeff3 / $f_out2;
        $coeff4 = $coeff4 / $f_out2;

        $coeff2_array = array($coeff3,$coeff4);
        $f_out        = $f_out * $f_out2;
    }

    if ($f_out == 1)
    {
        $f_out = "";
    }

    $var_array = array('x^(2)');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    if ($a == $b && $p==$q)
    {
        $numerator = $f_out."( ".$factor1." )^(2)";
    }
    else
    {
      $numerator = $f_out."( ".$factor1." )( ".$factor2." )";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #345 Generator              ////
////        Factoring - Psuedo Quadratic 7             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_345()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = rand(1,9);
    $b = rand(1,9);

    $coeff1 = $a + $b;
    $coeff2 = $a * $b;

    $coeff_array = array(1,$coeff1,$coeff2);
    $var_array   = array('x^(4/3)','x^(2/3)');

    $question = poly_prep($coeff_array,$var_array);

    $coeff1 = 1;
    $coeff2 = $a;
    $coeff3 = 1;
    $coeff4 = $b;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);

    $var_array = array('x^(2/3)');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    if ($a == $b)
    {
        $numerator = "( ".$factor1." )^(2)";
    }
    else
    {
        $numerator = "( ".$factor1." )( ".$factor2." )";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #346 Generator              ////
////        Factoring - Psuedo Quadratic 8             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_346()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = rand(1,9);
    $b = rand(1,9);
    $c = rand(1,9);

    $coeff1 = $a * $b;
    $coeff2 = $a + $b;
    $coeff3 = 1;
    $coeff4 = $c;

    $coeff1_array = array(1,$coeff4);
    $var1_array   = array('x');

    $factor1 = poly_prep($coeff1_array,$var1_array);

    $var1 = "( ".$factor1." )^(1/2)";
    $var2 = "( ".$factor1." )^(3/2)";
    $var3 = "( ".$factor1." )^(5/2)";

    $coeff_array = array($coeff1,$coeff2,$coeff3,0);
    $var_array   = array($var1,$var2,$var3);

    $question = poly_prep($coeff_array,$var_array);

    $coeff1 = 1;
    $coeff2 = $c;
    $coeff3 = 1;
    $coeff4 = $c + $a;
    $coeff5 = 1;
    $coeff6 = $c + $b;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $coeff3_array = array($coeff5,$coeff6);

    $var_array = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);
    $factor3 = poly_prep($coeff3_array,$var_array);

    if ($coeff4 == $coeff6)
    {
        $numerator  = "( ".$factor1." )^(1/2)";
        $numerator .= "( ".$factor2." )^(2)";
    }
    else
    {
        $numerator  = "( ".$factor1." )^(1/2)";
        $numerator .= "( ".$factor2." )( ".$factor3." )";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////         Question Type #347 Generator              ////
////        Factoring - Psuedo Quadratic 9             ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_347()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = rand(1,9);
    $b = rand(1,9);

    $coeff1 = $a + $b;
    $coeff2 = $a * $b;

    $coeff_array = array(1,$coeff1,$coeff2);
    $var_array   = array('x','sqrt(x)');

    $question = poly_prep($coeff_array,$var_array);

    $coeff1 = 1;
    $coeff2 = $a;
    $coeff3 = 1;
    $coeff4 = $b;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);

    $var_array = array('sqrt(x)');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);

    if ($a == $b)
    {
        $numerator = "( ".$factor1." )^(2)";
    }
    else
    {
        $numerator = "( ".$factor1." )( ".$factor2." )";
    }

    $answer = array($question,$numerator,$denominator,0,0,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question Type #348 Generator               ////
////        Factoring GCD with Neg & Pos Powers 1      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_348()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = rand(2,6);
    $b = rand(2,6);

    $pow2 = $a + $b;

    $question = "x^($a) + x^(-$b)";

    $numerator   = "1 + x^($pow2) ";
    $denominator = "x^($b)";
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,$numerator2,$denominator2,0);
    return $answer;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////        Question Type #349 Generator               ////
////        Factoring GCD with Neg & Pos Powers 2      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_349()
{
    $question    = "";
    $numerator   = "";
    $denominator = "1";

    $a = 2 * rand(1,4) + 1;
    $b = 2 * rand(1,4) + 1;

    $pow2 = ($a + $b) / 2;

    $question = "x^($a/2) + x^(-$b/2)";

    $numerator   = "1 + x^($pow2) ";
    $denominator = "x^($b/2)";
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,$numerator2,$denominator2,0);
    return $answer;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////          Question Type #350 Generator             ////
////     Factoring Binomial GCD with Neg Powers 2      ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function gen_350()
{
    $question    = "";
    $numerator   = "";
    $denominator = "";

    $a = 2 * rand(1,4) + 1;
    $b = 2 + rand(1,4);
    $d = 2 * rand(1,4);

    while (gmp_gcd($a+$d,$a*$b) > 1)
    {
        $d = 2 * rand(1,4);
    }

    $coeff1 = 1;
    $coeff2 = $b;
    $coeff3 = $a + $d;
    $coeff4 = $b * $a;

    $coeff1_array = array($coeff1,$coeff2);
    $coeff2_array = array($coeff3,$coeff4);
    $var_array    = array('x');

    $factor1 = poly_prep($coeff1_array,$var_array);
    $factor2 = poly_prep($coeff2_array,$var_array);


    $question = "$a ( $factor1 )^(1/2) + $d x ( $factor1 )^(-1/2)";

    $numerator   = $factor2;
    $denominator = "( ".$factor1." )^(1/2)";
    if($denominator!="1")
     $numerator="(".$numerator.")/(".$denominator.")";
    $answer = array($question,$numerator,1,0,0,0);
    return $answer;
}
function neg($a)
{
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }
    return $a1;
}
function neg1($a)
{
    $a1=$a;
	  if($a<-1)
	  {
       $a1="~".abs($a);
    }else if ($a == -1)
    {
        $a1 = "~";
    }
    return $a1;
}

?>
