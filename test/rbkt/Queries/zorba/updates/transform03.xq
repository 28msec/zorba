let $book := <book><bar/></book>
return
   copy $expanded := $book
   modify replace node $book/bar with <blub/>
   return $book
