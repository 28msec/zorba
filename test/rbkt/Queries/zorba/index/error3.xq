(:
  Check that index domain expr does not reference the context item
:)


import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module2.xqlib";

xqddf:create-index(xs:QName("idx:foo"));
xqddf:drop-index(xs:QName("idx:foo"));
