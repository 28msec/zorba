doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "résumé." 
with wildcards with diacritics)>0]
