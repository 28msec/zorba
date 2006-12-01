for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $ct := $book/content/part/chapter/title[. ftcontains 
   "usability" && ("test" with stemming)]
where count($ct)>0
return <book number="{$book/@number}"> 
          {for $title in $ct
          return $title} 
             <number-of-steps> 
                {count($title/..//step)}
             </number-of-steps>
       </book>
