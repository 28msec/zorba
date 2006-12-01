for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "planning then conducting" without stop words]
where count($cont)>0
return $book
