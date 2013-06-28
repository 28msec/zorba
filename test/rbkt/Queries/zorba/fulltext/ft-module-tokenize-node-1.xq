jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

let $doc := <msg>hello, world</msg>
let $tokens := ft:tokenize-node( $doc, xs:language("en") )
let $t1 := $tokens[1]
let $t2 := $tokens[2]

return  $t1.value eq "hello"
    and $t1.lang eq "en"
    and $t1.paragraph eq 1
    and $t1.sentence eq 1

    and $t2.value eq "world"
    and $t2.lang eq "en"
    and $t2.paragraph eq 1
    and $t2.sentence eq 1

(: vim:set et sw=2 ts=2: :)
