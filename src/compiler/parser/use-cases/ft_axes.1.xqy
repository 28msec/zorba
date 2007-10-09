for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $para := $book//p[. ftcontains "computer 
   workstation"]
let $fn := $para/footnote[. ftcontains "comfortable"]
where count($fn)>0
return $book/metadata/title, $para
