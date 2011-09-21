(:*******************************************************:)
(: Test: mainModule3.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: the following dependency graph:              :)
(:             mainModule2                               :)
(:                /\                                     :)
(:   libraryModule6 libraryModule7                       :)
(:                \/                                     :)
(:          libraryModule5                               :)
(:*******************************************************:)

import module namespace
lmns="http://www.w3.org/TestModules/lmns" at
"libraryModule6.xqlib",
"libraryModule7.xqlib";

<mainModule3>{$lmns:var6 + $lmns:var7}</mainModule3>
