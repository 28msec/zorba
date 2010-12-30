import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";

excel:hlookup(fn:true(), 
                 ((1, 2, fn:false()),
                  (4, 5, 6),
                  (7, 8, 9),
                  (10,11,12)),
                  3, 4,
                  2)
