<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	
	$b->AddCrumb("Your Students","teachersStudents.php");
	$b->AddCrumb("Add Student","");
	$b->ActiveMenu=5;
	
	$b->AddScript("scripts/ajax.js");
	
	$b->SecurePage("2");
	
	$b->AddSubMenuItem("Add Student","addStudent.php",TRUE);
	
	//
	// - Members
	//
	$con=new DatabaseManager();
	$srcpt='';
	$list='';
	$list2='';
	
	//
	// - Lists
	//
	$sql="SELECT courseId,title,days";
	$sql.=" FROM courses";
	$sql.=" WHERE active=1 AND fk_user_teacher=" . $b->User->UserId;
	$ds=$con->Query($sql);
	$list.='<select id="ddl_course" name="ddl_course">';
	while($dr=mysql_fetch_row($ds))
	{
		$list.='<option value="' . $dr[0] . '">' . $dr[1] . ' (' . $dr[2] . ')</option>';
	}
	$list.='</select>';
	$list2=str_replace("ddl_course","ddl_courseExisting",$list);
	
	//
	// - Script
	//
	$srcpt.='var requestInt=0;';
	$srcpt.='';
	$srcpt.='function OnRequestComplete()';
	$srcpt.='{';
	$srcpt.='	switch(requestInt)';
	$srcpt.='	{';
	$srcpt.='		case 1 :';
	$srcpt.='			FinishNext();';
	$srcpt.='			break;';
	$srcpt.='	}';
	$srcpt.='}';
	$srcpt.='function Next()';
	$srcpt.='{';
	$srcpt.='	requestInt=1;';
	$srcpt.='	if(GetBrowserElement("txt_email").value==GetBrowserElement("txt_emailConfirm").value)';
	$srcpt.='	{';
	$srcpt.='		AjaxRequest("GET","ajax/userExists.php?email=" + GetBrowserElement("txt_email").value + "&poo=' . md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']) . '",true);';
	$srcpt.='	}';
	$srcpt.='	else';
	$srcpt.='	{';
	$srcpt.='		alert("You must enter the same email address in both email fields!");';
	$srcpt.='	}';
	$srcpt.='}';
	$srcpt.='function FinishNext()';
	$srcpt.='{';
	$srcpt.='	GetBrowserElement("tbl_intro").style.display="none";';
	$srcpt.='	GetBrowserElement("txt_exists").value=xmlHttp.responseText;';
	$srcpt.='	if(xmlHttp.responseText=="1")';
	$srcpt.='	{';
	$srcpt.='		GetBrowserElement("tbl_confirmAdd").style.display="";';
	$srcpt.='	}';
	$srcpt.='	else';
	$srcpt.='	{';
	$srcpt.='		GetBrowserElement("tbl_newStudent").style.display="";';
	$srcpt.='	}';
	$srcpt.='}';
	$srcpt.='function Submit()';
	$srcpt.='{';
	$srcpt.='	GetBrowserElement("btn_submit").click();';
	$srcpt.='}';
	$srcpt.='';
	$b->AddScriptMethods($srcpt);
	
	//
	// - Submit Form
	//
	if($_POST["btn_submit"] || $_POST["btn_submit2"])
	{
		//vars
		$usrId="";
		$email=$_POST["txt_email"];
		$courseId="";
		
		if($_POST["txt_exists"]=="0")
		{
			//create student account
			$pass=substr(md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']),0,7);
			$sql="INSERT INTO users";
			$sql.=" ( type,email,password,firstName,lastName )";
			$sql.=" VALUES ( 3,'" . $email . "','" . $pass . "','" . $_POST["txt_firstName"] . "','" . $_POST["txt_lastName"] . "' )";
			$con->Query($sql);
			
			//email user their password
			$headers="From:" . $from;
			$subject="Math Pass Account Creation";
			$body="A teacher by the name of " . $b->User->Name . " created a student account for you at Math Pass.";
			$body.=" Your user name is " . $email . " and your password is " . $pass . ". You may change your password and account information by logging on to our web site.";
			$body.=" To logon to your account go to http://www.math.kent.edu/mathpass/.";
			mail($email,$subject,$body,$headers);
			
			$courseId=$_POST["ddl_course"];
		}
		else
		{
			$courseId=$_POST["ddl_courseExisting"];
		}
		
		//retreive userId
		$sql="SELECT userId";
		$sql.=" FROM users";
		$sql.=" WHERE active=1 AND email='" . $email . "'";
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$usrId=$dr[0];
		}
		
		//save record
		$sql="INSERT INTO studentenrollment";
		$sql.=" ( fk_user,fk_course,active )";
		$sql.=" VALUES ( " . $usrId . "," . $courseId . ",1 )";
		$con->Query($sql);
		
		$b->Redirect("teachersStudents.php");
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<input type="hidden" id="txt_exists" name="txt_exists" value="0" />

<h1>New Student Form</h1>
<p>
<table width="100%" id="tbl_intro" border="0" cellpadding="1" cellspacing="0" style="">
	<tr>
		<td colspan="2">
		<h2>Email Address</h2>
		<p>Type the student's email address into the text boxes below.</p></td>
	</tr>
	<tr>
		<td class="white">
		Email:</td>
		<td>
		<input type="text" id="txt_email" name="txt_email" value="<? echo($email); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Confirm Email:</td>
		<td>
		<input type="text" id="txt_emailConfirm" name="txt_emailConfirm" value="<? echo($email); ?>" /></td>
	</tr>
	<tr>
		<td  align="center">
		&nbsp;</td>
		<td>
		<button class="button1" onclick="javascript:Next();">Next Step</button></td>
	</tr>
</table>
<table width="100%" id="tbl_confirmAdd" border="0" cellpadding="0" cellspacing="0" style="display:none;">
	<tr>
		<td>
		<h2>Student Account Found</h2>
		<p>A student with the email address you provided already has an account here at Math Pass. To add this student to your class, select the class from the drop down list below then click "Add Student".</p></td>
	</tr>
	<tr>
		<td class="white">
		Select Class:
		<? echo($list2); ?></td>
	</tr>
	<tr>
		<td align="center">
		<button class="button1" onclick="javascript:Submit();" id="btn_submit2" name="btn_submit2">Add Student</button>&nbsp;|&nbsp;<button onclick="document.location='teachersStudents.php'" class="button1">Cancel</button></td>
	</tr>
</table>
<table width="100%" id="tbl_newStudent" border="0" cellpadding="0" cellspacing="0" style="display:none;">
	<tr>
		<td colspan="2">
		<h2>User Information</h2>
		<p>No user was found with that information. Please fill out the student's information using the form below.</p></td>
	</tr>
	<tr>
		<td class="white">
		First Name:</td>
		<td>
		<input type="text" id="txt_firstName" name="txt_firstName" value="<? echo($firstName); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Last Name:</td>
		<td>
		<input type="text" id="txt_lastName" name="txt_lastName" value="<? echo($lastName); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Select Class:</td>
		<td>
		<? echo($list); ?></td>
	</tr>
	<tr>
		<td colspan="2">
		<img src="pics/blank.gif" alt="" height="5" /></td>
	</tr>
	<tr>
		<td colspan="2" align="center">
		<input type="submit" value="Add Student" id="btn_submit" name="btn_submit" class="button1" />&nbsp;&nbsp;<button onclick="document.location='teachersStudents.php'" class="button1">Cancel</button></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>