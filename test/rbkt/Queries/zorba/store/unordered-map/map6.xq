import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

declare namespace zerr = "http://zorba.io/modules/zorba-errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";


let $name1 := fn:QName("http://www.zorba-xquery.com/map", "first")
let $type1 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:string")
let $name2 := fn:QName("http://www.zorba-xquery.com/map", "second")
let $type2 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create($name1, $type1);
    map:create($name2, $type2);
    map:insert($name1, <a>blub</a>, xs:anyURI("http://www.zorba-xquery.com/"));
    map:insert($name1, <a>blub42</a>, 42);
    map:insert($name2, <a>blub23</a>, 2);
    (
      map:get($name1, "http://www.zorba-xquery.com/"),
      map:get($name1, 42),
      try
      {
        map:get($name2, "blub")
      } catch zerr:ZXQD0005
      {
        $err:description
      }
    )

  }

