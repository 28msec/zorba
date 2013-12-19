import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "foo",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "decimal"
          }
        },
        "$open" : false
      },
      {
        "$name" : "bar",
        "$kind" : "object",
        "$baseType" : "foo",
        "$content" : {
          "foo" : {
            "$type" : "integer"
          }
        },
        "$open" : true (: can not set back to true :)
      }
    ]
  }

let $instance := "foo"

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
