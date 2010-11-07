import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-closed(<gml:Curve><gml:segments>
                <gml:LineStringSegment interpolation="linear"><gml:posList> 1 1  2 2 </gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>2 2 4 4</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>4 4 3 3 1 1</gml:posList></gml:LineStringSegment>
              </gml:segments></gml:Curve>)