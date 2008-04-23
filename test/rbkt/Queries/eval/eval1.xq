declare namespace myns="a";
declare variable $myns:g := 42;
using $myns:x := $myns:g eval {
"declare namespace myns1='a';
declare function local:f () { 11 };
$myns1:x + local:f()"
}
