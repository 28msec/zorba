import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:num-geometries(<gml:Polygon>
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
              </gml:Polygon>
              )