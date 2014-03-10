(: Invalid (wrong use in FLWOR) :)

import module namespace util = "http://zorba.io/modules/reflection";

let $x := 42 return util:eval("$x")
