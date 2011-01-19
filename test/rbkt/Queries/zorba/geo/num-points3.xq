import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:num-points(<gml:MultiCurve>
                <gml:LineString><gml:posList>1 1 0 0 2 1</gml:posList></gml:LineString>
                <gml:LineString><gml:posList>20 10 3 3 4 4</gml:posList></gml:LineString>
              </gml:MultiCurve>)