(:*******************************************************:)
(: Test: moduleMain9.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XQST0059 No namespace found           :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns99="http://www.w3.org/TestModules/lmns99" at
"libraryModule1.xqlib";
(: insert-end :)

<result>{lmns999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999:text()}</result>

