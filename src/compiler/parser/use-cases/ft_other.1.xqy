for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
where $book/metadata/title/@shortTitle ftcontains "improve" 
   && "web" && "usability" with stemming distance at most 2 words    
return $book/metadata/title
