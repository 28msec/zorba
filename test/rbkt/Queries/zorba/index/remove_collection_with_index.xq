import module namespace decl = "http://www.test.com/" at "remove_collection_with_index.xqlib";

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

init:create-collection(xs:QName("decl:coll1"));
init:create-index(xs:QName("decl:coll1_index"));

init:delete-collection(xs:QName("decl:coll1"));
