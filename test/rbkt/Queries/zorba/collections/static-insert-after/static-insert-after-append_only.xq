import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

ddl:create(xs:QName("ns:collection_append_only"));

dml:insert-first(xs:QName("ns:collection_append_only"), <a/>);

dml:insert-after(xs:QName("ns:collection_append_only"), <a/>, xs:QName("ns:collection_append_only")[1]);
