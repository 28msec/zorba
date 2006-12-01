for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "goal" && "obstacles" && "task" ordered]
where count($cont)>0
return $book
