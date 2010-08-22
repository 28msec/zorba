import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:relate(<gml:Polygon><gml:exterior>
                    <gml:LinearRing><gml:posList>10 10 20 10 30 40 20 40 10 10</gml:posList></gml:LinearRing>
           </gml:exterior></gml:Polygon>,

            <gml:LinearRing><gml:posList>0 0 20 20 20 30 0 20 0 0</gml:posList></gml:LinearRing>,
            
            "1**0**1**"           
              )