import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";


excel:offset(((1, 2, 3),
              (4, 5, 6),
              (7, 8, 9),
              (10,11,12)),
              4, 3,
              1, 1,
              3, 3)

(:
Output: Error [XQP0021] Offset function: inner array is outside the reference array
:)