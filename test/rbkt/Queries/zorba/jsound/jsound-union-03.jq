import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "integer-or-string",
        "$kind" : "union",
        "$content" : [ "integer", "string" ]
      },
      {
        "$name" : "ios-array",
        "$kind" : "array",
        "$content" : [ "integer-or-string" ]
      }
    ]
  }

let $instance := [ 42, "forty-two" ]

return jsd:validate( $jsd, "ios-array", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
