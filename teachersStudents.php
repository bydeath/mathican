<?
	include_once("base/baseForm.php");
	$b->ActiveMenu=5;
	
	$b->AddCrumb("Your Students","");
	$b->MainMenuIndex=5;
	
	//$b->AddSubMenuItem("Add Student","addStudent.php");
	
	$b->SecurePage("2");
	
	//
	// members
	//
	$con=new DatabaseManager();
	$list='';
	$filter='';
	$selectedFilter="";
	
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
	if($selectedFilter!="")
	{
		$script='GetBrowserElement("ddl_filter").selectedIndex=' . $selectedFilter . ';';
		$b->AddGenericScript($script);
	}
	
	//
	// filter script
	//
	$script='function Filter()';
	$script.='{';
	$script.='	var link="teachersStudents.php";';
	$script.='	link+="?sort=' . $_GET["sort"] . '&filter=" + GetBrowserElement("ddl_filter").options[GetBrowserElement("ddl_filter").selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);
	
	//
	// populate student list
	//
	$sql="SELECT users.userId,users.lastName,users.firstName,users.email,courses.courseId";
	$sql.=" FROM users";
	$sql.="  INNER JOIN studentenrollment ON studentenrollment.fk_user=users.userId";
	$sql.="  INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	$sql.=" WHERE ( courses.fk_user_teacher=" . $b->User->UserId . " AND courses.active=1 AND studentenrollment.active=1 AND users.active=1";
	if($_GET["filter"]!=NULL && $_GET["filter"]!="" && $_GET["filter"]!="0")
	{
		$sql.=" AND studentenrollment.fk_course=" . $_GET["filter"];
	}
	$sql.=" )";
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}
	//echo($sql . "<br />");
	$ds=$con->Query($sql);
	
	
	$list.='<table width="500" border="0" cellpadding="2" cellspacing="0">';
	$list.='	<tr>';
	$list.='		<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
	$list.='		&nbsp;</td>';
	$list.='		<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="lastName,firstName" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Student\'s Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersStudents.php?sort=lastName,firstName&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='		<td style="border-style:solid;border-width:1px;border-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="email" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='		Email Address&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'teachersStudents.php?sort=email&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='	</tr>';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$list.='	<tr>';
		$list.='		<td style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		<a href="removeStudent.php?id=' . $dr[0] . '&cid=' . $dr[4] . '"><img src="pics/trash.gif" alt="Remove this student from your class" border="0" /></a>&nbsp;<a href="mailto:'.$dr[3].'"><img src="pics/email.gif" alt="Email this student" border="0" /></a>&nbsp;<a href="viewStudent.php?id=' . $dr[0] . '"><img src="pics/person.gif" title="View Students Profile" border="0" /></a>&nbsp;<a href="killsession.php?pastid='.$b->User->UserId.'&newid='.$dr[0].'"><img src="pics/beperson2.png" title="Login as this Student" border="0"/></a></td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[1] . ', ' . $dr[2] . '&nbsp;</td>';
		$list.='		<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="room" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		$list.='		' . $dr[3] . '&nbsp;</td>';
		$list.='	</tr>';
		$added=TRUE;
	}
	if($added==FALSE)
	{
		$list.='	<tr>';
		$list.='		<td colspan="6" style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='		You have no students in any of your classes. </td>';
		$list.='	</tr>';
	}
	$list.='</table>';
	$con->Dispose();
	
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Below you will find a list of all your students from every class. To narrow the results to only show students for a particular class. Use the drop down list above the student list to select a specific class. If you want to remove a student from your class, click the trash can icon beside the student's name.</p>

<h1>Student List</h1>
<p>
<table width="500" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td align="right" class="white">
		Currently showing students in: <select id="ddl_filter" name="ddl_filter" onchange="javascript:Filter();"><option value="0">All Classes</option><? echo($filter); ?></select></td>
	</tr>
	<tr>
		<td align="right">
		<img src="pics/blank.gif" alt="" height="5" /></td>
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