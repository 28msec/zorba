for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $subj := $book/metadata/subjects/subject[. ftcontains 
   "web site" && "usability"]
where count($subj)>0
return $book
