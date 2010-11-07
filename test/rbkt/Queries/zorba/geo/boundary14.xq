import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:boundary(<gml:MultiGeometry>
                <gml:geometryMember>
                <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
                </gml:geometryMember>
                <gml:geometryMember>
                <gml:Point><gml:pos>1 1</gml:pos></gml:Point>
                </gml:geometryMember>
              </gml:MultiGeometry>)