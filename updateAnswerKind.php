<?
	include_once("base/baseForm.php");
	include_once("base/databaseManager.php");
	
	//$b->AddCrumb("The kind of answers for eacn problem","");
	$b->ActiveMenu=23;
	$b->MainMenuIndex=23;

  $flag=0;	
  $sqlupdate="insert into kindofanswers values ";
	$con=new DatabaseManager();
	$number=$_GET["number"];
	$b->AddSubMenuItem("Show the kind of answers for eacn problem","answerKindAdmin.php?number=".$number."&page=1");
	$sql="delete from kindofanswers where fk_problem=".$number;
	$con->Query($sql);
	
	$sql="select array_0 from assignmenttakequestions where fk_problem=".$number." group by array_0";
	$dsp=$con->Query($sql);
	while($drp=mysql_fetch_row($dsp))
	{
		$k=0;
		$problem="";
		$sAnswer="";
		if (strpos($drp[0],"'")!==false) 
		{
			$drp[0]=str_replace("'","\'",$drp[0]);
    }
		$sql="select useranswer,array_0,array_1,result from assignmenttakequestions where ";
		$sql.="fk_problem=".$number." and array_0='".$drp[0]."'";
		$ds=$con->Query($sql);
		$dr=mysql_fetch_row($ds);
		$kind[]=$dr[0];
		$problem=$dr[1];
		$sAnswer=$dr[2];
		if($dr[3]==1||$dr[3]==2)
			$result[]="YES";
		else
			$result[]="NO"; 

		
		while($dr=mysql_fetch_row($ds))
	  {
	  	$kind[]=$dr[0];
	  	if($dr[3]==1||$dr[3]==2)
				$result[]="YES";
			else
				$result[]="NO"; 
	  }
	
		for($i=0; $i<count($kind);$i++)
		{
			$kind[$i]=substr($kind[$i],12);
			$j=strpos($kind[$i],"\"");
		  $kind[$i]=substr($kind[$i],0,$j);
		  if(strcmp($kind[$i],"")==0)
		  {
		  	$kind[$i]="NULL";
		  }
		}
	

//select useranswer,array_0,array_1 from assignmenttakequestions where fk_problem=10 and array_0='(2 - 2^2 )/(9 - 3^2)';
//k=0;
//count[x]=0
//for(i=0;i<8;i++)
//{
//   if(a[i]!="@#%$*")
//   {
//	b[k]=a[i];
//	count[k]=1;
//	for(j=i+1;j<8;j++)
//	{
//		if(a[i]==a[j])
//		{
//		  count[k]++;
//                  a[j]="@#%$*";	
//		}
//	}
//	k++;
//   }
//}
		if (strpos($problem,"'")!==false) 
		{
			$problem=str_replace("'","\'",$problem);
    }
    if (strpos($sAnswer,"'")!==false) 
		{
			$sAnswer=str_replace("'","\'",$sAnswer);
    }
		for($i=0;$i<count($kind);$i++)
		{
			if(strcmp($kind[$i],"@#%$*")!=0)
      {
        $tempKind[$k]=$kind[$i];
        $tempResult[$k]=$result[$i];
        $count[$k]=1;
        for($j=$i+1;$j<count($kind);$j++)
				{
					if($kind[$i]==$kind[$j])
					{
					  $count[$k]++;
            $kind[$j]="@#%$*";	
					}
				}
    		if (strpos($tempKind[$k],"'")!==false) 
				{
					$tempKind[$k]=str_replace("'","\'",$tempKind[$k]);
    		}

				$sqlupdate.="('',".$number.",'".$problem."','".$sAnswer."','".$tempKind[$k]."',".$count[$k].",'".$tempResult[$k]."',".$flag."),";
	      $k++;
      }
		}
		if($flag==0)
		{
			$flag=1;
		}else
		{
			$flag=0;
		}
		unset($tempKind);
	  unset($count);
	  unset($kind);
	  unset($result);
	  unset($tempResult);
  }
  $sqlupdate= substr($sqlupdate,0, -1);
  $con->Query($sqlupdate);
	//
	// - Drop out
	//
	$con->Dispose();	
	$b->RenderTemplateTop();
	echo "<br><br><br><br><br><br><br><br><center><font size=\"4\" color=\"red\"><b> Update Successfully!</b></font></center>";
	$b->RenderTemplateBottom();
	$b->Dispose();
?>