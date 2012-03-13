import module namespace j = "http://www.jsoniq.org/functions";

for $i in j:names(j:parse-json('{ "foo" : "bar" }'))
return $i
