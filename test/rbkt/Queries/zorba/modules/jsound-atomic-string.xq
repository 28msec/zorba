import module namespace jsv = "http://jsound.io/modules/validate"; 

let $jsd :=
{
  "$namespace" : "http://www.example.com/my-schema",
  "$types" : [
    {
      "$kind" : "atomic",
      "$name" : "a-string",
      "$baseType" : "string"
    }
  ]
}


let $instance := "hello"

return
  jsv:jsd-valid($jsd, "a-string", "http://www.example.com/my-schema", $instance)
