doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains "web site components" 
with thesaurus at 
"http://bstore1.example.com/UsabilityThesaurus.xml" 
relationship "narrower terms" at most 2 levels)>0]
