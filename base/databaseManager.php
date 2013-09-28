<?php

/*
	- DatabaseManager Class
	-	Author: Chris Green (cgreen9@kent.edu)
	
	- This class handles the database connection, state, and queries

*/

//Includes

//Class
class DatabaseManager
{
	// 
	// Members
	// 
	var $host;
	var $databaseName;
	var $userName;
	var $password;
	var $con;

	// 
	// Constructors and destructors
	// 
	function DatabaseManager()
	{
		//get connection information
		//$this->host="yang.lzu.edu.cn";
		$this->databaseName="mathpass";
		$this->userName="root";
		$this->password="890524";
		
		//connect
		$this->con=mysql_connect($this->host,$this->userName,$this->password);
		if(!$this->con) 
		{
			printf("Can't connect to $this->host. Errorcode: %s\n",mysql_error());
			exit;
		}
		$x=mysql_select_db($this->databaseName,$this->con);
		if(!$x)
		{
			printf("Can't connect to database $dbname. Errorcode: %s\n",mysql_error());
			exit;
		}	 
		mysql_query("set names 'GBK'");
	}
	function Dispose()
	{
		//close connection
		@ mysql_close($this->con);
	}

	// 
	// Methods
	// 
	function Query($sql)
	{
		return mysql_query($sql);
	}
}
?>
