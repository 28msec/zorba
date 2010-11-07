import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-closed(<gml:MultiCurve>
                <gml:LineString><gml:posList>1 1 2 1 2 2 1 2 1 1</gml:posList></gml:LineString>
                <gml:LineString><gml:posList>1 2 2 2 3 3 1 2</gml:posList></gml:LineString>
              </gml:MultiCurve>)