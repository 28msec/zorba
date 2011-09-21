xquery version "3.0";
(: Higher Order Functions :)
(: instance-of tests on user-defined function, varying the argument types - all true :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

declare function local:f($x as xs:long, $y as xs:NCName) as element(e) {
  <e x="{$x}" y="{$y}"/>
};

local:f#2 instance of function(*),
local:f#2 instance of function(xs:long, xs:NCName) as element(e),
local:f#2 instance of function(xs:anyAtomicType?, xs:anyAtomicType?) as element(e),
local:f#2 instance of function(item()*, item()*) as element(e)

