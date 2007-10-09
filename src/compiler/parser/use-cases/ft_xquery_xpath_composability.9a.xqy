doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains ("successfully" 
&& "completing" && "tasks") with stemming
window at most (count(./contents/part/chapter) * 3)
words)>0]/(./metadata/title|./content)
