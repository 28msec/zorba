import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      (:
       : Test the subtype assertion where one type (type-1) has a key ("foo")
       : inherited from its base type (base-1) and the other type (type-2) has
       : the same key ("foo") directly.
       :)
      {
        "$name" : "base-1",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "float"
          }
        }
      },
      {
        "$name" : "type-1",
        "$kind" : "object",
        "$baseType" : "base-1",
        "$content" : {
          "bar" : {
            "$type" : "boolean"
          }
        }
      },
      {
        "$name" : "type-2",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "string"
          }
        }
      },

      {
        "$name" : "base",
        "$kind" : "object",
        "$content" : {
          "f1" : {
            "$type" : "type-1"
          }
        }
      },
      {
        "$name" : "derived",
        "$kind" : "object",
        "$baseType" : "base",
         (:
          : "base" can not be a base type of "derived" because:
          : + the type of derived's "f1" (type-2) is not a subtype of the type
          :   of base's "f1" (type-1) because:
          : + the type of type-2's "foo" (string) is not a subtype of the type
          :   of type-1's "foo" (float)
          :)
        "$content" : {
          "f1" : {
            "$type" : "type-2"
          }
        }
      }

    ]
  }

let $instance := "doesn't matter"

return jsd:validate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
