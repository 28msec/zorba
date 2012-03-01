import module namespace f = "http://expath.org/ns/file";

let $s := f:read-text(fn:resolve-uri("mydata.xml"))
let $p := fn:parse-xml($s)
let $l := fn:string-length($s)
return ($p, $l)
