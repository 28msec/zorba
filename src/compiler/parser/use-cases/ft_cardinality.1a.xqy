doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./metadata/subjects/subject ftcontains 
"web site" && "usability")>0]
