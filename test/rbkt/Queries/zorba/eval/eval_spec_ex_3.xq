declare variable $g := 11;
declare function local:f1 ($a) { $g + $a };

let $x := 10 return
using $x eval { "
declare function local:f2 () { $g + $x };
local:f1 ($x) + local:f2 ()
"}
