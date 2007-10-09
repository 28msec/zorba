doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//chapter ftcontains "at any computer 
workstation or in a lab" without content 
.//footnote[. ftcontains "workstation." with wildcards])>0]
/metadata/title | .//chapter
