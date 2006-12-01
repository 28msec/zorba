doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains "not been 
approved" with stop words at 
"http://bstore1.example.com/StopWordList.xml" 
except ("not"))>0]/(./metadata/title|./content)
