xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, user-defined function :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

declare function local:f() as xs:integer {
  42
};

declare function local:f($x as xs:integer) as xs:integer {
  $x + 1
};

let $f := local:f#0 return $f()
