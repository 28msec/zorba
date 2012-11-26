import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';
declare namespace mapper = 'http://www.zorba-xquery.com/modules/xqxq/uri-mapper';
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:enable "f:hof";

declare function mapper:uri-mapper($namespace as xs:string, $entity as xs:string)
{
  if ($namespace = 'http://test' and $entity = 'schema')
  then resolve-uri('test.xsd')
  else ()
};

variable $queryID := xqxq:prepare-main-module
(
  "import schema namespace test = 'http://test'; validate{<test:test><test:subtest>a</test:subtest><test:subtest2>a</test:subtest2></test:test>}", 
  (),
  mapper:uri-mapper#2
);
xqxq:evaluate($queryID)
