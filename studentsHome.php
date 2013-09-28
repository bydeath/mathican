<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	$b->ActiveMenu=8;
	
	$b->AddCrumb("Your Home","");
	$b->MainMenuIndex=8;
	
	$b->SecurePage(3);
	
	//
	// - Members
	//
	$con=new DatabaseManager();
	$students='';
	
	//
	// - Generate report
	//
	
	//classes & class info
	$sql="SELECT courses.courseId,courses.title,users2.lastName,users2.firstName";
	$sql.=" FROM studentenrollment";
	$sql.="  INNER JOIN courses ON courses.courseId = studentenrollment.fk_course";
	$sql.="   INNER JOIN users AS users2 ON users2.userId = courses.fk_user_teacher";
	$sql.=" WHERE ( studentenrollment.active=1 AND courses.active=1 AND studentenrollment.fk_user=" . $b->User->UserId . " )";
	//echo($sql . '<br />');
	$ds=$con->Query($sql);
	$cAdded=FALSE;
	while($dr=mysql_fetch_row($ds))
	{
		$cAdded=TRUE;
		//query database for students
		$sSql="SELECT users.userId,users.lastName,users.firstName,users.email";
		$sSql.=" FROM users";
		$sSql.="  INNER JOIN studentenrollment ON studentenrollment.fk_user=users.userId";
		$sSql.=" WHERE ( studentenrollment.fk_course=" . $dr[0] . " )";
		$sSql.=" order by users.lastName,users.firstName"; 
		$studs=$con->Query($sSql);
		
		//format html for students
		$students.='<h3' . ( $added==TRUE ? ' style="margin-top:10px;"' : '' ) . '>' . $dr[1] . ' - ' . $dr[2] . ', ' . $dr[3] . '</h3>';
		$students.='<table width="275" border="0" cellpadding="2" cellspacing="0" style="background-color:white;border-top-color:black;border-top-width:1px;border-top-style:solid;border-right-color:black;border-right-width:1px;border-right-style:solid;border-left-color:black;border-left-width:1px;border-left-style:solid;">';
		while($student=mysql_fetch_row($studs))
		{
			$students.='<tr>';
			$students.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
			$students.='	<a href="mailto:'.$student[3].'"><img src="pics/email.gif" alt="Email this student" border="0" /></a>&nbsp;</td>';
			$students.='	<td style="border-bottom-color:black;border-bottom-width:1px;border-bottom-style:dashed;">';
			$students.='	' . $student[1] . ', ' . $student[2] . '</td>';
			$students.='</tr>';
		}
		$students.='</table>';	
		}
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<table border="0" cellpadding="5" cellspacing="0">
	<tr>
		<td valign="top">
		<h1><? echo($b->User->FirstName); ?>'s Home Page</h1>
		<p>Welcome to your home page. This page will summarize all of your information to allow you to quickly get to what you're looking for.</p>
		<h2>Math Pass Instructions</h2>
		<p>The following tools and utilities are available to you for use here at Math Pass. Familiarizing yourself with these tools will help you get things done quicker and easier.</p>
		<ul>
			<li><b>User's Guide</b> - This contains step by step instructions to accomplish virtually any task on Math Pass. To view the user's guide <a href="MATHPASS_Guide.pdf">click here</a>.</li>
		</ul></td>
		<td valign="top">
		<h2>Your Classmates</h2>
		<div class="yourstu"><? echo($students); ?></div></td>
	</tr>
</table>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>