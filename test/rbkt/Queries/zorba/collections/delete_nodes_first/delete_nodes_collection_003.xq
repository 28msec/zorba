import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

ddl:create(xs:QName("ns:collection_unordered"));

dml:insert-nodes(xs:QName("ns:collection_unordered"), <a/>);

dml:delete-nodes-first(xs:QName("ns:collection_unordered"), xs:unsignedLong(1));

dml:collection(xs:QName("ns:collection_unordered"));
