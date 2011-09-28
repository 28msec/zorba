(:
  Check that index definition does not reference any input sources other
  than dc:collection
:)

import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module1.xqlib";

index_ddl:create(xs:QName("idx:foo"));
index_ddl:drop-index(xs:QName("idx:foo"));

