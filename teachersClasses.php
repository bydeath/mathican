<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Your Classes","");
	$b->ActiveMenu=7;
	$b->MainMenuIndex=7;
	
	$b->SecurePage("2");
	
	$b->AddSubMenuItem("Add Class","addClass.php");
	
	//
	// members
	//
	$con=new DatabaseManager();
	$list='';
	
	//
	// populate class list
	//
	$sql="SELECT courseId,title,room,days,startDate,endDate";
	$sql.=" FROM courses";
	$sql.=" WHERE ( fk_user_teacher=" . $b->User->UserId . " AND active=1 )";
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}
	//echo($sql . "<br />");
	$ds=$con->Query($sql);
	
	
	$list.='<table width="100%" border="0" cellpadding="2" cellspacing="0">';
	$list.='	<tr>';
	$list.='		<td class="tablehead">';
	$list.='		&nbsp;</td>';
/*****************/	
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="courseId" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Course Id&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersClasses.php?sort=courseId\';" /></td>';
/****************/
	
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Course Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersClasses.php?sort=title\';" /></td>';
	$list.='		<td style="border-style:solid;border-width:1px;border-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="days" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Time&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersClasses.php?sort=days\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="startDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Duration&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersClasses.php?sort=startDate\';" /></td>';
	$list.='	</tr>';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$list.='	<tr>';
		$list.='		<td style="background-color:#ffffff;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		<a href="modifyClass.php?id=' . $dr[0] . '"><img src="pics/modify.gif" alt="Modify this class" border="0" /></a>&nbsp;<a href="removeClass.php?id=' . $dr[0] . '"><img src="pics/trash.gif" alt="Remove this class" border="0" /></a></td>';
/***********************/
		$list.='		<td align="center" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="courseId" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[0] . '&nbsp;</td>';
/***********************/
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[1] . '&nbsp;</td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="days" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[3] . '&nbsp;</td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="startDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[4] . '&nbsp;<b>-</b>&nbsp;' . $dr[5] . '&nbsp;</td>';
		$list.='	</tr>';
		$added=TRUE;
	}
	if($added==FALSE)
	{
		$list.='	<tr>';
		$list.='		<td colspan="6" style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		You have no classes in your list. To create class <a href="addClass.php">click here</a>.</td>';
		$list.='	</tr>';
	}
	$list.='</table>';
	$con->Dispose();
	
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Below you will find a list of all your classes. To modify a class click on the <i>[modify]</i> link beside the class's name. To remove a class from your list, click on the trash can icon beside the class's name. If you wish to add a new list <a href="addClass.php">click here</a> or use the "New Class" link in the sub-menu above.</p>
<h1>Class List</h1>
<p>
<? echo($list); ?>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>