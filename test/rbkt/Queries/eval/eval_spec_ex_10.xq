declare variable $x := 20;

declare function local:f () { $x };

let $x := 22 return
using $x eval { "$x + local:f ()" }
