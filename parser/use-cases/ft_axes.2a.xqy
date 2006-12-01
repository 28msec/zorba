doc("http://bstore1.example.com/full-text.xml")
/books/book//chapter/p[count(. ftcontains "usability" 
&& "test" with stemming)>0]/(metadata/book 
| .//chapter/p/step[1] | .//chapter/p/step[2])
