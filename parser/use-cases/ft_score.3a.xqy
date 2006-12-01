doc("http://bstore1.example.com/full-text.xml")
/books/book[(for $i score $s in .[. ftcontains "usability"]
return $s) > 0.1]/metadata/title
