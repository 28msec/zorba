import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "an-integer",
        "$baseType" : "integer"
      }
    ]
  }

let $instance := "42"
let $options := { "cast-atomic-values" : true }
return jsd:validate( $jsd, "an-integer", $instance, $options )

(: vim:set syntax=xquery et sw=2 ts=2: :)
