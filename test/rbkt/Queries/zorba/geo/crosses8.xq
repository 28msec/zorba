import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:crosses(<gml:LineString>
                <gml:pos>1 1</gml:pos>
                <gml:pos>55 99</gml:pos>
                <gml:pos>2 1</gml:pos>
             </gml:LineString>,
             <gml:LineString>
                <gml:posList>
                1 2
                55 0
                </gml:posList>
             </gml:LineString>)