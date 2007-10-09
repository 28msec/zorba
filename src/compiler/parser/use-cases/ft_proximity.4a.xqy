doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "users" && "would" 
&& "know" && "step" with stemming same sentence)>0]
