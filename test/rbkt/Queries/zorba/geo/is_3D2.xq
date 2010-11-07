import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-3d(<gml:MultiCurve srsDimension='3'>
                <gml:LineString><gml:pos>1 1 1</gml:pos><gml:pos>2 1 2</gml:pos></gml:LineString>
                <gml:LineString><gml:pos>1 2 4</gml:pos><gml:pos>1 1 3</gml:pos></gml:LineString>
              </gml:MultiCurve>)