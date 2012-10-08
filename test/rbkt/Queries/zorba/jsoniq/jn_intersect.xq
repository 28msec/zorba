import module namespace libjn = "http://jsoniq.org/function-library";

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
return libjn:intersect(($object, $object2, $object3))

