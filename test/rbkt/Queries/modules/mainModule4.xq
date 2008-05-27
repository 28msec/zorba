(:*******************************************************:)
(: Test: mainModule4.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: the following dependency graph:              :)
(:                mainModule4                            :)
(:            /      |     	\                        :)
(:libraryModule3 libraryModule4 libraryModule8           :)
(:            \      |          /                        :)
(:              libraryModule5                           :)
(:*******************************************************:)

import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule3.xqlib",
"libraryModule4.xqlib";

import module namespace
lm8ns="http://www.w3.org/TestModules/lm8ns" at
"libraryModule8.xqlib";

<mainModule4>{lmns:moduleNamespace()}{lm8ns:moduleNamespace()}</mainModule4>

