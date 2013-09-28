<?php

class DateSelector
{
	// - Members
	var $m_year=2007;
	var $m_month=1;
	var $m_day=1;
	
	// - Properties
	var $ID='';
	
	// - Constructor
	function DateSelector($id)
	{
		$this->ID=$id;
	}
	
	// - Set and retreive values
	function Get($field)
	{
		return $_POST[$this->ID . "_" . $field];
	}
	function Set($field,$value)
	{
		if($field=="year")
		{
			$this->m_year=$value;
		}
		else if($field=="month")
		{
			$this->m_month=$value;
		}
		else if($field=="day")
		{
			$this->m_day=$value;
		}
	}
	
	// - Render Control
	function Render()
	{
		$html='';
		
		//month
		$html.='<select id="' . $this->ID . '_month" name="' . $this->ID . '_month">';
		$i=0;
		while($i<12)
		{
			$extra='';
			if($i+1==$this->m_month)
			{
				$extra=' selected';
			}
			$html.='<option value="' . ($i+1) . '"' . $extra . '>' . ($i+1) . '</option>';
			$i=$i+1;
		}
		$html.='</select>';
		
		//separator
		$html.='&nbsp;/&nbsp;';
		
		//day
		$html.='<select id="' . $this->ID . '_month" name="' . $this->ID . '_day">';
		$i=0;
		while($i<31)
		{
			$extra='';
			if($i+1==$this->m_day)
			{
				$extra=' selected';
			}
			$html.='<option value="' . ($i+1) . '"' . $extra . '>' . ($i+1) . '</option>';
			$i=$i+1;
		}
		$html.='</select>';
		
		//separator
		$html.='&nbsp;/&nbsp;';
		
		//year
		$html.='<select id="' . $this->ID . '_month" name="' . $this->ID . '_year">';
		$i=2006;
		while($i<2015)
		{
			$extra='';
			if($i+1==$this->m_year)
			{
				$extra=' selected';
			}
			$html.='<option value="' . ($i+1) . '"' . $extra . '>' . ($i+1) . '</option>';
			$i=$i+1;
		}
		$html.='</select>';
		
		echo($html);
	}
}

?>