xquery version "3.0";
(: Higher Order Functions :)
(: In SequenceType syntax, Result type required if argument type given :)
(: Author - Michael Kay, Saxonica :)

declare function local:f($x as xs:integer) as xs:integer {
  $x + 1
};

let $f as function(xs:integer) := local:f#1