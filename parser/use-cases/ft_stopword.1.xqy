for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $cont := $book//content[. ftcontains 
   "planning then conducting" with stop words 
   at "http://bstore1.example.com/StopWordList.xml"]
where count($cont)>0
return $book
