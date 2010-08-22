import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:envelope(<gml:LinearRing>
                <gml:posList>
                1 1 
                2 1
                5 3
                1 1
                </gml:posList>
              </gml:LinearRing>)