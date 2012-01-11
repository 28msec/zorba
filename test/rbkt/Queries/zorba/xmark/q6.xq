declare variable $input-context external;
let $auction := doc($input-context) return
for $b in $auction//site/regions return count($b//item)

