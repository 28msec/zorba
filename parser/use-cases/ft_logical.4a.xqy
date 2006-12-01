doc("http://bstore1.example.com/full-text.xml")
/books/book[count(. ftcontains  ! "us.* testing" 
with wildcards)>0]
