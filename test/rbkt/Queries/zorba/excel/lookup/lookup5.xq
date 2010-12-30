import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";

(: array form :)
excel:lookup(2, 
            ((1, 2, 3), 
             (4, 5, 6),
             (7, 8, 9),
             (11, 12, 13)),
             3, 4)
