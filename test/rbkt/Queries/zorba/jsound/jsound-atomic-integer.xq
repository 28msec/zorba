import module namespace jsv = "http://jsound.io/modules/validate"; 

let $jsd :=
{
  "$namespace" : "http://www.example.com/my-schema",
  "$types" : [
    {
      "$kind" : "atomic",
      "$name" : "small-number",
      "$baseType" : "integer"
    }
  ]
}


let $instance := 5

return
  jsv:jsd-valid($jsd, "small-number", "http://www.example.com/my-schema", $instance)
