function sAlert(strHtml,wth,hgt){
    //var eSrc=(document.all)?window.event.srcElement:arguments[1];
    strHtmls="<div style='background:#3399cc;align:left;color:#ff9900;font-weight: bold'>MathPASS</div><br/>"+strHtml;
    if(wth=="" ||wth==null)wth="400";
    if(hgt=="" ||hgt==null)hgt="100";
    var shield = document.createElement("DIV");
    shield.id = "shield";
    shield.style.position ="absolute";
    shield.style.left = "0px";
    shield.style.top = "0px";
    shield.style.width = "100%";
    shield.style.height = ((document.documentElement.clientHeight>document.documentElement.scrollHeight)?document.documentElement.clientHeight:document.documentElement.scrollHeight)+"px";
    shield.style.background = "#F5F8F9";
    //shield.style.textAlign = "center";
    shield.style.zIndex = "10000";
    shield.style.filter = "alpha(opacity=0)";
    shield.style.opacity = 0;
    shield.style.border = "solid";
    
    var div_Mask = document.createElement("DIV");
    div_Mask.id = "div_Mask";
    div_Mask.style.zIndex = "999";
		div_Mask.style.position = "absolute";
		div_Mask.style.backgroundColor = this.MaskColor?this.MaskColor:"#f0f0f0";
		
		div_Mask.style.width = winsize()[0]+"px";
		div_Mask.style.height = winsize()[1]+"px";
		div_Mask.style.top = "0px";
		div_Mask.style.left = "0px";
		div_Mask.style.filter = "alpha(opacity=50)";
		div_Mask.style.opacity = 50/100;
		div_Mask.style.display = "";
    
    var alertFram = document.createElement("DIV");
    alertFram.id="alertFram";
    alertFram.style.position = "absolute";
    alertFram.style.left = "50%";
    alertFram.style.top = "50%";
    alertFram.style.marginLeft = "-180px" ;
    alertFram.style.marginTop = "-140px";
    alertFram.style.width = wth+"px";
    alertFram.style.height = hgt+"px";
    alertFram.style.background = "#E8F0F8";
    alertFram.style.zIndex = "10001";
   // alertFram.style.textAlign = "left";
    
    alertFram.innerHTML = strHtmls;
    document.body.appendChild(div_Mask);
    document.body.appendChild(alertFram);
    document.body.appendChild(shield);
    this.setOpacity = function(obj,opacity){
        if(opacity>=1)opacity=opacity/100;
        try{ obj.style.opacity=opacity; }catch(e){}
        try{ 
            if(obj.filters.length>0&&obj.filters("alpha")){
                obj.filters("alpha").opacity=opacity*100;
            }else{
                obj.style.filter="alpha(opacity=\""+(opacity*100)+"\")";
            }
        }catch(e){}
    }
    
    var c = 0;
    this.doAlpha = function(){
        if (++c > 20){clearInterval(ad);return 0;}
        setOpacity(shield,c);
    }
    var ad = setInterval("doAlpha()",1);
    
    this.doOk = function(){
        //alertFram.style.display = "none";
        //shield.style.display = "none";
        document.body.removeChild(alertFram);
        document.body.removeChild(shield);
        document.body.removeChild(div_Mask);
        //eSrc.focus();
        document.body.onselectstart = function(){return true;}
        document.body.oncontextmenu = function(){return true;}
    }
    //eSrc.blur();
    document.body.onselectstart = function(){return false;}
    document.body.oncontextmenu = function(){return false;}
}
function winsize()
{
	return [
			Math.max(document.documentElement.scrollWidth, document.body.scrollWidth), 
			Math.max(document.documentElement.scrollHeight, document.body.scrollHeight)
	  	];
}