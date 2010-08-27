(:
Geo module test.
Tests if two lines are equal, even if one line contains a duplicate point.
Result: true
:)

import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:equals(<gml:LineString>
                <gml:pos>1 1</gml:pos>
                <gml:pos>55 99</gml:pos>
                <gml:pos>2 1</gml:pos>
             </gml:LineString>,
             <gml:LineString>
                <gml:posList>
                1 1
                1 1
                55 99
                2 1
                </gml:posList>
             </gml:LineString>)