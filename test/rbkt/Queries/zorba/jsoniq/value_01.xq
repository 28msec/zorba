import module namespace j = "http://jsoniq.org/functions";

let $json := j:parse-json('{ "foo" : "bar" }')
let $keys := j:keys($json)
return $json($keys[1])
