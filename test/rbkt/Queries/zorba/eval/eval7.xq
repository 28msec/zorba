import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

declare variable $s :=
'module namespace math = "http://example.org/math-functions";
 declare variable $math:pi := 3.14;';

util:eval-simple($s)
