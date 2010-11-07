import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:overlaps(<gml:LineString>
                <gml:posList >
                -1 1
                -1 0
                0 0
                0 1
                </gml:posList>
             </gml:LineString>,
             <gml:LineString>
                <gml:posList>
                0 -1
                0 0
                10 0
                10 -1
                </gml:posList>
             </gml:LineString>)