<?php
class config
{
	//
	// - Define Configuration Keys
	//
	var $ContentEmail;
	var $TechnicalEmail;
	var $TemplateTop;
	var $TemplateBottom;
	
	//
	// - Set Configuration Values
	//
	function config()
	{
		//$this->ContentEmail="breed1@kent.edu";
		//$this->TechnicalEmail="cgreen9@kent.edu,dzeller@cs.kent.edu";
		//$this->ContentEmail="wsu@cs.kent.edu";
		//$this->TechnicalEmail="wsu@cs.kent.edu";
		$this->ContentEmail="ouyhsh06@gmail.com";
		$this->TechnicalEmail="ouyhsh06@gmail.com";
		$this->TemplateTop="tmplt_top.php";
		$this->TemplateBottom="tmplt_bottom.php";
	}
}
?>