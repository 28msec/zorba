import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "base",
        "$kind" : "array",
        "$content" : [ "string" ],
        "$maxLength" : 2
      },
      {
        "$name" : "derived",
        "$kind" : "array",
        "$baseType" : "base",
        "$content" : [ "string" ],
        "$maxLength" : 3 (: must be <= 2 :)
      }
    ]
  }

let $instance := [ "foo" ]

return jsd:jsd-validate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
