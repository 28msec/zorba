import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace ns = "http://example.org/datamodule/" at "collections.xqdata";

(init:is-declared-collection(xs:QName("ns:http")), init:is-declared-collection(xs:QName("ns:nothing")))
