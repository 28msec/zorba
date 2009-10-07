module namespace math = "http://www.zorba-xquery.com/modules/math";

(:~
 : Computes the sqrt of the value passed as argument.
 :
 : @param $arg the argument to compute the sqrt of.
 :
 : @returns The sqrt of the $arg value.
 :          If the type of $arg is one of the four numeric types 
 :          (i.e. xs:float, xs:double, xs:decimal or xs:integer),
 :          the type of the result is the same as the type of $arg.
 :          If the type of $arg is a type derived from one of the
 :          numeric types, the result is an instance of the
 :          base numeric type.
 :)
declare function math:sqrt ($arg as xs:anyAtomicType?) as xs:anyAtomicType? external;

(:~
 :)
declare function math:exp ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:log ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:sin ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:cos ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:tan ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:asin ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:acos ($arg as xs:double) as xs:double external;

(:~
 :)
declare function math:atan ($arg as xs:double) as xs:double external;
