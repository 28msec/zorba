import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer",
        "$minInclusive" : 5
      }
    ]
  }

let $instance := 4 (: must be >= 5 :)

return jsd:annotate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
