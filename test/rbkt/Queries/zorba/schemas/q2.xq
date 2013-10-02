
import module namespace fn-zorba-util = "http://zorba.io/modules/schema"; 
import schema default element namespace "http://ns.example.com/books" at "books.xsd";

declare variable $books as document-node(element(BOOKLIST)) external;

let $x := ($books//PRICE)[1]
let $y := fn:data($x)
return (fn-zorba-util:schema-type($x), $y instance of xs:decimal, fn-zorba-util:schema-type($y))

