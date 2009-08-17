
import module namespace fn-zorba-util = "http://www.zorba-xquery.com/zorba/util-functions"; 
import schema default element namespace "http://ns.example.com/books" at "books.xsd";

declare variable $books as document-node(element(BOOKLIST)) external;

let $x := fn:data(($books//PRICE)[1])
return ($x instance of xs:decimal, fn-zorba-util:schema-type($x))

