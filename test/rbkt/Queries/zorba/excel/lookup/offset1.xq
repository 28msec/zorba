import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";


excel:offset(((1, 2, 3),
              (4, 5, 6),
              (7, 8, 9),
              (10,11,12)),
              4, 3,
              -1, -1)

(:
Output: Error [XQP0021] Offset function: rows and cols must be positive or zero 
:)