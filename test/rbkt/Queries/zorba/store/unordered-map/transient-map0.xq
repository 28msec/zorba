import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";


let $name := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create-transient($name, $type);

    (
      for $i in 1 to 1000
      return map:insert($name, concat("value", $i), $i)
    );

    variable $res := <avail>{ map:available-maps() }</avail>;

    $res := ($res, <contains>{ map:get($name, 5) }</contains>);

    map:remove($name, 5);

    $res := ($res, <contains>{ map:get($name, 5) }</contains>);
    
    map:delete($name);

    ($res, <avail>{ map:available-maps() }</avail>)
  }

