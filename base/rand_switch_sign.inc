<?php 
    function rand_switch_sign(&$data, $odds = 2, $switch_odds = 1)
    {
	    if ($switch_odds == 1)
	    {
	        $randy = rand(1,$odds);
	        if ($randy == 1)
	            $data = $data * (-1);
        }
        else // $switch_odds != 1
        {
	        $randy = rand(1,$odds);
	        if ($randy != 1)
	            $data = $data * (-1);
        }
    }
?>