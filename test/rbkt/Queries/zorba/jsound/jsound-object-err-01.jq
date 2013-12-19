import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema/",
    "$types" : [
      {
        "$name" : "base",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "integer"
          }
        },
        "$open" : false
      },
      {
        "$name" : "derived",
        "$kind" : "object",
        "$baseType" : "base",
        "$content" : {
          "bar" : { (: new key not allowed when base.$open = false :)
            "$type" : "integer"
          }
        }
      }  
    ]
  }

let $instance := 
  {
    "foo" : 42
  }

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
