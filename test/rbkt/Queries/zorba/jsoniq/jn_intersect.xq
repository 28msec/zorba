import module namespace jn = "http://www.jsoniq.org/functions";

let $object :=
{
 "foo" : "bar",
 "bar" : { "foo" : [1] },
 "foobar" : "foo" 
}
let $object2 :=
{
 "bar" : { "bar" : [2] },
 "foobar" : "foo" 
}
let $object3 :=
{
 "foo" : "bar",
 "bar" : [ "this" ]
}
return jn:intersect(($object, $object2, $object3))

