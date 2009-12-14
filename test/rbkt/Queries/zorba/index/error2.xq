(:
  Check that index definition does not reference any input sources other
  than dc:collection
:)

import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module1.xqlib";

xqddf:create-index(xs:QName("idx:foo"));
xqddf:drop-index(xs:QName("idx:foo"));

