for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   (("usable" with stemming) && "testing" phrase) 
   || (("use" with stemming) && "testing" phrase)]
where count($cont)>0
return $book/@number, $book/metadata/title/text(), $cont
