import module namespace map = "http://zorba.io/modules/unordered-maps";

declare namespace zerr = "http://zorba.io/errors";
declare namespace err = "http://www.w3.org/2005/xqt-errors";


let $name1 := "first"
let $type1 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:string")
let $name2 := "second"
let $type2 := fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer")
return
  {
    map:create($name1, $type1);
    map:create($name2, $type2);
    map:insert($name1, xs:anyURI("http://www.zorba-xquery.com/"), <a>blub</a>);
    map:insert($name1, 42, <a>blub42</a>);
    map:insert($name2, 2, <a>blub23</a>);
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

