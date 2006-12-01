doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "software" 
&& "developer" with stemming distance at most 3 words)>0]
