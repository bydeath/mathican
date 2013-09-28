<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	
	$b->AddCrumb("Your Account","");
	$b->MainMenuIndex=3;
	
	/*
	*/
	if($_POST["btn_submit"])
	{
		$con=new DatabaseManager();
		
		$extra="";
		//password
		if($_POST["txt_password"]!="")
		{
			if($_POST["txt_password"]!=$_POST["txt_confirmPassword"])
			{
				$b->Alert("The passwords you entered do no match!",TRUE);
			}
			else
			{
				$extra=",password='" . $_POST["txt_confirmPassword"] . "'";
			}
		}
		
		//email
		if($_POST["txt_email"]!=$_POST["txt_confirmEmail"])
		{
			$b->Alert("You must enter two matching email addresses in the email address fields!",TRUE);
		}
		
		if($b->Errored==FALSE)
		{
			$sql="UPDATE users";
			$sql.=" SET firstName='" . $_POST["txt_firstName"] . "',lastName='" . $_POST["txt_lastName"] . "',email='" . $_POST["txt_email"] . "'" . $extra;
			$sql.=" WHERE ( userId=" . $b->User->UserId . " )";
			
			$con->Query($sql);
			
			if($b->User->Type=="2")
			{
				$b->Redirect("teachersHome.php");
			}
			else if($b->User->Type=="3")
			{
				$b->Redirect("studentsHome.php");
			}
			$con->Dispose();
		}
	}
	
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Use the form below to change your account information.</p>
<p><table border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td colspan="2" class="white">
		<h2>User Information</h2></td>
	</tr>
	<tr>
		<td class="white">
		Last Name:</td>
		<td class="white">
		<input type="text" id="txt_lastName" name="txt_lastName" value="<? echo($b->User->LastName); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		First Name:</td>
		<td class="white">
		<input type="text" id="txt_firstName" name="txt_firstName" value="<? echo($b->User->FirstName); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Email:</td>
		<td class="white">
		<input type="text" id="txt_email" name="txt_email" value="<? echo($b->User->Email); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Email:</td>
		<td class="white">
		<input type="text" id="txt_confirmEmail" name="txt_confirmEmail" value="<? echo($b->User->Email); ?>" /></td>
	</tr>
	<tr>
		<td colspan="2">
		<h2>Account Information</h2></td>
	</tr>
	<tr>
		<td class="white">
		Password:</td>
		<td class="white">
		<input type="text" id="txt_password" name="txt_password" value="<? echo($b->User->Password); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Password:</td>
		<td class="white">
		<input type="text" id="txt_confirmPassword" name="txt_confirmPassword" value="<? echo($b->User->Password); ?>" /></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" value="Update" id="btn_submit" name="btn_submit" class="button1" /></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>