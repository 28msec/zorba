import module namespace foaf = "http://www.w3.org/TestModules/foaf" at
                                   "foaf_module-with-index.xqlib";

import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

foaf:create-db();

for $x in foaf:probe-point-general-id($foaf:friends, ("Jean-Luc Picard", "James T. Kirk", "Q"))
order by $x("name")
return $x
