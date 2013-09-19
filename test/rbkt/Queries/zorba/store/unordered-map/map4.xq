import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type := "decimal"
return
  {
    map:create($name, $type);
    map:insert($name, 3.2, <a>blub</a>);
    map:get($name, 3.2)
  }
