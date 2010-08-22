import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:within(<gml:Point><gml:pos>1 1</gml:pos></gml:Point>,
            <gml:MultiPoint>
                <gml:Point><gml:pos>1 1</gml:pos></gml:Point>
                <gml:Point><gml:pos>1 2</gml:pos></gml:Point>
              </gml:MultiPoint>
              
              )