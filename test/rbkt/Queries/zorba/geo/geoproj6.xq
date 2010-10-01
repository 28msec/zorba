import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";

geoproj:wgs84-to-omerc(10, 100, 1, 
                        (<latlong><lat>11</lat><long>102</long></latlong>,
                        <latlong><lat>12</lat><long>102</long></latlong>))
