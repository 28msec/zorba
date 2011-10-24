import module namespace x = "http://www.zorba-xquery.com/modules/xml";

x:parse-xml-fragment("<?xml version='1.0'?>
<!DOCTYPE note [
<!ELEMENT note (#PCDATA)>
<!ATTLIST note nmt NMTOKENS #REQUIRED>
]>
<note nmt='aaa'/>
", 
"d")
