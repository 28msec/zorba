import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:enable "f:hof";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if($namespace = 'http://test.xq')
  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
  else ()
};

variable $queryID := xqxq:prepare-main-module(
  "import module namespace test = 'http://test'; test:foo()",
  resolver:url-resolver#2, ());
xqxq:evaluate($queryID)
