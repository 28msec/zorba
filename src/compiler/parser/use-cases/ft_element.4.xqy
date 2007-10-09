for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $title := $book/metadata/title[. ftcontains "usability tests"] 
   or $book/content/part/chapter/title[. ftcontains "usability tests"] 
where count($title) > 0
return $book
