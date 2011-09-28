import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


let $name := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create($name, $type);

    (
      for $i in 1 to 1000
      return map:insert($name, concat("value", $i), $i)
    );

    count(map:keys($name)) = map:size($name)
  }
