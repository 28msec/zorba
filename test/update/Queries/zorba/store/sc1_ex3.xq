import module namespace cdml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import schema namespace kml = "http://earth.google.com/kml/2.1" at "kml21.xsd";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

let $doc := http:get-text("http://www.zorba-xquery.com/rest-tests/wildlife-national-parks-india.kml")[2]
for $placemark in fn:parse-xml($doc)//kml:Placemark
return 
  cdml:insert-nodes(xs:QName("kml-data:placemarks"),
    validate { $placemark }
  );
