for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains "r�sum�." 
   with wildcards with diacritics]
where count($cont) >0    
return $book
