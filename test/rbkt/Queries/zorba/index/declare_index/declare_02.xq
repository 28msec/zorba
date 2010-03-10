import module namespace decl = "http://www.test.com/" at "declare_02.xqlib";

import module namespace sc = "http://www.zorba-xquery.com/modules/introspection/sctx";

sc:is-declared-index(xs:QName("decl:coll1_index"))
