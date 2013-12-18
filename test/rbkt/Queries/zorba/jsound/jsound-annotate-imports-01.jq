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
      }
    ],
    "$types" : [
      {
        "$name" : "tiny-even",
        "$kind" : "atomic",
        "$baseType" : "tint:tiny-int",
        "$constraints" : [ "$$ mod 2 eq 0" ]
      }
    ]
  }

let $instance := 6 (: must be <= 5 :)

return jsd:annotate( $jsd, "tiny-even", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
