<?
		include_once("base/baseForm.php");
		session_start();
	  $b->ActiveMenu=0;
	  $b->MainMenuIndex=0;
	 
	  if($_POST["btn_submit"]||$_POST["btn_logon"])
	  {
			if($b->Logon($_POST["txt_user"],$_POST["txt_password"],"")==TRUE)
			{
					if(((int)$b->User->Type)==1)
					{
						$page="./logon.php";
						$b->Redirect("./index.php");
					}
					else if(((int)$b->User->Type)==2)
					{
						$page="./logon.php";
						$b->Redirect("./teachersHome.php");
					}
					else if(((int)$b->User->Type)==3)
					{
						$page="./logon.php";	
						$b->Redirect("./studentsHome.php");
					}
			}
			else
			{
					$b->Alert("The user name and password you entered are incorrect.");
					$b->Redirect("./logon.php");
			}
	  }
	
	$b->RenderTemplateTop();
	$b->RenderTemplateBottom();
	$b->Dispose();
?>