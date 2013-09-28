<?php
	 include_once("base/databaseManager.php");
	 include_once("base/baseForm.php");
   $selectedId=$_GET["selectedId"];
   $targetSelId=$_GET["targetSelId"];
   $uid=$_GET["uid"];
   $title=$_GET["title"];
   $uidI=$_GET["uidI"];
   $cidI=$_GET["cidI"];
   $pwd=$_GET["pwd"];
   $cid=$_GET["cid"];
   
   $titleId="";
   
   $responseText="{";
   $count=0;
   $con=new DatabaseManager();
   
   if(strcmp($selectedId,"")!=0&&strcmp($targetSelId,"title")==0){
   	 $sql="select distinct title,courseId from courses where active=1 and fk_user_teacher=".$selectedId." order by title asc";
   	 $dsTitle=$con->Query($sql);
   	 while($drTitle=mysql_fetch_row($dsTitle)) {
   	 		$titleId=$selectedId;
   	 		$titleId.=",@^&";
   	 		$titleId.=$drTitle[0];
   	 		$titleId.="&^@,";
   	 		
   	 		if($count>0) {
   	 			$responseText.=",";
   	 		}
   	 		$responseText.="'";
   	 		$responseText.=$titleId;
   	 		$responseText.="':'";
   	 	  $responseText.=$drTitle[0];
   	 	  $responseText.="'";
   	 		$count++; 		
   	 }
   	 $responseText.="}";
   	 print $responseText;
   }
   
   if(strcmp($uid,"")!=0&&strcmp($title,"")!=0) {
   	 $sql="select distinct firstName,lastName,startDate,endDate,courseId";
   	 $sql.=" from courses,users where courses.active=1 and fk_user_teacher=";
   	 $sql.=$uid." and title='".$title."' and fk_user_teacher=userid";
   	 $dsCourseInfo=$con->Query($sql);
   	 $drCourseInfo=mysql_fetch_row($dsCourseInfo);
		 $responseText="{'";
		 $responseText.=$drCourseInfo[4];
		 $responseText.="':'";
		 $responseText.=$drCourseInfo[4];
		 $responseText.="','";
		 $responseText.=$drCourseInfo[1].'&nbsp;'.$drCourseInfo[0];
		 $responseText.="':'";
		 $responseText.=$drCourseInfo[1].'&nbsp;'.$drCourseInfo[0];
		 $responseText.="','";
		 $responseText.=$title;
		 $responseText.="':'";
		 $responseText.=$title;
		 $responseText.="','";
		 $responseText.=$drCourseInfo[2];
		 $responseText.="':'";
		 $responseText.=$drCourseInfo[2];
		 $responseText.="','";
		 $responseText.=$drCourseInfo[3];
		 $responseText.="':'";
		 $responseText.=$drCourseInfo[3];
		 
		 $flagP="yes";
		 $sql="select * from courses where active=1 and courseId=".$drCourseInfo[4];
  	 $dsHavePwd=$con->Query($sql);
	   while($drHavePwd=mysql_fetch_row($dsHavePwd))
		 {	
			 if(strcmp($drHavePwd[8],'')==0)
			 {
					$flagP="no";
			 }
		 }
			
		 $responseText.="','";
		 $responseText.=$flagP;
		 $responseText.="':'";
		 $responseText.=$flagP;
		 $responseText.="'}";
		 print $responseText;
   }
   
   if(strcmp($cid,"")!=0) {
   	 $sql="select distinct firstName,lastName,startDate,endDate,courseId,title";
   	 $sql.=" from courses,users where courses.active=1 and courseId=";
   	 $sql.=$cid." and fk_user_teacher=userid";
   	 $dsCourseInfo=$con->Query($sql);
   	 if($drCourseInfo=mysql_fetch_row($dsCourseInfo)){
			 $responseText="{'";
			 $responseText.=$drCourseInfo[4];
			 $responseText.="':'";
			 $responseText.=$drCourseInfo[4];
			 $responseText.="','";
			 $responseText.=$drCourseInfo[1].'&nbsp;'.$drCourseInfo[0];
			 $responseText.="':'";
			 $responseText.=$drCourseInfo[1].'&nbsp;'.$drCourseInfo[0];
			 $responseText.="','";
			 $responseText.=$drCourseInfo[5];
			 $responseText.="':'";
			 $responseText.=$drCourseInfo[5];
			 $responseText.="','";
			 $responseText.=$drCourseInfo[2];
			 $responseText.="':'";
			 $responseText.=$drCourseInfo[2];
			 $responseText.="','";
			 $responseText.=$drCourseInfo[3];
			 $responseText.="':'";
			 $responseText.=$drCourseInfo[3];
			 
			 $flagP="yes";
			 $sql="select * from courses where active=1 and courseId=".$drCourseInfo[4];
	  	 $dsHavePwd=$con->Query($sql);
		   while($drHavePwd=mysql_fetch_row($dsHavePwd))
			 {	
				 if(strcmp($drHavePwd[8],'')==0)
				 {
						$flagP="no";
				 }
			 }
				
			 $responseText.="','";
			 $responseText.=$flagP;
			 $responseText.="':'";
			 $responseText.=$flagP;
			 $responseText.="'}";
		 }else{
		 	 $responseText="{'";
			 $responseText.="a";
			 $responseText.="':'";
			 $responseText.="";
			 $responseText.="','";
			 $responseText.="b";
			 $responseText.="':'";
			 $responseText.="";
			 $responseText.="','";
			 $responseText.="This class doesn\'t exist!";
			 $responseText.="':'";
			 $responseText.="<center><font size=\"2\" color=\"red\"><b> This course doesn\'t exist</b></font></center>";
			 $responseText.="','";
			 $responseText.="c";
			 $responseText.="':'";
			 $responseText.="";
			 $responseText.="','";
			 $responseText.="d";
			 $responseText.="':'";
			 $responseText.="";
			 
			 $flagP="no";
				
			 $responseText.="','";
			 $responseText.=$flagP;
			 $responseText.="':'";
			 $responseText.=$flagP;
			 $responseText.="'}";
		 }
		 print $responseText;
   }
   
   if(strcmp($uidI,"")!=0&&strcmp($cidI,"")!=0) {
	   	 		//validate form
			$sql="select password from courses";
			$sql.=" where courseId=".(int)$cidI;
			$dss=$con->Query($sql);
			$success="";
			while($drs=mysql_fetch_row($dss))
	    {
	    	if(strcmp($pwd,$drs[0])==0)
	    	{
	    		$tcount=0;
					$sql="SELECT fk_course,active";
		  		$sql.=" FROM studentenrollment";
		  		$sql.=" where fk_user=".$uidI." and fk_course='".$cidI. "' and active=1";;
		  		$dsComfirm=$con->Query($sql);
		  		while($drComfirm=mysql_fetch_row($dsComfirm))
		  		{
			 			$tcount++;
		  		}
		  		if($tcount<1) {
						$sql="INSERT INTO studentenrollment";
						$sql.=" (fk_user,fk_course)";
						$sql.=" VALUES ( " .$uidI . ",'" . $cidI . "')";
						$con->Query($sql);			
					}		
					$success="a";   		
	    	}
	    	else if(strcmp($pwd,$drs[0])!=0)
	    	{
	    		$success="b";
	    		print $success;
	    	}
	    }
	    print $success;
   }
   
   $con->Dispose();
?>