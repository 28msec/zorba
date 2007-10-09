for $result at $i in
     for $book score $s in 
        doc("http://bstore1.example.com/full-text.xml")
        /books/book[. ftcontains "usability"]
      order by $s descending
      return $book
   where $i <= 2
   return <book number="{$result/@number}"> 
      $result/metadata/title</book>
