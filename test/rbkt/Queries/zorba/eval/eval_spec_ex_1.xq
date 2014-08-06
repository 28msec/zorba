
import module namespace util = "http://zorba.io/modules/reflection";

let $x := 10
return util:eval("declare variable $x := 11; $x + 1")
