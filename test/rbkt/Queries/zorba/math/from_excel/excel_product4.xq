import module namespace
math="http://zorba.io/modules/math";

math:product((5, 15, 30, "POP"))

(:
Output: Error [ZXQP0021] Type promotion not possible: xs:string -> xs:double
:)
