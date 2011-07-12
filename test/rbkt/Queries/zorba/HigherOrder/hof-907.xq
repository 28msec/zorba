xquery version "3.0";
(: Higher Order Functions :)
(: apply deep-equal() to a function item :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

declare function local:f($x as xs:integer) as xs:integer {
  $x + 1
};

deep-equal((1,2,3,4,local:f#1), (1,2,3,4,local:f#1))
