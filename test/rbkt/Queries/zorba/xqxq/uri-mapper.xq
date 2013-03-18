import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';
declare namespace mapper = 'http://www.zorba-xquery.com/modules/xqxq/uri-mapper';
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:enable "f:hof";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if($namespace = 'http://foo')
  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
  else ()
};

declare function mapper:uri-mapper($namespace as xs:string, $entity as xs:string)
{
   if($namespace = 'http://test')
   then 'http://foo'
   else ()
};

variable $queryID := xqxq:prepare-main-module
(
  "import module namespace test = 'http://test'; test:foo()", 
  resolver:url-resolver#2, mapper:uri-mapper#2
);
xqxq:evaluate($queryID)
