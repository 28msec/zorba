import module namespace zorba =
  "http://www.zorba-xquery.com/zorba/node-ref-functions";

declare variable $input-context external;

let $persons := doc($input-context)/site/people
for $person in $persons
return zorba:node-by-reference(zorba:node-reference($person))

