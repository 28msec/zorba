(: Declaration of index in non data module :)

import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

import module namespace idx = "http://www.w3.org/TestModules/idx" at
                              "auctions_module1.xqlib";

ddl:create-index(xs:QName("idx:foo"));
ddl:drop-index(xs:QName("idx:foo"));

