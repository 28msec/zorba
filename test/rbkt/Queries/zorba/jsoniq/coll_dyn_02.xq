import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";

import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace xqsx = "http://www.zorba-xquery.com/zorba/scripting";

declare variable $coll1 := xs:QName("collection1");

ddl:create($coll1, (<a/>, { "p1":1, "p2":2 }, {||}, [1, 2, 3]));

dml:collection($coll1)


