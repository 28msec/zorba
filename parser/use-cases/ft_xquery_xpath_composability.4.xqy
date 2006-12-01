for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book/books/book[./metadata/title ftcontains 
    "usability"]
return <book number="{$book/@number}">
           {$book/metadata/title,  
             if ($book/metadata/price > 25)
             then <price>{concat("$", round($book/metadata/price))}</price>
             else ()
           }   
       </book>
