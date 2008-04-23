declare namespace myns="a";
declare variable $myns:g := 42;
let $y := 1 return
using $myns:x := $myns:g, $y eval {
"declare namespace myns1='a';
declare function local:f () { 11 + $myns:g + $y};
$myns1:x + local:f()"
}
