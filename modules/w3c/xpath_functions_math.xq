(:~
 : This module contains all the functions part of the
 : W3C XPath and XQuery Functions and Operators 3.0 
 : section "4.7 Trigonometric and exponential functions".
 :
 :
 : @author www.w3c.org
 : @see http://www.w3.org/TR/xpath-functions-30/#trigonometry
 : @project www.w3.org/2005
 :
 :)
module namespace math = "http://www.w3.org/2005/xpath-functions/math";

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-pi">math:pi</a>
 :)
declare function math:pi() as xs:double external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-exp">math:exp</a>
 :)
declare function math:exp($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-exp10">math:exp10</a>
 :)
declare function math:exp10($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-log">math:log</a>
 :)
declare function math:log($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-log10">math:log10</a>
 :)
declare function math:log10($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-pow">math:pow</a>
 :)
declare function math:pow($x as xs:double?, $y as numeric) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-sqrt">math:sqrt</a>
 :)
declare function math:sqrt($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-sin">math:sin</a>
 :)
declare function math:sin($θ as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-cos">math:cos</a>
 :)
declare function math:cos($θ as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-tan">math:tan</a>
 :)
declare function math:tan($θ as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-asin">math:asin</a>
 :)
declare function math:asin($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-acos">math:acos</a>
 :)
declare function math:acos($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-atan">math:atan</a>
 :)
declare function math:atan($arg as xs:double?) as xs:double? external;

(:~
 : @see for semantics please check <a href="http://www.w3.org/TR/xpath-functions-30/#func-math-atan2">math:atan2</a>
 :)
declare function math:atan2($y as xs:double, $x as xs:double) as xs:double external;