<?php

function question_retrieve($i)
{
    $question = array();
    for ($j = 0; $j < 6; $j++)
    {
        $qt = "txt_array_".$j."_".$i;
        $question[$j] = $_POST[$qt];
    }
    return $question;
}

?>
    
 



























