import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type1 := "string"
let $type2 := "integer"
return
  {
    map:create($name, [ $type1, $type2]);

    map:insert($name, ["key0", 1], "value");

    map:get($name, ["key0", 1]);

    map:keys($name)
  }
