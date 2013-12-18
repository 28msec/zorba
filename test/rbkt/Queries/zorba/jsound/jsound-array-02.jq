import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer",
        "$maxInclusive" : 5
      },
      {
        "$kind" : "array",
        "$name" : "bar",
        "$content" : [ "foo" ]
      }
    ]
  }

let $instance := [ 1, 2, 3, 4, 5 ]

return jsd:validate( $jsd, "bar", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
