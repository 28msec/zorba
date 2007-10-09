doc("http://bstore1.example.com/full-text.xml")
/books/book[count(./content ftcontains "letters" 
|| "holiday cards" with thesaurus at 
"http://bstore1.example.com/UsabilityThesaurus.xml" 
relationship "BT" exactly 1 levels)>0]
