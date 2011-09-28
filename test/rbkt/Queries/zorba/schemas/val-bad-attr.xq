
import schema default element namespace "http://ns.example.com/books" at "books1.xsd";

for $att in (validate lax { fn:doc("books.xml") })//@CAT
return 
(
<result>{$att}</result>,
"
"
)
