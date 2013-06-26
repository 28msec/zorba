(:
  Check that index domain expr does not reference the context item
:)


import module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module2.xqlib";

iddl:create(xs:QName("idx:foo"));
iddl:drop-index(xs:QName("idx:foo"));
