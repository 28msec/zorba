import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:boundary(<gml:MultiCurve>
                <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
                <gml:LineString><gml:pos>1 2</gml:pos><gml:pos>1 1</gml:pos></gml:LineString>
                <gml:LineString><gml:posList>10 20 20 30 30 40</gml:posList></gml:LineString>
              </gml:MultiCurve>)