/*
	- Generic Formula Writer Script File for Math Pass Software
	-	Writen by Chris Green (cgreen9@kent.edu)

	- The code in this script file is used to re-instantiate FormulaWriter
	-	objects that have already been collected by the garbage collector.
	-	Additional comments and documentation can be found in the "documents"
	-	directory, found at the root level of this web site.
*/

//
// - Members
//
var focusAvailable=true;

//
// - Preview/Format Views
//
function GenericPreview(id)
{
	var x=new FormulaWriter(id);
	//alert(x.Host);
	x.EnableBorders=false;
	//alert(x.EnableBorders);
	x.Dispose();
	x=null;
	x=new FormulaWriter(id);
	//alert(x.EnableBorders);
	x.Draw();
	x.Dispose();
	//
	GetBrowserElement("lnk_preview_" + id).style.display="none";
	GetBrowserElement("lnk_format_" + id).style.display="";
}
function GenericFormat(id)
{
	var x=new FormulaWriter(id);
	x.EnableBorders=true;
	x.Dispose();
	x=null;
	x=new FormulaWriter(id);
	x.Draw();
	x.Dispose();
	//
	GetBrowserElement("lnk_preview_" + id).style.display="";
	GetBrowserElement("lnk_format_" + id).style.display="none";
}

//
// - Input
//
function GenericType(id,e)
{
	var temp=new FormulaWriter(id);
	temp.Type(e);
	temp.Dispose();
}
function GenericDown(id,e)
{
	var temp=new FormulaWriter(id);
	temp.AbnormalType(e);
	temp.Dispose();
}
function GenericTriggerOperations(id)
{
	var temp=new FormulaWriter(id);
	temp.TriggerOperations();
	temp.Dispose();
}
function GenericAddOperation(id,op)
{
	var x=GetBrowserElement("txt_activeFormulaWriter_" + id).value;
	if(x!="")
	{
		var temp=new FormulaWriter(x);
		temp.AppendWriter(op);
		temp.Dispose();
	}
}

//
// - Generic Object Manipulation
//
function SwapGenericImage(elementId,newImage)
{
	GetBrowserElement(elementId).src=newImage;
}
function ShowGenericObject(id)
{
	GetBrowserElement(id).style.display="";
}
function HideGenericObject(id)
{
	GetBrowserElement(id).style.display="none";
}

//
// - Cursor
//
/*
*/
function GenericShowCursor(id,counter)
{
	var temp=new FormulaWriter(id);
	temp.ShowCursor(counter);
	temp.Dispose();
}
function GenericHideCursor(id,counter)
{
	var temp=new FormulaWriter(id);
	temp.HideCursor(counter);
	temp.Dispose();
}

//
// - Focus
//
function SetGenericWriter(host,id)
{
	GetBrowserElement("txt_activeFormulaWriter_" + host).value=id;
}
function GenericSetFocus(id)
{
	if(focusAvailable)
	{
		focusAvailable=false;
		var x=new FormulaWriter(id);
		x.Focus();
		x.Dispose();
		setTimeout("SetFocusAvailable()",50);
	}
}
function SetFocusAvailable()
{
	focusAvailable=true;
}
function GetFocusedWriter(id)
{
	return GetBrowserElement("txt_activeFormulaWriter_" + id).value;
}
function GenericBlur(id)
{
	//setTimeout("FinishGenericBlur('" + id + "')",500);
}
function FinishGenericBlur(id)
{
	//alert(document.activeElement.id);
}