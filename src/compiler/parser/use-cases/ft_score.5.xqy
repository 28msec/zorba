for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let score $s := $book//content ftcontains "software"
order by $s descending
return $book
