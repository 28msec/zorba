import module namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

declare sequential function local:test_create() {
  init:create-collection(xs:QName("decl:coll1"));
  init:create-index(xs:QName("decl:coll1_index"));
  init:create-collection(xs:QName("decl:coll3"));
  init:create-index(xs:QName("decl:coll3_index"));
  (
    manip:is-available-index(xs:QName("decl:coll1_index")),
    manip:is-available-index(xs:QName("decl:coll2_index")),
    manip:is-available-index(xs:QName("decl:coll3_index")),
    for $x in manip:available-indexes()
    order by xs:string($x)
    return $x
  );
};

declare sequential function local:test_delete() {
  init:delete-index(xs:QName("decl:coll1_index"));
  (
    manip:is-available-index(xs:QName("decl:coll1_index")),
    manip:is-available-index(xs:QName("decl:coll2_index")),
    manip:is-available-index(xs:QName("decl:coll3_index")),
    manip:available-indexes()
  );
};

local:test_create(),local:test_delete()
