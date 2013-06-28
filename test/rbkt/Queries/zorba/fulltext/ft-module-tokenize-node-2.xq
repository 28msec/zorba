jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";

let $doc := <msg xml:lang="es">hola, mundo</msg>
let $tokens := ft:tokenize-node( $doc )
let $t1 := $tokens[1]
let $t2 := $tokens[2]

return  $t1.value eq "hola"
    and $t1.lang eq "es"
    and $t1.paragraph eq 1
    and $t1.sentence eq 1

    and $t2.value eq "mundo"
    and $t2.lang eq "es"
    and $t2.paragraph eq 1
    and $t2.sentence eq 1

(: vim:set et sw=2 ts=2: :)
