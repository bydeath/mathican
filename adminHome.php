<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Your Home","");
	$b->ActiveMenu=16;
	$b->MainMenuIndex=16;
	
	$b->SecurePage("2");
	
	//
	// - Members
	//
	$con=new DatabaseManager();
	$students='';
	$classes='';
	
	//
	// - Generate report
	//
	
	//students
	$sql="SELECT users.userId,users.lastName,users.firstName";
	$sql.=" FROM users";
	$sql.="  INNER JOIN studentenrollment ON studentenrollment.fk_user=users.userId";
	$sql.="   INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	$sql.=" WHERE ( studentenrollment.active=1 AND courses.fk_user_teacher=" . $b->User->UserId . " AND courses.active=1 AND users.active=1 )";
	$sql.=" ORDER BY users.lastName ASC";
	//echo($sql);
	$ds=$con->Query($sql);
	$students.='<table width="275" border="0" cellpadding="2" cellspacing="0" style="background-color:white;border-top-color:black;border-top-width:1px;border-top-style:solid;border-right-color:black;border-right-width:1px;border-right-style:solid;border-left-color:black;border-left-width:1px;border-left-style:solid;">';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$added=TRUE;
		$students.='<tr>';
		$students.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$students.='	<img src="pics/email.gif" alt="Email this student" border="0" />&nbsp;<a href="viewStudent.php?id=' . $dr[0] . '"><img src="pics/person.gif" alt="View Students Profile" border="0" /></a></td>';
		$students.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$students.='	' . $dr[1] . ', ' . $dr[2] . '</td>';
		$students.='</tr>';
	}
	if($added==FALSE)
	{
		$students.='<tr>';
		$students.='	<td colspan="2" style="background-color:white;border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$students.='	You have no students in your list.</td>';
		$students.='</tr>';
	}
	$students.='</table>';
	
	//classes
	$sql="SELECT courseId,title";
	$sql.=" FROM courses";
	$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
	$ds=$con->Query($sql);
	$classes.='<table width="275" border="0" cellpadding="2" cellspacing="0" style="background-color:white;border-top-color:black;border-top-width:1px;border-top-style:solid;border-right-color:black;border-right-width:1px;border-right-style:solid;border-left-color:black;border-left-width:1px;border-left-style:solid;">';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$added=TRUE;
		$classes.='<tr>';
		$classes.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$classes.='	<a href="modifyClass.php?id=' . $dr[0] . '"><img src="pics/modify.gif" alt="Modify this class" border="0" /></a>&nbsp;<a href="removeClass.php?id=' . $dr[0] . '"><img src="pics/trash.gif" alt="Remove this class" border="0" /></a></td>';
		$classes.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$classes.='	' . $dr[1] . '</td>';
		$classes.='</tr>';
	}
	if($added==FALSE)
	{
		$classes.='<tr>';
		$classes.='	<td colspan="2" style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;background-color:white;">';
		$classes.='	You have no classes in your list.</td>';
		$classes.='</tr>';
	}
	$classes.='</table>';

	$con->Dispose();
	$b->RenderTemplateTop();
?>

<table border="0" cellpadding="5" cellspacing="0">
	<tr>
		<td valign="top">
		<h1><? echo($b->User->FirstName); ?>'s Home Page</h1>
		<p>Welcome to your home page. This page will summarize all of your information to allow you to quickly get to what you're looking for.</p>
		<h2>Math Pass Instructions</h2>
		<p>Familiarizing yourself with the following tools will help you use MathPass more efficiently.</p>
		<ul>
			<li><b>User's Guide</b> - This contains step by step instructions to occomplish virtually any task on Math Pass. To download the user's guide <a href="downloads/guide.doc">click here</a>.</li>
			<li><b>Site Map</b> - A link to the site map is located at the top right hand corner of your screen, directly beside the logon or logoff link. Use this as a quick refrence to find your way through the site.</li>
			<li><b>Print Page</b> - The print page feature, located on the right hand side of the screen below the main menu, provides a printer friendly version of the page you are viewing. After you click on the "Print" button it will show you a printer dialog which will allow you to customize the font size you would like for your printed page.</li>
			<li><b>Help</b> - Every page has a link to the help application located on the right hand side of the screen directly below the main menu. If you click on this the help application will open in a new window to allow you to continue using Math Pass and access help materials simultaniously.</li>
			<li><b>Report Error</b> - Every page also has a button to "Report Error on this Page" located on the right hand side of the screen directly below the main menu. This will take you to a form that will allow you to document the error that occured. Please take advantage of this feature as we appreciate any feedback we can get.</li>
		</ul></td>
		<td valign="top">
		<h2>Your Classes</h2>
		<p><? echo($classes); ?></p>
		<h2 style="margin-top:10px;">Your Students</h2>
		<p><? echo($students); ?></p></td>
	</tr>
</table>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>