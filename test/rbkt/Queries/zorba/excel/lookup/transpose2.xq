import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";


excel:transpose(((1, 2, 3), 
                 (4, 5, 6),
                 (7, 8, 9),
                 (10,11,12)),
                 3, 4)
