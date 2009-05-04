(:*******************************************************:)
(: Test: mainModule11.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: XQST0049 Duplicate variable declaration: one :)
(: in the imported module, and the other in the main one :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule2.xqlib";
(: insert-end :)

declare variable $lmns:flag2 as xs:integer := 22;

<result>{$lmns:fag2}</result>

