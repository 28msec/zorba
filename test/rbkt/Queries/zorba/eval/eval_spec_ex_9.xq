(: Var Access :)

import module namespace util = "http://zorba.io/modules/reflection";

let $x := "21" return util:eval(concat($x, " + xs:double ($x)"))
