let $x := 10 return
using $x eval {
"declare variable $x := 11;
$x + 1"
}
