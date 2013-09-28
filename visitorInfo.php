<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Info for Visitors","");
	$b->MainMenuIndex=16;
	
	$con=new DatabaseManager();
	
	$s='';
	$s.='function Generate()';
	$s.='{';
	$s.='	var type=GetBrowserElement("ddl_problem").options[GetBrowserElement("ddl_problem").selectedIndex].value;';
	$s.='	var link="takeAssignmentDo1.php?openmode=1&number=10&types=" + type;';
	$s.='	window.open(link,"assignment","toolbar=no,menubar=yes,width=800,height=550,status=no,scrollbars=yes");';
	$s.='}';
	$b->AddScriptMethods($s);
	
	$problems='';
	$sql="SELECT number,title";
	$sql.=" FROM problems";
	$sql.=" WHERE active=1";
	$sql.=" ORDER BY title";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$problems.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<div style="width:520px;">
<h1>What is MathPass?</h1>
<p>Math Pass is an online service that allows for teachers and students to participate in class curriculum over the world wide web. MathPass is created and maintained by faculty and students at <a href="http://www.kent.edu" target="_blank">Kent State University</a>.</p>
<!--
<h2>Information for Parents</h2>
<p>MathPass is used by the Kent State University College of Mathematics.</p>
-->
<h2>Information for Teachers</h2>
<p>MathPass provides a variety of features to help our teachers effectively manage their courses over the web. Logging on to the site will allow you to communicate with your class via email along with manage each of your class curriculums independently. You may also create assignments online and review students grades once assignments have been completed. If you would like to look at examples of our mathematics curriculum check the <i>Math Curriculum</i> section below.</p>
<h2>Information for Students</h2>
<p>Prospective students may check out examples of course curriculum in the <i>Math Curriculum</i> section below. If you are a new or existing student looking to enroll in a course, you may go to our <a href="register.php">enrollment page</a> to sign up for a class.</p>
<h1>Math Curriculum</h1>
<p>Select a problem type from the drop down box below. Click the <i>Generate Sample</i> button to generate the sample problems.</p>
<p align="center">Select Problem Type: <select id="ddl_problem" name="ddl_problem"><? echo($problems); ?></select><img src="images/blank.gif" alt="" height="1" width="100" /><button onclick="javascript:Generate();" class="button1">Generate Sample</button></p>
</div>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>