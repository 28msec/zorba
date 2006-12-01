doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains "test.{3,4}" 
with wildcards)>0]/(@number|./content)
