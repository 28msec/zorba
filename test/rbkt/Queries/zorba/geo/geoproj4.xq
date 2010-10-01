import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";
declare namespace gml="http://www.opengis.net/gml";

geoproj:omerc-gmlpos-to-wgs84(10, 10, 1 div 1000, 
                (<gml:pos xmlns:gml="http://www.opengis.net/gml">109.29273684961206 110.79318638310056</gml:pos>))