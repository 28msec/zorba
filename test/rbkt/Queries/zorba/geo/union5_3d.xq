import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:union(<gml:Surface><gml:patches>
                <gml:PolygonPatch><gml:exterior>
                    <gml:LinearRing><gml:posList> 1 1   2 2   3 4   2 4   1 1 </gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
                <gml:PolygonPatch srsDimension='3'><gml:exterior>
                    <gml:LinearRing><gml:posList> 10 10 1  20 15 2  30 40 3  20 40 2  10 10 1 </gml:posList></gml:LinearRing>
                </gml:exterior></gml:PolygonPatch>
              </gml:patches></gml:Surface>,

              <gml:LinearRing><gml:posList>11 11 12 12 13 14 12 14 11 11</gml:posList></gml:LinearRing>
              )