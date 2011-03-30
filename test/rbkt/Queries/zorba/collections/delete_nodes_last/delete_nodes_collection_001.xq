import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

manip:delete-nodes-last(xs:QName("ns:collection22"), xs:unsignedLong(1));

