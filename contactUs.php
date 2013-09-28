<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Contact Us","");
	$b->MainMenuIndex=12;
	
	//
	// - Members
	//
	$to=$b->Config->ContentEmail;
	$from=$_POST["txt_email"];;
	$subject=$_POST["ddl_subject"];
	$message=$_POST["txt_message"];
	$name=$_POST["txt_name"];
	
	//
	// - subject box
	//
	$subjectHtml='';
	$subjectHtml.='<option>General Inquiry</option>';
	$subjectHtml.='<option>Questions about using MathPass</option>';
	$subjectHtml.='<option>Report Errors or Broken Links</option>';
	
	//
	// - Submit Form
	//
	if($_POST["btn_submit"])
	{
		$headers="From:" .$name." <".$from.">\r\n";

		if(mail($to,$subject,$message,$headers))
		{
			$b->Redirect("contactUsConfirmation.php");
		}
		else
		{
			$b->Alert("An error occured while trying to send your email. Please make sure all the fields are filled in and try again!",TRUE);
		}
	}
	
	//
	// - Drop out
	//
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Use the form below to send us an email. If you require a response, a member of our team will get back to you as shortly as possible.</p>

<p>
<table width="500" border="0" cellpadding="0" cellspacing="5">
	<tr>
		<td class="white">
		Your Email Address:</td>
		<td class="white">
		<input id="txt_email" name="txt_email" type="text" value="<? echo($from); ?>" style="width:300;" /></td>
	</tr>
	<tr>
		<td class="white">
		Your Name:</td>
		<td class="white">
		<input id="txt_name" name="txt_name" type="text" value="<? echo($name); ?>" style="width:300;" /></td>
	</tr>
	<tr>
		<td class="white">
		Subject:</td>
		<td class="white">
		<select id="ddl_subject" name="ddl_subject"><? echo($subjectHtml); ?></select></td>
	</tr>
	<tr>
		<td class="white" valign="top">
		Message:</td>
		<td class="white">
		<textarea id="txt_message" name="txt_message" style="width:350;height:300;"><? echo($message); ?></textarea></td>
	</tr>
	<tr>
		<td colspan="2" class="white" align="center">
		<input type="submit" id="btn_submit" name="btn_submit" value="Send" class="button1" />&nbsp;<button onclick="document.location='index.php'" class="button1">Cancel</button></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>