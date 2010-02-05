import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

xqddf:insert-nodes-before(xs:QName("ns:collection22"), <a/>, xs:QName("ns:collection22")[1]);

