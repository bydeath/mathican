/*
	- Global Script File for Math Pass Software
	-	Writen by Chris Green (cgreen9@kent.edu)
	
	- Copyright Protected 2007 - Christopher B. Green
	-	Anyone may use or modify this program as they desire so long as they
	-	don't remove this comment block and provide the program free of charge.

	- This script file contains scripts consumed globally across
	-	the software package.
*/

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