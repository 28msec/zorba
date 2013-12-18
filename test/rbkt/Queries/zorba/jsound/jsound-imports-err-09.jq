import module namespace jsd = "http://jsound.io/modules/jsound"; 

declare variable $rbktPath as xs:string external;

let $location :=
  concat( $rbktPath, "/Queries/zorba/jsound/schemas/tiny-int.jsd" )

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$imports" : [
      {
        "$namespace" : "http://www.example.com/tiny-int",
        "$prefix" : "tint",
        "$location" : $location
      },
      {
        "$namespace" : "http://www.example.com/tiny-int",
        "$prefix" : "tint2",
        "$location" : "bar"
      }
    ],
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "integer"
      }
    ]
  }

let $instance := 5

return jsd:validate( $jsd, "foo", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
