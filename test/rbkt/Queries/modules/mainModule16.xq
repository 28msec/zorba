(:*******************************************************:)
(: Test: mainModule16.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: Error XPST0081                               :)
(:*******************************************************:)

import module namespace math = "http://example.org/math-functions" at
"libraryModule12.xqlib";

<result>{math:area(geometry:triangle("Right"))}</result>