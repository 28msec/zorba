declare variable $input-context external;
let $auction := doc($input-context) return
for $i in $auction/site//item
where contains(string(exactly-one($i/description)), "gold")
return $i/name/text()

