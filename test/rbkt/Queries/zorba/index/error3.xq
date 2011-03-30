(:
  Check that index domain expr does not reference the context item
:)


import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module2.xqlib";

init:create-index(xs:QName("idx:foo"));
init:drop-index(xs:QName("idx:foo"));
