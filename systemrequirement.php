<?
	include_once("base/baseForm.php");
	
	$b->AddCrumb("Browser Setup for MathPASS","");
	$b->MainMenuIndex=14;
	

	$b->RenderTemplateTop();
?>
<p>MathPASS works well in MS Internet Explorer and Firefox Browser. MathPASS adopts W3C's MathML to represent mathematical expression.
To work with MathPASS, you should set up your browser as the following directions. To use MATHPASS on a MAC computer, you MUST use the Firefox browser. 
MATHPASS does NOT work on a MAC with Safari or any other browser.
</p>
<ul>

<li><h3>Setting Up MS Internet Explorer (IE)</h3>
<p><a href="http://www.dessci.com/en/products/mathplayer/check.htm" target="_blank">Click here</a> to check if Mathplayer plugin for MathML have been Installed. If not, you need to <a href="http://www.dessci.com/en/products/mathplayer/download.htm" target="_blank">Install MathPlayer for MathML</a>
plugins.</p>
</li>
<li><h3>Setting Up Firefox (Recommended)</h3>
<p>	
<a href="http://www.mozilla.com" target="_blank">Firefox 1.5 and above</a> is required. 
Firefox supports MathML natively, all you need is to download <a href="http://web.mit.edu/atticus/www/mathml/mit-mathml-fonts-1.0-fc1.msi" target="_blank">math fonts</a> and <a href="http://web.mit.edu/is/topics/webpublishing/mathml/fonts-win.html">install the downloaded math fonts</a>.
After installing the fonts, test MathML display on your browser by visiting 
<a href="http://www.mozilla.org/projects/mathml/demo/texvsmml.xhtml" target="_blank">this page</a>.</li>

</ul>


<?
	$b->RenderTemplateBottom();
	$b->Dispose();
?>