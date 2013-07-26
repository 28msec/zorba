import module namespace
math="http://zorba.io/modules/math";

math:floor(-2.5, 2)

(:
Output: Error [ZXQP0021] Floor function: both arguments must have the same sign
:)
