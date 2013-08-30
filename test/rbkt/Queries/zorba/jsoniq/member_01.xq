import module namespace j = "http://jsoniq.org/functions";

let $j as item()? := j:parse-json('[ "foo", "bar" ]')
return (empty($j(0)), $j(1), empty($j(3)))
