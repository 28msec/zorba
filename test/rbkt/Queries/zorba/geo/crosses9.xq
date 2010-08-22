import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:crosses(<gml:LinearRing>
                <gml:posList>
                1 1 
                20 1
                50 30
                1 1
                </gml:posList>
              </gml:LinearRing>,
              <gml:LinearRing>
                <gml:posList>
                10 2 
                30 2
                30 4
                10 2
                </gml:posList>
              </gml:LinearRing>
             )