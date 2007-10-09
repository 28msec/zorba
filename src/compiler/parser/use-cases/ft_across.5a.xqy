doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content/introduction ftcontains 
"identif.*" with wildcards and ./content/part/introduction 
ftcontains "identif.*" with wildcards)>0]
