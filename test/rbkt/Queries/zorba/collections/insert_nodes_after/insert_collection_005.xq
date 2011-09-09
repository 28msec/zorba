import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:test2"), (<center1/>,<center2/>));

dml:insert-nodes-after(xs:QName("ddl:test2"),
                       dml:collection(xs:QName("ddl:test2"))[2],
                       (<c1/>,<c2/>));
