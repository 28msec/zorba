import module namespace
excel="http://www.zorba-xquery.com/modules/excel/math";

excel:gcd((-5, 0, 2))

(:
Output: Error [XQP0021] gcd function: numbers should be greater than zero or equal
:)