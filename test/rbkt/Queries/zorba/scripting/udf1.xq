import module namespace x = "http://zorba.io/modules/unordered-maps";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:foo()
{
  if (fn:true())
  then
  {
    variable $req := <a/>;
    variable $result := x:create("first",
                                 fn:QName("http://www.w3.org/2001/XMLSchema", "xs:integer"));

    $result
  }
  else
  ()
};


let $x := local:foo()
return $x
