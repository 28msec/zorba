import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "time",
        "$explicitTimezone" : "required"
      },
      {
        "$kind" : "atomic",
        "$name" : "bar",
        "$baseType" : "foo",
        "$explicitTimezone" : "prohibited"
      }
    ]
  }

let $instance := xs:time( "11:42:00" )

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
