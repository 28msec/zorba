for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "expert review methods" occurs at least 2 times]
where count($cont)>0
return $book
