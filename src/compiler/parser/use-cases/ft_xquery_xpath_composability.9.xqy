for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
for $cont := $book/content[. ftcontains ("successfully" 
   && "completing" && "tasks") with stemming
   window at most (count(./contents/part/chapter) * 3) 
   words] 
where count($cont)>0
return $book/metadata/title, $cont
