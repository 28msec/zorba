declare variable $input-context external;
let $auction := doc($input-context) return
for $b in $auction/site/open_auctions/open_auction
return <increase>{$b/bidder[1]/increase/text()}</increase>
