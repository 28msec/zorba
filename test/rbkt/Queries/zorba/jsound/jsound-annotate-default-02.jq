import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://zorba.io/modules/images/",
    "$types" : [
      {
        "$name" : "base",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "integer",
            "$default" : 1
          }
        }
      },
      {
        "$name" : "derived",
        "$kind" : "object",
        "$baseType" : "base",
        "$content" : {
          "foo" : {
            "$type" : "integer",
            "$default" : 2
          }
        }
      }
    ]
  }

let $instance := { } (: { "foo" : 2 } should be added :)

return jsd:annotate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
