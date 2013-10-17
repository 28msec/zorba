
import module namespace util = "http://zorba.io/modules/reflection";

declare variable $x := 41;

util:eval(concat ("$x", "+", "1"))
