<?php
// cleans up strings in three ways, first trims, then set all alpha
// characters to lowercase, and final takes away all the * signs
function str_cleanup(&$my_string,$times_remove = 1)
{
    $my_string = trim($my_string);
    if ($times_remove == 1)
    {
        $my_string = str_replace('*','',$my_string);
    }
}

//str_split function
function str_split1($str,$num = 1)
{
    if ($num < 1 )
    {
        return FALSE;
    }
    $arr = array();
    for ($j = 0 ; $j < strlen($str); $j = $j + $num)
    {
        $arr[]=substr($str,$j,$num);
    }

    return $arr;
}
//// creates a decent looking fraction
function str_frac($numerator,$denominator)
{
    $numerator = (string)$numerator;
    $denominator = (string)$denominator;
    $result = "<sup>".$numerator."</sup><bold><big>/</big></bold><sub>";
    $result = $result.$denominator."</sub>";
    return $result;
}
//// takes caps to lowercase
//// removes all * signs
//// inserts <sup> </sup> for exponents
//// replaces sqrt( * ) with the square root sign
//// replaces cbrt( * ) with a cube root sign
function str_to_math($str,$times_remove = 1)
{
    $exp =0;
    $pexp =0;
    str_cleanup($str,$times_remove);

    $answer_array = str_split1($str);
    $a = (string)"";
    $length = strlen($str);


    for ($i = 0; $i < $length; $i++)
    {
    if ($answer_array[$i] == "^")
    {
        $i++;
        $exp = 1;
        $newstring = $newstring."<span class='super'><sup>&nbsp; ";
            if ($answer_array[$i] == "(")
            {
                $i++;
                $pexp = 1;
            }
            while ($i < $length)
            {
                if ($answer_array[$i] == ")" || $answer_array[$i] == "(" )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "x" || $answer_array[$i] == "y" )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "a" || $answer_array[$i] == "b" )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "c" || $answer_array[$i] == " " )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "+" || $answer_array[$i] == "s" )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "f" || $answer_array[$i] == "n" )
                {
                    $i--;
                    break;
                }

                if ($answer_array[$i] == "k" || $answer_array[$i] == "m" )
                {
                    $i--;
                    break;
                }
                   // test  
		   // if ($answer_array[$i] == "/" || $pexp != 1 )
		   // {
		   // $i--;
		   // break;
		   // }
		// end test`


                if ($answer_array[$i] == "h" || $answer_array[$i] == "z" )
                {
                    $i--;
                    break;
                }
                if ($answer_array[$i] == "-" && $answer_array[$i-1] != "(" && $answer_array[$i-1] != "^")
                {
                    $i--;
                    break;
                }
                $a = $answer_array[$i];
                $newstring = $newstring.$a;
                $i++;
            }
        }
	// else if($answer_array[$i] == "/")
	// {
	// $i++;
	// $a = $answer_array[$i];
	// $sfrac = str_frac("",$a);
	// $newstring = $newstring.$sfrac;
	// } // end of else if($answer_array[$i] == "/")
        else
        {
            $a = $answer_array[$i];
            $newstring = $newstring.$a;
        }
        if ($pexp == 1)
        {
            $i++;
            $pexp = 0;
        }
        if ($exp == 1)
        {
            $newstring = $newstring."&nbsp;</sup></span>";
            $exp=0;
        }
    }
    //// Replace all "sqrt( ~~~ )" with a proper, displayable square root sign
    $pos = strpos($newstring, 'sqrt(');
    while($pos !== FALSE)
    {
        $newstring = substr_replace($newstring, '<FONT FACE="Symbol">&#214;</FONT><span class="root">',$pos, 5);

        $newpos = strpos($newstring, '(', $pos + 1);

        $pos = strpos($newstring, ')', $pos + 1);

        if($newpos === TRUE && $newpos < $pos)
        {
            while($newpos < $pos && $newpos === TRUE)
            {
                $newpos = strpos($newstring, '(', $newpos + 1);
            }
        }

        $newstring = substr_replace($newstring, '</span>', $pos, 1);

        $pos = strpos($newstring, 'sqrt(');
    }

    //// Replace all "cbrt( ~~~ )" with a proper, displayable cube root sign

    $pos = strpos($newstring, 'cbrt(');

    while($pos !== FALSE)
    {
        $newstring = substr_replace($newstring, '<span class="rootnum"><sup>3</sup></span><FONT FACE="Symbol">&#214;</FONT><span class="root">',$pos, 5);

        $newpos = strpos($newstring, '(', $pos + 1);

        $pos = strpos($newstring, ')', $pos + 1);

        if($newpos === TRUE && $newpos < $pos)
        {
            while($newpos < $pos && $newpos === TRUE)
            {
                $newpos = strpos($newstring, '(', $newpos + 1);
            }
        }

        $newstring = substr_replace($newstring, '</span>', $pos, 1);

        $pos = strpos('cbrt(', $newstring);
    }

    //// Replace all "ftrt( ~~~ )" with a proper, displayable fourth root sign

    $pos = strpos($newstring, 'ftrt(');

    while($pos !== FALSE)
    {
        $newstring = substr_replace($newstring, '<span class="rootnum"><sup>4</sup></span><FONT FACE="Symbol">&#214;</FONT><span class="root">',$pos, 5);

        $newpos = strpos($newstring, '(', $pos + 1);

        $pos = strpos($newstring, ')', $pos + 1);

        if($newpos === TRUE && $newpos < $pos)
        {
            while($newpos < $pos && $newpos === TRUE)
            {
                $newpos = strpos($newstring, '(', $newpos + 1);
            }
        }

        $newstring = substr_replace($newstring, '</span>', $pos, 1);

        $pos = strpos('ftrt(', $newstring);
    }


    return $newstring;
}

//// This is the function for echo-ing out questions.  It handles simple fractional and
//// non-fractional output

function simple_out($numerator,$denominator = 1,$dash_length = 0)
{
    str_cleanup($numerator,0);
    str_cleanup($denominator,0);

    if (!strlen($denominator))
    {
        $denominator = 1;
    }

    $return_string .= "<center>\n";
    $return_string .= "<table border=0 cellpadding=0 cellspacing=1 ><tr><td align='center'>\n";
    $return_string .= "$numerator</td></tr>\n";

    if ($denominator == "1" || $denominator == 1 && strlen($denominator) == 1)  // Non-fractional output
    {
        $return_string .= "</table></center>\n";
        return $return_string;
    }
    else if ($denominator == "0")
    {
        $return_string .= "error in question...division by zero not allowed\n";
        return $return_string;
    }
    else  // Fraction
    {
    if ($dash_length == 0)
    {
            $num_length = strlen($numerator);
            $denom_length = strlen($denominator);
            $temp = 0;
            if ($num_length >= $denom_length)
            {
                $temp = $num_length / 2;
            }
            else // $denom_length > $num_length
            {
                $temp = $denom_length / 2;
            }
        }
        else // $dash_length given
        {
            //// do nothing
        }
        $temp = $dash_length * 3;
        if ($temp < 10)
        {
            $temp = 10;
        }
    $return_string .= "<tr><td align='center'><span class='midline'>"
        ."<img src='Images/1px.gif' width='$temp' height='1'></span>"
        ."</tr></td><tr><td align='center'>"
        ."$denominator </td></tr></table></center>\n";

        return $return_string;
    }
}

function coeff_prep(&$my_coeff,$var_coeff = 1)
{
    $temp = TRUE;
    if ($var_coeff == 1)
    {
        if ($my_coeff == 0)
        {
            $temp = FALSE;
            return $temp;
        }
        if ($my_coeff == 1)
        {
            $my_coeff = " + ";
            return $temp;
        }
        if ($my_coeff == -1)
        {
            $my_coeff = " - ";
            return $temp;
        }

    }
    else // $my_coeff is not a variable coeff
    {
        if ($my_coeff == 0)
        {
            $my_coeff = " ";
            $temp = FALSE;
            return $temp;
        }
    }
    if ($my_coeff > 0)
        $my_coeff = "+".$my_coeff;
    else
    {
        $my_coeff = $my_coeff * (-1);
        $my_coeff = "-".$my_coeff;
    }
    return $temp;
}

function r_prime($i)
{
    $temp = 0;
    if ($i == 1)
        $temp = 2;
    else if ($i == 2)
        $temp = 3;
    else if ($i == 3)
        $temp = 5;
    else if ($i == 4)
        $temp = 7;
    else if ($i == 5)
        $temp = 11;
    else if ($i == 6)
        $temp = 13;
    else
        $temp = 17;
    return $temp;
}


function question_type_string($q_type)
{
    $string_return = array(
            "Multiplication of Proper Fractions",
            "Multiplication of Mixed Numbers",
            "Division: Integer by Unit Fraction",
            "Division: Mixed Number by Integer",
            "Division: Two Mixed Numbers",
            "Addition of Proper Fractions",
            "Addition of Mixed Numbers",
            "Subtraction of Proper Fractions",
            "Subtraction of Mixed Numbers",
            "Zero In Numerator or Denominator 1",
            "Zero in Numerator or Denominator 2",
            "Properties of Fractions",
            "Order of Operations 1",
            "Order of Operations 2",
            "Order of Operations 3",
            "Order of Operations 4",
            "Integer Exponents 1",
            "Integer Exponents 2",
            "Integer Exponents 3",
            "Integer Exponents 4",
            "Integer Exponents 5",
            "Integer Exponents 6",
            "Integer Exponents 7",
            "Integer Exponents with Integer Bases",
            "Evaluate with Rational Exponents 1",
            "Evaluate with Rational Exponents 2",
            "Evaluate with Rational Exponents 3",
            "Simplify with Rational Exponents 1",
            "Simplify with Rational Exponents 2",
            "Simplify with Rational Exponents 3",
            "Simplify with Rational Exponents 4",
            "Simplify with Rational Exponents 5",
            "Simplify with Rational Exponents 6",
            "Simplify with Rational Exponents 7",
            "Simplify with Rational Exponents 8",
            "Simplify with Rational Exponents 9",
            "Simplify with Rational Exponents 10",
            "Simplify with Rational Exponents 11",
            "Simplify with Rational Exponents 12",
            "Polynomial Addition/Subtraction",
            "Binomial Multiplication 1",
            "Binomial Multiplication 2",
            "Binomial Multiplication 3",
            "Squaring a Binomial",
            "Binomial/Trinomial Multiplication 1",
            "Binomial/Trinomial Multiplication 2",
            "Trinomial Multiplication 1",
            "Trinomial Multiplication 2",
            "Cubing a binomial 1",
            "Cubing a binomial 2",
            "Cubing a binomial 3",
            "Factoring GCF",
            "Factoring Difference of Squares 1",
            "Factoring Difference of Squares 2",
            "Factoring Difference of Squares 3",
            "Factoring Trinomials 1",
            "Factoring Trinomials 2",
            "Factoring Trinomials 3",
            "Factoring Trinomials with GCF 1",
            "Factoring Trinomials with GCF 2",
            "Factoring Trinomials with GCF 3",
            "Factoring Trinomials with GCF 4",
            "Factoring difference/sum of cubes 1",
            "Factoring difference/sum of cubes 2",
            "Factoring difference/sum of cubes 3",
            "Factoring difference/sum of cubes 4",
            "Factoring difference/sum of cubes 5",
            "Factoring difference/sum of cubes 6",
            "Factoring by Grouping 1",
            "Factoring by Grouping 2",
            "Factoring by Grouping 3",
            "Factoring binomial GCF 1",
            "Factoring binomial GCF 2",
            "Factoring binomial GCF 3",
            "Factoring binomial GCF 4",
            "Simplifying Rational Expressions 1",
            "Simplifying Rational Expressions 2",
            "Simplifying Rational Expressions 3",
            "Simplifying Rational Expressions 4",
            "Simplifying Rational Expressions 5",
            "Simplifying Rational Expressions 6",
            "Simplifying Rational Expressions 7",
            "Adding/Subtracting Rational Expressions 1",
            "Adding/Subtracting Rational Expressions 2",
            "Adding/Subtracting Rational Expressions 3",
            "Adding/Subtracting Rational Expressions 4",
            "Adding/Subtracting Rational Expressions 5",
            "Adding/Subtracting Rational Expressions 6",
            "Compound Rational Expressions 1",
            "Compound Rational Expressions 2",
            "Compound Rational Expressions 3",
            "Compound Rational Expressions 4",
            "Compound Rational Expressions 5",
            "Compound Rational Expressions 6",
            "Compound Rational Expressions 7",
            "Compound Rational Expressions 8",
            "Rational Expressions and Negative Exponents 1",
            "Rational Expressions and Negative Exponents 2",
            "Rational Expressions and Negative Exponents 3",
            "Rational Expressions and GCF 1",
            "Rational Expressions and GCF 2",
            "Rational Expressions and GCF 3",
            "Simplifying Square Roots 1",
            "Simplifying Square Roots 2",
            "Evaluating Cube Roots",
            "Simplifying Cube Roots",
            "Simplifying Fourth Roots",
            "Simplifying Fractions with square roots 1",
            "Simplifying Fractions with square roots 2",
            "Multiplication of Roots 1",
            "Multiplication of Roots 2",
            "Multiplication of Roots 3",
            "Multiplication of Roots 4",
            "Rationalize the Denominator 1",
            "Rationalize the Denominator 2",
            "Rationalize the Denominator with Two Terms 1",
            "Rationalize the Denominator with Two Terms 2",
            "Linear Equations",
            "Linear Equations - variable on both sides",
            "Linear Equations - grouping symbols 1",
            "Linear Equations - grouping symbols 2",
            "Linear Equations with Fractions 1",
            "Linear Equations with Fractions 2",
            "Linear Equations with Fractions 3",
            "Linear Equations with Fractions 4",
            "Linear Equations with Fractions 5",
            "Equations with Variable in Denominator 1",
            "Equations with Variable in Denominator 2",
            "Equations with Variable in Denominator 3",
            "Equations with Variable in Denominator 4",
            "Equations with Variable in Denominator 5",
            "Equations with Variable in Denominator 6",
            "Quasi-Linear Equations 1",
            "Quasi-Linear Equations 2",
            "Linear Inequalities 1",
            "Linear Inequalities 2",
            "Linear Inequalities 3",
            "Simultaneous Linear Inequatlities 1",
            "Simultaneous Linear Inequatlities 2",
            "Function Evaluation - numeric 1",
            "Function Evaluation - numeric 2",
            "Function Evaluation - numeric 3",
            "Function Evaluation - symbolic linear",
            "Function Evaluation - symbolic quadratic 1",
            "Function Evaluation - symbolic quadratic 2",
            "Function Evaluation f(a + h) 1",
            "Function Evaluation f(a + h) 2",
            "Function Evaluation f(a + h) 3",
            "Function Evaluation - Difference Quotient 1",
            "Function Evaluation - Difference Quotient 2",
            "Function Evaluation - Difference Quotient 3",
            "Function Evaluation - In Model 1",
            "Function Evaluation - In Model 2",
            "Function Evaluation - In Model 3",
            "Composition of Functions - Numeric",
            "Domain of Functions 1",
            "Domain of Functions 2 variable in denominator",
            "Domain of Functions 3 variable in denominator ",
            "Domain of Functions 4 roots",
            "Domain of Functions 5 roots",
            "Domain of Functions 6 combination",
            "Domain of Functions 7 combination",
            "Equation of a Line 1 - point and slope",
            "Equation of a Line 2 - point and slope",
            "Equation of a Line 3 - (2 points)",
            "Equation of a Line 4 - <i>m</i> and b",
            "Equation of a Line 5 - intercepts",
            "Equation of a Line 6 - parallel",
            "Equation of a Line 7 - perpendicular",
            "Equation of a Line 8 - parallel (2 points)",
            "Equation of a Line 9 - perpendicular (2 points)",
            "Equation of a Line parallel to axis 1",
            "Equation of a Line parallel to axis 2",
            "Equation of a Line parallel to axis 3",
            "Equation of a Line parallel to axis 4",
            "Equation of a Line 10 - vertical and horizontal",
            "Equation of a Line 11 - vertical and horizontal",
            "Equation of a Line 12 - vertical and horizontal",
            "Equation of a Line 13 - vertical and horizontal",
            "Equation of a Line - Modeling 1 (2 points)",
            "Equation of a Line - Modeling 2 (2 points)",
            "Equation of a Line - Modeling 3 (2 points)",
            "Equation of a Line - Modeling 4 (2 points)",
            "Equation of a Line - Modeling 5",
            "Equation of a Line - Modeling 6",
            "Piecewise functions - find flat tax given function",
            "Piecewise functions - find graduated tax given function",
            "Piecewise functions - find tax not given function",
            "Piecewise functions - find larger tax",
            "Piecewise functions - write function",
            "Converting Units 1 - Metric to English ",
            "Converting Units 2 - Metric to English ",
            "Converting Units 3 - Metric to English ",
            "Converting Units 4 - English to Metric ",
            "Converting Units 5 - English to Metric ",
            "Converting Units 6 - English to Metric ",
            "Converting Units 7 - Light Years ",
            "Converting Units 8 - Light Years ",
            "Orders of Magnitude 1 ",
            "Orders of Magnitude 2 ",
            "Orders of Magnitude 3 ",
            "Orders of Magnitude 4 ",
            "Orders of Magnitude 5 ",
            "Common Log 1 - Write in Log Form ",
            "Common Log 2 - Write in Exp Form ",
            "Common Log 2 - Find log x easy ",
            "Common Log 3 - Find log x messy ",
            "Exponential Models 1 - Identify N(0) and growth rate ",
            "Exponential Models 2 - Growth Rate as a % ",
            "Exponential Models 3 - Growth vs. Decay ",
            "Write Exponential Model 1 ",
            "Write Exponential Model 2 ",
            "Write Exponential Model 3 ",
            "Exponential Modeling Problems 1",
            "Exponential Modeling Problems 2 ",
            "Exponential Modeling Problems 3 ",
            "Exponential Modeling Problems 4 ",
            "Linear vs. Exponential 1 - Identify Growth Type",
            "Linear vs. Exponential 2 - Compare Salary",
            "Write exponential function 1",
            "Write exponential function 2 ",
            "Compound Interest 1 - Write Model",
            "Compound Interest 2 - Write Model",
            "Compound Interest 3 - Find A(0)",
            "Compound Interest 4 - Find A(t)",
            "Compound Interest 5 - Find t",
            "Compound Interest 6 - Effective Interest Rate",
            "Expand the Logarithm 1 ",
            "Expand the Logarithm 2 ",
            "Expand the Logarithm 3 ",
            "Expand the Logarithm 4 ",
            "Expand the Logarithm 5 ",
            "Expand the Logarithm 6 ",
            "Expand the Logarithm 7 ",
            "Expand the Logarithm 8 ",
            "Expand the Logarithm 9 ",
            "Write as a Single Logarithm 1 ",
            "Write as a Single Logarithm 2 ",
            "Write as a Single Logarithm 3 ",
            "Write as a Single Logarithm 4 ",
            "Write as a Single Logarithm 5 ",
            "Write as a Single Logarithm 6 ",
            "Write as a Single Logarithm 7 ",
            "Exponential Equations 1 - x on one side ",
            "Exponential Equations 2 - x on one side ",
            "Exponential Equations 3 - x on one side ",
            "Exponential Equations 4 - base e ",
            "Exponential Equations 5 - base e ",
            "Exponential Equations 6 ",
            "Exponential Equations 7 ",
            "Exponential Equations 8 - x on both sides ",
            "Exponential Equations 9 - base e in function ",
            "Logarithmic Equations 1 ",
            "Logarithmic Equations 2 ",
            "Logarithmic Equations 3 ",
            "Logarithmic Equations 4 ",
            "Logarithmic Equations 5 - logs both sides ",
            "Logarithmic Equations 6 - logs both sides ",
            "Logarithmic Equations 7 - logs both sides",
            "Logarithmic Equations 8 - logs both sides",
            "Logarithmic Equations 9 - need properties",
            "Logarithmic Equations 10 - need properties ",
            "Logarithmic Equations 11 - need properties ",
            "Domain of Logarithms 1 ",
            "Domain of Logarithms 2 ",
            "Domain of Logarithms 3 ",
            "Change to Base e ",
            "Compund Interest - Doubling/Tripling",
            "Composition of Functions 1 ",
            "Composition of Functions 2 ",
            "Composition of Functions 3 ",
            "Composition of Functions 4 ",
            "Composition of Functions 5 ",
            "End behavior 1 - find power function ",
            "End behavior 2 - rise or fall ",
            "End behavior 3 - rise or fall ",
            "Behavior at x-intercepts - touch or cross ",
            "Direct vs. Inverse Proportion ",
            "Inverse Proportion ",
            "Direct Proportion ",
            "Quadratic Functions - Find the zeros by Factoring ",
            "Quadratic Functions - Find the zeros by Formula ",
            "Quadratic Functions - Completing the square 1 ",
            "Quadratic Functions - Completing the square 2 ",
            "Quadratic Functions - Find the vertex 1",
            "Quadratic Functions - Find the vertex 2",
            "Quadratic Functions - Max/Min 1 ",
            "Quadratic Functions - Max/Min Value 2 ",
            "Quadratic Functions - Standard Form ",
            "Quadratic Functions - Translations 1 ",
            "Quadratic Functions - Translations 2 ",
            "Quadratic Functions - Modeling 1 ",
            "Quadratic Functions - Modeling 2 ",
            "Quadratic Functions - Modeling 3 ",
            "Quadratic Functions - Modeling 4 ",
            "Non-Linear Inequalities 1 - factored form  ",
            "Non-Linear Inequalities 2 - factored form  ",
            "Non-Linear Inequalities 3  ",
            "Non-Linear Inequalities 4  ",
            "Non-Linear Inequalities 5 - get one side equal to 0  ",
            "Non-Linear Inequalities 6 - get one side equal to 0  ",
            "Non-Linear Inequalities 7 - get one side equal to 0  ",
            "Non-Linear Inequalities 8 - get one side equal to 0  ",
            "Non-Linear Inequalities 9 - cubic  ",
            "Non-Linear Inequalities 10 - cubic ",
            "Non-Linear Inequalities 11 - cubic ",
            "Non-Linear Inequalities 12 - cubic ",
            "Polynomials - End Behavior 1 ",
            "Polynomials - End Behavior 2 ",
            "Polynomials - Possible Rational Zeros ",
            "Polynomials - Synthetic Division 1 ",
            "Polynomials - Synthetic Division 2 ",
            "Polynomials - Synthetic Division 3 ",
            "Polynomials - Synthetic Division evaluate P(n) ",
            "Polynomials - Synthetic Division evaluate P(n) ",
            "Polynomials - Find all Real Zeros 1 ",
            "Polynomials - Find all Real Zeros 2 ",
            "Polynomials - Find all Real Zeros 3 ",
            "Polynomials - Construct function given zeros ",
            "Continuous Compounding -  find A(0) ",
            "Continuous Compounding - find A(t) ",
            "Continuous Compounding - find t ",
            "Projectile Problems - find time given height 1 ",
            "Projectile Problems - find time given height 2 ",
            "Projectile Problems - find time at ground level ",
            "Projectile Problems - max height ",
            "Projectile Problems  - time for max height",
            "Decibel Problems - find decibel",
            "Decibel Problems - compare intensities",
            "Factoring GCD - Negative Powers 1",
            "Factoring GCD - Fractional Powers",
            "Factoring GCD - Negative Powers 2",
            "Factoring Binomial GCD - Negative Powers 1",
            "Factoring Binomail GCD - Fractional Powers",
            "Factoring Binomail GCD - Negative Powers 2",
            "Factoring Binomail GCD - Differential 1",
            "Factoring Binomail GCD - Differential 2",
            "Factoring Binomail GCD - Differential 3",
            "Factoring - Psuedo Quadratic 1",
            "Factoring - Psuedo Quadratic 2",
            "Factoring - Psuedo Quadratic 3",
            "Factoring - Psuedo Quadratic 4",
            "Factoring - Psuedo Quadratic 5",
            "Factoring - Psuedo Quadratic 6",
            "Factoring - Psuedo Quadratic 7",
            "Factoring - Psuedo Quadratic 8",
            "Factoring - Psuedo Quadratic 9",
            "Factoring GCD - Negative and Positive Powers 1",
            "Factoring GCD - Negative and Positive Powers 2",
            "Factoring Binomial GCD - Negative and Positive Powers");


    if($q_type > 400 || $q_type < 1)
        return "Bounds exception in question_type_string\n";

    return $string_return[$q_type - 1];
}

//// trims parenthesis on the outside of polynomials and such
function trim_parenth($my_string)
{
    $num_parenth = 0;
    $temp_string = "";
    $length = strlen($my_string);

    $o_group = array('(','[');
    $c_group = array(')',']');

    for ($j = 0; $j < $length; $j++)
    {
        $char_array[] = substr($my_string,$j,1);
    }
    if (is_in($o_group,$char_array[0]) && is_in($c_group,$char_array[$length-1]))
    {
        for ($j = 1; $j < ($length - 1); $j++)
        {
            if (is_in($o_group,$char_array[$j]))
            {
                $num_parenth++;
            }
            else if (is_in($c_group,$char_array[$j]))
            {
                $num_parenth--;
            }
            ////echo "<br /> $num_parenth";
            if ($num_parenth < 0)
            {
                return $my_string;
            }
        }
        for ($j = 1; $j < ($length - 1); $j++)
        {
            $temp_string = $temp_string.$char_array[$j];
        }
        if (is_in($o_group,$char_array[1]))
        {
            $temp_string = trim_parenth($temp_string);
        }
        $my_string = $temp_string;
    }
    return $my_string;
}

function xy_pow_prep($x_pow,$y_pow)
{
    $numerator = "";
    $denominator = "";

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
    $result = array($numerator,$denominator);
    return $result;

}

///// same function with two coefficients

function xy_pow_prep_2($num_coeff,$denom_coeff,$x_pow,$y_pow)
{
    $numerator = (string)$num_coeff;
    $denominator = (string)$denom_coeff;
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
    $result = array($numerator,$denominator);
    return $result;

}

function abc_pow_prep($a_pow,$b_pow,$c_pow)
{

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
    $result = array($numerator,$denominator);
    return $result;
}

function xy_frac_pow_prep($num_coeff,$denom_coeff,$x_num,$x_denom,$y_num,$y_denom)
{
    if ($x_denom < 0)
    {
        $x_denom = $x_denom * (-1);
        $x_num = $x_num * (-1);
    }
    if ($y_denom < 0)
    {
        $y_denom = $y_denom * (-1);
        $y_num = $y_num * (-1);
    }
    if ($denom_coeff < 0)
    {
        $denom_coeff = $denom_coeff * (-1);
        $num_coeff = $num_coeff * (-1);
    }

    $isneg_x_num = 0;
    $isneg_y_num = 0;

    reduce($x_num,$x_denom);
    reduce($y_num,$y_denom);
    reduce($num_coeff,$denom_coeff);

    $numerator = (string)$num_coeff;
    $denominator = (string)$denom_coeff;

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
        $x_pow = $x_num;
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
        $y_pow = $y_num;
    }
    else
    {
        $y_pow = "(".$y_num."/".$y_denom.")";
    }

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
            $numerator = "x^".$x_pow;
        }
        else
        {
            $numerator = $numerator."*x^".$x_pow;
        }
    }
    else // ($x_pow < 0)
    {
        if ($denominator == "1")
        {
            $denominator = "x^".$x_pow;
        }
        else
        {
            $denominator = $denominator."*x^".$x_pow;
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
            $numerator = "y^".$y_pow;
        }
        else
        {
            $numerator = $numerator."*y^".$y_pow;
        }
    }
    else // ($y_pow < 0)
    {
        if ($denominator == "1")
        {
            $denominator = "y^".$y_pow;
        }
        else
        {
            $denominator = $denominator."*y^".$y_pow;
        }
    }
    $result = array($numerator,$denominator);
    return $result;
}

function is_in($my_array,$my_var)
{
    $result = FALSE;
    $size = count($my_array);
    if ($size == 0)
    {
        return $result;
    }
    for ($i = 0; $i < $size; $i++)
    {
        if ($my_var == $my_array[$i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////         Polynomial string creation            ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         October 18th 2005                     ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   $my_string = poly_prep($coeff_array,$var_array);
////
////   in:  $coeff_array - array of coefficients
////        $var_array   - array of variables (strings)
////
////   out:  $my_string - string that needs to be hit by
////         str_to_math before being ready to echo out
////
////   returns false if count($var_array == 0)
////       or count($var_array) + 1 != count($coeff_array)
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


function poly_prep($coeff_array,$var_array)
{
    $debug = FALSE;
    if ($debug)
    {
        echo "<br> <strong> <center> DEBUG INFO FOR POLY_PREP\n";
        echo "</center></strong><br>";
    }
    if (count($var_array) == 0)
    {
        echo "<br><center> ***WARNING*** poly_prep was passed a variable ";
        echo "array that was of count = 0 </center><br>";
        return FALSE;
    }
    if ( (count($var_array) + 1) != count($coeff_array) )
    {
        echo "<br><center> ***WARNING*** poly_prep was passed two arrays ";
        echo "whose size did not match.<br>";
        $coeff_size = count($coeff_array);
        $var_size = count($var_array);
        echo "coefficient array was of size $coeff_size<br>";
        echo "variable array was of size $var_size</center><br>";

        return FALSE;
    }
    $size = count($coeff_array);
    $start_poly = FALSE;
    for ($i = 0; $i < $size; $i++)
    {
        if($coeff_array[$i] != 0)
        {
            if ($i != 0 && $i < ($size - 1) )
            {
                if ($start_poly)
                {
                    if (strlen($var_array[$i]))
                    {
                        coeff_prep($coeff_array[$i]);
                    }
                    else
                    {
                        coeff_prep($coeff_array[$i],0);
                    }
                }
                else
                {
                    if (strlen($var_array[$i]))
                    {
                        if ($debug)
                        {
                            echo "<br> var array $i is ".$var_array[$i]."<br>";
                        }
                        if ($coeff_array[$i] == 1)
                        {
                            $coeff_array[$i] = " ";
                        }
                        else if ($coeff_array[$i] == -1)
                        {
                            $coeff_array[$i] = "-";
                        }
                    }
                }
                $start_poly = TRUE;
            }
            else if ($i == ($size - 1) )
            {
                if ($start_poly != FALSE)
                {
                    coeff_prep($coeff_array[$i],0);
                }
            }
            else
            {
                if (strlen($var_array[$i]))
                {
                    if ($coeff_array[$i] == -1)
                    {
                        $coeff_array[$i] = "-";
                    }
                    else if ($coeff_array[$i] == 1)
                    {
                        $coeff_array[$i] = " ";
                    }
                }
                $start_poly = TRUE;
            }
        }
        else
        {
            $coeff_array[$i] == NULL;
        }
        if ($debug == TRUE)
        {
            echo "<br> coefficient array $i is $coeff_array[$i] <br>";
        }
    }
    $my_string = "";
    $var_array[] = "";
    for ($i = 0; $i < $size; $i++)
    {
        if($coeff_array[$i] != NULL)
        {
            $my_string .= $coeff_array[$i].$var_array[$i];
            if ($i != ($size - 1))
            {
                $my_string .= " ";
            }
        }
    }
    if ($debug == TRUE)
    {
        echo "<br> my_string is $my_string <br>";
        echo "<strong><center> END DEBUG INFO FOR POLY PREP</center></strong>";
    }
    return $my_string;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////               String to Math 2                    ////
////                                                   ////
////                  Written by                       ////
////              Gregory P Richards                   ////
////                                                   ////
////                  Last Updated                     ////
////               February 8th 2006                   ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////
////    >> $my_string = str_to_math_2($str) ;
////
////    in : unformated string
////   out : string ready for echoing
////
////   should be able to handle the following syntax
////     * for multiplication
////     ^ for powers, and super script
////     / for division
////    () for grouping
////    [] for grouping
////  sqrt for square root
////  cbrt for cube root
////  ftrt for fourth root
////
////  *NOTE* after the ^ there must be () or []
////
//// *ALSO NOTE* This function should be expandable to other
////             special graphics..i.e integrals, differentials
////             and what not
////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function str_to_math_2($str,$opts=array())
{
    $parenth    = 0;
    $length     = 0;
    $c_array    = array();
    $terms      = array();
    $operators  = array();
    $p_loc      = array();
    $g_loc      = array();
    $pow_loc    = array();
    $o_loc      = array();
    $special    = array('+','-','^','/','(','[',')',']','*','=');
    $o_group    = array('(','[');
    $c_group    = array(')',']');
    $opers      = array('+','-','/','*','^');
    $g_ops      = array('+','-','=','<','>');
    $graphics1  = array('sqrt','cbrt','ftrt');
    $graphics2  = array('inf');
    $g_offset   = array(5,5,5);
    $s_temp     = "";
    $f_str      = "";
    $debug      = FALSE;
    $debug2     = FALSE;
    $debug3     = FALSE;
    $debug4     = FALSE;
    $found_op   = FALSE;
    $multiplier = 10;
    $numerator    = array();
    $denominator  = array();
    $n_size       = array();
    $d_size       = array();
    $g_size2      = count($graphics1);


    // set user defined and default options
    $opts = str_opts($opts);

    $pow       = $opts[1];
    $align     = $opts[3];
    $recursive = $opts[5];

    if ($debug4)
    {
        echo "<h3> OPTIONS </h3> ";
        echo "pow : ".$pow;
        echo "<br><br>";
        echo "align : ".$align;
        echo "<br><br>";
        echo "recursive : ".$recursive;
        echo "<h3> END OPTIONS </h3>";
    }


    // if debug echo out heading of debug section
    if ($debug)
    {
        echo "<h3>*** STARTED DEBUG OF STR_TO_MATH_2 ***</h3>\n";
        echo "Given String: ";
        echo $str;
        echo "<br>\n";
    }

    // trim string & remove multiplication signs and spaces
    $str = trim($str);
    $str = str_replace(' ','',$str);
    $str = str_replace('*','&middot;',$str);

    if ($debug)
    {
        echo "1st cleaning gives: ";
        echo $str;
        echo "<br>\n";
    }

    // get length of string
    $length = strlen($str);

    for ($i = 0; $i < $length; $i++)
    {
        $char = $str[$i];
        if (is_in($o_group,$char))
        {
            if ($i == 0)
            {
                continue;
            }
            else if (is_in($special,$str[$i-1]))
            {
                continue;
            }
            else
            {
                $str = substr_replace($str, '*'.$char,$i, 1);
                $length = strlen($str);
            }
        }
    }

    for ($i = 0; $i < $length; $i++)
    {
        $char = $str[$i];
        if (is_in($c_group,$char))
        {
            if (is_in($opers,$str[$i+1]) || $str[$i+1] == '^')
            {
                continue;
            }
            else
            {
                if (!is_in($c_group,$str[$i+1]))
                {
                    $str = substr_replace($str,$char.'*',$i, 1);
                    $length = strlen($str);
                }
            }
        }
    }

    $length = strlen($str);
    if ($str[$length-1] == '*')
    {
        $length--;
        $str = substr($str,0,$length);
    }

    for ($i = 0; $i < $g_size2; $i++)
    {
        $str = str_replace($graphics1[$i].'*','*'.$graphics1[$i],$str);
    }

    if ($debug)
    {
        echo "<br> 2nd cleaning gives: ";
        echo $str;
        echo "<br>\n";
    }


    // put string into character array
    for ($i = 0; $i < $length; $i++)
    {
        $c_array[$i] = substr($str,$i,1);
    }

    // parse through character array seperate by terms
    // by +,-,= operators
    for ($i = 0; $i < $length; $i++)
    {
        $char = $c_array[$i];
        if (is_in($o_group,$char))
        {
            $parenth++;
            $s_temp .= $char;
        }
        else if (is_in($c_group,$char))
        {
            $parenth--;
            $s_temp .= $char;
        }
        else if (is_in($g_ops,$char))
        {
            if ($parenth == 0 && strlen($s_temp) != 0)
            {
                $terms[]     = $s_temp;
                $s_temp      = "";
                $operators[] = $char;
            }
            else
            {
                $s_temp .= $char;
            }
        }
        else
        {
            $s_temp .= $char;
        }
    }
    if (strlen($s_temp))
    {
        $terms[] = $s_temp;
    }

    // set sizes
    $t_size = count($terms);
    $o_size = count($operators);

    if ($debug)
    {
        echo "T Size: ".$t_size."<br>\n";
        echo "O Size: ".$o_size."<br>\n";
        echo "<h3>TERMS</h3>\n";
        for ($j = 0; $j < $t_size; $j++)
        {
            echo $j+1;
            echo " : ";
            echo $terms[$j];
            echo "<br>\n";
        }

        echo "<h3>OPERATORS</h3>\n";
        for ($j = 0; $j < $o_size; $j++)
        {
            echo $j+1;
            echo " : ";
            echo $operators[$j];
            echo "<br>\n";
        }
        echo "<br>";
    }

    if ($debug)
    {
        echo "<h3> Term by Term Clean Up and Num/Denom Parse</h3>";
    }

    // break terms up by division and multiplication
    for ($i = 0; $i < $t_size; $i++)
    {
        $numerator[$i] = array();
        $denominator[$i] = array();
        $parenth = 0;

        $t_string = $terms[$i];

        $t_length = strlen($t_string);

        $sub_t_string = "";
        $t_op         = "";

        for ($j = 0; $j < $t_length; $j++)
        {
            $char = $t_string[$j];
            if (is_in($o_group,$char))
            {
                $parenth++;
                $sub_t_string .= $char;
            }
            else if (is_in($c_group,$char))
            {
                $parenth--;
                $sub_t_string .= $char;
            }
            else
            {
                if ($parenth == 0)
                {
                    if ($char == '*' || $char == '/')
                    {
                        if ($t_op == '*' || $t_op == "")
                        {
                            if (strlen($sub_t_string))
                            {
                                $numerator[$i][] = $sub_t_string;
                             }
                        }
                        else
                        {
                            if (strlen($sub_t_string))
                            {
                                $denominator[$i][] = $sub_t_string;
                            }
                        }
                        $t_op = $char;
                        $sub_t_string = "";
                    }
                    else
                    {
                        $sub_t_string .= $char;
                    }
                }
                else
                {
                    $sub_t_string .= $char;
                }
            }
        }
        if ($t_op == '*' || $t_op == "")
        {
            $numerator[$i][] = $sub_t_string;
        }
        else
        {
            $denominator[$i][] = $sub_t_string;
        }

        $n_size[$i] = count($numerator[$i]);
        $d_size[$i] = count($denominator[$i]);
        if ($debug2)
        {
            echo "num size $i is ".$n_size[$i]."<br>";
            echo "denom size $i is ".$d_size[$i]."<br><br>";
        }
    }

    // classify numerators and denominators
    for ($i = 0; $i < $t_size; $i++)
    {
        for ($j = 0; $j < $n_size[$i]; $j++)
        {
            $classified = FALSE;
            $location = $i.",num,".$j;
            $t_string = $numerator[$i][$j];
            $t_length = strlen($t_string);
            $parenth  = 0;

            for ($k = 0; $k < $t_length; $k++)
            {
                $char = $t_string[$k];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
                else
                {
                    if ($parenth == 0 && $char == '^')
                    {
                        $pow_loc[]  = $location;
                        $classified = TRUE;
                        break;
                    }
                }
            }

            if ($classified)
            {
                continue;
            }

            for ($k = 0; $k < $g_size2; $k++)
            {
                if (strpos(" ".$t_string,$graphics1[$k]))
                {
                    if (is_in($o_group,$t_string[0]))
                    {
                        $p_loc[] = $location;
                    }
                    else
                    {
                        $g_loc[]    = $location;
                    }
                    $classified = TRUE;
                    $break;
                }
            }

            if ($classified)
            {
                continue;
            }

            if (is_in($o_group,$t_string[0]))
            {
                for ($k = 0; $k < $t_length; $k++)
                {
                    $char = $t_string[$k];
                    if (is_in($opers,$char))
                    {
                        $p_loc[]    = $location;
                        $classified = TRUE;
                        break;
                    }
                }
            }

            if (!$classified)
            {
                $o_loc[] = $location;
            }
        }

        for ($j = 0; $j < $d_size[$i]; $j++)
        {
            $classified = FALSE;
            $location = $i.",denom,".$j;
            $t_string = $denominator[$i][$j];
            $t_length = strlen($t_string);
            $parenth  = 0;

            for ($k = 0; $k < $t_length; $k++)
            {
                $char = $t_string[$k];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
                else
                {
                    if ($parenth == 0 && $char == '^')
                    {
                        $pow_loc[]  = $location;
                        $classified = TRUE;
                        break;
                    }
                }
            }

            if ($classified)
            {
                continue;
            }

            for ($k = 0; $k < $g_size2; $k++)
            {
                if (strpos(" ".$t_string,$graphics1[$k]))
                {
                    if (is_in($o_group,$t_string[0]))
                    {
                        $p_loc[] = $location;
                    }
                    else
                    {
                        $g_loc[]    = $location;
                    }
                    $classified = TRUE;
                    $break;
                }
            }

            if ($classified)
            {
                continue;
            }


            if (is_in($o_group,$t_string[0]))
            {
                for ($k = 0; $k < $t_length; $k++)
                {
                    $char = $t_string[$k];
                    if (is_in($opers,$char))
                    {
                        $p_loc[]    = $location;
                        $classified = TRUE;
                        break;
                    }
                }
            }

            if (!$classified)
            {
                $o_loc[] = $location;
            }
        }
    }

    $pow_size = count($pow_loc);
    $g_size   = count($g_loc);
    $p_size   = count($p_loc);
    $ot_size  = count($o_loc);

    if ($debug)
    {
        for ($j = 0; $j < $t_size; $j++)
        {
            echo "<br><br> Term $j is ".$terms[$j];
            echo "<br><br>";
            echo "<b> NUMERATORS: </b><br>";
            for ($k = 0; $k < $n_size[$j]; $k++)
            {
                $num = $k + 1;
                echo "<br>".$num." : ";
                echo $numerator[$j][$k];
            }
            echo "<br><br>";
            echo "<b> DENOMINATORS: </b><br>";
            for ($k = 0; $k < $d_size[$j]; $k++)
            {
                $num = $k + 1;
                echo "<br>".$num." : ";
                echo $denominator[$j][$k];
            }
        }
        echo "<h3> Parenth Locations </h3>";
        for ($j = 0; $j < $p_size;$j++)
        {
            echo $j." : ".$p_loc[$j]."<br>";
        }
        echo "<br>";
        echo "<h3> Graphics Locations </h3>";
        for ($j = 0; $j < $g_size;$j++)
        {
            echo $j." : ".$g_loc[$j]."<br>";
        }
        echo "<h3> Power Locations </h3>";
        for ($j = 0; $j < $pow_size;$j++)
        {
            echo $j." : ".$pow_loc[$j]."<br>";
        }
        echo "<h3> Other Locations </h3>";
        for ($j = 0; $j < $ot_size;$j++)
        {
            echo $j." : ".$o_loc[$j]."<br>";
        }
        echo "<br>";
    }

    // recursively parse the terms in pow_loc
    for ($i = 0; $i < $pow_size; $i++)
    {
        $local = explode(',',$pow_loc[$i]);
        $m = $local[0];
        $n = $local[2];
        if ($local[1] == "num")
        {
            $t_string = $numerator[$m][$n];
        }
        else
        {
            $t_string = $denominator[$m][$n];
        }

        $size      = strlen($t_string);

        if (!is_in($o_group,$t_string[0]))
        {
            $pos = strpos($t_string,'^');
        }
        else
        {
            $parenth  = 0;
            $t_length = strlen($t_string);

            for ($j = 0; $j < $t_length; $j++)
            {
                $char = $t_string[$j];
                if (is_in($o_group,$char))
                {
                    $parenth++;
                }
                else if (is_in($c_group,$char))
                {
                    $parenth--;
                }
                if ($parenth == 0)
                {
                    break;
                }
            }

            $pos = $j + 1;
        }

        $variable = substr($t_string,0,$pos);
        $power    = substr($t_string,$pos+1);

        if ($debug)
        {
            echo "<br> $t_string <br> ";
            echo "Power :".$power;
            echo "Variable :".$variable;
        }


        $new_opts = array('recursive',1);
        $variable = str_to_math_2($variable,$new_opts);

        $p_length = strlen($power);

        $power = substr($power,1,$p_length-2);

        $new_opts = array('pow',1,'recursive',1);

        $power = str_to_math_2($power,$new_opts);

        $my_str2 = str_replace('math2',
                               'math3',
                               $power);
        $my_str  = "<table style=pow1 border=0 cellspacing=0 cellpadding=0>";
        $my_str .= "<tr><td valign=bottom align=right>";
        $my_str .= $variable;
        $my_str .= "</td><td valign=top>";
        $my_str .= $my_str2;
        $my_str .= "</td></tr></table>";

        if ($local[1] == "num")
        {
            $numerator[$m][$n] = $my_str;
        }
        else
        {
            $denominator[$m][$n] = $my_str;
        }
    }

    // recursively parse the terms in p_loc

    for ($i = 0; $i < $p_size; $i++)
    {
        $local = explode(',',$p_loc[$i]);
        $m = $local[0];
        $n = $local[2];
        if ($local[1] == "num")
        {
            $t_string = $numerator[$m][$n];
        }
        else
        {
            $t_string = $denominator[$m][$n];
        }

        $size      = strlen($t_string);

        $opener = $t_string[0];
        $closer = $t_string[$size-1];

        if ($debug3)
        {
            echo "<h3> Parenth Group Parse </h3>";
            echo "t string is ".$t_string."<br>";
            echo "Opener is ".$opener."<br>";
            echo "Closer is ".$closer."<br>";
        }


        $t_string = substr($t_string,1,$size-2);

        $new_opts = array('recursive',1);

        $t_string = str_to_math_2($t_string,$new_opts);

        if (strpos($t_string,'img'))
        {
            if (strpos($t_string,"height='2'"))
            {
                $class = 'parenth1';
                $p_align = 'center';
            }
            else
            {
                $class = 'parenth2';
                $p_align = 'bottom';
            }
        }
        else
        {
            $class = 'parenth2';
            $p_align = 'bottom';
        }

        $my_str  = "<table style=";
        $my_str .= $class;
        $my_str .= " border=0 cellspacing=0 cellpadding=0>";
        $my_str .= "<tr valign='".$p_align."'><td align=center>";
        $my_str .= $opener." ";
        $my_str .= "</td><td align=center >";
        $my_str .= $t_string;
        $my_str .= "</td><td align=right> ";
        $my_str .= $closer;
        $my_str .= "</td></tr></table>";

        if ($local[1] == "num")
        {
            $numerator[$m][$n] = $my_str;
        }
        else
        {
            $denominator[$m][$n] = $my_str;
        }
    }

    // recursively parse the terms in g_loc

    for ($i = 0; $i < $g_size; $i++)
    {
        $local = explode(',',$g_loc[$i]);
        $m = $local[0];
        $n = $local[2];
        if ($local[1] == "num")
        {
            $t_string = $numerator[$m][$n];
        }
        else
        {
            $t_string = $denominator[$m][$n];
        }

        $pos = strpos($t_string,'(');
        if ($pos == 0)
        {
            $pos = strpos($t_string,'[');
        }

        // find what type of graphic is required
        $graphic = substr($t_string,0,$pos);
        $type    = find_in($graphics1,$graphic);

        // recursevly parse string that graphic acts on
        $t_string = substr($t_string,$pos);
        $t_length = strlen($t_string);
        $t_string = substr($t_string,1,$t_length-2);

        $new_opts = array('recursive',1);
        $t_string = str_to_math_2($t_string,$new_opts);

        if (strpos($t_string,'img') && strpos($t_string,"height='2'") )
        {
            if (strpos($t_string,'math3'))
            {
                $class = 'rt_style1';
                $ht = 4;
            }
            else
            {
                $class = 'rt_style2';
                $ht = 3;
            }
        }
        else if (strpos($t_string,'math3') )
        {
            $class = 'rt_style3';
            $ht    = 1;
        }
        else
        {
            $class = 'rt_style4';
            $ht    = 1;
        }

        if ($type == 0)
        {
            // create string for sqrt symbol
            $rt_string  = "<table style=";
            $rt_string .= $class;
            $rt_string .= " border=0 cellpadding=0 cellspacing=0>";
            $rt_string .= "<tr><td>";
            $rt_string .= "<span style={vertical-align:-15%}>&#214;</span>";
            $rt_string .= "</tr></td></table>";

            // construct table with t_string and an overline
            $data_str  = "<table style=math2 ";
            $data_str .= " border=0 cellpadding=0 cellspacing=0>";
            $data_str .= "<tr><td>";
            $data_str .= "<span class='midline'>";
            $data_str .= "<img src='Images/1px.gif' width='10' height='$ht'>";
            $data_str .= "</span>";
            $data_str .= "</td></tr>";
            $data_str .= "<tr><td>";
            $data_str .= $t_string;
            $data_str .= "</tr></tr></table>";

            $my_str  = "<table style=math2 ";
            $my_str .= " border=0 cellspacing=0 cellpadding=0>";
            $my_str .= "<tr><td>";
            $my_str .= $rt_string;
            $my_str .= "</td><td>";
            $my_str .= $data_str;
            $my_str .= "</td></tr></table>";
        }
        else if ($type == 1)
        {
            // create string for cbrt symbol
            $rt_string  = "<table style=";
            $rt_string .= $class;
            $rt_string .= " border=0 cellpadding=0 cellspacing=0>";
            $rt_string .= "<tr><td>";
            $rt_string .= "<span class='rootnum'>";
            $rt_string .= "<sup>3</sup></span><span style={vertical-align:-15%}>&#214;</span>";
            $rt_string .= "</tr></td></table>";

            // construct table with t_string and an overline
            $data_str  = "<table style=math2 ";
            $data_str .= " border=0 cellpadding=0 cellspacing=0>";
            $data_str .= "<tr><td>";
            $data_str .= "<span class='midline'>";
            $data_str .= "<img src='Images/1px.gif' width='10' height='$ht'>";
            $data_str .= "</span>";
            $data_str .= "</td></tr>";
            $data_str .= "<tr><td>";
            $data_str .= $t_string;
            $data_str .= "</tr></tr></table>";

            $my_str  = "<table style=math2 ";
            $my_str .= " border=0 cellspacing=0 cellpadding=0>";
            $my_str .= "<tr><td>";
            $my_str .= $rt_string;
            $my_str .= "</td><td>";
            $my_str .= $data_str;
            $my_str .= "</td></tr></table>";
        }
        else if ($type == 2)
        {
            // create string for ftrt symbol
            $rt_string  = "<table style=";
            $rt_string .= $class;
            $rt_string .= " border=0 cellpadding=0 cellspacing=0>";
            $rt_string .= "<tr><td>";
            $rt_string .= "<span class='rootnum'>";
            $rt_string .= "<sup>4</sup></span><span style={vertical-align:-15%}>&#214;</span>";
            $rt_string .= "</tr></td></table>";

            // construct table with t_string and an overline
            $data_str  = "<table style=math2 ";
            $data_str .= " border=0 cellpadding=0 cellspacing=0>";
            $data_str .= "<tr><td>";
            $data_str .= "<span class='midline'>";
            $data_str .= "<img src='Images/1px.gif' width='10' height='$ht'>";
            $data_str .= "</span>";
            $data_str .= "</td></tr>";
            $data_str .= "<tr><td>";
            $data_str .= $t_string;
            $data_str .= "</tr></tr></table>";

            $my_str  = "<table style=math2 ";
            $my_str .= " border=0 cellspacing=0 cellpadding=0>";
            $my_str .= "<tr><td>";
            $my_str .= $rt_string;
            $my_str .= "</td><td>";
            $my_str .= $data_str;
            $my_str .= "</td></tr></table>";
        }

        if ($local[1] == "num")
        {
            $numerator[$m][$n] = $my_str;
        }
        else
        {
            $denominator[$m][$n] = $my_str;
        }
    }

    // create tables for those in others
    for ($i = 0; $i < $ot_size; $i++)
    {
        $local = explode(',',$o_loc[$i]);
        $m = $local[0];
        $n = $local[2];
        if ($local[1] == "num")
        {
            $t_string = $numerator[$m][$n];
        }
        else
        {
            $t_string = $denominator[$m][$n];
        }


        $my_str  = "<table style=math2 ";
        $my_str .= " border=0 cellspacing=0 cellpadding=0>";
        $my_str .= "<tr valign=center><td align=center>";
        $my_str .= $t_string;
        $my_str .= "</td></tr></table>";

        if ($local[1] == "num")
        {
            $numerator[$m][$n] = $my_str;
        }
        else
        {
            $denominator[$m][$n] = $my_str;
        }
    }

    // combine numerators into single numerator per term
    for ($i = 0; $i < $t_size; $i++)
    {
        $size = count($numerator[$i]);
        if ($size != 1)
        {
            $my_str  = "<table style=math2 ";
            $my_str .= "border=0 cellspacing=0 cellpadding=0 >";
            $my_str .= "<tr valign=bottom><td>";

            for ($j = 0; $j < $size; $j++)
            {
                $my_str .= $numerator[$i][$j];
                $my_str .= "</td><td>";
            }

            $my_str .= "</td></tr></table>";

            $numerator[$i] = $my_str;
        }
        else
        {
            $numerator[$i] = $numerator[$i][0];
        }
    }
    // combine denominators into single denomnator per term
    for ($i = 0; $i < $t_size; $i++)
    {
        $size = count($denominator[$i]);
        if ($size == 0)
        {
            $denominator[$i] = 1;
        }
        else
        {
            $my_str  = "<table style=math2  ";
            $my_str .= "border=0 cellspacing=0 cellpadding=0 >";
            $my_str .= "<tr><td>";

            for ($j = 0; $j < $size; $j++)
            {
                $my_str .= $denominator[$i][$j];
                $my_str .= "</td><td>";
            }

            $my_str .= "</td></tr></table>";

            $denominator[$i] = $my_str;
        }
    }


    // combine numerators and denominators to make final
    // form of the terms if pow is set to true use /
    // else use a table
    for ($i = 0; $i < $t_size;$i++)
    {
        if ($denominator[$i] == 1)
        {
            $terms[$i] = $numerator[$i];
            continue;
        }
        $t_string1 = $numerator[$i];
        $t_string2 = $denominator[$i];

        $size1 = strlen($t_string1);
        $size2 = strlen($t_string2);

        $true_size1 = 0;
        $true_size2 = 0;

        $html_command = FALSE;

        for ($j = 0; $j< $size1; $j++)
        {
            $temp_char = substr($t_string1,$j,1);

            if ($temp_char == '<')
            {
                $html_command = TRUE;
            }
            if ($temp_char == '&')
            {
                $true_size1        = $true_size1 + 1;
                $html_command      = TRUE;
                $html_special_char = TRUE;
            }
            if (!$html_command)
            {
                $true_size1++;

                if ($temp_char == ' ')
                {
                    $true_size1--;
                }
                if ($temp_char == NULL)
                {
                    $true_size1--;
                }
            }
            if ($temp_char == '>' )
            {
                $html_command = FALSE;
            }
            if ($temp_char == ';' && $html_special_char)
            {
                $html_command      = FALSE;
                $html_special_char = FALSE;
            }
        }

        for ($j = 0; $j < $size2; $j++)
        {
            $temp_char = substr($t_string2,$j,1);

            if ($temp_char == '<')
            {
                $html_command = TRUE;
            }
            if ($temp_char == '&')
            {
                $true_size2        = $true_size2 + 1;
                $html_command      = TRUE;
                $html_special_char = TRUE;
            }
            if (!$html_command)
            {
                $true_size2++;

                if ($temp_char == ' ')
                {
                    $true_size2--;
                }
                if ($temp_char == NULL)
                {
                    $true_size2--;
                }
            }
            if ($temp_char == '>' )
            {
                $html_command = FALSE;
            }
            if ($temp_char == ';' && $html_special_char)
            {
                $html_special_char = FALSE;
                $html_command      = FALSE;
            }
        }
        if ($true_size1 < 2)
        {
            $true_size1 = 2;
        }

        if ($true_size1 > $true_size2)
        {
            $temp = $multiplier * $true_size1;
        }
        else
        {
            $temp = $multiplier * $true_size2;
        }
        if ($pow)
        {
            $my_str  = "<table style=pow2 border=0 cellspacing=0 cellpadding=0>";
            $my_str .= "<tr><td valign=top >";
            $my_str .= $t_string1;
            $my_str .= "</td><td style='{width:0.2em ; text-align:right}' >/</td>";
            $my_str .= "<td valign=bottom >";
            $my_str .= $t_string2;
            $my_str .= "</td></tr></table>";
        }
        else
        {
            $my_str  = "<table style=math2 border=0 cellspacing=0 cellpadding=0>";
            $my_str .= "<tr valign=bottom><td align=center>";
            $my_str .= $t_string1;
            $my_str .= "</td></tr><tr><td>";
            $my_str .= "<span class='midline'>";
            $my_str .= "<img src='Images/1px.gif' width='$temp' height='2'>";
            $my_str .= "</span></td></tr><tr><td align=center>";
            $my_str .= $t_string2;
            $my_str .= "</td></tr></table>";
        }
        $terms[$i] = $my_str;
    }

    // go through operators and make them into tables
    for ($i = 0; $i < $o_size; $i++)
    {
        if ($operators[$i] == '-')
        {
            $my_str2 = "<span style='height:0.75ex;'>";
            $my_str2 .= "<img src='Images/1px.gif' width=7 height=1>";
            $my_str2 .= "</span>";
            $operators[$i] = $my_str2;
        }

        $my_str  = "<table style=math2 border=0 cellspacing=0 cellpadding=0>";
        $my_str .= "<tr valign=center><td>&nbsp;";
        if (!$recursive)
        {
            $my_str .= "&nbsp;";
        }
        $my_str .= $operators[$i];
        $my_str .= "&nbsp;";
        if (!$recursive)
        {
            $my_str .= "&nbsp;";
        }
        $my_str .= "</td></tr></table>";
        $operators[$i] = $my_str;
    }


    // combine terms to make final string ready for echoing
    // deal with addition and subtraction

    $f_str  = "";
    $f_str .= "<table border=0 cellspacing=0 cellpadding=0>";
    $f_str .= "<tr valign='";
    $f_str .= $align;
    $f_str .= "'>";

    for ($i = 0; $i < $o_size; $i++)
    {
        $f_str .= "<td align=center>";
        $f_str .= $terms[$i];
        $f_str .= "</td><td align=center >";
        $f_str .= $operators[$i];
        $f_str .= "</td>";
    }

    $f_str .= "<td align=center>";
    $f_str .= $terms[$o_size];
    $f_str .= "</td></tr>";

    $f_str .= "</table>";

    if (!$recursive)
    {
        // apply inline style
        $math2 = "'{  color:black; "
                  . " font-family:arial,sans-serif; "
                  . " font-size:12pt; }'";
        $math3 = "'{  color:black; "
                ."    font-family:arial,sans-serif; "
                ."    font-size:8pt; "
                ."    margin-left:1pt; }'";
        $parenth1 = "'{ color:black;"
                   ."  font-family:Verdana;"
                   ."  font-size:24pt; "
                   ."  font-stretch:narrower ;"
                   ."  vertical-align:top ; }'";
        $parenth2 = "'{  color:black; "
                   ."  font-family:sans-serif ; "
                   ."  font-size:12pt; "
                   ."  height:0.95ex; "
                   ."  margin-right:3pt; "
                   ."  margin-left:3pt; "
                   ."  letter-spacing:3pt;}'";
        $pow1     = "'{ color:black ; "
                   ."  height:3.1ex;}'";
        $pow2     = "'{ height:2.5ex;}'";

        $rt_style1 = "'{ color:black;"
                    ."   font-size:42pt;"
                    ."   font-family:Symbol;"
                    ."   width:0.3em;}'";
        $rt_style2 = "'{ color:black;"
                    ."   font-size:35pt;"
                    ."   font-family:Symbol;"
                    ."   width:0.3em;}'";
        $rt_style3 = "'{ color:black;"
                    ."   font-size:20pt;"
                    ."   font-family:Symbol;"
                    ."   width:0.3em;}'";
        $rt_style4 = "'{ color:black;"
                    ."   font-size:12pt;"
                    ."   font-family:Symbol;"
                    ."   width:0.3em;}'";

        $f_str = str_replace('math2',$math2,$f_str);
        $f_str = str_replace('math3',$math3,$f_str);
        $f_str = str_replace('parenth1',$parenth1,$f_str);
        $f_str = str_replace('parenth2',$parenth2,$f_str);
        $f_str = str_replace('pow1',$pow1,$f_str);
        $f_str = str_replace('pow2',$pow2,$f_str);

        $f_str = str_replace('rt_style1',$rt_style1,$f_str);
        $f_str = str_replace('rt_style2',$rt_style2,$f_str);
        $f_str = str_replace('rt_style3',$rt_style3,$f_str);
        $f_str = str_replace('rt_style4',$rt_style4,$f_str);


        $f_str = str_replace('&middot;',
                            "<span style='width:0.5em; font-weight:800;'>"
                           ."&middot;</span>",$f_str);

        $f_str .= "<br><br>";
    $s_error = FALSE;   // start of inserted code wxyz
    for($i=0;$i<$length-1;$i++)
    {
      if($str[$i]=='^' && $str[$i+1]!='(')
      {
        $s_error = TRUE;
      }
    }
    if($s_error)
    {
      $f_str .="<center>*** WARNING SYNTAX ERROR ***<br>";

      $f_str .="Power Symbol was not followed by a parenthesis </center>";
    }   // end of inserted code
    }

    if ($debug)
    {
        echo "Final String: ";
        echo $f_str;
        echo "<br>\n";
        echo "<h3> *** END DEBUG FOR STR_TO_MATH_2 *** </h3>\n";
    }

    return $f_str;
}

function get_max($my_array)
{
    $size = count($my_array);
    if ($size == 0)
    {
        return 0;
    }
    else if ($size == 1)
    {
        if ($my_array[0] < 0)
        {
            $my_array[0] = $my_array[0] * (-1);
        }
        return $my_array[0];
    }
    else
    {
        if ($my_array[0] < 0)
        {
            $my_array[0] = $my_array[0] * (-1);
        }
        $my_max = $my_array[0];
        for ($i = 0; $i < $size; $i++)
        {
            if ($my_array[$i] < 0)
            {
                $my_array[$i] = $my_array[$i] * (-1);
            }
            if ($my_array[$i] > $my_max)
            {
                $my_max = $my_array[$i];
            }
        }
    }
    return $my_max;
}


//// finds the index of the first occurance of
//// my_value in my_array
//// if my_array does not contain my_value
//// returns -1
function find_in($my_array,$my_value)
{
    $index = -1;
    $size = count($my_array);
    for ($i = 0; $i < $size; $i++)
    {
        if ($my_array[$i] == $my_value)
        {
            $index = $i;
            return $index;
        }
    }
    return $index;
}

//// set options for str_to_math2
//// extendable
function str_opts($o_array)
{
    $opt_array = array('pow',0,
                     'align','bottom',
                 'recursive',0);

    $options = array('pow',
                   'align',
                'recursive');

    $size = count($options);

    for ($i = 0; $i < $size; $i++)
    {
        $my_opt = $options[$i];
        $pos = find_in($o_array,$my_opt) ;

        if ($pos > -1)
        {
            $true_pos = $pos + 1;
            $opt_array[2 * $i + 1] = $o_array[$true_pos] ;
        }
    }
    return $opt_array;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////        create results array                   ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////         January 7th 2006                      ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   $r_array = create_results_array($q_array,$a_array);
////
////   in:  $q_array - array of question information
////        $a_array - array of answer information
////
////   out:  $r_array - array of results in the following
////         form
////         -1 => user was incorrect
////          0 => user did not answer
////          1 => user was correct
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function create_result_array($q_array,$a_array)
{
    //// initilize variables and size of loop
    $r_array   = array();
    $num_total = count($q_array)-1;
    $i_break   = "INFORMATION_BREAK";
    $debug     = FALSE;

    for ($i = 0; $i < $num_total; $i++)
    {
        //// create information arrays
        $qi_array = explode($i_break,$q_array[$i]);
        $ai_array = explode($i_break,$a_array[$i]);

        //// parse ai_array into correct form of num denom
        $correct_form = gen_correct_answer_form($qi_array[6],$ai_array);

        $num   = $correct_form[0];
        $denom = $correct_form[1];

        ///// parse qi_array into q_type and question
        $q_type   = $qi_array[0];
        $question = array();
        for ($j = 1; $j < 7; $j++)
        {
            $question[$j-1] = $qi_array[$j];
        }

        //// check to see if user answers question
        $no_answer = FALSE;

        $num   = trim($num);
        $denom = trim($denom);

        if (!(strlen($num) || strlen($denom)))
        {
            $no_answer = TRUE;
        }
        else if (strlen($denom) == 0)
        {
            $denom = 1;
        }
        else if (strlen($num) == 0)
        {
            $num = 1;
        }

        //// check answer
        //echo('<br />num=' . $num);
        //echo('<br />denom=' . $denom);
        //echo('<br />question=' . $question);
        //echo('<br />q_type=' . $q_type);
        $answer = check_answer($num,$denom,$question,$q_type);

        //// update r_array
        if ($no_answer)
        {
            $r_array[$i] = 0;
        }
        else if($answer)
        {
            $r_array[$i] = 1;
        }
        else
        {
            $r_array[$i] = -1;
        }
        if ($debug)
        {
            echo "<br> RESULT ARRAY $i is ".$r_array[$i];
        }
    }

    return $r_array;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////           create test html                    ////
////                                               ////
////           Gregory Richards                    ////
////                                               ////
////             Last updated                      ////
////           January 7th 2006                    ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////
////   $test_html = create_results_array($q_array,$a_array);
////
////   in:  $q_array - array of question information
////        $a_array - array of answer information
////        $r_array - array of result information
////
////   out:  $test_html - string ready to echo out test
////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

function create_test_html($q_array,$a_array,$r_array)
{
    //// initilize variables
    $test_html = "";
    $i_break   = "INFORMATION_BREAK";
    $hr        = "75%";
    $debug     = FALSE;
    $c_result  = 0;

    $qi_array = array();
    $ai_array = array();

    $num_total = count($q_array) - 1;

    for ($i = 0; $i < $num_total; $i++)
    {
        //// set question number
        $number = $i + 1;

        //// parse question,answer and result information
        $qi_array = explode($i_break,$q_array[$i]);
        $ai_array = explode($i_break,$a_array[$i]);

        $q_type   = $qi_array[0];
        $question = array();
        for ($j = 1; $j < 7; $j++)
        {
            $question[$j-1] = $qi_array[$j];
        }

        $correct_form = gen_correct_answer_form($qi_array[6],$ai_array);

        $num   = $correct_form[0];
        $denom = $correct_form[1];

        $c_result = $r_array[$i];

        //// get question ready for string
        $q_out = parse_question($question[0],$q_type);

        //// get answer ready for string
        $num   = str_to_math($num);
        $denom = str_to_math($denom);

        //// set directions
        $directions = gen_directions($q_type);

        //// question title
        $test_html .= "<h3>Question #$number</h3>\n";

        //// result image
        if ($c_result == 1)
        {
            $test_html .= "<img src='Images/check.png' alt='Correct!'>\n";
        }
        else
        {
            $test_html .= "<img src='Images/x.png' alt='Incorrect'>\n";
        }

        $test_html .= "<br>\n";

        //// directions
        $test_html .= "<p><center>$directions</center></p>";

        //// question
        $test_html .= gen_q_out($q_type,$q_out);

        $test_html .= "<br>\n";

        //// users answer
        $test_html .= "You answered: ";
        if ($c_result == 0)
        {
            $test_html .= "<br><center>You did not answer the question.</center>";
        }
        else
        {
            $out_array = array(1
                              ,$num
                              ,$denom
                              ,$question[3]
                              ,$question[4]
                              ,$question[5] );
            $test_html .= gen_parser_out($out_array,$q_type);
        }

        //// correct answer
        $test_html .=  "<br>The correct answer was... <br>";

        $out_array = array(1
                          ,$question[1]
                          ,$question[2]
                          ,$question[3]
                          ,$question[4]
                          ,$question[5]);
        $test_html .= gen_parser_out($out_array,$q_type);

        //// question break
        $test_html .= "<br><hr width='$hr'><br>\n";
    }

    //// make test_html ready for return and return
    return $test_html;
}


?>
