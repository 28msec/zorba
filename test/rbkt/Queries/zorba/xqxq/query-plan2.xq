import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if($namespace = 'http://test')
  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
  else ()
};

variable $queryID := xqxq:prepare-main-module(
  "import module namespace test = 'http://test'; test:foo()",
  resolver:url-resolver#2, ());


variable $query-plan := xqxq:query-plan($queryID); 
variable $queryID2 := xqxq:load-from-query-plan($query-plan, resolver:url-resolver#2, ());
xqxq:evaluate ($queryID2)
