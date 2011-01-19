import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:crosses(<gml:MultiSurface>
                <gml:Polygon><gml:exterior>
                <gml:LinearRing>
                <gml:pos>1 1 </gml:pos>
                <gml:pos>20 1</gml:pos>
                <gml:pos>20 20</gml:pos>
                <gml:pos>1 20</gml:pos>
                <gml:pos> 1 1  </gml:pos>
                </gml:LinearRing>
                </gml:exterior></gml:Polygon>
              </gml:MultiSurface>,
              
                <gml:LinearRing>
                <gml:pos>1 1 </gml:pos>
                <gml:pos>30 1</gml:pos>
                <gml:pos>30 10</gml:pos>
                <gml:pos>1 10</gml:pos>
                <gml:pos> 1 1  </gml:pos>
                </gml:LinearRing>
              )