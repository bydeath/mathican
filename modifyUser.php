<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	$con=new DatabaseManager();
	$email="";
	$type="";
	$password="";
	$lastName="";
	$firstName="";
	$userid="";
  if(isset($_GET["id"]))
  {
  	$b->AddCrumb("Modify Users",""); 
    $userid=$_GET["id"];
  	$sql="SELECT type,email,password,lastName,firstName";
  	$sql.=" FROM users where userId=".$userid;
  	$ds=$con->Query($sql);
  	while($dr=mysql_fetch_row($ds))
	  {
		$email=$dr[1];
		$type=$dr[0];
		$password=$dr[2];
		$lastName=$dr[3];
		$firstName=$dr[4];
    }
    $submit="Update";
  }else
  {
  	$b->AddCrumb("Add Users","");
  	$submit="Create";
  }
	if($_POST["btn_submit"])
	{
		$email=$_POST["txt_email"];
		$type=(int)$_POST["utype"];
		$password=$_POST["txt_password"];
		$lastName=$_POST["txt_lastName"];
		$firstName=$_POST["txt_firstName"];
		$userid=$_POST["userid"];
		$sql="select userId from users where";
		$sql.=" email='".$email."'";
		$ds=$con->Query($sql);
		$e=0;
		while($dr=mysql_fetch_row($ds))
		{
				if($dr[0]!=$userid)
				{
				  $e=1;
					echo "<script language='javascript'>alert('The email address has been used, please change another one.');</script>";
		    }
		}
		if($_POST["btn_submit"]=="Create" && $e==0)
		{
  			$sql="INSERT INTO users";
  			$sql.="(type,email,password,firstName,lastName,active)";
  			$sql.=" VALUES ( " . (int)$_POST["utype"] . ",'" . $_POST["txt_email"] . "','" . $_POST["txt_password"] . "','" . $_POST["txt_firstName"] . "','" .  $_POST["txt_lastName"] . "',1)";
  			$con->Query($sql);
  			echo "<script language='javascript'>alert('You have successfully created a new user.');</script>";
		    $b->Redirect("adminUser.php");
		}else if($_POST["btn_submit"]=="Update"  && $e==0)
		{
			
			$sql="update users";
			$sql.=" set type=" . (int)$_POST["utype"] . ",email='" . $_POST["txt_email"] . "',password='" . $_POST["txt_password"] . "',firstName='" . $_POST["txt_firstName"] . "',lastName='" .  $_POST["txt_lastName"] . "',active=1";
			$sql.=" where userId=" . (int)$_POST["userid"];
			$con->Query($sql);
			echo "<script language='javascript'>alert('The user information have been updated successfully.');</script>";
		  $b->Redirect("adminUser.php");
		}
	}
	$b->RenderTemplateTop();	
?>

<p><table border="0" cellpadding="2" cellspacing="2" align="center">
	<tr>
		<td colspan="2">
		<h2>User Information</h2></td>
	</tr>
	<tr>
		<td>
		Last Name:</td>
		<td>
		<input type="text" id="txt_lastName" name="txt_lastName" size="30" value="<? echo($lastName); ?>" /></td>
	</tr>
	<tr>
		<td>
		First Name:</td>
		<td>
		<input type="text" size="30" id="txt_firstName" name="txt_firstName" value="<? echo($firstName); ?>" /></td>
	</tr>
	<tr>
		<td>
		Email:</td>
		<td class="white">
		<input type="text" size="30" id="txt_email" name="txt_email" size="30" value="<? echo($email); ?>" /></td>
	</tr>
	<tr>
		<td>
		Confirm Email:</td>
		<td class="white">
		<input type="text" id="txt_confirmEmail" name="txt_confirmEmail" size="30" value="<? echo($email); ?>" /></td>
	</tr>
	<tr>
		<td>
		Password:</td>
		<td>
		<input type="text" id="txt_password" name="txt_password" size="30" value="<? echo($password); ?>" /></td>
	</tr>
	<tr>
		<td>
		Confirm Password:</td>
		<td>
		<input type="text" id="txt_confirmPassword" name="txt_confirmPassword" value="<? echo($password); ?>" size="30" /></td>
	</tr>
	<tr>
		<td>
		User Type:</td>
		<td>
			<select id="utype" name="utype">
				<option value="2" <? if($type==2) echo "selected"; ?> >teacher</option>
				<option value="3" <? if($type==3) echo "selected"; ?> >student</option>
		 </select></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="hidden" id="userid" name="userid" value="<? echo($userid); ?>"/>
		<input type="submit" value="<? echo $submit; ?>" id="btn_submit" name="btn_submit" class="button1" onClick="return submitf(this.form)"/></td>
	</tr>
</table>

<script language="javascript">
function submitf(thisform)
{
	var email=document.getElementById("txt_email");
	var cemail=document.getElementById("txt_confirmEmail");
	var pass=document.getElementById("txt_password");
	var cpass=document.getElementById("txt_confirmPassword");
	if(email.value==""){alert("Email address can't be empty");return false;}                                              
	if(cemail.value==""){alert("Confirm email address can't be empty"); return false;}
	if(pass.value==""){alert("Password can't be empty"); return false;}
	if(cpass.value==""){alert("Confirm password can't be empty");return false;}
	if(email.value!=cemail.value){alert("The email address you entered twice is not same.");return false;}
	if(pass.value!=cpass.value){alert("The password you entered twice is not same.");return false;}
	return ture;   
}
</script>
<?
	$con->Dispose();
	$b->RenderTemplateBottom();
	$b->Dispose();
?>