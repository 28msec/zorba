for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book                        
let $subj := $book/metadata/subjects/subject            
where (some $s1 in $subj satisfies $subj ftcontains "web site")    
   and (some $s2 in $subj satisfies $subj ftcontains "usability")
return $book
