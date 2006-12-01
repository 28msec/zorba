for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $booktext := $book/content[. ftcontains 
   "conduct" && "usability" && "tests"
   with stemming distance at most 10 words]
let score $s := $booktext ftcontains 
   "measuring" && "success" with stemming distance
   at most 4 words weight 0.8
where count($booktext) > 0
order by $s
return $book/metadata/title, $booktext
