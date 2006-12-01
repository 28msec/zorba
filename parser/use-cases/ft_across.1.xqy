for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $chap := $book//chapter[. ftcontains 
   "one of the best known lists of heuristics is 
   Ten Usability Heuristics"]
where count($chap) > 0
return $book
