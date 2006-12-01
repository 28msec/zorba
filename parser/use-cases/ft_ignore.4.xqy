for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $where := ($book//chapter/p | $book//chapter/p/footnote) 
   [. ftcontains "workstation" && "lab" 
   distance at most 6 words without content ./footnote]
where fn:count($where) > 0
return $b/metadata/title, $where
