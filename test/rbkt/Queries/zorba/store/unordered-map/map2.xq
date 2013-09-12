import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type := "integer"
return
  {
    variable $foo;

    map:create($name, $type);

    map:insert($name, 1, "value1");
    map:insert($name, 1, "value2");
    map:insert($name, 2, "value3");

    $foo := map:get($name, 1);

    map:delete($name, 1);

    $foo := ($foo, map:get($name, 1), map:size($name), map:available-maps());

    $foo

  }
