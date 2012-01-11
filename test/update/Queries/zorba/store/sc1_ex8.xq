import module namespace idml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import schema namespace kml = "http://earth.google.com/kml/2.1" at "kml21.xsd";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

idml:probe-index-point-value(xs:QName("kml-data:park-names"), "Barsey Rhododendron Sanctuary")
