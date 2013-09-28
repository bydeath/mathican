<?

	session_start();
    session_unset();
    session_destroy();
    
    session_id(md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']));
    
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Logoff","");
	$b->MainMenuIndex=11;
	
	$b->RenderTemplateTop();
?>

<p>You are now logged off. If you would like to logon again you may return to the <a href="logon.php">logon page</a>. To go to the Home Page, <a href="index.php">click here</a>.</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>