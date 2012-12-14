import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

let $doc := <msg xml:lang="es">hola, mundo</msg>
let $tokens := ft:tokenize-node( $doc )
let $t1 := validate { $tokens[1] }
let $t2 := validate { $tokens[2] }

return  $t1/@value = "hola"
    and $t1/@lang = "es"
    and $t1/@paragraph = 1
    and $t1/@sentence = 1

    and $t2/@value = "mundo"
    and $t2/@lang = "es"
    and $t2/@paragraph = 1
    and $t2/@sentence = 1

(: vim:set et sw=2 ts=2: :)
