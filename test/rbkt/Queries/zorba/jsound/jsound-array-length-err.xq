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
    "start": [1, 2, 5],
    "end": 5
  }

return
  jsv:jsd-valid($jsd, "line", "http://zorba.io/modules/images/", $instance)
