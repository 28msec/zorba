import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://www.example.com/my-schema",
    "$types" : [
      {
        "$kind" : "union",
        "$content" : [ "dateTime", "null" ],
        "$name" : "dateTime-or-null"
      }
    ]
  }
return
(
  jsd:validate( $jsd, "dateTime-or-null", current-dateTime() ),
  jsd:validate( $jsd, "dateTime-or-null", null ),
  jsd:validate( $jsd, "dateTime-or-null", 1 )
)
