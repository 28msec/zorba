for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $au := $book/metadata/author[. ftcontains ! ("montana" 
  && "marigold")]   
let $co := $book//content[. ftcontains (("correct" 
   || ("comment" with stemming) || "guidance" || "assistance" 
   || "help") && "usability test.*" with wildcards) 
   window 70 words without content .//footnote]
where count($au) > 0 and  count($co) > 0 
return <book number="{$book/@number}"> 
          {$book/metadata/title,
          $book//content}
       </book>
