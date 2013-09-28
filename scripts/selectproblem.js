function takepractice()
{
	var sptable=document.getElementById("spTable");
	if(getOs()==1)	
  	var ps=sptable.firstChild.childNodes;
  else
  	var ps=sptable.childNodes;
  if(ps.length==0)
  {
  	alert("You have not selected any problems.");
  	return;
  }
  else
  {
   var pvalue=""; 
   
   for(var i=0;i<ps.length-1;i++)
   {
   	 pvalue=pvalue+ps[i].childNodes[0].childNodes[1].value+",";
   }
   pvalue=pvalue+ps[i].childNodes[0].childNodes[1].value;
   var link="takeAssignmentDo1.php?openmode=1&number=1&types=" + pvalue;
	 window.open(link,"assignment","location=no,menubar=no,toolbar=no,width=780,height=550,status=no,scrollbars=yes");
  }
}

function submitf()
{
	var txt_t=document.getElementById("txt_title");
	if(txt_t.value=="" ||txt_t.value==null)
	{
	  alert("You must enter a title for the assignment!");
	  return false;
  }
	var sptable=document.getElementById("spTable");
	if(getOs()==1)	
  	var ps=sptable.firstChild.childNodes;
  else
  	var ps=sptable.childNodes;
  if(ps.length==0)
  {
  	alert("You have not selected problems.");
  	return false;
  }
  else
  {
   var pvalue=""; 
   for(var i=0;i<ps.length-1;i++)
   {
   	 pvalue=pvalue+ps[i].firstChild.childNodes[1].value+":";
   	 pvalue=pvalue+ps[i].childNodes[1].firstChild.value+",";
   }
   pvalue=pvalue+ps[i].firstChild.childNodes[1].value+":";
   pvalue=pvalue+ps[i].childNodes[1].firstChild.value;
   document.getElementById("selectp").value=pvalue;
   return true;
  }
}
function changecourse()
{
	var course=document.getElementById("course");
  var params="course="+course.value;
  send_request("fetchChap.php",params,processchgc);
}
changecourse();
function changechap()
{	
	  var course=document.getElementById("course");
		var chap=document.getElementById("chapter");
    var params="chapter="+chap.value+"&course="+course.value;
    send_request("fetchProblem.php",params,processchange);
}
function send_request(url,params,pr)
{ 
	http_request=false;
	if(window.XMLHttpRequest)
	{ http_request=new XMLHttpRequest();
	  if(http_request.overrideMimeType)
	  { 
	  	http_request.overrideMimeType("text/xml");
	  }
	}else if(window.ActiveXObject){
	  try{
	    http_request=new ActiveXObject("Msxml2.XMLHttp");
	  }catch(e){
	   try{
	     http_request=new ActiveXobject("Microsoft.XMLHttp");
	   }catch(e){}
	  }
	}

	if(!http_request){
	 window.alert("Fail to create XMLHttp Object.");
	 return false; 
	} 
	http_request.onreadystatechange=pr;  
	http_request.open("POST",url,true);
	http_request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=UTF-8");
	http_request.send(params);
}
function processchgc()
{
	if(http_request.readyState<4)
	{

	}
  if(http_request.readyState==4)
  {
	  if(http_request.status==200){
	   var ap=document.frm_body.chapter;
	   var ch=Array();
	   var co=document.getElementById("chapterop");
	   var rt=http_request.responseText;
	   var rt1='<select id="chapter" name="ddl_chapter" onchange="changechap();">'+rt+'</select>'
	   co.innerHTML=rt1;
	   changechap();
	  }else {
	  }
  }
}
function processchange()
{
	if(http_request.readyState<4)
	{
		//bs.value="fetch...";
	}
  if(http_request.readyState==4)
  {
	  if(http_request.status==200){
	   var ap=GetBrowserElement("apDiv");
	   ap.innerHTML=http_request.responseText;
	  }else {
	  }
  }       
} 
function selectall(said)
{
	var sa=document.getElementById(said);
	var osv=getOs();
	if(sa.checked==1)
	{
		if(said=="left")
		{
		 var aptable=document.getElementById("apTable");
		 var ps=aptable.firstChild.childNodes;
		 for(i=0;i<ps.length;i++)
		 {
		 	if(ps[i].firstChild.firstChild.type=="checkbox")ps[i].firstChild.firstChild.checked=1;
		 }
		}
		if(said=="right")
		{
		 var aptable=document.getElementById("spTable");
		 if(osv==1)
		 {
		  var ps=aptable.firstChild.childNodes;
		 }else
		 {
		 	 var ps=aptable.childNodes;
		 }
		 for(i=0;i<ps.length;i++)
		 {
		 	if(ps[i].firstChild.childNodes[1].type=="checkbox")ps[i].firstChild.childNodes[1].checked=true;
		 }
		}
	}else
	{
		if(said=="left")
		{
  		 var aptable=document.getElementById("apTable");
  		 var ps=aptable.firstChild.childNodes;
  		 for(i=0;i<ps.length;i++)
  		 {
  		 	ps[i].firstChild.firstChild.checked=false;
  		 }
		}
	  if(said=="right")
		{
   		 var aptable=document.getElementById("spTable");
   		 if(osv==1)
		  {
		    var ps=aptable.firstChild.childNodes;
		   }else
		  {
		 	  var ps=aptable.childNodes;
		   }
   		 for(i=0;i<ps.length;i++)
   		 {
   		 	if(ps[i].firstChild.childNodes[1].type=="checkbox")ps[i].firstChild.childNodes[1].checked=false;
   		 }
		}
	}
}
function addp()
{
	var aptable=document.getElementById("apTable");
  var ps=aptable.firstChild.childNodes;
  var k=0;
  for(i=0;i<ps.length;i++)
  {
  	if(ps[i].firstChild.firstChild.checked)
  	{
      var ptext=ps[i].firstChild.childNodes[1].innerHTML;
      var pn=ps[i].firstChild.firstChild.getAttribute("value");
      addthis(ptext,pn,"1");
  		ps[i].firstChild.firstChild.checked=false;  		
  	}
  }
  sortp(); 
}
function addthis(ptext,pn,num)
{

		  var tr1=document.createElement("tr");
  		var td1=document.createElement("td");
  		var td2=document.createElement("td");
  		td1.setAttribute("width","280px");  		
  		td2.setAttribute("align","right");	
  		td2.setAttribute("width","20px");
  		var span2=document.createElement("span");
  		var input1=document.createElement("input");
  		var span1=document.createElement("span");	
  		var text1=document.createTextNode(ptext);
  		input1.setAttribute("type","checkbox");
  		input1.setAttribute("name","sp");
  		input1.setAttribute("value",pn);
  		span1.setAttribute("id",pn);
  		span1.onclick=function(){openp(this.id);}
  		var input2=document.createElement("input"); 
  		input2.setAttribute("type","text");
  		input2.setAttribute("size","1");
      input2.setAttribute("value",num);
  		if(getOs()==1)
  		{
  			span1.setAttribute("className","phand");
  			input2.setAttribute("className","input1");
  		}else
  		{
  		  span1.setAttribute("class","phand");
  		 input2.setAttribute("class","input1");
  	  }
      td1.appendChild(span2);	
  		td1.appendChild(input1);
  		span1.appendChild(text1);	
  		td1.appendChild(span1);
  		td2.appendChild(input2);  		
  		tr1.appendChild(td1);
  		tr1.appendChild(td2);
  	  var sptable=document.getElementById("spTable");
  		if(getOs()==1)	
  		sptable.firstChild.appendChild(tr1);
  		else
  		sptable.appendChild(tr1);
  		
}
function openp(d)
{
  var openlink="takeAssignmentDo1.php?openmode=1&number=1&types="+ d;
  window.open(openlink,"assignment","location=no,menubar=no,toolbar=no,width=780,height=650,status=no,scrollbars=yes,resizable=yes");
}
function sort()
{
	var sptable=document.getElementById("spTable");
	var osv=getOs();
	if(osv==1)	
  	var ps=sptable.firstChild.childNodes;
  else
  	var ps=sptable.childNodes;
  for(var i=1;i<ps.length;i++)
  {
  	var cid= ps[i].firstChild.childNodes[1].getAttribute("value");
  	var k=i;
  	var j;
  	for(j=i-1;j>=0;j--)
  	{
  		if(parseInt(cid)>=parseInt(ps[j].firstChild.childNodes[1].getAttribute("value")))
  		{
  			break;
  		}
  	}
  	if(j<i-1)
  	{
  		var pnode=ps[i].cloneNode(true);
  		if(getOs()==1)	
  		{
  			sptable.firstChild.removeChild(ps[i]);
  		  sptable.firstChild.insertBefore(pnode,ps[j+1]);  
  		}
  		else
  	  {
  		 sptable.removeChild(ps[i]);
  		 sptable.insertBefore(pnode,ps[j+1]);
  		}
  	}
  }
  sortp();
}

function sortp()
{
	var sptable=document.getElementById("spTable");
	var osv=getOs();
	if(osv==1)	
  	var ps=sptable.firstChild.childNodes;
  else
  	var ps=sptable.childNodes;
  for(var i=0;i<ps.length;i++)
  {
  		var num=document.createTextNode(String(i+1));
  		ps[i].firstChild.firstChild.innerHTML="";
  		ps[i].firstChild.firstChild.appendChild(num);
  		
  		if(osv==1)
  		{
  		  ps[i].childNodes[0].removeAttribute("className");
  		  ps[i].childNodes[0].removeAttribute("className");
  	  }
  	  else
  	  {
  	  	ps[i].childNodes[0].removeAttribute("class");
  		  ps[i].childNodes[0].removeAttribute("class");
  	  }
      if(i%2==1)
      {
  	    if(osv==1)
  	    {
  	    	ps[i].childNodes[0].setAttribute("className","td_pro");
  	      ps[i].childNodes[1].setAttribute("className","td_pro");	
  	    }else
  	    {
  	      ps[i].childNodes[0].setAttribute("class","td_pro");
  	      ps[i].childNodes[1].setAttribute("class","td_pro");	
  	    }
  	  }
  }
  
}
function removep()
{
	var sptable=document.getElementById("spTable");
	if(getOs()==1)	
  	var ps=sptable.firstChild.childNodes;
  else
  	var ps=sptable.childNodes;
  for(i=0;i<ps.length;i++)
  {
  	if(ps[i].firstChild.childNodes[1].checked)
  	{
  		if(getOs()==1)	
  		{
  		 sptable.firstChild.removeChild(ps[i]);
  		}
  		else
  		 sptable.removeChild(ps[i]);
  		i--;
  	}
  }
  sortp();
}
function goUp()
{
	var sptable=document.getElementById("spTable");
	if(getOs()==1)
	{	
  	var ps=sptable.firstChild.childNodes;
  }
  else
  {
  	var ps=sptable.childNodes;
  }
  for(var i=1;i<ps.length;i++)
  {
  	if(ps[i].firstChild.childNodes[1].checked)
  	{
  		var pnode=ps[i].cloneNode(true);
  		if(getOs()==1)	
  		{
  			sptable.firstChild.removeChild(ps[i]);
  		  sptable.firstChild.insertBefore(pnode,ps[i-1]);  
  		}
  		else
  	  {
  		 sptable.removeChild(ps[i]);
  		 sptable.insertBefore(pnode,ps[i-1]);
  		}
  		ps[i-1].firstChild.childNodes[1].checked=true;
  	}
  }
  sortp();
}
function goDown()
{
	var sptable=document.getElementById("spTable");
	if(getOs()==1)
	{	
  	var ps=sptable.firstChild.childNodes;
  }
  else
  {
  	var ps=sptable.childNodes;
  }
  for(var i=ps.length-2;i>=0;i--)
  {
  	if(ps[i].firstChild.childNodes[1].checked)
  	{
  		var pnode=ps[i].cloneNode(true);
  		var len=ps.length-2;
  		if(getOs()==1)	
  		{	
  			sptable.firstChild.removeChild(ps[i]);
  			if(i==len)
  			{
  			 sptable.firstChild.appendChild(pnode);
  			}
  			else
  		   sptable.firstChild.insertBefore(pnode,ps[i+1]);
  		}
  		else
  	  {
  		 sptable.removeChild(ps[i]);
  		 if(i==len)
  			 sptable.appendChild(pnode);
  		 else
  		   sptable.insertBefore(pnode,ps[i+1]);
  		}
  		ps[i+1].firstChild.childNodes[1].checked=true;
  	}
  }
  sortp();
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