declare ft-option using language "en";

let $x := <p>It was the best of times, it was the worst of times.</p>
return $x contains text "best any times"
using stop words ( "any" )
