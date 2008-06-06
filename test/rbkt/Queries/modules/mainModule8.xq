(:*******************************************************:)
(: Test: moduleMain8.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XQST0059 No library module found      :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule99.xqlib";
(: insert-end :)

<result>{lmns:text()}</result>

