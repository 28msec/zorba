import module namespace jsv = "http://jsound.io/modules/validate"; 

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

return jsv:jsd-validate( $jsd, "a-string-array", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
