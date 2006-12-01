for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "users" && "feeling" && ("well served" || "well-served")
   with stemming window 15 words ordered]
where count($cont)>0
return $book
