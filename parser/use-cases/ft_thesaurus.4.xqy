for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[. ftcontains "Merrygould" 
   with thesaurus at 
   "http://bstore1.example.com/UsabilitySoundex.xml" 
   relationship "sounds like"]
where count($cont)>0
return $book
