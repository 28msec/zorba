import module namespace zorba =
  "http://www.zorba-xquery.com/zorba/node-ref-functions";

declare variable $input-context external;

let $book := doc($input-context)/bib/book[1]
return zorba:node-reference($book)
