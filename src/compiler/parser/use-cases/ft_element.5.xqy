for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
where $book//subject ftcontains "usability testing"
return $book/metadata/(title|author)
