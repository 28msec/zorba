import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-closed(<gml:Surface><gml:patches>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>1 1 2 1 2 2 1 2 1 1</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>2 0 3 0 3 3 2 3 2 0</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>3 0 4 0 4 3 3 3 3 0</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>3 3 4 3 4 8 3 8 3 3</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList>3 8 4 8 4 9 3 9 3 8</gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
              </gml:patches></gml:Surface>)