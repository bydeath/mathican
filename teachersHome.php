<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Your Home","");
	$b->ActiveMenu=4;
	$b->MainMenuIndex=4;
	
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
	$sql="SELECT users.userId,users.lastName,users.firstName,users.email";
	$sql.=" FROM users";
	$sql.="  INNER JOIN studentenrollment ON studentenrollment.fk_user=users.userId";
	$sql.="   INNER JOIN courses ON courses.courseId=studentenrollment.fk_course";
	$sql.=" WHERE ( studentenrollment.active=1 AND courses.fk_user_teacher=" . $b->User->UserId . " AND courses.active=1 AND users.active=1 )";
	$sql.=" ORDER BY users.lastName,users.firstName ASC";
	//echo($sql);
	$ds=$con->Query($sql);
	$students.='<table width="275" border="0" cellpadding="2" cellspacing="0" style="background-color:white;border-top-color:black;border-top-width:1px;border-top-style:solid;border-right-color:black;border-right-width:1px;border-right-style:solid;border-left-color:black;border-left-width:1px;border-left-style:solid;">';
	$added=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$added=TRUE;
		$students.='<tr>';
		$students.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
		$students.='	<a href="mailto:'.$dr[3].'"><img src="pics/email.gif" alt="Email this student" border="0" /></a>&nbsp;<a href="viewStudent.php?id=' . $dr[0] . '"><img src="pics/person.gif" alt="View Students Profile" border="0" /></a></td>';
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
		<p>The following tools and utilities are available to you for use here at MathPASS. Familiarizing yourself with these tools will help you get things done quicker and easier.</p>
		<ul>
			<li><b>Instructor Guide</b> - This contains step by step instructions to accomplish virtually any task on MathPASS. To view the instructor's guide <a href="Instructor_Guide.pdf">click here</a>.</li>
			
		</ul></td>
		<td valign="top">
		<h2>Your Classes</h2>
		<p><? echo($classes); ?></p>
		<h2 style="margin-top:10px;">Your Students</h2>
		<div class="yourstu"><? echo($students); ?></div></td>
	</tr>
</table>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>