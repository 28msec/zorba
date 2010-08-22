import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:within(   <gml:LinearRing>
                <gml:posList>
                1 1 
                2 1
                5 3
                1 1
                </gml:posList>
              </gml:LinearRing>,
              
              <gml:LinearRing>
                <gml:posList>
                1 1 
                20 1
                50 30
                1 1
                </gml:posList>
              </gml:LinearRing>
             )