doc("http://bstore1.example.com/full-text.xml")
/books/book[count(. ftcontains "sucessfull" 
with thesaurus at 
"http://bstore1.example.com/spellcheck.xml" 
relationship "misspelling of")>0]
