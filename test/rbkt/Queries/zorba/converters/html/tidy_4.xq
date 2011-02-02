import module namespace html="http://www.zorba-xquery.com/modules/convertors/html";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/html-options";

html:parse('<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html>
<head>
  <title>[#427663] Line endings not supported correctly</title>
</head>
<body>
<p>This is a carriage return^MThis is a Unix line-ending
This is a DOS line ending^M

</body>
</html>')