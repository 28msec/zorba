declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) return
for $b in $auction/site/open_auctions/open_auction
where
some $pr1 in $b/bidder/personref[@person = "person20"],
$pr2 in $b/bidder/personref[@person = "person51"]
satisfies $pr1 << $pr2
return <history>{$b/reserve/text()}</history>
