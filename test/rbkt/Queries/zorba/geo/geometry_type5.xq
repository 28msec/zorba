import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:geometry-type(<gml:Curve><gml:segments>
                <gml:LineStringSegment interpolation="linear"><gml:posList> 1 1 2 2</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList> 1 1 1 3</gml:posList></gml:LineStringSegment>
              </gml:segments></gml:Curve>)