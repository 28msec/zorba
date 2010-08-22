import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:interior-point(<gml:LineString>
                <gml:pos>1 1</gml:pos>
                <gml:pos>55 99</gml:pos>
                <gml:pos>2 1</gml:pos>
                <gml:pos>2.1 1</gml:pos>
                <gml:pos>2.2 1</gml:pos>
                <gml:pos>2.3 1</gml:pos>
                <gml:pos>2.4 1</gml:pos>
                <gml:pos>2.5 1</gml:pos>
                <gml:pos>2.6 1</gml:pos>
                <gml:pos>2.7 1</gml:pos>
                <gml:pos>2.8 1</gml:pos>
                <gml:pos>2.9 1</gml:pos>
             </gml:LineString>)