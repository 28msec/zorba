for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $var := $book[./metadata/title ftcontains "usability"]
where count ($var) > 0   
return <result> 
          {$book/metadata/title, $book/metadata/author} 
       </result>
