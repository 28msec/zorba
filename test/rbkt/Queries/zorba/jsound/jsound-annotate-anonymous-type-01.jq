import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$name" : "foo",
        "$kind" : "object",
        "$content" : {
          "k1" : {
            "$type" :
              {
                "$kind" : "atomic",
                "$baseType" : "integer",
                "$maxInclusive" : 5
              }
          }
        }
      }
    ]
  }

let $instance := { "k1" : 6 (: must be <= 5 :) }

return jsd:annotate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
