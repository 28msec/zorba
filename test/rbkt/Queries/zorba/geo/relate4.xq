import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:relate(<gml:Polygon>
              <gml:exterior>
                <gml:LinearRing><gml:posList>
                1 1 
                20 1 
                20 20 
                30 20
                30 30 
                1 30 
                1 1
                </gml:posList></gml:LinearRing>
              </gml:exterior>
              <gml:interior>
                <gml:LinearRing><gml:posList>
                2 2 
                3 2 
                3 3 
                2 3 
                2 2
                </gml:posList></gml:LinearRing>
              </gml:interior>
              <gml:interior>
                <gml:LinearRing><gml:posList>
                10 10 
                19 10
                 19 19 
                 10 19 
                10 10
                </gml:posList></gml:LinearRing>
              </gml:interior>
              </gml:Polygon>,
              
              
                <gml:LinearRing><gml:posList>
                11 11 
                18 11 
                18 18 
                11 18 
                11 11
                </gml:posList></gml:LinearRing>,
                
                "F********"
                )
              