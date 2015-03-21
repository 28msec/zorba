import module namespace fs = "http://expath.org/ns/file";

declare namespace xqdoc = "http://www.xqdoc.org/1.0";

for $file at $i in fs:list(".")
where fs:is-directory($file)

for $name in fs:list($file || "/modules/xml")
let $xqdoc := parse-xml(fs:read-text($file || "/modules/xml/" || $name))
where empty($xqdoc//xqdoc:date)
(: instance of element(xqdoc:xqdoc)) :)
return fs:delete($file || "/modules/xml/" || $name); 


