for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
   [(($book/metadata/publicationInfo/dateIssued > "2000-12-31") 
   or ($book/metadata/publicationInfo/dateRevised > "2000-12-31")) 
   and count($book/metadata/author) > 1]
let $subj := $book//subject[. ftcontains "usability test.*" 
   with wildcards]
where count($subj)>0
return <book number="{$book/@number}"> 
          {$book/metadata/title, $book/metadata/author, $subj}
       </book>
