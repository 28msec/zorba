(:*******************************************************:)
(: Test: moduleMain7.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XQST0088 Duplicate namespace prefix   :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns="" at
"libraryModule1.xqlib";
(: insert-end :)

<result>{lmns:text()}</result>

