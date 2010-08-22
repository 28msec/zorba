import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:relate(<gml:Point><gml:pos>18 11</gml:pos></gml:Point>,
           
           <gml:Polygon><gml:exterior>
                    <gml:LinearRing><gml:posList>10 10 20 10 30 40 20 40 10 10</gml:posList></gml:LinearRing>
           </gml:exterior></gml:Polygon>,
           
           "0********"
              
              )