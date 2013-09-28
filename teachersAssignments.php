<?
	include_once("base/baseForm.php");
	$b->ActiveMenu=6;
	$b->MainMenuIndex=6;
	
	$b->AddCrumb("Your Assignments","");
	$b->SecurePage("2");
	
	$b->AddSubMenuItem("Add Assignment","addAssignment.php");
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php");
	
	//
	// members
	//
	$con=new DatabaseManager();
	$list='';
	$filter='';
	$script='';
	$selectedFilter="";
	
	//
	// filter script
	//
	$script='function Filter()';
	$script.='{';
	$script.='	var link="teachersAssignments.php";';
	$script.='	link+="?sort=' . $_GET["sort"] . '&filter=" + GetBrowserElement("ddl_filter").options[GetBrowserElement("ddl_filter").selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);

	
	//
	// populate filter drop down
	//
	$sql="SELECT courseId,title,days,room";
	$sql.=" FROM courses";
	$sql.=" WHERE ( fk_user_teacher=" . $b->User->UserId ." AND active=1 )";
	$sql.=" ORDER BY title";
	$ds=$con->Query($sql);
	$i=0;
	while($dr=mysql_fetch_row($ds))
	{
		$filter.='<option value="' . $dr[0] . '">';
		$filter.=$dr[1] . ' (' . $dr[2] . ' - ' . $dr[3] . ')';
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
		$script.='';
		$script.='';
		$script.='';
		$script.='';
		$script.='';
		$script.='';
	}
	$b->AddGenericScript($script);
	
	//
	// populate assignments list
	//
	$sql="SELECT assignmentId,assignments.title,_list_assignmenttypes.title,shared,startDate,dueDate";
	$sql.=" FROM assignments";
	$sql.="  INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
	$sql.=" WHERE ( fk_user_owner=" . $b->User->UserId . " AND assignments.active=1 )";
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}
	//echo($sql . "<br />");
	$ds=$con->Query($sql);
	//$ds=$b->con->Query($sql);
	
	
	$list.='<table width="100%" border="0" cellpadding="2" cellspacing="0">';
	$list.='	<tr>';
	$list.='		<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
	$list.='		&nbsp;</td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Assignment Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersAssignments.php?sort=assignments.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Type&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersAssignments.php?sort=_list_assignmenttypes.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="startDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Start Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersAssignments.php?sort=startDate&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="dueDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Due Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersAssignments.php?sort=dueDate&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-style:solid;border-width:1px;border-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="shared" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Shared&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersAssignments.php?sort=shared&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='	</tr>';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$aId=$dr[0];
		$doobie=FALSE;
		
		if($_GET["filter"])
		{
			if($_GET["filter"]=="0")
			{
				$doobie=TRUE;
			}
			else
			{
				$sql="SELECT *";
				$sql.=" FROM assignmentcourses";
				$sql.=" WHERE ( fk_assignment=" . $aId . " AND fk_course=" . $_GET["filter"] . " AND active=1 )";
				//echo($sql . "<br />");
				$sDs=$con->Query($sql);
				while($sDr=mysql_fetch_row($sDs))
				{
					$doobie=TRUE;
				}
			}
		}
		else
		{
			$doobie=TRUE;
		}
		
		//echo("doobie" . $aId . "=" . $doobie . "<br />");
		if($doobie==TRUE)
		{
			$added=TRUE;
			$list.='	<tr>';
			$list.='		<td style="background-color:#ffffff;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
			$list.='		<a href="addAssignment.php?id=' . $aId . '"><img src="pics/modify.gif" alt="Modify this assignment" border="0" /></a>&nbsp;<a href="removeAssignment.php?id=' . $dr[0] . '"><img src="pics/trash.gif" alt="Remove this assignment" border="0" /></a>&nbsp;<a href="takeAssignment.php?id=' . $dr[0] . '"><img src="pics/fillOut.gif" alt="Take this assignment" border="0" /></a>';
			$list.='		<a href="viewGrades.php?aid='.$aId.'&cid='.$_GET["filter"].'"><img src="pics/score1.png" alt="View Student Grades" title="View Student Grades" border="0"/></a></td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . $dr[1] . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . $dr[2] . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="startDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . substr($dr[4],0,10) . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="dueDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . substr($dr[5],0,10) . '</td>';
			$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="shared" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
			$list.='		' . ( $dr[3]=="1" ? "Yes" : "No" ) . '</td>';
			$list.='	</tr>';
		}
	}
	if($added==FALSE)
	{
		$list.='	<tr>';
		$list.='		<td colspan="6" style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		You have no assignments in your list. To create an assignment <a href="addAssignment.php">click here</a>.</td>';
		$list.='	</tr>';
	}
	$list.='</table>';
	$con->Dispose();
	
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Below you will find a list of all your assignments. If you would like to import a shared assignment from another teacher, click on the "Shared Assignments" item in the sub menu or <a href="sharedAssignments.php">click here</a>. To delete an assignment click on the trash can icon beside the assignment's name. If you would like to modify an assignment click the modify icon also located beside the assignment's name. If you would like to create a new assignment, you may do so by clicking on the "Add Assignment" item in the sub menu or by <a href="addAssignment.php">clicking here</a>.</p>

<h1>Assignment List</h1>
<p style="width:100%;margin:5px 5px 5px 5px;padding:5px 5px 5px 5px;">
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td align="right" class="white">
		Currently showing assignments for: <select name="ddl_filter" id="ddl_filter" onchange="javascript:Filter();"><option value="0">All Classes</option><? echo($filter); ?></select></td>
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