<?	
	/*head information*/
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Your Classes","");
	$b->ActiveMenu=19;
	$b->MainMenuIndex=19;
	
	/*Security Check*/
	$b->SecurePage("3");
	
	/*Get the database connection*/
	$con=new DatabaseManager();
	$title="title";
	
	/*Introduction information*/
	$class.='<table>';	
	$class.='<tr><td>';
	$class.='<h1>Add To A Class</h1><p>Please find your class by class ID or teacher name. Enter the class password if need(consult your teacher about the password). Then click "Add To This Class" button to register into the class.</p>';
	$class.='</td></tr>';
	$class.='<tr><td>';
	$class.='<p>You can find your class by these two methods:</p>';
	$class.='</td></tr><br>';
	$class.='</table><br>';


  /*Method One*/
    /*Display the teacher name*/
		$sql="select distinct userId,firstName,lastName from courses,users where fk_user_teacher=userId and courses.active=1 order by lastName asc";
		$dsTname=$con->Query($sql);
		$class.='<br><h2><b>Method One</b></h2><br><br>';
		$class.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$class.='<tr>';
		$class.='	<td width="5%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;
							border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.=' <input type="radio" name="method" id="methodt"  value="t" checked onClick="enablemethod();"/>';
		$class.=' </td>';
		$class.='	<td align="center" width="15%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white				  ;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.=' Teacher:';
		$class.=' </td>';
		$class.='	<td align="left" width="30%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;
							border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.=' <select name="teachername" id="teachername" width="100" onchange="showCTitle(this.value,\'title\')">';
		$class.=' <option value="">Please Select</option>';		
		while($drTname=mysql_fetch_row($dsTname))
		{	
			$class.=' <option value ="'.$drTname[0].'">'.$drTname[2].'&nbsp;'.$drTname[1].'</option>'; 		
		}
		$class.=' </select>';
	  $class.=' </td>';
	  
	  
		$class.=' <td align="center" width="15%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.=' Class Title:';
		$class.=' </td>';
		$class.='	<td align="left" width="35%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.=' <select name="title" id="title" width="100" onchange="listCourseInfo(this.value);">';
		$class.=' <option value ="">Please Select</option>';
		$class.=' </select>';
		$class.=' </td>';
		$class.='</tr>';
		$class.='</table>';
		
	 /*Method Two*/
	 	$class.='<h2><br><b>Method Two</b></h2><br><br> <table width="700" border="0" cellpadding="2" cellspacing="0">';
		$class.='<tr>';
		$class.='	<td width="5%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.='<input type="radio" name="method" id="methodt"  value="o" onClick="enablemethod();"/>';
		$class.='</td>';
		$class.='	<td align="right" width="25%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.='Please Input Course ID:';
		$class.='</td>';
		$class.='	<td align="left" width="25%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.='<input type="text" bgcolor="white" name="courseid" id="courseid" disabled class="nofocusinput" value="" />&nbsp;';
		$class.='</td>';
		$class.='<td align="center" width="25%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.='<input type="button" name="search" id="search" disabled value="Search" onClick="listCourse(document.getElementById(\'courseid\').value);">';
		$class.='</td>';
		$class.='	<td width="20%" style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		$class.='&nbsp;';
		$class.='</td>';
		$class.='</tr>';
		$class.='</table></form><br><br>';
		
		
	 /*Course Information*/
		$class.='<h2><br><br><b>Course Information</b></h2> <br><br><table width="700" border="0" cellpadding="2" cellspacing="0">';
		$class.='<tr>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Class Id</td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Teacher</td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Class Title</td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Start Date</td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	End Date</td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Password</td>';
		$class.='<tr>';
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<div id="cid"></div>';
		$class.='	</td>';	
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<div id="tName"></div>';
		$class.='	</td>';	
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<div id="cTitle"></div>';
		$class.='	</td>';	
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<div id="sDate"></div>';
		$class.='	</td>';	
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<div id="eDate"></div>';
		$class.='	</td>';	
		$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">&nbsp;';
		$class.='<input type="password" style="display:none" id="pwd" class="nofocusinput" value="" name="pwd"/>';
		$class.='	</td>';	
		$class.='</tr>';
		$class.='</table><br><br>';
		$class.='<center><input type="button" name="btn_add" id="btn_add" value="Add To This Class" class="button" onClick="insertClass('.(int)($b->User->UserId);
		$class.=',document.getElementById(\'cid\').innerHTML,document.getElementById(\'pwd\').value);"></center>';

  
  /*You have been in these classes*/
	  $sqls="SELECT fk_course,active";
	  $sqls.=" FROM studentenrollment";
	  $sqls.=" where fk_user=".(int)($b->User->UserId);
	  $dss=$con->Query($sqls);
	  while($drs=mysql_fetch_row($dss))
	  {
		 $rclass[]=$drs[0];
	  }
		$class.='<p>';
		$class.='<br><br><b>You have been added to these classes.</b><br><br>';
		$class.='<table width="700" border="0" cellpadding="2" cellspacing="0">';
		$class.='<tr>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Class ID<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'findclass.php?sort=courseId\'" /></td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Teacher<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'findclass.php?sort=users.lastName\'" /></td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Class Title<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'findclass.php?sort=title\'" /></td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	Start Date<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'findclass.php?sort=startDate\'" /></td>';
		$class.='	<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;background-color:#cccccc;">';
		$class.='	End Date<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'findclass.php?sort=endDate\'" /></td>';
		$class.='</tr>';	
		$sql="SELECT distinct courseId,title,fk_user_teacher,startDate,endDate,room,users.firstName,users.lastName";
		$sql.=" FROM courses,users";
		$sql.=" where courses.fk_user_teacher=users.userId and courses.active=1";
		if($_GET["sort"]!=NULL && $_GET["sort"]!="")
		{
			$sql.=" ORDER BY " . $_GET["sort"];
			if($_GET["sort"]!="startDate")
			{
				$sql.=",startDate";
		  }		
		}
		else 
		{
			$sql.=" ORDER BY courseId asc";
		}	
		$ds=$con->Query($sql);
	
		while($dr=mysql_fetch_row($ds))
		{	
			$inclass=0;
			if(count($rclass)>=1)
			{
			 foreach($rclass as $rc)
			 {
			   if($rc==$dr[0])
			    $inclass=1;
		   }
		  }
			
		  if($inclass==1)
		  {
		  	$class.='<tr>';
		  	$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
		  	$class.='	'.$dr[0].'</td>';
				$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$class.='	' . $dr[7].' , '.$dr[6] . '&nbsp;</td>';
				$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$class.=$dr[1]. '&nbsp;</td>';
				$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$class.='	' . $dr[3]. '&nbsp;</td>';
				$class.='	<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;">';
				$class.='	' . $dr[4] . '&nbsp;</td>';
				$class.='</tr>';
		  }
			
		}
		
		$class.='</table><br>';
		$class.='</p>';
  
	$con->Dispose();
	$b->RenderTemplateTop();
?>




<p align="center">
	<? echo($class); ?>
</p>
<script language="javascript" src="scripts/findclass.js"></script>
<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>