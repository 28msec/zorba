import module namespace jsv = "http://jsound.io/modules/validate"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "atomic",
        "$name" : "foo",
        "$baseType" : "decimal",
        "$fractionDigits" : -1 (: must be >= 0 :)
      }
    ]
  }

let $instance := 12345

return jsv:jsd-validate( $jsd, "a-string-enum", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
