declare variable $input-context external;
let $auction := doc($input-context) return
for $p in $auction/site/people/person
where empty($p/homepage/text())
return <person name="{$p/name/text()}"/>
