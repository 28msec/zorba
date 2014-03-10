

import module namespace refl = "http://zorba.io/modules/reflection";


for $x in (1, 5)
return count(refl:eval("for $i in 1 to $x where $i < 4 return $i"))
