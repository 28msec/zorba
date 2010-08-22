import module namespace geo = "http://www.zorba-xquery.com/modules/geo";
declare namespace gml="http://www.opengis.net/gml";

geo:relate(   <gml:LineString><gml:posList>1 1 10 0</gml:posList></gml:LineString>,

              <gml:LinearRing><gml:posList>0 0 20 20 20 30 0 20 0 0</gml:posList></gml:LinearRing>,
              
              "******T**"
              )