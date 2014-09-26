import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import schema namespace kml = "http://earth.google.com/kml/2.1" at "kml21.xsd";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

let $doc := http:get-text("http://zorbatest.28.io:8080/http-test-data/wildlife-national-parks-india.kml")[2]
for $placemark in fn:parse-xml($doc)//kml:Placemark
return 
  cdml:insert(xs:QName("kml-data:placemarks"),
    validate { $placemark }
  );
