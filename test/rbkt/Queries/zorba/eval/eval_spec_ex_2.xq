
import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

declare variable $x := 41;

util:eval(concat ("$x", "+", "1"))
