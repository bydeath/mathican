<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Forgot Password","");
	$b->ActiveMenu=2;
	$b->MainMenuIndex=0;
	
	if($_POST["btn_submit"])
	{
		$con=new DatabaseManager();
		$id=0;
		$address="";
		
		$sql="SELECT userId,email";
		$sql.=" FROM users";
		$sql.=" WHERE email='" . $_POST["txt_email"] . "'";
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$id=$dr[0];
			$address=$dr[1];
		}
		
		if($id==0)
		{
			$b->Alert("No account was found that matches the email address you provided. Please check your spelling and try again!");
		}
		else
		{
			$b->User->ResetPassword($address);
		}
		
		$con->Dispose();
	}
	
	$b->RenderTemplateTop();
?>

<h1>Forgot Password Form</h1>
<p>Enter your email address below and click the submit button. Your password will be reset with an automatically generated string of characters and numbers. Your new password will then be sent to you in an email.</p>
<p>Your Email Address:
&nbsp;<input type="text" id="txt_email" name="txt_email" maxlength="255" cols="75" value="<? echo($email); ?>" />
&nbsp;<input type="submit" class="button1" id="btn_submit" name="btn_submit" value="Retrieve Password" /></p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>