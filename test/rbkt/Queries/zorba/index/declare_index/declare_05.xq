import module namespace decl = "http://www.test.com/" at "declare_05.xqlib";

import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

index_ddl:is-declared-index(xs:QName("decl:coll1_index"))
