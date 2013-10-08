import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

dml:insert-after(xs:QName("ns:collection"), <a/>, xs:QName("ns:collection")[1]);
