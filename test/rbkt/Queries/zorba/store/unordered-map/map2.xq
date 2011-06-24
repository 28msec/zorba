import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


let $name := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    variable $foo;

    map:create($name, $type);

    map:insert($name, "value1", 1);
    map:insert($name, "value2", 1);
    map:insert($name, "value3", 2);

    $foo := map:get($name, 1);

    map:remove($name, 1);

    $foo := ($foo, map:get($name, 1), map:size($name), map:available-maps());

    $foo

  }
