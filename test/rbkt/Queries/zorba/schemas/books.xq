
import schema default element namespace "http://ns.example.com/books" at "books.xsd";

declare variable $books as document-node(element(BOOKLIST)) external;


<out>
  <a>{$books/BOOKLIST instance of schema-element(BOOKLIST)}</a>
</out>        
