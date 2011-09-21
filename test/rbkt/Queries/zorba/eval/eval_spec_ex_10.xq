(: Var Access over User def Function :)

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

declare variable $x := 20;

declare function local:f() { $x };

let $x := 22 return util:eval("$x + local:f()")
