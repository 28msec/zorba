doc("http://bstore1.example.com/full-text.xml")
/books/book(some $s1 in ./metadata/subjects/subject satisfies 
./metadata/subjects/subject ftcontains "web site") 
and (some $s2  in ./metadata/subjects/subject satisfies 
./metadata/subjects/subject ftcontains "usability")
