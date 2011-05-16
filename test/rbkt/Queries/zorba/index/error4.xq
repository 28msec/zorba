(:
  Check that index domain expr does not produce any atomic items
:)


import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "error_module3.xqlib";

ddl:create-collection(xs:QName("idx:auctions"));

index_ddl:create-index(xs:QName("idx:foo"));
index_ddl:delete-index(xs:QName("idx:foo"));
