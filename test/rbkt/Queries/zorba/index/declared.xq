import module namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";

(
  init:is-declared-index(xs:QName("decl:abcd")),
  init:is-declared-index(xs:QName("decl:coll1_index")),
  for $x in init:declared-indexes()
  order by xs:string($x)
  return $x
)
