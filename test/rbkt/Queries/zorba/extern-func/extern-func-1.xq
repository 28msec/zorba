import module namespace file = "http://expath.org/ns/file";

declare variable $xqdocXmlPath as xs:string := fn:concat("", file:directory-separator(), "xml");

$xqdocXmlPath = "/xml" or $xqdocXmlPath = "\xml"
