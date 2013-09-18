
import module namespace file = "http://expath.org/ns/file";
import module namespace x = "http://zorba.io/modules/xml";
import schema namespace opt = "http://zorba.io/modules/xml-options";

let $xml-frags1 := x:parse(file:read-text(fn:resolve-uri("levels.xml")),
<opt:options>
<opt:parse-external-parsed-entity/>
</opt:options>)

let $xml-frags2 := <a></a>

return $xml-frags2
