(:
  Check that index domain expr does not reference the context item
:)


import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module2.xqlib";

index_ddl:create-index(xs:QName("idx:foo"));
index_ddl:drop-index(xs:QName("idx:foo"));
