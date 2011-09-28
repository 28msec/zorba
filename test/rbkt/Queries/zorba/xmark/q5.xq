declare variable $input-context external;
let $auction := doc($input-context) return
count(
    for $i in $auction/site/closed_auctions/closed_auction
    where $i/price/text() >= 40
    return $i/price
    )
