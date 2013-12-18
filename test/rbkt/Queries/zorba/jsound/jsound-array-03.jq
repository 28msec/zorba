import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "array",
        "$name" : "a-string-array",
        "$content" : [ "string" ]
      }
    ]
  }

let $instance := [ "", "a", "abc", 123 (: must be string :) ]

return jsd:validate( $jsd, "a-string-array", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
