for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $up := $book[./metadata ftcontains "usability" 
   && ! "plan"]
where count($up) > 0
return $book
