declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) 
return
for $p in $auction/site/people/person
let $l :=
  for $i in $auction/site/open_auctions/open_auction/initial
  where $p/profile/@income > 5000 * exactly-one($i/text())
  return $i
where $p/profile/@income > 50000
return <items person="{$p/profile/@income}">{count($l)}</items>

