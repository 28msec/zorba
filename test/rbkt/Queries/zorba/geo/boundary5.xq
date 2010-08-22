import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:boundary(<gml:LineString>
                <gml:pos>1 1</gml:pos>
                <gml:pos>55 99</gml:pos>
                <gml:pos>2 1</gml:pos>
             </gml:LineString>)