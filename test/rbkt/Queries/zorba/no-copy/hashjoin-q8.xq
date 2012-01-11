declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

(:
  HashJoin
:)

let $auction := doc("auction.xml") return

for $p in $auction/site/people/person
let $a :=
  for $t in $auction/site/closed_auctions/closed_auction
  where xs:string($t/buyer/@person) eq xs:string($p/@id)
  return $t
return <item person="{$p/name/text()}">{count($a)}</item>

