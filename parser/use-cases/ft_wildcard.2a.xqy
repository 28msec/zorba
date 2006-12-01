doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains ".?way" 
with wildcards)>0]
