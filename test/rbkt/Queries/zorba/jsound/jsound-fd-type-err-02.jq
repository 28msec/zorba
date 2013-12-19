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
            "$type" : "integer"
          }
        }
      },
      {
        "$name" : "base",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "obj-a"
          }
        }
      },
      {
        "$name" : "derived",
        "$kind" : "object",
        "$baseType" : "base",
         (:
          : "base" can not be a base type of "derived" because:
          : + the type of derived's "foo" (obj-b) is not a subtype of the type
          :   of base's "foo" (obj-a) because:
          : + the type of obj-b's "f1" (integer) is not a subtype of the type
          :   of obj-a's "f1" (string)
          :)
        "$content" : {
          "foo" : {
            "$type" : "obj-b"
          }
        }
      }
    ]
  }

let $instance := "doesn't matter"

return jsd:validate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
