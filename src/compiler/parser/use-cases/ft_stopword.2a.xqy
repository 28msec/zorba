doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "planning then 
conducting" without stop words)>0]
