doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains "planning then 
conducting" with stop words at 
"http://bstore1.example.com/StopWordList.xml")>0]
