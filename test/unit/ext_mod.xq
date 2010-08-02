module namespace ext = "http://www.zorba-xquery.com/m";

declare function ext:bar() as xs:string external;

declare function ext:foo()
{
  let $res := ext:bar()
  return (1, $res)
};
