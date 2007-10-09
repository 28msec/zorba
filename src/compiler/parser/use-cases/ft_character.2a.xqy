doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "resume." 
with wildcards diacritics insensitive)>0]
