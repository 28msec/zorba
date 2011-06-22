import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


let $name := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type1 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:anyAtomicType")
let $type2 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create($name, $type1, $type2);

    map:insert($name, "value", "key0", 1);

    map:get($name, "key0", 1);

    map:keys($name)
  }
