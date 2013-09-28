<?
    if(!isset($_SESSION)) 
    { 
        session_start(); 
    } 
  //session_start();
	include_once("layoverGenerator.php");
	
?>
<html>
	<head>
		<title><? global $pageTitle; echo($pageTitle); ?> - MathICAN 1.0</title>
		<link id="ss_static" rel="stylesheet" type="text/css" href="globals.css" />
		<link id="ss_dynamic" rel="stylesheet" type="text/css" href="dynamicFontSize.php?size=12" />
		<script type="text/javascript" src="scripts/globals.js"></script>
		<? global $scripts; echo($scripts); ?>
		<script language="javascript">
		function GenericCode()
		{
			window.name="mathPass";
			<?
				if($b->ActiveMenu!=NULL)
				{
					echo('MainMenuSelect(' . $b->ActiveMenu . ');');
				}
			?>
			<? global $scriptCode; echo($scriptCode); ?>
			MainMenuSelect(<? global $b; echo($b->MainMenuIndex); ?>);
		}
		<? global $scriptMethod; echo($scriptMethod); ?>
		</script>
		<style>
		<? global $myStyles; echo($myStyles); ?>
		</style>
	</head>
	<body onLoad="javascript:Initialize();<? echo($tOnload); ?>"<? global $bodyProperties;echo($bodyProperties); ?>>
	<form id="frm_body" name="frm_body" method="post" action="<? global $page; echo($page); ?>">
	<input type="hidden" id="txt_activeMenu" name="txt_activeMenu" value="" />
			<table class="t1" align="center">
				<tr>
					<td width="242px">
					<img src="pics/logo.png" alt="Math Pass Version 3.1" /></td>
					<td width="648px" align="right">
					<!-- BEGIN EMBED FLASH -->
					<?
					/*
					*/
						global $b;
						if($b->ShowAnimation==TRUE)
						{
							echo('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8,0,0,0" width="550" height="78" id=".swf" align="right" VIEWASTEXT>');
							echo('<param name="allowScriptAccess" value="sameDomain" />');
							echo('<param name="movie" value="flash/banner.swf" />');
							echo('<param name="quality" value="high" />');
							echo('<param name="salign" value="r" />');
							echo('<param name="bgcolor" value="#ffffff" />');
							echo('<embed src="flash/banner.swf" quality="high" salign="r" bgcolor="#ffffff" width="550" height="78" name=".swf" align="right" allowScriptAccess="sameDomain" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />');
							echo('</object>');
						}
						else
						{
							if(((int)$b->User->Type)==0)
							{
								echo('<img src="pics/flashstillguest.gif" alt="" />');
							}
							else if(((int)$b->User->Type)==1)
							{
								echo('<img src="pics/flashstilladmin.gif" alt="" />');
							}
							else if(((int)$b->User->Type)==2)
							{
								echo('<img src="pics/flashstillteach.gif" alt="" />');
							}
							else if(((int)$b->User->Type)==3)
							{
								echo('<img src="pics/flashstillstudent.gif" alt="" />');
							}
						}
					?><!-- END EMBED FLASH --></td>
				</tr>
			</table>
			<!-- BEGIN BODY AREA -->
			<table class="tbl_content" cellpadding="0" cellspacing="0" border="0">
				<tr>
					<td id="td_breadCrumbs" colspan="2">
					<? global $crumbs; echo($crumbs); ?>
					 </td>
				</tr>
				<tr>
					<td id="td_left">
					<table id="tbl_mainMenu" cellspacing="0" border="0" height="100%">
						<tr>
							<td id="td_menuItem_13" class="menuItemOff" onMouseOver="javascript:MainMenuOver(13);" onMouseOut="javascript:MainMenuOut(13);" onClick="javascript:MainMenuClick(13);">
							MathPASS Home</td>
						</tr>
						<? global $b; if((int)$b->User->Type==0)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_10" class="menuItemOff" onmouseover="javascript:MainMenuOver(10);" onmouseout="javascript:MainMenuOut(10);" onclick="javascript:MainMenuClick(10);">');
							echo('	Practice</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_0" class="menuItemOff" onmouseover="javascript:MainMenuOver(0);" onmouseout="javascript:MainMenuOut(0);" onclick="javascript:MainMenuClick(0);">');
							echo('	Log In</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_1" class="menuItemOff" onmouseover="javascript:MainMenuOver(1);" onmouseout="javascript:MainMenuOut(1);" onclick="javascript:MainMenuClick(1);">');
							echo('	Register</td>');
							echo('</tr>');
						}
						?>
						<? global $b; if((int)$b->User->Type==1)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_10" class="menuItemOff" onmouseover="javascript:MainMenuOver(10);" onmouseout="javascript:MainMenuOut(10);" onclick="javascript:MainMenuClick(10);">');
							echo('	Practice</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_18" class="menuItemOff" onmouseover="javascript:MainMenuOver(18);" onmouseout="javascript:MainMenuOut(18);" onclick="javascript:MainMenuClick(18);">');
							echo('	Users</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_21" class="menuItemOff" onmouseover="javascript:MainMenuOver(21);" onmouseout="javascript:MainMenuOut(21);" onclick="javascript:MainMenuClick(21);">');
							echo('	Problems</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_23" class="menuItemOff" onmouseover="javascript:MainMenuOver(23);" onmouseout="javascript:MainMenuOut(23);" onclick="javascript:MainMenuClick(23);">');
							echo('  Item Analysis</td>');
							echo('</tr>');
						}
						?>
						<? global $b; if((int)$b->User->Type==2)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_4" class="menuItemOff" onmouseover="javascript:MainMenuOver(4);" onmouseout="javascript:MainMenuOut(4);" onclick="javascript:MainMenuClick(4);">');
							echo('	Your Home</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_5" class="menuItemOff" onmouseover="javascript:MainMenuOver(5);" onmouseout="javascript:MainMenuOut(5);" onclick="javascript:MainMenuClick(5);">');
							echo('	Your Students</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_24" class="menuItemOff" onmouseover="javascript:MainMenuOver(24);" onmouseout="javascript:MainMenuOut(24);" onclick="javascript:MainMenuClick(24);">');
							echo('	Item Analysis</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_6" class="menuItemOff" onmouseover="javascript:MainMenuOver(6);" onmouseout="javascript:MainMenuOut(6);" onclick="javascript:MainMenuClick(6);">');
							echo('	Your Assignments</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_20" class="menuItemOff" onmouseover="javascript:MainMenuOver(20);" onmouseout="javascript:MainMenuOut(20);" onclick="javascript:MainMenuClick(20);">');
							echo('	Export Grade</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_7" class="menuItemOff" onmouseover="javascript:MainMenuOver(7);" onmouseout="javascript:MainMenuOut(7);" onclick="javascript:MainMenuClick(7);">');
							echo('	Your Classes</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_10" class="menuItemOff" onmouseover="javascript:MainMenuOver(10);" onmouseout="javascript:MainMenuOut(10);" onclick="javascript:MainMenuClick(10);">');
							echo('	Practice</td>');
							echo('</tr>');
						}
						?>
						<? global $b; if((int)$b->User->Type==3)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_8" class="menuItemOff" onmouseover="javascript:MainMenuOver(8);" onmouseout="javascript:MainMenuOut(8);" onclick="javascript:MainMenuClick(8);">');
							echo('	Your Home</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_9" class="menuItemOff" onmouseover="javascript:MainMenuOver(9);" onmouseout="javascript:MainMenuOut(9);" onclick="javascript:MainMenuClick(9);">');
							echo('	Your Assignments</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_15" class="menuItemOff" onmouseover="javascript:MainMenuOver(15);" onmouseout="javascript:MainMenuOut(15);" onclick="javascript:MainMenuClick(15);">');
							echo('	Your Grades</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_19" class="menuItemOff" onmouseover="javascript:MainMenuOver(19);" onmouseout="javascript:MainMenuOut(19);" onclick="javascript:MainMenuClick(19);">');
							echo('	Find a Class</td>');
							echo('</tr>');
							echo('<tr>');
							echo('	<td id="td_menuItem_10" class="menuItemOff" onmouseover="javascript:MainMenuOver(10);" onmouseout="javascript:MainMenuOut(10);" onclick="javascript:MainMenuClick(10);">');
							echo('	Practice</td>');
							echo('</tr>');
						}
						?>
						<? global $b; if((int)$b->User->Type!=0)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_3" class="menuItemOff" onmouseover="javascript:MainMenuOver(3);" onmouseout="javascript:MainMenuOut(3);" onclick="javascript:MainMenuClick(3);">');
							echo('	Account Settings</td>');
							echo('</tr>');
						}
						?>
						<? global $b; if((int)$b->User->Type!=0)
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_11" class="menuItemOff" onmouseover="javascript:MainMenuOver(11);" onmouseout="javascript:MainMenuOut(11);" onclick="javascript:MainMenuClick(11);">');
							echo('	Logoff</td>');
							echo('</tr>');
						}
						?>
						
						<tr>
							
							<td id="td_menuItem_14" class="menuItemOff" onMouseOver="javascript:MainMenuOver(14);" onMouseOut="javascript:MainMenuOut(14);" onClick="javascript:MainMenuClick(14);">
							Information</td>
						</tr>
						<tr>
							<td id="td_menuItem_12" class="menuItemOff" onMouseOver="javascript:MainMenuOver(12);" onMouseOut="javascript:MainMenuOut(12);" onClick="javascript:MainMenuClick(12);">
							Contact Us</td>
						</tr>
						<?  
						if($_SESSION["pastids"]!="")
						{
							echo('<tr>');
							echo('	<td id="td_menuItem_22" class="menuItemOff" onmouseover="javascript:MainMenuOver(22);" onmouseout="javascript:MainMenuOut(22);" onclick="javascript:MainMenuClick(22);">');
							echo('	<span style="color:red">&lt;&lt;Go Back</span></td>');
							echo('</tr>');
						}
						?>
					</table>
					</td>
					<td class="td_right">
					<table class="tbl_right" border="0" cellpadding="0" cellspacing="0">
						<tr>
							<td id="td_subMenu">
							<? global $subMenu; echo($subMenu=="" ? "" : '<table border="0" cellpadding="0" cellspacing="0"><tr>' . $subMenu .  ' </tr></table>'); ?></td>
						</tr>
						<tr>
							<td id="td_pageTitle">
							<? global $pageTitle; echo($pageTitle); ?></td>
						</tr>
						<tr>
							<td id="td_contentArea">
							
							
							
							
										
														
		

