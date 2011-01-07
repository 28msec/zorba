import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:subtotal(3, (2, 3, 4, "", "x"))

(:
Output: Error [XQP0021] Type promotion not possible: xs:string -> xs:double
:)