import module namespace decl = "http://www.test.com/" at "remove_collection_with_index.xqlib";

import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

xqddf:create-collection(xs:QName("decl:coll1"));
xqddf:create-index(xs:QName("decl:coll1_index"));

xqddf:delete-collection(xs:QName("decl:coll1"));
