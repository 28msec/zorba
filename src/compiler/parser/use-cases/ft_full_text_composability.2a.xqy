doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content/p ftcontains ("task" 
&& "performance" with stemming distance 
at most 3 words) && "expert review" with stemming)>0]
