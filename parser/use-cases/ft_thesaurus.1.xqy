for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $intro := $book//introduction[. ftcontains "quote" 
   with thesaurus at
   "http://bstore1.example.com/UsabilityThesaurus.xml" 
   relationship "synonyms"]
where count($intro)>0
return $book
