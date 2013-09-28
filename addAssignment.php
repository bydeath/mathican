<?php
	include_once("base/baseForm.php");
	include_once("base/dateSelector.php");
	$b->ActiveMenu=6;
	
	$b->AddCrumb("Your Assignments","teachersAssignments.php");
	$b->AddCrumb("Add Assignment","");
	$b->SecurePage("2");
	$b->AddScript("scripts/ajax.js");
	$b->AddGenericScript("InitAjax();");
	
	$b->AddSubMenuItem("Add Assignment","addAssignment.php",TRUE);
	$b->AddSubMenuItem("Shared Assignments","sharedAssignments.php");
	
	
	//members
	$s_title="";
	$s_type="";
	$s_takes="";
	$s_password="";
	$s_shared=0;
	$s_start="";
	$s_due="";
	$s_id="";
	$addpro="";
	$con=new DatabaseManager();
	if(isset($_GET["id"]))
	{
		$s_id=$_GET["id"];
		$sql="SELECT title,password,type,takes,shared,startDate,dueDate";
		$sql.=" FROM assignments";
		$sql.=" WHERE ( assignmentId=" . $_GET['id'] . " )";
		$ds=$con->Query($sql);
		while($dr=mysql_fetch_row($ds))
		{
			$s_title=$dr[0];
			$s_password=$dr[1];
			$s_type=$dr[2];
			$s_takes=$dr[3];
			$s_shared=$dr[4];
			$s_start=$dr[5];
			$s_due=$dr[6];
		}
		$sql3="SELECT fk_course";
	  $sql3.=" FROM assignmentcourses";
	  $sql3.=" WHERE ( fk_assignment=" . $_GET['id'] . " )";
	  $ds3=$con->Query($sql3);
	  $fk_course=array();
	  $ck=0;
	  while($dr3=mysql_fetch_row($ds3))
		{
			$fk_course[$ck]=$dr3[0];
			$ck++;
		}
		$sql4="SELECT sortnum,fk_problem,numbers,title";
	  $sql4.=" FROM assignmentquestions,problems";
	  $sql4.=" WHERE ( fk_assignment=" . $_GET['id'] . " and problems.number=assignmentquestions.fk_problem)";
	  $sql4.=" order by sortnum";
	  $ds4=$con->Query($sql4);
	  while($dr4=mysql_fetch_row($ds4))
		{
			$addpro.="addthis('P".$dr4[1].".".$dr4[3]."','".$dr4[1]."','".$dr4[2]."');";
		}
		$addpro.="sortp();";
	}
	$types='';
	$classes='';
	$chapters='';
	

	
	if($_POST["btn_submit"])
	{
		$s_title=$_POST["txt_title"];
	}
	
	//types
	$sql="SELECT assignmentTypeId,title";
	$sql.=" FROM _list_assignmenttypes";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		if($dr[0]==$s_type)
		{
		 $types.='<option value="' . $dr[0] . '" selected>' . $dr[1] . '</option>';
	  }else
	  {
	  	$types.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	  }
	}
	
	//classes
	$sql="SELECT courseId,title";
	$sql.=" FROM courses";
	$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
	$ds2=$con->Query($sql);
	
	
	while($dr=mysql_fetch_row($ds2))
	{
		if($classes!='')
		{
			$classes.='<br />';
		}	
		$checked=0;	
		for($k0=0;$k0<count($fk_course);$k0++)
		{ 
			if($dr[0]==$fk_course[$k0])
		   $checked=1;
	  }
	  if($checked==0)
	  {
	  	$classes.='<input type="checkbox" id="cb_class_' . $dr[0] . '" name="cb_class_' . $dr[0] . '" value="' . $dr[0] . '" />&nbsp;' . $dr[1];
	  }else
	  {
	  	$classes.='<input type="checkbox" id="cb_class_' . $dr[0] . '" name="cb_class_' . $dr[0] . '" value="' . $dr[0] . '" checked/>&nbsp;' . $dr[1];
	  }
	}
	
	//
	$sql="SELECT pcourseId,name";
	$sql.=" FROM pcourse";
	$sql.=" order by name";
	$ds=$con->Query($sql);
	while($dr=mysql_fetch_row($ds))
	{
		$courses.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	}
	
	$sql="SELECT chapterId,title";
	$sql.=" FROM chapters";
	$ds5=$con->Query($sql);
	while($dr=mysql_fetch_row($ds5))
	{
		$chapters.='<option value="' . $dr[0] . '">' . $dr[1] . '</option>';
	}
	
	
	//
	// - Process Submited Form
	//
	if($_POST["btn_submit"])
	{
		if($b->Errored==FALSE)
		{
			// - Create Assignment
			$dueDate=new DateSelector("ddl_dueDate");
			$startDate=new DateSelector("ddl_startDate");
			$pk=0;
			if($s_id!="")
			{
				$sql='update assignments set title="'.$_POST["txt_title"].'",type="'.$_POST["ddl_type"].'",shared='.( $_POST["cb_shared"]==TRUE ? "1" : "0" ).',password="'.$_POST["txt_password"].'",startDate="' . $startDate->Get("year") . '-' . $startDate->Get("month") . '-' . $startDate->Get("day") . '",dueDate="' . $dueDate->Get("year") . '-' . $dueDate->Get("month") . '-' . $dueDate->Get("day") . ' 23:59:59",takes='. $_POST["ddl_takes"] .' where assignmentId='.$s_id;
  			$pk=$s_id;
  			$con->Query($sql);
  			$sql="delete from assignmentquestions where fk_assignment=".$s_id."";
  			$con->Query($sql);
  			$sql="delete from assignmentcourses where fk_assignment=".$s_id."";
  			$con->Query($sql);
			}else
			{
			 $sql="INSERT INTO assignments";
			 $sql.=" ( title,fk_user_owner,fk_user_creator,type,shared,password,startDate,dueDate,takes )";
			 $sql.=" VALUES ( '" . $_POST["txt_title"] . "'," . $b->User->UserId . "," . $b->User->UserId . "," . $_POST["ddl_type"] . "," . ( $_POST["cb_shared"]==TRUE ? "1" : "0" ) . ",'" . $_POST["txt_password"] . "','" . $startDate->Get("year") . "-" . $startDate->Get("month") . "-" . $startDate->Get("day") . "','" . $dueDate->Get("year") . "-" . $dueDate->Get("month") . "-" . $dueDate->Get("day") . " 23:59:59'," . $_POST["ddl_takes"] . " )";
			// $b->Alert($sql);
			 $con->Query($sql);
			 $sql="SELECT assignmentId";
			 $sql.=" FROM assignments";
			 $sql.=" WHERE ( fk_user_owner=" . $b->User->UserId . " )";
			 $sql.=" ORDER BY assignmentId DESC";
			 $ds=$con->Query($sql);
			 while($dr=mysql_fetch_row($ds))
			 {
				$pk=(int)$dr[0];
				break;
			 }
		  }
		// - Retreive PK
			
	
			
			// - Save Class Assignments
			/*
			*/
			$sql="SELECT courseId";
			$sql.=" FROM courses";
			$sql.=" WHERE ( active=1 AND fk_user_teacher=" . $b->User->UserId . " )";
			$ds2=$con->Query($sql);
			while($dr=mysql_fetch_row($ds2))
			{
				if($_POST["cb_class_" . $dr[0]]==TRUE)
				{
					$sql="INSERT INTO assignmentcourses";
					$sql.=" ( fk_assignment,fk_course,active )";
					$sql.=" VALUES ( " . $pk . "," . $dr[0] . ",1 )";
					$con->Query($sql);
				}
			}
			$selectp=$_POST["selectp"];
			$prob=split(",",$selectp);
			$count=count($prob);
			$i=0;
			while($i< $count)
			{
				$pt=split(":",$prob[$i]);
				$problem=(int)$pt[0];
				$numbers=(int)$pt[1];
				$sql="INSERT INTO assignmentquestions";
				$sql.=" ( fk_assignment,sortnum,fk_problem,numbers )";
				$sql.=" VALUES ( " . $pk . "," . ($i+1) . "," . $problem . "," . $numbers . " )";
				$con->Query($sql);
				$i=$i+1;
			}
			$b->Redirect("teachersAssignments.php");
		}
	}
	
	$con->Dispose();
	$b->RenderTemplateTop();
?>

<h1>Instructions</h1>
<p>Use the form below to create your new assignment. Complete the <i>assignment information</i> - it is not neccesary to enter a password unless you would like to require your students to enter a password before taking the assignment. Next complete the <i>class assignments</i> and then begin the <i>problem set</i> information. After you've selected the <i>chapter</i>, <i>problem orientation</i>, and <i>number of problems</i> click the <i><b>set questions</b></i> button to set the properties for individual questions. Once you've completed the form click the <i><b>create assignment</b></i> button at the bottom of the page.</p>

<h1>Add Assignment Form</h1>
<p>
<table width="100%" border="0" cellpadding="2" cellspacing="0">
	<tr>
		<td colspan="2">
		<h2>Assignment Information</h2></td>
	</tr>
	<tr>
		<td width="130" class="white">
		Title:</td>
		<td width="500" class="white">
		<input type="text" id="txt_title" name="txt_title" value="<? echo($s_title); ?>" /></td>
	</tr>
	<tr>
		<td class="white">
		Type:</td>
		<td class="white">
		<select id="ddl_type" name="ddl_type">
		<? echo($types); ?>
		</select></td>
	</tr>
	<tr>
		<td class="white">
		Takes:</td>
		<td class="white">
		<select id="ddl_takes" name="ddl_takes">
		<?php
			$i=1;
			if((int)$s_takes==-1)
			{
				 echo('<option value="999" selected>unlimited</option>');
			}else
			{
				 echo('<option value="999">unlimited</option>');
			}			
			while($i<=15)
			{
				if((int)$s_takes==$i)
				{
				 echo('<option value="' . $i . '" selected>' . $i . '</option>');
				}else
				{
				 echo('<option value="' . $i . '">' . $i . '</option>');
				}			
				$i=$i+1;
			}
		?>
		</select></td>
	</tr>
	<tr>
		<td class="white">
		Shared:</td>
		<td class="white">
		<input type="checkbox" id="cb_shared" name="cb_shared" <? if((int)$s_shared==1) echo("checked"); ?>/>&nbsp;<a href="#" onclick="javascript:open('help/share.html','help','width=350,height=200,menubar=no')">What is this?</a></td>
	</tr>
	<tr>
		<td class="white">
		Password:</td>
		<td class="white">
		<input type="text" id="txt_password" name="txt_password" value="<? echo($s_password); ?>"/></td>
	</tr>
	<tr>
		<td colspan="2">
		<hr></td>
	</tr>
	<tr>
		<td colspan="2">
		<h2>Class Assignments</h2></td>
	</tr>
	<tr>
		<td  valign="top" class="white">
		Classes:</td>
		<td class="white">
		<? echo($classes); ?></td>
	</tr>
	<tr>
		<td class="white">
		Start Date:</td>
		<td class="white">
		<?
			$startDate=new DateSelector("ddl_startDate");
			if($s_start!=""){
				$date1=split("-",$s_start);
				$startDate->Set("year",(int)$date1[0]);
			  $startDate->Set("month",(int)$date1[1]);
			  $startDate->Set("day",(int)$date1[2]); 
			}else
			{
  			$today=getdate();
  			$startDate->Set("year",$today['year']);
  			$startDate->Set("month",$today['mon']);
  			$startDate->Set("day",$today['mday']);
		  }
			$startDate->Render();
		?></td>
	</tr>
	<tr>
		<td class="white">
		Due Date:</td>
		<td class="white">
		<?php
			$dueDate=new DateSelector("ddl_dueDate");
			if($s_due!=""){
				$date1=split("-",$s_due);
				$dueDate->Set("year",(int)$date1[0]);
			  $dueDate->Set("month",(int)$date1[1]);
			  $dueDate->Set("day",(int)$date1[2]); 
			}else
			{
  			$today=getdate();
  			$dueDate->Set("year",$today['year']);
  			$dueDate->Set("month",$today['mon']);
  			$dueDate->Set("day",$today['mday']);
			}
			$dueDate->Render();
		?></td>
	</tr>
	<tr>
		<td colspan="2">
		<hr></td>
	</tr>
	<tr>
		<td colspan="2">
		<h2>Problem Set</h2></td>
	</tr>
	<tr>
   <td class="white">
		Course: <select id="course" name="ddl_course" onchange="changecourse();">
		<?php
			echo($courses);
		?>
		</select>
	 </td>	
	 <td>
		Chapter: <span id="chapterop" name="chapterop"><select id="chapter" name="ddl_chapter" onchange="changechap();">
		</select>
			</span>
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
		<input id="btn_submit" name="btn_submit" type="submit" value="Save Assignment" onClick="return submitf(this.form)" class="button1"/>&nbsp;<button onclick="document.location='teachersAssignments.php'" class="button1">Cancel</button></td>
	</tr>
</table>
</p>
<script language="javascript" src="scripts/selectproblem.js"></script>
<script language="javascript">
  <? echo $addpro; ?>
</script>
<?php
	$b->RenderTemplateBottom();
	$b->Dispose();
?>