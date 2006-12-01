for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[.//publicationInfo/place/text() 
   = "Washington, D.C."]
let $intro := $book/content/introduction[. ftcontains 
   ("résumés" with diacritics) && "drafts" && "correspondence"]
where count($intro)>0
return <book number="{$book/@number}"> 
           {$book/metadata/title, $intro}
        </book>
