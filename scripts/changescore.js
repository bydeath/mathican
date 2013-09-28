function changesc(fname,lname,aname,bestid,bests,bestt,bestc)
{
	var strHtml="<table align='center'><tr><td>Assignment Name:</td><td>"+aname.toUpperCase()+"</td></tr>";
	strHtml=strHtml+"<tr><td>Student Name:</td><td>"+fname+" "+lname+"</td></tr>";
	strHtml=strHtml+"<tr><td>Original Score:</td><td>"+bests+"/"+bestt+"</td></tr>";
	if(bestc=="-1")
	{
	  strHtml=strHtml+"<tr><td>Current Score:</td><td><input id='"+bestid+"' name='"+bestid+"' type='inputbox' value='"+bests+"'></input> (total:"+bestt+")</td></tr>";
  }else
  {
  	strHtml=strHtml+"<tr><td>Current Score:</td><td><input id='"+bestid+"' name='"+bestid+"' type='inputbox' value='"+bestc+"'></input> (total:"+bestt+")</td></tr>";
  }
  
	strHtml=strHtml+"<tr><td colspan='2' align='center'><button class='button1' onClick='changescore("+bestid+","+bestt+")'>Change</button> <button class='button1' onClick='doOk();'>Cancel</button></td></tr></table>";
	sAlert(strHtml,400,200);
}
function changescore(tid,tt)
{
	var telet=document.getElementById(tid);
	if(telet.value>tt)
	{
	  alert("The score should be less than or equal to total numbers");
	  return;
  }
  var params="tid="+tid+"&chgs="+telet.value;
  send_request("changescore.php",params,processchange);	
}
function processchange()
{
	if(http_request.readyState<4)
	{
		
	}
  if(http_request.readyState==4)
  {
	  if(http_request.status==200){
	   doOk();
	   window.location.reload(true);
	  }else {
	  }
  }       
}