<?
include_once("base/baseForm.php");	

$b->RenderTemplateTop();

if(isset($_SESSION["pastids"]))
{	
  	$pastid="";
  	$newid=$_SESSION["pastids"];
}

?>

<script language="javascript">
	document.location="killsession.php?pastid=<? echo $pastid ?>&newid=<? echo $newid ?>";
</script>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>