doc("http://bstore1.example.com/full-text.xml")
/books//p[count(. ftcontains "testing" 
&& ("guidance" || "correct") distance at 
most 60 words without content *)>0]
