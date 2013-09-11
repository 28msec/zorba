import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type := "integer"
return
  {
    map:create($name, $type);

    (
      for $i in 1 to 1000
      return map:insert($name, $i, concat("value", $i))
    );

    map:get($name, 423)
  }
