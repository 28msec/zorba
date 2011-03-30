import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

init:create-collection(xs:QName("ns:collection2"));

manip:insert-nodes-first(xs:QName("ns:collection2"), <a/>);

manip:insert-nodes-after(xs:QName("ns:collection2"), <b/>, xs:QName("ns:collection2")[1]);
