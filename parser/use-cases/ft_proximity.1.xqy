for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "software" && "developer" with stemming 
   distance at most 3 words]
where count($cont)>0
return $book
