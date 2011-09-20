import module namespace x = "http://www.zorba-xquery.com/modules/xml";

x:parse-xml-fragment("<?xml version='1.0'?>
<!DOCTYPE note [
<!ELEMENT note (to,from,heading,body)>
<!ELEMENT to (#PCDATA)>
<!ELEMENT from (#PCDATA)>
<!ELEMENT heading (#PCDATA)>
<!ELEMENT body (#PCDATA)>
]>
<note>
<incorrect>Element not in DTD</incorrect>
</note>
", 
"d")
