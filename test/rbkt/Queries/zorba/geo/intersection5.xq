import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:intersection(<gml:MultiCurve>
                <gml:LineString><gml:posList>1 1 0 0 2 1</gml:posList></gml:LineString>
                <gml:LineString><gml:posList>2 1 3 3 4 4</gml:posList></gml:LineString>
              </gml:MultiCurve>,
            <gml:LineString><gml:posList>0 0 2 1 3 3</gml:posList></gml:LineString>
              )