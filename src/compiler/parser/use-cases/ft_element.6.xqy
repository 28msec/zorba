for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $title := $book/metadata/title[. ftcontains 
"improving" && "usability" distance at 
most 2 words ordered at start]
where count($title)>0
return $title
