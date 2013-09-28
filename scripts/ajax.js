var xmlHttp=null;

//
// Initialize
//
function InitAjax()
{
	//alert("InitAjax(); 1");
	//
	// - Define xmlHttp
	//
	try
	{
		//Firefox, Opera, Safari
		xmlHttp=new XMLHttpRequest();
	}
	catch(error)
	{
		//Internet explorer
		try
		{
			xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
		catch(error2)
		{
			try
			{
				xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
			}
			catch(error3)
			{
				//Your browser sucks...
				alert("This browser does not support AJAX!");
			}
		}
	}
	//
	// - Hook up event handlers
	//
	xmlHttp.onreadystatechange=function()
	{
		switch(xmlHttp.readyState)
		{
			case 0 ://method to be called when the request is not initialized
						try
						{
							OnRequestNotInitialized();
						}
						catch(ex0){}
						break;
					case 1 ://method to be called when the request has been set up
						try
						{
							OnRequestSetUp();
						}
						catch(ex1){}
						break;
					case 2 ://method to be called when the request has been sent
						try
						{
							OnRequestSent();
						}
						catch(ex2){}
						break;
					case 3 ://method to be called when the request is in process
						try
						{
							OnRequestInProcess();
						}
						catch(ex3){}
						break;
					case 4 ://method to be called when the request is complete
						try
						{
							OnRequestComplete();
						}
						catch(ex4){}
						break;
		}
	}
}

//
// - Invoking Method
//
function AjaxRequest(method,link,bo)
{
//	alert("ajax sending");
	xmlHttp=null;
//	if(xmlHttp==null)
	InitAjax();
	xmlHttp.open(method,link,bo);
	xmlHttp.send(null);
}