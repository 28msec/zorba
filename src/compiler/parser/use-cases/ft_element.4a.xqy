doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./metadata/title[. ftcontains "usability tests"] 
or ./content/part/chapter/title[. ftcontains "usability tests"])>0]
