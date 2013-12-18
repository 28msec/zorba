import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "object",
        "$name" : "foo",
        "$content" : {
          "k1" : {
            "$type" : "integer"
          }
        },
        "$constraints" : [ "$$ mod 2 eq 0" ] (: $$ can not be object :)
      }
    ]
  }

let $instance := { "k1" : 41 }

return jsd:annotate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
