import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:large((), 1)

(:
Output: Error [ZXQP0021] An empty sequence cannot be promoted to the xs:double+ type.
:)
