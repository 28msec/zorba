import module namespace cddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

cddl:create-collection(xs:QName("kml-data:placemarks"));
iddl:create-index(xs:QName("kml-data:park-names"));

(: sanity check: return true if collection is available, false otherwise :)
cddl:is-available-collection(xs:QName("kml-data:placemarks"))
