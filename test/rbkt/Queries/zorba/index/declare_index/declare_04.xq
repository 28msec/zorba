import module namespace decl = "http://www.test.com/" at "declare_04.xqlib";

import module namespace ddl = "http://zorba.io/modules/store/static/indexes/ddl";

ddl:is-declared-index(xs:QName("decl:coll1_index"))
