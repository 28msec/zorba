for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[@number="3"]
let $cont := $book/content[. ftcontains 
   "letters" || "holiday cards" with thesaurus at 
   "http://bstore1.example.com/UsabilityThesaurus.xml" 
   relationship "BT" exactly 1 levels]
where count($cont)>0
return $book
