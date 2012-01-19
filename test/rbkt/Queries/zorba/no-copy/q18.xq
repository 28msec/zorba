declare namespace local = "http://www.foobar.org";

declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

declare function local:convert($v as xs:decimal?) as xs:decimal?
{
  2.20371 * $v (: convert Dfl to Euro :)
};

let $auction := doc($input-context) return
  for $i in $auction/site/open_auctions/open_auction
  return local:convert(zero-or-one($i/reserve))

