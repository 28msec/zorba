import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema/",
    "$types" : [
      {
        "$name" : "foo",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "integer",
            "$maxInclusive" : 100 (: illegal key for field descriptor :)
          }
        }
      }
    ]
  }

let $instance := 
  {
    "foo" : 42
  }

return jsd:validate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
