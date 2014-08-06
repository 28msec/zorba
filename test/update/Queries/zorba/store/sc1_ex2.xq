import module namespace cddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace iddl = "http://zorba.io/modules/store/static/indexes/ddl";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

cddl:create(xs:QName("kml-data:placemarks"));
iddl:create(xs:QName("kml-data:park-names"));

(: sanity check: return true if collection is available, false otherwise :)
cddl:is-available-collection(xs:QName("kml-data:placemarks"))
