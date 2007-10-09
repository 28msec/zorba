doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains (("résumés" 
with diacritics) || "drafts" || "correspondence") 
&& ! "book drafts")>0]
