import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

let $geom := <myGeom srsName="http://www.zorba-xquery.com0/">
              <gml:boundedBy>
              <gml:Envelope srsName="http://www.zorba-xquery.com2/">
                  <lowerCorner>1 1</lowerCorner>
                  <upperCorner>2 2</upperCorner>
              </gml:Envelope>
              </gml:boundedBy>
              <gml:MultiPoint>
                <gml:Point><gml:pos>1 1</gml:pos></gml:Point>
              </gml:MultiPoint>
             </myGeom>
return
geo:srid($geom//gml:MultiPoint
              )