import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

xqddf:create-collection(xs:QName("ns:collection_unordered"));

xqddf:insert-nodes(xs:QName("ns:collection_unordered"), <a/>);

xqddf:delete-node-first(xs:QName("ns:collection_unordered"));

xqddf:collection(xs:QName("ns:collection_unordered"));
