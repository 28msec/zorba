import module namespace
math="http://zorba.io/modules/math";

math:gcd((-5, 0, 2))

(:
Output: Error [ZXQP0021] gcd function: numbers should be greater than zero or equal
:)
