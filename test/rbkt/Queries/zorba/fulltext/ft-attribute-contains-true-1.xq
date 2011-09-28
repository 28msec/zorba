(: Tests tokenization of attributes. :)

let $x := <msg subject="hello"/>
return $x/@subject contains text "hello"
