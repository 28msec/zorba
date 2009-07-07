
import schema default element namespace "http://ns.example.com/books" at "books.xsd";

declare variable $books as document-node(element(BOOKLIST)) external;


<out>
  <a>{$books/BOOKLIST/BOOKS/ITEM[1]/PRICE instance of element(*, xs:decimal)}</a>
</out>        
