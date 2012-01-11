declare variable $input-context external;
let $auction := doc($input-context) return
for $b in $auction/site/people/person[@id = "person0"] return $b/name/text()
