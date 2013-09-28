<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");

	$b->AddCrumb("Problems","");
	$b->ActiveMenu=21;
	$b->MainMenuIndex=21;
  $startp=1;
  $endp=350;
  if($_GET["startp"]!=null && $_GET["startp"]!="")
	{
		 $startp=$_GET["startp"];
     $endp=$_GET["endp"];
	}
	$b->AddScriptMethods($script);
	$con=new DatabaseManager();
	$sql="SELECT number,questionIntro";
	$sql.=" FROM problems";
	$sql.=" where number>=".$startp." and number<=".$endp;
	$sql.=" order by number";
	$ds=$con->Query($sql);
	$h="";
	$h.="<table border='0' cellspacing='0' cellpadding='0'><tr>";
	$h.="<td class='tablehead'>";
	$h.="Number</td>";
	$h.="<td class='tablehead' width='94%'>Description</td>";
	$h.="</tr>";
	while($dr=mysql_fetch_row($ds))
	{
		$h.="<tr ><td class='tablecontent' align='center'>";
		$h.="<a href='#' onclick='opensingle(".$dr[0].")'>P".$dr[0]."</td>";
		$h.="<td class='tablecontent' align='center'><textarea id='p".$dr[0]."' name='p".$dr[0]."' cols='90%' style='overflow-y:visible'>".$dr[1]."</textarea> </td>";
		$h.="</tr>";
	}
	$h.="</table>";
	$b->RenderTemplateTop();
	
?>

<p>
Enter the range of the problems: From <input type="text" id="startp" value="<? echo $startp; ?>" size="4"></input> to <input type="text" id="endp" value="<? echo $endp; ?>" size="4"></input>(1-350). <input type="button" id="btnchp" value="Display" class="button1" onclick="changep();"></input><br/><br/>
<? echo $h;?>
<p style="text-align:center"><input type="button" id="btnsavep" value="Save the changes" class="button1" onclick="savechgp();"></input></p>
</p>
<script language="javascript" src="scripts/openta.js"></script>
<script language="javascript" src="scripts/admindirect.js"></script>
<script language="javascript" src="scripts/dialog.js"></script>
<script language="javascript" src="scripts/sendrequest.js"></script>

<script language="javascript" >
function savechgp()
{
	var params="startp=<? echo $startp; ?>&endp=<? echo $endp; ?>";
	var i;
	for(i=<? echo $startp; ?>;i<=<? echo $endp; ?>;i++)
	{
		var pd=document.getElementById("p"+i);
		params+="&p"+i+"="+encodeURIComponent(pd.value);
	}
	var strHtml  = "Saving, please Wait...";
  sAlert(strHtml,400,100);	
	send_request("savechgp.php",params,aftersave)
}
function aftersave()
{
   if(http_request.readyState==4){
 	 
 	 if(http_request.status==200){
 	   var sh=document.getElementById("alertFram");
     sh.innerHTML="<div style='background:#3399cc;align:left;color:#ff9900;font-weight: bold'>MathPASS</div><br/>Save Successfully!<br/><a href='#' onClick='doOk();'>Go Back to Continue</a>"
 	 }else {
 	 alert("The page you requested is abnormal.");  
 	 }
 	 
 } //end if       
}
</script>
<?
	$con->Dispose();
	$b->RenderTemplateBottom();
	$b->Dispose();
?>