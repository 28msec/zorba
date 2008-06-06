(:*******************************************************:)
(: Test: moduleMain6.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XQST0047 Duplicate namespace prefix   :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule1.xqlib";

import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule2.xqlib";
(: insert-end :)

<result>{lmns:text()}</result>
