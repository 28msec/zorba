import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:sym-difference(<gml:MultiSurface>
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
                <gml:Polygon><gml:exterior>
                <gml:LinearRing>
                <gml:pos>0 0</gml:pos>
                <gml:pos>2 0</gml:pos>
                <gml:pos>2 2</gml:pos>
                <gml:pos>0 2</gml:pos>
                <gml:pos>0 0</gml:pos>
                </gml:LinearRing>
                </gml:exterior></gml:Polygon>
              )