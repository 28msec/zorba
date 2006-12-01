for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $chapters := $book//chapter[./p ftcontains "usability 
   testing" and ./p/following-sibling::p ftcontains 
   "information architecture"]
where count($chapters)>0
return ($book/metadata/title, $chapters)
