for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book/content[. ftcontains 
   "not been approved" with stop words at
   "http://bstore1.example.com/StopWordList.xml" 
   except ("not")]
where count($cont)>0
return $book/metadata/title, $book/content
