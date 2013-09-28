<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Help","");
	
	$b->RenderTemplateTop();
?>

<h1>Template Page</h1>
<p>Text goes here...</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>