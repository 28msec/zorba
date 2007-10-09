doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./metadata/title/@shortTitle ftcontains 
"improve" && "web" && "usability" with stemming  
distance at most 2 words)>0]/metadata/title
