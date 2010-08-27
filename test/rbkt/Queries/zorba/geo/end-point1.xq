import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:end-point(<gml:LinearRing>
                    <gml:pos>1 1</gml:pos>
                    <gml:pos>2 1</gml:pos>
                    <gml:pos>20 1</gml:pos>
                    <gml:pos>1 1</gml:pos>
                </gml:LinearRing>)