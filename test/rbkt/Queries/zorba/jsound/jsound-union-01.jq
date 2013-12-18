import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "integer-or-string",
        "$kind" : "union",
        "$content" : [ "integer", "string" ]
      }
    ]
  }

let $instance := 42

return jsd:validate( $jsd, "integer-or-string", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
