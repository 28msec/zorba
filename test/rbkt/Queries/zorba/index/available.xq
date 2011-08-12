import module namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:test_create() {
  ddl:create(xs:QName("decl:coll1"));
  index_ddl:create(xs:QName("decl:coll1_index"));
  ddl:create(xs:QName("decl:coll3"));
  index_ddl:create(xs:QName("decl:coll3_index"));
  (
    index_ddl:is-available-index(xs:QName("decl:coll1_index")),
    index_ddl:is-available-index(xs:QName("decl:coll2_index")),
    index_ddl:is-available-index(xs:QName("decl:coll3_index")),
    for $x in index_ddl:available-indexes()
    order by xs:string($x)
    return $x
  )
};

declare %ann:sequential function local:test_delete() {
  index_ddl:delete(xs:QName("decl:coll1_index"));
  (
    index_ddl:is-available-index(xs:QName("decl:coll1_index")),
    index_ddl:is-available-index(xs:QName("decl:coll2_index")),
    index_ddl:is-available-index(xs:QName("decl:coll3_index")),
    index_ddl:available-indexes()
  )
};

local:test_create(),local:test_delete()
