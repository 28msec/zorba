xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, constructor function, non default namespace :)
(: Author - Michael Kay, Saxonica :)


let $f := xs:date#1 return $f('2008-01-31')