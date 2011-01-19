import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:overlaps(<gml:LinearRing>
                <gml:posList>
                1 1 
                20 1
                50 30
                1 1
                </gml:posList>
              </gml:LinearRing>,
              <gml:LineString>
                <gml:posList>
                1 1 
                20 1
                30 1
                40 1
                </gml:posList>
              </gml:LineString>
             )