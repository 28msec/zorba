module namespace extern_func = "http://www.zorba-xquery.com/extern_func";

declare namespace foo="urn:foo";

declare function foo:test() as xs:integer
{
  (: eval { "
    declare namespace ns2 = 'myns';
    declare function foo:bar1() external;
    foo:bar1()
  " }
  :)
  foo:bar1();
};

