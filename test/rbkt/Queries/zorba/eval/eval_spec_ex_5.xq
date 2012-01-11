(: Invalid (wrong use in FLWOR) :)

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

let $x := 42 return util:eval("$x")
