<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Export student grades","");
	$b->ActiveMenu=20;
	$b->MainMenuIndex=20;
	
	$con=new DatabaseManager();
	$list='';
	$filter='';
	$script='';
	$selectedFilter="";
	
	$script='function Filter()';
	$script.='{';
	$script.='	var link="exportgrade.php";';
	$script.='	link+="?filter=" + GetBrowserElement("ddl_filter").options[GetBrowserElement("ddl_filter").selectedIndex].value;';
	$script.='	document.location=link;';
	$script.='}';
	$b->AddScriptMethods($script);

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
	}
	$b->AddGenericScript($script);
	
	$sql="SELECT assignmentId,assignments.title,_list_assignmenttypes.title,shared,startDate,dueDate";
	$sql.=" FROM assignments";
	$sql.="  INNER JOIN _list_assignmenttypes ON assignments.type=_list_assignmenttypes.assignmentTypeId";
	$sql.=" WHERE ( fk_user_owner=" . $b->User->UserId . " AND assignments.active=1 )";
	if($_GET["sort"]!=NULL && $_GET["sort"]!="")
	{
		$sql.=" ORDER BY " . $_GET["sort"] . " ASC";
	}
  $ds=$con->Query($sql);
  $list.='<table width="100%" border="0" cellpadding="2" cellspacing="0" id="t1">';
	$list.='<tr>';
	$list.='<td style="background-color:#cccccc;border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;">';
	$list.='<input type="checkbox" id="aall" value="aall" name="aall" onClick="selectall(this.id)"></input>All</td>';
	$list.='<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='Assignment Name&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'exportgrade.php?sort=assignments.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='Type&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'exportgrade.php?sort=_list_assignmenttypes.title&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="startDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='Start Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'exportgrade.php?sort=startDate&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='<td style="border-top-style:solid;border-top-width:1px;border-top-color:black;border-bottom-style:solid;border-bottom-width:1px;border-bottom-color:black;border-left-style:solid;border-left-width:1px;border-left-color:black;font-weight:bold;text-align:center;' . ( $_GET["sort"]=="dueDate" ? "background-color:#aaaaaa;" : "background-color:#cccccc;" ) . '">';
	$list.='Due Date&nbsp;<img src="pics/downArrow.gif" alt="Sort by field" style="cursor:pointer;" onclick="javascript:document.location=\'exportgrade.php?sort=dueDate&filter=' . $_GET["filter"] . '\';" /></td>';
	$list.='</tr>';
  $i=0;
  while($dr=mysql_fetch_row($ds))
	{
		$aId=$dr[0];
		$doobie=FALSE;
		
		if($_GET["filter"])
		{
			if($_GET["filter"]!="0")
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
		if($doobie==TRUE)
		{
		 $added=TRUE;
		 $list.='<tr>';
		 $list.='<td style="background-color:#ffffff;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;text-align:center">';
		 $list.='<input type="checkbox" id="a'.$dr[0].'" name="ass" value="'.$dr[0].'"></input>';
		 $list.='</td>';
		 $list.='<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="assignments.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		 $list.=$dr[1] . '</td>';
		 $list.='<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="_list_assignmenttypes.title" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		 $list.=$dr[2] . '</td>';
		 $list.='<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="startDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		 $list.=substr($dr[4],0,10) . '</td>';
		 $list.='<td style="border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;' . ( $_GET["sort"]=="dueDate" ? "background-color:#dddddd;border-left-style:solid;border-left-width:1px;border-left-color:black;" : "background-color:white;border-left-style:solid;border-left-width:1px;border-left-color:white;" ) . '">';
		 $list.=substr($dr[5],0,10) . '</td>';
		 $list.='</tr>';
	  }
	 }
	 if($added==FALSE)
	 {
		$list.='<tr>';
		$list.='<td colspan="5" style="background-color:white;border-bottom-style:dashed;border-bottom-width:1px;border-bottom-color:black;cursor:default;">';
		$list.='Please Select Class Firstly.</td>';
		$list.='</tr>';
	 }
	$list.='</table>';
	$con->Dispose();
	$b->RenderTemplateTop();
?>
Choose assignments which you want to export. 
<p><h2>Step 1: Select Class</h2><br/> <select name="ddl_filter" id="ddl_filter" onchange="javascript:Filter();"><option value="0">Select Class</option><? echo($filter); ?></select></p>
<h2>Step 2: Select Assignments</h2><br/>
<? 
echo($list);
?>
<h2>Step 3: Select Display Format</h2><br/>
<input type='radio' name='dformat' value='1' /> Percentage <br>
<input type='radio' name='dformat' value='2' /> Number Correct <br>
<input type='radio' name='dformat' value='3' /> Number Correct out of Number of Questions <br>
<p style="text-align:center"><button type="button" id="b1" class="button1" onclick="subm()">View and Export</button></p>
<script language="javascript">
	function subm()
	{
		var cla=document.getElementById("ddl_filter");
		var cid=cla.options[cla.selectedIndex].value;
		if(cid==0)
		{
			alert("You didn't select class for which you want to export grade.");
			return;
		}
		var as=0;
		var obj=document.frm_body;	
		for(var i = 0;i<obj.elements.length;i++)
		{
     if(obj.elements[i].type == "checkbox" && obj.elements[i].checked ==true && obj.elements[i].value!="aall")
     {
       if(as==0)
       {
        aid=obj.elements[i].value;
       }else
       {
       	aid=aid+","+obj.elements[i].value;
       }
       as=1;
     }
    } 
    if(as==0)
    {
		 alert("You didn't select any assignments.");
		 return;
		}
		var dtype=obj.dformat;
		var dt=0;
		for(k=0;k<3;k++)
		{
			if(dtype[k].checked==true)
			{
		    dt=dtype[k].value;
		  }
		}
		if(dt==0)
		{
			alert("You didn't select display format.");
		  return;
		}
		var openlink="exportgradeview.php?cid="+cid+"&aid="+aid+"&dt="+dt;
	  window.open(openlink,"grade_view","toolbar=no,width=1024,height=768,status=no,resizable=yes,scrollbars=yes");
	}
function selectall(said)
{
	var sa=document.getElementById(said);
	if(sa.checked==1)
	{
	  var aptable=document.getElementById("t1");
	  var ps=aptable.firstChild.childNodes; 
	  for(i=0;i<ps.length;i++)
	  {	  	
	    ps[i].firstChild.childNodes[0].checked=true;	   
	  }
	}else
	{
    var aptable=document.getElementById("t1");
	  var ps=aptable.firstChild.childNodes; 
	  for(i=0;i<ps.length;i++)
	  {	  	
	    ps[i].firstChild.childNodes[0].checked=false;	   
	  }
	}
}
function getOs() 
{ 
 var OsObject = ""; 
 if(navigator.userAgent.indexOf("MSIE")>0) { 
 return 1; 
 } 
 if(isFirefox=navigator.userAgent.indexOf("Firefox")>0){ 
 return 2; 
 } 
 if(isSafari=navigator.userAgent.indexOf("Safari")>0) { 
 return 3; 
 } 
 if(isCamino=navigator.userAgent.indexOf("Camino")>0){ 
 return 4; 
 } 
 if(isMozilla=navigator.userAgent.indexOf("Gecko/")>0){ 
 return 5; 
 } 
 return 0;
}
</script>

<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>
