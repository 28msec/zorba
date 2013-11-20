import module namespace jsv = "http://jsound.io/modules/validate"; 

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

return jsv:jsd-validate( $jsd, "even", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
