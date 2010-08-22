import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:equals(<gml:LinearRing>
                <gml:posList>
                1 1 
                2 1
                5 3
                1 1
                </gml:posList>
              </gml:LinearRing>,
              <gml:Polygon><gml:exterior>
              <gml:LinearRing>
                <gml:posList>
                1 1 
                2 1
                5 3
                1 1
                </gml:posList>
              </gml:LinearRing>
              </gml:exterior></gml:Polygon>
             )