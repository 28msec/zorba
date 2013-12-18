import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema/",
    "$types" : [
      {
        "$name" : "decimal-100",
        "$kind" : "atomic",
        "$baseType" : "decimal",
        "$maxInclusive" : 100
      },
      {
        "$name" : "integer-101",
        "$kind" : "atomic",
        "$baseType" : "integer",
        "$maxInclusive" : 101
      },
      {
        "$name" : "base",
        "$kind" : "object",
        "$content" : {
          "foo" : {
            "$type" : "decimal-100"
          }
        },
        "$open" : false
      },
      {
        "$name" : "derived",
        "$kind" : "object",
        "$baseType" : "base",
        "$content" : {
          "foo" : {
            "$type" : "integer-101" (: incompatible $maxInclusive value :)
          }
        }
      }  
    ]
  }

let $instance := 
  {
    "foo" : 42
  }

return jsd:validate( $jsd, "derived", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
