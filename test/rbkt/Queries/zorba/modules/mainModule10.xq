(:*******************************************************:)
(: Test: mainModule10.xq                                 :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/05/26                                      :)
(: Purpose: XQST0034 Duplicate function declaration: one :)
(: in the imported module, and the other in the main one :)
(:*******************************************************:)

(: insert-start :)
import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule1.xqlib";
(: insert-end :)

declare function lmns:text ()
{
  "libraryModule1.xqlib"
};

<result>{lmns:text()}</result>
