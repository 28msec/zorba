
let $auction := doc("auction.xml") return

for $p in $auction/site/people/person
for $a in $auction/site/closed_auctions
for $t in $a/closed_auction
where $t/buyer/@person eq $p/@id
return <item person="{$p/name/text()}">{$t}</item>


