import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

x:parse("<?xml version='1.0'?>
<!DOCTYPE note [
<!ELEMENT note (#PCDATA)>
<!ATTLIST note nmt NMTOKENS #REQUIRED>
]>
<note nmt='aaa'/>
", 
  <opt:options>
    <opt:DTD-validate/>
  </opt:options>
)
