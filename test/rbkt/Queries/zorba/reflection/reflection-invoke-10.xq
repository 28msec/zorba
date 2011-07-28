import module namespace ref  = "http://www.zorba-xquery.com/modules/reflection";
import module namespace rand = "http://www.zorba-xquery.com/modules/random";

declare variable $name as xs:QName := fn:QName('http://www.zorba-xquery.com/modules/random', 'random');

count( ref:invoke($name) ) > 0
