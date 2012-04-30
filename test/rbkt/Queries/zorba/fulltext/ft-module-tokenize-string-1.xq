import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

let $x := "hello, world"
let $tokens := ft:tokenize-string( $x, xs:language("en") )
return $tokens[1] = "hello"
   and $tokens[2] = "world"

(: vim:set et sw=2 ts=2: :)
