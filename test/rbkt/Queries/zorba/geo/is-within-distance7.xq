import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-within-distance(<gml:Point><gml:pos>0 1</gml:pos></gml:Point>,
           <gml:LineString><gml:posList>0 0 2 2</gml:posList></gml:LineString>,
           0.8 )