import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:large((), 1)

(:
Output: Error [XQP0021] An empty sequence cannot be promoted to the xs:double+ type.
:)