import module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';

declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if($namespace = 'http://test' and $entity = 'schema')
  then 
    doc('test.xsd')
  else 
    ()
};

variable $contextQueryID := zq:prepare-main-module(
  "import schema namespace test = 'http://test';
  declare variable $cwd as xs:anyURI external;
  validate { doc(resolve-uri('test.xml', $cwd)) }",
  resolver:url-resolver#2, ());
zq:bind-variable($contextQueryID, fn:QName("", "cwd"), resolve-uri("."));
variable $contextItem := zq:evaluate($contextQueryID);

variable $queryID := zq:prepare-main-module(
  "import schema namespace test = 'http://test'; //*:test",
  resolver:url-resolver#2, ());
zq:bind-context-item($queryID, $contextItem);
zq:evaluate($queryID)
