import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "date-2013",
        "$baseType" : "date",
        "$minInclusive" : xs:date("2013-01-01"),
        "$maxInclusive" : xs:date("2013-12-31")
      }
    ]
  }

let $instance := "2013-11-18"
let $options := { "cast-atomic-values" : true }
return jsd:validate( $jsd, "date-2013", $instance, $options )

(: vim:set syntax=xquery et sw=2 ts=2: :)
