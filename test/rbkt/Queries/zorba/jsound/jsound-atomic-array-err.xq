import module namespace jsv = "http://jsound.io/modules/validate"; 

let $jsd :=
{
  "$namespace" : "http://www.example.com/my-schema",
  "$types" : [
    {
      "$kind" : "array",
      "$name" : "a-string-array",
      "$content" : [ "string" ]
    }
  ]
}


let $instance := ["", "a", "abc", 123]

return
  jsv:jsd-valid($jsd, "a-string-array", "http://www.example.com/my-schema", $instance)
