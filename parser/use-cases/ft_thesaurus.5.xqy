for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[. ftcontains "sucessfull" 
   with thesaurus at 
   "http://bstore1.example.com/spellcheck.xml" 
   relationship "misspelling of"]
where count($cont)>0  
return $book
