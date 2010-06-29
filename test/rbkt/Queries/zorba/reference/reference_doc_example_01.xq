import module namespace ref =
  "http://www.zorba-xquery.com/modules/node-reference";

declare variable $input-context external;

let $book := doc($input-context)/bib/book[1]
return ref:node-reference($book)
