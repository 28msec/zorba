import module namespace jn = "http://www.jsoniq.org/functions";

let $object :=
{
 "foo" : "bar",
 "bar" : { "foo" : [1] },
 "foobar" : "foo" 
}
return jn:descendant-pairs($object)

