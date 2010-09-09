import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:coordinate-dimension(<gml:Polygon srsDimension='3'>
              <gml:exterior>
                <gml:LinearRing><gml:posList>
                1 1 3
                20 1  3
                20 20 3
                1 20 3
                1 1 3
                </gml:posList></gml:LinearRing>
              </gml:exterior>
              <gml:interior>
                <gml:LinearRing><gml:posList>
                2 2 3
                3 2 3
                3 3 3
                2 3 3
                2 2 3
                </gml:posList></gml:LinearRing>
              </gml:interior>
              <gml:interior>
                <gml:LinearRing><gml:posList>
                10 10 3
                20 10 3
                 20 20 4
                 10 20 4
                10 10 4
                </gml:posList></gml:LinearRing>
              </gml:interior>
              </gml:Polygon>)