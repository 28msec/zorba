module namespace ext = "http://www.zorba-xquery.com/m";

declare function ext:bar() as xs:string external;

declare function ext:foo()
{
  let $res := ext:bar()
  return (1, $res)
};

declare function ext:foo2()
{
  let $res := ext:bar2()
  return (1, $res)
};

declare function ext:bar2() as xs:string external;
