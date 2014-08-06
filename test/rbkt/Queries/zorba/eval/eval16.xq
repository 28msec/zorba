xquery version "3.0";

import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";
import module namespace e = "http://zorba.io/modules/reflection";

ddl:create(xs:QName("ddl:test2"),(<center1/>,<oldlast/>));

subsequence(e:eval("dml:collection(xs:QName('ddl:test2'))"), 2, 1)
