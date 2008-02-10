declare variable $input-context external;
let $auction := doc($input-context) return
for $p in $auction/site
return
count($p//description) + count($p//annotation) + count($p//emailaddress)

