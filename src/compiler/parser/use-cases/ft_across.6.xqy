for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
where $book ftcontains "mouse"
return $book
