import module namespace conf  = "http://www.zorba-xquery.com/modules/conformance" at "conformance_xqftts.xqi";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

conf:create-collection-submissions();
conf:test();
dml:delete-nodes(dml:collection(xs:QName("conf:submissionXqueryX")));                           
ddl:delete(xs:QName("conf:submissionXqueryX"));
dml:delete-nodes(dml:collection(xs:QName("conf:submissionXquery")));                           
ddl:delete(xs:QName("conf:submissionXquery"));
dml:delete-nodes(dml:collection(xs:QName("conf:xquery")));                           
ddl:delete(xs:QName("conf:xquery"));
dml:delete-nodes(dml:collection(xs:QName("conf:xqueryx")));                           
ddl:delete(xs:QName("conf:xqueryx"));

