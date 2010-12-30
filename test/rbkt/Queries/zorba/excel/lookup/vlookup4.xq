import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";

excel:vlookup(".3", (("21", 2, 3),
                  ("22", 5, 6),
                  ("23", 8, 9),
                  ("24",11,12)),
                  3, 4,
                  2,
                  fn:false())
