import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:mode((1, 3, 4, 2, "l"))

(:
Output: Error [XQP0021] Type promotion not possible: xs:string -> xs:double
:)