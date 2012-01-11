declare namespace ann = "http://www.my-annotation.com/";
declare namespace op = "http://www.zorba-xquery.com/options/warnings";

declare option op:disable "all";

variable $local:foo1 := 2;
variable $local:foo2 as xs:integer := 2;
variable $local:foo3 as xs:integer := 2, $local:foo4 := "foo";
%ann:foo variable $local:foo5 as xs:integer := 2;
%ann:foo1 %ann:foo2 variable $local:foo6 as xs:integer := 2;

($local:foo1, $local:foo2, $local:foo3, $local:foo4, $local:foo5, $local:foo6)
