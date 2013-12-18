import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "even",
        "$baseType" : "integer",
        "$constraints" : [ "$$ modulus 2 eq 0" ] (: "modulus" is invalid :)
      }
    ]
  }

let $instance := 42

return jsd:validate( $jsd, "even", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
