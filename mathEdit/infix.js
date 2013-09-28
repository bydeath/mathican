
var temp1=0;
var temp2=0;
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
  var ch1=ch.charCodeAt();
  if((ch1 == 9633) ||(ch1==8734) || (ch1>=945 && ch1<968))return 1;
  if(ch == '&')return 1;
  switch (ch) {  
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '^' :	// Power
    case '(' :
    case ')' :
    case '=' :
    case '>' :
    case '<' :
    case '[' :	// Array Index Start
    case ']' :	// Array Index End    
    case '{' :
    case '}' :
    case ',' :	// Seperator
    case '|' :	// Absolute Value
    case '!' :
    case ';' :
     	return 4;
    case ' ' :
    case '\t':
    case '\r':
    case '\n':
    case '\f': return 5;
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

function ErrorReport(Pos, code)
{ 
	alert("Syntax error at " + Pos);
	ErrorCode = code;
}

function getToken(str) {
  State = 0;
  ErrorCode = 0;
  var token;
  var T;

  while ( End < str.length )
  {
  	T = charType(str.charAt(End));
//alert("[ Start="+Start+"; End="+End+"; Length="+str.length+" ]");
//alert("State="+State+"; Char='"+str.charAt(End)+"'; Type="+T+"; ");
  	if (T < 1)
  	 {
  		ErrorReport(End, -1);
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
  		  		ErrorReport(End, -3);
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
  			ErrorReport(End, -1);
  
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
		case "INFINITY" :
			return true;
	}
	return false;
}

function getPriority(OPT)
{
	switch (OPT) {
		case "~" :	// Special Negative Operator '-'
			return 6;
		case "+" :
	    case "-" :
	    	return 2;
	    case "*" :
	    case "/" :
	    case "^" :	
	    	return 3;
	    case "(" :
	    	return 4;
	    case ")" :
	    	return 5;
	    case "=" :
	    case ">" :
	    case "<" :
		case ">=" :
		case "<=" :
		case "!=" :
			return 1;
	    case "[":	
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
	if (r == 4) return 1;	// OPT, '('
	if (r == 5) return 2;	// OPT, ')'
	if (l == 4) return 1;	// '(', OPT
	if (l == 5) return 2;	// ')', OPT
	if (r > l) return 1;	// OPT, OPT
	else return 2;
}

function SetNameSpace(str)
{
	NameSpace = str;
}

function CreateMathNode(str)
{
	var node;
	if (NameSpace != "") {
		node = document.createElement(NameSpace+":"+str);
		//alert(NameSpace);
	}
	else {
		node = document.createElement(str);
	}
	return node;
}

function mathml()
{
	var OPRD = new Array();
	var OPER = new Array();
	var Last = 0;
	var Node;
	var Text;
	var Current;
	var subNode;
	var WORD
	
	//Node = CreateMathNode("mrow");
	//Current = Node;
	while ((Loc < TList.length)&&(ErrorCode >= 0)) {
		
		WORD = TList[Loc].token;
		State = TList[Loc].state;
//alert("Location="+Loc+"; WORD="+WORD+"; Type="+State+"; ");
		
		switch (State) {
			case 1:	// Token is string
				if ( ((Loc+1) < TList.length) && ((TList[Loc+1].token == "(" )||(TList[Loc+1].token == "[" )) ) {	//Function Name?
					Current = CreateMathNode("mrow");
					switch (WORD.toLowerCase())
					 {
		
						case "sqrt" :
							Node = CreateMathNode("msqrt");
							
							//OPER.push(TList[Loc+1]);
							Loc = Loc + 2;
							subNode = mathml();
							Node.appendChild(subNode);
							Current.appendChild(Node);
							break;
					 case "abs" :
					 case "card" :
							var Node1 = CreateMathNode("mo");
							var Text1= document.createTextNode("\u2758");
					    Node1.appendChild(Text1);	
					    Current.appendChild(Node1);				   
							Loc = Loc + 2;
							subNode = mathml();							
							Current.appendChild(subNode);
							var Node2 = CreateMathNode("mo");
							var Text2 = document.createTextNode("\u2758");
					    Node2.appendChild(Text2);	
					    Current.appendChild(Node2);	
						break;
//						case "root" :
//							Node = CreateMathNode("mroot");
//							
//							//OPER.push(TList[Loc+1]);	// Push '(' to OPER Stack
//							Loc = Loc + 2;				// Bypass '('
//							subNode = mathml();
//							Node.appendChild(subNode);
//							Current.appendChild(Node);
//							break;
          case "vector":
             { 
             	  Node = CreateMathNode("mfenced");
					      var MNode = CreateMathNode("mtable");
					      var  TNode = CreateMathNode("mtr");
					      Loc = Loc + 3;		
					      while(Loc < TList.length-2 )	
					      {
					      	var  DNode = CreateMathNode("mtd");
						      var  subNode = mathml();
						      DNode.appendChild(subNode);
						      TNode.appendChild(DNode)
						      Loc++;
					      	}			   
             	 MNode.appendChild(TNode);	
             	 Node.appendChild(MNode);
					  	 Current.appendChild(Node);
             	}
             	break;
				  case "matrix":
					  {   Node = CreateMathNode("mfenced");
					      var MNode = CreateMathNode("mtable");
					      Loc = Loc + 3;					   
					      while(Loc < TList.length-2 )					    
					         {
					         	 if( TList[Loc].token == "[" )							  									
							       var  TNode = CreateMathNode("mtr");
					        	Loc++;
					         	do 
					         	{
					   	       var  DNode = CreateMathNode("mtd");
						         var   subNode = mathml();
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
							Node = CreateMathNode("mfenced");
							
							
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
					    	subNode = mathml();
							  Node.appendChild(subNode);							  
						    Loc++;
					      }	
					      Current.appendChild(Node);							 																												
					   }
						 break;
						 case "diff" :						
							{					  
						  Node = CreateMathNode("mfrac");							
							Loc = Loc + 2;
							var msubNode = mathml();
							
							
							var PNode=CreateMathNode("mrow");
							var vNode=CreateMathNode("mo");
							Text = document.createTextNode("d")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
							Node.appendChild(PNode);
							Loc++;
							var PNode=CreateMathNode("mrow");
							var vNode=CreateMathNode("mo");
							Text = document.createTextNode("d")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
						  subNode = mathml();
						  PNode.appendChild(subNode);
						  Node.appendChild(PNode);						 
							Current.appendChild(Node);
							Current.appendChild(msubNode);
					  	}
							break;	
						
						 case	"partialdiff" :
							{	
					 	 Node = CreateMathNode("mfrac");							
							Loc = Loc + 2;
							var msubNode = mathml();
							
							
							var PNode=CreateMathNode("mrow");
							var vNode=CreateMathNode("mo");
							Text = document.createTextNode("&#x2202;")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
							Node.appendChild(PNode);
							Loc++;
							var PNode=CreateMathNode("mrow");
							var vNode=CreateMathNode("mo");
							Text = document.createTextNode("&#x2202;")
					    vNode.appendChild(Text);
					    PNode.appendChild(vNode);					    					   				    					    
						  subNode = mathml();
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
							var temp=1;
							if(temp==1)
							{ 
								var vNode=CreateMathNode("mo");
				        var Text2 = document.createTextNode("&Integral;")
				        vNode.appendChild(Text2);
				        Current.appendChild(vNode);
								var subNode = mathml();										
        				Current.appendChild(subNode);
								}
							else
							{
						  Node = CreateMathNode("mrow");	
							
							var subNode1 = mathml();						
							Node.appendChild(subNode1);
							Loc++;							
							var vNode=CreateMathNode("mo");
							var Text1 = document.createTextNode("d")
					    vNode.appendChild(Text1);               
							var subNode2 = mathml();
	            Node.appendChild(vNode);  
						  Node.appendChild(subNode2);						  
							Loc++;	
							
							var subNode3 = mathml();	
							if(TList[Loc].token == ".")	
							{									      
							var SNode=CreateMathNode("msubsup");					
				      var vNode=CreateMathNode("mo");
				      var Text2 = document.createTextNode("&Integral;")
				      vNode.appendChild(Text2);
				      SNode.appendChild(vNode);
				      SNode.appendChild(subNode3);	
				      Loc+=2;
							var subNode = mathml();							
				      SNode.appendChild(subNode); 
				      }						      				      
							else
							{
							var SNode=CreateMathNode("msub");					
				      var vNode=CreateMathNode("mo");
				      var Text2 = document.createTextNode("&Integral;")
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
							 var MNode = CreateMathNode("mo");		
					     Text = document.createTextNode("lim");
							 MNode.appendChild(Text);	
							 Node=CreateMathNode("munder");
							 Node.appendChild(MNode);
					     Loc+=2;
					     
					     var SNode=CreateMathNode("mrow");
							 var subNode1 = mathml();
							 SNode.appendChild(subNode1);		
					     Loc++;	
					     var PNode=CreateMathNode("mrow");
							 var subNode2 = mathml();
							 PNode.appendChild(subNode2);
							 var cNode = CreateMathNode("mo");		
					     Text = document.createTextNode("&RightArrow;");
							 cNode.appendChild(Text);	 
					     PNode.appendChild(cNode);
					     Node.appendChild(PNode);
					     Loc++;
					     var subNode3 = mathml();
							 PNode.appendChild(subNode3);
							 Node.appendChild(PNode);
					 	   Current.appendChild(Node);	
						   Current.appendChild(SNode);			
					  	}
							break;	
					  case "log":
					    {
					    	if(TList[1].token == "[")
					    	{
					      Node = CreateMathNode("msub");							
						   	Loc = Loc + 2;						
						  	var vNode=CreateMathNode("mo");
						    Text = document.createTextNode("log")
					      vNode.appendChild(Text);
					      Node.appendChild(vNode);
					      do 
					      {
						    var PNode=CreateMathNode("mrow");
							  var subNode = mathml();
							  PNode.appendChild(subNode);
				        Node.appendChild(PNode);
						     Loc++; 
						    }	while(TList[Loc-1].token == "]" );	
					      
				        Current.appendChild(Node);
				       
				        var PNode=CreateMathNode("mrow");
							  var subNode = mathml();
							  PNode.appendChild(subNode);
				        Current.appendChild(PNode);				        					      
					    	}	
					    	if(TList[1].token == "(")
					    	{
					    	Node = CreateMathNode("mo");
							  Text = document.createTextNode("log");
							  Node.appendChild(Text);
							  Current.appendChild(Node);																											
						    Loc = Loc + 2;				// Bypass '('							 
							  subNode = mathml();													
							  Current.appendChild(subNode);
					    			}			    						    						    						    	
					 	  }	
					  	break;	
					  	
					  case  "sum"	:
					    {
					     var	 MNode = CreateMathNode("mo");		
					     Text = document.createTextNode("&sum;");
							 MNode.appendChild(Text);	
					     Loc+=2;
					     var SNode=CreateMathNode("mrow");
							 var subNode1 = mathml();
							 SNode.appendChild(subNode1);	
							 if(TList[Loc].token == ",")
							 {
							 	Loc++;
							 	var TNode=CreateMathNode("mrow");
							  var subNode2 = mathml();
							  TNode.appendChild(subNode2);	
					
							 	if(TList[Loc].token == ".")
							 	{
							 	 Loc+=2;
							 	 var PNode=CreateMathNode("munderover");
							 	 PNode.appendChild(MNode);
							 	 PNode.appendChild(TNode);
							 	 var vNode=CreateMathNode("mrow");
							   var subNode3 = mathml();
							   vNode.appendChild(subNode3);	
							   PNode.appendChild(vNode);
							  }
							  else
							 	{							 	 
							 	 var PNode=CreateMathNode("munder");
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
					   	var	 MNode = CreateMathNode("mo");		
					     Text = document.createTextNode("&prod;");
							 MNode.appendChild(Text);	
					     Loc+=2;
					     var SNode=CreateMathNode("mrow");
							 var subNode1 = mathml();
							 SNode.appendChild(subNode1);	
							 
							  if(TList[Loc].token == ",")
							  {
							 	 Loc++;
							 	 var PNode=CreateMathNode("munderover");
							 	 PNode.appendChild(MNode);
							 	 var TNode=CreateMathNode("mrow");
							   var subNode2 = mathml();
							   TNode.appendChild(subNode2);
							 	 PNode.appendChild(TNode);
							 	 Loc+=2;
							 	 var vNode=CreateMathNode("mrow");
							   var subNode3 = mathml();
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
							Node = CreateMathNode("mi");
							Text = document.createTextNode(WORD);
							Node.appendChild(Text);
							Current.appendChild(Node);
							
							Node = CreateMathNode("mo");
							Text = document.createTextNode("&ApplyFunction;");
							Node.appendChild(Text);
							Current.appendChild(Node);
							
							Node = CreateMathNode("mfenced");
							//OPER.push(TList[Loc+1]);	// Push '(' to OPER Stack
							Loc = Loc + 2;				// Bypass '('
							subNode = mathml();
							Node.appendChild(subNode);
							//subNode = CreateMathNode("mfenced");
							//subNode.appendChild(Node);
							Current.appendChild(Node);
						}
						OPRD.push(Current);			// Push MathNode to Statck
				}
				else 
					{	// TOken is not Function Name
					if ( isReservedConst(WORD) ) 
					{
						//alert("Find Constant");
						Node = CreateMathNode("mi");
						switch (WORD.toUpperCase()) {
							case "PI" :
								Text = document.createTextNode("&pi;");
								break;
							case "E"  :
								Text = document.createTextNode("&ExponentialE;");
								break;
							case "I"  :
								Text = document.createTextNode("&ImaginaryI;");
								break;
							case "GAMMA" :
								Text = document.createTextNode("&gamma;");
								break;
							case "INFINITY" :
								Text = document.createTextNode("&infin;");
								break;
						}
						  Node.appendChild(Text);
						//Current.appendChild(Node);
	            OPRD.push(Node);
	            Loc++;
					 }

        
          	  if( isSetFunc(WORD)) 
							{	
								var Current = CreateMathNode("mrow");	
								var PNode = OPRD.pop();
								Current.appendChild(PNode);
								Node = CreateMathNode("mo");
						    switch (WORD.toLowerCase()) 
						    {
							  case "and" :
								Text = document.createTextNode("&wedge;");
								break;
							  case "or"  :
								Text = document.createTextNode("&vee;");
								break;
						 	  case "implies"  :
								Text = document.createTextNode("&Rightarrow;");
								break;
							  case "xor" :
								Text = document.createTextNode("&veebar;");
								break;
							  case "union" :
								Text = document.createTextNode("\u222A");
							  break;
								case "intersect"   :					
								Text = document.createTextNode("&cap;");
								break;
		            case "notsubset"   :
		            Text = document.createTextNode("&nsub;");
		            break;
		            case "notprsubset"   :
		            Text = document.createTextNode("&nsubseteq;");
		            break;
		            case "subset"   :
		            Text = document.createTextNode("&subseteqq;");
		            break;
		            case "prsubset"   :
		            Text = document.createTextNode("&subset;");
		            break;
		            case "in"   :		            
		            Text = document.createTextNode("&#x2208;");
		            break;
      		      case "notin"   :
      		      Text = document.createTextNode("&#x2209;");
								break;
								case "setdiff"   :
      		      Text = document.createTextNode("\u2216");
								break;
								case "cartesianproduct":
								Text = document.createTextNode("\u00D7");
								break;
					    	}
						    Node.appendChild(Text);	
						    Current.appendChild(Node);	
						    Loc++;
						    subNode = mathml();
				  			Current.appendChild(subNode);							    
						   	OPRD.push(Current);										   
								} 
              if(TList[Loc].token=="then"||TList[Loc].token=="for"||TList[Loc].token=="which")
								   {
								   	var Node = CreateMathNode("mrow");
								   	var vNode = CreateMathNode("mi");
						        Text = document.createTextNode(WORD);
						        vNode.appendChild(Text);
						        var mNode = CreateMathNode("mo");
						        var Text2 = document.createTextNode(" ");
						        mNode.appendChild(Text2);
						        Node.appendChild(vNode);
						        Node.appendChild(mNode);
								   	return Node;
							      }						     		   

							if(TList[Loc].token=="exists"||TList[Loc].token=="forall")
								{ 
								var Current = CreateMathNode("mrow");					    	
						    Node=CreateMathNode("mo");
						    Text = document.createTextNode(WORD);
							  Node.appendChild(Text);							  
							  Current.appendChild(Node);
							  while((Loc+1) < TList.length-1)
							     {
							  	  Loc++;
							      var subNode = mathml();										 				  
							      Current.appendChild(subNode);
					    			}		
					    		OPRD.push(Current);		    						    						    						    	
					 	     }	
					  
					    
						else
						 { 
						 	Node = CreateMathNode("mi");
						  Text = document.createTextNode(WORD);
						  Node.appendChild(Text);
						  //Curent.appendChild(Node);
						  OPRD.push(Node);
						  Loc++;
						  if(TList[Loc].token=="for")
						   {
						  	 Node = OPRD.pop();	
						  	 Loc--;							  					
						     return Node;
						  	}						  
						}
					}
				break;
			case 2:
				Node = CreateMathNode("mn");
				Text = document.createTextNode(WORD);
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
					Node = CreateMathNode("mfenced");
					var EnNode = CreateMathNode("mrow");
					Loc++;
					var subNode = mathml();
					EnNode.appendChild(subNode);
					Node.appendChild(EnNode);
					OPRD.push(Node);
				}
				else {
					var L = OPER.length;
					//alert("Handle Operator. OPER.length="+L);
					if (L == 0) 
					{
						if (WORD == ";")
						 {
							Node = OPRD.pop();
							return Node;
						}
					 if (WORD == "{") 
						 {if(TList[Loc+1].token == "}")
							 {Node = CreateMathNode("mi");
						    Text = document.createTextNode("\u2205");
						    Node.appendChild(Text);
						   }
						   else
						   {  temp1=1;						 				  	
					     	 Node = CreateMathNode("mfenced");
							   Node.setAttribute("close","}");	
							   Node.setAttribute("open","{");
							   while((Loc+1) < TList.length-1 )
						     {Loc++;
					    	 subNode = mathml();
							   Node.appendChild(subNode);									  
					       }						     					 																												
						     }
						   return Node;
					     }
					if (WORD == "[")
					   {
							   temp1=1;						 				  	
					     	 Node = CreateMathNode("mfenced");
							   Node.setAttribute("close","]");	
							   Node.setAttribute("open","[");
							   while((Loc+1) < TList.length-1 )
						     {Loc++;
					    	 subNode = mathml();
							   Node.appendChild(subNode);							  
					       }						     											
						  return Node;
					  	} 
//						 if (WORD == "=")
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
							{if(Loc==TList.length-2)
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
					//alert("Compare ["+OPER[L-1]+"] ["+WORD+"] Priority="+priority);
					if (priority == 1) {	// High Priority
						OPER.push(WORD);
						Loc++;
					}
					if (priority == 2) {	// Low or equal priority
						Current = CreateMathNode("mrow");
						var Action = OPER.pop();
						var Operand;
						var Operand1;
						var Operand2;
						switch (Action) {
							case "~" :
								Operand1 = OPRD.pop();
								Node = CreateMathNode("mo");
								Text = document.createTextNode("-");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								OPRD.push(Current);
								break;
							case "+" :
								Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("+");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "-" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("-");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
							case "==" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&#x2261;");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "*" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&times;");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "/" :
		    					Node = CreateMathNode("mfrac");
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
		    					Node.appendChild(Operand1);
		    					Node.appendChild(Operand2);
		    					Current.appendChild(Node);
		    					OPRD.push(Current);
		    					break;
					    	case "^" :	// Power
					    		Node = CreateMathNode("msup");
					    		Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
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
								Node = CreateMathNode("mo");
								Text = document.createTextNode("=");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case ">" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&gt;");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case "<" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&lt;");
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
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&ge;");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "<=" :
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&le;");
								Node.appendChild(Text);
								Current.appendChild(Node);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "!=" : 
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Current.appendChild(Operand1);
								Node = CreateMathNode("mo");
								Text = document.createTextNode("&ne;");
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
				ErrorReport(End, -1);
				var Empty = document.createTextNode(" ");
				return Empty;
		}
	}
	
	var Node = CreateMathNode("mrow");
	return Node;
}

function mathmlContent()
{
	var OPRD = new Array();
	var OPER = new Array();
	var Last = 0;
	var Node;
	var Text;
	var Current;
	var subNode;
	var WORD
	
	//Node = CreateMathNode("mrow");
	//Current = Node;
	while ((Loc < TList.length)&&(ErrorCode >= 0)) {
		
		WORD = TList[Loc].token;
		State = TList[Loc].state;
//alert("Location="+Loc+"; WORD="+WORD+"; Type="+State+"; ");
		
	switch (State) 
		{
			case 1:	// Token is string
			if ( ((Loc+1) < TList.length) && ((TList[Loc+1].token == "(" )||(TList[Loc+1].token == "[" ))||TList[Loc].token == "exists" ||TList[Loc].token == "forall" ) //Function Name?
				{	
					
					if ( isReservedFunc(WORD) ) 
					{
						switch (WORD.toLowerCase()) 
						{
						case "vector"	:
						{temp1=1;
						Current = CreateMathNode("vector");
						Loc = Loc + 3;
						while(Loc < TList.length-1 )
						{
						subNode = mathmlContent();
						Current.appendChild(subNode);
						Loc++;
					  }
					  }
						break;
	         case "interval"	:
						{temp1=1;
						//	alert(TList[Loc+1].token);
							//alert(TList[TList.length-2].token);
						 var Current = CreateMathNode("interval");
						 if((TList[Loc+1].token == "(") &&(TList[TList.length-2].token == ")") )
						   {
							  Current.setAttribute("closure","open");
							  }					 				
						 if(TList[Loc+1].token == "(" && TList[TList.length-2].token == "]")
						    {
							  Current.setAttribute("closure","open-closed");							
							  }
						 if(TList[Loc+1].token == "[" &&TList[TList.length-2].token == ")")
					  	 {
							 Current.setAttribute("closure","closed-open");
							
						  	}					
					   if(TList[Loc+1].token == "[" &&TList[TList.length-2].token == "]")
					    	{
							   Current.setAttribute("closure","closed");
							 }
					  	 Loc = Loc + 2;
						   while((Loc+1) < TList.length-1 )
						   {
					    	subNode = mathmlContent();
					  	  Current.appendChild(subNode);
						    Loc++;
						    
					      }
				  	 }				
						 break;
					   case "matrix"	:
						  {temp1=1;
						  Current = CreateMathNode("matrix");
						  Loc = Loc + 3;						
		  		    while(Loc < TList.length-2 )
					    {			 
					    if( TList[Loc].token == "[" )							  			
							var  SNode= CreateMathNode("matrixrow");
			    		Loc++; 
						  do {
						  subNode = mathmlContent();
						  SNode.appendChild(subNode);
						  Loc++; 
						    }	while(TList[Loc-2].token != "]" );								 
						  Current.appendChild(SNode);				   				    
						 }						
					    }					
						 break;
						 case "log" :
				   	 {
						  Current = CreateMathNode("apply");
							Node = CreateMathNode("log");
							Current.appendChild(Node);
							Loc = Loc + 2;
							//alert(TList[Loc].token);
							if( TList[Loc-1].token == "[" )
							{
								var  SNode= CreateMathNode("logbase");
						  do {
						  subNode = mathmlContent();
						  SNode.appendChild(subNode);
						  Loc++; 
						  }	while(TList[Loc-1].token == "]" );					   						  
						  Current.appendChild(SNode);	
						  }					 						
							
						  subNode = mathmlContent();
						  Current.appendChild(subNode);					       
		        }
							break;	
						case "sqrt" :
						  Current = CreateMathNode("apply");
							Node = CreateMathNode("root");
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
							Current.appendChild(subNode);
							break;
						case "abs" :
						  Current = CreateMathNode("apply");
							Node = CreateMathNode("abs");
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
							Current.appendChild(subNode);
							break;
						case "not" :
						  Current = CreateMathNode("apply");
							Node = CreateMathNode("not");
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
							Current.appendChild(subNode);
							break;
					  case "sum":
						case "product":
						 {
						 	Current = CreateMathNode("apply");
							Node = CreateMathNode(WORD.toLowerCase());
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
								
			       	while  ( TList[Loc].token == "," )							
							  {  
  		      	if( TList[Loc-1].token == ")"&& temp1==1) break;

								Loc++;
								var i=Loc;
								while(i<TList.length)
								{  
									if(TList[i].token==".")
								      var	esp=1;	
								    if(TList[i].token == "sum"||TList[i].token == "product"||TList[i].token == "int")		break;	
								    i++;			 
								  	 }
								if(esp==1)
								{
								var  SNode= CreateMathNode("lowlimit");
								var  vNode = mathmlContent();
							
								SNode.appendChild(vNode);	
								Current.appendChild(SNode);
								Loc+=2;
							  var  eNode= CreateMathNode("uplimit");
								var  vNode = mathmlContent();
								eNode.appendChild(vNode);	
								Current.appendChild(eNode);
							
							  }
							  else 
							  	{
							  		var  SNode= CreateMathNode("domainofapplication");
								    var  vNode = mathmlContent();
								    SNode.appendChild(vNode);	
								    Current.appendChild(SNode);
							  	}	
							  						
						}
					 
							Current.appendChild(subNode);
						 	}
						 
						 	break;
						 case "forall" :
						 case	"exists" :
							{
						  Current = CreateMathNode("apply");
						  Node = CreateMathNode(WORD.toLowerCase());
							Current.appendChild(Node);
							Loc++;	

						  var  SNode= CreateMathNode("bvar");
							var  eNode=CreateMathNode("ci");
							eNode.setAttribute("type","bvar");								
							var    subNode = mathmlContent();
							eNode.appendChild(subNode);
							SNode.appendChild(eNode);	
							Current.appendChild(SNode);
							Loc+=2;																
							var  vNode = mathmlContent();																	
							Current.appendChild(vNode);
					  	}
							break;	
						 case "diff" :
						 case	"partialdiff" :
							{
						  Current = CreateMathNode("apply");
						  Node = CreateMathNode(WORD.toLowerCase());
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
							Loc++;							
							var  SNode= CreateMathNode("bvar");
							var  eNode=CreateMathNode("ci");
							eNode.setAttribute("type","bvar");								
							vNode = mathmlContent();
							eNode.appendChild(vNode);
							SNode.appendChild(eNode);						
							Current.appendChild(SNode);
							Current.appendChild(subNode);
					  	}
							break;	
						case	"limit" :
						case	"int" :
							{
						 	Current = CreateMathNode("apply");
							Node = CreateMathNode(WORD.toLowerCase());
							Current.appendChild(Node);
							Loc = Loc + 2;
							subNode = mathmlContent();
							Loc++;
						  //alert(TList[Loc-1].token );
						  if( TList[Loc-1].token == "," )
						  {
						  var  SNode= CreateMathNode("bvar");
							var  eNode=CreateMathNode("ci");
							eNode.setAttribute("type","bvar");								
							var  vNode = mathmlContent();
							eNode.appendChild(vNode);
							SNode.appendChild(eNode);						
							Current.appendChild(SNode);
							Loc++;
						  }
					   
							if( TList[Loc-1].token == "=" )
							{								
								for(i=Loc;i<TList.length;i++)
								{if(TList[i].token==".")
								      var	esp=1;							 
								  	 }
								if(esp==1)
								{
								var  SNode= CreateMathNode("lowlimit");
								var  vNode = mathmlContent();
							
								SNode.appendChild(vNode);	
								Current.appendChild(SNode);
								Loc+=2;
							  var  eNode= CreateMathNode("uplimit");
								var  vNode = mathmlContent();
								eNode.appendChild(vNode);	
								Current.appendChild(eNode);
							  }
							  else 
							  	{
							  		var  SNode= CreateMathNode("lowlimit");
								    var  vNode = mathmlContent();
								    SNode.appendChild(vNode);	
								    Current.appendChild(SNode);
							  	}						
							  }
							  Current.appendChild(subNode);
					  	}
							break;	
						default:
						  Current = CreateMathNode("apply");
							Node = CreateMathNode(WORD.toLowerCase());
							Current.appendChild(Node);
							
							//OPER.push(TList[Loc+1]);	// Push '(' to OPER Stack
							Loc = Loc + 2;				// Bypass '('
							subNode = mathmlContent();
							Current.appendChild(subNode);
						}
					}
					else 
						{
						Current = CreateMathNode("apply");
						Node = CreateMathNode("csymbol");
						Text = document.createTextNode(WORD);
						Node.appendChild(Node);
						Current.appendChild(Node);
						Loc = Loc + 2;
						subNode = mathmlContent();
						Current.appendChild(subNode);
					}
					OPRD.push(Current);			// Push MathNode to Statck
				}
				else {	// TOken is not Function Name
					if ( isReservedConst(WORD) ) {
						//alert("Find Constant");
						//Node = CreateMathNode("ci");
						switch (WORD.toUpperCase()) {
							case "PI" :
								Node = CreateMathNode("pi");
								break;
							case "E"  :
								Node = CreateMathNode("exponentiale");
								break;
							case "I"  :
								Node = CreateMathNode("imaginaryi");
								break;
							case "GAMMA" :
								Node = CreateMathNode("eulergamma");
								break;
							case "INFINITY" :
								Node = CreateMathNode("infinity");
								
						}
						//Node.appendChild(Text);
						//Current.appendChild(Node);
						OPRD.push(Node);
					}
					else 
						{
							if( isSetFunc(WORD)) 
							{		
							Node = CreateMathNode(WORD.toLowerCase());	
						  Current = CreateMathNode("apply");
							
							Current.appendChild(Node);
							subNode=OPRD.pop(Node);						
							Current.appendChild(subNode);
							Loc = Loc + 1;
						  var eNode = mathmlContent();
						  Current.appendChild(eNode);
							OPRD.push(Current);							
								} 
						else
							{
								if(TList[Loc].token=="for")
								{
										Node = OPRD.pop();
							      return Node;
									}
						 else
						  	{Node = CreateMathNode("ci");
						    Text = document.createTextNode(WORD);
						    Node.appendChild(Text);
					     	//Curent.appendChild(Node);
						    OPRD.push(Node);
						  	Loc++;
						  }
						}
					}	
				}			
			break;
			case 2:
				Node = CreateMathNode("cn");
				Text = document.createTextNode(WORD);
				Node.appendChild(Text);
				//Current.appendChild(Node);
				OPRD.push(Node);
				
				Loc++;
				if(charType(TList[Loc].token)==1)
				temp2=1;
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
					Loc++;
					Node = mathmlContent();
					OPRD.push(Node);
				}
				else {
					var L = OPER.length;
					//alert("Handle Operator. OPER.length="+L);
					if (L == 0)
					 {
						 if (WORD == ";") 
						 {
							Node = OPRD.pop();
							return Node;
						  }
						  if ((WORD == "{")) 
				      { if(TList[Loc+1].token == "}")
						     {Node = CreateMathNode("mi");
						      Text = document.createTextNode("\u2205");
						      Node.appendChild(Text);
						      }
					     else
					     {temp1=1;
						    Node = CreateMathNode("set");
					      Loc ++;
						    while(Loc < TList.length-1 )
						      { subNode =mathmlContent();
					        	Node.appendChild(subNode);
					         	Loc++;					      }
						  }
					   return Node;
				    }			  
				    if ((WORD == "[")) 				  				
					  {  temp1=1;
						   Node = CreateMathNode("list");
					     Loc ++;
						   while(Loc < TList.length-1 )
						      { subNode =mathmlContent();
					        	Node.appendChild(subNode);
					         	Loc++;					      }
					  return Node;
				    }
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
			      	 {	 Node = OPRD.pop();								  					
						     return Node;
						   }
//					  if (WORD == "=")
//					   {
//							Node = OPRD.pop();							
//						  return Node;
//					  	}
				   if (WORD == "]") 
							{if(Loc==TList.length-2)
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
					//alert("Compare ["+OPER[L-1]+"] ["+WORD+"] Priority="+priority);
					if (priority == 1) {	// High Priority
						OPER.push(WORD);
						Loc++;
					}
					if (priority == 2) {	// Low or equal priority
						Current = CreateMathNode("apply");
						var Action = OPER.pop();
						var Operand;
						var Operand1;
						var Operand2;
						switch (Action) {
							case "~" :
								Operand1 = OPRD.pop();
								Node = CreateMathNode("minus");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								OPRD.push(Current);
								break;
							case "+" :
								Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Node = CreateMathNode("plus");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "-" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Node = CreateMathNode("minus");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "*" :
		    					Operand2 = OPRD.pop();
								Operand1 = OPRD.pop();
								Node = CreateMathNode("times");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
								break;
		    				case "/" :
		    					Node = CreateMathNode("divide");
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
		    					Current.appendChild(Node);
		    					Current.appendChild(Operand1);
		    					Current.appendChild(Operand2);
		    					OPRD.push(Current);
		    					break;
					    	case "^" :	// Power
					    		Node = CreateMathNode("power");
					    		Current.appendChild(Node);
					    		Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
		    					Current.appendChild(Operand1);
		    					Current.appendChild(Operand2);
		    					OPRD.push(Current);
		    					break;
					    	/* case "(" : */	// Never handle this
		    				case "=" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("eq");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case ">" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("gt");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case "<" :
		    					Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("lt");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
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
								Node = CreateMathNode("geq");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "<=" :
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("leq");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case "!=" : 
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("neq");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
		    				case "==" : 
								Operand2 = OPRD.pop();
		    					Operand1 = OPRD.pop();
								Node = CreateMathNode("equivalent");
								Current.appendChild(Node);
								Current.appendChild(Operand1);
								Current.appendChild(Operand2);
								OPRD.push(Current);
		    					break;
							case ";"  :	// End of expression
						}
					}
				} //End of Else '('
				break;
			default :
				ErrorReport(End, -1);
				var Empty = document.createTextNode(" ");
				return Empty;
		}
	}
	
	var Node = CreateMathNode("mrow");
	return Node;
}

function convertToMathMLDOM(str)
{
	Expression = new String(str);
	reset();
	
	TList = new Array();
	while ((End < Expression.length)&&(ErrorCode >= 0)) {
		WORD = getToken(Expression);
		if (ErrorCode < 0) return "";
		else TList.push( new TokenRecord(WORD, State) );
	}
	TList.push( new TokenRecord(";", 4) );
	
	/*
	for (var i=0; i<TList.length; i++) 
		alert("Token: '" + TList[i].token + "' ; Type: " + TList[i].state +" ; ");
	*/
	
	var root = CreateMathNode("math");
	var semantic = CreateMathNode("semantics");
	var exprP = mathml();
	reset();
	var exprC = mathmlContent();
	
	semantic.appendChild(exprP);
	
	var annotation = CreateMathNode("annotation-xml");
	
	
	//var attribute = document.createAttribute("encoding");
	//attribute.nodeValue = "MathML-Content";
	//annotation.setAttributeNode(attribute);
	annotation.setAttribute("encoding", "MathML-Content");
	annotation.appendChild(exprC);
	
	
	semantic.appendChild(annotation);
	
	annotation = CreateMathNode("annotation-xml");
	//attribute = document.createAttribute("encoding");
	//attribute.nodeValue = "Infix";
	//annotation.setAttributeNode(attribute);
	annotation.setAttribute("encoding", "Infix")
	
	var Infix = document.createTextNode(str);
	annotation.appendChild(Infix);
	
	semantic.appendChild(annotation);
	
	root.appendChild(semantic);
	
	return root;
}

function convertToMathMLPresentDOM(str)
{
	Expression = new String(str);
	reset();
	
	TList = new Array();
	while ((End < Expression.length)&&(ErrorCode >= 0)) {
		WORD = getToken(Expression);
		if (ErrorCode < 0) return "";
		else TList.push( new TokenRecord(WORD, State) );
	}
	TList.push( new TokenRecord(";", 4) );
	
	var root = CreateMathNode("math");
	var expr = mathml();
	root.appendChild(expr);
	
	return root;
}

function convertToMathMLContentDOM(str)
{
	Expression = new String(str);
	reset();

	TList = new Array();
	while ((End < Expression.length)&&(ErrorCode >= 0)) {
		WORD = getToken(Expression);
		if (ErrorCode < 0) return "";
		else TList.push( new TokenRecord(WORD, State) );
	}
	TList.push( new TokenRecord(";", 4) );
	
	var root = CreateMathNode("math");
//	 root.setAttribute("xmlns:mml","http://www.w3.org/1998/Math/MathML");
//  alert(root.getAttribute("xmlns:mml"));
	var expr = mathmlContent();
	root.appendChild(expr);
	
	return root;
}

function convertToMathMLSTR(str)
{
	var node = convertToMathMLDOM(str);
	var result = GetMathML(node);
	return result;
}

function DisplayDOM(Expr)
{
	var msg;
	msg = "Parent=<"+Expr.parentNode.nodeName+"> NodeName=<"+Expr.nodeName + "> ChildNum="+Expr.childNodes.length;
	if (Expr.nodeType == 3) msg = msg+" Content='"+Expr.nodeValue+"' ";
	for (var i=0; i<Expr.childNodes.length; i++) Display(Expr.childNodes[i]);
}


function GetAttribute(node, NodeName, AttrName)
{
	var list = " ";

	if (node.nodeName != NodeName) return list;
	for (var i=0; i<node.attributes.length; i++) {
		if (node.attributes[i].nodeName == AttrName) {
			list = list+ node.attributes[i].nodeName + '="' + node.attributes[i].nodeValue + '" ';
			return list;
		}
	}
	return list;
}

function GetAttributeP(node, NodeName, AttrName)
{
	var list = "";

	if (node.nodeName != NodeName) return list;
	for (var i=0; i<node.attributes.length; i++) {
		if (node.attributes[i].nodeName == AttrName) {
			list = list+" " + node.attributes[i].nodeName + '="' + node.attributes[i].nodeValue + '" ';
			return list;
		}
	}
	return list;
}

function GetMathML(Expr)
{
	var MathMLValue="";
	
	if (Expr.nodeType == 3) {
		MathMLValue =  MathMLValue + " "+Expr.nodeValue+" ";
		return MathMLValue;
	}
	if (Expr.childNodes.length == 0) {
		MathMLValue = MathMLValue + "<"+Expr.nodeName+GetAttribute(Expr, "annotation-xml","encoding")+"/>";
		return MathMLValue;
	}
	else {
		MathMLValue = MathMLValue + "<"+Expr.nodeName+GetAttribute(Expr, "annotation-xml","encoding")+">";
		for (var i=0; i<Expr.childNodes.length; i++) {
			MathMLValue += GetMathML(Expr.childNodes[i]);
		}
		MathMLValue = MathMLValue + "</"+Expr.nodeName+">";
	}
	
	return MathMLValue;
}

function GetMathMLEx(Expr)
{
	var MathMLValue="";
	var prefix = "";

	if (Expr.nodeType == 3) {
		MathMLValue =  MathMLValue + ""+Expr.nodeValue+"";
		return MathMLValue;
	}
	
	if (NameSpace == "") prefix = "";
	else {//alert(NameSapce);
		prefix = NameSpace+":"}
	
	if (Expr.childNodes.length == 0) {
		MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttribute(Expr, "interval","closure")+"/>";
		return MathMLValue;
	}
	else {
		if(TList[0].token == "interval")
	{		   
		   	MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttribute(Expr, "interval","closure")+">";
	 }
		else
		MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttribute(Expr, "ci","type")+">";
		for (var i=0; i<Expr.childNodes.length; i++) {
		
			MathMLValue += GetMathMLEx(Expr.childNodes[i]);
		}
		MathMLValue = MathMLValue + "</"+prefix+Expr.nodeName+">";
	}
	
	return MathMLValue;
}

function GetMathMLExP(Expr)
{
	var MathMLValue="";
	var prefix = "";

	if (Expr.nodeType == 3) {
		MathMLValue =  MathMLValue + ""+Expr.nodeValue+"";
		return MathMLValue;
	}
	
	if (NameSpace == "") prefix = "";
	else {//alert(NameSapce);
		prefix = NameSpace+":"}
	
	if (Expr.childNodes.length == 0) {
		MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "mfenced","open")+"/>";
		return MathMLValue;
	}
	else {
		if(TList[0].token == "interval")
		{
			if((TList[1].token == "[")&&(TList[TList.length-2].token == "("))
		    MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "mfenced","open")+">";
		  if((TList[1].token == "(")&&(TList[TList.length-2].token == "]"))
		    MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "mfenced","close")+">";
		else
		MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "mfenced","open")+GetAttributeP(Expr, "mfenced","close")+">";
	  }
	  if(TList[0].token == "["||TList[0].token == "{")
	  MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "mfenced","open")+GetAttributeP(Expr, "mfenced","close")+">";
		else
		MathMLValue = MathMLValue + "<"+prefix+Expr.nodeName+GetAttributeP(Expr, "ci","type")+">";
		for (var i=0; i<Expr.childNodes.length; i++) {
		
			MathMLValue += GetMathMLExP(Expr.childNodes[i]);
		}
		MathMLValue = MathMLValue + "</"+prefix+Expr.nodeName+">";
	}
	
	return MathMLValue;
}


function test(str)
{
	var result;
  SetNameSpace("mml");
  //alert("d");
	result = convertToMathMLDOM(str);
	var STR = GetMathMLEx(result);
	
	var dis = document.getElementById("display");
	dis.appendChild(result);
	var hr = document.createElement("hr");
	dis.appendChild(hr);
	
	alert("Mixed Encoding:  " +STR);
	
	
	result = convertToMathMLPresentDOM(str);
	var STR = GetMathMLEx(result);
	alert("Presentation Encoding:  "+STR);
	
   result = convertToMathMLContentDOM(str);
	 var STR = GetMathMLEx(result);
	

	alert("Content Encoding:  "+STR);

}

