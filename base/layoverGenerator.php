<?

/*
	- LayoverGenerator Class
	-	Author: Chris Green (cgreen9@kent.edu) and Su Wei (wsu@math.kent.edu)
	
	- This class is used to generate the layover effect used by the site
	-	map and in other areas of the site.
*/

class LayoverGenerator
{
	//
	// - Members
	//
	
	//
	// - Constructor and destructor
	//
	function LayoverGenerator($id)
	{
		$this->ID=$id;
		$this->BackgroundColor="white";
		$this->ShowCloseLink=TRUE;
	}
	function Dispose()
	{
	}
	
	//
	// - Properties
	//
	var $ID;
	var $BackgroundColor;
	var $InnerHtml;
	var $Width;
	var $Height;
	var $ShowCloseLink;
	
	//
	// - Methods
	//
	function Render()
	{
		$retval='';
		$retval.='<div id="' . $this->ID . '_div1" style="display:none;background-image:url(images/fade.png);position:absolute;left:0;right:0;top:0;bottom:0;width:100%;height:100%;z-index:500;text-align:center;"></div>';
		$retval.='<div id="' . $this->ID . '_div2" style="display:none;position:absolute;z-index:501;position:absolute;top:30%;left:0;right:0;bottom:0;text-align:center;vertical-align:top;width:100%;">';
		$retval.='<table style="border-style:solid;border-color:#333366;border-width:2px;background-color:' . $this->BackgroundColor . ';margin:auto;" border="0" cellpadding="0" cellspacing="0">';
		$retval.='	<tr>';
		$retval.='		<td height="' . $this->Height . '" width="' . $this->Width . '" style="height:' . $this->Height . ';width:' . $this->Width . ';">';
		$retval.='		' . $this->InnerHtml . '</td>';
		$retval.='	</tr>';
		if($this->ShowCloseLink==TRUE)
		{
			$retval.='	<tr>';
			$retval.='		<td class="text">';
			$retval.='		<p align="center"><a href="javascript:HideLayover(\'' . $this->ID . '\');" class="black">Close</a></p></td>';
			$retval.='	</tr>';
		}
		$retval.='</table>';
		$retval.='</div>';
		echo($retval);
	}
}

?>