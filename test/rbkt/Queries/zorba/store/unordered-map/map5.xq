import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type := "integer"
return
  {
    map:create($name, $type);
    map:drop("second");
  }
