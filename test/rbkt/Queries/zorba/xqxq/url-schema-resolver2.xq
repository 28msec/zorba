import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

import module namespace ddl =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl";
import module namespace dml =
    "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml";

declare namespace resolver = 'http://www.zorba-xquery.com/modules/xqxq/url-resolver';
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";
declare option op:enable "f:hof";

declare function resolver:url-resolver($namespace as xs:string, $entity as xs:string) {
  if ($entity = 'schema')
  then
    dml:collection("http://www.zorba-xquery.com/modules/xqxq")//xs:schema[@targetNamespace=$namespace]
  else
    ()
};

declare variable $coll := "http://www.zorba-xquery.com/modules/xqxq";
declare variable $schema := doc("test.xsd");
ddl:create($coll);

dml:apply-insert-nodes-first($coll, $schema);
variable $query-key := xqxq:prepare-main-module(
  "import schema namespace test = 'http://test'; validate {<test:test><test:subtest>a</test:subtest><test:subtest2>a</test:subtest2></test:test>}",
  resolver:url-resolver#2, ());
xqxq:evaluate($query-key)
