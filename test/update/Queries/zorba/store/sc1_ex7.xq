import module namespace cddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

iddl:delete(xs:QName("kml-data:park-names"));
cddl:delete(xs:QName("kml-data:placemarks"));
cddl:is-available-collection(xs:QName("kml-data:placemarks"))
