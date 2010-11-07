import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:point-n(<gml:MultiCurve>
                <gml:LineString><gml:posList>1 1 0 0 2 1</gml:posList></gml:LineString>
                <gml:LineString><gml:posList>20 10 3 3 4 4</gml:posList></gml:LineString>
              </gml:MultiCurve>,
                3 cast as xs:unsignedInt)