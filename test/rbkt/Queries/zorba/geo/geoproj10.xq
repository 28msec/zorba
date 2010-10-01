import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";

geoproj:wgs84-to-omerc(-11, 0, 1, 
                       (<latlong><lat>-12</lat><long>0</long></latlong>,
                       <latlong><lat>10</lat><long>0</long></latlong>))