import module namespace j = "http://www.jsoniq.org/functions";

let $obj := j:parse-json('{ "foo" : "bar" }')
let $arr := j:parse-json('[ "foo" , "bar" ]')
return (fn:boolean($obj), fn:boolean($arr), fn:boolean(j:pairs($obj)))
