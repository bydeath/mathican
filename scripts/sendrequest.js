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