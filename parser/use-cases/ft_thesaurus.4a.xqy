doc("http://bstore1.example.com/full-text.xml")
/books/book[count(. ftcontains "Merrygould" 
with thesaurus at 
"http://bstore1.example.com/UsabilitySoundex.xml" 
relationship "sounds like")>0]
