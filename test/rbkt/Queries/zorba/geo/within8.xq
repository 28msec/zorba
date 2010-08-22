import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:within(<gml:Polygon><gml:exterior>
                <gml:LinearRing>
                <gml:pos>1 1 </gml:pos>
                <gml:pos>2 1</gml:pos>
                <gml:pos>2 2</gml:pos>
                <gml:pos>1 2</gml:pos>
                <gml:pos> 1 1  </gml:pos>
                </gml:LinearRing>
                </gml:exterior></gml:Polygon>,
                
             <gml:MultiSurface>
                <gml:Polygon><gml:exterior>
                <gml:LinearRing>
                <gml:pos>1 1 </gml:pos>
                <gml:pos>20 1</gml:pos>
                <gml:pos>20 20</gml:pos>
                <gml:pos>1 20</gml:pos>
                <gml:pos> 1 1  </gml:pos>
                </gml:LinearRing>
                </gml:exterior></gml:Polygon>
              </gml:MultiSurface>
                
              )