doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "users" 
&& "feeling" && ("well served" || "well-served") with stemming 
window 15 words ordered)>0]
