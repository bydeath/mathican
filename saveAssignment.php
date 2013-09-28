<?
 	include_once("base/baseForm.php");
 	if($b->User->UserId!=""&&$b->User->UserId!=0&&$b->User->UserId!="0")
 	{
		$done=$_POST["txt_done"];
		$started=$_POST["txt_started"];
		$finished=$_POST["txt_finished"];
		$number=$_POST["num_questions"];
		$finish=$_POST["finish"];
		$pk=0;
		$cornum=0; 
		$questions="";
		$answers="";
		$con=new DatabaseManager();
		$id=$_POST["id"];	
		$cid=$_POST["cid"];
		$sql="SELECT assignmentTakeId";
		$sql.=" FROM assignmenttakes";
		$sql.=" WHERE ( fk_user_taker=" . $b->User->UserId . "  and fk_assignment=". $_POST["id"] ." and done=0)";
		$ds=$con->Query($sql);
		if($finish!=""&&$done=="1"&&mysql_num_rows($ds)<1)
		{
			$con->Dispose();
			echo '{"cnums":"-1","atid":"-1"}';
		}else{
				//
				//save assignment take and retreive pk
				$cornum=0;
				if(mysql_num_rows($ds)>=1 )
				{
					while($dr=mysql_fetch_row($ds))
				  {
				  	$pk=$dr[0];
				  }
				  if($done=="1")
				  {
			  	  $sql="update assignmenttakes";
			     	$sql.=" set done='1'";
			     	$sql.=" where assignmentTakeId=".$pk; 
			     	$con->Query($sql);
			    }
				  $i=1;
				  
//				  $sql="SELECT active from assignmenttakequestions where fk_assignmentTake=".$pk;
//				  $dhomeworks=$con->Query($sql);
				  
					while($i<=$number)
			 	  {
//			 	  	$dhomeworkr=mysql_fetch_row($dhomeworks);
//			 	  	
//			 	  	if($dhomeworkr[0]<5)
//			 	  	{
				      $useranswer=$_POST["useranswer_".$i];
				   		$q0=$_POST["txt_array_0_" . $i];
				   		$q1=$_POST["txt_array_1_" . $i];
				   		$q2=$_POST["txt_array_2_" . $i];
				   		$q3=$_POST["txt_array_3_" . $i];
				   		$q4=$_POST["txt_array_4_" . $i];
				   		$q_type=$_POST["txt_problemType_" . $i];
				   		$active=(int)$_POST["active_". $i];
				   		$result=(int)$_POST["result_". $i];
				   		if($result>=1 && $result<=2) 
				   		{
				   			$cornum++;
				   		}
				   		$sql="update assignmenttakequestions";
				   		$sql.=" set fk_problem=".$q_type.",array_0=\"".$q0."\" ,array_1=\"".$q1."\",array_2='".$q2."',array_3='".$q3."',array_4='".$q4."',useranswer='".$useranswer."',active=".$active.",result=".$result;
				   		$sql.=" where fk_assignmentTake=".$pk." and number=".$i; 
				   		$con->Query($sql);
//			     	}
			   		$i++;
			 	  }
			 	
				}else
				{
				  $sql="INSERT INTO assignmenttakes";
				  $sql.=" ( fk_user_taker,fk_assignment,started,finished,done" . ( $cid=="" ? "" : ",fk_course" ) . ")";
			  	$sql.=" VALUES ( " . $b->User->UserId . "," . $_POST["id"] . ",'" .$started ."','" . $finished . "'," . $done . " " . ( $cid=="" ? "" : ( "," . $cid ) ) . ")";
			  	$con->Query($sql);
			  	$sql="SELECT assignmentTakeId";
				  $sql.=" FROM assignmenttakes";
				  $sql.=" WHERE ( fk_user_taker=" . $b->User->UserId . "  and fk_assignment=". $_POST["id"] .") order by assignmentTakeId desc limit 1";
				  $ds=$con->Query($sql); 
				  while($dr=mysql_fetch_row($ds))
				  {
				  	$pk=$dr[0];
				  }
				  $i=1;
			    while($i<=$number)
			 	  {
			   		$useranswer=$_POST["useranswer_" . $i];  
			   		//question array values
			   		$q0=$_POST["txt_array_0_" . $i];
			   		$q1=$_POST["txt_array_1_" . $i];
			   		$q2=$_POST["txt_array_2_" . $i];
			   		$q3=$_POST["txt_array_3_" . $i];
			   		$q4=$_POST["txt_array_4_" . $i];
			   		$q_type=$_POST["txt_problemType_" . $i];
			   		$active=(int)$_POST["active_". $i];
			   		$result=(int)$_POST["result_". $i];
			   		if($result>=1 && $result<=2) 
			   		{
			   			$cornum++;
			   		}
			   		$sql="INSERT INTO assignmenttakequestions";
			   		$sql.=" ( fk_assignmentTake,number,fk_problem,active,result,useranswer,array_0,array_1,array_2,array_3,array_4 )";
			   		$sql.=" VALUES ( " . $pk . "," . $i . "," . $q_type . ",".$active.",".$result.",'" . $useranswer . "',\"" . $q0 . "\",'" . $q1 . "','" . $q2 . "','" . $q3 . "','" . $q4 . "' )";
			   		$con->Query($sql);
			   		//echo mysql_affected_rows();
			   		$i++;
			 	 }
			 }
			   $sql="update assignmenttakes";
			   $sql.=" set correctAnswers=".$cornum.",incorrectAnswers=".($number-$cornum).",correctAnswersch=".$cornum;
			   $sql.=" where assignmentTakeId=".$pk; 
			   $con->Query($sql);
			   $con->Dispose();
			   echo '{"cnums":"'.$cornum.'","atid":"'.$pk.'"}';
			}
		}else {
			echo '{"cnums":"-2","atid":"-2"}';
		}
?>