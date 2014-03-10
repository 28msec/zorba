import module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';
declare namespace mapper = 'http://zorba.io/modules/zorba-query/uri-mapper';
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string)
{
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

variable $queryID := zq:prepare-main-module
(
  "import module namespace test = 'http://test'; test:foo()", 
  resolver:url-resolver#2, mapper:uri-mapper#2
);

zq:evaluate($queryID)
