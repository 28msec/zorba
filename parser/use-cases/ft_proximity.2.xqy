for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "efficient" && "task" && "completion" 
   distance at most 10 words ordered]
where count($cont)>0
return $book
