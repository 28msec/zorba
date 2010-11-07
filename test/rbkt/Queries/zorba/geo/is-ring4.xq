import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-ring(<gml:Curve><gml:segments>
                <gml:LineStringSegment interpolation="linear"><gml:posList> 1 1  2 1 </gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>2 1 4 4</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>4 4 3 3 1 1</gml:posList></gml:LineStringSegment>
              </gml:segments></gml:Curve>)