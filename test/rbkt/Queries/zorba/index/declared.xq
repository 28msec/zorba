import datamodule namespace decl = "http://www.test.com/" at "declared.xqlib";

import module namespace sc = "http://www.zorba-xquery.com/module/static-context";

(
  sc:is-declared-index(xs:QName("decl:abcd")),
  sc:is-declared-index(xs:QName("decl:coll1_index")),
  for $x in sc:declared-indexes()
  order by xs:string($x)
  return $x
)
