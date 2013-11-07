import module namespace jsv = "http://jsound.io/modules/validate"; 

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
        "$content" : 
          {
            "start" :
              {
                "$type" : "pointType"
              },
            "end" :
              {
                "$type" : "integer"
              },
            "strokeWidth" : 
              {
                "$type" : "double",
                "$optional" : true
              },
            "antiAliasing" : 
              {
                "$type" : "boolean",
                "$optional" : true
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
return jsv:jsd-validate( $jsd, "line", $instance )

(: vim:set syntax=xquery et sw=2 ts=2: :)
