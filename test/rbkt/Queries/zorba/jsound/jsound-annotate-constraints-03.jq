import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "even",
        "$baseType" : "integer",
        "$constraints" : [ "$$ mod 2 eq 0" ]
      },
      {
        "$kind" : "atomic",
        "$name" : "not-42",
        "$baseType" : "even",
        "$constraints" : [ "$$ ne 42" ]
      }
    ]
  }

let $instance := 41 (: must be even :)

return jsd:annotate( $jsd, "not-42", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
