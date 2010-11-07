import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:is-empty(<gml:LineString><gml:posList/></gml:LineString>)