xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, system function :)
(: Author - Michael Kay, Saxonica :)


let $f := fn:round#1 return $f(1.2345)