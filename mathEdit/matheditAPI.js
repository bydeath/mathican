var mmlparse='<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en" xmlns:mml="http://www.w3.org/1998/Math/MathML"><object id="matheditdemo1" classid="clsid:32F66A20-7614-11D4-BD11-00104BD3F987" codebase="http://www.dessci.com/dl/mathplayer.cab"></object>';
mmlparse=mmlparse+'<?import namespace="mml" implementation="#matheditdemo1" ?>';
var mmlparse1='</html>';

function mathedit(tID,stateStr){

 this.tID=tID;
 this.pID="";
 this.stateStr=stateStr;
 this.mathmlC="";
 this.infix="";
 this.customizalbe=""; 
 this.matheditURL=" ";
 this.editorsizevalue="";
 this.toolbarsvalue="";
 this.templatesvalue="";
 this.editingmode="";
 mathedit.editor[mathedit.numeditor++]=this;
 this.display=function(winID,mode)
 {
  	this.pID=winID;
     this.mathWin=document.getElementById(this.pID);
     if(stateStr==null || stateStr=="undefine" ||stateStr==""){
       this.mathWin.setAttribute("src",this.matheditURL);
     }
     else{     
        var initstate=this.stateStr.split("|");
        this.mathWin.setAttribute("src",initstate[0]);               
     } 
 }
this.afterload=function()
{
   if(stateStr==null ||stateStr=="undefine"){  	
       this.setEditorSize(this.editorsizevalue);
       this.showToolbar(this.toolbarsvalue); 
       this.showTemplate(this.templatesvalue);
       this.mathWin.contentWindow.showEM(this.editingmode);  
   }
   else{     
       var initstate=this.stateStr.split("|");
       this.setEditorSize(initstate[1]);
       this.showToolbar(initstate[2]);
       this.showTemplate(initstate[3]);
       this.mathWin.contentWindow.showEM(initstate[4]);  
   }                     
}
 this.showTemplate=function(templateID)
 {
 	if(templateID=="" || templateID==null ||templateID=="undefine") return;
  var templates=templateID.split(",");
  for(i=0;i<templates.length;i++)
    {
      try{
          this.mathWin.contentWindow.showT(templates[i]);        
      }catch(e)
      {
         	alert(e.message + " " + e.lineNumber );
	    } 
	   }
 }

 this.showToolbar=function(toolbarID)
 {
 	if(toolbarID=="" || toolbarID==null ||toolbarID=="undefine") return;
  toolbars=toolbarID.split(",");
  for(i=0;i<toolbars.length;i++)
   {  
     try{
         this.mathWin.contentWindow.showFT(toolbars[i]);
     }catch(e)
     {
   	    alert(e.message + " " + e.lineNumber );
	   } 
	 }
 }
 this.setEditorSize=function(sizevalue)
 {
  var sizes=sizevalue.split(",");
  var width1=sizes[0];
  var height1=sizes[1];
  try{
      this.mathWin.contentWindow.editarea(width1,height1);
  }catch(e)
   {
   	alert(e.message + " " + e.lineNumber );
	 } 
 }
 this.getContentMathML=function()
 {
 	 try{
 	 	 mc=new Array();
     mc=this.mathWin.contentWindow.getCode();
     return mc[0];
 	 	}
 	 catch(e)
   {
   	alert(e.message + " " + e.lineNumber );
	 }
 }
 this.getInfix=function()
 {
 	try{
     mc=new Array();
     mc=this.mathWin.contentWindow.getCode();
 	   return mc[1];
 	 	}
 	 catch(e)
   {
   	alert(e.message + " " + e.lineNumber );
	 }
 }
  this.getPresentation=function()
 {
 	try{
     mc=new Array();
     mc=this.mathWin.contentWindow.getCode();
 	   return mc[2];
 	 	}
 	 catch(e)
   {
   	alert(e.message + " " + e.lineNumber );
	 }
 }
 this.get=function(attrID){
    switch(attrID){ 
        case "toolbarID"  : return this.toolbarsvalue;        
        case "templateID" : return this.templatesvalue;
        case "EditorSize" : return this.editorsizevalue;
        case "mathContent":
                            var con=this.getContentMathML();
                        	  alert(con);
                        	  return con;          
        case "mathInfix":  
                           var inf=this.getInfix();
                           alert(inf);
                           return inf;  
        case "mathPresentation":  
                           var pre=this.getPresentation();
                           alert(pre);
                           return pre;                          
    }
 }
 this.set=function(attrName, value1){   
   switch(attrName){
        case "customizable": this.customizable=value1;break;
        case "mathURL"     : this.matheditURL=value1; break;
        case "toolbarID"   : this.toolbarsvalue=value1;break;
        case "templateID"  : this.templatesvalue=value1;break;
        case "EditorSize"  : this.editorsizevalue=value1;break;
        case "editingmode" : this.editingmode=value1;break;
  }
 }
 this.getAttributeNames=function(){
  var attrNames=["customizable","mathURL","EditorSize","toolbarID","templateID","mathContent","mathInfix","mathPresentation"];
  var aNames="";
  for(var i=0;i<attrNames.length;i++)
       aNames+=attrNames[i]+" ";
  return aNames;
 }
 this.getAttributeValues=function(){
  var aNamesvalue=this.customizable+"|"+this.matheditURL+"|"+this.editorsizevalue+"|"+this.toolbarsvalue+"|"+this.templatesvalue;
  return aNamesvalue;
 }
 this.editMathByCode=function(Str,cType){
  var codestr="";
  if(cType=="1") 
    codestr=Str;
  else if(cType=="2")
  {  
    codestr= this.mathWin.contentWindow.addprefix(Str);
  }
   
  this.mathWin.contentWindow.val_currentmath(codestr);
  this.mathWin.contentWindow.focus();
  this.mathWin.contentWindow.renew();
 }
}


mathedit.Code="";
mathedit.codeType=0;
mathedit.mathArray=new Array();
mathedit.matheditWin=null;
mathedit.currentMath=null;
mathedit.numOfMath=0;
mathedit.op="";
mathedit.editor=new Array();
mathedit.numeditor=0;
mathedit.foo=function(winID)
{
	alert(winID);
	for(var i=0; i<mathedit.editor.length;i++)
	{
		if(mathedit.editor[i].mathWin.contentWindow==winID)
		{
			 mathedit.editor[i].afterload();
			 return mathedit.editor[i].tID;
			}
	}
}
mathedit.newMath=function(tID,pID)
{
  if ( mathedit.matheditWin != null && !mathedit.matheditWin.closed )
	{
		alert( "You have already opened a MathEdit window!" );
		return;
	}
	var tmp = mathedit.getMathById( tID );
	if ( tmp != null )
	{
		alert( "In mathedit.newMath(): Duplicate tID \"" + tID + "\"!" );
		return;
	}
	mathedit.op="new";
  mathedit.currentMath = new mathedit(tID);
  mathedit.currentMath.pID=pID;
  mathedit.matheditWin=open("mathedit/mathedit.html","matheditwin","top=100,left=100,width=780,height=550,resizable=yes,status=yes");
}

mathedit.getMath=function(cmath)
{  
   var tempMath=mathedit.currentMath;
   var html;
   tempMath.pID=mathedit.currentMath.pID;
   tempMath.mathmlP=cmath[2];
   tempMath.mathmlC=cmath[0];
   tempMath.infix=cmath[1];
   if(mathedit.op=="new")
   {
     tempMath.mathmlC=tempMath.mathmlC.replace('<mml:math','<mml:math id="'+tempMath.tID+'"');
   }
   if(getOs()==1)
   {
   	if(mathedit.op=="edit")
   	{ 
   		var editor=document.getElementById("editor");
   		if(editor==null || editor=="undefine")
   		{
   		  var pElement = document.getElementById(tempMath.pID); 
   		  html=mmlparse+tempMath.mathmlC+mmlparse1;
        pElement.innerHTML=html;
   	  }else
   	  {
   	  	var pElement = editor.document.getElementById(tempMath.tID);
   	  	pElement.outerHTML=tempMath.mathmlC;
   	  }
   		if ( pElement == null )
   		{
   			alert( "Parent Id is invalid" );
   			mathedit.matheditWin.close();
   			return;
   		}
   	 
   	}else if(tempMath.pID=="cursor")
   	{
   		var editor=document.getElementById("editor");
   		var pElement=editor.document.selection.createRange();
   		alert(tempMath.mathmlC);
   		pElement.pasteHTML(tempMath.mathmlC);
   	}else if(tempMath.pID!="" )
	  {
		 var pElement = document.getElementById(tempMath.pID);
		 if ( pElement == null )
		 {
		  	alert( "Parent Id is invalid" );
		  	return;
	  	}
      alert(tempMath.mathmlC);
      html=mmlparse+tempMath.mathmlC+mmlparse1;
      
      pElement.innerHTML=html;
    }   
   }
   if(getOs()>=2)
   {
    	if(tempMath.pID=="cursor")
    	{
    		var pElement=editor.getSelection();
    	}else if(tempMath.pID!="" )
 	    {
 		   var pElement = document.getElementById(tempMath.pID);
 		 }
    	alert(tempMath.mathmlP);
    	html=tempMath.mathmlP;
    	var parser = new DOMParser(); 
      var myDocument = parser.parseFromString(html.toString(), "text/xml");
      var root=myDocument.documentElement;
      pElement.innerHTML="";
 	    pElement.appendChild(root);
   }
	 mathedit.mathArray[mathedit.numOfMath++] = tempMath;
	 mathedit.matheditWin.close();
}

mathedit.editMathById=function(tID)
{
	if ( mathedit.matheditWin != null && !mathedit.matheditWin.closed )
	{
		alert( "You have already opened a MathEdit window!" );
		return;
	}
	mathedit.currentMath = mathedit.getMathById( tID );
	if ( mathedit.currentMath == null )
	{
		alert( "In mathedit.editMath(): math with tID \"" + tID + "\" not found!" );
		return;
	}
	mathedit.op="edit";
  mathedit.matheditWin=open("mathedit/mathedit.html","matheditwin","top=100,left=100,width=780,height=550,status=yes");
}

mathedit.getMathById = function( tID )
{
	for ( var i=0; i<mathedit.numOfMath; i++ )
		if ( mathedit.mathArray[i].tID == tID )
			return mathedit.mathArray[i];
	return null;
}
mathedit.getCurrentMath=function (){
 	return mathedit.currentMath.mathmlC;
}
mathedit.getCurrentMath1=function (){
 	return mathedit.currentMath.mathmlP;
}
mathedit.editMath=function(Str,cType,tID,pID)
{ 
  mathedit.op="display_edit";
  mathedit.codeType=cType;
  var mathobj= new mathedit(tID);  
  mathobj.Code=Str;  
  mathedit.currentMath=mathobj;
  mathedit.currentMath.pID=pID;
  mathedit.matheditWin=open("mathedit/mathedit.html","matheditwin","top=100,left=100,width=780,height=550,resizable=yes,status=yes"); 
}
mathedit.getCurrentMath2=function()
{
 	return mathedit.currentMath.Code;
}
mathedit.get=function(attrID){
     switch(attrID){ 
        case "mathContent": mathedit.getContentMathML(mathedit.currentMath.tID); break;                                    
        case "mathInfix":  mathedit.getInfix(mathedit.currentMath.tID); break;                                   
        case "mathPresentation":  mathedit.getPresentationMathML(mathedit.currentMath.tID);  
    }
}    
mathedit.getContentMathML=function (tID){
  mathedit.currentMath = mathedit.getMathById( tID );
	if ( mathedit.currentMath == null )
	{
		alert( "In mathedit.getContentMathML(): math with tID \"" + tID + "\" not found!" );
		return;
	}
  alert(mathedit.currentMath.mathmlC); 
 	return mathedit.currentMath.mathmlC;
}
mathedit.getInfix=function (tID){
  mathedit.currentMath = mathedit.getMathById( tID );
	if ( mathedit.currentMath == null )
	{
		alert( "In mathedit.getInfix(): math with tID \"" + tID + "\" not found!" );
		return;
	}
  alert(mathedit.currentMath.infix); 
 	return mathedit.currentMath.infix;
}

mathedit.getPresentationMathML=function (tID)
{
 mathedit.currentMath = mathedit.getMathById( tID );
	if ( mathedit.currentMath == null )
	{
		alert( "In mathedit.getPresentationMathML(): math with tID \"" + tID + "\" not found!" );
		return;
	}
  alert(mathedit.currentMath.mathmlP); 
 	return mathedit.currentMath.mathmlP;
}

function Convert(Str,codeType){
	var codesource=Str;
	var codedestination;

	if(codeType=='1')
  {
  	var outmathml=strConvert(codesource);
    codedestination=outmathml;	       	
  }
	else if(codeType=='2')
  {  
  	var outmathml=strConvert(codesource);
    if(getOs()==1)
     SetNameSpace("mml");
    else
     SetNameSpace("");
    var infpre=convertToMathMLPresentDOM(outmathml);
    codedestination=GetMathMLEx(infpre);	     	
  }
  else if(codeType=='3')
	{ 
		if(getOs()==1)
     SetNameSpace("mml");
   	var result=convertToMathMLContentDOM(codesource);
    codedestination= GetMathMLEx(result);	          	
	}	   
	else if(codeType=='4')
  {
  	if(getOs()==1)  
   	SetNameSpace("mml");
   	var result=convertToMathMLPresentDOM(codesource);
    codedestination= GetMathMLExP(result);     	
	}	 
	codedestination=codedestination.toLowerCase(); 
  alert(codedestination);
  return codedestination;
}
/*
mathedit.displayMath=function(tID,pID)
{
	if (mathedit.pID!="")
	{
		var pElement = document.getElementById(mathedit.pID);
		if ( pElement == null )
		{
			alert( "Parent Id is invalid" );
			return;
		}
	}
	//pElement.innerHTML="";
	var html=mmlparse+mathedit.ContentMathML+mmlparse1;
	alert(mathedit.ContentMathML);
	pElement.innerHTML=html;
	mathedit.matheditWin.close();
	//alert(pElement.innerHTML);
}
*/
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