(:*******************************************************:)
(: Test: moduleMain12.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: XPST0081                                     :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lm10ns="http://www.w3.org/TestModules/lm10ns" at
"libraryModule11.xqlib";
(: insert-end :)

<result>{lm10ns:moduleNamespace()}</result>
