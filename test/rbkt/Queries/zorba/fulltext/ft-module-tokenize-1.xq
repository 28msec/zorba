import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

let $doc := <msg>hello, world</msg>
let $tokens := ft:tokenize( $doc, xs:language("en") )
let $t1 := $tokens[1]
let $t2 := $tokens[2]

return  $t1/@value = "hello"
    and $t1/@lang = "en"
    and $t1/@paragraph = 1
    and $t1/@sentence = 1

    and $t2/@value = "world"
    and $t2/@lang = "en"
    and $t2/@paragraph = 1
    and $t2/@sentence = 1

(: vim:set et sw=2 ts=2: :)
