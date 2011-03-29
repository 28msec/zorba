
import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

let $x := 10
return util:eval-simple("declare variable $x := 11; $x + 1")
