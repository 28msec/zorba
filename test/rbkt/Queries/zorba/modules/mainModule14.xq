(:*******************************************************:)
(: Test: mainModule14.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: import libraryModule that depends on a schema:)
(:*******************************************************:)

import module namespace math = "http://example.org/math-functions" at
"libraryModule12.xqlib";

import schema namespace geometry = "http://www.zorba-xquery.com/schema/test/triangle_schema" at 
"triangle_schema.xsd";

<result>{math:area(geometry:triangle("Right"))}</result>
