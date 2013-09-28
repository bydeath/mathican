function openta(openmode,assid,cid,finish)
{
	window.open("takeAssignmentDo1.php?openmode="+openmode+"&id="+assid+"&cid="+cid+"&finish="+finish,"assignment","location=no,menubar=no,toolbar=no,width=780,height=650,status=no,scrollbars=yes,resizable=yes");
}
function opensingle(d)
{
  var openlink="takeAssignmentDo1.php?openmode=1&number=1&types="+ d;
  window.open(openlink,"assignment","location=no,menubar=no,toolbar=no,width=780,height=650,status=no,scrollbars=yes,resizable=yes");
}