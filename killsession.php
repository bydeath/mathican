<? 
	session_start();
	$pastid=$_GET["pastid"];
  $newid=$_GET["newid"];
  
  session_unset();
  session_destroy();
    
  session_id(md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']));
    
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Kill Session","");
	
	$b->RenderTemplateTop();
?>
<script language="javascript">
	document.location="su.php?pastid=<? echo $pastid ?>&newid=<? echo $newid ?>";
</script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>