<?php

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////             u_answer_save function                ////
////                                                   ////
////              Originally Created by                ////
////               Gregory P Richards                  ////
////                                                   ////
////                                                   ////
////                 Last Updated                      ////
////                                                   ////
////                    On                             ////
////                January 5th 2006                   ////
////                                                   ////
////                    By                             ////
////               Gregory P Richards                  ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

function u_answer_save($question_type,$num)
{
    $a_string = "";
    $i_string = "";
    $i_break  = "INFORMATION_BREAK";
    $debug    = FALSE;

    if ($question_type < 135) //// answer input
    {
        $r_string = "infix".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 140) //// interval answer input
    {
        $r_string = "infix".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;
        for($i=1;$i<=5;$i++)
        {
          $r_string = "infix".$i.$num;
          $i_string = $_REQUEST[$r_string];
          $a_string .= $i_string.$i_break;
        }
    }
    else if ($question_type < 156) //// answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 163) //// domain answer input
    {
        $r_string = "answer_single_interval_left_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 180) //// linear equation answer input
    {
        $r_string = "answer_slope_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_slope_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_yint_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_yint_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_y_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_y_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 186) //// linear equation reform answer input
    {
        $r_string = "answer_slope_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_slope_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_yint_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_yint_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_y_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_y_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 189) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 190) //// compare tax answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 191) //// tax equation answer input
    {
        $r_string = "answer_low_tax_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_bound1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_const1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_high_tax_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_const2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_bound2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 197) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 199) //// sci answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 204) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 205) //// common log form answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 206) //// easy exp form answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 208) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 209) //// initial pop growth rate answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 210) //// simple answer percentage input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 211) //// growth vs decay answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 214) //// exponential equation answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 217) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 218) //// compare salary answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 219) //// growth type answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 220) ///// compare salary answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 222) //// exponential equation answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 224) //// exponentiatl equation 2 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 226) //// simple answer money input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 227) //// simple answer t input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 228) /// simple answer percentage input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 237) //// expanded logarithm answer input
    {
        $r_string = "answer_coeff1_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff1_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside1_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside1_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff2_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff2_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside2_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside2_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff3_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff3_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base3_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside3_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside3_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff4_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff4_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base4_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside4_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside4_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff5_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff5_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base5_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside5_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside5_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff6_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_coeff6_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base6_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside6_num_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_inside6_denom_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 244) //// single logarithm answer input
    {
        $r_string = "answer_num1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_num2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_num3_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_base_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denom1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denom2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denom3_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 253) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 256) //// simple answer x input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 264) //// quadratic equation answer input
    {
        $r_string = "answer_x1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_no_solution_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 267) //// domain answer input
    {
        $r_string = "answer_single_interval_left_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 268) //// exponential equation 3 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 269) //// simple answer t input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 274) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 275) //// end behavior 1 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 277) //// end behavior 2 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 278) //// zero behavior answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 279) //// proportion 1 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 281) //// proportion 2 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 282) //// quadratic equation answer input
    {
        $r_string = "answer_x1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_no_solution_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 283) //// quadratic equation 2 answer input
    {
        $r_string = "answer_x1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_no_solution_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 285) //// answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 287) //// equation answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 289) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 290) //// standard form answer input
    {
        $r_string = "answer_left_operator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_right_operator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 292) //// translation answer input
    {
        $r_string = "answer_moved_left_or_right_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_left_or_right_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_moved_up_or_down_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_up_or_down_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_reflected_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 294) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 296) //// length width answer input
    {
        $r_string = "answer_x1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 308) //// interval answer input
    {
        $r_string = "answer_single_interval_left_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_left_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_single_interval_right_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right1_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_left2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_double_interval_right2_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 309) //// end behavior 3 answer input
    {
        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 310) //// end behavior 4 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 314) //// multiple choice answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 316) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 317) //// multiple choice answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 319) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 320) //// multiple choice answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 322) //// simple answer money input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 323) //// simple answer t input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 327) //// projectile 2 answer input
    {
        $r_string = "answer_x1_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x1_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_x2_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_no_solution_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 328) //// projectile 1 answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 330) //// simple answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else if ($question_type < 351) //// answer input
    {
        $r_string = "answer_numerator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string.$i_break;

        $r_string = "answer_denominator_".$num;
        $i_string = $_REQUEST[$r_string];
        $a_string .= $i_string;
    }
    else
    {
        echo "u_aswer_save() was passed non-question-type<br>\n";
        echo "type was $question_type on number $question_number.<br>\n";
        return FALSE;
    }
    return $a_string;
}

/*
//// need to test


20)function simple_answer_t_input($number)

15)function exponential_equation_3_answer_input($number)

14)function end_behavior_1_answer_input($number)

13)function end_behavior_2_answer_input($number)

12)function end_behavior_3_answer_input($number)

11)function end_behavior_4_answer_input($number)

10)function proportion_1_answer_input($number)

9)function proportion_2_answer_input($number)

8)function zero_behavior_answer_input($number)

7)function quadratic_equation_2_answer_input($number)

6)function standard_form_answer_input($number)

5)function translation_answer_input($number)

4)function length_width_answer_input($number)

3)function multiple_choice_answer_input($number)

2)function projectile_2_answer_input($number)

1)function projectile_1_answer_input($number)

*/
?>

