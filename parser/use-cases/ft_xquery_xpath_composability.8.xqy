let $books := doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $bookSubject := 
   $books/metadata[./title/@shortTitle 
   ftcontains "Usability Basics"]/subjects/subject
for $book in $books   
where $book/metadata/publicationInfo/dateIssued > 2001 or
     $book/metadata/publicationInfo/dateRevised > 2001 and
     $book/metadata/subjects/subject ftcontains 
     {$bookSubject} any
return
        <book number="{$book/@number}">
           {$book/metadata/title,
           $book/metadata/author}
        </book>
