<?
	include_once("base/baseForm.php");
	$b->ActiveMenu=6;
	
	$b->AddCrumb("Shared Assignments","");
	$b->SecurePage("2");
	
	$b->AddSubMenuItem("Add Assignment","addAssignment.php");
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php",TRUE);
	
	//
	//
	//
	$con=new DatabaseManager();
	$list='';
	$filter='';
	$script='';
	$selectedFilter="";
	
	//
	//
	//
	$script='function Filter()';
	$script.='{';
	$script.='	var link="sharedAssignments.php";';
	$script.='	link+="?sort=' . $_GET["sort"] . '&filter=" + GetBrowserElement("ddl_filter").options[GetBrowserElement("ddl_filter").selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);

	
	//
	// populate filter drop down
	//
	$sql="SELECT assignments.fk_user_creator,users.lastName,users.firstName";
	$sql.=" FROM assignments";
	$sql.="  INNER JOIN users ON users.userId=assignments.fk_user_creator";
	$sql.=" WHERE ( assignments.shared=1 AND assignments.active=1 )";
	$sql.=" GROUP BY assignments.fk_user_creator";
	$sql.=" ORDER BY users.lastName,users.firstName";
	//echo($sql);
	$ds=$con->Query($sql);
	$i=0;
	while($dr=mysql_fetch_row($ds))
	{
		$filter.='<option value="' . $dr[0] . '">';
		$filter.=$dr[1] . ', ' . $dr[2];
		$filter.='</option>';
		$i++;
		if($dr[0]==$_GET["filter"])
		{
			$selectedFilter=$i;
		}
	}
	
	$script='';
	if($selectedFilter!="")
	{
		$script.='GetBrowserElement("ddl_filter").selectedIndex=' . $selectedFilter . ';';
	}
	$b->AddGenericScript($script);
	
	//
	// populate assignments list
	//
	$sql="SELECT assignments.assignmentId,assignments.title,_list_assignmenttypes.title,assignments.shared,users.lastName,users.firstName";
	$sql.=" FROM assignments";
	$sql.="  INNER JOIN users ON users.userId=assignments.fk_user_creator";
	$sql.="  INNER JOIN _list_assignmenttypes ON _list_assignmenttypes.assignmentTypeId=assignments.type";
	$sql.=" WHERE ( assignments.shared=1 AND assignments.active=1";
	if($_GET["filter"])
	{
		if($_GET["filter"]!="0")
		{
			$sql.=" AND assignments.fk_user_creator = " . $_GET["filter"];
		}
	}
	$sql.=" )";
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}
	//echo($sql);
	$ds=$con->Query($sql);
	//$ds=$b->con->Query($sql);
	
	
	$list.='<table width="100%" border="0" cellpadding="2" cellspacing="0">';
	$list.='	<tr>';
	$list.='		<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
	$list.='		&nbsp;</td>';
	$list.='		<td style="border-style:solid;border-width:1px;border-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="users.lastName" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Creator&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'sharedAssignments.php?sort=users.lastName&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Assignment Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'sharedAssignments.php?sort=assignments.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Type&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'sharedAssignments.php?sort=_list_assignmenttypes.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='	</tr>';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$added=TRUE;
		$aId=$dr[0];
		
		$list.='	<tr>';
		$list.='		<td style="background-color:#ffffff;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		<a href="importSharedAssignment.php?id=' . $dr[0] . '"><img src="pics/import.gif" alt="Import this assignment" border="0" /></a>&nbsp;<a href="takeAssignment.php?id=' . $dr[0] . '"><img src="pics/fillOut.gif" alt="Take this assignment" border="0" /></a></td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="users.lastName" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[4] . ', ' . $dr[5] . '</td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[1] . '&nbsp;</td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[2] . '</td>';
		$list.='	</tr>';
	}
	if($added==FALSE)
	{
		$list.='	<tr>';
		$list.='		<td colspan="6" style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		There are currently no shared assignments. To create a shared assignment go to the <a href="addAssignment.php">add assignment</a> page and select the "Shared Assignment" checkbox while filling out the form. You could also modify an existing assignment to be shared by going to <a href="teachersAssignments.php">your assignments</a> page.</td>';
		$list.='	</tr>';
	}
	$list.='</table>';
	$con->Dispose();
	
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Below you will find a list of all your fellow instructor's shared assignments. Assignments can be shared to help eliminate the need for instructors to duplicate one anothers work for similar classes. Every instructor can create a shared assignment by selecting the "Shared Assignment" checkbox on the <a href="addAssignment.php">Add Assignment</a> page or by modifying an existing assignment. To import someone elses assignment into your own curriculum simply click the import icon to the left of the assignment name in the list below. You will then be taken to an import page to specify exactly how you would like it to be included in your curriculum.</p>

<h1>Assignment List</h1>
<p style="width:100%;margin:5px 5px 5px 5px;padding:5px 5px 5px 5px;">
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td align="right">
		Currently Showing assignments from: <select name="ddl_filter" id="ddl_filter" onchange="javascript:Filter();"><option value="0">All Instructors</option><? echo($filter); ?></select></td>
	</tr>
	<tr>
		<td>
		<img src="pics/blank.gif" alt="" height="3" /></td>
	</tr>
	<tr>
		<td>
		<? echo($list); ?></td>
	</tr>
</table>
</p>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>