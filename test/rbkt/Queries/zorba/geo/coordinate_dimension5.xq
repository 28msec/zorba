import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:coordinate-dimension(<gml:MultiGeometry>
                <gml:geometryMember>
                <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
                </gml:geometryMember>
                <gml:geometryMember>
                <gml:Point><gml:pos>1 4</gml:pos></gml:Point>
                </gml:geometryMember>
                <gml:geometryMembers>
                <gml:LineString><gml:pos>100 200</gml:pos><gml:pos>100 1</gml:pos></gml:LineString>
                <gml:Polygon srsDimension='3'>
                    <gml:exterior>
                    <gml:LinearRing><gml:posList>10 20 0 11 20 0 11 21 0 10 21 0 10 20 0</gml:posList></gml:LinearRing>
                    </gml:exterior>
                </gml:Polygon>
                </gml:geometryMembers>
              </gml:MultiGeometry>)