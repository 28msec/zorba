doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./metadata ftcontains "usability" 
&& ! "plan")>0]
