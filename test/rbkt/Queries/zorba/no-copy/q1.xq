
declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

declare variable $input-context external;

let $auction := doc($input-context) return
for $b in $auction/site/people/person[@id = "person0"] return $b/name/text()
