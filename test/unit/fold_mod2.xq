module namespace mod2 = "http://www.zorba-xquery.com/mod2";

declare function mod2:bar() as xs:string external;

declare function mod2:someFunc() as element(data)?
{
  ()
};

declare function mod2:foo() as element(data)?
{
  let $res := mod2:bar()
  return 
    if ($res)
    then
      mod2:someFunc()
    else
      ()
};
