import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:convex-hull(<gml:LinearRing>
                <gml:posList>
                1 1 
                20 1
                50 30
                20 2
                1 1
                </gml:posList>
              </gml:LinearRing>
             )