import module namespace j = "http://www.jsoniq.org/functions";

j:values(j:parse-json('{ "foo" : "bar" }')),

j:members(j:parse-json('[ "foo" ]'))
