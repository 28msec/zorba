import module namespace decl = "http://www.test.com/" at "declare_05.xqlib";

import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";

index_ddl:is-declared-index(xs:QName("decl:coll1_index"))
