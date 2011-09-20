xquery version "3.0";
(: Higher Order Functions :)
(: partial-apply, argument value invalid for target function :)
(: Author - Michael Kay, Saxonica :)


let $ops := partial-apply(substring-before#2, 42, 2)
return $ops('Michael Kay')