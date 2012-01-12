declare namespace opt = "http://www.zorba-xquery.com/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) return
for $p in $auction/site
return
count($p//description) + count($p//annotation) + count($p//emailaddress)

