for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $chap := $book//chapter[. ftcontains 
   "at any computer workstation or in a lab" 
   without content (.//footnote[. ftcontains 
   "workstation." with wildcards])]
where count($chap) > 0
return $book/metadata/title, $chap
