(:*******************************************************:)
(: Test: modules-28.xq                                   :)
(: Written By: Nicolae Brinza                            :)
(: Purpose: Cyclic module imports                        :)
(:*******************************************************:)

import module namespace defs1 = "http://www.w3.org/TestModules/defs1" at "modules-recursive1.xqi";


$defs1:var
