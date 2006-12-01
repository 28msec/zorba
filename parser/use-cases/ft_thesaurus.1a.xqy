doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//introduction ftcontains "quote" 
with thesaurus at 
"http://bstore1.example.com/UsabilityThesaurus.xml" 
relationship "synonyms")>0]
