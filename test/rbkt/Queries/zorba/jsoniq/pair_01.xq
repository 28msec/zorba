import module namespace j = "http://jsoniq.org/functions";

let $j as object()? := j:parse-json('{ "foo": "bar" }')
return (empty($j("bar")), $j("foo"))

