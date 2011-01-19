import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-simple(<gml:LineString>
              <gml:pos>1 1</gml:pos>
              <gml:pos>20 1</gml:pos>
              <gml:pos>10 4</gml:pos>
              <gml:pos>20 -10</gml:pos>
              </gml:LineString>)