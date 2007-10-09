doc("http://bstore1.example.com/full-text.xml")
/books/book/metadata/title[count(. ftcontains 
"improving" && "usability" distance at 
most 2 words ordered at start)>0]
