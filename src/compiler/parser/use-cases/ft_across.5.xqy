for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $bi := $book/content/introduction[./p ftcontains 
   "identif.*" with wildcards]
let $pi := $book/content/part/introduction[./p ftcontains 
   "identif.*" with wildcards]
where count($bi)>0 and count($pi)>0
return $book
