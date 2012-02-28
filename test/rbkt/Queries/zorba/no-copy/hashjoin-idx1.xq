declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

let $auction := doc("auction.xml") return

for $p in $auction/site/people/person
for $a in $auction/site/closed_auctions/closed_auction
where $a/buyer/@person eq $p/@id
return <item person="{$p/name/text()}">{$a}</item>


