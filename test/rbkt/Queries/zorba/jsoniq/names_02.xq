import module namespace j = "http://www.jsoniq.org/functions";

for $i in j:pairs(j:parse-json('{ "foo" : "bar" }'))
return j:name($i)
