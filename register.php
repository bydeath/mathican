<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	$b->AddCrumb("Register for MathPASS","");
	$b->ActiveMenu=1;
	$b->MainMenuIndex=1;
	
	$con=new DatabaseManager();
	$code="";
	$email="";
	$password="";
	$lastname="";
	$firstname="";
	$htmlerror="";
	if(isset($_POST["btn_submit"]))
	{
		$usertype=$_POST["usertype"];
		$code=$_POST["accesscode"];
		$email=$_POST["email"];
	  $password=$_POST["password1"];
	  $lastname=$_POST["lastname"];
	  $firstname=$_POST["firstname"];
	  if (strpos($firstname,"'")!==false) 
		{
			$firstname=str_replace("'","\'",$firstname);
    }
    if (strpos($lastname,"'")!==false) 
		{
			$lastname=str_replace("'","\'",$lastname);
    }
    if (strpos($email,"'")!==false) 
		{
			$email=str_replace("'","\'",$email);
    }
    if (strpos($password,"'")!==false) 
		{
			$password=str_replace("'","\'",$password);
    }
		if(($usertype=="1" && $code=="kentmath")||($usertype=="2" && $code=="kentteacher")||($usertype=="3" && $code=="kentstudent"))
		{
		 $sql="select count(*) from users";
		 $sql.=" where email='".$email."'";
		 $ds=$con->Query($sql);
		 $dr=mysql_fetch_row($ds); 	
		 if($dr[0]>=1)
		 {	 	 
       $htmlerror="The email address has been registered. Please change another email address";
		 }else
		 {
		  $sql="insert into users";
		  $sql.="(type,email,password,firstName,lastName)";
		  $sql.=" values(".(int)$usertype.",'".$email."','".$password."','".$firstname."','".$lastname."')";
		  $con->Query($sql);
		  $htmlerror="Add user successfully!";
		  echo '<script type="text/javascript">alert("Add user successfully! You can login with your new account.");document.location="logon.php"</script>';
		 }
	  }else
	  {
	  	$htmlerror="Your access code is not right.";
	  }
	}
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<p align="center">Please fill the form below to create your account in MathPASS.(All the fields are required)</p>
<p><div style="color:#ff2211" align="center"><? echo $htmlerror; ?></div></p>
<p align="center">
	<table border="0" cellpadding="2" cellspacing="2" width="50%">
	<tr>
		<td class="white" >
		Email:</td>
		<td class="white">
		<input type="text" id="email" name="email" value="<? echo $email; ?>" size="30"/></td>
	</tr>
	<tr>
		<td class="white" >
		Confirm Email:</td>
		<td class="white">
		<input type="text" id="confirmemail" name="confirmemail" value="<? echo $email; ?>" size="30"/></td>
	</tr>
	<tr>
		<td class="white">
		Password:</td>
		<td class="white">
		<input type="password" id="password1" name="password1" value="" size="30"/></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Password:</td>
		<td class="white">
		<input type="password" id="confirmpassword" name="confirmpassword" value="" size="30"/></td>
	</tr>
	<tr>
		<td class="white">
		Last Name:</td>
		<td class="white">
		<input type="text" id="lastname" name="lastname" value="<? echo $lastname; ?>" size="30"/></td>
	</tr>
	<tr>
		<td class="white">
		First Name:</td>
		<td class="white">
		<input type="text" id="firstname" name="firstname" value="<? echo $firstname; ?>" size="30"/></td>
	</tr>
	<tr>
		<td class="white">
		User Type:</td>
		<td class="white">
		<select name="usertype">
		<option value="3">Student</option>
    <option value="2">Teacher</option>
    <option value="1">Administrator</option>
   </select></td>
	</tr>
	<tr>
		<td class="white">
		Access Code:</td>
		<td class="white">
		<input type="password" id="accesscode" name="accesscode" value="" size="30"/></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" value="Create" id="btn_submit" name="btn_submit" class="button1" onClick="precheck();return false;" /></td>
	</tr>
</table>
<script language="javascript">
	function precheck()
	{
		var email=document.getElementById("email");
		var confemail=document.getElementById("confirmemail");
		var password1=document.getElementById("password1");
		var confpassword=document.getElementById("confirmpassword");
		var code=document.getElementById("accesscode");
		if(email.value=="")
		{
			alert("You have not enter your email.");
			return false;
		}
		if(confemail.value=="")
		{
			alert("You have not enter the confirm email.");
			return false;
		}
		if(password1.value=="")
		{
			alert("You have not enter the password.");
			return false;
		}
		if(confpassword.value=="")
		{
			alert("You have not enter the confirm password.");
			return false;
		}
		if(code.value=="")
		{
			alert("You have not enter the access code.");
			return false;
		}
		if(email.value!=confemail.value)
		{
			alert("The email address and confirm email address are not same.");
	  	return false;
		}
	  if(password1.value!=confpassword.value)
	  {
	   alert("The password and confirm password are not same.");
	  	return false;
		}
		return ture; 
	}
</script>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>