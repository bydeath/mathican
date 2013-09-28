<?php

/*
	- User Class
	-	Author: Chris Green (cgreen9@kent.edu)
	
	- This class extends the object oriented model for user information and operations
*/

include_once("databaseManager.php");

class User
{
	function User($userId=0)
	{
		$this->UserId=$userId;
		if($userId!=0 && $userId!="0")
		{
			$this->UserId=$userId;
			$sql="SELECT email,password,type,firstName,lastName";
			$sql.=" FROM users";
			$sql.=" WHERE ( userId=" . $userId . " )";
			$con=new DatabaseManager();
			$ds=$con->Query($sql);
			while($dr=mysql_fetch_row($ds))
			{
				$this->UserName=$dr[0];
				$this->Email=$dr[0];
				$this->Password=$dr[1];
				$this->Type=$dr[2];
				$this->FirstName=$dr[3];
				$this->LastName=$dr[4];
				$this->Name=$dr[4] . ", " . $dr[3];
			}
			$con->Dispose();
		}
		else
		{
			$this->Type="0";
		}
	}
	
	//properties
	var $UserId;
	var $Type;
	var $UserName;
	var $Password;
	var	$Email;
	var $Name;
	var $FirstName;
	var $LastName;
	
	function ResetPassword($email)
	{
		$reset=FALSE;
		$sql="SELECT *";
		$sql.=" FROM users";
		$sql.=" WHERE email = '" . $email . "'";
		$con=new DatabaseManager();
		$ds=$con->Query($sql);
		$count=mysql_num_rows($ds);
		if($count>0)
		{
			$newPass=substr(md5(mktime() . rand() . $_SERVER['REMOTE_ADDR']),0,7);
			$sql="UPDATE users";
			$sql.=" SET password = '" . $newPass . "'";
			$sql.=" WHERE email = '" . $email . "'";
			$con->Query($sql);
			
			$to=$email;
			$subject="Math Pass Password Reset";
			$from=$b->Config->ContentEmail;
			$body="Due to your request for password retreival, your Math Pass password has been reset. Your new password is: " . $newPass . ". You may change your password by logging on to our web site and going to the \"Account Settings\" page.";
			mail($to,$subject,$body,"From: $from\nReply-To: $from\nContent-Type: text/html");
			
			$reset=TRUE;
		}
		$con->Dispose();
		return $reset;
	}
}

?>