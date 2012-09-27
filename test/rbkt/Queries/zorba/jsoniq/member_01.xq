import module namespace j = "http://jsoniq.org/functions";

let $j := j:parse-json('[ "foo", "bar" ]')
return (empty(j:member($j, 0)), j:member($j, 1), empty(j:member($j, 3)))
