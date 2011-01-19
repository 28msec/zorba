import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:intersection(<gml:LineString>
                <gml:pos>1 1</gml:pos>
                <gml:pos>55 99</gml:pos>
                <gml:pos>2 1</gml:pos>
             </gml:LineString>,
             <gml:LineString>
                <gml:posList srsDimension='3'>
                1 2 10
                55 0 20
                </gml:posList>
             </gml:LineString>)