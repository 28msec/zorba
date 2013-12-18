import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "even",
        "$baseType" : "integer",
        "$constraints" : [
          "$$ mod 2 eq 0",
          "$$ ne 42"
        ]
      }
    ]
  }

let $instance := 42 (: must not be 42 :)

return jsd:annotate( $jsd, "even", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
