import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:fact(-1)

(:
Output: Error [XQP0021] Fact function does not accept numbers smaller than zero
:)