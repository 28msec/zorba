import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:union(<gml:Point><gml:pos>10 10</gml:pos></gml:Point>,
           <gml:LineString><gml:posList>0 0 2 2</gml:posList></gml:LineString> )