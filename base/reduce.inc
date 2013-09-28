<?php
// reduce fractions function
function reduce(&$numerator, &$denominator, $highest_possible = 12)
{
    $reduced = FALSE;
    $temp = 0;
    if ($numerator < 0)
    {
        $temp = 1;
        $numerator = $numerator * (-1);
    }
    for ($i =2; $i <= $highest_possible ; $i++)
    {
        if ( ($numerator >= $i) && ($denominator >= $i))
            while ((($numerator % $i) == 0) && (($denominator % $i) == 0))
            {
                $numerator = $numerator/$i;
                $denominator = $denominator/$i;
                $reduced = TRUE;
            }
    }
    if ( $temp == 1)
        $numerator = $numerator * (-1);
    return $reduced;
}
?>