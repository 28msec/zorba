(: Global Var and Function Access :)

import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

declare variable $g := 11;

declare function local:f1($a) { $g + $a };

let $x := 10 
return
  util:eval
  ( 
    "
    declare function local:f2() { $g + $x };

    local:f1($x) + local:f2()
    "
  )
