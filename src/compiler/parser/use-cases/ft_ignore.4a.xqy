doc("http://bstore1.example.com/full-text.xml")
/books/book/chapter[count((./p | ./p/footnote) 
ftcontains "workstation" && "lab" distance at most 6 words 
without content ./footnote)>0]/(metadata/title | ./p 
| ./p/footnote)
