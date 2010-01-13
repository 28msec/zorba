(:
  Check that index domain expr does not produce any atomic items
:)


import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module3.xqlib";

xqddf:create-collection(xs:QName("idx:auctions"));

xqddf:create-index(xs:QName("idx:foo"));
xqddf:delete-index(xs:QName("idx:foo"));
