<?php

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////                                                   ////
////             Check Answer Function                 ////
////                                                   ////
////               Originally by                       ////
////             Gregory P Richards                    ////
////                                                   ////
////              Last updated                         ////
////                                                   ////
////                   On                              ////
////              July 30, 2005                        ////
////                                                   ////
////                   By                              ////
////             Gregory P Richards                    ////
////                                                   ////
////                 Need To                           ////
////           Make Lines 80 Characters or less        ////
////                                                   ////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


function check_answer($a_numerator,$a_denominator,$q_array,$q_type)
{
    $debug = FALSE;
    if ($debug == TRUE)
    {
        echo "<br /> called check_answer function with q_type = ";
        echo "<br /> $q_type";
        echo "<br /> and with q_array = ";
        for ($i = 1; $i < 6; $i++)
        {
            echo "<br /> $q_array[$i] <br />";
        }
    }
    $correct = FALSE;
    if ($q_array != NULL)
    {
        $numerator = $q_array[1];
        $denominator = $q_array[2];
        $numerator2 = $q_array[3];
        $denominator2 = $q_array[4];
        $special_instructions = $q_array[5];
    }
    else
    {
        return FALSE;
    } 
    $a_numerator   = strtolower($a_numerator);
    $a_denominator = strtolower($a_denominator);
    if ($q_type == 1)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 2)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 3)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 4)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 5)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 6)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 7)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 8)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    if ($q_type == 9)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 10)
    {
        $a_numerator = strtolower($a_numerator);
        $a_denominator = strtolower($a_denominator);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 11)
    {
        $a_numerator = strtolower($a_numerator);
        $a_denominator = strtolower($a_denominator);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 12)
    {
        $a_numerator = strtolower($a_numerator);
        $a_denominator = strtolower($a_denominator);
        if ($a_numerator == 'undefined')
        {
            return FALSE;
        }

        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 13)
    {
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 14)
    {
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 15)
    {
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 16)
    {
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type >= 17 && $q_type <= 20)
    {
        $numerator = parse_input($numerator,1);
        $a_numerator = parse_input($a_numerator,1);
        if($a_numerator=="Not Simple") return 2;
        if ($numerator == $a_numerator)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if ($q_type == 21)
    {
        $numerator = parse_input($numerator,2);
        $denominator = parse_input($denominator,2);
        $a_numerator = parse_input($a_numerator,2);
        $a_denominator = parse_input($a_denominator,2);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 22)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 23)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 24)
    {
       if ($numerator == $a_numerator && $denominator == $a_denominator)
       {
           return TRUE;
       }
       else
       {
           return FALSE;
       }
    }
    else if ($q_type == 25)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 26)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 27)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 28)
    {
        $numerator = parse_input($numerator,1);
        $a_numerator = parse_input($a_numerator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 29)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 30)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 31)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 32)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 33)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 34)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 35)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 36)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 37)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 38)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 39)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 40)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 41)
    {
        $numerator = parse_input($numerator,6);
        $a_numerator = parse_input($a_numerator,6);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 42)
    {
        $numerator = parse_input($numerator,4);
        $a_numerator = parse_input($a_numerator,4);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 43)
    {
        $numerator = parse_input($numerator,7);
        $a_numerator = parse_input($a_numerator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 44)
    {
        $numerator = parse_input($numerator,7);
        $a_numerator = parse_input($a_numerator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 45)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 46)
    {
        $numerator = parse_input($numerator,4);
        $a_numerator = parse_input($a_numerator,4);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 47)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 48)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 49)
    {
        $numerator = parse_input($numerator,5);
        $a_numerator = parse_input($a_numerator,5);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 50)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 51)
    {
        $numerator = parse_input($numerator,7);
        $a_numerator = parse_input($a_numerator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 52)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,8);
        if (!$s_answer_array = parse_input($a_numerator,8))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 53)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 54)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 55)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,11);
        if (!$s_answer_array = parse_input($a_numerator,11))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 56)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 57)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 58)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 59)
    {
        $num_correct = 0;
        $position_1 = -1;
        $position_2 = -1;
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,12);
        if (!$s_answer_array = parse_input($a_numerator,12))
        {
            return FALSE;
        }
        if ($s_answer_array[3] != NULL)
        {
            return FALSE;
        }
        for ($j = 0; $j < 3; $j++)
        {
            $check = $s_answer_array[$j];
            if ($check == $c_answer_array[0])
            {
                $position_1 = $j;
                $num_correct++;
                break;
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[1])
                {
                    $position_2 = $j;
                    $num_correct++;
                    break;
                }
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1 && $j != $position_2)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[2])
                {
                    $num_correct++;
                    break;
                }
            }
        }
        if ($num_correct == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 60)
    {
        $num_correct = 0;
        $position_1 = -1;
        $position_2 = -1;
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,12);
        if (!$s_answer_array = parse_input($a_numerator,12))
        {
            return FALSE;
        }
        if ($s_answer_array[3] != NULL)
        {
            return FALSE;
        }
        for ($j = 0; $j < 3; $j++)
        {
            $check = $s_answer_array[$j];
            if ($check == $c_answer_array[0])
            {
                $position_1 = $j;
                $num_correct++;
                break;
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[1])
                {
                    $position_2 = $j;
                    $num_correct++;
                    break;
                }
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1 && $j != $position_2)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[2])
                {
                    $num_correct++;
                    break;
                }
            }
        }
        if ($num_correct == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 61)
    {
        $num_correct = 0;
        $position_1 = -1;
        $position_2 = -1;
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,12);
        if (!$s_answer_array = parse_input($a_numerator,12))
        {
            return FALSE;
        }
        if ($s_answer_array[3] != NULL)
        {
            return FALSE;
        }
        for ($j = 0; $j < 3; $j++)
        {
            $check = $s_answer_array[$j];
            if ($check == $c_answer_array[0])
            {
                $position_1 = $j;
                $num_correct++;
                break;
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[1])
                {
                    $position_2 = $j;
                    $num_correct++;
                    break;
                }
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1 && $j != $position_2)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[2])
                {
                    $num_correct++;
                    break;
                }
            }
        }
        if ($num_correct == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 62)
    {
        $num_correct = 0;
        $position_1 = -1;
        $position_2 = -1;
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,12);
        if (!$s_answer_array = parse_input($a_numerator,12))
        {
            return FALSE;
        }
        if ($s_answer_array[3] != NULL)
        {
            return FALSE;
        }
        for ($j = 0; $j < 3; $j++)
        {
            $check = $s_answer_array[$j];
            if ($check == $c_answer_array[0])
            {
                $position_1 = $j;
                $num_correct++;
                break;
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[1])
                {
                    $position_2 = $j;
                    $num_correct++;
                    break;
                }
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1 && $j != $position_2)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[2])
                {
                    $num_correct++;
                    break;
                }
            }
        }
        if ($num_correct == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 63)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,10);
        if (!$s_answer_array = parse_input($a_numerator,10))
        {
            return FALSE;
        }
    if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 64)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,10);
        if (!$s_answer_array = parse_input($a_numerator,10))
        {
            return FALSE;
        }
    if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 65)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,10);
        if (!$s_answer_array = parse_input($a_numerator,10))
        {
            return FALSE;
        }
    if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 66)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,10);
        if (!$s_answer_array = parse_input($a_numerator,10))
        {
            return FALSE;
        }
    if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 67)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,11);
        if (!$s_answer_array = parse_input($a_numerator,11))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 68)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,11);
        if (!$s_answer_array = parse_input($a_numerator,11))
        {
            echo "got here";
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 69)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 70)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 71)
    {
        if ($a_denominator != "1")
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,14);
        if (!$s_answer_array = parse_input($a_numerator,14))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 72)
    {
        $a_numerator = strtolower($a_numerator);
        if ($a_denominator != 1)
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 73)
    {
        $a_numerator = strtolower($a_numerator);
        if ($a_denominator != 1)
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,9);
        if (!$s_answer_array = parse_input($a_numerator,9))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 74)
    {
        $a_numerator = strtolower($a_numerator);
        if ($a_denominator != 1)
        {
            return FALSE;
        }
        $c_answer_array = parse_input($numerator,15);
        if (!$s_answer_array = parse_input($a_numerator,15))
        {
            return FALSE;
        }
        if ($s_answer_array[2] != NULL)
        {
            return FALSE;
        }
        if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
        {
            return TRUE;
        }
        else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 75)
    {
        $a_numerator = strtolower($a_numerator);
        if ($a_denominator != 1)
        {
            return FALSE;
        }
        $num_correct = 0;
        $position_1 = -1;
        $position_2 = -1;
        $c_answer_array = parse_input($numerator,16);
        if (!$s_answer_array = parse_input($a_numerator,16))
        {
            return FALSE;
        }
        if ($s_answer_array[3] != NULL)
        {
            return FALSE;
        }
        for ($j = 0; $j < 3; $j++)
        {
            $check = $s_answer_array[$j];
            if ($check == $c_answer_array[0])
            {
                $position_1 = $j;
                 $num_correct++;
                break;
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[1])
                {
                    $position_2 = $j;
                    $num_correct++;
                    break;
                }
            }
        }
        for ($j = 0; $j < 3; $j++)
        {
            if ($j != $position_1 && $j != $position_2)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[2])
                {
                    $num_correct++;
                    break;
                }
            }
        }
        if ($num_correct == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    else if ($q_type == 76)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 77)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 78)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 79)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 80)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 81)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 82)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 83)
    {
        $numerator = parse_input($numerator,3);
        $denominator2 = parse_input($denominator2,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denom = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $a_numerator)
            {
                $c_answer_array = parse_input($denominator,9);
                if (!$s_answer_array = parse_input($a_denominator,9))
                {
                    return FALSE;
                }
                if ($s_answer_array[2] != NULL)
                {
                    return FALSE;
                }
                if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 84)
    {
        $numerator = parse_input($numerator,3);
        $denominator2 = parse_input($denominator2,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denom = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator2 == $a_denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $a_numerator)
            {
                $c_answer_array = parse_input($denominator,9);
                if (!$s_answer_array = parse_input($a_denominator,9))
                {
                    return FALSE;
                }
                if ($s_answer_array[2] != NULL)
                {
                    return FALSE;
                }
                if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 85)
    {
        $numerator = parse_input($numerator,3);
        $denominator2 = parse_input($denominator2,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denom = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator2 == $a_denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $a_numerator)
            {
                $c_answer_array = parse_input($denominator,9);
                if (!$s_answer_array = parse_input($a_denominator,9))
                {
                    return FALSE;
                }
                if ($s_answer_array[2] != NULL)
                {
                    return FALSE;
                }
                if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 86)
    {
        $numerator = parse_input($numerator,17);
        $denominator2 = parse_input($denominator2,17);
        $a_numerator = parse_input($a_numerator,17);
        $a_denom = parse_input($a_denominator,17);
        if ($numerator == $a_numerator && $denominator2 == $a_denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $a_numerator)
            {
                $num_correct = 0;
                $position_1 = -1;
                $position_2 = -1;
                $c_answer_array = parse_input($denominator,18);
                if (!$s_answer_array = parse_input($a_denominator,18))
                {
                    return FALSE;
                }
                if ($s_answer_array[3] != NULL)
                {
                    return FALSE;
                }
                for ($j = 0; $j < 3; $j++)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[0])
                    {
                        $position_1 = $j;
                         $num_correct++;
                        break;
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[1])
                        {
                            $position_2 = $j;
                            $num_correct++;
                            break;
                        }
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1 && $j != $position_2)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[2])
                        {
                            $num_correct++;
                            break;
                        }
                    }
                }
                if ($num_correct == 3)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 87)
    {
        $numerator = parse_input($numerator,3);
        $denominator2 = parse_input($denominator2,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denom = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator2 == $a_denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $a_numerator)
            {
                $c_answer_array = parse_input($denominator,9);
                if (!$s_answer_array = parse_input($a_denominator,9))
                {
                    return FALSE;
                }
                if ($s_answer_array[2] != NULL)
                {
                    return FALSE;
                }
                if ($c_answer_array[0] == $s_answer_array[0] && $c_answer_array[1] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else if ($c_answer_array[1] == $s_answer_array[0] && $c_answer_array[0] == $s_answer_array[1])
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 88)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 89)
    {
        $numerator = parse_input($numerator,7);
        $denominator = parse_input($denominator,7);
        $a_numerator = parse_input($a_numerator,7);
        $a_denominator = parse_input($a_denominator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 90)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 91)
    {
        $numerator2 = parse_input($numerator2,3);
        $denominator2 = parse_input($denominator2,3);
        $num = parse_input($a_numerator,3);
        $denom = parse_input($a_denominator,3);
        if ($numerator2 == $num && $denominator2 == $denom)
        {
            return TRUE;
        }
        else if ($numerator2 == $num && $denominator2 != $denom)
        {
            $num_correct = 0;
            $position_1 = -1;
            $position_2 = -1;
            $c_answer_array = parse_input($denominator,12);
            if (!$s_answer_array = parse_input($a_denominator,12))
            {
                return FALSE;
            }
            if ($s_answer_array[3] != NULL)
            {
                return FALSE;
            }
            for ($j = 0; $j < 3; $j++)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[0])
                {
                    $position_1 = $j;
                    $num_correct++;
                    break;
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[1])
                    {
                        $position_2 = $j;
                        $num_correct++;
                        break;
                    }
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1 && $j != $position_2)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[2])
                    {
                        $num_correct++;
                        break;
                    }
                }
            }
            if ($num_correct == 3)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($numerator2 != $num && $denominator2 == $denom)
        {
            $num_correct = 0;
            $position_1 = -1;
            $position_2 = -1;
            $c_answer_array = parse_input($numerator,12);
            if (!$s_answer_array = parse_input($a_numerator,12))
            {
                return FALSE;
            }
            if ($s_answer_array[3] != NULL)
            {
                return FALSE;
            }
            for ($j = 0; $j < 3; $j++)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[0])
                {
                    $position_1 = $j;
                     $num_correct++;
                    break;
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[1])
                    {
                        $position_2 = $j;
                        $num_correct++;
                        break;
                    }
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1 && $j != $position_2)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[2])
                    {
                        $num_correct++;
                        break;
                    }
                }
            }
            if ($num_correct == 3)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            $numer_correct = FALSE;
            $denom_correct = FALSE;
            $num_correct = 0;
            $position_1 = -1;
            $position_2 = -1;
            $c_answer_array = parse_input($numerator,12);
            if (!$s_answer_array = parse_input($a_numerator,12))
            {
                return FALSE;
            }
            if ($s_answer_array[3] != NULL)
            {
                return FALSE;
            }
            for ($j = 0; $j < 3; $j++)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[0])
                {
                    $position_1 = $j;
                     $num_correct++;
                    break;
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[1])
                    {
                        $position_2 = $j;
                        $num_correct++;
                        break;
                    }
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1 && $j != $position_2)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[2])
                    {
                        $num_correct++;
                        break;
                    }
                }
            }
            if ($num_correct == 3)
            {
                $numer_correct = TRUE;
            }
            $num_correct = 0;
            $position_1 = -1;
            $position_2 = -1;
            $c_answer_array = parse_input($denominator,12);
            if (!$s_answer_array = parse_input($a_denominator,12))
            {
                return FALSE;
            }
            if ($s_answer_array[3] != NULL)
            {
                return FALSE;
            }
            for ($j = 0; $j < 3; $j++)
            {
                $check = $s_answer_array[$j];
                if ($check == $c_answer_array[0])
                {
                    $position_1 = $j;
                     $num_correct++;
                    break;
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[1])
                    {
                        $position_2 = $j;
                        $num_correct++;
                        break;
                    }
                }
            }
            for ($j = 0; $j < 3; $j++)
            {
                if ($j != $position_1 && $j != $position_2)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[2])
                    {
                        $num_correct++;
                        break;
                    }
                }
            }
            if ($num_correct == 3)
            {
                $denom_correct = TRUE;
            }
            if ($denom_correct == TRUE && $numer_correct == TRUE)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 92)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,4);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,4);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 93)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $num = parse_input($a_numerator,3);
        $denom = parse_input($a_denominator,3);
        if ($numerator == $num && $denominator == $denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $num)
            {
                $num_correct = 0;
                $position_1 = -1;
                $position_2 = -1;
                $c_answer_array = parse_input($numerator2,12);
                if (!$s_answer_array = parse_input($a_numerator,12))
                {
                    return FALSE;
                }
                if ($s_answer_array[3] != NULL)
                {
                    return FALSE;
                }
                for ($j = 0; $j < 3; $j++)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[0])
                    {
                        $position_1 = $j;
                         $num_correct++;
                        break;
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[1])
                        {
                            $position_2 = $j;
                            $num_correct++;
                            break;
                        }
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1 && $j != $position_2)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[2])
                        {
                            $num_correct++;
                            break;
                        }
                    }
                }
                if ($num_correct == 3)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 94)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $num = parse_input($a_numerator,3);
        $denom = parse_input($a_denominator,3);
        if ($numerator == $num && $denominator == $denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $num)
            {
                $num_correct = 0;
                $position_1 = -1;
                $position_2 = -1;
                $c_answer_array = parse_input($denominator2,12);
                if (!$s_answer_array = parse_input($a_denominator,12))
                {
                    return FALSE;
                }
                if ($s_answer_array[3] != NULL)
                {
                    return FALSE;
                }
                for ($j = 0; $j < 3; $j++)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[0])
                    {
                        $position_1 = $j;
                         $num_correct++;
                        break;
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[1])
                        {
                            $position_2 = $j;
                            $num_correct++;
                            break;
                        }
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1 && $j != $position_2)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[2])
                        {
                            $num_correct++;
                            break;
                        }
                    }
                }
                if ($num_correct == 3)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 95)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $num = parse_input($a_numerator,3);
        $denom = parse_input($a_denominator,3);
        if ($numerator == $num && $denominator == $denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $num)
            {
                $num_correct = 0;
                $position_1 = -1;
                $position_2 = -1;
                $c_answer_array = parse_input($denominator2,12);
                if (!$s_answer_array = parse_input($a_denominator,12))
                {
                    return FALSE;
                }
                if ($s_answer_array[3] != NULL)
                {
                    return FALSE;
                }
                for ($j = 0; $j < 3; $j++)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[0])
                    {
                        $position_1 = $j;
                         $num_correct++;
                        break;
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[1])
                        {
                            $position_2 = $j;
                            $num_correct++;
                            break;
                        }
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1 && $j != $position_2)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[2])
                        {
                            $num_correct++;
                            break;
                        }
                    }
                }
                if ($num_correct == 3)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 96)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $num = parse_input($a_numerator,3);
        $denom = parse_input($a_denominator,3);
        if ($numerator == $num && $denominator == $denom)
        {
            return TRUE;
        }
        else
        {
            if ($numerator == $num)
            {
                $num_correct = 0;
                $position_1 = -1;
                $position_2 = -1;
                $c_answer_array = parse_input($numerator2,12);
                if (!$s_answer_array = parse_input($a_numerator,12))
                {
                    return FALSE;
                }
                if ($s_answer_array[3] != NULL)
                {
                    return FALSE;
                }
                for ($j = 0; $j < 3; $j++)
                {
                    $check = $s_answer_array[$j];
                    if ($check == $c_answer_array[0])
                    {
                        $position_1 = $j;
                         $num_correct++;
                        break;
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[1])
                        {
                            $position_2 = $j;
                            $num_correct++;
                            break;
                        }
                    }
                }
                for ($j = 0; $j < 3; $j++)
                {
                    if ($j != $position_1 && $j != $position_2)
                    {
                        $check = $s_answer_array[$j];
                        if ($check == $c_answer_array[2])
                        {
                            $num_correct++;
                            break;
                        }
                    }
                }
                if ($num_correct == 3)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 97)
    {
        $numerator = parse_input($numerator,7);
        $denominator = parse_input($denominator,7);
        $a_numerator = parse_input($a_numerator,7);
        $a_denominator = parse_input($a_denominator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 98)
    {
        $numerator = parse_input($numerator,7);
        $denominator = parse_input($denominator,7);
        $a_numerator = parse_input($a_numerator,7);
        $a_denominator = parse_input($a_denominator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 99)
    {
        $numerator = parse_input($numerator,7);
        $denominator = parse_input($denominator,7);
        $a_numerator = parse_input($a_numerator,7);
        $a_denominator = parse_input($a_denominator,7);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 100)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 101)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 102)
    {
        $numerator = parse_input($numerator,3);
        $denominator = parse_input($denominator,3);
        $a_numerator = parse_input($a_numerator,3);
        $a_denominator = parse_input($a_denominator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 103)
    {
        $numerator = parse_input($numerator,19);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,19);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 104)
    {
        $numerator = parse_input($numerator,19);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,19);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    else if ($q_type == 105)
    {
        $numerator = parse_input($numerator,1);
        $denominator = parse_input($denominator,1);
        $a_numerator = parse_input($a_numerator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 106)
    {
        $numerator = parse_input($numerator,20);
        $a_numerator = parse_input($a_numerator,20);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 107)
    {
        $numerator = parse_input($numerator,21);
        $a_numerator = parse_input($a_numerator,21);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    else if ($q_type == 108)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 109)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    else if ($q_type == 110)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 111)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    else if ($q_type == 112)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 113)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 114)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 115)
    {
        $numerator = parse_input($numerator,22);
        $a_numerator = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 116)
    {
        $numerator2 = parse_input($numerator2,22);
        $a_numerator1 = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator2 == $a_numerator1 && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            $numerator = parse_input($numerator,23);
            $a_numerator = parse_input($a_numerator,23);
            if ($numerator == $a_numerator && $denominator == $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 117)
    {
        $numerator2 = parse_input($numerator2,22);
        $a_numerator1 = parse_input($a_numerator,22);
        $denominator = parse_input($denominator,1);
        $a_denominator = parse_input($a_denominator,1);
        if ($numerator2 == $a_numerator1 && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            $numerator = parse_input($numerator,23);
            $a_numerator = parse_input($a_numerator,23);
            if ($numerator == $a_numerator && $denominator == $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 118)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 119)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 120)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 121)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 122)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 123)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 124)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 125)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 126)
    {
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 127)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $a_numerator = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;
        $numerator = $numerator + 0;
        $denominator = $denominator +0;
        if ($a_numerator < 0 && $a_denominator < 0)
        {
            return FALSE;
        }
        else if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        else if ($a_numerator == ((-1) * $numerator) && $a_denominator == ((-1) * $denominator))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 128)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 129)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 130)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 131)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 132)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 133)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 134)
    {
        if ($numerator == "no solution")
        {
            $a_numerator = strtolower($a_numerator);
            if ($a_numerator == $numerator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 135)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 136)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 137)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 138)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 139)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 140)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 141)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 142)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 143)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 144)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 145)
    {
        $numerator = parse_input($numerator,3);
        $a_numerator = parse_input($a_numerator,3);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 146)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 147)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 148)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 149)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 150)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 151)
    {
        $numerator = parse_input($numerator,27);
        $a_numerator = parse_input($a_numerator,27);
        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 152)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 153)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 154)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 155)
    {
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 156)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 157)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 158)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 159)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 160)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 161)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 162)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 163)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 164)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 165)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 166)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 167)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 168)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 169)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 170)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 171)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 172)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 173)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 174)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 175)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 176)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 177)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 178)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 179)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 180)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 181)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 182)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 183)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 184)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                if ($i == 2)
                {
                    if ($num_array[$i] == 0 && $a_num_array[$i] == "not_used")
                    {
                        //// do nothing
                    }
                    else
                    {
                        return FALSE;
                    }
                }
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 185)
    {
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $num_array = explode('@',$numerator);
        $a_num_array = explode('@',$a_numerator);
        for ($i = 0; $i < 8; $i++)
        {
            if ($num_array[$i] != $a_num_array[$i])
            {
                if ($i == 2)
                {
                    if ($num_array[$i] == 0 && $a_num_array[$i] == "not_used")
                    {
                        //// do nothing
                    }
                    else
                    {
                        return FALSE;
                    }
                }
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 186)
    {
        $a_numerator = str_replace('$','',$a_numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = $a_numerator + 0;
        if ($a_numerator > $denominator2 && $a_numerator < $numerator2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 187)
    {
        $a_numerator = str_replace('$','',$a_numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = $a_numerator + 0;
        if ($a_numerator > $denominator2 && $a_numerator < $numerator2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 188)
    {
        $a_numerator = str_replace('$','',$a_numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = $a_numerator + 0;
        if ($a_numerator > $denominator2 && $a_numerator < $numerator2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 189)
    {
        $numerator = strtolower($numerator) ;
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 190)
    {
        $a_array = explode('@',$a_numerator);
        $n_array = explode('@',$numerator);
        for ($i = 0; $i < 6; $i++)
        {
            if ($a_array[$i] < ($n_array[$i] - 0.006) || $a_array[$i] > ($n_array[$i] + 0.006))
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 191)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 192)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 193)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 194)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 195)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 196)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 197)
    {
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = $a_denominator + 0;
        $a_numerator = $a_numerator +0;
        if ($a_denominator != $denominator)
        {
            return FALSE;
        }
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 198)
    {
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = $a_denominator + 0;
        $a_numerator = $a_numerator +0;
        if ($a_denominator != $denominator)
        {
            return FALSE;
        }
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 199)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 200)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 201)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 202)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 203)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 204)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 205)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 206)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 207)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.0006) || $a_numerator > ($numerator + 0.0006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 208)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 209)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('%','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 210)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 211)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 212)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 213)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 214)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 215)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 216)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 217)
    {
        $numerator = strtolower($numerator) ;
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 218)
    {
        $numerator = strtolower($numerator) ;
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 219)
    {
        $numerator = strtolower($numerator) ;
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 220)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 221)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_numerator == $numerator && $a_denominator == $denominator)
        {
            return TRUE;
        }
        return FALSE;
    }
    else if ($q_type == 222)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_denominator < ($denominator - 0.00006) || $a_denominator > ($denominator + 0.00006))
        {
            return FALSE;
        }
        if ($numerator != $a_numerator)
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 223)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        if ($a_denominator < ($denominator - 0.00006) || $a_denominator > ($denominator + 0.00006))
        {
            return FALSE;
        }
        if ($numerator != $a_numerator)
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 224)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('$','',$a_numerator);
        $numerator = str_replace('$','',$numerator);
        $numerator = $numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 225)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('$','',$a_numerator);
        $numerator = str_replace('$','',$numerator);
        $numerator = $numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 226)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('years','',$a_numerator);
        $numerator = str_replace('years','',$numerator);
        $numerator = $numerator + 0;
        $a_numerator = $a_numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 227)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('%','',$a_numerator);
        $numerator = str_replace('%','',$numerator);
        $numerator = $numerator + 0;
        $a_numerator = $a_numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 228)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        for ($j = 0; $j < 6; $j++)
        {
            $n_array[$j] = str_replace('(','',$n_array[$j]);
            $n_array[$j] = str_replace(')','',$n_array[$j]);
            $a_array[$j] = str_replace('(','',$a_array[$j]);
            $a_array[$j] = str_replace(')','',$a_array[$j]);
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 229)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        for ($j = 0; $j < 6; $j++)
        {
            $n_array[$j] = str_replace('(','',$n_array[$j]);
            $n_array[$j] = str_replace(')','',$n_array[$j]);
            $a_array[$j] = str_replace('(','',$a_array[$j]);
            $a_array[$j] = str_replace(')','',$a_array[$j]);
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 230)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        for ($j = 0; $j < 6; $j++)
        {
            $n_array[$j] = str_replace('(','',$n_array[$j]);
            $n_array[$j] = str_replace(')','',$n_array[$j]);
            $a_array[$j] = str_replace('(','',$a_array[$j]);
            $a_array[$j] = str_replace(')','',$a_array[$j]);
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 231)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        for ($j = 0; $j < 6; $j++)
        {
            $n_array[$j] = str_replace('(','',$n_array[$j]);
            $n_array[$j] = str_replace(')','',$n_array[$j]);
            $a_array[$j] = str_replace('(','',$a_array[$j]);
            $a_array[$j] = str_replace(')','',$a_array[$j]);
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 232)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        $split = "@";
        for ($i = 0; $i < 6; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 233)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        $split = "@";
        for ($i = 0; $i < 6; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 234)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        $split = "@";
        for ($i = 0; $i < 6; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 235)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        $split = "@";
        for ($i = 0; $i < 6; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 5; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],3);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 236)
    {
        $a_array = explode('#',$a_numerator);
        $n_array = explode('#',$numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0])
        {
            $num_true++;
        }
        if ($n_array[1] == $a_array[1] && $n_array[2] == $a_array[2])
        {
            $num_true++;
        }
        else if ($n_array[1] == $a_array[2] && $n_array[2] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[3] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[5])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[4] && $n_array[4] == $a_array[5] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[4] && $n_array[5] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[3] == $a_array[5] && $n_array[4] == $a_array[3] && $n_array[5] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 237)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {

                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 238)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {

                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 239)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],2);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],2);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 240)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],30);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],30);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 241)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 242)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $a_array[$i] = $new_string;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                $temp_array[$j] = parse_input($temp_array[$j],29);
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 243)
    {
        $a_array = explode('##',$a_numerator);
        $n_array = explode('##',$numerator);
        $split = '@';
        $num_true = 0;
        for ($i = 1; $i < 3; $i++)
        {
            $temp_array = explode('@',$a_array[$i]);
            $new_string = "";
            $temp2_array = explode('@',$a_array[$i]);
            $temp3_array = explode('@',$a_array[$i]);
            $temp_array[0] = parse_input($temp_array[0], 30);
            $temp2_array[0] = parse_input($temp2_array[0], 29);
            $temp3_array[0] = parse_input($temp3_array[0], 29);
            $temp_array[1] = parse_input($temp_array[1], 29);
            $temp2_array[1] = parse_input($temp2_array[1], 30);
            $temp3_array[1] = parse_input($temp3_array[1], 29);
            $temp_array[2] = parse_input($temp_array[2], 29);
            $temp2_array[2] = parse_input($temp2_array[2], 29);
            $temp3_array[2] = parse_input($temp3_array[2], 30);
            $a_array[$i] = $temp_array[0].$split.$temp_array[1].$split.$temp_array[2].$split;
            $a2_array[$i] = $temp2_array[0].$split.$temp2_array[1].$split.$temp2_array[2].$split;
            $a3_array[$i] = $temp3_array[0].$split.$temp3_array[1].$split.$temp3_array[2].$split;
            $temp_array = explode('@',$n_array[$i]);
            $new_string = "";
            for ($j = 0; $j < 3; $j++)
            {
                if ($j == 0)
                {
                    $temp_array[$j] = parse_input($temp_array[$j],30);
                }
                else
                {
                    $temp_array[$j] = parse_input($temp_array[$j],29);
                }
                $new_string .= $temp_array[$j].$split;
            }
            $n_array[$i] = $new_string;
        }
        $base = $n_array[0];
        $a_base = $a_array[0];
        $num_array = explode('@',$n_array[1]);
        $denom_array = explode('@',$n_array[2]);
        $a_num_array = explode('@',$a_array[1]);
        $a_denom_array = explode('@',$a_array[2]);
        if ($base == $a_base)
        {
            $num_true++;
        }
        $a2_num_array = explode('@',$a2_array[1]);
        $a2_denom_array = explode('@',$a2_array[2]);
        $a3_num_array = explode('@',$a3_array[1]);
        $a3_denom_array = explode('@',$a3_array[2]);
        if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[0] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
            else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[2] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[1] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[1] && $num_array[2] == $a_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a_num_array[2] && $num_array[1] == $a_num_array[0] && $num_array[2] == $a_num_array[1])
        {
            $num_true++;
        }
            else if ($num_array[0] == $a2_num_array[0] && $num_array[1] == $a2_num_array[1] && $num_array[2] == $a2_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a2_num_array[0] && $num_array[1] == $a2_num_array[2] && $num_array[2] == $a2_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a2_num_array[1] && $num_array[1] == $a2_num_array[2] && $num_array[2] == $a2_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a2_num_array[1] && $num_array[1] == $a2_num_array[0] && $num_array[2] == $a2_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a2_num_array[2] && $num_array[1] == $a2_num_array[1] && $num_array[2] == $a2_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a2_num_array[2] && $num_array[1] == $a2_num_array[0] && $num_array[2] == $a2_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[0] && $num_array[1] == $a3_num_array[1] && $num_array[2] == $a3_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[0] && $num_array[1] == $a3_num_array[2] && $num_array[2] == $a3_num_array[1])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[1] && $num_array[1] == $a3_num_array[2] && $num_array[2] == $a3_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[1] && $num_array[1] == $a3_num_array[0] && $num_array[2] == $a3_num_array[2])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[2] && $num_array[1] == $a3_num_array[1] && $num_array[2] == $a3_num_array[0])
        {
            $num_true++;
        }
        else if ($num_array[0] == $a3_num_array[2] && $num_array[1] == $a3_num_array[0] && $num_array[2] == $a3_num_array[1])
        {
            $num_true++;
        }
        if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[0] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[2] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[1] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[2])
        {
                $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[1] && $denom_array[2] == $a_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a_denom_array[2] && $denom_array[1] == $a_denom_array[0] && $denom_array[2] == $a_denom_array[1])
        {
                $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[0] && $denom_array[1] == $a2_denom_array[1] && $denom_array[2] == $a2_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[0] && $denom_array[1] == $a2_denom_array[2] && $denom_array[2] == $a2_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[1] && $denom_array[1] == $a2_denom_array[2] && $denom_array[2] == $a2_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[1] && $denom_array[1] == $a2_denom_array[0] && $denom_array[2] == $a2_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[2] && $denom_array[1] == $a2_denom_array[1] && $denom_array[2] == $a2_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a2_denom_array[2] && $denom_array[1] == $a2_denom_array[0] && $denom_array[2] == $a2_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[0] && $denom_array[1] == $a3_denom_array[1] && $denom_array[2] == $a3_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[0] && $denom_array[1] == $a3_denom_array[2] && $denom_array[2] == $a3_denom_array[1])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[1] && $denom_array[1] == $a3_denom_array[2] && $denom_array[2] == $a3_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[1] && $denom_array[1] == $a3_denom_array[0] && $denom_array[2] == $a3_denom_array[2])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[2] && $denom_array[1] == $a3_denom_array[1] && $denom_array[2] == $a3_denom_array[0])
        {
            $num_true++;
        }
        else if ($denom_array[0] == $a3_denom_array[2] && $denom_array[1] == $a3_denom_array[0] && $denom_array[2] == $a3_denom_array[1])
        {
            $num_true++;
        }
        if ($num_true == 3)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 244)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 245)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 246)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 247)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 248)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 249)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 250)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 251)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 252)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.00006) || $a_numerator > ($numerator + 0.00006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 253)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.06) || $a_numerator > ($numerator + 0.06))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 254)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.06) || $a_numerator > ($numerator + 0.06))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 255)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator < ($numerator - 0.06) || $a_numerator > ($numerator + 0.06))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 256)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 257)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 258)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 259)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 260)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 261)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 262)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 263)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 264)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 265)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 266)
    {
        $num_correct = FALSE;
        $denom_correct = FALSE;
        $numerator = str_replace(' ','',$numerator);
        $a_numerator = str_replace(' ','',$a_numerator);
        $denominator = parse_input($denominator,28);
        $a_denominator = parse_input($a_denominator,28);
        if ($numerator == $a_numerator)
        {
            $num_correct = TRUE;
        }
        if ($denominator[0] == $a_denominator[0] && $denominator[1] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        else if ($denominator[1] == $a_denominator[0] && $denominator[0] == $a_denominator[1])
        {
            $denom_correct = TRUE;
        }
        if ($num_correct == TRUE && $denom_correct == TRUE)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 267)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('*','',$a_denominator);
        if ($a_denominator < ($denominator - 0.00006) || $a_denominator > ($denominator + 0.06))
        {
            return FALSE;
        }
        if ($a_numerator != $numerator)
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 268)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('years','',$a_numerator);
        $numerator = str_replace('years','',$numerator);
        $numerator = $numerator + 0;
        $a_numerator = $a_numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 269)
    {
        $a_numerator = parse_input($a_numerator,3);
        $numerator = parse_input($numerator,3);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 270)
    {
        $a_numerator = parse_input($a_numerator,3);
        $numerator = parse_input($numerator,3);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 271)
    {
        $a_numerator = parse_input($a_numerator,3);
        $numerator = parse_input($numerator,3);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 272)
    {
        $a_numerator = parse_input($a_numerator,3);
        $numerator = parse_input($numerator,3);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 273)
    {
        $a_numerator = parse_input($a_numerator,3);
        $numerator = parse_input($numerator,3);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 274)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 275)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 276)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 277)
    {
        $numerator = strtolower($numerator) ;
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 278)
    {
        $numerator = strtolower($numerator) ;
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 279)
    {
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator != $numerator)
        {
            return FALSE;
        }
        else if ($a_denominator != $denominator)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else if ($q_type == 280)
    {
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator != $numerator)
        {
            return FALSE;
        }
        else if ($a_denominator != $denominator)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else if ($q_type == 281)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 282)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $n_array[0] = parse_input($n_array[0],22);
        $n_array[2] = parse_input($n_array[2],22);
        $a_array[0] = parse_input($a_array[0],22);
        $a_array[2] = parse_input($a_array[2],22);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 283)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 284)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 285)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 286)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 287)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if (!strlen($a_numerator))
        {
            return FALSE;
        }
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 288)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if (!strlen($a_numerator))
        {
            return FALSE;
        }
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 289)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 290)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 291)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 292)
    {
        $a_temp = parse_input($a_numerator,31);
        $temp = parse_input($numerator,31);
        if ($a_temp == $temp)
        {
            return TRUE;
        }
        else
        {
            $a_temp = parse_input($a_numerator,32);
            $temp = parse_input($numerator2,32);
            $a_array = explode('@',$a_temp);
            $n_array = explode('@',$temp);
            if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
            {
                return TRUE;
            }
            else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 293)
    {
        $a_temp = parse_input($a_numerator,31);
        $temp = parse_input($numerator,31);
        if ($a_temp == $temp)
        {
            return TRUE;
        }
        else
        {
            $a_temp = parse_input($a_numerator,32);
            $temp = parse_input($numerator2,32);
            $a_array = explode('@',$a_temp);
            $n_array = explode('@',$temp);
            if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
            {
                return TRUE;
            }
            else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 294)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 295)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 296)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 297)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 298)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 299)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 300)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 301)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 302)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 303)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 304)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 305)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 306)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 307)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode("<fontface=arial>u</font>",$a_numerator);
        $n_array = explode("<fontface=arial>U</font>",$numerator);
        if ($a_array[0] == $n_array[0] && $a_array[1] == $n_array[1])
        {
            return TRUE;
        }
        else if ($a_array[0] == $n_array[1] && $a_array[1] == $n_array[0])
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 308)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $a_denominator = str_replace(')','',$a_denominator);
        $a_denominator = str_replace('(','',$a_denominator);
        if ($a_denominator == '-')
        {
            $a_denominator = -1;
        }
        if (!(strlen($a_denominator)))
        {
            $a_denominator = 1;
        }
        if ($a_denominator == $denominator && $a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 309)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 310)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 311)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 312)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 313)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 314)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 315)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 316)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 317)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode(',',$a_numerator);
        $n_array = explode(',',$numerator);
        $position = array();
        for ($i = 0; $i < 4; $i++)
        {
            $position[$i] = -1;
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[0])
            {
                $position[0] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[1] && $i != $position[0])
            {
                $position[1] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[2] && $i != $position[0] && $i != $position[1])
            {
                $position[2] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[3] && $i != $position[0])
            {
                if ($i != $position[1] && $i != $position[2])
                {
                    $position[3] = $i;
                }
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($position[$i] == -1)
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 318)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('(','',$a_numerator);
        $a_numerator = str_replace(')','',$a_numerator);
        $numerator = str_replace(' ','',$numerator);
        $a_array = explode(',',$a_numerator);
        $n_array = explode(',',$numerator);
        $position = array();
        for ($i = 0; $i < 4; $i++)
        {
            $position[$i] = -1;
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[0])
            {
                $position[0] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[1] && $i != $position[0])
            {
                $position[1] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[2] && $i != $position[0] && $i != $position[1])
            {
                $position[2] = $i;
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($a_array[$i] == $n_array[3] && $i != $position[0])
            {
                if ($i != $position[1] && $i != $position[2])
                {
                    $position[3] = $i;
                }
            }
        }
        for ($i = 0; $i < 4; $i++)
        {
            if ($position[$i] == -1)
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    else if ($q_type == 319)
    {
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 320)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('$','',$a_numerator);
        $numerator = str_replace('$','',$numerator);
        $numerator = $numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 321)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('$','',$a_numerator);
        $numerator = str_replace('$','',$numerator);
        $numerator = $numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 322)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('years','',$a_numerator);
        $numerator = str_replace('years','',$numerator);
        $numerator = $numerator + 0;
        $a_numerator = $a_numerator + 0;
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 323)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('sec','',$a_numerator);
        $a_numerator = str_replace('second','',$a_numerator);
        $a_numerator = str_replace('seconds','',$a_numerator);
        $a_numerator = str_replace('s','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $n_array[0] = parse_input($n_array[0],22);
        $n_array[2] = parse_input($n_array[2],22);
        $a_array[0] = parse_input($a_array[0],22);
        $a_array[2] = parse_input($a_array[2],22);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 324)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('sec','',$a_numerator);
        $a_numerator = str_replace('second','',$a_numerator);
        $a_numerator = str_replace('seconds','',$a_numerator);
        $a_numerator = str_replace('s','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $n_array[0] = parse_input($n_array[0],22);
        $n_array[2] = parse_input($n_array[2],22);
        $a_array[0] = parse_input($a_array[0],22);
        $a_array[2] = parse_input($a_array[2],22);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 325)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('sec','',$a_numerator);
        $a_numerator = str_replace('second','',$a_numerator);
        $a_numerator = str_replace('seconds','',$a_numerator);
        $a_numerator = str_replace('s','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $n_array[0] = parse_input($n_array[0],22);
        $n_array[2] = parse_input($n_array[2],22);
        $a_array[0] = parse_input($a_array[0],22);
        $a_array[2] = parse_input($a_array[2],22);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 326)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('sec','',$a_numerator);
        $a_numerator = str_replace('second','',$a_numerator);
        $a_numerator = str_replace('seconds','',$a_numerator);
        $a_numerator = str_replace('s','',$a_numerator);
        $n_array = explode('@',$numerator);
        $a_array = explode('@',$a_numerator);
        $n_array[0] = parse_input($n_array[0],22);
        $n_array[2] = parse_input($n_array[2],22);
        $a_array[0] = parse_input($a_array[0],22);
        $a_array[2] = parse_input($a_array[2],22);
        $num_true = 0;
        if ($n_array[0] == $a_array[0] && $n_array[1] == $a_array[1] && $n_array[2] == $a_array[2] && $n_array[3] == $a_array[3])
        {
            $num_true++;
        }
        else if ($n_array[0] == $a_array[2] && $n_array[1] == $a_array[3] && $n_array[2] == $a_array[0] && $n_array[3] == $a_array[1])
        {
            $num_true++;
        }
        if ($n_array[4] == $a_array[4])
        {
            $num_true++;
        }
        if ($num_true == 2)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 327)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = $numerator + 0;
        $denominator   = $denominator + 0;
        $a_numerator   = $a_numerator + 0;
        $a_denominator = $a_denominator + 0;

        if ($numerator == $a_numerator && $denominator == $a_denominator)
        {
            return TRUE;
        }
        else if ($a_denominator < 0)
        {
            if ($a_numerator < 0)
            {
                return FALSE;
            }
            if ($numerator = (-1) * $a_numerator && $denominator == (-1) * $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if ($a_denominator != 0)
        {
            if ($numerator / $denominator == $a_numerator / $a_denominator)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 328)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('decibals','',$a_numerator);
        $a_numerator = str_replace('dB','',$a_numerator);
        if ($a_numerator == $numerator)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 329)
    {
        $a_numerator = str_replace(' ','',$a_numerator);
        $a_numerator = str_replace('decibals','',$a_numerator);
        $a_numerator = str_replace('dB','',$a_numerator);
        if ($a_numerator < ($numerator - 0.006) || $a_numerator > ($numerator + 0.006))
        {
            return FALSE;
        }
        return TRUE;
    }
    else if ($q_type == 330)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $a_denominator = trim_parenth($a_denominator);
        $numerator     = trim_parenth($numerator);
        $denominator   = trim_parenth($denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);
        $denom_correct = equiv_polynomials($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 331)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }    else if ($q_type == 332)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $a_denominator = trim_parenth($a_denominator);
        $numerator     = trim_parenth($numerator);
        $denominator   = trim_parenth($denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);
        $denom_correct = equiv_polynomials($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 333)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $numerator     = trim_parenth($numerator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $denom_correct = equiv_terms($a_denominator,$denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 334)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 335)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $numerator     = trim_parenth($numerator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $denom_correct = equiv_terms($a_denominator,$denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 336)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 337)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $numerator2    = str_replace(' ','',$numerator2);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $numerator     = trim_parenth($numerator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $denom_correct = equiv_terms($a_denominator,$denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            $num_correct = equiv_terms($a_numerator,$numerator);
            $num2_correct = equiv_terms($a_numerator,$numerator2);
            if ($num_correct && $denom_correct)
            {
                return TRUE;
            }
            else if ($num2_correct && $denom_correct)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else if ($q_type == 338)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 339)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 340)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 341)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 342)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 343)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 344)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 345)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 346)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 347)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct   = equiv_terms($a_numerator,$numerator);
        $denom_correct = equiv_terms($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 348)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $a_denominator = trim_parenth($a_denominator);
        $numerator     = trim_parenth($numerator);
        $denominator   = trim_parenth($denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);
        $denom_correct = equiv_polynomials($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 349)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $a_denominator = trim_parenth($a_denominator);
        $numerator     = trim_parenth($numerator);
        $denominator   = trim_parenth($denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);
        $denom_correct = equiv_polynomials($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if ($q_type == 350)
    {
        $debug = FALSE;

        $a_numerator   = str_replace(' ','',$a_numerator);
        $a_denominator = str_replace(' ','',$a_denominator);
        $numerator     = str_replace(' ','',$numerator);
        $denominator   = str_replace(' ','',$denominator);

        $a_numerator   = trim_parenth($a_numerator);
        $a_denominator = trim_parenth($a_denominator);
        $numerator     = trim_parenth($numerator);
        $denominator   = trim_parenth($denominator);

        if ($debug)
        {
            echo "<h2> BEGIN DEBUG FOR CHECK ANSWER FUNCTION FOR NEW QUESTIONS</h2>";
            echo "CHECK ANSWER WAS PADDED";
            echo "<br> a_numerator: ".$a_numerator;
            echo "<br> a_denominoator: ".$a_denominator;
            echo "<br> numerator: ".$numerator;
            echo "<br> denominator: ".$denominator;
        }

        $num1 = strlen($a_numerator);
        $num2 = strlen($numerator);

        $denom1 = strlen($a_denominator);
        $denom2 = strlen($denominator);

        $num_correct = equiv_polynomials($a_numerator,$numerator);
        $denom_correct = equiv_polynomials($a_denominator,$denominator);

        if ($debug)
        {
            echo "<br> Numerators Equal: ".$num_correct;
            echo "<br> Denominator Equal: ".$denom_correct;
        }

        if ($num_correct && $denom_correct)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        echo "<br />passed check_answer a type that does not exist<br />\n";
        echo "Question type: $q_type\n";
        return FALSE;
    }
}

?>
