for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
where $book//subject[. ftcontains "?????" language "zh"]
   and $book/content/introduction/author[. ftcontains 
   "Elina" && "Rose" distance at most 3 words]
   and $book//content[. ftcontains "Millicent" && "Marigold" 
   distance at most 3 words]
return <book number="{$book/@number}"> 
          {$book/metadata/title, $book//subject, 
          $book/content/introduction, $book//content} 
       </book>
