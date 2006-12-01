doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//p ftcontains "computer workstation" 
and .//p/footnote ftcontains "comfortable")>0]/(metadata/title 
| .//p)
