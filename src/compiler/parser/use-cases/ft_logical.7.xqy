for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   (("résumés" with diacritics) || "drafts" 
   || "correspondence") not in "book drafts"]
where count($cont)>0
return $book
