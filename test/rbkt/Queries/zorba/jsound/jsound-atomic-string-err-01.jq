import module namespace jsv = "http://jsound.io/modules/validate"; 

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

return jsv:jsd-validate( $jsd, "a-string", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
