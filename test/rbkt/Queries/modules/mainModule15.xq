(:*******************************************************:)
(: Test: mainModule15.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: import libraryModule that depends on a schema:)
(:*******************************************************:)

import module namespace math = "http://example.org/math-functions" at
"libraryModule13.xqlib";

import schema namespace geometry = "triangle_schema.xsd" at 
"triangle_schema.xsd";

<result>{fn:concat('created triangle of type ' ,math:createTriangle(0))}</result>
