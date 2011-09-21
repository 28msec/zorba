(: Var Access :)

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

let $x := "21" return util:eval(concat($x, " + xs:double ($x)"))
