
var temp1=0;
var temp2=0;
var Istimes=0;
var Start = 0;
var End = 0;
var State = 0;
var ErrorCode = 0;
var Expression;
var WORD;
var TList;
var Loc = 0;

function reset() {
  Start = 0;
  End = 0;
  State = 0;
  ErrorCode = 0;
  Loc = 0;
}

function charType(ch)
{
  /* Error = -1   Character = 1  Number = 2  '.' = 3   Operator = 4 Space = 5 */
  if (((ch>='A')&&(ch<='Z'))||((ch>='a')&&(ch<='z'))) return 1;
  if ((ch>='0')&&(ch<='9')) return 2;
  if (ch == '.') return 3;
  if(ch == '&')return 1;
  var ch1=ch.charCodeAt();  
  if((ch1 == 9633) ||(ch1==8734) || (ch1>=945 && ch1<970)) return 1;
  switch (ch) {   
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '=' :
    case '>' :
	case '~' :
    case '<' :
    case ',' :	// Seperator
    case '|' :	// Absolute Value
    case '!' :
    case ';' :
    case '(' :
    case ')' :
    case '[' :	// Array Index Start
    case ']' :	// Array Index End    
    case '{' :
    case '}' :
    case '^' :
	case '#' :
	case '@' :
	case '_' :
              return 4;
    case ' ' :
    case '\t':
    case '\r':
    case '\n':
    case '\f': return 5;
    

    case '_' :
    case ' ' :
    case '$' :
    case '%' :
    case '&' :
             return 1;
    default: return -1;
  }
}

function JointOPER(str)
{
	switch (str) {
		case "==" :
		case ">=" :
		case "<=" :
		case "!=" : return true;
		default   : return false;
	}
}

function getToken(str) {
  State = 0;
  ErrorCode = 0;
  var token;
  var T;
  while ( End < str.length )
  {
  	
  	T = charType(str.charAt(End));
  	if (T < 1)
  	{
      	return "";
  	 }
  	switch (State) 
  	{
  		case 0:	// Initial State
  		{		  	
  			switch (T) {
  				case 1:	// Character
  					State = 1;
  					End++;
  					break;
  				case 2:
  					State = 2;
  					End++;
  					break;
  				case 3:
  					State = 3;
  					End++;
  					break;
  				case 4:
  					State = 4;
  					End++;
  					break;
  				case 5:
  					End++;
  					Start = End;
  			}
  		 }
  		  break;
  		case 1:	// Previous Character
  		  {
 
  		  	switch (T)  
  		  	{
  		  		case 1:
  		  		case 2: 
  		  			End++; 
   		  			break;  		  			
  		  	  case 3: 
  		  		{
  		  				if(charType(str.charAt(End+1))==3)
  		  				{
  		  					token = str.substr(Start, End-Start);
  		  			    Start = End;    		  			   
  		  			   return token;
  		  		  	}
  		  		    else
  		  			  {	 
  		  				State = 3;   		  			
  		  			  End++; 
  		  		    }
  		  		} break;
  		  		default:
  		  			token = str.substr(Start, End-Start);
  		  			Start = End;  		  		
  		  			return token;
  		  	}
  	    }
 		  		  		  	 		  
  		  break;
  		case 2:	// Previous Number
  		{  
  		  	switch (T)  
  		  	{
  		  		case 1:
  		  		  Istimes=1;
  		  		  token = str.substr(Start, End-Start);
  		  			Start = End;
  		  			return token;
  		  		case 2: 
  		  			End++; 
  		  			break;  		  			
  		  	  case 3: 
  		  		{
  		  				if(charType(str.charAt(End+1))==3)
  		  				{
  		  					token = str.substr(Start, End-Start);
  		  			    Start = End;    		  			   
  		  			   return token;
  		  		  	}
  		  		    else
  		  			  {	 
  		  				State = 3;   		  			
  		  			  End++; 
  		  		    }
  		  		} break;
  		  		default:
  		  			token = str.substr(Start, End-Start);
  		  			Start = End;
  		  			tokenNext=str.substr(End,1);
  		  			if(tokenNext=="(")
  		  			 Istimes=1;
  		  			return token;
  		  	}
  	   }
  		 break;
  		case 3:	// Previous '.'
  		  {
  		  	switch (T) 
  		  	{
  		  		case 1:
  		  	 
  		  	    token = str.substr(Start, End-Start);
  		  			Start = End;
  		  			return token; 		  	   
  		  	
  		  		
  		  	 case 2:
  		  	  {
  		  	  	if(charType(str.charAt(End-2))==3)
  		  		  {
  		  			   token = str.substr(Start, End-Start);
  		  		     Start = End;   		  		  
  		  			   return token;
  		  		  }
  		  	  else
  		  		  {	
  		  		  State = 2;
  		  		  End++;
  		  	   }
  		  	 }break;
  		  	case 3:  		  	
  		  	   token = str.substr(Start, End-Start);
  		  		 Start = End;
  		  		 return token;
  		  	   break;
  		   case 4:		  	
  		  	   token = str.substr(Start, End-Start);
  		  		 Start = End;
  		  		 return token;
  		  	   break;
  		  	default:
  		  		return "";
  		  	
  		  }
  		}
  		  break;
  		case 4:	// Previous Operator
  		{
  		  	if (T == 4) 
  		  	{
  		  		var tmpOper = str.substr(Start, End-Start+1);
  		 
  		  		if (JointOPER(tmpOper)) {
  		  		 
  		  		  End++;
  		  		  token = str.substr(Start, End-Start);
  		  		  Start = End;
  		  		  return token;
  		  		}
  		  	}
		  	 token = str.substr(Start, End-Start);
  		  	Start = End;
  		  	return token;
  		  }
  		  break;
  		default:
  
      		return "";
  	}
  }  // End of While
  token = str.substr(Start, End-Start);
  Start = End;
  return token;
}

function TokenRecord(str, s) {
	this.token = str;
	this.state = s;
}

function isReservedFunc(str)
{
	var tmp = str.toLowerCase();
	switch (str) {
		case "sin"  :
		case "cos"  :
		case "tan"  :
		case "sec"   :
		case "csc"   :
		case "cot"   :
		case "sinh"   :
		case "cosh"   :
		case "tanh"   :
		case "sech"   :
		case "csch"   :
		case "coth"   :
		case "arcsin" :
		case "arccos" :
		case "arctan" :
		case "arccosh" :
		case "arccot"   :
		case "arccoth"   :
		case "arccsc"   :
		case "arccsch"   :
		case "arcsec"  :
		case "arcsech"   :
		case "arcsinh"  :
		case "arctanh"  :
		case "exp"  :
		case "log"  :
		case "ln"   :
		case "log"  :
		case "root" :
		case "abs" :
		case "not" :
		case "sum" :
		case "card" :
		case "exists" :
		case "forall" :
		case "sqrt" :
		case "limit" :
		case "product" :
		case "diff" :
		case "partialdiff" :
		case "int" :
		case "vector"   :
		case "matrix"  :
		case "interval" : return true;

	}
	return false;
}

function isSetFunc(str)
{
	var tmp = str.toLowerCase();
	switch (str) {
		case "and"  :
		case "or"  :
		case "xor"  :
		case "implies"   :
		case "union"   :
		case "intersect"   :
		case "notsubset"   :
		case "notprsubset"   :
		case "subset"   :
		case "prsubset"   :
		case "in"   :
		case "notin"   :
	  case "setdiff"   :
	  case "cartesianproduct":
		 return true;

	}
	return false;
}
function isReservedConst(str)
{
	var tmp = str.toUpperCase();
	switch (str) {
		case "PI" :
		case "E"  :
		case "I"  : 
		case "GAMMA" :
		case "INF" :
		case "AL" :
		case "BE" :
		case "GA" :
		case "DE" :
		case "ES" :
			return true;
	}
	return false;
}

function getPriority(OPT)
{
	switch (OPT) {
		case "~" :	// Special Negative Operator '-'
			return 9;
	case "_" : 
	       return 2;
	case "+" :
	case "-" :
	    	return 3;
    case "*" :
    case "#" :
	case "@" :
	    return 4;
	case "/" :
    	return 5;
   	case "^" :	
   	  return 6;
    case "(" :
    	return 7;
    case ")" :
    	return 8;
    case "=" :
    case ">" :
    case "<" :
	case ">=" :
	case "<=" :
	case "!=" :
			return 1;
    case "[" :	
    case "]" :	
    case "," :	
    case "|" :	
    case ";" :	return 0;
	}
}

function Compare(Left, Right)
{ 
	var l = getPriority(Left);
	var r = getPriority(Right);
	
	if (r == 0) return 2;	// ENd of expression
	if (r == 7) return 1;	// OPT, '('
	if (r == 8) return 2;	// OPT, ')'
	if (l == 7) return 1;	// '(', OPT
	if (l == 8) return 2;	// ')', OPT
	if (r > l) return 1;	// OPT, OPT
	else return 2;
}
function createElement1(xmlDoc1,element1)
{
	var mmlns  = "http://www.w3.org/1998/Math/MathML";
	var mml="mml:";
	if(getOs()==1)
	{
		var element2=mml+element1;
		return xmlDoc1.createElement(element2);
	}else
	{
		return xmlDoc1.createElementNS(mmlns,element1);
	}	
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

function mathml(xmlDoc)
{
	var OPRD = new Array();
	var OPER = new Array();
	var Last = 0;
	var Node;
	var Text;
	var Current;
	var subNode;
	var WORD;
	while ((Loc < TList.length)&&(ErrorCode >= 0)) {
		WORD = TList[Loc].token;
		State = TList[Loc].state;
		switch (State) {
			case 1:	// Token is string
				if ( ((Loc+1) < TList.length) && ((TList[Loc+1].token == "(" )||(TList[Loc+1].token == "[" )) ) {	//Function Name?
					Current = createElement1(xmlDoc,"mrow");
					
					switch (WORD.toLowerCase())
					 {
		        case "root" :
							Node = createElement1(xmlDoc,"mroot");
							
							//OPER.push(TList[Loc+1]);	// Push '(' to OPER Stack
							Loc = Loc + 2;				// Bypass '('
							subNode = mathml(xmlDoc);
							Loc=Loc+1;
							subNode1=mathml(xmlDoc);
							Node.appendChild(subNode);
							Node.appendChild(subNode1);
							Current.appendChild(Node);
							break;
						case "sqrt" :
							Node = createElement1(xmlDoc,"msqrt");
							Loc = Loc + 2;
							subNode = mathml(xmlDoc);
							Node.appendChild(subNode);
							Current.appendChild(Node);
							break;
				    case "matrix":
					  {   Node = createElement1(xmlDoc,"mfenced");
					      var MNode = createElement1(xmlDoc,"mtable");
					      Loc = Loc + 3;					   
					      while(Loc < TList.length-2 )					    
					         {
					         	 if( TList[Loc].token == "[" )							  									
							       var  TNode = createElement1(xmlDoc,"mtr");
					        	Loc++;
					         	do 
					         	{
					   	       var  DNode = createElement1(xmlDoc,"mtd");
						         var   subNode = mathml(xmlDoc);
						         DNode.appendChild(subNode);
						         TNode.appendChild(DNode)
						         Loc++; 
						        }	while(TList[Loc-2].token != "]" );						    							 
						       MNode.appendChild(TNode);				  					   
					  	}	
					  	Node.appendChild(MNode);
					  	Current.appendChild(Node);				  	
					  }
					  break;
					  case "interval" :
					  {					  	
							Node = createElement1(xmlDoc,"mfenced");
							
							
						  if( TList[TList.length-2].token == "]")
						    {
							  Node.setAttribute("close","]");							
							  }
						  if(TList[Loc+1].token == "[" )
					  	 {
							 Node.setAttribute("open","[");
						
						  	}					
					    if((TList[Loc+1].token == "[") &&(TList[TList.length-2].token == "]"))
					    	{
							   Node.setAttribute("close","]");	
							   Node.setAttribute("open","[");
							 }
							 Loc=Loc+2;
			
							while((Loc+1) < TList.length-1 )
						   {
					    	subNode = mathml(xmlDoc);
							  Node.appendChild(subNode);							  
						    Loc++;
					      }	
					      Current.appendChild(Node);							 																												
					   }
						 break;
						 case "diff" :						
							{					  
						  Node = createElement1(xmlDoc,"mfrac");							
							Loc = Loc + 2;
							var msubNode = mathml(xmlDoc);
							
							
							var PNode=createElement1(xmlDoc,"mrow");
							var vNode=createElement1(xmlDoc,"mo");
							Text = xmlDoc.createTextNode("d")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
							Node.appendChild(PNode);
							Loc++;
							var PNode=createElement1(xmlDoc,"mrow");
							var vNode=createElement1(xmlDoc,"mo");
							Text = xmlDoc.createTextNode("d")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
						  subNode = mathml(xmlDoc);
						  PNode.appendChild(subNode);
						  Node.appendChild(PNode);						 
							Current.appendChild(Node);
							Current.appendChild(msubNode);
					  	}
							break;	
						
						 case	"partialdiff" :
							{	
					 	 Node = createElement1(xmlDoc,"mfrac");							
							Loc = Loc + 2;
							var msubNode = mathml(xmlDoc);
							
							
							var PNode=createElement1(xmlDoc,"mrow");
							var vNode=createElement1(xmlDoc,"mo");
							Text = xmlDoc.createTextNode("\u2202")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
							Node.appendChild(PNode);
							Loc++;
							var PNode=createElement1(xmlDoc,"mrow");
							var vNode=createElement1(xmlDoc,"mo");
							Text = xmlDoc.createTextNode("\u2202")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
						  subNode = mathml(xmlDoc);
						  PNode.appendChild(subNode);
						  Node.appendChild(PNode);						 
							Current.appendChild(Node);
							Current.appendChild(msubNode);			  
					  	}
					  	break;
					  	case "int" :						
							{	
								  
							Loc = Loc + 2;
							if(TList[Loc].token == "int")
							{
							 var temp=1;
							}
							if(temp==1)
							{ 
								var vNode=createElement1(xmlDoc,"mo");
				        var Text2 = xmlDoc.createTextNode("\u222b")
				        vNode.appendChild(Text2);
				        Current.appendChild(vNode);
								var subNode = mathml(xmlDoc);										
        				Current.appendChild(subNode);
								}
							else
							{
						  Node = createElement1(xmlDoc,"mrow");	
							
							var subNode1 = mathml(xmlDoc);						
							Node.appendChild(subNode1);
							Loc++;							
							var vNode=createElement1(xmlDoc,"mo");
							var Text1 = xmlDoc.createTextNode("d")
					    vNode.appendChild(Text1);               
							var subNode2 = mathml(xmlDoc);
	            Node.appendChild(vNode);  
						  Node.appendChild(subNode2);						  
							Loc++;	
							var subNode3 = mathml(xmlDoc);
							if(TList[Loc].token == ".")	
							{									      
							var SNode=createElement1(xmlDoc,"msubsup");					
				      var vNode=createElement1(xmlDoc,"mo");
				      var Text2 = xmlDoc.createTextNode("\u222b");
				      vNode.appendChild(Text2);
				      SNode.appendChild(vNode);
				      SNode.appendChild(subNode3);
				      Loc+=2;
							var subNode = mathml(xmlDoc);							
				      SNode.appendChild(subNode); 
				      }						      				      
							else
							{
							var SNode=createElement1(xmlDoc,"msub");					
				      var vNode=createElement1(xmlDoc,"mo");
				      var Text2 = xmlDoc.createTextNode("\u222b")
				      vNode.appendChild(Text2);
				      SNode.appendChild(vNode);
				      SNode.appendChild(subNode3);	
								}
				      
							Current.appendChild(SNode);
							Current.appendChild(Node);
						 }
					  	}
							break;	
						case "limit" :						
							{	
							 var MNode = createElement1(xmlDoc,"mo");		
					     Text = xmlDoc.createTextNode("lim");
							 MNode.appendChild(Text);	
							 Node=createElement1(xmlDoc,"munder");
							 Node.appendChild(MNode);
					     Loc+=2;
					     
					     var SNode=createElement1(xmlDoc,"mrow");
							 var subNode1 = mathml(xmlDoc);
							 SNode.appendChild(subNode1);		
					     Loc++;	
					     var PNode=createElement1(xmlDoc,"mrow");
							 var subNode2 = mathml(xmlDoc);
							 PNode.appendChild(subNode2);
							 var cNode = createElement1(xmlDoc,"mo");		
					     Text = xmlDoc.createTextNode("\u2192");
							 cNode.appendChild(Text);	 
					     PNode.appendChild(cNode);
					     Node.appendChild(PNode);
					     Loc++;
					     var subNode3 = mathml(xmlDoc);
							 PNode.appendChild(subNode3);
							 Node.appendChild(PNode);
					 	   Current.appendChild(Node);	
						   Current.appendChild(SNode);			
					  	}
							break;	
					  case "log":
					   {
					    	if(TList[Loc+1].token == "[")
					    	{
					      Node = createElement1(xmlDoc,"msub");							
						   	Loc = Loc + 2;						
						  	var vNode=createElement1(xmlDoc,"mo");
						    Text = xmlDoc.createTextNode("log")
					      vNode.appendChild(Text);
					      Node.appendChild(vNode);
					      do 
					      {
						    var PNode=createElement1(xmlDoc,"mrow");
							  var subNode = mathml(xmlDoc);
							  PNode.appendChild(subNode);
				        Node.appendChild(PNode);
						     Loc++; 
						    }	while(TList[Loc+1].token == "]" );	
					      
				        Current.appendChild(Node);
				       
				        var PNode=createElement1(xmlDoc,"mrow");
							  var subNode = mathml(xmlDoc);
							  PNode.appendChild(subNode);
				        Current.appendChild(PNode);				        					      
					    	}	
					    	if(TList[Loc+1].token == "(")
					    	{
					    	Node = createElement1(xmlDoc,"mo");
							  Text = xmlDoc.createTextNode("log");
							  Node.appendChild(Text);
							  Current.appendChild(Node);																											
						    Loc = Loc + 2;				// Bypass '('							 
							  subNode = mathml(xmlDoc);													
							  Current.appendChild(subNode);
					      }			    						    						    						    	
					 	  }	
					  	break;	
					  case  "sum"	:
					    {
					     var	 MNode = createElement1(xmlDoc,"mo");		
					     Text = xmlDoc.createTextNode("\u2211");
							 MNode.appendChild(Text);	
					     Loc+=2;
					     var SNode=createElement1(xmlDoc,"mrow");
							 var subNode1 = mathml(xmlDoc);
							 SNode.appendChild(subNode1);	
							 if(TList[Loc].token == ",")
							 {
							 	Loc++;
							 	var TNode=createElement1(xmlDoc,"mrow");
							  var subNode2 = mathml(xmlDoc);
							  TNode.appendChild(subNode2);	
					
							 	if(TList[Loc].token == ".")
							 	{
							 	 Loc+=2;
							 	 var PNode=createElement1(xmlDoc,"munderover");
							 	 PNode.appendChild(MNode);
							 	 PNode.appendChild(TNode);
							 	 var vNode=createElement1(xmlDoc,"mrow");
							   var subNode3 = mathml(xmlDoc);
							   vNode.appendChild(subNode3);	
							   PNode.appendChild(vNode);
							  }
							  else
							 	{
							 	 
							 	 var PNode=createElement1(xmlDoc,"munder");
							 	 PNode.appendChild(MNode);
							 	 PNode.appendChild(TNode);	
							 	}	
							 	Current.appendChild(PNode);					 	 
						 	}
						  else
						  {
						   Current.appendChild(MNode);		
						  }

							 Current.appendChild(SNode);							
						 }
					   break;	
					  case  "product" :
					   {
					   	var	 MNode = createElement1(xmlDoc,"mo");		
					     Text = xmlDoc.createTextNode("\u220f");
							 MNode.appendChild(Text);	
					     Loc+=2;
					     var SNode=createElement1(xmlDoc,"mrow");
							 var subNode1 = mathml(xmlDoc);
							 SNode.appendChild(subNode1);	
							 
							  if(TList[Loc].token == ",")
							  {
							 	 Loc++;
							 	 var PNode=createElement1(xmlDoc,"munderover");
							 	 PNode.appendChild(MNode);
							 	 var TNode=createElement1(xmlDoc,"mrow");
							   var subNode2 = mathml(xmlDoc);
							   TNode.appendChild(subNode2);
							 	 PNode.appendChild(TNode);
							 	 Loc+=2;
							 	 var vNode=createElement1(xmlDoc,"mrow");
							   var subNode3 = mathml(xmlDoc);
							   vNode.appendChild(subNode3);	
							   PNode.appendChild(vNode);
							 	 Current.appendChild(PNode);						
							  }
						  else
						   {
						   Current.appendChild(MNode);		
						   }

							 Current.appendChild(SNode);							
						 }
					  break;
						default:
							Node = createElement1(xmlDoc,"mi");
							Text = xmlDoc.createTextNode(WORD);
							Node.appendChild(Text);
							Current.appendChild(Node);
							
							Node = createElement1(xmlDoc,"mo");
							Text = xmlDoc.createTextNode("\u2061");
							Node.appendChild(Text);
							Current.appendChild(Node);
							
							Node = createElement1(xmlDoc,"mfenced");
							Loc = Loc + 2;				// Bypass '('
							subNode = mathml(xmlDoc);
							Node.appendChild(subNode);
							//alert(Current.tagName);
							Current.appendChild(Node);
						}
						OPRD.push(Current);			// Push MathNode to Statck
				}
				else 
			  {	// TOken is not Function Name
					if ( isReservedConst(WORD) ) 
					{
						Node = createElement1(xmlDoc,"mi");
						switch (WORD.toUpperCase()) {
								case "PI" :
								Text = xmlDoc.createTextNode("\u03C0");
								break;
							case "AL"  :
								Text = xmlDoc.createTextNode("\u03b1");
								break;
							case "BE"  :
								Text = xmlDoc.createTextNode("\u03b2");
								break;
							case "GA"  :
								Text = xmlDoc.createTextNode("\u03b3");
								break;
							case "DE"  :
								Text = xmlDoc.createTextNode("\u03b4");
								break;
							case "ES"  :
								Text = xmlDoc.createTextNode("\u2205");
								break;
							case "E"  :
								Text = xmlDoc.createTextNode("\u2147");
								break;
							case "I"  :
								Text = xmlDoc.createTextNode("\u2148");
								break;
							case "GAMMA" :
								Text = xmlDoc.createTextNode("\u03B3");
								break;
							case "INF" :
								Text = xmlDoc.createTextNode("\u221E");
								break;
						}
						  Node.appendChild(Text);
	            OPRD.push(Node);
	            Loc++;
					 }  
       	  else if( isSetFunc(WORD)) 
					{	
						var Current = createElement1(xmlDoc,"mrow");	
						var PNode = OPRD.pop();
						Current.appendChild(PNode);
						Node = createElement1(xmlDoc,"mo");
				    switch (WORD.toLowerCase()) 
				    {
					  case "and" :
						Text = xmlDoc.createTextNode("\u2227");
						break;
					  case "or"  :
						Text = xmlDoc.createTextNode("\u2228");
						break;
				 	  case "implies"  :
						Text = xmlDoc.createTextNode("\u2192");
						break;
					  case "xor" :
						Text = xmlDoc.createTextNode("\u22bb");
						break;
					  case "union" :
						Text = xmlDoc.createTextNode("\u222a");
						break;
						case "intersect"   :
						Text = xmlDoc.createTextNode("\u2229");
						break;
            case "notsubset"   :
            Text = xmlDoc.createTextNode("\u2288");
            break;
            case "notprsubset"   :
            Text = xmlDoc.createTextNode("\u2284");
            break;
            case "subset"   :
            Text = xmlDoc.createTextNode("\u2286");
            break;
            case "prsubset"   :
            Text = xmlDoc.createTextNode("\u2282");
            break;
            case "in"   :
            Text = xmlDoc.createTextNode("\u2208");
            break;
   		      case "notin"   :
   		      Text = xmlDoc.createTextNode("\u2209");
						break;
			    	}
				    Node.appendChild(Text);	
				    Current.appendChild(Node);	
				    Loc++;
				    subNode = mathml(xmlDoc);
		  			Current.appendChild(subNode);	
				    
				   	OPRD.push(Current);				
				   
						}
					else
					 {
					 Node = createElement1(xmlDoc,"mi");
					 Text = xmlDoc.createTextNode(WORD);
					 Node.appendChild(Text);
					 //Curent.appendChild(Node);
					OPRD.push(Node);
					Loc++;
					}	
				}
				break;
			case 2:
				Node = createElement1(xmlDoc,"mn");
				Text = xmlDoc.createTextNode(WORD);
				Node.appendChild(Text);
				//Current.appendChild(Node);
				OPRD.push(Node);
				if(charType(TList[Loc+1].token)==1)
				temp1=1;
				Loc++;
				break;
			case 3:
			  {
			    if(TList[Loc+1].token=".")
				  {
					 OPRD.push(Node);	
					 return Node;		
				   }
				  else Loc++;
				  }
				  break;
			case 4:
				if (WORD == "(") {
					Node = createElement1(xmlDoc,"mfenced");
					var EnNode = createElement1(xmlDoc,"mrow");
					Loc++;
					var subNode = mathml(xmlDoc);
					EnNode.appendChild(subNode);
					Node.appendChild(EnNode);
					OPRD.push(Node);
				}
				else {
					var L = OPER.length;
					if (L == 0) 
					{
						if (WORD == ";")
						 {
							Node = OPRD.pop();
							return Node;
						}
							if ((WORD == "{")&&(TList[Loc+1].token == "}")) //suwei 2007-12-17
						 {
							  Node = createElement1(xmlDoc,"mi");
						    Text = xmlDoc.createTextNode("\u2205");
						    Node.appendChild(Text);
							return Node;
						  }
//						 if (WORD == "=") //suwei_20080130
//					   {
//							Node = OPRD.pop();			
//						  return Node;
//					  	}
					  if (WORD == ")") 
						{
							if(Loc==TList.length-2)
								{
										Node = OPRD.pop();
                    return Node;
									}
								else
									{																				
								   	 Node = OPRD.pop();
									   Loc++;
                     return Node;														 		
						       }
						}
						 if (WORD == ",")
						{ if(TList[Loc-1].token == ")"||TList[Loc-1].token == "]")
							 {
							 	Node = OPRD.pop();								  					
						    return Node;
						  	Loc++;
							}
							else
							{							
							   Node = OPRD.pop();								  					
						     return Node;
						  }
						}
			
						if (WORD == "]") 
						{
							 if(Loc==TList.length-2)
								{
										Node = OPRD.pop();
                    return Node;
									}
								else
									{Node = OPRD.pop();
									Loc++;
                   return Node;                   
										}
						}
						if ((OPRD.length == 0)&&(WORD=="-")) {	// Should be modified
							//Node = CreateMathNode("mrow");
							OPER.push("~");
							Loc++;
							//return Node; 
							break;
						}
						else {
							OPER.push(WORD);
							Loc++;
							break;
						}
					}
					var priority = Compare(OPER[L-1], WORD);
					if (priority == 1) {	// High Priority
						OPER.push(WORD);
						Loc++;
					}
					if (priority == 2) {	// Low or equal priority
						Current = createElement1(xmlDoc,"mrow");
						var Action = OPER.pop();
						var Operand;
						var Operand1;
						var Operand2;
						switch (Action) {
							case "~" :
								Operand1 = OPRD.pop();
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("-");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								OPRD.push(Current);
								break;
							case "_" :
		                        Node = createElement1(xmlDoc,"mfrac");
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								//alert(Operand2.firstChild.tagName);
		    					//if(Operand2.firstChild.tagName=="mrow")Operand2=Operand2.firstChild;
		    					//if(Operand1.firstChild.tagName=="mrow")Operand1=Operand1.firstChild;
		    					Node.appendChild(Operand1);
		    					Node.appendChild(Operand2);
		    					Current.appendChild(Node);
		    					OPRD.push(Current);
		    					break;
							case "+" :
								Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("+");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    			case "-" :
		    				Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("-");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
							case "==" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u2261");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    			case "*" :
		    				    Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
						   	Text = xmlDoc.createTextNode("\u2062");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
						case "#" :
		    				    Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u00D7");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
						case "@" :
		    				    Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u00F7");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    			case "/" :
		    					Node = createElement1(xmlDoc,"mfrac");
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
		    					if(Operand2.tagName=="mfenced")Operand2=Operand2.firstChild;
		    					if(Operand1.tagName=="mfenced")Operand1=Operand1.firstChild;
		    					Node.appendChild(Operand1);
		    					Node.appendChild(Operand2);
		    					Current.appendChild(Node);
		    					OPRD.push(Current);
		    					break;
					    	case "^" :	// Power
					    		Node = createElement1(xmlDoc,"msup");
					    		Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								if(Operand2.tagName=="mfenced")Operand2=Operand2.firstChild;
		    					//if(Operand1.firstChild.tagName=="mrow")Operand1=Operand1.firstChild;
		    					Node.appendChild(Operand1);
		    					Node.appendChild(Operand2);
		    					Current.appendChild(Node);
		    					OPRD.push(Current);
		    					break;
					    	/* case "(" : */	// Never handle this
		    				case "=" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("=");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case ">" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode(">");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case "<" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("<");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case "[" :	// Array Index Start
		    				case "]" :	// Array Index End
		    				case "," :	// Seperator
		    				case "|" :
		    				//case "==" :
							case ">=" :
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u2265");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "<=" :
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u2264");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "!=" : 
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = createElement1(xmlDoc,"mo");
								Text = xmlDoc.createTextNode("\u2260");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case ";"  :	// End of expression
						}
					}
				} //End of Else '('
				break;
			default :
				var Empty = xmlDoc.createTextNode(" ");
				return Empty;
		}
	}
	
	var Node = createElement1(xmlDoc,"mrow");
	return Node;
}


function convertToPresentDOM(str,xmlDoc)
{
	Expression = new String(str);
	reset();
	TList = new Array();
	while ((End < Expression.length)&&(ErrorCode >= 0)) {
		WORD = getToken(Expression);
		if (ErrorCode < 0) return "";
		else
		{
		 TList.push( new TokenRecord(WORD, State) );
		 if(Istimes==1)
		 { 	 
		   TList.push( new TokenRecord("*", 4) );
		   Istimes=0;
		 }
		}
	}

	TList.push( new TokenRecord(";", 4) );
	var root = createElement1(xmlDoc,"math");
	var expr = mathml(xmlDoc);
	root.appendChild(expr);
	return root;
}


