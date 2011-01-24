import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";
declare namespace geoproj-param = "http://www.zorba-xquery.com/modules/geoproj-param";

geoproj:omerc-to-wgs84(10, 100, 1, 
                (<geoproj-param:coord>
                    <geoproj-param:x>218616.56181767347</geoproj-param:x>
                    <geoproj-param:y>111339.45363464409</geoproj-param:y>
                 </geoproj-param:coord>,
                 <geoproj-param:coord>
                    <geoproj-param:x>217845.99308707257</geoproj-param:x>
                    <geoproj-param:y>222020.3879810845</geoproj-param:y>
                 </geoproj-param:coord>))