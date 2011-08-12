import module namespace decl = "http://www.test.com/" at "remove_collection_with_index.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

ddl:create(xs:QName("decl:coll1"));
index_ddl:create(xs:QName("decl:coll1_index"));

ddl:delete(xs:QName("decl:coll1"));
