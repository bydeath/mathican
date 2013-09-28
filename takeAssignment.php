<?
	include_once("base/baseForm.php");
	$b->AddCrumb("Take Assignment","");
	$script='';
	$script.='function Launch(){window.open("takeAssignmentDo1.php?openmode=2&id=' . $_GET["id"] . '&cid=' . $_GET["cid"] . '&finish=' . $_GET["finish"] . '","assignment","location=no,menubar=no,toolbar=no,width=780,height=650,status=no,scrollbars=yes,resizable=yes");}';
	$b->AddScriptMethods($script);
	$b->AddGenericScript("Launch();");
	$b->RenderTemplateTop();
?>

<h2>Take Assignment</h2>
<p width="100%" align="center">
The assignment you selected should now open in a new window. If your assignment doesn't open <a href="javascript:Launch();">click here</a> to reload it.
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>