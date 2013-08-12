import module namespace zorba = "http://zorba.io/modules/reference";

declare variable $input-context external;

let $persons := doc($input-context)/site/people
for $person in $persons
return zorba:dereference(zorba:reference($person))

