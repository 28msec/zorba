xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, system function :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

let $f := fn:round#1 return $f(1.2345)
