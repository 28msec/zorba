import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer",
        "$maxExclusive" : 42
      },
      {
        "$kind" : "atomic",
        "$name" : "bar",
        "$baseType" : "foo",
        "$maxExclusive" : 43 (: must be <= 42 :)
      }
    ]
  }

let $instance := 1

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
