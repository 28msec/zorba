xquery version "3.0";
(: Higher Order Functions :)
(: apply string() to a function item :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

declare function local:f($x as xs:integer) as xs:integer {
  $x + 1
};

string(local:f#1)
