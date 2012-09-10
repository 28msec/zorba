import module namespace libjn = "http://www.jsoniq.org/function-library";

let $object :=
{
 "foo" : "bar",
 "bar" : { "foo" : [1] },
 "foobar" : "foo" 
}
return libjn:descendant-objects($object)

