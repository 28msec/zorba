declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) return
for $a in $auction/site/closed_auctions/closed_auction
where
not(
    empty(
      $a/annotation/description/parlist/listitem/parlist/listitem/text/emph/
      keyword/
      text()
      )
   )
return <person id="{$a/seller/@person}"/>
