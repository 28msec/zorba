xquery version "3.0";
(: Higher Order Functions :)
(: Return an inline function from a user-defined function. Needs function coercion :)
(: Author - Michael Kay, Saxonica :)

declare function local:splitter() as (function(xs:string) as xs:string*) {
  function($x as xs:string) { tokenize($x, '\s') }
};

string-join(local:splitter()("A nice cup of tea"), '|')