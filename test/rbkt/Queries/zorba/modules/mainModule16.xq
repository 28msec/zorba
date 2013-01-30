(:*******************************************************:)
(: Test: mainModule16.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: Error XQST0036                               :)
(:*******************************************************:)

xquery version "1.0";

import module namespace math = "http://example.org/math-functions" at
"libraryModule12.xqlib";

declare namespace geometry = "http://www.zorba-xquery.com/schema/test/triangle_schema";

<result>{math:area(geometry:triangle("Right"))}</result>
