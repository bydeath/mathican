function changep()
{
	var startp=document.getElementById("startp");
	var endp=document.getElementById("endp");
	if(startp.value=="" || endp.value=="")
	{
		alert("You don't enter the arrange for problems.");
		return;
	}
	var linka="admindirect.php";
	linka+="?startp="+startp.value+"&endp="+endp.value;
	document.location=linka;
}
