import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "a-string",
        "$baseType" : "string"
      }
    ]
  }

let $instance := 42 (: must be string :)

return jsd:validate( $jsd, "a-string", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
