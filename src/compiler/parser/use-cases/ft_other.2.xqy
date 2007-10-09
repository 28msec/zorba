for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $stitle := $book/metadata/title[./@shortTitle ftcontains 
   "manuscript guides" with stemming]
let $cont := $book//componentTitle[. ftcontains 
   "user profiling" with stemming]
where count($stitle)>0 and count($cont)>0
return data($book/metadata/title/@shortTitle)
