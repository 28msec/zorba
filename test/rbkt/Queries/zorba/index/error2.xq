(:
  Check that index definition does not reference any input sources other
  than dc:collection
:)

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module1.xqlib";

init:create-index(xs:QName("idx:foo"));
init:drop-index(xs:QName("idx:foo"));

