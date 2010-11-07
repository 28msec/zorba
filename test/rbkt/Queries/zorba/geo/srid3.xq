import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

let $mygeo := <myGeometryCollection srsName="http://zorba.com">
                <myGeometry srsName="http://www.zorba-query.com">
                <gml:LineString><gml:pos>1 1</gml:pos><gml:pos>2 1</gml:pos></gml:LineString>
                </myGeometry>
                </myGeometryCollection>
return
geo:srid($mygeo//gml:LineString
                )