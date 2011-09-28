import module namespace x =
"http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:foo()
{
  if (fn:true())
  then
  {
    variable $req := <a/>;
    variable $result := x:create(fn:QName("http://www.zorba-xquery.com/map", "first"),
                                 fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer"));

    $result
  }
  else
  ()
};


let $x := local:foo()
return $x
