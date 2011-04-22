xquery version "3.0";
(: Higher Order Functions :)
(: inline function literal, constructor function, default namespace :)
(: Author - Michael Kay, Saxonica :)

declare default function namespace "http://www.w3.org/2001/XMLSchema";


let $f := date#1 return $f('2008-01-31')