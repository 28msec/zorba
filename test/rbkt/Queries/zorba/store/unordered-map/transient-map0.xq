import module namespace map = "http://zorba.io/modules/unordered-maps";


let $name := "first"
let $type := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create($name, $type, { $map:PERSISTENT : false });

    (
      for $i in 1 to 1000
      return map:insert($name, $i, concat("value", $i))
    );

    variable $res := <avail>{ map:available-maps() }</avail>;

    $res := ($res, <contains>{ map:get($name, 5) }</contains>);

    map:delete($name, 5);

    $res := ($res, <contains>{ map:get($name, 5) }</contains>);
    
    map:drop($name);

    ($res, <avail>{ map:available-maps() }</avail>)
  }

