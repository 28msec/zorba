import module namespace ref  = "http://zorba.io/modules/reflection";
import module namespace rand = "http://zorba.io/modules/random";

declare variable $name as xs:QName := fn:QName('http://zorba.io/modules/random', 'random');

count( ref:invoke($name) ) > 0
