import module namespace f = "http://expath.org/ns/file";

let $json := jn:parse-json(f:read-text(fn:resolve-uri("encoded_01.json")))
let $obj := jn:decode-from-roundtrip($json)
return
  $obj("serialized XML")
