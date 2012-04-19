(:
 : Checks if the underlying EvalIterator is reset properly in case if not every 
 : resulting item of the EvalIterator in the iteration before was consumed.
 : Simulated by doing an empty check on resulting items of the eval function.
 :)

import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";

for $x in (1,2,3)
let $code := "($x, 1, 2, 3)" 
return
  if (not(empty(reflection:eval($code)))) then
    "not empty"
  else
    "empty"
