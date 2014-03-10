import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

import schema namespace kml = "http://earth.google.com/kml/2.1" at "kml21.xsd";

import module namespace kml-data = "http://www.mykml/data" at "sc1_ex1.xqlib";

cdml:delete(
  for $placemark in cdml:collection(xs:QName("kml-data:placemarks"))
  where not(contains($placemark/kml:description, "Elephants"))
  return $placemark
)
