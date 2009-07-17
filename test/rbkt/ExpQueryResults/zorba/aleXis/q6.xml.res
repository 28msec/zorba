<test><q1><html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>[ #426885 ] Definition list w/Center crashes</title>
</head>
<body>
<center>
<h1>Heading 1</h1>
</center>
<dl>
<dt><img src="redball.gif"></img><b>Term 1</b></dt>
<dt><img src="redball.gif"></img><b>Term 2</b></dt>
<dd>
<hr></hr></dd>
</dl>
<center>
<h1>Heading 2</h1>
</center>
<div style="margin-left: 2em">
<dl>
<dt><img src="redball.gif"></img><b>Term 3</b></dt>
<dt><img src="redball.gif"></img><b>Term 4</b></dt>
<dd>
<hr></hr></dd>
</dl>
</div>
</body>
</html></q1><q2><html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>[#427663] Line endings not supported correctly</title>
</head>
<body>
<p>This is a carriage return^MThis is a Unix line-ending This is a
DOS line ending^M</p>
</body>
</html></q2></test>
