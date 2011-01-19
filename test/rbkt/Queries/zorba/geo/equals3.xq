import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:equals(<gml:MultiCurve>
                <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
              </gml:MultiCurve>,
            <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
              )