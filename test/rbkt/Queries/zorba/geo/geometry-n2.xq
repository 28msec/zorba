import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:geometry-n( <gml:Point><gml:pos>1 1</gml:pos></gml:Point>,
                0 cast as xs:unsignedInt
              )