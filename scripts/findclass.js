var xmlHttp;   
var targetSelId;
var selArray;

function createXmlHttp() {
	if(window.XMLHttpRequest) {
		xmlHttp = new XMLHttpRequest();
	} else {
		xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
}

function showCTitle(selectedId,targetId) {
	/*alert(targetId);*/
	var s=selectedId;
	var t=targetId;
	if(selectedId=="") {
		return;
	}
	targetSelId=targetId;
	createXmlHttp();
	xmlHttp.onreadystatechange=buildSelectCallBack;
	xmlHttp.open("GET","findclassServer.php?selectedId="+s+"&targetSelId="+t,true);
	xmlHttp.send(null);
}

function buildSelectCallBack() {
	if(xmlHttp.readyState==4){
		var optionsInfo = eval("("+xmlHttp.responseText+")");
		var targetSelNode = document.getElementById(targetSelId);
		targetSelNode.length=1;
		targetSelNode.options[0].selected=true;
		
		
		for(var o in optionsInfo)
		{
			targetSelNode.appendChild(createOption(o,optionsInfo[o]));
		}
	}
}

function createOption(value,text) {
	var opt = document.createElement("option");
	opt.setAttribute("value",value);
	opt.appendChild(document.createTextNode(text));
	return opt;
}

function listCourseInfo(uidTitle) {
	var uid;
	var title;
	var startIndex=uidTitle.lastIndexOf(",@^&")+1;
	var endIndex=uidTitle.lastIndexOf("&^@,");
	
	uid=uidTitle.substring(0,startIndex-1);
	title=uidTitle.substring(startIndex+3,endIndex);
	
	createXmlHttp();
	xmlHttp.onreadystatechange=showCourseCallback;
	xmlHttp.open("GET","findclassServer.php?uid="+uid+"&title="+title,true);
	xmlHttp.send(null);
}

function showCourseCallback() {
	if(xmlHttp.readyState==4){
		if(xmlHttp.responseText!=""){
			var sCourseInfo = eval("("+xmlHttp.responseText+")");
			var cid = document.getElementById("cid");
			var tName = document.getElementById("tName");
			var cTitle = document.getElementById("cTitle");
			var sDate = document.getElementById("sDate");
			var eDate = document.getElementById("eDate");
			var pwd = document.getElementById("pwd");
			var count=0;
		  for(var o in sCourseInfo)
			{
				if(count==0)
					cid.innerHTML=sCourseInfo[o];
				if(count==1)
					tName.innerHTML=sCourseInfo[o];
				if(count==2)
					cTitle.innerHTML=sCourseInfo[o];
				if(count==3)
					sDate.innerHTML=sCourseInfo[o];
				if(count==4)
					eDate.innerHTML=sCourseInfo[o];
				if(count==5&&sCourseInfo[o]=="no")
				  pwd.style.display="none";
				else
					pwd.style.display="block";
				count++;
			}
	  }
	}
}

function insertClass(uid,cid,pwd){
  document.getElementById("pwd").value="";
  createXmlHttp();
	xmlHttp.onreadystatechange=insertClassCallback;
	xmlHttp.open("GET","findclassServer.php?uidI="+uid+"&cidI="+cid+"&pwd="+pwd,true);
	xmlHttp.send(null);
}

function insertClassCallback() {
	if(xmlHttp.readyState==4){
	  var success = xmlHttp.responseText;
	  if(success=="a"){
	  	alert("You have been added to the class!");
	  	window.location = "findclass.php";
	  }else{
	  	alert("The password is wrong!");
	  }
	}
}


function enablemethod() {
	var method = document.getElementsByName("method");
	var mv;
	for(i=0;i<method.length;i++) {
		if(method[i].checked) {
			mv=method[i].value;
		}
	}

	if(mv=="o") {
		  
			var teachername=document.getElementById("teachername");
			teachername.disabled=true;
			
			var title=document.getElementById("title");
			title.disabled=true;
			
			var search=document.getElementById("search");
			search.disabled=false;
			
			var courseid=document.getElementById("courseid");
			courseid.disabled=false;
	} else {
			var teachername=document.getElementById("teachername");
			teachername.disabled=false;
			
			var title=document.getElementById("title");
			title.disabled=false;
			
			var search=document.getElementById("search");
			search.disabled=true;
			
			var courseid=document.getElementById("courseid");
			courseid.disabled=true;
	}
}


function listCourse(cid)
{
	createXmlHttp();
	xmlHttp.onreadystatechange=showCourseCallback;
	xmlHttp.open("GET","findclassServer.php?cid="+cid,true);
	xmlHttp.send(null);
}

