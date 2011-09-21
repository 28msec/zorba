(:*******************************************************:)
(: Test: mainModule5.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: the following dependency graph:              :)
(:                mainModule5                            :)
(:            /      |          \                        :)
(:libraryModule5 libraryModule9 libraryModule10          :)
(:*******************************************************:)

import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule5.xqlib";

import module namespace
lm9ns="http://www.w3.org/TestModules/lm9ns" at
"libraryModule9.xqlib";

import module namespace
lm10ns="http://www.w3.org/TestModules/lm10ns" at
"libraryModule10.xqlib";

<mainModule5>{lmns:moduleNamespace()}{lm9ns:moduleNamespace()}{lm10ns:moduleNamespace()}</mainModule5>
