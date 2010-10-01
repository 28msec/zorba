import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";

geoproj:wgs84-to-omerc(-11, 169, 1, 
                       (<latlong><lat>-72</lat><long>170</long></latlong>,
                       <latlong><lat>70</lat><long>170</long></latlong>))