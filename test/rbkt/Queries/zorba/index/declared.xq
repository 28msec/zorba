import module namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

(
  index_ddl:is-declared-index(xs:QName("decl:abcd")),
  index_ddl:is-declared-index(xs:QName("decl:coll1_index")),
  for $x in index_ddl:declared-indexes()
  order by xs:string($x)
  return $x
)
