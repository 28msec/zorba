(: gather all links from a html :)

import module namespace file = "http://expath.org/ns/file";
declare namespace output="http://www.w3.org/2010/xslt-xquery-serialization";
declare namespace err="http://www.w3.org/2005/xqt-errors";


let $content := file:read-text(fn:resolve-uri("http-client-doc.htm"))
let $search := fn:analyze-string($content, "(&lt;|&amp;lt;|<)(((a|link|area).+?href)|((script|img).+?src))=([""'])(.*?)\7")
for $s in $search//fn:group[@nr=8]/fn:string()
return ($s,"
")
