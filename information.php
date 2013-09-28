<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Information","");
	$b->MainMenuIndex=14;
	

	$b->RenderTemplateTop();
?>

<h1>Information for MathPASS</h1>

<p>
MathPASS Instructions

The following tools and utilities are available to you for use here at MathPASS. Familiarizing yourself with these tools will help you get things done quicker and easier.
</p>
<ul>
<li><h2><a href="MATHPASS_Guide.pdf">User's Guide</a></h2> <p>This contains step by step instructions to accomplish virtually any task on Math Pass. <a href="MATHPASS_Guide.pdf">Click here</a> to view the user's guide.</p></li>
<li><h2><a href="Instructor_Guide.pdf">Instructor Guide</a></h2> <p>This contains instructions for instructor to use MathPASS. <a href="Instructor_Guide.pdf">Click here</a> to open the instructor guide.</p></li>
<li><h2><a href="syntax_chart.pdf">Syntax Chart</a></h2> <p>This contains syntax instructions for user to enter any mathematical expression. </p></li>
<li><h2><a href="systemrequirement.php">System requirement</a></h2> <p>To work with MathPASS, you should check and set up your browser as the directions.</p></li>
<li><h2><a href="MathPlayer.exe">Download MathPlayer 2.0b</a></h2> <p>If your broswer is Internet Explorer 8, you must install MathPlayer 2.0b or 
	      lower version of it. Other version of Internet Explorer can work well with the Mathpass using any version of MathPlayer.</p></li>
</ul>


<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>