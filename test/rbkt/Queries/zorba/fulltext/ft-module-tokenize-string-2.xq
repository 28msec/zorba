import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

declare ft-option using language "en";

let $x := "hello, world"
let $tokens := ft:tokenize-string( $x )
return $tokens[1] = "hello"
   and $tokens[2] = "world"

(: vim:set et sw=2 ts=2: :)
