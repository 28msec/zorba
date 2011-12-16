import module namespace j = "http://www.jsoniq.org/functions";

j:value(j:pairs(j:parse-json('{ "foo" : "bar" }')))
