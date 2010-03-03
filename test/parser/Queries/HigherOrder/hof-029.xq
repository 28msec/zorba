xquery version "1.1";
(: Higher Order Functions :)
(: Return an inline function that uses internal variables. Needs function coercion :)
(: Author - Michael Kay, Saxonica :)

declare function local:splitter() as (function(xs:string) as xs:string+)? {
  function($x as xs:string) { for $i in tokenize($x, '\s') return upper-case($i)}
};

string-join(local:splitter()("A nice cup of tea"), '|')