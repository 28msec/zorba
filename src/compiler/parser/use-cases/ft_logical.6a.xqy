doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains (("r�sum�s" 
with diacritics) || "drafts" || "correspondence") 
&& ! "book drafts")>0]
