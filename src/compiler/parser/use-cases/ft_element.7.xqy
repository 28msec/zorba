for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $exactTitle := $book/metadata/title[. ftcontains 
   "improv.* the usability of a web site through expert 
   reviews and usability testing" entire content]
where count($exactTitle)>0
return $exactTitle
