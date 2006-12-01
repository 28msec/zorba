for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $intro := $book/content/part/introduction[. ftcontains 
   "prototypes"]
where count($intro)>0
return $book
