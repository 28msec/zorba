doc("http://bstore1.example.com/full-text.xml")
/books/book(every $pub in .//publisher 
satisfies ($pub ftcontains "ersatz" && "publications"))
