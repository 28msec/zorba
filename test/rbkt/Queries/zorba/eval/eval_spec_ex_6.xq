(: Atomization :)

import module namespace util = "http://zorba.io/modules/reflection";

declare variable $n := <a><b>1</b><b>+$x</b></a>;

declare variable $x :=2;

util:eval($n)
