<?
  include_once("base/baseForm.php");	
  $pastid=$_GET["pastid"];
  $newid=$_GET["newid"];
  
  $con=new DatabaseManager();
  $sql="SELECT email,password";
	$sql.=" FROM users";
	$sql.=" WHERE userId='" . $newid."'" ;
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$email=$dr[0];
		$pword=$dr[1];
	}
	if($b->Logon($email,$pword,$pastid)==TRUE)
	{	 
			if(((int)$b->User->Type)==1)
			{
				$b->Redirect("index.php");
			}
			else if(((int)$b->User->Type)==2)
			{
				$b->Redirect("teachersHome.php");
			}
			else if(((int)$b->User->Type)==3)
			{
				$b->Redirect("studentsHome.php");
			}
	}
		$con->Dispose();
		$b->RenderTemplateTop();
		$b->RenderTemplateBottom();
	  $b->Dispose();
	?>