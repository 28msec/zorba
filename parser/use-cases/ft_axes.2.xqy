for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $para := $book[.//chapter/p ftcontains "usability" 
   && "test" with stemming]
where count($para) > 0   
return $book/metadata/title, $para/step[1], $para/step[2]
