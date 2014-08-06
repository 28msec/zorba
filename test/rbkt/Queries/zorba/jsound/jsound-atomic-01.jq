import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "small-number",
        "$baseType" : "integer"
      }
    ]
  }

let $instance := 5

return jsd:validate( $jsd, "small-number", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
