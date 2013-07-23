declare variable $sales := jn:parse-json('{"foo" : ["bar"], "order_id" : 42, "customer" : "Jackelyn Luckey"}');

$sales("order_id") eq 42
