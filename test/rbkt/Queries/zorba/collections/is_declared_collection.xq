import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

(ddl:is-declared-collection(xs:QName("ns:http")), ddl:is-declared-collection(xs:QName("ns:nothing")))
