for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $chap := $book//chapter[. ftcontains 
   "users can be tested at any computer workstation 
   or in a lab" without content .//footnote] 
where count($chap) > 0
return $book/metadata/title, $chap
