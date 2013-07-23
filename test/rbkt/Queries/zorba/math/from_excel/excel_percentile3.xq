import module namespace
math="http://zorba.io/modules/math";

math:percentile((1, 3, 4, 3, 2, 2, 5, 3, 5), 5)

(:
Output: Error [ZXQP0021] Percentile function: k must be a value between 0 and 1 inclusive
:)
