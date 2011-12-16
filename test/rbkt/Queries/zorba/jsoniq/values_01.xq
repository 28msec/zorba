import module namespace j = "http://www.jsoniq.org/functions";

j:values(j:parse-json('{ "foo" : "bar" }')),
j:values(j:parse-json('[ "foo" ]')),
j:values(j:pairs(j:parse-json('{ "foo" : "blub" }')))
