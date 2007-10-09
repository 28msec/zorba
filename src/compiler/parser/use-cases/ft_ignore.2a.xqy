doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//chapter ftcontains "users can be 
tested at any computer workstation or in a lab" 
without content .//footnote)>0]/(metadata/title | .//chapter)
