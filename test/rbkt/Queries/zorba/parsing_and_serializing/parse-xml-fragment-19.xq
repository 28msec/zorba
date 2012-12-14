(: 
  Test that the backwards-compatible parse-xml-fragment() function works.
:)
import module namespace z = "http://www.zorba-xquery.com/modules/xml";

z:parse-xml-fragment("<from1>Jani</from1>
<from2>Jani</from2>
<from3>Jani</from3>",
"e")
