import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:patch-n(<gml:Surface><gml:patches>
              </gml:patches></gml:Surface>,
              0 cast as xs:unsignedInt)