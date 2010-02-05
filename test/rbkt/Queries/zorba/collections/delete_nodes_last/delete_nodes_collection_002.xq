import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

xqddf:delete-nodes-last(xs:QName("ns:collection"), xs:unsignedLong(1));

