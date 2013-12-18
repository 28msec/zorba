import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer",
        "$minExclusive" : 42
      },
      {
        "$kind" : "atomic",
        "$name" : "bar",
        "$baseType" : "foo",
        "$minExclusive" : 41 (: must be >= 42 :)
      }
    ]
  }

let $instance := 12345

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
