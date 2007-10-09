declare function local:filter ( $nodes 
   as node()*, $exclude as element()* ) as node()*
   {
      for $node in $nodes except $exclude
      return
         typeswitch ($node)
            case $e as element()
               return 
                 element {node-name($e)}
                   {
                       $e/@*,
                      filter( $e/node() except $exclude, 
                      $exclude )
                   }
            default 
               return $node
   };

for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book
let $irrelevantParts := 
   for $part in $book//part
   let score $score := $part ftcontains "usability test.*" 
      with wildcards
   where $score < 0.5
   return $part
where count($irrelevantParts) < count($book//part)
return filter($book, $irrelevantParts)
