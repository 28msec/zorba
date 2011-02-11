(: Tests tokenization of attributes. :)

let $x := <msg subject="hello"/>
return $x/@subject contains text "hello"

(: vim:set syntax=xquery et sw=2 ts=2: :)
