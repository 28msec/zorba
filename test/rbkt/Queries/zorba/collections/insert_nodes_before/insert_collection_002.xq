import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

dml:insert-nodes-before(xs:QName("ns:collection"), <a/>, xs:QName("ns:collection")[1]);

