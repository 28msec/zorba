doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "r�sum�." 
with wildcards with diacritics)>0]
