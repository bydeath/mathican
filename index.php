<?php
	include_once("base/baseForm.php");
	$b->AddCrumb("Home Page","");
	$b->ActiveMenu=13;
	$b->MainMenuIndex=13;
	$b->ShowAnimation=TRUE;
	
	//$page="/mathican/validate.php";
	$page="./validate.php";
	
	$b->RenderTemplateTop();
?>

<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td width="50%" valign="top" style="padding:0px 10px 0px 0px;">
		<h1>Welcome to MathICAN!</h1>
		<p>MathICAN is an interactive approach to learning mathematical skills.  It allows the instructor to manage assignments and classes easily.  MathICAN provides an opportunity to practice algebraic skills.  The student is able to work at his own pace through material that has been customized for his needs. </p>
		<p>We hope you enjoy the newer, cleaner, more user friendly version of MathICAN.</p>
		<p>To work with MathICAN, you should check and set up your browser as the  <a href="systemrequirement.php">directions</a>.</p>
		</td>
		<td width="50%" valign="top" align="center" style="padding:5px 5px 5px 5px;">
		<?php global $b; if($b->User->Type=="0")
		{
		echo('<table border="0" cellpadding="0" cellspacing="0" style="border-style:solid;border-color:black;border-width:1px;">');
		echo('	<tr>');
		echo('		<td width="7" style="font-size:1;background-color:#e5e8e9;">');
		echo('		&nbsp;</td>');
		echo('		<td width="275" align="center" style="background-color:#e5e8e9;padding:5px 5px 5px 5px;">');
		echo('		<table border="0" cellpadding="0" cellspacing="2">');
		echo('			<tr>');
		echo('				<td colspan="2" class="black">');
		echo('				<h2 class="black">Sign In</h2>');
		echo('				<p class="black">Use this form to logon to your account. If this is your first time visiting, and you would like to request access, <a href="register.php">click here</a>. If you have forgotten your password <a href="forgotPassword.php">click here</a>.</p></td>');
		echo('			</tr>');
		echo('			<tr>');
		echo('				<td class="black">');
		echo('				Email:</td>');
		echo('				<td class="black">');
		echo('				<input type="text" id="txt_user" name="txt_user" value="" /></td>');
		echo('			</tr>');
		echo('			<tr>');
		echo('				<td class="black">');
		echo('				Password:</td>');
		echo('				<td class="black">');
		echo('				<input type="password" id="txt_password" name="txt_password" value="" /></td>');
		echo('			</tr>');
		echo('			<tr>');
		echo('				<td colspan="2" align="center">');
		echo('				<input type="submit" id="btn_logon" name="btn_logon" value="Logon" class="button1" /></td>');
		echo('			</tr>');
		echo('			<tr>');
		echo('				<td colspan="2" align="center" class="black">');
		echo('				<a href="register.php" class="black">Request Account</a> | <a href="forgotPassword.php" class="black">Forgot Password</a></td>');
		echo('			</tr>');
		echo('		</table></td>');
		echo('		<td width="7" style="font-size:1;background-color:#e5e8e9;">');
		echo('		&nbsp;</td>');
		echo('	</tr>');
		echo('</table>');
		} ?>
		<?php global $b; if($b->User->Type!="0")
		{
		echo('<table border="0" cellpadding="0" cellspacing="0">');
		echo('	<tr>');
		echo('		<td width="7" style="font-size:1;background-color:#e5e8e9;">');
		echo('		&nbsp;</td>');
		echo('		<td width="275" align="center" style="background-color:#e5e8e9;">');
		echo('		<table border="0" cellpadding="0" cellspacing="2">');
		echo('			<tr>');
		echo('				<td colspan="2">');
		echo('				<h2>Logged on as ' . $b->User->FirstName . '</h2>');
		echo('				<p>Whenever you are ready to logoff. Simply <a href="logoff.php">click here</a> or use the "Logoff" item in the main menu at the top of the page.</p></td>');
		echo('			</tr>');
		echo('			<tr>');
		echo('				<td colspan="2">');
		echo('				<img src="pics/blank.gif" alt="" height="10" /></td>');
		echo('			</tr>');
		echo('		</table></td>');
		echo('		<td width="7" style="font-size:1;background-color:#e5e8e9;">');
		echo('		&nbsp;</td>');
		echo('	</tr>');
		echo('</table>');
		} ?></td>
	</tr>
</table>

<?php
	$b->RenderTemplateBottom();
	$b->Dispose();
?>