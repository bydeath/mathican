<?
	include_once("base/baseForm.php");
	$b->AddCrumb("Logon","");
	$b->ActiveMenu=0;
	$b->MainMenuIndex=0;
	
	//$page="/mathpass/validate.php";
	$page="./validate.php";
	
	$b->RenderTemplateTop();
?>
<h2 align="center">Please Enter your Email and Password:</h2>
<br/>
<table width="40%" border="0" cellpadding="0" cellspacing="2" align="center">
	<tr>
		<td class="white" align="right">
		Email:</td>
		<td class="white" align="center">
		<input type="text" id="txt_user" name="txt_user" value="" size="28"/></td>
	</tr>
	<tr>
		<td class="white" align="right">
		Password:</td>
		<td class="white" align="center">
		<input type="password" id="txt_password" name="txt_password" value="" size="28"/></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" id="btn_submit" name="btn_submit" value="Submit" class="button1" /></td>
	</tr>
	
	<tr>
		<td colspan="2" align="center"><br/>
		<a href="register.php">Request Account</a> | <a href="forgotPassword.php">Forgot Password</a></td>
	</tr>
</table>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>