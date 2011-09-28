xquery version "3.0";
(: Higher Order Functions :)
(: Parenthesized expression in a function call :)
(: Author - Michael Kay, Saxonica :)

(if (current-date() gt xs:date('2000-12-31')) then upper-case#1 else lower-case#1)("Mike")

