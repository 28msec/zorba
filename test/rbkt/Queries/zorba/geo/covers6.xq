import module namespace geo = "http://expath.org/ns/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:covers(<gml:Point><gml:pos>1 1</gml:pos></gml:Point>,
           <gml:Point><gml:pos>1.00 1.00</gml:pos></gml:Point> )