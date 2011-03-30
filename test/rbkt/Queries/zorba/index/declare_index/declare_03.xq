import module namespace decl = "http://www.test.com/" at "declare_03.xqlib";

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";

init:is-declared-index(xs:QName("decl:coll1_index"))
