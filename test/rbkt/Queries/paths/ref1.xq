declare variable $input-context external;

let $persons := doc($input-context)/site/people
for $person in $persons
return fn-zorba:node-by-reference(fn-zorba:node-reference($person))

