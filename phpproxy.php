<?
require_once("base/class_http.php"); 
$proxy_url = isset($_GET['proxy_url'])?$_GET['proxy_url']:false;
if (!$proxy_url) {    
	   header("HTTP/1.0 400 Bad Request"); 
	   echo "proxy.php failed because proxy_url parameter is missing"; 
	   exit();
} 
if (!$h = new http()) 
{    
	header("HTTP/1.0 501 Script Error");
  echo "proxy.php failed trying to initialize the http object";
	exit();
} 
$h->url = $proxy_url;
$h->postvars = $_POST;
if (!$h->fetch($h->url)) 
{    
	header("HTTP/1.0 501 Script Error");
	echo "proxy.php had an error attempting to query the url";
	exit();
} 
$ary_headers = split("\n", $h->header);
foreach($ary_headers as $hdr) { header($hdr); }
echo $h->body;
?>