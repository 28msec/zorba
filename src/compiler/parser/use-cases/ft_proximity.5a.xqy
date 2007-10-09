doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "usability" 
&& "web site" && "efficiency" && "satisfaction" 
same paragraph)>0]
