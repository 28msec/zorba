import module namespace jsd = "http://jsound.io/modules/jsound"; 

let $jsd :=
  {
    "$namespace" : "http://zorba.io/modules/images/",
    "$types" : [
      {
        "$name" : "pointType",
        "$kind" : "array",
        "$content" : [ "integer" ],
        "$minLength" : 2,
        "$maxLength" : 2
      },
      {
        "$name" : "line",
        "$kind" : "object",
        "$content" : {
          "start" : {
            "$type" : "pointType"
          },
          "end" : {
            "$type" : "pointType"
          },
          "lineWidth" : {
            "$type" : "integer",
            "$default" : 1
          }
        }
      }  
    ]
  }

let $instance := 
  {
    "start" : [ 1, 2 ],
    "end" : [ 3, 4 ]
  }

return jsd:annotate( $jsd, "line", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
