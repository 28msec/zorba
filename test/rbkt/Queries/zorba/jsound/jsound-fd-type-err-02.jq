import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "obj-a",
        "$kind" : "object",
        "$content" : {
          "f1" : {
            "$type" : "string"
          }
        }
      },
      {
        "$name" : "obj-b",
        "$kind" : "object",
        "$content" : {
          "f1" : {
            "$type" :"integer"
          }
        }
      },
      {
        "$name" : "base-2",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "obj-a"
          }
        }
      },
      {
        "$name" : "derived-2",
        "$kind" : "object",
        "$baseType" : "base-2",
        "$content" : {
          "foo" : {
            "$type" : "obj-b"
          }
        }
      }
    ]
  }

let $instance := "doesn't matter"

return jsd:jsd-validate( $jsd, "derived-2", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
