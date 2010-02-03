import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

xqddf:insert-nodes-after(xs:QName("ns:collection"), <a/>, xs:QName("ns:collection")[1]);

