import module namespace ref =
  "http://www.zorba-xquery.com/modules/node-reference";

declare variable $input-context external;

let $book := doc($input-context)/bib/book[1]
let $bookref := ref:node-reference($book)
return ref:node-by-reference($bookref)
