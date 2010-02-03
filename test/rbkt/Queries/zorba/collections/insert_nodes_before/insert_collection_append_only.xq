import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

xqddf:create-collection(xs:QName("ns:collection_append_only"));

xqddf:insert-nodes-first(xs:QName("ns:collection_append_only"), <a/>);

xqddf:insert-nodes-before(xs:QName("ns:collection_append_only"), <a/>, xs:QName("ns:collection_append_only")[1]);
