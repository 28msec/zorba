import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:dimension(<gml:MultiSurface>
                <gml:Polygon><gml:exterior>
                <gml:LinearRing>
                <gml:pos>1 1 </gml:pos>
                <gml:pos>2 1</gml:pos>
                <gml:pos>2 2</gml:pos>
                <gml:pos>1 2</gml:pos>
                <gml:pos> 1 1  </gml:pos>
                </gml:LinearRing>
                </gml:exterior></gml:Polygon>
              </gml:MultiSurface>)