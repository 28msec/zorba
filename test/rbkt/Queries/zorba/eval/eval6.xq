import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

(util:eval-simple("declare variable $x := 1; $x")) + $x
