(:*******************************************************:)
(: Test: mainModule2.xq                                  :)
(: Written By: Sorin Nasoi                               :)
(: Date: 2008/06/26                                      :)
(: Purpose: the following dependency graph:              :)
(:             mainModule2                               :)
(:                /\                                     :)
(:   libraryModule3 libraryModule4                       :)
(:                \/                                     :)
(:          libraryModule5                               :)
(:*******************************************************:)

import module namespace 
lmns="http://www.w3.org/TestModules/lmns" at 
"libraryModule3.xqlib",
"libraryModule4.xqlib";

<mainModule2>{lmns:moduleName()}{lmns:moduleType()}</mainModule2>
