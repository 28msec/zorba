import module namespace
math="http://zorba.io/modules/math";

math:subtotal(3, (2, 3, 4, "", "x"))

(:
Output: Error [ZXQP0021] Type promotion not possible: xs:string -> xs:double
:)
