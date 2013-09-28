<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Users","");
	$b->ActiveMenu=18;
	$b->MainMenuIndex=18;
	$b->AddSubMenuItem("Add User","modifyUser.php");
	$selectedFilter=$_GET["filter"];
	if($selectedFilter!="")
	{
		$script='GetBrowserElement("ddl_filter").selectedIndex=' . $selectedFilter . ';';
		$b->AddGenericScript($script);
	}
	$script='function Filter()';
	$script.='{';
	$script.='	var link="adminUser.php";';
	$script.='	link+="?sort=' . $_GET["sort"] . '&filter=" + GetBrowserElement("ddl_filter").options[GetBrowserElement("ddl_filter").selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);
	
	$con=new DatabaseManager();
	$sql="SELECT userId,type,email,password,lastName,firstName";
	$sql.=" FROM users";
	if($_GET["filter"]!=NULL && $_GET["filter"]!="" && $_GET["filter"]!="0")
	{
		$sql.=" where type=" . $_GET["filter"];
	}
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}else
	{
	 $sql.=" order by type,userId";
  }
	$ds=$con->Query($sql);
	$h="";
	$h.="<table border='0' cellspacing='0' cellpadding='0'><tr><td class='tablehead' width='80'>&nbsp;</td>";
	$h.="<td style='border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;" . ( $_GET["sort"]=="userId" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . "'>";
	$h.="User ID<img src='pics/downArrow.gif' alt='Sort by field' style='cursor:pointer;' onclick='javascript:document.location=\"adminUser.php?sort=userId&filter=" . $_GET["filter"]."\";' /></td>";
	$h.="<td class='tablehead' width='100'>Type</td>";
	$h.="<td style='width:200;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;" . ( $_GET["sort"]=="email" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . "'>";
	$h.="Email <img src='pics/downArrow.gif' alt='Sort by field' style='cursor:pointer;' onclick='javascript:document.location=\"adminUser.php?sort=email&filter=" . $_GET["filter"]."\";' /></td>";
	$h.="<td style='width:120;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;" . ( $_GET["sort"]=="lastName" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . "'>";
	$h.="Last Name<img src='pics/downArrow.gif' alt='Sort by field' style='cursor:pointer;' onclick='javascript:document.location=\"adminUser.php?sort=lastName&filter=" . $_GET["filter"]."\";' /></td>";
	$h.="<td style='width:120;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;" . ( $_GET["sort"]=="firstName" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . "'>";
	$h.="First Name<img src='pics/downArrow.gif' alt='Sort by field' style='cursor:pointer;' onclick='javascript:document.location=\"adminUser.php?sort=firstName&filter=" . $_GET["filter"]."\";' /></td>";
	$h.="</tr>";
	while($dr=mysql_fetch_row($ds))
	{
		if($dr[1]==1)
		$h1="administrator";
		else if($dr[1]==2)
		 $h1="teacher";
		else if($dr[1]==3)
		 $h1="student";	
		$h.="<tr id='user".$dr[0]."'><td class='tablecontent' align='center'>";
		$h.="<a href='modifyUser.php?id=" . $dr[0] . "'><img src='pics/modify.gif' alt='Modify this user' border='0' /></a>&nbsp;&nbsp;&nbsp;<a href='#' onClick='javascript:removeuser(" . $dr[0] . ");'><img src='pics/trash.gif' alt='Remove this user' border='0' /></a></td>";
		$h.="<td class='tablecontent' align='center'>".$dr[0]."</td>";
		$h.="<td class='tablecontent' align='center'>".$h1."</td>";
		$h.="<td class='tablecontent'>".$dr[2]."</td>";
		$h.="<td class='tablecontent'>&nbsp;".$dr[4]."</td>";
		$h.="<td class='tablecontent'>&nbsp;".$dr[5]."</td>";
		$h.="</tr>";
	}
	$h.="</table>";
	$b->RenderTemplateTop();
	
?>

<p>
Currently showing users of type: <select id="ddl_filter" name="ddl_filter" onchange="javascript:Filter();"><option value="0">All</option><option value="1">Administrator</option><option value="2">Teacher</option><option value="3">Students</option></select>
<? echo $h;?>
</p>
<script language="javascript">
function removeuser(userid)
{
	if(confirm("Are you sure to delete the user ("+userid+")?")==true)
	{
	var params="userid="+userid;
	send_request("removeuser.php",params,processrequest);
  }
}

function send_request(url,params,pr)
{ 
 	http_request=false;
 	if(window.XMLHttpRequest)
 	{ http_request=new XMLHttpRequest();
 	  if(http_request.overrideMimeType)
 	  { 
 	  	http_request.overrideMimeType("text/xml");
 	  }
 	}else if(window.ActiveXObject){
 	  try{
 	    http_request=new ActiveXObject("Msxml2.XMLHttp");
 	  }catch(e){
 	   try{
 	     http_request=new ActiveXobject("Microsoft.XMLHttp");
 	   }catch(e){}
 	  }
 	}
 
 	if(!http_request){
 	 window.alert("Fail to create XMLHttp Object.");
 	 return false; 
 	} 
 	http_request.onreadystatechange=pr;  
 	http_request.open("POST",url,true);
 	http_request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;");
 	http_request.send(params);
}
function processrequest()
{
   if(http_request.readyState==4){
 	 if(http_request.status==200){
 	   if(http_request.responseText=="no")alert("Can't delete the user from the database.");
 	   else
 	   {
 	   	
 	   	 var tr1=document.getElementById("user"+http_request.responseText);
 	   	 var tr1p=tr1.parentNode;
 	   	 tr1p.removeChild(tr1);
 	   	 alert("You have deleted the user successfully!");  
 	   }
 	 }else {
 	 alert("The page you requested is abnormal.");  
 	 }
   } //end if       
} //
</script>
<?
	$con->Dispose();
	$b->RenderTemplateBottom();
	$b->Dispose();
?>