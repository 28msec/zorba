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

let $instance := [ 2, 4, 6 (: must be <= 5 :), 4, 2 ]

return jsd:annotate( $jsd, "bar", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
