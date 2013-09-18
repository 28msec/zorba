import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse("<?xml version='1.0'?>
<!DOCTYPE note [
<!ELEMENT note (to,from,heading,body)>
<!ELEMENT to (#PCDATA)>
<!ELEMENT from (#PCDATA)>
<!ELEMENT heading (#PCDATA)>
<!ELEMENT body (#PCDATA)>
]>
<note>
<to>Tove</to>
<from>Jani</from>
<heading>Reminder</heading>
<body>Don't forget me this weekend</body>
</note>
", 
  <opt:options>
    <opt:DTD-validate/>
  </opt:options>
)
