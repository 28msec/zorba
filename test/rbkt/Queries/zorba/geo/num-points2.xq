import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:num-points(<gml:Curve><gml:segments>
                <gml:LineStringSegment interpolation="linear"><gml:posList srsDimension="3"> 1 1 11 2 2 11</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>2 2 4 4</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList>4 4 3 3 6 6</gml:posList></gml:LineStringSegment>
              </gml:segments></gml:Curve>)