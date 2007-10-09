for $book in doc("http://bstore1.example.com/full-text.xml")
  /books/book
let score $s := ($book/metadata/title ftcontains 
   "usability" or $book/content ftcontains "usability") 
where $s > 0  
order by $s descending 
return <book number="{$book/@number}"> 
          {$book/metadata/title},  <score>{$s}</score> 
       </book>
