for $book score $s in 
   doc("http://bstore1.example.com/full-text.xml")
   /books/book[. ftcontains "usability"]
where $s > 0.1
return $book/metadata/title
