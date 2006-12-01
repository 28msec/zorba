for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
where every $pub in $book//publisher satisfies 
   ($pub ftcontains "ersatz" && "publications")
return $book
