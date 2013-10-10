import module namespace zq = 'http://zorba.io/modules/zorba-query';

import module namespace ddl =
    "http://zorba.io/modules/store/dynamic/collections/w3c/ddl";
import module namespace dml =
    "http://zorba.io/modules/store/dynamic/collections/w3c/dml";

declare namespace resolver = 'http://zorba.io/modules/zorba-query/url-resolver';
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if ($entity = 'schema')
  then
    dml:collection("http://zorba.io/modules/zorba-query")//xs:schema[@targetNamespace=$namespace]
  else
    ()
};

declare variable $coll := "http://zorba.io/modules/zorba-query";
declare variable $schema := doc("test.xsd");
ddl:create($coll);

dml:apply-insert-nodes-first($coll, $schema);
variable $query-key := zq:prepare-main-module(
  "import schema namespace test = 'http://test'; validate {<test:test><test:subtest>a</test:subtest><test:subtest2>a</test:subtest2></test:test>}",
  resolver:url-resolver#2, ());
zq:evaluate($query-key)
