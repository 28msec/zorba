import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

ddl:create(xs:QName("ns:collection_unordered"));

dml:insert(xs:QName("ns:collection_unordered"), <a/>);

dml:delete-last(xs:QName("ns:collection_unordered"), xs:unsignedLong(1));

dml:collection(xs:QName("ns:collection_unordered"));
