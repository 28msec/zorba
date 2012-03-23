import module namespace j = "http://www.jsoniq.org/functions";

for $i in j:keys(j:parse-json('{ "foo" : "bar" }'))
return $i
