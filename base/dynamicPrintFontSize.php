<?php  header("Content-Type: text/css"); ?>
TD
{
	font-size:<? echo($_GET["fontSize"]); ?>;
}
H1
{
	font-size:<? echo(((int)$_GET["fontSize"])+3); ?>;
}
H2
{
	font-size:<? echo(((int)$_GET["fontSize"])+1); ?>;
}
P
{
	font-size:<? echo($_GET["fontSize"]); ?>;
}