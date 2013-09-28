/*
	- Global Script File for Math Pass Software
	-	Writen by Chris Green (cgreen9@kent.edu)
	
	- Copyright Protected 2007 - Christopher B. Green
	-	Anyone may use or modify this program as they desire so long as they
	-	don't remove this comment block and provide the program free of charge.

	- This script file contains scripts consumed globally across
	-	the software package.
*/

//
// - Initialize
//
function Initialize()
{
	GenericCode();
}

function GoToPage(link)
{
	document.location=link;
}

//
// - Page Options
//
function PageOptionsOver(index)
{
	GetBrowserElement("tbl_pageOptions_" + index).className="pageOptionsOn";
	GetBrowserElement("td_pageOptionsR_" + index).style.display="";
}
function PageOptionsOut(index)
{
	GetBrowserElement("tbl_pageOptions_" + index).className="pageOptionsOff";
	GetBrowserElement("td_pageOptionsR_" + index).style.display="none";
}

//
// - Printer Friendly
//
function PrintPage()
{
	var src=GetBrowserElement("img_print").src;
	src=src.substr(src.lastIndexOf("/")+1);
	if(src=="print.gif")
	{
		PrintTemplate();
	}
	else
	{
		StandardizeTemplate();
	}
	var fSize="";
}

function PrintTemplate()
{
	ShowLayover("printSheet");
	SetPreviewTextSize(GetBrowserElement("txt_previewFontSize").value);
}
function FormatPageForPrint()
{
	HideLayover("printSheet");
	GetBrowserElement("img_print").src="pics/stopPrint.gif";
	GetBrowserElement("lnk_styleSheet").href="globals.printPreview.css";
	var fSize=GetBrowserElement("txt_previewFontSize").value;
	GetBrowserElement("lnk_dynmicSheet").href="base/dynamicPrintFontSize.php?fontSize=" + fSize;
	window.print();
}
function StandardizeTemplate()
{
	GetBrowserElement("lnk_dynmicSheet").href="";
	GetBrowserElement("img_print").src="pics/print.gif";
	GetBrowserElement("lnk_styleSheet").href="globals.css";
}
function PrinterZoomTextIn()
{
	var x=parseInt(GetBrowserElement("txt_previewFontSize").value);
	x+=2;
	SetPreviewTextSize(x);
}
function PrinterZoomTextOut()
{
	var x=parseInt(GetBrowserElement("txt_previewFontSize").value);
	x-=2;
	SetPreviewTextSize(x);
}
function SetPreviewTextSize(size)
{
	GetBrowserElement("txt_previewFontSize").value=size;
	GetBrowserElement("div_printPreview").style.fontSize=size;
	GetBrowserElement("div_printPreview").innerText=size + "pt";
}

//
// - Main Menu
//
function MainMenuOver(index)
{
	if(GetBrowserElement("td_menuItem_" + index).className!="menuItemOn")
	{
		GetBrowserElement("td_menuItem_" + index).className="menuItemOver";
	}
}
function MainMenuOut(index)
{
	if(GetBrowserElement("td_menuItem_" + index).className!="menuItemOn")
	{
		GetBrowserElement("td_menuItem_" + index).className="menuItemOff";
	}
}
function MainMenuSelect(index)
{
	try
	{
		GetBrowserElement("td_menuItem_" + index).className="menuItemOn";
	}
	catch(e)
	{}
}
function MainMenuClick(index)
{
	var link=null;
	switch(index)
	{
		case 13 :
			link="index.php";
			break;
		case 14 :
			link="faq.php";
			break;
		case 0 :
			link="logon.php";
			break;
		case 1 :
			link="register.php";
			break;
		case 2 :
			link="forgotPassword.php";
			break;
		case 3 :
			link="yourAccount.php";
			break;
		case 4 :
			link="teachersHome.php";
			break;
		case 5 :
			link="teachersStudents.php";
			break;
		case 6 :
			link="teachersAssignments.php";
			break;
		case 7 :
			link="teachersClasses.php";
			break;
		case 8 :
			link="studentsHome.php";
			break;
		case 9 :
			link="studentsAssignments.php";
			break;
		case 10 :
			link="practice.php";
			break;
		case 11 :
			link="logoff.php";
			break;
		case 12 :
			link="contactUs.php";
			break;
		case 15 :
			link="viewStudent.php";
			break;
		case 16 :
			link="visitorInfo.php";
			break;
		 case 17 :
			link="adminHome.php";
			break;
		case 18 :
			link="adminUser.php";
	}
	if(link!=null)
	{
		document.location=link;
	}
}

//
// - Layover
//
function ShowLayover(id)
{
	document.body.scroll="no";
	document.body.style.overflow="hidden";
	GetBrowserElement(id + "_div1").style.display="";
	GetBrowserElement(id + "_div2").style.display="";
}
function HideLayover(id)
{
	document.body.scroll="yes";
	document.body.style.overflow="auto";
	GetBrowserElement(id + "_div1").style.display="none";
	GetBrowserElement(id + "_div2").style.display="none";
}

//
// - General Tools
//
function ReportError(isForm)
{
	var c=true;
	if(isForm==1)
	{
		c=confirm("To report an error you must navigate away from this page. If you navigate away from this page without submiting the form first you will lose any data that hasn't already been saved. Are you sure you want to leave the page?");
	}
	if(c==true)
	{
		document.location="reportError.php?page=" + document.location;
	}
}
function GetBrowserElement(elementId)
{
	return document.getElementById ? document.getElementById(elementId) : ( document.all ? eval("document.all." + elementId) : eval("document.forms[0]." + elementId) );
}
function GetCharFromCode(charCode)
{
	var retval="";
	switch(charCode)
	{
		// - Symbols
		case 43:
			retval="+";
			break;
		case 45:
			retval="-";
			break;
		case 42:
			retval="*";
			break;
		case 47:
			retval="/";
			break;
		case 40:
			retval="(";
			break;
		case 41:
			retval=")";
			break;
		case 91:
			retval="[";
			break;
		case 93:
			retval="]";
			break;
		case 46:
			retval=".";
			break;
		// - Numbers
		case 48:
			retval="0";
			break;
		case 49:
			retval="1";
			break;
		case 50:
			retval="2";
			break;
		case 51:
			retval="3";
			break;
		case 52:
			retval="4";
			break;
		case 53:
			retval="5";
			break;
		case 54:
			retval="6";
			break;
		case 55:
			retval="7";
			break;
		case 56:
			retval="8";
			break;
		case 57:
			retval="9";
			break;
		// - Letters
		case 65:
			retval="A";
			break;
		case 66:
			retval="B";
			break;
		case 67:
			retval="C";
			break;
		case 68:
			retval="D";
			break;
		case 69:
			retval="E";
			break;
		case 70:
			retval="F";
			break;
		case 71:
			retval="G";
			break;
		case 72:
			retval="H";
			break;
		case 73:
			retval="I";
			break;
		case 74:
			retval="J";
			break;
		case 75:
			retval="K";
			break;
		case 76:
			retval="L";
			break;
		case 77:
			retval="M";
			break;
		case 78:
			retval="N";
			break;
		case 79:
			retval="O";
			break;
		case 80:
			retval="P";
			break;
		case 81:
			retval="Q";
			break;
		case 82:
			retval="R";
			break;
		case 83:
			retval="S";
			break;
		case 84:
			retval="T";
			break;
		case 85:
			retval="U";
			break;
		case 86:
			retval="V";
			break;
		case 87:
			retval="W";
			break;
		case 88:
			retval="X";
			break;
		case 89:
			retval="Y";
			break;
		case 90:
			retval="Z";
			break;
		case 97:
			retval="a";
			break;
		case 98:
			retval="b";
			break;
		case 99:
			retval="c";
			break;
		case 100:
			retval="d";
			break;
		case 101:
			retval="e";
			break;
		case 102:
			retval="f";
			break;
		case 103:
			retval="g";
			break;
		case 104:
			retval="h";
			break;
		case 105:
			retval="i";
			break;
		case 106:
			retval="j";
			break;
		case 107:
			retval="k";
			break;
		case 108:
			retval="l";
			break;
		case 109:
			retval="m";
			break;
		case 110:
			retval="n";
			break;
		case 111:
			retval="o";
			break;
		case 112:
			retval="p";
			break;
		case 113:
			retval="q";
			break;
		case 114:
			retval="r";
			break;
		case 115:
			retval="s";
			break;
		case 116:
			retval="t";
			break;
		case 117:
			retval="u";
			break;
		case 118:
			retval="v";
			break;
		case 119:
			retval="w";
			break;
		case 120:
			retval="x";
			break;
		case 121:
			retval="y";
			break;
		case 122:
			retval="z";
			break;
	}
	return retval;
}

function OpenHelp(page)
{
	page=page.substr(page.lastIndexOf("/")+1);
	//alert(page);
	window.open("help.html?page=" + page,"helpWindow","menubar=0,toolbar=0,status=0,titlebar=0",true);
}

//
// AJAX
//