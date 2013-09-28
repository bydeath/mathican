<?php

/*
	- BaseForm Class
	-	Author: Chris Green (cgreen9@kent.edu)
	          Su Wei(wsu@cs.kent.edu)
	
	- This class provides all functionality used on every page of the site.
	-	Some of the things included in the class are:
	-		- Template Builders
	-		- Session Handlers
	-		- Page Permissions
	-		- Menu Generator
	-		- Database Handlers
*/

include_once("user.php");
include_once("databaseManager.php");
include_once("config.php");

class BaseForm
{
	// - Members
	var $m_sessionName;
	var $m_con;
	var $ActiveMenu=NULL;
	
	// - Constructor and destructor
	function BaseForm()
	{
		//session name
		$this->m_sessionName="mathPass3_1";
		
		//database connection
		$this->con=new DatabaseManager();
		
		//session handling
		$this->InitSession();
		
		//initialize global vars
		global $crumbs;
		global $pageTitle;
		global $scripts;
		global $onload;
		global $page;
		global $scriptCode;
		global $userType;
		global $subMenu;
		global $myStyles;
		$crumbs="";
		$this->AddCrumb("Math Pass","index.php");
		$pageTitle="";
		$scripts="";
		$scriptCode="";
		$subMenu="";
		$this->Errored=FALSE;
		$this->Config=new config();
		$this->IsForm=FALSE;
		$this->ShowAnimation=FALSE;
		$this->MainMenuIndex=0;
		
		//page file name
		$page=$_SERVER['REQUEST_URI'];
	}
	function Dispose()
	{
		if($this->m_con!=NULL)
		{
			$this->m_con->Dispose();
		}
	}
	
	// - Properties
	var $User;
	var $con;
	var $Onload;
	var $Errored;
	var $Config;
	var $IsForm;
	var $ShowAnimation;
	var $MainMenuIndex;
	
	// - Session Handling
	function InitSession()
	{
		session_name($this->m_sessionName);
		@session_start();
		
		if($_SESSION["activated"]==NULL || $_SESSION["activated"]=="")
		{
			//new session
			$_SESSION["activated"]=TRUE;
			$_SESSION["userId"]=0;
			$this->User=new User(0);
		}
		else
		{
			//old session
			$this->User=new User($_SESSION["userId"]);
		}
	}
	function Logon($user,$pass,$pastid)
	{
		$retval=FALSE;
		$sql="SELECT *";
		$sql.=" FROM users";
		$sql.=" WHERE ( email='" . $user . "' AND password='" . $pass . "' AND active=1 )";
		$ds=$this->con->Query($sql);
		$count=mysql_num_rows($ds);
		$i=0;
		if(strcmp($pastid,"")!=0)
		{
			$_SESSION["pastids"]=$pastid;
		}
		while($i< $count)
		{
			$_SESSION["userId"]=mysql_result($ds,$i,"userId");
			
			$this->User=new User($_SESSION["userId"]);
			
			$retval=TRUE;
			$i=$i+1;
		}
		return $retval;
	}
	function SecurePage($permissions="")
	{
		if($permissions!="" && $this->User->Type!=$permissions)
		{
			$this->Redirect("index.php");
		}
		else if($permissions=="" && $this->User->Type=="guest")
		{
			$this->Redirect("index.php");
		}
	}
	function Logoff()
	{
	}
	
	//
	// - Methods
	//
	function AddBodyProperty($property,$value)
	{
		global $bodyProperties;
		$bodyProperties.=' ' . $property . '="' . $value . '"';
	}
	function AddSubMenuItem($text,$link,$selected=FALSE)
	{
		global $subMenu;
		if($selected==FALSE)
		{
			$subMenu.='<td>';
			$subMenu.='<img src="pics/gradientwhiteyellow.gif" alt="" />';
			$subMenu.='</td>';
		}
		$subMenu.='<td' . ( $selected==FALSE ? ' style="cursor:pointer;" onclick="document.location=\'' . $link . '\'"' : ' style="cursor:default;"' ) . ' class="' . ( $selected==TRUE ? "subMenuOn" : "subMenuOff" ) . '">';
		$subMenu.=$text;
		$subMenu.='</td>';
	}
	function AddGenericScript($script)
	{
		global $scriptCode;
		$scriptCode.=$script;
	}
	function AddScriptMethods($script)
	{
		global $scriptMethod;
		$scriptMethod.=$script;
	}
	function AddScript($src)
	{
		global $scripts;
		$scripts.='<script language="javascript" src="' . $src . '"></script>';
	}
	function AddStyle($css)
	{
		global $myStyles;
		$myStyles.=$css;
	}
	function Redirect($link)
	{
		global $scriptCode;
		$scriptCode.='document.location="' . $link . '";';
	}
	function Alert($message,$errored=FALSE)
	{
		global $scriptCode;
		$scriptCode.='alert("' . $message . '");';
		if($errored==TRUE)
		{
			$this->Errored=TRUE;
		}
	}
	function RenderTemplateTop()
	{
		global $user;
		$user=$this->User;
		
		global $userType;
		$userType=$this->User->Type;
		
		global $onload;
		$onload=$this->Onload;
		
		include($this->Config->TemplateTop);
	}
	function RenderTemplateBottom()
	{
		include($this->Config->TemplateBottom);
	}
	function AddCrumb($text,$link)
	{
		global $crumbs;
		global $pageTitle;
		if($crumbs!='')
		{
			$crumbs.='&nbsp;&gt;&nbsp;';
		}
		if($link!="")
		{
			$crumbs.='<a href="' . $link . '" class="black">';
		}
		$crumbs.=$text;
		if($link!="")
		{
			$crumbs.='</a>';
		}
		else //set as page title
		{
			$pageTitle=$text;
		}
	}
	
	//
	// - Other methods
	//
	// Found GetUrl() online - dont remember where...
	function GetUrl()
	{
		$s = empty($_SERVER["HTTPS"]) ? '' : ($_SERVER["HTTPS"] == "on") ? "s" : "";
		$protocol = strleft(strtolower($_SERVER["SERVER_PROTOCOL"]), "/").$s;
		$port = ($_SERVER["SERVER_PORT"] == "80") ? "" : (":".$_SERVER["SERVER_PORT"]);
		return $protocol."://".$_SERVER['SERVER_NAME'].$port.$_SERVER['REQUEST_URI'];
	}
	function strleft($s1,$s2)
	{
		return substr($s1,0,strpos($s1,$s2));
	}
}

global $b;
$b=new BaseForm();

?>
