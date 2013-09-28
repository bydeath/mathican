/*
	- Formula Writer Script File for Math Pass Software
	-	Writen by Chris Green (cgreen9@kent.edu)

	- This script file contains scripts used by the formula writer
	-	control. Additional comments and documentation can be found
	-	in the "documents" directory, found at the root level of
	-	this web site.
*/

function FormulaWriter(ID)
{
	//
	// - Members
	//

	// - Field Names
	this.ViewState="td_viewState_" + ID;
	this.ViewStateField="txt_viewState_" + ID;
	this.WhiteBoard="div_whiteBoard_" + ID;
	this.Operations="td_operations_" + ID;
	this.Hidden="txt_hidden_" + ID;
	this.ParenthesisCounter="txt_parenthesisCounter_" + ID;
	this.ControlList="txt_controlList_" + ID;
	this.Infix="txt_infix_" + ID;
	this.Mml="txt_mml_" + ID;
	this.MmlP="txt_mmlP_" + ID;
	this.Test="txt_test_" + ID;

	// - Timer Values
	this.CursorHelper="img_cursorHelper_" + ID;
	this.CursorCounter="txt_cursorBlinkCounter_" + ID;
	this.Cursor="spn_cursor_" + ID;
	this.CursorIndex="txt_cursorIndex_" + ID;

	//
	// - Properties
	//
	this.Parent=null;
	this.Host=ID;
	this.Value="";
	this.Height=20;
	this.Width=25;
	this.FontSize="13";
	this.ZIndex=1;
	this.IsChild=false;
	this.SubElements=new Array();
	this.EnableBorders=true;

	//
	// - Constructor
	//
	this.Initialize=function()
	{
		// - Load ViewState
		if(GetBrowserElement(this.ViewStateField)!=null)
		{
			if(GetBrowserElement(this.ViewStateField).value!="")
			{
				var state=GetBrowserElement(this.ViewStateField).value;
				//alert(state);
				
				var collection=state.split(";");
				
				for(var i=0;i<collection.length;i+=1)
				{
					var x=collection[i].split("=");
					switch(x[0].toUpperCase())
					{
						case "HEIGHT" :
							this.Height=x[1];
							break;
						case "WIDTH" :
							this.Width=x[1];
							break;
						case "FONTSIZE" :
							this.FontSize=x[1];
							break;
						case "ZINDEX" :
							this.ZIndex=x[1];
							break;
						case "ISCHILD" :
							this.IsChild=x[1];
							break;
						case "PARENT" :
							this.Parent=x[1];
							break;
						case "HOST" :
							this.Host=x[1];
							break;
						case "VALUE" :
							this.Value=x[1];
							break;
						case "SUBELEMENTS" :
							this.SubElements=x[1].split(",");
							break;
						case "ENABLEBORDERS" :
							this.EnableBorders=(x[1]=="1");
							break;
					}
				}
			}
		}
		return true;
	}
	this.m_initialized=this.Initialize();

	//
	// - Destructors
	//
	this.Dispose=function()
	{
		var state="";
		//alert("1");
		
		state+="height=" + this.Height;
		state+=";width=" + this.Width;
		state+=";fontSize=" + this.FontSize;
		state+=";zIndex=" + this.ZIndex;
		state+=";isChild=" + ( this.IsChild==true ? "1" : "0" );
		state+=";parent=" + ( this.Parent!=null ? this.Parent : "" );
		state+=";host=" + this.Host;
		state+=";value=" + this.Value;
		var s="";
		//alert("2");
		for(var i=0;i<this.SubElements.length;i+=1)
		{
			if(s!="")
			{
				s+=",";
			}
			s+=this.SubElements[i];
		}
		state+=";subElements=" + s;
		state+=";enableBorders=" + ( this.EnableBorders==true ? "1" : "0" );
		//alert("3");
		//alert(state);
		
		//alert(this.ViewStateField);
		GetBrowserElement(this.ViewStateField).value=state;	
		//alert("4");
	}

	// - Store View State
	// -	This handles the storage of child controls view state information. All child view state
	// -	 information is stored in the very top level parent FormulaWriter control. It is neccesary
	// -	 to store this information outside of the White Board so that it is not lost each time
	// -	 the White Board is redrawn.
	this.StoreViewState=function(control)
	{
		if(GetBrowserElement(control.ViewStateField)==null)
		{
			if(this.Host==ID)
			{
				GetBrowserElement(this.ViewState).innerHTML+=control.RenderViewState();
			}
			else
			{
				var host=new FormulaWriter(this.Host);
				GetBrowserElement(host.ViewState).innerHTML+=control.RenderViewState();
				host.Dispose();
			}
		}
		control.Dispose();
	}

	//
	// - Rendering
	//

	// - Render
	// -	This protocall handles the entire rendering process from start to finished.
	// -	 This process of rendering the entire control is only used by the parent
	// -	 control. All child controls are rendered peices at a time.
	this.Render=function(parentElement)
	{
		GetBrowserElement(parentElement).innerHTML=this.RenderHtml();
		GetBrowserElement(this.ViewState).innerHTML=this.RenderViewState();
		this.Draw();
	}

	// - Render Html
	// -	This renders the html objects, including white board, view state, and
	// -	 operations panel. The Draw() method then performs the logic required
	// -	 to generate the graphical representation of the formula.
	this.RenderHtml=function()
	{
		// - Generate html
		var html='';
		html+='<table border="0" cellpadding="0" cellspacing="2" style="">';
		html+='	<tr>';
		html+='		<td id="' + this.ViewState + '" style="height:1px;"></td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td id="' + this.Operations + '">';
		html+='		' + this.RenderOperationsMenu() + '</td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td >';
		html+='		' + this.RenderWhiteBoard() + '</td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td style="display:none;">';
		html+='		Hidden: <input type="text" id="' + this.Hidden + '" /></td>';
		html+='	</tr>';
		/*
		html+='	<tr>';
		html+='		<td >';
		html+='		Test: <input type="text" id="' + this.Test + '" /></td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td >';
		html+='		Infix: <input type="text" id="' + this.Infix + '" /></td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td >';
		html+='		MathML: <input type="text" id="' + this.Mml + '" /></td>';
		html+='	</tr>';
		html+='	<tr>';
		html+='		<td >';
		html+='		MathML Presentation Code: <input type="text" id="' + this.MmlP + '" /></td>';
		html+='	</tr>';
		*/
		html+='	<tr>';
		html+='		<td style="font-family:arial;font-size:10;color:black;" align="center">';
		html+='		<a id="lnk_preview_' + ID + '" href="javascript:GenericPreview(\'' + ID + '\');" style="color:black;">Preview Answer</a><a id="lnk_format_' + ID + '" href="javascript:GenericFormat(\'' + ID + '\');" style="color:black;display:none;">Format Answer</a></td>';
		html+='	</tr>';
		html+='</table>';

		// return
		return html;
	}

	// - Render Operations
	// -	This generates the drop down menu (Operations Panel) that allows
	// -	 users to select variouse mathematical operations to perform.
	this.RenderOperationsMenu=function()
	{
		var html='';
		html+='<table border="0" cellpadding="1" cellspacing="0" style="">';
		html+='	<tr>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_add" src="pics/add.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_add\',\'pics/addOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opAdd\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_add\',\'pics/add.gif\');javascript:HideGenericObject(\'img_' + ID + '_opAdd\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~a\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opAdd" src="pics/addPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_subtract" src="pics/subtract.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_subtract\',\'pics/subtractOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opSubtract\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_subtract\',\'pics/subtract.gif\');javascript:HideGenericObject(\'img_' + ID + '_opSubtract\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~s\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opSubtract" src="pics/subtractPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_multiply" src="pics/multiply.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_multiply\',\'pics/multiplyOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opMultiply\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_multiply\',\'pics/multiply.gif\');javascript:HideGenericObject(\'img_' + ID + '_opMultiply\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~m\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opMultiply" src="pics/multiplyPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_divide" src="pics/divide.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_divide\',\'pics/divideOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opDivide\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_divide\',\'pics/divide.gif\');javascript:HideGenericObject(\'img_' + ID + '_opDivide\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~d\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opDivide" src="pics/dividePreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_other" src="pics/root.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_other\',\'pics/rootOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opOther\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_other\',\'pics/root.gif\');javascript:HideGenericObject(\'img_' + ID + '_opOther\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~r\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opOther" src="pics/otherPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_squareRoot" src="pics/squareRoot.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_squareRoot\',\'pics/squareRootOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opSquareRoot\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_squareRoot\',\'pics/squareRoot.gif\');javascript:HideGenericObject(\'img_' + ID + '_opSquareRoot\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~R\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opSquareRoot" src="pics/squareRootPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">';
		html+='		<img id="img_' + ID + '_power" src="pics/power.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_power\',\'pics/powerOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opPower\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_power\',\'pics/power.gif\');javascript:HideGenericObject(\'img_' + ID + '_opPower\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~p\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opPower" src="pics/powerPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_absoluteValue" src="pics/absoluteValue.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_absoluteValue\',\'pics/absoluteValueOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opAbsoluteValue\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_absoluteValue\',\'pics/absoluteValue.gif\');javascript:HideGenericObject(\'img_' + ID + '_opAbsoluteValue\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~A\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opAbsoluteValue" src="pics/absoluteValuePreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		/* NOT NEEDED
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_ceiling" src="pics/ceiling.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_ceiling\',\'pics/ceilingOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opCeiling\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_ceiling\',\'pics/ceiling.gif\');javascript:HideGenericObject(\'img_' + ID + '_opCeiling\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~c\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opCeiling" src="pics/ceilingPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_floor" src="pics/floor.gif" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_floor\',\'pics/floorOn.gif\');javascript:ShowGenericObject(\'img_' + ID + '_opFloor\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_floor\',\'pics/floor.gif\');javascript:HideGenericObject(\'img_' + ID + '_opFloor\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~f\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_opFloor" src="pics/floorPreview.gif" alt="" style="display:none;position:absolute;" /></p></td>';
		*/
		var _id="";
		var _onImage="";
		var _offImage="";
		var _previewImage="";
		/* NOT NEEDED
		_id="sum1";
		_onImage="sum1On.gif";
		_offImage="sum1.gif";
		_previewImage="sum1Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~U\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="sum2";
		_onImage="sum2On.gif";
		_offImage="sum2.gif";
		_previewImage="sum2Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~S\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="sum3";
		_onImage="sum3On.gif";
		_offImage="sum3.gif";
		_previewImage="sum3Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~u\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		*/
		_id="log1";
		_onImage="log1On.gif";
		_offImage="log1.gif";
		_previewImage="log1Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~l\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="log2";
		_onImage="log2On.gif";
		_offImage="log2.gif";
		_previewImage="log2Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~L\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		// new row
		//
		html+='	</tr>';
		html+='	<tr>';
		//
		// new row
		//
		_id="ln";
		_onImage="lnOn.gif";
		_offImage="ln.gif";
		_previewImage="lnPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~n\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		/* NOT NEEDED
		_id="limit";
		_onImage="limOn.gif";
		_offImage="lim.gif";
		_previewImage="limPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~M\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="product1";
		_onImage="product1On.gif";
		_offImage="product1.gif";
		_previewImage="product1Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~P\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="product2";
		_onImage="product2On.gif";
		_offImage="product2.gif";
		_previewImage="product2Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~D\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		*/
		//
		_id="equal";
		_onImage="equalOn.gif";
		_offImage="equal.gif";
		_previewImage="equalsPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~e\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		_id="notEqual";
		_onImage="notEqualOn.gif";
		_offImage="notEqual.gif";
		_previewImage="notEqualPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~1\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="greaterThan";
		_onImage="greaterThanOn.gif";
		_offImage="greaterThan.gif";
		_previewImage="greaterThanPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~g\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="greaterThanEqual";
		_onImage="greaterThanEqualOn.gif";
		_offImage="greaterThanEqual.gif";
		_previewImage="greaterThanEqualPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~G\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="lessThan";
		_onImage="lessThanOn.gif";
		_offImage="lessThan.gif";
		_previewImage="lessThanPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~t\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="lessThanEqual";
		_onImage="lessThanEqualOn.gif";
		_offImage="lessThanEqual.gif";
		_previewImage="lessThanEqualPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~T\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="approximately";
		_onImage="approximatelyOn.gif";
		_offImage="approximately.gif";
		_previewImage="approximatelyPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~&\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="pi";
		_onImage="piOn.gif";
		_offImage="pi.gif";
		_previewImage="piPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~^\');" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		/*
		//
		_id="equivilent";
		_onImage="equivilentOn.gif";
		_offImage="equivilent.gif";
		_previewImage="equivilentPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~E\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="factorOf";
		_onImage="factorOfOn.gif";
		_offImage="factorOf.gif";
		_previewImage="factorOfPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:GenericAddOperation(\'' + this.Host + '\',\'~F\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="in";
		_onImage="inOn.gif";
		_offImage="in.gif";
		_previewImage="inPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="notIn";
		_onImage="notInOn.gif";
		_offImage="notIn.gif";
		_previewImage="notInPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="prSubset";
		_onImage="prSubsetOn.gif";
		_offImage="prSubset.gif";
		_previewImage="prSubsetPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="subset";
		_onImage="subsetOn.gif";
		_offImage="subset.gif";
		_previewImage="subsetPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="notSubset";
		_onImage="notSubsetOn.gif";
		_offImage="notSubset.gif";
		_previewImage="notSubsetPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="notPrSubset";
		_onImage="notPrSubsetOn.gif";
		_offImage="notPrSubset.gif";
		_previewImage="notPrSubsetPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="intersect";
		_onImage="intersectOn.gif";
		_offImage="intersect.gif";
		_previewImage="intersectPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="union";
		_onImage="unionOn.gif";
		_offImage="union.gif";
		_previewImage="unionPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="emptySubset";
		_onImage="emptySubsetOn.gif";
		_offImage="emptySubset.gif";
		_previewImage="emptySubsetPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="interval1";
		_onImage="interval1On.gif";
		_offImage="interval1.gif";
		_previewImage="interval1Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="interval2";
		_onImage="interval2On.gif";
		_offImage="interval2.gif";
		_previewImage="interval2Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="interval3";
		_onImage="interval3On.gif";
		_offImage="interval3.gif";
		_previewImage="interval3Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		html+='	<tr>';
		html+='	</tr>';
		//
		_id="interval4";
		_onImage="interval4On.gif";
		_offImage="interval4.gif";
		_previewImage="interval4Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="setDif";
		_onImage="setDifOn.gif";
		_offImage="setDif.gif";
		_previewImage="setDifPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="cartesianProduct";
		_onImage="cartesianProductOn.gif";
		_offImage="cartesianProduct.gif";
		_previewImage="cartesianProductPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="card";
		_onImage="cardOn.gif";
		_offImage="card.gif";
		_previewImage="cardPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="alpha";
		_onImage="alphaOn.gif";
		_offImage="alpha.gif";
		_previewImage="alphaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="beta";
		_onImage="betaOn.gif";
		_offImage="beta.gif";
		_previewImage="betaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="gamma";
		_onImage="gammaOn.gif";
		_offImage="gamma.gif";
		_previewImage="gammaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="delta";
		_onImage="deltaOn.gif";
		_offImage="delta.gif";
		_previewImage="deltaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="straightEpsilon";
		_onImage="straightEpsilonOn.gif";
		_offImage="straightEpsilon.gif";
		_previewImage="straightEpsilonPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="eta";
		_onImage="etaOn.gif";
		_offImage="eta.gif";
		_previewImage="etaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="theta";
		_onImage="thetaOn.gif";
		_offImage="theta.gif";
		_previewImage="thetaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="lambda";
		_onImage="lambdaOn.gif";
		_offImage="lambda.gif";
		_previewImage="lambdaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="mu";
		_onImage="muOn.gif";
		_offImage="mu.gif";
		_previewImage="muPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="rho";
		_onImage="rhoOn.gif";
		_offImage="rho.gif";
		_previewImage="rhoPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="sigma";
		_onImage="sigmaOn.gif";
		_offImage="sigma.gif";
		_previewImage="sigmaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="straightPhi";
		_onImage="straightPhiOn.gif";
		_offImage="straightPhi.gif";
		_previewImage="straightPhiPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="omega";
		_onImage="omegaOn.gif";
		_offImage="omega.gif";
		_previewImage="omegaPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="psi";
		_onImage="psiOn.gif";
		_offImage="psi.gif";
		_previewImage="psiPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="infinity";
		_onImage="infinityOn.gif";
		_offImage="infinity.gif";
		_previewImage="infinityPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		html+='	</tr>';
		html+='	<tr>';
		//
		_id="matrix1";
		_onImage="matrix1On.gif";
		_offImage="matrix1.gif";
		_previewImage="matrix1Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="matrix2";
		_onImage="matrix2On.gif";
		_offImage="matrix2.gif";
		_previewImage="matrix2Preview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		//
		_id="vector";
		_onImage="vectorOn.gif";
		_offImage="vector.gif";
		_previewImage="vectorPreview.gif";
		html+='		<td class="text" align="center">'
		html+='		<img id="img_' + ID + '_' + _id + '" src="pics/' + _offImage + '" alt="" onmouseover="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _onImage + '\');javascript:ShowGenericObject(\'img_' + ID + '_op' + _id + '\');" onmouseout="javascript:SwapGenericImage(\'img_' + ID + '_' + _id + '\',\'pics/' + _offImage + '\');javascript:HideGenericObject(\'img_' + ID + '_op' + _id + '\');" onclick="javascript:Power(\'' + ID + '\');" style="cursor:pointer;" />';
		html+='		<p style="margin:0px 0px 0px 0px;height:1px;"><img id="img_' + ID + '_op' + _id + '" src="pics/' + _previewImage + '" alt="" style="display:none;position:absolute;" /></p></td>';
		*/
		//
		html+='		<td colspan="1"></td>';
		html+='	</tr>';
		html+='</table>';
		return html;
	}
	
	// - Render ViewState
	// -	This section is essential to storing the data associated with this control.
	// -	 The ViewState keeps track of a number of important criteria:
	// -		- Formula - a text-only version of the formula
	// -		- CursorIndex, CursorCounter - handle the cursors blinking
	// -		- Active - "1" if this control is in focus, "0" otherwise
	// -		- Parent - keeps track of the parent control if this control is nested
	this.RenderViewState=function()
	{
		var html='<input type="hidden" id="' + this.ViewStateField + '" value="" />';
		html+='<input type="hidden" id="' + this.CursorIndex + '" value="0" />';
		html+='<input type="hidden" id="' + this.CursorCounter + '" value="0" />';
		if(GetBrowserElement("txt_activeFormulaWriter_" + this.Host)==null)
		{
			html+='<input type="hidden" id="txt_activeFormulaWriter_' + this.Host + '" value="' + ID + '" />';
		}
		return html;
	}
	
	// - Render White Board
	// -	This renders the div area termed "White Board", this is the area where the graphical
	// -	 representation of the formula is drawn. The drawing of the formula into this White
	// -	 Board object is handled by the Draw() method.
	this.RenderWhiteBoard=function()
	{
		// - Generate html
		var html='<div id="' + this.WhiteBoard + '" onkeypress="javascript:GenericType(\'' + ID + '\',event);" onkeydown="javascript:GenericDown(\'' + ID + '\',event);" valign="bottom" style="';
		html+='white-space:nowrap;overflow:show;z-index:' + this.ZIndex + ';padding:1px 1px 1px 1px;margin:0px 0px 0px 0px;height:' + this.Height + ';width:' + this.Width + ';';
		html+='border-style:solid;border-width:1px;border-color:blue;cursor:text;background-color:white;font-family:arial,courier,courier new;font-size:13px;color:black;';
		html+='" onclick="javascript:GenericSetFocus(\'' + ID + '\');" onblur="javascript:GenericBlur(\'' + ID + '\');"></div>';
		return html;
	}
	
	//
	// - Retreive Value
	//
	this.ToString=function()
	{
		//TODO formulaWriter.ToString()
	}
	
	// - Draw Formula
	// -	This handles creating the graphical representation of the formula. It reads
	// -	 the value of the 'this.Value' textbox, which stores a textual representation
	// -	 of the formula. It then redraws the formula each time the formula is modified
	// -	 or added to. It replaces special characters (such as ~,!,@,#, and $)  with
	// -	 formations of textboxes arranged to represent a mathematical operation.
	this.Draw=function()
	{
		var html="";
		
		// - Render Html
		html+='<table border="0" cellpadding="0" cellspacing="0">';
		html+='	<tr>';
		
		var subElements=new Array();
		var cursorSet=false;
		var text=this.Value;
		var len=text.length;
		text=text.replace("~n","ln(~n)");
		/*
		text=text.replace("~&","?");
		text=text.replace("","");
		text=text.replace("?","~");
		*/
		var newLen=text.length;
		GetBrowserElement(this.CursorIndex).value=parseInt(GetBrowserElement(this.CursorIndex).value) + (newLen-len);
		
		for(var i=0;i<text.length;i+=1)
		{
			//alert("2.1");
			//get character
			var car=text.substr(i,1);
			if(car=="~")
			{
				i+=1;
				car+=text.substr(i,1);
			}
			
			//cursor
			if(String(i)==GetBrowserElement(this.CursorIndex).value || ( i-1==0 && "0"==GetBrowserElement(this.CursorIndex).value ) )
			{
				cursorSet=true;
				sHtml='<span id="' + this.Cursor + '" style="display:none;font-size:11;">&#124;</span>';
				sHtml+='<img id="' + this.CursorHelper + '" src="pics/blank.gif" alt="" width="2" />';
				html+='<td valign="middle">';
				html+=sHtml;
				html+='</td>';
			}
			
			//formula
			html+='<td style="font-size:13px;" valign="middle">';
			/*
			if(car=="(")
			{
				html+=OpenParenthesis();
			}
			else if(car==")")
			{
				html+=CloseParenthesis();
			}
			else */if(car=="~a")
			{
				//ADDITION
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		+</td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~^")
			{
				//PI
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/piOperation.gif" alt="" /></td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~s")
			{
				//SUBTRACTION
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		-</td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="*")
			{
				//MULTIPLICATION SYMBOL
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/smbl_multiply.bmp" alt="" /></td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~m")
			{
				//MULTIPLICATION
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/smbl_multiply.bmp" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~d")
			{
				//DIVISION
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;border-bottom-style:solid;border-bottom-width:2px;border-bottom-color:black;" align="center">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='</tr>';
				html+='<tr>';
				html+='		<td style="white-space:nowrap;" align="center">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~r")
			{
				//ROOT
				html+='<table border="0" cellpadding="0" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td width="18" rowspan="2">';
				//html+='		&nbsp;</td>';
				html+='		<img src="pics/middleBracket.gif" alt="" height="45" width="18" /></td>';
				html+='		<td style="background-image:url(pics/topBracket.gif);background-repeat:repeat-x;">';
				html+='		<img src="pics/blank.gif" height="5" alt="" /></td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td align="right" valign="bottom">';
				html+='		<img src="pics/bottomBracket.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~p")
			{
				//POWER
				html+='<table border="0" cellpadding="0" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/blank.gif" alt="" height="5" /></td>';
				html+='		<td rowspan="2" style="white-space:nowrap;" valign="top">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~A")
			{
				//ABSOLUTE VALUE
				html+='<table border="0" cellpadding="0" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/absoluteValueOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td>';
				html+='		<img src="pics/absoluteValueOperator.gif" alt="" /></td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~R")
			{
				//SQUARE ROOT
				html+='<table border="0" cellpadding="0" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;"></td>';
				html+='		<td rowspan="2">';
				html+='		<img src="pics/middleBracket.gif" height="45" width="18" alt="" /></td>';
				html+='		<td style="background-image:url(pics/topBracket.gif);">';
				html+='		<img src="pics/blank.gif" height="5" alt="" /></td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td align="right" valign="bottom">';
				html+='		<img src="pics/bottomBracket.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~c")
			{
				//CEILING
				html+='<table border="0" cellpadding="0" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/ceilingLeft.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td>';
				html+='		<img src="pics/ceilingRight.gif" alt="" /></td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~f")
			{
				//FLOOR
				html+='<table border="0" cellpadding="0" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/floorLeft.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td>';
				html+='		<img src="pics/floorRight.gif" alt="" /></td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~U")
			{
				//SUM (1 VAR)
				html+='<table border="0" cellpadding="2" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/sumOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~S")
			{
				//SUM (2 VAR)
				html+='<table border="0" cellpadding="2" cellspacing="1">';
				html+='	<tr>';
				html+='		<td rowspan="2">';
				html+='		<img src="pics/sumOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/blank.gif" alt="" width="20" height="1" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;" colspan="2">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~u")
			{
				//SUM (3 VAR)
				html+='<table border="0" cellpadding="2" cellspacing="1">';
				html+='	<tr>';
				html+='		<td rowspan="2">';
				html+='		<img src="pics/sumOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td rowspan="2" style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				temp=new FormulaWriter(ID + '_char_' + i + 'C');
				subElements[subElements.length]=ID + '_char_' + i + 'C';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'C-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~l")
			{
				//LOG (1 VAR)
				html+='<table border="0" cellpadding="0" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/logOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~L")
			{
				//LOG (2 VAR)
				html+='<table border="0" cellpadding="0" cellspacing="1">';
				html+='	<tr>';
				html+='		<td rowspan="2">';
				html+='		<img src="pics/logOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/blank.gif" alt="" width="20" height="1" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;" colspan="2">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~n")
			{
				//LN (1 VAR)
				html+='<table border="0" cellpadding="0" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~M")
			{
				//LIMIT
				html+='<table border="0" cellpadding="2" cellspacing="2">';
				html+='	<tr>';
				html+='		<td colspan="3" style="white-space:nowrap;" align="center">';
				html+='		lim</td>';
				html+='		<td rowspan="2" style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/limOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				temp=new FormulaWriter(ID + '_char_' + i + 'C');
				subElements[subElements.length]=ID + '_char_' + i + 'C';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'C-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~P")
			{
				//PRODUCT (1 VAR)
				html+='<table border="0" cellpadding="2" cellspacing="1">';
				html+='	<tr>';
				html+='		<td>';
				html+='		<img src="pics/productOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~D")
			{
				//PRODUCT (3 VAR)
				html+='<table border="0" cellpadding="2" cellspacing="1">';
				html+='	<tr>';
				html+='		<td rowspan="2">';
				html+='		<img src="pics/productOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='		<td rowspan="2" style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				temp=new FormulaWriter(ID + '_char_' + i + 'C');
				subElements[subElements.length]=ID + '_char_' + i + 'C';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'C-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~e")
			{
				//EQUAL
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		&#61;</td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="=")
			{
				//EQUAL SYMBOL
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				html+='		&#61;</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~1")
			{
				//NOT EQUAL
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/notEqualOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~g")
			{
				//GREATER THAN
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/greaterThanOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~t")
			{
				//LESS THAN
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/lessThanOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~G")
			{
				//GREATER THAN / EQUAL TO
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/greaterThanEqualOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~T")
			{
				//LESS THAN / EQUAL TO
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/lessThanEqualOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~&")
			{
				//APPROXIMATELY
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/approximatelyOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else if(car=="~E")
			{
				//EQUIVILENT
				html+='<table border="0" cellpadding="2" cellspacing="0">';
				html+='	<tr>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'A-->';temp=new FormulaWriter(ID + '_char_' + i + 'A');
				subElements[subElements.length]=ID + '_char_' + i + 'A';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'A-->';temp=null;
				// **** end create sub element
				html+='		</td>';
				html+='		<td style="white-space:nowrap;">';
				html+='		<img src="pics/equivilalentOperator.gif" alt="" /></td>';
				html+='		<td style="white-space:nowrap;">';
				// **** begin create sub element
				html+='<!--BEGIN WRITER ' + ID + '_char_' + i + 'B-->';temp=new FormulaWriter(ID + '_char_' + i + 'B');
				subElements[subElements.length]=ID + '_char_' + i + 'B';
				temp.ZIndex=this.ZIndex+1;
				html+=temp.RenderWhiteBoard();
				this.StoreViewState(temp);
				temp.Parent=ID;
				temp.Host=this.Host;
				temp.Dispose();
				html+='<!--END WRITER ' + ID + '_char_' + i + 'B-->';temp=null;
				// **** end create sub element
				html+='</td>';
				html+='	</tr>';
				html+='</table>';
			}
			else
			{
				html+=car;
			}
			html+='</td>';
		}
		if(!cursorSet)
		{
			cursorSet=true;
			sHtml='<span id="' + this.Cursor + '" style="display:none;font-size:11;">&#124;</span>';
			sHtml+='<img id="' + this.CursorHelper + '" src="pics/blank.gif" alt="" width="2" />';
			html+='<td valign="middle">';
			html+=sHtml;
			html+='</td>';
		}
		html+='	</tr>';
		html+='</table>';
		
		// - Cache Sub Elements
		this.SubElements=subElements;
		
		// - Handle Border
		if(this.Host!=ID)
		{
			var h=new FormulaWriter(this.Host);
			if(h.EnableBorders==false)
			{
				GetBrowserElement(this.WhiteBoard).style.border="none";
				GetBrowserElement(this.WhiteBoard).style.width="";
				GetBrowserElement(this.WhiteBoard).style.padding="0px";
				GetBrowserElement(this.WhiteBoard).style.paddingBottom="0px";
			}
			h.Dispose();
		}
		
		// - Set Html
		GetBrowserElement(this.WhiteBoard).innerHTML=html;
		
		// - Draw Children
		for(var j=0;j<subElements.length;j+=1)
		{
			k=new FormulaWriter(subElements[j]);
			k.FontSize=String(parseInt(this.FontSize)-4);
			if(k.FontSize!=36 && k.FontSize!=24)
			{
				k.FontSize=k.FontSize+1;
			}
			k.Draw();
			k.Dispose();
		}
		
		// - Draw Infix
		this.Dispose();
		var host=new FormulaWriter(this.Host);
	//	GetBrowserElement("txt_infix_" + this.Host).value=host.GetInfix();
	//	GetBrowserElement("txt_mml_" + this.Host).value=host.GetMml();
	//	GetBrowserElement("txt_mmlP_" + this.Host).value=host.GetMmlPresentation();
	
		// - Cursor
		GetBrowserElement(this.CursorCounter).value=0;
		this.ShowCursor(0);
	}
	
	//
	// - Methods
	//
	
	// - Handles Focus/Unfocus
	this.Focus=function()
	{
		//handle focus
		GetBrowserElement("txt_activeFormulaWriter_" + this.Host).value=ID;
		GetBrowserElement(this.WhiteBoard).focus();
		
		//handle cursor
		GetBrowserElement(this.CursorCounter).value="0";
		this.ShowCursor(0);
	}
	this.Blur=function()
	{
	}
	
	// - Handle Typing
	this.Type=function(e)
	{
		if(ID==GetFocusedWriter(this.Host))
		{
			//get typed character
			var carCode=((window.event)? window.event.keyCode : e.which);
			var car=GetCharFromCode(carCode);
			//alert(carCode);
			
			//rewrite formula
			var cIndex=parseInt(GetBrowserElement(this.CursorIndex).value);
			var orig=this.Value;
			var first="";
			var last="";
			for(var i=0;i<orig.length;i+=1)
			{
				if(i<cIndex)
				{
					first+=orig.substr(i,1);
				}
				else
				{
					last+=orig.substr(i,1);
				}
			}
			//alert("start=" + first);
			//alert("char=" + car);
			//alert("end=" + last);
			this.Value=first + car + last;
			
			cIndex+=1;
			GetBrowserElement(this.CursorIndex).value=cIndex;
			
			//draw formula
			this.Draw();
			this.Focus();
		}
	}
	
	// - AbnormalType
	// -	This is for backspace and arrow buttons which dont fire the onkeypress event
	this.AbnormalType=function(e)
	{
		if(ID==GetFocusedWriter(this.Host))
		{
			var carCode=((window.event)? window.event.keyCode : e.which);
			var cIndex=parseInt(GetBrowserElement(this.CursorIndex).value);
			var orig=this.Value;
			var first="";
			var last="";
			for(var i=0;i<orig.length;i+=1)
			{
				if(i<cIndex)
				{
					first+=orig.substr(i,1);
				}
				else
				{
					last+=orig.substr(i,1);
				}
			}
			if(carCode==8)
			{
				//backspace
				if(cIndex!=0)
				{
					first=first.substr(0,first.length-1);
					if(first.substr(first.length-1)=="~")
					{
						if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "A")!=null)
						{
							GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "A").value="";
						}
						if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "B")!=null)
						{
							GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "B").value="";
						}
						if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "C")!=null)
						{
							GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex-1) + "C").value="";
						}
						
						first=first.substr(0,first.length-1);
						cIndex-=1;
					}
					this.Value=first+last;
					cIndex-=1;
				}
			}
			else if(carCode==46)
			{
				//delete
				//alert("Match: " + last.substr(0,1));
				if(last.substr(0,1)=="~")
				{
					last=last.substr(2);
					
					if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "A")!=null)
					{
						GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "A").value="";
					}
					if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "B")!=null)
					{
						GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "B").value="";
					}
					if(GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "C")!=null)
					{
						GetBrowserElement("txt_viewState_" + ID + "_char_" + (cIndex+1) + "C").value="";
					}
				}
				else
				{
					last=last.substr(1);
				}
				this.Value=first+last;
			}
			else if(carCode==37)
			{
				//nav left
				if(cIndex!=0)
				{
					cIndex-=1;
					if(this.Value.substr(cIndex-1,1)=="~")
					{
						cIndex-=1;
					}
				}
			}
			else if(carCode==39)
			{
				//nav right
				if(this.Value.substr(cIndex,1)=="~")
				{
					cIndex+=1;
				}
				if(cIndex<this.Value.length)
				{
					cIndex+=1;
				}
			}
			GetBrowserElement(this.CursorIndex).value=cIndex;
			
			//draw formula
			this.Draw();
			this.Focus();
		}
	}
	
	// - Apend Writer
	// -	This is the method that handles the insertion of special characters (the operations
	// -	 selected from the Operations Panel). Each operation in the Operations Panel is assigned
	// -	 a special character - such as a ~ to represent a addition operation. It simply appends
	// -	 the special character into the existing formula, then when the Draw() method finds
	// -	 the character it replaces it with it's associated operation.
	this.AppendWriter=function(operation)
	{
		if(ID==GetFocusedWriter(this.Host))
		{
			var cIndex=parseInt(GetBrowserElement(this.CursorIndex).value);
			var orig=this.Value;
			var first="";
			var last="";
			for(var i=0;i<orig.length;i+=1)
			{
				if(i<cIndex)
				{
					first+=orig.substr(i,1);
				}
				else
				{
					last+=orig.substr(i,1);
				}
			}
			this.Value=first + operation + last;
			
			cIndex+=2;
			GetBrowserElement(this.CursorIndex).value=cIndex;
			
			//draw
			this.Draw();
			this.Focus();
		}
	}
	
	// - GetValue()
	// -	Returns the FormulaWriter viewstate
	this.GetValue=function()
	{
		return GetBrowserElement("td_viewState_" + this.Host).innerHTML;
	}
	
	// - SetValue()
	// -	Sets the FormulaWriter viewstate
	this.SetValue=function(val)
	{
		GetBrowserElement("td_viewState_" + this.Host).innerHTML=val;
		//alert(GetBrowserElement("txt_viewState_div_question_10").value);
		//this.Dispose();
		this.Initialize();
		this.Index=this.Value.length;
		//alert(this.Index);
		this.Draw();
	}
	
	// - GetInfix()
	// -	Returns the infix for this control
	this.GetInfix=function()
	{
		var retval="";
		
		var val=this.Value;
		//alert(val);
		for(var j=0;j<val.length;j+=1)
		{
			var car=val.substr(j,1);
			//alert(car);
			if(car=="~")
			{
				//it is an operation
				j+=1;
				car+=val.substr(j,1);
				var aBox=null;
				var bBox=null;
				var cBox=null;
				
				for(var z=0;z<this.SubElements.length;z+=1)
				{
					if(z==0)
						aBox=new FormulaWriter(this.SubElements[z]);
					else if(z==1)
						bBox=new FormulaWriter(this.SubElements[z]);
					else if(z==2)
						cBox=new FormulaWriter(this.SubElements[z]);
				}
				
				//ADDITION
				if(car=="~a")
				{
					retval+=aBox.GetInfix() + "+" + bBox.GetInfix();
				}
				//SUBTRACTION
				else if(car=="~s")
				{
					retval+=aBox.GetInfix() + "-" + bBox.GetInfix();
				}
				//MULTIPLICATION
				else if(car=="~m")
				{
					retval+=aBox.GetInfix() + "*" + bBox.GetInfix();
				}
				//DIVISION
				else if(car=="~d")
				{
					retval+=aBox.GetInfix() + "/" + bBox.GetInfix();
				}
				//POWER
				else if(car=="~p")
				{
					var inf=aBox.GetInfix().length;
					
					retval+=bBox.GetInfix() + "^";
					if(inf.length>1)
					{
						retval+="(";
					}
					retval+=inf;
					if(inf.length>1)
					{
						retval+=")";
					}
				}
				//ABSOLUTE VALUE
				else if(car=="~A")
				{
					retval+="abs(" + aBox.GetInfix() + ")";
				}
				//SQUARE ROOT
				else if(car=="~R")
				{
					retval+="sqrt(" + aBox.GetInfix() + ")";
				}
				//EQUALS
				else if(car=="~e")
				{
					retval+=aBox.GetInfix() + "=" + bBox.GetInfix();
				}
				//NOT EQUAL
				else if(car=="~1")
				{
					retval+=aBox.GetInfix() + "neq" + bBox.GetInfix();
				}
				//GREATER THAN
				else if(car=="~g")
				{
					retval+=aBox.GetInfix() + ">" + bBox.GetInfix();
				}
				//LESS THAN
				else if(car=="~t")
				{
					retval+=aBox.GetInfix() + "<" + bBox.GetInfix();
				}
				//ROOT
				else if(car=="~r")
				{
					retval+="root(" + aBox.GetInfix() + "," + bBox.GetInfix() + ")";
				}
			}
			else
			{
				//it is a character
				retval+=car;
			}
		}
		
		return retval;
	}
	
	// - GetMml()
	// -	Returns the MathML for this control
	this.GetMml=function()
	{
		SetNameSpace("mml");
		var infix=this.GetInfix();
		var retval="";
		if(infix!="")
		{
			retval=convertToMathMLDOM(infix);
		}
		return retval;
	}
	
	// - GetMmlPresentation
	// -	Returns MathML presentation code
	this.GetMmlPresentation=function()
	{
		SetNameSpace("mml");
		var infix=this.GetInfix();
		var mmlDom="";
		if(infix!="")
		{
			mmlDom=convertToMathMLDOM(infix);
		}
		var retval="";
		if(mmlDom!="")
		{
			retval=GetMathMLEx(mmlDom);
		}
		return retval;
	}
	
	// - Cursor
	this.ShowCursor=function(count)
	{
		try
		{
			//GetBrowserElement(this.Test).value=GetBrowserElement(this.CursorCounter).value + "==" + count;
			//GetBrowserElement(this.Test).value+=" && ";
			//GetBrowserElement(this.Test).value+="( " + GetBrowserElement("txt_activeFormulaWriter_" + this.Host).value + "==" + ID + " )";
			GetBrowserElement(this.WhiteBoard).style.backgroundColor="#dddddd";
			if((parseInt(GetBrowserElement(this.CursorCounter).value)==count) && ( GetBrowserElement("txt_activeFormulaWriter_" + this.Host).value==ID) && document.activeElement.id==this.WhiteBoard)
			{
				GetBrowserElement(this.CursorCounter).value=parseInt(GetBrowserElement(this.CursorCounter).value)+1;
				GetBrowserElement(this.Cursor).style.display="";
				GetBrowserElement(this.CursorHelper).style.display="none";
				window.setTimeout("GenericHideCursor('" + ID + "'," + GetBrowserElement(this.CursorCounter).value + ")",600);
			}
			else
			{
				this.HideCursor(parseInt(GetBrowserElement(this.CursorCounter).value));
			}
		}
		catch(e)
		{
			window.setTimeout("GenericShowCursor('" + ID + "'," + GetBrowserElement(this.CursorCounter).value + ")",600);
		}
	}
	this.HideCursor=function(count)
	{
		try
		{
			GetBrowserElement(this.WhiteBoard).style.backgroundColor="#ffffff";
			if(parseInt(GetBrowserElement(this.CursorCounter).value)==count)
			{
				GetBrowserElement(this.CursorCounter).value=parseInt(GetBrowserElement(this.CursorCounter).value)+1;
				GetBrowserElement(this.Cursor).style.display="none";
				GetBrowserElement(this.CursorHelper).style.display="";
				if(GetBrowserElement("txt_activeFormulaWriter_" + this.Host).value==ID)
				{
					window.setTimeout("GenericShowCursor('" + ID + "'," + GetBrowserElement(this.CursorCounter).value + ")",425);
				}
			}
		}
		catch(e)
		{
			window.setTimeout("GenericHideCursor('" + ID + "'," + GetBrowserElement(this.CursorCounter).value + ")",425);
		}
	}
}