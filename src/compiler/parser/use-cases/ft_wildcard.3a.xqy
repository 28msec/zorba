doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "serv.*e" 
with wildcards)>0]/(@number|./metadata/title/text()
|./content)
