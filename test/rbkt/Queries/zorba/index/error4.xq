(:
  Check that index domain expr does not produce any atomic items
:)


import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module3.xqlib";

init:create-collection(xs:QName("idx:auctions"));

init:create-index(xs:QName("idx:foo"));
init:delete-index(xs:QName("idx:foo"));
