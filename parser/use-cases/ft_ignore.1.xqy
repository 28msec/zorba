for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $p := $book//p [. ftcontains "testing" 
   && ("guidance" || "correct") distance at 
   most 60 words without content *] 
where count($p) > 0
return $book
