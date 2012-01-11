xquery version "3.0";
(: Higher Order Functions :)
(: unordered{} applied to a function item :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

function-name((upper-case#1, lower-case#1)[ordered{.}("Mike") = "MIKE"])

