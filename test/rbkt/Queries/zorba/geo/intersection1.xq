(:
Geo module test.
Compute the intersection between a group of lines and a point on one line.
Result: 3.000000 3.000000
:)

import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:intersection(<gml:Curve><gml:segments>
                <gml:LineStringSegment interpolation="linear"><gml:posList> 1 1 2 2</gml:posList></gml:LineStringSegment>
                <gml:LineStringSegment><gml:posList> 1 1 2 2 4 4</gml:posList></gml:LineStringSegment>
              </gml:segments></gml:Curve>,
           <gml:Point><gml:pos> 3 3</gml:pos></gml:Point>
              )