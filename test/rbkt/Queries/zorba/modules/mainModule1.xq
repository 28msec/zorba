(:*******************************************************:)
(: Test: moduleMain1.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: Error: XQST0034 Duplicate definition         :)
(:*******************************************************:)

(: insert-start :)
import module namespace 
lmns="http://www.w3.org/TestModules/lmns" at 
"libraryModule1.xqlib", 
"libraryModule2.xqlib";
(: insert-end :)

<result>{lmns:text()}</result>
