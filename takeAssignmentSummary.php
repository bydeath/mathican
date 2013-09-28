<?
$cnums=$_GET["cnums"];
$nums=$_GET["nums"];
$atid=$_GET["atid"];
$aid=$_GET["aid"];
$cid="-1";
if($_GET["cid"])
 $cid=$_GET["cid"];
?>
<html>
<head>
	<title>- Math Pass 3.1-</title>
	<link rel="stylesheet" type="text/css" href="globals.css" />
	<style>
		BODY
		{
			padding:5px 0px 0px 0px;
			margin:0px 0px 0px 0px;
			background-color:#F5F8F9;
			text-align:center;
		}
	</style>
</head>
	
<body>
		<p>
		<table id="tbl_form" width="750" border="0" align="center" cellpadding="0" cellspacing="0" >
			<tr>
				<td>
				<table width="100%" border="0" cellpadding="0" cellspacing="0">
					<tr>
						<td>
						<img src="pics/logo.png" alt="Math Pass V3.1" /></td>
						<td class="ws1" width="200">
						<b></b></span></td>
					</tr>
				</table>
				</td>
			</tr>
			<tr>
				<td>
				<img src="pics/blank.gif" alt="" height="5" /></td>
			</tr>
			<tr>
				<td style="padding:5px 5px 5px 5px;border-style:solid;border-color:#b0b0b0;border-width:1px;background-color:white;">
				<table width="100%" border="0" cellpadding="0" cellspacing="2">
					<tr>
						<td colspan="2">
						<h3 class="h3"></h3></td>
					</tr>
					<tr>
						<? if($cnums=="-1"&&$cnums==-1) {?>
							<td colspan="2" id="td_assignmentNavigation">
								The assignment can be opened only once at the same time!
							</td>
						<?} else if($cnums=="-2"||$cnums==-2) {?>
							<td colspan="2" id="td_assignmentNavigation">
								You should login MathPASS firstly!
							</td>
						<? } else {?>
							<td colspan="2" id="td_assignmentNavigation">
								The Assignment has been submitted. Your score is <a href="javascript:openta(3,<?echo $aid.",".$cid.",".$atid;?>)"><? echo $cnums."/".$nums; ?></a>. Thank you.
							</td>
						<? }?>
					</tr>
					<tr>
						<td class="ws2">       
            </td>
						<td width="200" valign="top">
		        </td>
			</tr>
		</table>
		</p>
<script language="javascript" src="scripts/openta.js"></script>
</body>
</html>