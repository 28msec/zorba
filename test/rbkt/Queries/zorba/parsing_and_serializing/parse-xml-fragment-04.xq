import module namespace x = "http://www.zorba-xquery.com/modules/xml";

x:parse-xml-fragment("
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>
", 
"e")
