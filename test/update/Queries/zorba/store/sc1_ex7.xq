import module namespace cddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace iddl = "http://zorba.io/modules/store/static/indexes/ddl";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

iddl:delete(xs:QName("kml-data:park-names"));
cddl:delete(xs:QName("kml-data:placemarks"));
cddl:is-available-collection(xs:QName("kml-data:placemarks"))
