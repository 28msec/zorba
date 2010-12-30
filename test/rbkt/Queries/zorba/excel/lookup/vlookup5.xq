import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";

excel:vlookup("a", ((1, 2, 3),
                  (4, 5, 6),
                  (7, 8, 9),
                  ("A",11,12)),
                  3, 4,
                  2)
