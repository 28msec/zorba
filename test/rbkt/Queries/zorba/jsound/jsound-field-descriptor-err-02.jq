import module namespace jsv = "http://jsound.io/modules/validate"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "foo",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "string",
            "$optional" : "true" (: must be boolean :)
          }
        }
      }
    ]
  }

let $instance := "foo"

return jsv:jsd-validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
