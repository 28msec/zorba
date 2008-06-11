import module namespace zorba =
  "http://www.flworfound.org/zorba/internal-functions";

declare variable $input-context external;

let $persons := doc($input-context)/site/people
for $person in $persons
return zorba:node-by-reference(zorba:node-reference($person))

