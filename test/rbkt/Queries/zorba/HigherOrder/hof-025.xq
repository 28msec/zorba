xquery version "3.0";
(: Higher Order Functions :)
(: Name and arity of a concat function :)
(: Author - Michael Kay, Saxonica :)

declare namespace o = "http://www.zorba-xquery.com/options/features";
declare option o:enable "hof";

let $f := concat#123456 
let $n := function-name($f)
return (local-name-from-QName($n), namespace-uri-from-QName($n), function-arity($f))
