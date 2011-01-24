import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";
declare namespace geoproj-param = "http://www.zorba-xquery.com/modules/geoproj-param";

geoproj:wgs84-to-omerc(0, 0, 1, 
                       (<geoproj-param:latlong>
                           <geoproj-param:lat>-2</geoproj-param:lat>
                           <geoproj-param:long>0</geoproj-param:long>
                        </geoproj-param:latlong>))