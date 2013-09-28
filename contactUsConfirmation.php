<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Contact Us Successful","");
	
	$b->RenderTemplateTop();
?>

<h1>Message Send Successfully</h1>
<p>Your message has been sent. Thank you for your feed back. If you require a response a member of our team will contact you via email as quickly as possible.</p>
<p align="center"><a href="index.php">Home Page</a>&nbsp;|&nbsp;<a href="contactUs.php">Contact Us</a></p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>