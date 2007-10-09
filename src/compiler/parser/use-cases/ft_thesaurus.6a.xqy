doc("http://bstore1.example.com/full-text.xml")
/books/book[@number="3" and count(.//component ftcontains "AIDS" 
uppercase with thesaurus at 
"http://bstore1.example.com/OurTaxonomy.xml" 
relationship "disease in this category")>0]
