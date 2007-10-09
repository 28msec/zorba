for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[./metadata/title ftcontains 
   "usability"]
return <book number="{$book/@number}">
          {$book/metadata/title,
             if (count($book/metadata//author) > 0) 
             then $book/metadata//author 
             else $book/metadata//publisher}
       </book>
