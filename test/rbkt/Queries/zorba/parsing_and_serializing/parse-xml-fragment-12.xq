import module namespace z = "http://www.zorba-xquery.com/modules/xml";

let $var := z:parse-xml-fragment("<?xml version='1.0'?>
<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>", 
"e")
return <fragment>{ $var }<count>{ count($var) }</count></fragment>