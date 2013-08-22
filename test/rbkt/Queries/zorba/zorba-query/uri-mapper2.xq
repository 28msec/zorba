import module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';
declare namespace mapper = 'http://zorba.io/modules/zorba-query/uri-mapper';
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function mapper:uri-mapper($namespace as xs:string, $entity as xs:string)
{
  if ($namespace = 'http://test' and $entity = 'schema')
  then resolve-uri('test.xsd')
  else ()
};

variable $queryID := zq:prepare-main-module
(
  "import schema namespace test = 'http://test'; validate{<test:test><test:subtest>a</test:subtest><test:subtest2>a</test:subtest2></test:test>}", 
  (),
  mapper:uri-mapper#2
);
zq:evaluate($queryID)
