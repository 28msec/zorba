import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


let $name := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:anyAtomicType")
return
  {
    map:create($name, $type);
    map:insert($name, <a>blub</a>, 3.2);
    map:get($name, 3.2)
  }
