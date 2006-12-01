for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $para := $book/content//p[. ftcontains 
   ("task" && "performance" with stemming distance 
   at most 3 words) && "expert review" with stemming]
where count($para) > 0
return $book/metadata/title, $book//content
