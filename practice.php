<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Practice","");
	$b->MainMenuIndex=10;

	global $con;
	$con=new DatabaseManager();
	
	//chapters
	$sql="SELECT pcourseId,name";
	$sql.=" FROM pcourse";
	$sql.=" order by name";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$courses.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Welcome to your practice page. You may use this page to practice material related to the classes you are enrolled in. Below you will find two columns. On the left you may create your own practice worksheet for whatever types of problems you would like. On the right you will be provided with some practice material sudgested by our program. These practice assignments are generated by analysing your grades on assignments you've submitted. If any weeknesses are diagnosed the program generates appropriate study material to help you stay on the ball.</p>

<p>
<table width="100%" border="0" cellpadding="5" cellspacing="0">
	<tr>
		<td colspan="2">
		<h2>Create Practice Worksheet</h2></td>
	</tr>
	<tr>
   <td width="200">
		Course: <select id="course" name="ddl_course" onchange="changecourse();">
		<?php
			echo($courses);
		?>
		</select>
	 </td>	
	 <td>
		Chapter: <span id="chapterop" name="chapterop"><select id="chapter" name="ddl_chapter" onchange="changechap();">
		</select></span>
	 </td>
	</tr>
</table>
			
<table width="100%">
	<tr>
		<td width="42%" valign="top">
			<table width="100%" cellpadding="0" cellspacing="0" class="addAs">
	   		<tr><td><h2 align="center">Available Problems:</h2></td>
  	    </tr>
  	    <tr>
  	    <td width="250px">
				<input type="checkbox" name="left" id="left" onClick="selectall(this.id);"></input>Select All
			  </td>
  		 </tr>
  	  </table>
    	<div id="apDiv" class="addAs1">
    	</div>
	  </td>
	  <td width="8%" align="center">
	    <button id="add" type="button" onclick="addp();" class="button1">&nbsp;&gt;&gt;&gt;&nbsp;</button><br/><br/>
	   	<button type="button" id="remove" onclick="removep();" class="button1">&nbsp;&lt;&lt;&lt;&nbsp;</button>
	  </td>
	  <td width="50%">
	   	<table width="100%" cellpadding="0" cellspacing="0" class="addAs">
	   		<tr><td colspan="3"><h2 align="center">Selected Problems:</h2></td>
  	    </tr>
  	    <tr>
  	    <td width="150px">
  			 <input type="checkbox" name="right" id="right" onClick="selectall(this.id);"></input>Select All
  		  </td>
  		  <td>
  		  </td>
  			<td align="right">
  				Numbers
  		  </td>
  		 </tr>
  	  </table>
	   	<div class="addAs2" id="spDiv">
	   		<table id="spTable" width="100%" cellpadding="0" cellspacing="0"></table>
    	</div>
    	<div id="sort" class="sort" align="center">
    		  <a href="javascript:goUp();" class="prob">Go Up</a>&nbsp;|
  		  	<a href="javascript:goDown();" class="prob">Go Down</a>&nbsp;|
  		  	<a href="javascript:sort();" class="prob">Sort</a><br/>
  		 </div>
	    </td>
	  </tr>
	 <tr>
		<td colspan="3" align="center">
		<input id="selectp" name="selectp" type="hidden" value="" />
		<input id="btn_submit" name="btn_submit" type="button" value="Take this practice" onClick="takepractice()" class="button1"/>&nbsp;<button onclick="document.location='practice.php'" class="button1">Cancel</button></td>
	</tr>
</table>
</p>
<script language="javascript" src="scripts/selectproblem.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>