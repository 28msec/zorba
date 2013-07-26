import module namespace
math="http://zorba.io/modules/math";

math:ceiling(-2.5, 2)

(:
Output: Error [ZXQP0021] Ceiling function: both arguments must have the same sign
:)
