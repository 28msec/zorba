for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $title := $book/metadata/title[. ftcontains 
   "usability"]
let $in := $book/content/introduction[. ftcontains 
   "satisfaction"]
let $pin := $book/content/part/introduction[. ftcontains 
   "identify problems"]
where count($title)>0 and count($in)>0 
   and count($pin)>0
return <book number="{$book/@number}"> 
          {$title} 
          if (count($book/metadata/author) > 0)
          then {$book/metadata/author, $in, $pin}
          else {$book/metadata/publicationInfo/publisher, $in, $pin}
       </book>
