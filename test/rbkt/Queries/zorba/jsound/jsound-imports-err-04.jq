import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$imports" : [
      {
        "$namespace" : true, (: must be string :)
        "$prefix" : "other"
      }
    ],
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer"
      }
    ]
  }

let $instance := 42

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
