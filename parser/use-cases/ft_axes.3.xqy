for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[@number="3"]
let $comp := $book[./content/part/component/
   (subcomponent | subcomponent/subsubcomponent)/
   componentTitle ftcontains "flow diagram.?" 
   with wildcards]
let $parentComp := $book[ancestor::books//../$comp 
  ftcontains "human computer interaction"]
where count($comp) > 0   
return $book/metadata/title, $book/content
