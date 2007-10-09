for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $not := $book[. ftcontains ! "us.* testing"
   with wildcards]
where count($not) > 0
return $book
