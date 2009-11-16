(:
  Check that index definition does not reference any input sources other
  than dc:collection
:)

import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module1.xqlib";

ddl:create-index(xs:QName("idx:foo"));
ddl:drop-index(xs:QName("idx:foo"));

