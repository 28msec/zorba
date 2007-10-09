doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "efficient" 
&& "task" && "completion" distance 
at most 10 words ordered)>0]
