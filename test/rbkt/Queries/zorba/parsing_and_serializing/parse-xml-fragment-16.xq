import module namespace x = "http://www.zorba-xquery.com/modules/xml";
import schema namespace opt = "http://www.zorba-xquery.com/modules/xml-options";

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
