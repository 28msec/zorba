for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[./metadata/title ftcontains 
   "usability"]
return <book number="{$book/@number}">
          {$book/metadata/title} 
          <has-publishers> 
             {if (count($book//publisher) > 1) 
             then "true" else "false"}
          </has-publishers>
       </book>
